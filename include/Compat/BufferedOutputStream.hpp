/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BufferedOutputStream_hpp)
#define Apoxi_BufferedOutputStream_hpp

#include <Kernel/OutputStream.hpp>

#ifndef APOXI_NOSTREAMING

class BufferedOutputStream : public OutputStream {
    public:
        BufferedOutputStream(OutputStream* stream);
        virtual ~BufferedOutputStream();

        virtual INT Write (const BYTE data);
        virtual INT Write (const BYTE* data, INT len);

        virtual void Flush();
    
    private:
        OutputStream* m_stream;
        const UINT16 m_maxBuffer;
        UINT16 m_tail;
        BYTE m_buffer[512];
};

#endif

#endif // Apoxi_BufferedOutputStream_hpp


