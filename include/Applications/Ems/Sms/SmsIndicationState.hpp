/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsIndicationState_hpp)
#define Mmi_SmsIndicationState_hpp

class AbstractSmsApp;
const int c_pending_priority = 1;
const int c_msg_waiting_priority = 2;
const int c_new_sms_priority = 3;
const int c_new_status_report_priority = 4;
        
class SmsIndicationState {
    public:

        SmsIndicationState(AbstractSmsApp* app);
        virtual ~SmsIndicationState();

        enum Indication {
            PendingIndication = c_pending_priority,
            MsgWaitingIndication = c_msg_waiting_priority,
            NewSmsIndication = c_new_sms_priority,
            NewStatRepIndication = c_new_status_report_priority, 
            NoIndication
        };

        void SetFlagState(BOOLEAN &flag, const BOOLEAN& enable, Indication cu);
        void SetMsgWaitingState(BOOLEAN enable);
        void SetPendingState(BOOLEAN enable);
        void SetNewSmsState(BOOLEAN enable);
        void SetNewStatRepState(BOOLEAN enable);
        void SetCurrentIndication(Indication li) {m_current_ind = li; }
        
        BOOLEAN GetMsgWaitingState() {return m_msg_waiting_state;}
        BOOLEAN GetPendingState() {return m_pending_state;}
        BOOLEAN GetNewSmsState() {return m_new_sms_state;}
        BOOLEAN GetNewStatRepState() {return m_new_status_report_state;}
        Indication GetCurrentIndication() {return m_current_ind;}

        virtual void SetNewCurrentIndication();
    private:
        Indication m_current_ind;
        BOOLEAN m_msg_waiting_state;
        BOOLEAN m_pending_state;
        BOOLEAN m_new_sms_state;
        BOOLEAN m_new_status_report_state;
        AbstractSmsApp* p_app;
};
#endif  // Mmi_SmsIndicationState_hpp
