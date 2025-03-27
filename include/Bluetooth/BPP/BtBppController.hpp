/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppController_hpp)
#define BtBppController_hpp

//#define BTAPI_SIMULATION_234


#include <stack/extensions.h>
//#include <Bluetooth/BtMultiConnectionController.hpp>
#include <Bluetooth/BtSingleConnectionController.hpp>
#include <Bluetooth/BPP/BtBppSndFilePushReqRequest.hpp>
#include <Bluetooth/BPP/BtBppSndAbortReqRequest.hpp>
#include <Bluetooth/BPP/BtBppSndGetRefObjRspRequest.hpp>


/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

//class BtBppService;
//class BtBppServerService;
//class BtBppClientService;
//class BtBppRegisterServerRequest;
//class BtBppUnregisterServerRequest;

//class BtBppSndFilePushReq;
//class BtBppSndGetRefObjRsp;
//class BtBppSndAbortReq;
//class BtBppSndAuthenticationReqRes;


class BtBppController: public BtSingleConnectionController
{

    private:
        typedef BtSingleConnectionController Base;
    
    public:
        BtBppController()   ;
        
        virtual ~BtBppController();


        static BtBppController& GetInstance() ;




        virtual const WCHAR* GetName() const;

    protected:


        BOOLEAN BppSndFilePushReq(BtBppSndFilePushReqRequest* filepushreq);

        BOOLEAN BppSndGetRefObjRsp(BtBppSndGetRefObjRspRequest* getrefobjrsp);

        BOOLEAN BppSndAbortReq(BtBppSndAbortReqRequest* abortreq);

        
//      BOOLEAN BppSndAuthenticationReqRes(BtBppSndAuthenticationReqRes* authenticationreqres);



    private:

//      typedef BtSingleConnectionController Base;
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




        //File Push scenarios
        // Callback corresponding to BPP_SND_CONNECT_IND msg, BPP_SND_ConnectInd
        static void BppSndConnectIndCb (btapi_result_t result, const btapi_bpp_snd_connect_ind_t *ind);
        // Callback corresponding to BPP_SND_FILE_PUSH_CFM
        static void BppSndFilePushCfmCb(btapi_result_t result, const btapi_bpp_snd_file_push_cfm_t *cfm);
        static void BppSndDisconnectIndCb(btapi_result_t result, const btapi_bpp_snd_disconnect_ind_t *ind); 
        
        //getReferencedObjects Scenarios
        static void BppSndGetRefObjIndCb(btapi_result_t result, const btapi_bpp_snd_get_ref_obj_ind_t *ind); 
        static void BppSndGetRefObjCompleteIndCb(btapi_result_t result); 
        
        //Abort Scenarios
        static void BppSndAbortCfmCb(btapi_result_t result, const btapi_bpp_snd_abort_cfm_t *cfm); // Callback for Abort Indication (BIP_ABORT_IND) 
        
        //Obex Authentication
        static void BppSndAuthenticationReqIndCb(btapi_result_t result, const btapi_bpp_snd_authentication_req_ind_t *cfm); // Callback for Abort Indication (BIP_ABORT_IND) 



        //File Push scenarios
        // Callback corresponding to BPP_SND_CONNECT_IND msg, BPP_SND_ConnectInd
        void OnBppSndConnectIndCb (btapi_result_t result, const btapi_bpp_snd_connect_ind_t *ind);
        // Callback corresponding to BPP_SND_FILE_PUSH_CFM
        void OnBppSndFilePushCfmCb(btapi_result_t result, const btapi_bpp_snd_file_push_cfm_t *cfm);
        void OnBppSndDisconnectIndCb(btapi_result_t result, const btapi_bpp_snd_disconnect_ind_t *ind); 
        
        //getReferencedObjects Scenarios
        void OnBppSndGetRefObjIndCb(btapi_result_t result, const btapi_bpp_snd_get_ref_obj_ind_t *ind); 
        void OnBppSndGetRefObjCompleteIndCb(btapi_result_t result); 
        
        //Abort Scenarios
        void OnBppAbortCfmCb(btapi_result_t result, const btapi_bpp_snd_abort_cfm_t *cfm); // Callback for Abort Indication (BIP_ABORT_IND) 
        
        //Obex Authentication
        void OnBppAuthenticationReqIndCb(btapi_result_t result, const btapi_bpp_snd_authentication_req_ind_t *cfm); // Callback for Abort Indication (BIP_ABORT_IND) 
        

//      BtBppController::BtBppController()  ;


        virtual void Register();


        virtual void Unregister();



        btapi_bpp_handle_t GetBppHandle(const void* apoxi_handle);

        btapi_bppcb_funp_t* m_Bpp_callback_functions;

        static BtBppController m_controller;
        BOOLEAN m_need_disconnect_request_after_abort_cfm; // because of Mecel BPP SDK, Figure 6, page 12
#ifdef BTAPI_SIMULATION_234
        static void OnResponseTimer1(void* arg);
        static void OnResponseTimer2(void* arg);
        static void OnResponseTimer3(void* arg);
        static SystemTimer m_responsetimer1;
        static SystemTimer m_responsetimer2;
        static SystemTimer m_responsetimer3;
        btapi_bpp_snd_file_push_req_t* m_op_params_btapi_simulation;
        static btapi_BT_BdAddr m_bdAddr_btapi_simulation;
#endif //BTAPI_SIMULATION_234       
        

        friend class BtBppService;
        friend class BtBppServerService;
        friend class BtBppClientService;
//      friend class BtBppRegisterServerRequest;
//      friend class BtBppUnregisterServerRequest;
        
        friend class BtBppSndFilePushReqRequest;
        friend class BtBppSndGetRefObjRspRequest;
        friend class BtBppSndAbortReqRequest;
//      friend class BtBppSndAuthenticationReqRes;
};

#endif  // BtBppController_hpp


