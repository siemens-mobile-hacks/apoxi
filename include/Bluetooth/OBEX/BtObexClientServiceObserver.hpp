/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexClientServiceObserver_hpp)
#define BtObexClientServiceObserver_hpp

#include <Bluetooth/OBEX/BtObexServiceObserver.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexClientService;

class BtObexClientServiceObserver: public BtObexServiceObserver
{
    private:
        typedef BtObexServiceObserver Base;

    public:
        BtObexClientServiceObserver();

        virtual ~BtObexClientServiceObserver();

    protected:

        virtual void OnEvent(const BtEvent& event);


        virtual void OnRegister(BtResultCode code) = 0;


        virtual void OnConnect(BtResultCode code, UINT8 response_code) = 0;


        virtual void OnDisconnect(BtResultCode code, UINT8 response_code) = 0;


        virtual void OnSetPath(BtResultCode code, UINT8 response_code) = 0;


        virtual void OnGet(BtResultCode code, UINT8 response_code) = 0;


        virtual void OnPut(BtResultCode code, UINT8 response_code) = 0;


        virtual void OnAbort(BtResultCode code, UINT8 response_code) = 0;

    private:
        friend class BtObexClientService;
};

#endif  // BtObexClientServiceObserver_hpp


