/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "dallaros_stack_test_pu_dv\lnz_apoxi\Apoxi\Apc\MdhSmsArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_MdhSmsStackMsgArgs_hpp)
#define Apc_MdhSmsStackMsgArgs_hpp

#include <Apc/MdhTypes.hpp>
#include <Apc/Tpdu.hpp>
#include <Apc/Sms.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class MdhDeregistrationCnfArg
    ====================================================================== */

class MdhDeregistrationCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhDeregistrationCnfArg();
        
        static const MdhDeregistrationCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        
        enum  {
            ID = 5439
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhDeregistrationCnfArg*) arg); }
        
        MdhResult m_result;
        
    };

// Inline definitions
inline const MdhDeregistrationCnfArg& MdhDeregistrationCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhDeregistrationCnfArg!\n");
    return ((MdhDeregistrationCnfArg &) arg);
}



/*  ======================================================================
    Class MdhRegistrationCnfArg
    ====================================================================== */

class MdhRegistrationCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhRegistrationCnfArg();
        
        static const MdhRegistrationCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        
        enum  {
            ID = 5441
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhRegistrationCnfArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        
    };

// Inline definitions
inline const MdhRegistrationCnfArg& MdhRegistrationCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhRegistrationCnfArg!\n");
    return ((MdhRegistrationCnfArg &) arg);
}



/*  ======================================================================
    Class MdhSmsStatusIndArg
    ====================================================================== */

class MdhSmsStatusIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsStatusIndArg();
        
        static const MdhSmsStatusIndArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetLastUsed(UINT8 last_used) { m_last_used = last_used; }
        UINT8 GetLastUsed() const { return m_last_used; }
        void SetNotification(UINT8 notification) { m_notification = notification; }
        UINT8 GetNotification() const { return m_notification; }
        
        enum  {
            ID = 5444
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsStatusIndArg*) arg); }
        
        MdhResult m_result;
        UINT8 m_last_used;
        UINT8 m_notification;
        
    };

// Inline definitions
inline const MdhSmsStatusIndArg& MdhSmsStatusIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsStatusIndArg!\n");
    return ((MdhSmsStatusIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsUpdStatusIndArg
    ====================================================================== */

class MdhSmsUpdStatusIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsUpdStatusIndArg();
        
        static const MdhSmsUpdStatusIndArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        
        enum  {
            ID = 5446
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsUpdStatusIndArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        INT m_recno;
        
    };

// Inline definitions
inline const MdhSmsUpdStatusIndArg& MdhSmsUpdStatusIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsUpdStatusIndArg!\n");
    return ((MdhSmsUpdStatusIndArg &) arg);
}



/*  ======================================================================
    Class MdhSetStorageCnfArg
    ====================================================================== */

class MdhSetStorageCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSetStorageCnfArg();
        
        static const MdhSetStorageCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        
        enum  {
            ID = 5448
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSetStorageCnfArg*) arg); }
        
        MdhResult m_result;
        
    };

// Inline definitions
inline const MdhSetStorageCnfArg& MdhSetStorageCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSetStorageCnfArg!\n");
    return ((MdhSetStorageCnfArg &) arg);
}



/*  ======================================================================
    Class MdhSmsReadIndArg
    ====================================================================== */

class MdhSmsReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsReadIndArg();
        
        static const MdhSmsReadIndArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetSmsId(INT sms_id) { m_sms_id = sms_id; }
        INT GetSmsId() const { return m_sms_id; }
        void SetTpduConc(const TpduConc& tpdu_conc) { m_tpdu_conc = tpdu_conc; }
        const TpduConc& GetTpduConc() const { return m_tpdu_conc; }
        void SetTimeStamp(const MdhTimeStamp& time_stamp) { m_time_stamp = time_stamp; }
        const MdhTimeStamp& GetTimeStamp() const { return m_time_stamp; }
        void SetExtendedData(const MdhExtendedData& extended_data) { m_extended_data = extended_data; }
        const MdhExtendedData& GetExtendedData() const { return m_extended_data; }
        
        enum  {
            ID = 5450
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsReadIndArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        INT m_sms_id;
        TpduConc m_tpdu_conc;
        MdhTimeStamp m_time_stamp;
        MdhExtendedData m_extended_data;
        
    };

