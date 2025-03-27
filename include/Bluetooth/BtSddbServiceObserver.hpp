/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbServiceObserver_hpp)
#define BtSddbServiceObserver_hpp

#include <Bluetooth/BtServiceObserver.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtSddbService;

class BtSddbServiceObserver: public BtServiceObserver
{
    private:
        typedef BtServiceObserver Base;

    public:
        BtSddbServiceObserver();

        virtual ~BtSddbServiceObserver();

    protected:

        virtual void OnEvent(const BtEvent& event);


        virtual void OnRegisterService(BtResultCode code) = 0;


        virtual void OnUnregisterService(BtResultCode code) = 0;

private:
        friend class BtSddbService;
};

#endif  // BtSddbServiceObserver_hpp


