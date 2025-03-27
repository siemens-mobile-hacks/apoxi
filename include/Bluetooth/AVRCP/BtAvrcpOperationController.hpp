/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpOperationController_hpp)
#define BtAvrcpOperationController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <stack/extensions.h>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtSingleConnectionController.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>
//#include <Bluetooth/AVRCP/BtAvrcpResponse.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtAvrcpRequest;
class BtAvrcpRegisterUnitInfo;
class BtAvrcpConnectRequest;
class BtAvrcpConnectResponse;
class BtAvrcpOperationService;
class BtAvrcpDisconnectRequest;
class BtAvrcpPanelPassThroughRequest;
class BtAvrcpRawFrameRequest;
class BtAvrcpUnitInfoRequest;
class BtAvrcpSubunitInfoRequest;
class BtAvrcpOperationRequestResponse;


class BtAvrcpOperationController : public BtMultiConnectionController
{
    private:
        typedef BtMultiConnectionController Base;
    
    public:

        static BtAvrcpOperationController& GetInstance();

    public:
        virtual ~BtAvrcpOperationController();


        virtual const WCHAR* GetName() const;


        BOOLEAN ConnectRequest(BtAvrcpConnectRequest *connect_request);

        BOOLEAN DisconnectRequest(BtAvrcpDisconnectRequest *disconnect_request); 

        BOOLEAN PanelPassThroughRequest(BtAvrcpPanelPassThroughRequest *panel_passthrough_request);

        BOOLEAN RawFrameRequest(BtAvrcpRawFrameRequest *raw_frame_request);

        BOOLEAN UnitInfoRequest(BtAvrcpUnitInfoRequest *unit_info_request);

        BOOLEAN SubunitInfoRequest(BtAvrcpSubunitInfoRequest *subunit_info_request);


        BOOLEAN ConnectResponse(BtAvrcpConnectResponse *connect_response);

        BOOLEAN RequestResponse(BtAvrcpOperationRequestResponse *request_response);

    protected:
        class BtAvrcpConnection: public BtMultiConnectionController::BtConnection
        {
            private:
                typedef BtMultiConnectionController::BtConnection Base;

            public:
                BtAvrcpConnection();

                virtual ~BtAvrcpConnection();


                btapi_avrcp_handle_t GetAvrcpHandle() const;


                void SetAvrcpHandle(btapi_avrcp_handle_t avrcp_handle);

            private:
                btapi_avrcp_handle_t m_avrcp_handle;

        };

    private:

        BtAvrcpConnection* FindConnectionByAvrcpHandle(btapi_avrcp_handle_t avrcp_handle) const;


        btapi_avrcp_handle_t GetAvrcpHandle(const void* apoxi_handle);


#ifdef _XXX_


        BOOLEAN DeRegisterApplication(BtAvrcpRegisterUnitInfo* unit_info);

#endif

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


        static void OnAvrcpConnectCfmCb(btapi_result_t result, const btapi_avrcp_connect_handle_t *hdl);

        static void OnAvrcpDisconnectCb(btapi_result_t result, const void *app_handle);

        static void OnAvrcpPanelPassthroughCfmCb(btapi_result_t result, const btapi_avrcp_response_t *rsp);

        static void OnAvrcpRawFrameCfmCb(btapi_result_t result, const btapi_avrcp_response_t *rsp);

        static void OnAvrcpUnitInfoCfmCb(btapi_result_t result, const btapi_avrcp_unit_info_t *rsp);

        static void OnAvrcpResponseCfmCb(btapi_result_t result, const btapi_avrcp_response_callback_t *rsp);

        static void OnAvrcpSubunitInfoCfmCb(btapi_result_t result, const btapi_avrcp_subunit_info_t *rsp);

        static void OnAvrcpConnectIndCb(btapi_result_t result, const btapi_avrcp_connect_handle_t *hdl);

        static void OnAvrcpPanelPassThroughIndCb(btapi_result_t result, const btapi_avrcp_panel_passthrough_t *ind);

        static void OnAvrcpRawFrameIndCb(btapi_result_t result, const btapi_avrcp_raw_frame_t *ind);

    private:
        BtAvrcpOperationController();
        

        virtual void Register();


        virtual void Unregister();

    private:
        btapi_avrcpcb_funp_t* m_avrcp_callback_functions;
        static BtAvrcpOperationController m_controller;

    private:
        friend class BtAvrcpRequest;
        friend class BtAvrcpConnectRequest;
        friend class BtAvrcpConnectResponse;
        friend class BtAvrcpOperationService;
        friend class BtAvrcpDisconnectRequest;
        friend class BtAvrcpPanelPassThroughRequest;
        friend class BtAvrcpRawFrameRequest;
        friend class BtAvrcpUnitInfoRequest;
        friend class BtAvrcpSubunitInfoRequest;
        friend class BtAvrcpOperationRequestResponse;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHfController_hpp