// Inline definitions
inline const MdhSmsReadIndArg& MdhSmsReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsReadIndArg!\n");
    return ((MdhSmsReadIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsWriteCnfArg
    ====================================================================== */

class MdhSmsWriteCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsWriteCnfArg();
        
        static const MdhSmsWriteCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetSmsId(INT sms_id) { m_sms_id = sms_id; }
        INT GetSmsId() const { return m_sms_id; }
        void SetNoOfSaved(UINT8 no_of_saved) { m_no_of_saved = no_of_saved; }
        UINT8 GetNoOfSaved() const { return m_no_of_saved; }
        void SetTimeStamp(const MdhTimeStamp& time_stamp) { m_time_stamp = time_stamp; }
        const MdhTimeStamp& GetTimeStamp() const { return m_time_stamp; }
        
        enum  {
            ID = 5452
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsWriteCnfArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        INT m_sms_id;
        UINT8 m_no_of_saved;
        MdhTimeStamp m_time_stamp;
        
    };

// Inline definitions
inline const MdhSmsWriteCnfArg& MdhSmsWriteCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsWriteCnfArg!\n");
    return ((MdhSmsWriteCnfArg &) arg);
}



/*  ======================================================================
    Class MdhSetConfigCnfArg
    ====================================================================== */

class MdhSetConfigCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSetConfigCnfArg();
        
        static const MdhSetConfigCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        
        enum  {
            ID = 5456
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSetConfigCnfArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        
    };

// Inline definitions
inline const MdhSetConfigCnfArg& MdhSetConfigCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSetConfigCnfArg!\n");
    return ((MdhSetConfigCnfArg &) arg);
}



/*  ======================================================================
    Class MdhMakeViewCnfArg
    ====================================================================== */

class MdhMakeViewCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhMakeViewCnfArg();
        
        static const MdhMakeViewCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        
        enum  {
            ID = 5458
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhMakeViewCnfArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        
    };

// Inline definitions
inline const MdhMakeViewCnfArg& MdhMakeViewCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhMakeViewCnfArg!\n");
    return ((MdhMakeViewCnfArg &) arg);
}



/*  ======================================================================
    Class MdhRemoveViewCnfArg
    ====================================================================== */

class MdhRemoveViewCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhRemoveViewCnfArg();
        
        static const MdhRemoveViewCnfArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        
        enum  {
            ID = 5460
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhRemoveViewCnfArg*) arg); }
        
        MdhResult m_result;
        MdhViewHdl m_view_hdl;
        
    };

// Inline definitions
inline const MdhRemoveViewCnfArg& MdhRemoveViewCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhRemoveViewCnfArg!\n");
    return ((MdhRemoveViewCnfArg &) arg);
}



/*  ======================================================================
    Class MdhNewStatusReportIndArg
    ====================================================================== */

class MdhNewStatusReportIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhNewStatusReportIndArg();
        
        static const MdhNewStatusReportIndArg& Cast(const StackMsgArgument& arg);
        void SetSmsrLocation(const MdhSmsrLocation& smsr_location) { m_smsr_location = smsr_location; }
        const MdhSmsrLocation& GetSmsrLocation() const { return m_smsr_location; }
        void SetLink(INT link) { m_link = link; }
        INT GetLink() const { return m_link; }
        void SetSrPos(INT sr_pos) { m_sr_pos = sr_pos; }
        INT GetSrPos() const { return m_sr_pos; }
        void SetSrStatus(UINT8 sr_status) { m_sr_status = sr_status; }
        UINT8 GetSrStatus() const { return m_sr_status; }
        void SetTpdu(const Tpdu& tpdu) { m_tpdu = tpdu; }
        const Tpdu& GetTpdu() const { return m_tpdu; }
        
        enum  {
            ID = 5463
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhNewStatusReportIndArg*) arg); }
        
        MdhSmsrLocation m_smsr_location;
        INT m_link;
        INT m_sr_pos;
        UINT8 m_sr_status;
        Tpdu m_tpdu;
        
    };

// Inline definitions
inline const MdhNewStatusReportIndArg& MdhNewStatusReportIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhNewStatusReportIndArg!\n");
    return ((MdhNewStatusReportIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsRefreshIndArg
    ====================================================================== */

class MdhSmsRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsRefreshIndArg();
        
        static const MdhSmsRefreshIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(UINT8 status) { m_status = status; }
        UINT8 GetStatus() const { return m_status; }
        void SetStoragePosition(INT storage_position) { m_storage_position = storage_position; }
        INT GetStoragePosition() const { return m_storage_position; }
        void SetTimeStamp(const MdhTimeStamp& time_stamp) { m_time_stamp = time_stamp; }
        const MdhTimeStamp& GetTimeStamp() const { return m_time_stamp; }
        
        enum  {
            ID = 5464
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsRefreshIndArg*) arg); }
        
        UINT8 m_status;
        INT m_storage_position;
        MdhTimeStamp m_time_stamp;
        
    };

