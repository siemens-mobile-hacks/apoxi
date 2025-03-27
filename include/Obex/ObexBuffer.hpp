/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexBuffer_hpp)
#define Apoxi_ObexBuffer_hpp

#include <Auxiliary/NonCloneable.hpp>

class ObexBuffer {

    public:
        class   Factory;
        class   Reader;
        class   Writer;

        friend  class Factory;
        friend  class Reader;
        friend  class Writer;

        typedef  UINT8 *        DataPtr;
        typedef const  UINT8 *  ConstDataPtr;
        typedef UINT32              Size;
        typedef UINT32              Offset;

        class Factory : public NonCloneable {

            public:
                void            Destroy(ObexBuffer &  buffer);

            protected:
                Factory();

                void            Construct(ObexBuffer &  init_obj,
                                          DataPtr       data_ptr,
                                          Size          capacity,
                                          Size          size = 0);

                virtual void    OnRelease(DataPtr   user_ptr,
                                          Size      capacity) = 0;
        };

        class Reader {

            public:
                Reader(ObexBuffer &  buffer, Size  offset = 0);

                inline  DataPtr GetPtr() const;

                inline  Size            GetOffset() const;

                Size                    GetNoBytesReadable() const;

                void                    Commit(Size  no_bytes);

                Size                    CopyTo(DataPtr  dest_ptr,
                                               Size     dest_size);
            private:
                Reader(const Reader &);

                Reader &                operator=(const Reader &);

                ObexBuffer &    m_buffer;
                Size            m_offset;
        };

        class Writer {

            public:
                Writer(ObexBuffer &  buffer);

                inline  DataPtr         GetPtr() const;

                inline  Size            GetOffset() const;

                Size                    GetNoBytesWritable() const;

                void                    Commit(Size  no_bytes);

                Size                    CopyFrom(ConstDataPtr   from_ptr,
                                                 Size           from_size);
            private:
                Writer(const Writer &);

                Writer &                operator=(const Writer &);

                ObexBuffer &    m_buffer;
        };

        ObexBuffer();

        ObexBuffer(Size  capacity);

        ObexBuffer(ObexBuffer &  take_from);

        ~ObexBuffer();

        ObexBuffer &            operator=(ObexBuffer &  take_from);

        inline  BOOLEAN         IsValid() const;

        inline  Size            GetSize() const;

        inline  Size            GetCapacity() const;

        inline  void            Empty();

        inline  void            Release();

    private:
        DataPtr     m_data_ptr;
        Size        m_capacity;
        Size        m_data_size;
        BOOLEAN     m_auto_free;

        inline  DataPtr         GetPtrAt(Size   where) const;

        void                    SetSize(Size  data_size);

        ObexBuffer(DataPtr  user_ptr, Size  capacity, Size  size);

        void                    Reset();

        void                    Dispose();
};

/*  ----------------------------------------------------------------------
    Reader::GetPtr

    Allows computation of a pointer which points exactly one byte behind
    the buffer. GetNoBytesReadable() will return 0 in this case, so a
    memcpy() will not read bad data in this case.
    ---------------------------------------------------------------------- */
ObexBuffer::DataPtr ObexBuffer::Reader::GetPtr()
const
{
    ASSERT_DEBUG( m_offset <= m_buffer.GetSize() );

    return  m_buffer.GetPtrAt(m_offset);
}// GetPtr

/*  ----------------------------------------------------------------------
    Reader::GetOffset
    ---------------------------------------------------------------------- */
ObexBuffer::Size            ObexBuffer::Reader::GetOffset()
const
{
    return  m_offset;
}// GetOffset

/*  ----------------------------------------------------------------------
    Writer::GetPtr

    Allows computation of a pointer which points exactly one byte behind
    the buffer. GetNoBytesWritable() will return 0 in this case, so a
    memcpy() will not overwrite memory in this case.
    ---------------------------------------------------------------------- */
ObexBuffer::DataPtr         ObexBuffer::Writer::GetPtr()
const
{
    ASSERT_DEBUG( (m_buffer.GetSize() <= m_buffer.GetCapacity()) );

    return  m_buffer.GetPtrAt( m_buffer.GetSize() );
}// GetPtr

/*  ----------------------------------------------------------------------
    Writer::GetOffset
    ---------------------------------------------------------------------- */
ObexBuffer::Size    ObexBuffer::Writer::GetOffset()
const
{
    return  m_buffer.GetSize();
}// GetOffset

/*  ----------------------------------------------------------------------
    IsValid
    ---------------------------------------------------------------------- */
BOOLEAN     ObexBuffer::IsValid()
const
{
    return ( m_data_ptr != 0 );
}// IsValid

/*  ----------------------------------------------------------------------
    GetSize
    ---------------------------------------------------------------------- */
ObexBuffer::Size    ObexBuffer::GetSize()
const
{
    return m_data_size;
}// GetSize

/*  ----------------------------------------------------------------------
    GetCapacity
    ---------------------------------------------------------------------- */
ObexBuffer::Size    ObexBuffer::GetCapacity()
const
{
    return m_capacity;
}// GetCapacity

/*  ----------------------------------------------------------------------
    Empty
    ---------------------------------------------------------------------- */
void    ObexBuffer::Empty()
{
    m_data_size = 0;
}// Empty

/*  ----------------------------------------------------------------------
    Release
    ---------------------------------------------------------------------- */
void    ObexBuffer::Release()
{
    Dispose();
    Reset();
}// Release

/*  ----------------------------------------------------------------------
    GetPtrAt
    ---------------------------------------------------------------------- */
ObexBuffer::DataPtr     ObexBuffer::GetPtrAt(Size   where)
const
{
    ASSERT_DEBUG( IsValid() );

    return  &( m_data_ptr[where] );
}// GetPtrAt

#endif  // Apoxi_ObexBuffer_hpp

