/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpPanelProfileService_hpp)
#define BtAvrcpPanelProfileService_hpp

#include <Bluetooth/AVRCP/BtAvrcpRegistrationService.hpp>
#include <Bluetooth/AVRCP/BtAvrcpOperationService.hpp>
#include "BtAvrcpAlertMessageWindow.hpp"

/*  ------------------------------------------------------------------------
    forward declartions
    ------------------------------------------------------------------------ */
class BtAvrcpAlertMessageWindow;
class BtAvrcpControllerApplicationWindow;

/*  ------------------------------------------------------------------------
    BtAvrcpProfileRegistrationService
    ------------------------------------------------------------------------ */
class BtAvrcpProfileRegistrationService: public BtAvrcpRegistrationService
{
    private:
        typedef BtAvrcpRegistrationService Base;

    public:
        BtAvrcpProfileRegistrationService(BtAvrcpAlertMessageWindow& alert_message_window);

        virtual ~BtAvrcpProfileRegistrationService();

    protected:
        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);

        void OnRegister(BtRequestState old_request_state, BtRequestState new_request_state);

        void OnDeRegister(BtRequestState old_request_state, BtRequestState new_request_state);
    private:
        BtAvrcpAlertMessageWindow& m_alert_message_window;
};

/*  ------------------------------------------------------------------------
    BtAvrcpProfileOperationService
    ------------------------------------------------------------------------ */
class BtAvrcpProfileOperationService: public BtAvrcpOperationService
{
    private:
        typedef BtAvrcpOperationService Base;

    public:
        BtAvrcpProfileOperationService(BtAvrcpPanelApplication& panel_app, BtAvrcpAlertMessageWindow& alert_message_window, BtAvrcpControllerApplicationWindow& controller_win);

        virtual ~BtAvrcpProfileOperationService();

    protected:
        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);

        void OnConnect(BtRequestState old_request_state, BtRequestState new_request_state);

        void OnDisconnect(BtRequestState old_request_state, BtRequestState new_request_state);

        void OnPanelPassthrough(BtRequestState old_request_state, BtRequestState new_request_state);

        void OnRawFrame(BtRequestState old_request_state, BtRequestState new_request_state);

        void OnUnitInfo(BtRequestState old_request_state, BtRequestState new_request_state);

        void OnSubunitInfo(BtRequestState old_request_state, BtRequestState new_request_state);

        virtual void OnPanelPassThrough(BtAvrcpPanelPassThroughParams ppt_params);

        virtual void OnRawFrame(BtAvrcpRawFrameParams raw_frame_paras);

    private:
        BtAvrcpAlertMessageWindow& m_alert_message_window;
        BtAvrcpPanelApplication& m_panel_app;
        BtAvrcpControllerApplicationWindow& m_controller_win;

};

#endif /* BtAvrcpPanelProfileService_hpp */

