/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexHeaderBuilder_hpp)
#define Apoxi_ObexHeaderBuilder_hpp

#include <Auxiliary/ByteBuffer.hpp>

#include <Obex/ObexHeader.hpp>

class ObexHeaderBuilder {

    friend class ObexHeaderList;

    public:
        ObexHeaderBuilder(ObexHeader::ByteOrder  format = ObexHeader::ObexByteOrder);

        ObexResult          NewHeader(UINT8  id, UINT16  max_size = 0);

        ObexResult          AppendData(const UINT8  data[], UINT16  length);

        ObexResult          SetValue(UINT32     value);

        BOOLEAN             IsComplete() const;

    private:
        BOOLEAN                         m_swap_global;  
        BOOLEAN                         m_swap_buffer;
        UINT8                           m_hi;           
        UINT16                          m_header_size;  
        UINT16                          m_append_offs;
        ByteBuffer                      m_buffer;

        ObexHeaderBuilder(const ObexHeaderBuilder &);

        ObexHeaderBuilder &     operator=(const ObexHeaderBuilder &);

        ObexHeader *            NewUnicodeHeader();
        ObexHeader *            NewByteSeqHeader();
        ObexHeader *            NewByteValHeader();
        ObexHeader *            NewLongValHeader();

        void                    Reset();

        ObexHeader *            GetResult();
};

#endif  // Apoxi_ObexHeaderBuilder_hpp