// Inline definitions
inline const MdhSmsRefreshIndArg& MdhSmsRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsRefreshIndArg!\n");
    return ((MdhSmsRefreshIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsStorageRefreshIndArg
    ====================================================================== */

class MdhSmsStorageRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsStorageRefreshIndArg();
        
        static const MdhSmsStorageRefreshIndArg& Cast(const StackMsgArgument& arg);
        void SetWorkMedia(const MdhWorkMedia& work_media) { m_work_media = work_media; }
        const MdhWorkMedia& GetWorkMedia() const { return m_work_media; }
        
        enum  {
            ID = 5465
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsStorageRefreshIndArg*) arg); }
        
        MdhWorkMedia m_work_media;
        
    };

// Inline definitions
inline const MdhSmsStorageRefreshIndArg& MdhSmsStorageRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsStorageRefreshIndArg!\n");
    return ((MdhSmsStorageRefreshIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsUpdStatusRefreshIndArg
    ====================================================================== */

class MdhSmsUpdStatusRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsUpdStatusRefreshIndArg();
        
        static const MdhSmsUpdStatusRefreshIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(UINT8 status) { m_status = status; }
        UINT8 GetStatus() const { return m_status; }
        void SetStoragePosition(INT storage_position) { m_storage_position = storage_position; }
        INT GetStoragePosition() const { return m_storage_position; }
        
        enum  {
            ID = 5466
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsUpdStatusRefreshIndArg*) arg); }
        
        UINT8 m_status;
        INT m_storage_position;
        
    };

// Inline definitions
inline const MdhSmsUpdStatusRefreshIndArg& MdhSmsUpdStatusRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsUpdStatusRefreshIndArg!\n");
    return ((MdhSmsUpdStatusRefreshIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsNewMessageIndArg
    ====================================================================== */

class MdhSmsNewMessageIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsNewMessageIndArg();
        
        static const MdhSmsNewMessageIndArg& Cast(const StackMsgArgument& arg);
        void SetStorageType(const Sms::StorageType& storage_type) { m_storage_type = storage_type; }
        const Sms::StorageType& GetStorageType() const { return m_storage_type; }
        void SetStoragePosition(INT storage_position) { m_storage_position = storage_position; }
        INT GetStoragePosition() const { return m_storage_position; }
        void SetProtocolIdentifier(const ProtocolIdentifier& protocol_identifier) { m_protocol_identifier = protocol_identifier; }
        const ProtocolIdentifier& GetProtocolIdentifier() const { return m_protocol_identifier; }
        void SetDataCodingScheme(const DataCodingScheme& data_coding_scheme) { m_data_coding_scheme = data_coding_scheme; }
        const DataCodingScheme& GetDataCodingScheme() const { return m_data_coding_scheme; }
        void SetUpdated(BOOLEAN updated) { m_updated = updated; }
        BOOLEAN IsUpdated() const { return m_updated; }
        void SetWaitIndicatorArray(const MdhWaitIndicatorArray& wait_indicator_array) { m_wait_indicator_array = wait_indicator_array; }
        const MdhWaitIndicatorArray& GetWaitIndicatorArray() const { return m_wait_indicator_array; }
        void SetTpdu(const Tpdu& tpdu) { m_tpdu = tpdu; }
        const Tpdu& GetTpdu() const { return m_tpdu; }
        
        enum  {
            ID = 5467
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsNewMessageIndArg*) arg); }
        
        Sms::StorageType m_storage_type;
        INT m_storage_position;
        ProtocolIdentifier m_protocol_identifier;
        DataCodingScheme m_data_coding_scheme;
        BOOLEAN m_updated;
        MdhWaitIndicatorArray m_wait_indicator_array;
        Tpdu m_tpdu;
        
    };

