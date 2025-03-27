/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "hauth_mpeu_pu_dv\lnz_apoxi\Apoxi\Apc\CallMiscArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_CallMiscStackMsgArgs_hpp)
#define Apc_CallMiscStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Apc/SimTkTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class CallProgressIndArg
    ====================================================================== */

class CallProgressIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallProgressIndArg();
        
        static const CallProgressIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallProgressInd(const CallProgressInd& call_progress_ind) { m_call_progress_ind = call_progress_ind; }
        const CallProgressInd& GetCallProgressInd() const { return m_call_progress_ind; }
        
        enum  {
            ID = 1120
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallProgressIndArg*) arg); }
        
        Tipd m_tipd;
        CallProgressInd m_call_progress_ind;
        
    };

// Inline definitions
inline const CallProgressIndArg& CallProgressIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallProgressIndArg!\n");
    return ((CallProgressIndArg &) arg);
}



/*  ======================================================================
    Class CallDiscIndArg
    ====================================================================== */

class CallDiscIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallDiscIndArg();
        
        static const CallDiscIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallDiscCause(const CallErrorCause& call_disc_cause) { m_call_disc_cause = call_disc_cause; }
        const CallErrorCause& GetCallDiscCause() const { return m_call_disc_cause; }
        
        enum  {
            ID = 1121
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallDiscIndArg*) arg); }
        
        Tipd m_tipd;
        CallErrorCause m_call_disc_cause;
        
    };

// Inline definitions
inline const CallDiscIndArg& CallDiscIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallDiscIndArg!\n");
    return ((CallDiscIndArg &) arg);
}



/*  ======================================================================
    Class CallIndArg
    ====================================================================== */

class CallIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallIndArg();
        
        static const CallIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallState(const CallState& call_state) { m_call_state = call_state; }
        const CallState& GetCallState() const { return m_call_state; }
        void SetCallType(const CallType& call_type) { m_call_type = call_type; }
        const CallType& GetCallType() const { return m_call_type; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        void SetCallErrorCause(const CallErrorCause& call_error_cause) { m_call_error_cause = call_error_cause; }
        const CallErrorCause& GetCallErrorCause() const { return m_call_error_cause; }
        void SetCallLine(const LineSelector& call_line) { m_call_line = call_line; }
        const LineSelector& GetCallLine() const { return m_call_line; }
        void SetCtm(BOOLEAN ctm) { m_ctm = ctm; }
        BOOLEAN IsCtm() const { return m_ctm; }
        void SetEstablishCause(const CallEstCause& establish_cause) { m_establish_cause = establish_cause; }
        const CallEstCause& GetEstablishCause() const { return m_establish_cause; }
        void SetEccCategory(const EccCategory& ecc_category) { m_ecc_category = ecc_category; }
        const EccCategory& GetEccCategory() const { return m_ecc_category; }
        void SetDataCallType(const DataCallType& data_call_type) { m_data_call_type = data_call_type; }
        const DataCallType& GetDataCallType() const { return m_data_call_type; }
        
        enum  {
            ID = 1123
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallIndArg*) arg); }
        
        Tipd m_tipd;
        CallState m_call_state;
        CallType m_call_type;
        PhoneNumber m_phone_number;
        CallErrorCause m_call_error_cause;
        LineSelector m_call_line;
        BOOLEAN m_ctm;
        CallEstCause m_establish_cause;
        EccCategory m_ecc_category;
        DataCallType m_data_call_type;
        
    };

// Inline definitions
inline const CallIndArg& CallIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallIndArg!\n");
    return ((CallIndArg &) arg);
}



/*  ======================================================================
    Class StartDtmfCnfArg
    ====================================================================== */

class StartDtmfCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StartDtmfCnfArg();
        
        static const StartDtmfCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetKey(const KeyCode& key) { m_key = key; }
        const KeyCode& GetKey() const { return m_key; }
        
        enum  {
            ID = 1124
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StartDtmfCnfArg*) arg); }
        
        Tipd m_tipd;
        KeyCode m_key;
        
    };

