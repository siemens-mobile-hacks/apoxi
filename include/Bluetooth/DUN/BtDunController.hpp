/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDunController_hpp)
#define BtDunController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <stack/extensions.h>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtSingleConnectionController.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtDunService;
class BtDunDisconnectRequest;

class BtDunController : public BtSingleConnectionController
{
    private:
        typedef BtSingleConnectionController Base;

    public:

        static BtDunController& GetInstance();

    public:
        virtual ~BtDunController();


        virtual const WCHAR* GetName() const;

    private:
        /*---------------------------------------------------------------------*/
        /* The following functions must not be called by an application.       */
        /* They are the entry point from the stack callback functions into our */
        /* object orientated framework (APOXI).                                */
        /* They are implemented as static because they have to be passed as    */
        /* normal C function pointers. The reason for this is the BT-API Stack */
        /* interface that demands C function pointers for callback the         */
        /* callback functions it calls to state the progress of ongoing        */
        /* operations                                                          */
        /*---------------------------------------------------------------------*/


        static void OnDunConnectCallback(btapi_result_t result, btapi_bdaddr_t api_device_address);


        void OnDunConnect(BtResultCode result, const BtDeviceAddress& device_address);


        static void OnDunDisconnectCallback(btapi_result_t result);


        void OnDunDisconnect(BtResultCode result);

    private:
        BtDunController();


        virtual void Register();


        virtual void Unregister();

    private:
        btapi_duncb_funp_t* m_dun_callback_functions;

    private:
        static BtDunController m_controller;

    private:
        friend class BtDunService;
        friend class BtDunDisconnectRequest;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtDunController_hpp