// Inline definitions
inline const MdhSmsNewMessageIndArg& MdhSmsNewMessageIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsNewMessageIndArg!\n");
    return ((MdhSmsNewMessageIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsInitFinishedIndArg
    ====================================================================== */

class MdhSmsInitFinishedIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsInitFinishedIndArg();
        
        static const MdhSmsInitFinishedIndArg& Cast(const StackMsgArgument& arg);
        void SetUpdated(BOOLEAN updated) { m_updated = updated; }
        BOOLEAN IsUpdated() const { return m_updated; }
        void SetWaitIndicatorArray(const MdhWaitIndicatorArray& wait_indicator_array) { m_wait_indicator_array = wait_indicator_array; }
        const MdhWaitIndicatorArray& GetWaitIndicatorArray() const { return m_wait_indicator_array; }
        
        enum  {
            ID = 5468
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsInitFinishedIndArg*) arg); }
        
        BOOLEAN m_updated;
        MdhWaitIndicatorArray m_wait_indicator_array;
        
    };

// Inline definitions
inline const MdhSmsInitFinishedIndArg& MdhSmsInitFinishedIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsInitFinishedIndArg!\n");
    return ((MdhSmsInitFinishedIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsWaitingIndArg
    ====================================================================== */

class MdhSmsWaitingIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsWaitingIndArg();
        
        static const MdhSmsWaitingIndArg& Cast(const StackMsgArgument& arg);
        void SetUpdated(BOOLEAN updated) { m_updated = updated; }
        BOOLEAN IsUpdated() const { return m_updated; }
        void SetWaitIndicatorArray(const MdhWaitIndicatorArray& wait_indicator_array) { m_wait_indicator_array = wait_indicator_array; }
        const MdhWaitIndicatorArray& GetWaitIndicatorArray() const { return m_wait_indicator_array; }
        
        enum  {
            ID = 5469
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsWaitingIndArg*) arg); }
        
        BOOLEAN m_updated;
        MdhWaitIndicatorArray m_wait_indicator_array;
        
    };

// Inline definitions
inline const MdhSmsWaitingIndArg& MdhSmsWaitingIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsWaitingIndArg!\n");
    return ((MdhSmsWaitingIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsTransmitStartIndArg
    ====================================================================== */

class MdhSmsTransmitStartIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsTransmitStartIndArg();
        
        static const MdhSmsTransmitStartIndArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetTransmitCause(const MdhTransmitCause& transmit_cause) { m_transmit_cause = transmit_cause; }
        const MdhTransmitCause& GetTransmitCause() const { return m_transmit_cause; }
        void SetNoNvramSms(INT no_nvram_sms) { m_no_nvram_sms = no_nvram_sms; }
        INT GetNoNvramSms() const { return m_no_nvram_sms; }
        void SetNoSimSms(INT no_sim_sms) { m_no_sim_sms = no_sim_sms; }
        INT GetNoSimSms() const { return m_no_sim_sms; }
        
        enum  {
            ID = 5470
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsTransmitStartIndArg*) arg); }
        
        UINT8 m_view;
        MdhTransmitCause m_transmit_cause;
        INT m_no_nvram_sms;
        INT m_no_sim_sms;
        
    };

// Inline definitions
inline const MdhSmsTransmitStartIndArg& MdhSmsTransmitStartIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsTransmitStartIndArg!\n");
    return ((MdhSmsTransmitStartIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsTransmitIndArg
    ====================================================================== */

class MdhSmsTransmitIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsTransmitIndArg();
        
        static const MdhSmsTransmitIndArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        void SetTpdu(const Tpdu& tpdu) { m_tpdu = tpdu; }
        const Tpdu& GetTpdu() const { return m_tpdu; }
        void SetWorkMedia(const MdhWorkMedia& work_media) { m_work_media = work_media; }
        const MdhWorkMedia& GetWorkMedia() const { return m_work_media; }
        void SetTimeStamp(const MdhTimeStamp& time_stamp) { m_time_stamp = time_stamp; }
        const MdhTimeStamp& GetTimeStamp() const { return m_time_stamp; }
        void SetExtendedData(const MdhExtendedData& extended_data) { m_extended_data = extended_data; }
        const MdhExtendedData& GetExtendedData() const { return m_extended_data; }
        
        enum  {
            ID = 5471
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsTransmitIndArg*) arg); }
        
        UINT8 m_view;
        INT m_position;
        Tpdu m_tpdu;
        MdhWorkMedia m_work_media;
        MdhTimeStamp m_time_stamp;
        MdhExtendedData m_extended_data;
        
    };

