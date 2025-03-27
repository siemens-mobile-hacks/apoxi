/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexServerServiceObserver_hpp)
#define BtObexServerServiceObserver_hpp

#include <Bluetooth/OBEX/BtObexServiceObserver.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexServerService;
class BtDevice;

class BtObexServerServiceObserver: public BtObexServiceObserver
{
    private:
        typedef BtObexServiceObserver Base;

    public:
        BtObexServerServiceObserver();

        virtual ~BtObexServerServiceObserver();

    protected:

        virtual void OnEvent(const BtEvent& event);


        virtual void OnRegister(BtResultCode code, UINT8 rfcom_channel) = 0;


        virtual void OnConnect(BtResultCode code, const BtDevice& device) = 0;


        virtual void OnDisconnect(BtResultCode code) = 0;


        virtual void OnSetPath(BtResultCode code, BOOLEAN backup, BOOLEAN create) = 0;


        virtual void OnGet(BtResultCode code) = 0;


        virtual void OnPut(BtResultCode code) = 0;


        virtual void OnAbort(BtResultCode code) = 0;

    private:
        friend class BtObexServerService;
};

#endif  // BtObexServerServiceObserver_hpp