// Inline definitions
inline const StartDtmfCnfArg& StartDtmfCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StartDtmfCnfArg!\n");
    return ((StartDtmfCnfArg &) arg);
}



/*  ======================================================================
    Class StopDtmfCnfArg
    ====================================================================== */

class StopDtmfCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StopDtmfCnfArg(const Tipd& tipd);
        StopDtmfCnfArg();
        ~StopDtmfCnfArg();
        
        static const StopDtmfCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1125
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StopDtmfCnfArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const StopDtmfCnfArg& StopDtmfCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StopDtmfCnfArg!\n");
    return ((StopDtmfCnfArg &) arg);
}



/*  ======================================================================
    Class StartDtmfRejArg
    ====================================================================== */

class StartDtmfRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StartDtmfRejArg();
        
        static const StartDtmfRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCause(const CallErrorCause& cause) { m_cause = cause; }
        const CallErrorCause& GetCause() const { return m_cause; }
        
        enum  {
            ID = 1126
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StartDtmfRejArg*) arg); }
        
        Tipd m_tipd;
        CallErrorCause m_cause;
        
    };

// Inline definitions
inline const StartDtmfRejArg& StartDtmfRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StartDtmfRejArg!\n");
    return ((StartDtmfRejArg &) arg);
}



/*  ======================================================================
    Class DtmfBufferClearedIndArg
    ====================================================================== */

class DtmfBufferClearedIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DtmfBufferClearedIndArg();
        
        static const DtmfBufferClearedIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1127
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DtmfBufferClearedIndArg*) arg); }
        
    };

// Inline definitions
inline const DtmfBufferClearedIndArg& DtmfBufferClearedIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DtmfBufferClearedIndArg!\n");
    return ((DtmfBufferClearedIndArg &) arg);
}



/*  ======================================================================
    Class NotifyIndArg
    ====================================================================== */

class NotifyIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        NotifyIndArg();
        
        static const NotifyIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetDescription(const NotificationDescription& description) { m_description = description; }
        const NotificationDescription& GetDescription() const { return m_description; }
        
        enum  {
            ID = 1128
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((NotifyIndArg*) arg); }
        
        Tipd m_tipd;
        NotificationDescription m_description;
        
    };

// Inline definitions
inline const NotifyIndArg& NotifyIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to NotifyIndArg!\n");
    return ((NotifyIndArg &) arg);
}



/*  ======================================================================
    Class CallRelCnfArg
    ====================================================================== */

class CallRelCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallRelCnfArg();
        
        static const CallRelCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1129
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallRelCnfArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const CallRelCnfArg& CallRelCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallRelCnfArg!\n");
    return ((CallRelCnfArg &) arg);
}



/*  ======================================================================
    Class CallRelIndArg
    ====================================================================== */

class CallRelIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallRelIndArg();
        
        static const CallRelIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallDiscCause(const CallErrorCause& call_disc_cause) { m_call_disc_cause = call_disc_cause; }
        const CallErrorCause& GetCallDiscCause() const { return m_call_disc_cause; }
        
        enum  {
            ID = 1131
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallRelIndArg*) arg); }
        
        Tipd m_tipd;
        CallErrorCause m_call_disc_cause;
        
    };

// Inline definitions
inline const CallRelIndArg& CallRelIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallRelIndArg!\n");
    return ((CallRelIndArg &) arg);
}



/*  ======================================================================
    Class DiagnosticIndArg
    ====================================================================== */

class DiagnosticIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DiagnosticIndArg();
        
        static const DiagnosticIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetDiagnosticCause(const DiagnosticCause& diagnostic_cause) { m_diagnostic_cause = diagnostic_cause; }
        const DiagnosticCause& GetDiagnosticCause() const { return m_diagnostic_cause; }
        
        enum  {
            ID = 1132
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DiagnosticIndArg*) arg); }
        
        Tipd m_tipd;
        DiagnosticCause m_diagnostic_cause;
        
    };