// Inline definitions
inline const MdhSmsTransmitIndArg& MdhSmsTransmitIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsTransmitIndArg!\n");
    return ((MdhSmsTransmitIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsTransmitStopIndArg
    ====================================================================== */

class MdhSmsTransmitStopIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsTransmitStopIndArg();
        
        static const MdhSmsTransmitStopIndArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        
        enum  {
            ID = 5472
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsTransmitStopIndArg*) arg); }
        
        UINT8 m_view;
        MdhResult m_result;
        
    };

// Inline definitions
inline const MdhSmsTransmitStopIndArg& MdhSmsTransmitStopIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsTransmitStopIndArg!\n");
    return ((MdhSmsTransmitStopIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsReportReadIndArg
    ====================================================================== */

class MdhSmsReportReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsReportReadIndArg();
        
        static const MdhSmsReportReadIndArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetLinkRecNo(INT link_rec_no) { m_link_rec_no = link_rec_no; }
        INT GetLinkRecNo() const { return m_link_rec_no; }
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetSmsrData(const SmsrData& smsr_data) { m_smsr_data = smsr_data; }
        const SmsrData& GetSmsrData() const { return m_smsr_data; }
        void SetLocation(const MdhSmsrLocation& location) { m_location = location; }
        const MdhSmsrLocation& GetLocation() const { return m_location; }
        
        enum  {
            ID = 5473
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsReportReadIndArg*) arg); }
        
        MdhResult m_result;
        UINT8 m_view;
        INT m_link_rec_no;
        INT m_rec_no;
        SmsrData m_smsr_data;
        MdhSmsrLocation m_location;
        
    };

// Inline definitions
inline const MdhSmsReportReadIndArg& MdhSmsReportReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsReportReadIndArg!\n");
    return ((MdhSmsReportReadIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsConcRefNumIndArg
    ====================================================================== */

class MdhSmsConcRefNumIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsConcRefNumIndArg();
        
        static const MdhSmsConcRefNumIndArg& Cast(const StackMsgArgument& arg);
        void SetRefNo(UINT16 ref_no) { m_ref_no = ref_no; }
        UINT16 GetRefNo() const { return m_ref_no; }
        
        enum  {
            ID = 5474
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsConcRefNumIndArg*) arg); }
        
        UINT16 m_ref_no;
        
    };

// Inline definitions
inline const MdhSmsConcRefNumIndArg& MdhSmsConcRefNumIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsConcRefNumIndArg!\n");
    return ((MdhSmsConcRefNumIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsDeletionIndArg
    ====================================================================== */

class MdhSmsDeletionIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsDeletionIndArg();
        
        static const MdhSmsDeletionIndArg& Cast(const StackMsgArgument& arg);
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetDeletionCmd(const MdhDeletionCmd& deletion_cmd) { m_deletion_cmd = deletion_cmd; }
        const MdhDeletionCmd& GetDeletionCmd() const { return m_deletion_cmd; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        void SetGors(const MdhGors& gors) { m_gors = gors; }
        const MdhGors& GetGors() const { return m_gors; }
        
        enum  {
            ID = 5475
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsDeletionIndArg*) arg); }
        
        MdhResult m_result;
        UINT8 m_view;
        MdhDeletionCmd m_deletion_cmd;
        INT m_position;
        MdhGors m_gors;
        
    };

// Inline definitions
inline const MdhSmsDeletionIndArg& MdhSmsDeletionIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsDeletionIndArg!\n");
    return ((MdhSmsDeletionIndArg &) arg);
}



/*  ======================================================================
    Class MdhSmsExtendedDataIndArg
    ====================================================================== */

class MdhSmsExtendedDataIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsExtendedDataIndArg();
        
        static const MdhSmsExtendedDataIndArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetResult(const MdhResult& result) { m_result = result; }
        const MdhResult& GetResult() const { return m_result; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        
        enum  {
            ID = 5476
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsExtendedDataIndArg*) arg); }
        
        UINT8 m_view;
        MdhResult m_result;
        INT m_position;
        
    };

// Inline definitions
inline const MdhSmsExtendedDataIndArg& MdhSmsExtendedDataIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsExtendedDataIndArg!\n");
    return ((MdhSmsExtendedDataIndArg &) arg);
}



/*  ======================================================================
    Class MdhDeregistrationReqArg
    ====================================================================== */

class MdhDeregistrationReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhDeregistrationReqArg();
        
        static const MdhDeregistrationReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 6438
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhDeregistrationReqArg*) arg); }
        
    };

// Inline definitions
inline const MdhDeregistrationReqArg& MdhDeregistrationReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhDeregistrationReqArg!\n");
    return ((MdhDeregistrationReqArg &) arg);
}



/*  ======================================================================
    Class MdhRegistrationReqArg
    ====================================================================== */

class MdhRegistrationReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhRegistrationReqArg();
        
        static const MdhRegistrationReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 6440
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhRegistrationReqArg*) arg); }
        
    };

// Inline definitions
inline const MdhRegistrationReqArg& MdhRegistrationReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhRegistrationReqArg!\n");
    return ((MdhRegistrationReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsStatusReqArg
    ====================================================================== */

class MdhSmsStatusReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsStatusReqArg();
        
        static const MdhSmsStatusReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 6443
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsStatusReqArg*) arg); }
        
    };

// Inline definitions
inline const MdhSmsStatusReqArg& MdhSmsStatusReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsStatusReqArg!\n");
    return ((MdhSmsStatusReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsUpdStatusReqArg
    ====================================================================== */

class MdhSmsUpdStatusReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsUpdStatusReqArg(const MdhViewHdl& view_hdl, INT sms_id, UINT8 recstatus, UINT8 complete);
        MdhSmsUpdStatusReqArg();
        
        static const MdhSmsUpdStatusReqArg& Cast(const StackMsgArgument& arg);
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetSmsId(INT sms_id) { m_sms_id = sms_id; }
        INT GetSmsId() const { return m_sms_id; }
        void SetRecstatus(UINT8 recstatus) { m_recstatus = recstatus; }
        UINT8 GetRecstatus() const { return m_recstatus; }
        void SetComplete(UINT8 complete) { m_complete = complete; }
        UINT8 GetComplete() const { return m_complete; }
        
        enum  {
            ID = 6445
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsUpdStatusReqArg*) arg); }
        
        MdhViewHdl m_view_hdl;
        INT m_sms_id;
        UINT8 m_recstatus;
        UINT8 m_complete;
        
    };

// Inline definitions
inline const MdhSmsUpdStatusReqArg& MdhSmsUpdStatusReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsUpdStatusReqArg!\n");
    return ((MdhSmsUpdStatusReqArg &) arg);
}



/*  ======================================================================
    Class MdhSetStorageReqArg
    ====================================================================== */

class MdhSetStorageReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSetStorageReqArg(const MdhWorkMedia& stor_media);
        MdhSetStorageReqArg();
        
        static const MdhSetStorageReqArg& Cast(const StackMsgArgument& arg);
        void SetStorMedia(const MdhWorkMedia& stor_media) { m_stor_media = stor_media; }
        const MdhWorkMedia& GetStorMedia() const { return m_stor_media; }
        
        enum  {
            ID = 6447
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSetStorageReqArg*) arg); }
        
        MdhWorkMedia m_stor_media;
        
    };

// Inline definitions
inline const MdhSetStorageReqArg& MdhSetStorageReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSetStorageReqArg!\n");
    return ((MdhSetStorageReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsReadReqArg
    ====================================================================== */

class MdhSmsReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsReadReqArg(const MdhViewHdl& view_hdl, INT sms_id = 0);
        MdhSmsReadReqArg();
        
        static const MdhSmsReadReqArg& Cast(const StackMsgArgument& arg);
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetSmsId(INT sms_id) { m_sms_id = sms_id; }
        INT GetSmsId() const { return m_sms_id; }
        
        enum  {
            ID = 6449
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsReadReqArg*) arg); }
        
        MdhViewHdl m_view_hdl;
        INT m_sms_id;
        
    };

// Inline definitions
inline const MdhSmsReadReqArg& MdhSmsReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsReadReqArg!\n");
    return ((MdhSmsReadReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsWriteReqArg
    ====================================================================== */

class MdhSmsWriteReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsWriteReqArg(const MdhViewHdl& view_hdl, INT sms_id, const TpduNode& pdu_node);
        MdhSmsWriteReqArg();
        
        static const MdhSmsWriteReqArg& Cast(const StackMsgArgument& arg);
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetSmsId(INT sms_id) { m_sms_id = sms_id; }
        INT GetSmsId() const { return m_sms_id; }
        void SetPduNode(const TpduNode& pdu_node) { m_pdu_node = pdu_node; }
        const TpduNode& GetPduNode() const { return m_pdu_node; }
        
        enum  {
            ID = 6451
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsWriteReqArg*) arg); }
        
        MdhViewHdl m_view_hdl;
        INT m_sms_id;
        TpduNode m_pdu_node;
        
    };

