/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsAlerts_hpp)
#define Mmi_SmsAlerts_hpp

#include <Common/MmiInfoBox.hpp>
#include <Common/MmiAlert.hpp>

struct SmsSendingAnimation {
    const static UINT32 c_sms_sending_anim_speed;
    const static BitmapRes* m_bmps[17];
    const static INT c_sms_sending_anim_img_cnt;
};

class SmsAlert : public MmiAlert {
    typedef MmiAlert Base;
    public:
        enum SmsAlertType {
            SmsSentOkType,
            SmsReceivedSmsType,
            SmsPendingSmsType,
            SmsReceivedStatRepType,
            SmsMemoryFullType,
            SmsSimFullType,
            SmsStoredOkType,
            SmsBoxEmpty
        };
        SmsAlert();
        ~SmsAlert();
        void Init();
        void SetSmsAlertType(SmsAlertType type, INT pending_seg_count = -1);
        
    private:
        SmsAlert(const SmsAlert &);
        SmsAlert& operator=(const SmsAlert&);
        WString m_text;
};


class SmsInfoBox : public MmiInfoBox {
    typedef MmiInfoBox Base;
    public:
        enum SmsInfoBoxType {
                SmsClass0Type,
                SmsSendingType,
                SmsPendingType,
                SmsAddToPhonebookErrorType,
                SmsSetupCallErrorType,
                SmsDeleteMessage,
                SmsDeleteAllInbox,
                SmsDeleteAllOutbox,
                SmsDeleteAllReports,
                SmsDeleteAllArchive,
                SmsSendType,
                SmsStoreType,
                SmsRejectType,
                SmsSendErrorType,
                SmsSendErrorStoreOptionType,
                SmsStoreErrorType,
                SmsDeleteError
            };
        SmsInfoBox();
        ~SmsInfoBox();
        void Init();
        void SetSmsInfoBoxType(const SmsInfoBoxType &type);
        void SetErrorInfo(const SmsInfoBoxType &type, Sms::Result result_code, INT pending_seg_count);
    
        Tpdu& GetTpdu() {return m_tpdu;}
    private:
        virtual BOOLEAN OnConfirm();
        SmsInfoBox(const SmsInfoBox &);
        SmsInfoBox& operator=(const SmsInfoBox&);
        SmsSendingAnimation m_sending_anim;
        Tpdu m_tpdu;
};

#endif // Mmi_SmsAlerts_hpp

