/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsSettingsRecord_hpp)
#define Mmi_SmsSettingsRecord_hpp

#include <AddOns/AdcExtensions/Record.hpp>

class SmsSettingsRecord : public Record {
    typedef Record Base;

    public:
        enum Box {
            Inbox,
            Outbox,
            Archive,
            StatusReport
        };

        SmsSettingsRecord();

        void        SetDefault();

        void        SetReplyPathRequested(BOOLEAN flag)         { m_data.flags.reply_path = flag; }

        BOOLEAN     IsReplyPathRequested() const                { return m_data.flags.reply_path; }

        void        SetStatusReportEnabled(BOOLEAN flag)        { m_data.flags.status_report = flag; }

        BOOLEAN     IsStatusReportEnabled() const               { return m_data.flags.status_report; }

        void        SetStatusReportOnIdleScreen(BOOLEAN flag)   { m_data.flags.statrep_on_idlescreen = flag; }

        BOOLEAN     IsStatusReportOnIdleScreen() const          { return m_data.flags.status_report && m_data.flags.statrep_on_idlescreen; }

        void        SetGsmService(GsmService service)           { m_data.gsm_service = service; }

        GsmService  GetGsmService() const                       { return (GsmService)m_data.gsm_service; }

        void        SetSendingConfirmationEnabled(BOOLEAN flag) { m_data.flags.sending_confirmation = flag; }

        BOOLEAN     IsSendingConfirmationEnabled() const        { return m_data.flags.sending_confirmation; }

        void        SetAutoStoreEnabled(BOOLEAN flag)           { m_data.flags.autostore = flag; }

        BOOLEAN     IsAutoStorageEnabled() const                { return m_data.flags.autostore; }

        void        SetSendPreviewMandatory(BOOLEAN flag)       { m_data.flags.preview_mandatory = flag; }

        BOOLEAN     IsSendPreviewMandatory() const              { return m_data.flags.preview_mandatory; }

        void        SetLine2VoiceBoxNumber(const PhoneNumber& number){ number >> m_data.line2_voicebox_number; }

        PhoneNumber GetLine2VoiceBoxNumber() const;

        void        SetVoiceBoxNumber(const PhoneNumber& number){ number >> m_data.voicebox_number; }

        PhoneNumber GetVoiceBoxNumber() const;

        void        SetSorting(Box box, INT colid, BOOLEAN ascending = TRUE);

        INT         GetSortingColumnId(Box box) const;

        BOOLEAN     IsAscendingOrder(Box box) const;

        void        SetDefaultProfile(UINT8 profile) { m_data.profile = profile; }

        UINT8       GetDefaultProfile() { return m_data.profile; }

        void        SetStorageLocation(UINT8 storage_location) { m_data.storage_location = storage_location; }

        UINT8       GetStorageLocation() { return m_data.storage_location; }

        void        SetPredInputEnabled(BOOLEAN flag)           { m_data.flags.pred_input = flag; }

        BOOLEAN     IsPredInputEnabled() const              { return m_data.flags.pred_input; }

        // SMS settings data field definition
        struct Persist {
            struct {
                BOOLEAN sending_confirmation    : 2;    // true, confirmation dialog should be displayed before sending
                BOOLEAN reply_path              : 2;    // true, if reply path is requested
                BOOLEAN status_report           : 2;    // enables or disables receiving status reports
                BOOLEAN statrep_on_idlescreen   : 2;    // true, if status reports should be displayed immediately on idle screen
                BOOLEAN autostore               : 2;    // true, if all sent SMS should be stored automatically
                BOOLEAN preview_mandatory       : 2;    // true, if all SMS sent by a service should be displayed before sending
                BOOLEAN inbox_ascending_order   : 2;    // true, if inbox sort order is ascending
                BOOLEAN outbox_ascending_order  : 2;    // true, if outbox sort order is ascending
                BOOLEAN archive_ascending_order : 2;    // true, if archive sort order is ascending
                BOOLEAN statrep_ascending_order : 2;    // true, if status report sort order is ascending
                BOOLEAN pred_input              : 2;    // true, if pred input is enabled
            } flags;
            UINT8       profile;
            UINT8       storage_location;
            INT8        gsm_service;
            INT         inbox_sorting_colid;
            INT         outbox_sorting_colid;
            INT         archive_sorting_colid;
            INT         statrep_sorting_colid;
            PhoneNumber::Persist    voicebox_number;
            PhoneNumber::Persist    line2_voicebox_number;
        } m_data;

        virtual const UINT8* GetData();
        
        virtual void SetData(const UINT8* data);
        
        virtual INT GetPersistentSize();

        virtual void MarkDeleted();
        
        virtual BOOLEAN IsRecordDeleted();

        #ifndef APOXI_NOSTREAMING
            friend InputStream& operator >>(InputStream &istr, SmsSettingsRecord &tpdu);
            friend OutputStream& operator <<(OutputStream &ostr, const SmsSettingsRecord &tpdu);
        #endif
};

typedef SmsSettingsRecord::Box SmsBox;

#endif  // Mmi_SmsSettingsRecord_hpp
