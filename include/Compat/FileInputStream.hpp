/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileInputStream_hpp)
#define Apoxi_FileInputStream_hpp

#include <Kernel/InputStream.hpp>

#ifndef APOXI_NOSTREAMING

class FileInputStream : public InputStream{
    public:

        FileInputStream();
        virtual ~FileInputStream();

        int IsOpen() const { return m_peer.IsOpen(); };
        void Open(const char* name, int flags) { m_peer.Open(name, flags); };
        void Close() { m_peer.Close(); };
        int Peek() { return m_peer.Peek(); };
        int Eof() {return m_peer.Eof(); };

        virtual INT Read (BYTE& data);
        virtual INT Read (BYTE* data, INT len);

        virtual UINT32 Available();
        
    private:
        FileIoPeer m_peer;
};

#endif

#endif // Apoxi_FileInputStream_hpp


