/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Os_SocketPeer_hpp)
#define Apoxi_Os_SocketPeer_hpp

#include <Auxiliary/String.hpp>


class SocketPeer {
    public :
        SocketPeer();
        virtual ~SocketPeer();

        BOOLEAN Bind(UINT16 port);
        BOOLEAN Connect(const String& address, UINT16 port);
        BOOLEAN Accept(const String& address, UINT16 port);
        BOOLEAN Listen(INT backlog = 1);
        void Close();

        BOOLEAN Read(BYTE* data, UINT length);
        BOOLEAN Write(const BYTE* data, UINT length);

        String GetLocalName() const;
        UINT16 GetLocalPort() const;
        String GetPeerName() const;
        UINT16 GetPeerPort() const;

        void SetLinger(BOOLEAN flag, INT timeout);
        BOOLEAN IsLingerEnabled();
        INT GetLingerTimeout();
        void SetBlockingEnabled(BOOLEAN flag);
        UINT32 GetAvailableCount();

    private:
};


#endif // Apoxi_Os_SocketPeer_hpp


