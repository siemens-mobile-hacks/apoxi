/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_ByteBuffer_hpp)
#define Auxiliary_ByteBuffer_hpp

#include <Kernel/Types.hpp>

class ByteBuffer {

    public:
        ByteBuffer();

        ByteBuffer(INT len, INT capacity = 0);

        ByteBuffer(const ByteBuffer& bbCopy);

        ByteBuffer(const ByteBuffer* bbCopy);

        ByteBuffer(const UINT8* buffer, INT len, INT capacity = 0);

        virtual ~ByteBuffer();

        ByteBuffer &    operator = (const ByteBuffer & bbCopy);

        UINT8 &         operator [] (INT idx);

        virtual BOOLEAN Append(UINT8    octet);

        virtual INT     GetLength() const { return m_buffer_len; }

        virtual UINT8*  GetData() const { return m_buffer; }

        virtual BOOLEAN IsEmpty() const { return m_buffer == 0; }

        virtual BOOLEAN IsEqualTo(const ByteBuffer &    rhs) const;

        virtual void    Swap(ByteBuffer &   swap_with);

        virtual BOOLEAN PreAlloc(INT    length,
                                 INT    capacity = 0);

        inline  INT     GetCapacity() const { return m_buffer_cap; }

        /*  @brief  Adjusts usable length of the buffer.
            
            When length is greater than the capacity of the buffer,
            a larger internal buffer will be allocated, otherwise
            just the length is adjusted and the capacity remains
            unchanged.
            
            @return \c 'TRUE' in case of success, \c 'FALSE' when
                    memory allocation failed - in this case the
                    object is not modified */
        virtual BOOLEAN SetLength(INT   length);

        inline  BOOLEAN Reserve(INT     capacity);

    protected:
        BOOLEAN         Allocate(INT  length, INT capacity = 0);
        BOOLEAN         Reallocate(INT  length, INT capacity);
        void            Free();

    private:
        UINT8 *         m_buffer;
        INT             m_buffer_len;
        INT             m_buffer_cap;
};

/*  ----------------------------------------------------------------------
    Reserve
    ---------------------------------------------------------------------- */
BOOLEAN ByteBuffer::Reserve(INT     capacity)
{
    return  PreAlloc( GetLength(), capacity );
}// Reserve

/*  ----------------------------------------------------------------------
    operator==()
    ---------------------------------------------------------------------- */
inline  BOOLEAN operator==(const ByteBuffer &   lhs,
                           const ByteBuffer &   rhs)
{
    return  lhs.IsEqualTo(rhs);
}

/*  ----------------------------------------------------------------------
    operator!=()
    ---------------------------------------------------------------------- */
inline  BOOLEAN operator!=(const ByteBuffer &   lhs,
                           const ByteBuffer &   rhs)
{
    return  ! lhs.IsEqualTo(rhs);
}
        
#if !defined(APOXI_BYTEBUFFER_TEST_SUITE) && defined(APOXI_RTOS_WIN32)
#define APOXI_BYTEBUFFER_TEST_SUITE

// Call for ByteBuffer test suite, only for WIN32 platform
void ByteBufferTest();

#endif

#endif  // Auxiliary_ByteBuffer_hpp