// Inline definitions
inline const DiagnosticIndArg& DiagnosticIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DiagnosticIndArg!\n");
    return ((DiagnosticIndArg &) arg);
}



/*  ======================================================================
    Class CtmInfoIndArg
    ====================================================================== */

class CtmInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CtmInfoIndArg();
        
        static const CtmInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCtm(BOOLEAN ctm) { m_ctm = ctm; }
        BOOLEAN IsCtm() const { return m_ctm; }
        
        enum  {
            ID = 1133
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CtmInfoIndArg*) arg); }
        
        Tipd m_tipd;
        BOOLEAN m_ctm;
        
    };

// Inline definitions
inline const CtmInfoIndArg& CtmInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CtmInfoIndArg!\n");
    return ((CtmInfoIndArg &) arg);
}



/*  ======================================================================
    Class CallSetupBySimtTkReqArg
    ====================================================================== */

class CallSetupBySimtTkReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallSetupBySimtTkReqArg();
        
        static const CallSetupBySimtTkReqArg& Cast(const StackMsgArgument& arg);
        void SetCause(const ProactiveCause& cause) { m_cause = cause; }
        const ProactiveCause& GetCause() const { return m_cause; }
        void SetStkCallSetupNo(const PhoneNumber& stk_call_setup_no) { m_stk_call_setup_no = stk_call_setup_no; }
        const PhoneNumber& GetStkCallSetupNo() const { return m_stk_call_setup_no; }
        void SetSimCallSetupOption(UINT8 sim_call_setup_option) { m_sim_call_setup_option = sim_call_setup_option; }
        UINT8 GetSimCallSetupOption() const { return m_sim_call_setup_option; }
        
        enum  {
            ID = 1134
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallSetupBySimtTkReqArg*) arg); }
        
        ProactiveCause m_cause;
        PhoneNumber m_stk_call_setup_no;
        UINT8 m_sim_call_setup_option;
        
    };

// Inline definitions
inline const CallSetupBySimtTkReqArg& CallSetupBySimtTkReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallSetupBySimtTkReqArg!\n");
    return ((CallSetupBySimtTkReqArg &) arg);
}



/*  ======================================================================
    Class RedialStatusIndArg
    ====================================================================== */

class RedialStatusIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RedialStatusIndArg();
        
        static const RedialStatusIndArg& Cast(const StackMsgArgument& arg);
        void SetRedialStatus(BOOLEAN redial_status) { m_redial_status = redial_status; }
        BOOLEAN IsRedialStatus() const { return m_redial_status; }
        
        enum  {
            ID = 1135
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RedialStatusIndArg*) arg); }
        
        BOOLEAN m_redial_status;
        
    };

// Inline definitions
inline const RedialStatusIndArg& RedialStatusIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RedialStatusIndArg!\n");
    return ((RedialStatusIndArg &) arg);
}



/*  ======================================================================
    Class CallIndCallControlInfoArg
    ====================================================================== */

class CallIndCallControlInfoArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallIndCallControlInfoArg();
        
        static const CallIndCallControlInfoArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallControlPerformed(BOOLEAN call_control_performed) { m_call_control_performed = call_control_performed; }
        BOOLEAN IsCallControlPerformed() const { return m_call_control_performed; }
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetAlphaIdentifier(const SimAlphaIdentifier& alpha_identifier) { m_alpha_identifier = alpha_identifier; }
        const SimAlphaIdentifier& GetAlphaIdentifier() const { return m_alpha_identifier; }
        
        enum  {
            ID = 1136
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallIndCallControlInfoArg*) arg); }
        
        Tipd m_tipd;
        BOOLEAN m_call_control_performed;
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_alpha_identifier;
        
    };

// Inline definitions
inline const CallIndCallControlInfoArg& CallIndCallControlInfoArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallIndCallControlInfoArg!\n");
    return ((CallIndCallControlInfoArg &) arg);
}



/*  ======================================================================
    Class MocSetupRejIndArg
    ====================================================================== */

class MocSetupRejIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MocSetupRejIndArg();
        
        static const MocSetupRejIndArg& Cast(const StackMsgArgument& arg);
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        void SetCause(const CallErrorCause& cause) { m_cause = cause; }
        const CallErrorCause& GetCause() const { return m_cause; }
        
        enum  {
            ID = 1137
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MocSetupRejIndArg*) arg); }
        
        PhoneNumber m_phone_number;
        CallErrorCause m_cause;
        
    };

// Inline definitions
inline const MocSetupRejIndArg& MocSetupRejIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MocSetupRejIndArg!\n");
    return ((MocSetupRejIndArg &) arg);
}



/*  ======================================================================
    Class CallDiscReqArg
    ====================================================================== */

class CallDiscReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallDiscReqArg(const Tipd& tipd, const CallErrorCause& call_disc_cause);
        CallDiscReqArg();
        
        static const CallDiscReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallDiscCause(const CallErrorCause& call_disc_cause) { m_call_disc_cause = call_disc_cause; }
        const CallErrorCause& GetCallDiscCause() const { return m_call_disc_cause; }
        
        enum  {
            ID = 2120
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallDiscReqArg*) arg); }
        
        Tipd m_tipd;
        CallErrorCause m_call_disc_cause;
        
    };

// Inline definitions
inline const CallDiscReqArg& CallDiscReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallDiscReqArg!\n");
    return ((CallDiscReqArg &) arg);
}



/*  ======================================================================
    Class StartDtmfReqArg
    ====================================================================== */

class StartDtmfReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StartDtmfReqArg(const Tipd& tipd, const KeyCode& key);
        StartDtmfReqArg();
        
        static const StartDtmfReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetKey(const KeyCode& key) { m_key = key; }
        const KeyCode& GetKey() const { return m_key; }
        
        enum  {
            ID = 2122
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StartDtmfReqArg*) arg); }
        
        Tipd m_tipd;
        KeyCode m_key;
        
    };

// Inline definitions
inline const StartDtmfReqArg& StartDtmfReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StartDtmfReqArg!\n");
    return ((StartDtmfReqArg &) arg);
}



/*  ======================================================================
    Class StopDtmfReqArg
    ====================================================================== */

class StopDtmfReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StopDtmfReqArg(const Tipd& tipd);
        StopDtmfReqArg();
        
        static const StopDtmfReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2123
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StopDtmfReqArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const StopDtmfReqArg& StopDtmfReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StopDtmfReqArg!\n");
    return ((StopDtmfReqArg &) arg);
}



/*  ======================================================================
    Class RejectCallsIndArg
    ====================================================================== */

class RejectCallsIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RejectCallsIndArg(BOOLEAN activated, const CallRefuseDirection& call_refuse_direction);
        RejectCallsIndArg();
        
        static const RejectCallsIndArg& Cast(const StackMsgArgument& arg);
        void SetActivated(BOOLEAN activated) { m_activated = activated; }
        BOOLEAN IsActivated() const { return m_activated; }
        void SetCallRefuseDirection(const CallRefuseDirection& call_refuse_direction) { m_call_refuse_direction = call_refuse_direction; }
        const CallRefuseDirection& GetCallRefuseDirection() const { return m_call_refuse_direction; }
        
        enum  {
            ID = 2124
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RejectCallsIndArg*) arg); }
        
        BOOLEAN m_activated;
        CallRefuseDirection m_call_refuse_direction;
        
    };

// Inline definitions
inline const RejectCallsIndArg& RejectCallsIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RejectCallsIndArg!\n");
    return ((RejectCallsIndArg &) arg);
}



/*  ======================================================================
    Class RedialQueryReqArg
    ====================================================================== */

class RedialQueryReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RedialQueryReqArg();
        
        static const RedialQueryReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2125
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RedialQueryReqArg*) arg); }
        
    };

// Inline definitions
inline const RedialQueryReqArg& RedialQueryReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RedialQueryReqArg!\n");
    return ((RedialQueryReqArg &) arg);
}


#endif // Apc_CallMiscStackMsgArgs_hpp