// Inline definitions
inline const MdhSmsWriteReqArg& MdhSmsWriteReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsWriteReqArg!\n");
    return ((MdhSmsWriteReqArg &) arg);
}



/*  ======================================================================
    Class MdhSetConfigReqArg
    ====================================================================== */

class MdhSetConfigReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSetConfigReqArg(const MdhViewHdl& view_hdl, const MdhViewConfig& view_config);
        MdhSetConfigReqArg();
        
        static const MdhSetConfigReqArg& Cast(const StackMsgArgument& arg);
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        void SetViewConfig(const MdhViewConfig& view_config) { m_view_config = view_config; }
        const MdhViewConfig& GetViewConfig() const { return m_view_config; }
        
        enum  {
            ID = 6455
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSetConfigReqArg*) arg); }
        
        MdhViewHdl m_view_hdl;
        MdhViewConfig m_view_config;
        
    };

// Inline definitions
inline const MdhSetConfigReqArg& MdhSetConfigReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSetConfigReqArg!\n");
    return ((MdhSetConfigReqArg &) arg);
}



/*  ======================================================================
    Class MdhMakeViewReqArg
    ====================================================================== */

class MdhMakeViewReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhMakeViewReqArg();
        
        static const MdhMakeViewReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 6457
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhMakeViewReqArg*) arg); }
        
    };

// Inline definitions
inline const MdhMakeViewReqArg& MdhMakeViewReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhMakeViewReqArg!\n");
    return ((MdhMakeViewReqArg &) arg);
}



/*  ======================================================================
    Class MdhRemoveViewReqArg
    ====================================================================== */

class MdhRemoveViewReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhRemoveViewReqArg(const MdhViewHdl& view_hdl);
        MdhRemoveViewReqArg();
        
        static const MdhRemoveViewReqArg& Cast(const StackMsgArgument& arg);
        void SetViewHdl(const MdhViewHdl& view_hdl) { m_view_hdl = view_hdl; }
        const MdhViewHdl& GetViewHdl() const { return m_view_hdl; }
        
        enum  {
            ID = 6459
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhRemoveViewReqArg*) arg); }
        
        MdhViewHdl m_view_hdl;
        
    };

// Inline definitions
inline const MdhRemoveViewReqArg& MdhRemoveViewReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhRemoveViewReqArg!\n");
    return ((MdhRemoveViewReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsSetWaitingReqArg
    ====================================================================== */

class MdhSmsSetWaitingReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsSetWaitingReqArg(const MdhSetWaitIndicatorArray& set_wait_indicator_array);
        MdhSmsSetWaitingReqArg();
        
        static const MdhSmsSetWaitingReqArg& Cast(const StackMsgArgument& arg);
        void SetSetWaitIndicatorArray(const MdhSetWaitIndicatorArray& set_wait_indicator_array) { m_set_wait_indicator_array = set_wait_indicator_array; }
        const MdhSetWaitIndicatorArray& GetSetWaitIndicatorArray() const { return m_set_wait_indicator_array; }
        
        enum  {
            ID = 6462
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsSetWaitingReqArg*) arg); }
        
        MdhSetWaitIndicatorArray m_set_wait_indicator_array;
        
    };

// Inline definitions
inline const MdhSmsSetWaitingReqArg& MdhSmsSetWaitingReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsSetWaitingReqArg!\n");
    return ((MdhSmsSetWaitingReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsTransmitStartAckArg
    ====================================================================== */

class MdhSmsTransmitStartAckArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsTransmitStartAckArg(UINT8 view, BOOLEAN shall_transmit);
        MdhSmsTransmitStartAckArg();
        
        static const MdhSmsTransmitStartAckArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetShallTransmit(BOOLEAN shall_transmit) { m_shall_transmit = shall_transmit; }
        BOOLEAN IsShallTransmit() const { return m_shall_transmit; }
        
        enum  {
            ID = 6463
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsTransmitStartAckArg*) arg); }
        
        UINT8 m_view;
        BOOLEAN m_shall_transmit;
        
    };

