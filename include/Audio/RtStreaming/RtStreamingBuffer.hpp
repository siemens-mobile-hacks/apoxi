/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_RtStreamingBuffer_hpp)
#define Apoxi_RtStreamingBuffer_hpp

#include <Kernel/Types.hpp>

class RtStreamingBuffer {

    public:
        RtStreamingBuffer(UINT32    capacity = 0);  

        ~RtStreamingBuffer();

        RtStreamingBuffer &     operator=(RtStreamingBuffer &  rhs);

        inline  BOOLEAN         IsValid() const {return( m_buffer_ptr != 0 );}

        inline  UINT8 *         GetDataPtr();
        inline  const UINT8 *   GetDataPtr() const;

        inline  UINT32          GetSize() const;
        inline  void            SetSize(UINT32  size);

        inline  UINT32          GetCapacity() const;

        inline  BOOLEAN         IsEndOfData() const;
        inline  void            SetEndOfData();
        
        inline  void            Clear();
        
        void                    Release();

    private:
        RtStreamingBuffer(const RtStreamingBuffer &);

        inline  void            Reset();
        void                    Dispose();
        
        UINT8 *     m_buffer_ptr;
        UINT32      m_capacity;
        UINT32      m_size;
        BOOLEAN     m_is_end_of_data;
};
/*  ------------------------------------------------------------------------
    GetDataPtr
    ------------------------------------------------------------------------ */
UINT8 *     RtStreamingBuffer::GetDataPtr()
{
    return m_buffer_ptr;
} // GetDataPtr

/*  ------------------------------------------------------------------------
    GetDataPtr
    ------------------------------------------------------------------------ */
const UINT8 * RtStreamingBuffer::GetDataPtr()
const
{
    return m_buffer_ptr;
} // GetDataPtr

/*  ------------------------------------------------------------------------
    GetSize
    ------------------------------------------------------------------------ */
UINT32 RtStreamingBuffer::GetSize()
const
{
    return m_size;
} // GetSize

/*  ------------------------------------------------------------------------
    SetSize
    ------------------------------------------------------------------------ */
void RtStreamingBuffer::SetSize(UINT32 size)
{
    ASSERT_DEBUG(size <= m_capacity);
    m_size = size;
} // SetSize

/*  ------------------------------------------------------------------------
GetCapacity
------------------------------------------------------------------------ */
UINT32 RtStreamingBuffer::GetCapacity()
const
{
    return m_capacity;
} // GetCapacity

/*  ------------------------------------------------------------------------
    IsEndOfData
    ------------------------------------------------------------------------ */
BOOLEAN RtStreamingBuffer::IsEndOfData()
const
{
    return m_is_end_of_data;
} // IsEndOfData

/*  ------------------------------------------------------------------------
    SetEndOfData
    ------------------------------------------------------------------------ */
void RtStreamingBuffer::SetEndOfData()
{
    m_is_end_of_data = TRUE;
} // SetEndOfData

/*  ------------------------------------------------------------------------
    Clear
    ------------------------------------------------------------------------ */
void RtStreamingBuffer::Clear()
{
    SetSize(0);
    m_is_end_of_data = FALSE;
} // Clear

/*  ------------------------------------------------------------------------
    Reset
    ------------------------------------------------------------------------ */
void RtStreamingBuffer::Reset()
{
    Clear();
    m_buffer_ptr = 0;
    m_capacity   = 0;
} // Reset

#endif  // Apoxi_RtStreamingBuffer_hpp

