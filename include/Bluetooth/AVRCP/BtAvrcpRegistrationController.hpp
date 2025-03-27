/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpRegistrationController_hpp)
#define BtAvrcpRegistrationController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <stack/extensions.h>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtConnectionlessController.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtAvrcpRegisterRequest;
class BtAvrcpDeRegisterRequest;

class BtAvrcpRegistrationController : public BtConnectionlessController
{
    private:
        typedef BtConnectionlessController Base;
    
    public:

        static BtAvrcpRegistrationController& GetInstance();

    public:
        virtual ~BtAvrcpRegistrationController();


        virtual const WCHAR* GetName() const;


    private:

        BOOLEAN RegisterApplication(BtAvrcpRegisterRequest *reg_app_req);

        BOOLEAN DeRegisterApplication(BtAvrcpDeRegisterRequest *dereg_app_req);

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

        static void OnAvrcpRegisterCfmCb(btapi_result_t result, void *app_handle);

    
        static void OnAvrcpDeRegisterCfmCb(btapi_result_t result, void *app_handle);


    private:
        BtAvrcpRegistrationController();
        

        virtual void Register();


        virtual void Unregister();

    private:
        btapi_avrcpcb_funp_t* m_avrcp_callback_functions;

    private:

        static BtAvrcpRegistrationController m_controller;

    private:

        friend class BtAvrcpRegisterRequest;
        friend class BtAvrcpDeRegisterRequest;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtAvrcpRegistrationController_hpp

