/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpOperationService_hpp)
#define BtAvrcpOperationService_hpp

#include <Bluetooth/AVRCP/BtAvrcpService.hpp>
#include <Bluetooth/AVRCP/BtAvrcpConnectRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpDisconnectRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpConnectResponse.hpp>
#include <Bluetooth/AVRCP/BtAvrcpPanelPassThroughRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRawFrameRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpUnitInfoRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpSubunitInfoRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpOperationRequestResponse.hpp>


class BtAvrcpOperationController;


class BtAvrcpOperationService : public BtAvrcpService
{
    private:
        typedef BtAvrcpService Base;

    public:
        BtAvrcpOperationService();

        virtual ~BtAvrcpOperationService();

        virtual BtRequestState GetRequestState(BtRequestType request_type) const;

        BOOLEAN IsConnected() const;

        BtRequestState ConnectRequest();

        BtRequestState DisconnectRequest();

        BtRequestState PanelPassthroughRequest(BtAvrcpOperation operation);

        BtRequestState PanelPassthroughRequest(BtAvrcpOperation operation, BtAvrcpStateFlag state_flag);

        BtRequestState PanelPassthroughRequest(BtAvrcpPanelPassThroughParams ppt_params);

        BtRequestState RawFrameRequest(BtAvrcpRawFrameParams raw_frame_params);


        BtRequestState UnitInfoRequest();

        BOOLEAN GetUnitInfo(BtAvrcpUnitInfoParams &unit_info);


        BtRequestState SubunitInfoRequest(UINT8 page);


        BOOLEAN GetSubunitInfo(BtAvrcpSubunitInfoParams &subunit_info);

        /*
            <em>ConnectResponse</em> Sent over the air in case the Application 
            Programmer wants to accept an incoming connection.
            @param avrcp_handle A <em>btapi_avrcp_handle_t</em> which is delivered
            from the stack via the incoming BtAvrcpNotificationMessage. Needs to 
            be sent back in order to accept the communication between two devices. 
        */
        BtRequestState ConnectResponse(btapi_avrcp_handle_t avrcp_handle);


        BtRequestState OperationRequestResponse(BtRequestType request_type, BtAvrcpResponseType response);


    protected:
        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


        virtual void OnPanelPassThrough(BtAvrcpPanelPassThroughParams panel_passthrough_params);

        virtual void OnRawFrame(BtAvrcpRawFrameParams raw_frame_params);


        virtual BOOLEAN OnMessage(const Message& message);


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;

    private:

        void PanelPassThroughIndicationCallback(BtAvrcpPanelPassThroughParams ppt_params);


        void RawFrameIndicationCallback(BtAvrcpRawFrameParams raw_frame_params);

private:
        BtAvrcpConnectRequest           m_connect_request;
        BtAvrcpConnectResponse          m_connect_response;
        BtAvrcpDisconnectRequest        m_disconnect_request;
        BtAvrcpPanelPassThroughRequest  m_panel_passthrough_request;
        BtAvrcpRawFrameRequest          m_raw_frame_request;
        BtAvrcpUnitInfoRequest          m_unit_info_request;
        BtAvrcpSubunitInfoRequest       m_subunit_info_request;
        BtAvrcpOperationRequestResponse m_response_request;

    private:
        friend class BtAvrcpOperationController;
};

#endif  // BtAvrcpOperationService_hpp

