/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileOutputStream_hpp)
#define Apoxi_FileOutputStream_hpp

#include <Kernel/OutputStream.hpp>

#ifndef APOXI_NOSTREAMING

class FileOutputStream : public OutputStream {
    public:
        FileOutputStream();
        virtual ~FileOutputStream();

        virtual INT Write (const BYTE data);
        virtual INT Write (const BYTE* data, INT len);

        INT IsOpen() const { return m_peer.IsOpen(); };
        void Open(const char* name, int flags) { m_peer.Open(name, flags); };
        void Close() { m_peer.Close(); };
        INT Eof() {return m_peer.Eof(); };

        virtual void Flush();
        
    private:
        FileIoPeer m_peer;
};

#endif

#endif // Apoxi_FileOutputStream_hpp