// Inline definitions
inline const MdhSmsTransmitStartAckArg& MdhSmsTransmitStartAckArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsTransmitStartAckArg!\n");
    return ((MdhSmsTransmitStartAckArg &) arg);
}



/*  ======================================================================
    Class MdhSmsTransmitAckArg
    ====================================================================== */

class MdhSmsTransmitAckArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsTransmitAckArg(UINT8 view, INT position, BOOLEAN shall_transmit);
        MdhSmsTransmitAckArg();
        
        static const MdhSmsTransmitAckArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        void SetShallTransmit(BOOLEAN shall_transmit) { m_shall_transmit = shall_transmit; }
        BOOLEAN IsShallTransmit() const { return m_shall_transmit; }
        
        enum  {
            ID = 6464
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsTransmitAckArg*) arg); }
        
        UINT8 m_view;
        INT m_position;
        BOOLEAN m_shall_transmit;
        
    };

// Inline definitions
inline const MdhSmsTransmitAckArg& MdhSmsTransmitAckArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsTransmitAckArg!\n");
    return ((MdhSmsTransmitAckArg &) arg);
}



/*  ======================================================================
    Class MdhSmsReportReadReqArg
    ====================================================================== */

class MdhSmsReportReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsReportReadReqArg(UINT8 view, INT position);
        MdhSmsReportReadReqArg();
        
        static const MdhSmsReportReadReqArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        
        enum  {
            ID = 6465
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsReportReadReqArg*) arg); }
        
        UINT8 m_view;
        INT m_position;
        
    };

// Inline definitions
inline const MdhSmsReportReadReqArg& MdhSmsReportReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsReportReadReqArg!\n");
    return ((MdhSmsReportReadReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsConcRefNumReqArg
    ====================================================================== */

class MdhSmsConcRefNumReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsConcRefNumReqArg();
        
        static const MdhSmsConcRefNumReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 6466
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsConcRefNumReqArg*) arg); }
        
    };

// Inline definitions
inline const MdhSmsConcRefNumReqArg& MdhSmsConcRefNumReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsConcRefNumReqArg!\n");
    return ((MdhSmsConcRefNumReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsDeletionReqArg
    ====================================================================== */

class MdhSmsDeletionReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsDeletionReqArg(UINT8 view, const MdhDeletionCmd& deletion_cmd, INT position);
        MdhSmsDeletionReqArg();
        
        static const MdhSmsDeletionReqArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetDeletionCmd(const MdhDeletionCmd& deletion_cmd) { m_deletion_cmd = deletion_cmd; }
        const MdhDeletionCmd& GetDeletionCmd() const { return m_deletion_cmd; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        
        enum  {
            ID = 6467
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsDeletionReqArg*) arg); }
        
        UINT8 m_view;
        MdhDeletionCmd m_deletion_cmd;
        INT m_position;
        
    };

// Inline definitions
inline const MdhSmsDeletionReqArg& MdhSmsDeletionReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsDeletionReqArg!\n");
    return ((MdhSmsDeletionReqArg &) arg);
}



/*  ======================================================================
    Class MdhSmsExtendedDataReqArg
    ====================================================================== */

class MdhSmsExtendedDataReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MdhSmsExtendedDataReqArg(UINT8 view, INT position, const MdhExtendedData& extended_data);
        MdhSmsExtendedDataReqArg();
        
        static const MdhSmsExtendedDataReqArg& Cast(const StackMsgArgument& arg);
        void SetView(UINT8 view) { m_view = view; }
        UINT8 GetView() const { return m_view; }
        void SetPosition(INT position) { m_position = position; }
        INT GetPosition() const { return m_position; }
        void SetExtendedData(const MdhExtendedData& extended_data) { m_extended_data = extended_data; }
        const MdhExtendedData& GetExtendedData() const { return m_extended_data; }
        
        enum  {
            ID = 6468
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MdhSmsExtendedDataReqArg*) arg); }
        
        UINT8 m_view;
        INT m_position;
        MdhExtendedData m_extended_data;
        
    };

// Inline definitions
inline const MdhSmsExtendedDataReqArg& MdhSmsExtendedDataReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MdhSmsExtendedDataReqArg!\n");
    return ((MdhSmsExtendedDataReqArg &) arg);
}


#endif // Apc_MdhSmsStackMsgArgs_hpp

