/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "auzinger_apoxi_test_dv\lnz_apoxi\Apoxi\Apc\SsArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_SsStackMsgArgs_hpp)
#define Apc_SsStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/DataCodingScheme.hpp>
#include <Apc/TaggedProblemCode.hpp>
#include <Apc/SsErrorCode.hpp>
#include <Apc/SimTkTypes.hpp>
#include <Auxiliary/Vector.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SsBeginAccArg
    ====================================================================== */

class SsBeginAccArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsBeginAccArg();
        
        static const SsBeginAccArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1000
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsBeginAccArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsBeginAccArg& SsBeginAccArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsBeginAccArg!\n");
    return ((SsBeginAccArg &) arg);
}



/*  ======================================================================
    Class SsFacilityIndArg
    ====================================================================== */

class SsFacilityIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsFacilityIndArg();
        
        static const SsFacilityIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetSsSequence(const WString& ss_sequence) { m_ss_sequence = ss_sequence; }
        const WString& GetSsSequence() const { return m_ss_sequence; }
        void SetCallControlPerformed(BOOLEAN call_control_performed) { m_call_control_performed = call_control_performed; }
        BOOLEAN IsCallControlPerformed() const { return m_call_control_performed; }
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetAlphaIdentifier(const SimAlphaIdentifier& alpha_identifier) { m_alpha_identifier = alpha_identifier; }
        const SimAlphaIdentifier& GetAlphaIdentifier() const { return m_alpha_identifier; }
        
        enum  {
            ID = 1029
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsFacilityIndArg*) arg); }
        
        Tipd m_tipd;
        WString m_ss_sequence;
        BOOLEAN m_call_control_performed;
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_alpha_identifier;
        
    };

// Inline definitions
inline const SsFacilityIndArg& SsFacilityIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsFacilityIndArg!\n");
    return ((SsFacilityIndArg &) arg);
}



/*  ======================================================================
    Class SsFacilityRejArg
    ====================================================================== */

class SsFacilityRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsFacilityRejArg();
        
        static const SsFacilityRejArg& Cast(const StackMsgArgument& arg);
        void SetRejectCause(const MnCause& reject_cause) { m_reject_cause = reject_cause; }
        const MnCause& GetRejectCause() const { return m_reject_cause; }
        
        enum  {
            ID = 1001
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsFacilityRejArg*) arg); }
        
        MnCause m_reject_cause;
        
    };

// Inline definitions
inline const SsFacilityRejArg& SsFacilityRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsFacilityRejArg!\n");
    return ((SsFacilityRejArg &) arg);
}



/*  ======================================================================
    Class SsForwardingIndArg
    ====================================================================== */

class SsForwardingIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsForwardingIndArg();
        
        static const SsForwardingIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetForwardingInfo(const ForwardingInfo& forwarding_info) { m_forwarding_info = forwarding_info; }
        const ForwardingInfo& GetForwardingInfo() const { return m_forwarding_info; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1002
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsForwardingIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        ForwardingInfo m_forwarding_info;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsForwardingIndArg& SsForwardingIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsForwardingIndArg!\n");
    return ((SsForwardingIndArg &) arg);
}



/*  ======================================================================
    Class SsBarringIndArg
    ====================================================================== */

class SsBarringIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsBarringIndArg();
        
        static const SsBarringIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetCallBarringInfo(const CallBarringInfo& call_barring_info) { m_call_barring_info = call_barring_info; }
        const CallBarringInfo& GetCallBarringInfo() const { return m_call_barring_info; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1003
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsBarringIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        CallBarringInfo m_call_barring_info;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsBarringIndArg& SsBarringIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsBarringIndArg!\n");
    return ((SsBarringIndArg &) arg);
}



/*  ======================================================================
    Class SsDataIndArg
    ====================================================================== */

class SsDataIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsDataIndArg();
        
        static const SsDataIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetSsData(const SsData& ss_data) { m_ss_data = ss_data; }
        const SsData& GetSsData() const { return m_ss_data; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1004
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsDataIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        SsData m_ss_data;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsDataIndArg& SsDataIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsDataIndArg!\n");
    return ((SsDataIndArg &) arg);
}



/*  ======================================================================
    Class SsNotifyIndArg
    ====================================================================== */

class SsNotifyIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsNotifyIndArg();
        
        static const SsNotifyIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetSsOperationCode(const SsOperationCode& ss_operation_code) { m_ss_operation_code = ss_operation_code; }
        const SsOperationCode& GetSsOperationCode() const { return m_ss_operation_code; }
        void SetNotifySsArg(const NotifySsArg& notify_ss_arg) { m_notify_ss_arg = notify_ss_arg; }
        const NotifySsArg& GetNotifySsArg() const { return m_notify_ss_arg; }
        
        enum  {
            ID = 1005
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsNotifyIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_ss_operation_code;
        NotifySsArg m_notify_ss_arg;
        
    };

// Inline definitions
inline const SsNotifyIndArg& SsNotifyIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsNotifyIndArg!\n");
    return ((SsNotifyIndArg &) arg);
}



/*  ======================================================================
    Class SsInterrogateIndArg
    ====================================================================== */

class SsInterrogateIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsInterrogateIndArg();
        
        static const SsInterrogateIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetResult(const InterrogateSsResult& result) { m_result = result; }
        const InterrogateSsResult& GetResult() const { return m_result; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1006
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsInterrogateIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        InterrogateSsResult m_result;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsInterrogateIndArg& SsInterrogateIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsInterrogateIndArg!\n");
    return ((SsInterrogateIndArg &) arg);
}



/*  ======================================================================
    Class SsPasswordIndArg
    ====================================================================== */

class SsPasswordIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsPasswordIndArg();
        
        static const SsPasswordIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetPassword(const WString& password) { m_password = password; }
        const WString& GetPassword() const { return m_password; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1007
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsPasswordIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        WString m_password;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsPasswordIndArg& SsPasswordIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsPasswordIndArg!\n");
    return ((SsPasswordIndArg &) arg);
}



/*  ======================================================================
    Class SsUnstructIndArg
    ====================================================================== */

class SsUnstructIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUnstructIndArg();
        
        static const SsUnstructIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetCtrlInfoString(const WString& ctrl_info_string) { m_ctrl_info_string = ctrl_info_string; }
        const WString& GetCtrlInfoString() const { return m_ctrl_info_string; }
        void SetDcs(const DataCodingScheme& dcs) { m_dcs = dcs; }
        const DataCodingScheme& GetDcs() const { return m_dcs; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1008
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUnstructIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        WString m_ctrl_info_string;
        DataCodingScheme m_dcs;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsUnstructIndArg& SsUnstructIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUnstructIndArg!\n");
    return ((SsUnstructIndArg &) arg);
}



/*  ======================================================================
    Class SsForwcheckIndArg
    ====================================================================== */

class SsForwcheckIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsForwcheckIndArg();
        
        static const SsForwcheckIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        
        enum  {
            ID = 1009
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsForwcheckIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        
    };

// Inline definitions
inline const SsForwcheckIndArg& SsForwcheckIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsForwcheckIndArg!\n");
    return ((SsForwcheckIndArg &) arg);
}



/*  ======================================================================
    Class SsRetResIndArg
    ====================================================================== */

class SsRetResIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsRetResIndArg();
        
        static const SsRetResIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1010
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsRetResIndArg*) arg); }
        
        Tipd m_tipd;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsRetResIndArg& SsRetResIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsRetResIndArg!\n");
    return ((SsRetResIndArg &) arg);
}



/*  ======================================================================
    Class SsEndIndArg
    ====================================================================== */

class SsEndIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsEndIndArg();
        
        static const SsEndIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1011
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsEndIndArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsEndIndArg& SsEndIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsEndIndArg!\n");
    return ((SsEndIndArg &) arg);
}



/*  ======================================================================
    Class SsRejArg
    ====================================================================== */

class SsRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsRejArg();
        
        static const SsRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetTaggedProblemCode(const TaggedProblemCode& tagged_problem_code) { m_tagged_problem_code = tagged_problem_code; }
        const TaggedProblemCode& GetTaggedProblemCode() const { return m_tagged_problem_code; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1012
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsRejArg*) arg); }
        
        Tipd m_tipd;
        TaggedProblemCode m_tagged_problem_code;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsRejArg& SsRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsRejArg!\n");
    return ((SsRejArg &) arg);
}



/*  ======================================================================
    Class SsClientRejArg
    ====================================================================== */

class SsClientRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsClientRejArg();
        
        static const SsClientRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1019
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsClientRejArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsClientRejArg& SsClientRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsClientRejArg!\n");
    return ((SsClientRejArg &) arg);
}



/*  ======================================================================
    Class SsErrIndArg
    ====================================================================== */

class SsErrIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsErrIndArg();
        
        static const SsErrIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetSsErrorCode(const SsErrorCode& ss_error_code) { m_ss_error_code = ss_error_code; }
        const SsErrorCode& GetSsErrorCode() const { return m_ss_error_code; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1013
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsErrIndArg*) arg); }
        
        Tipd m_tipd;
        SsErrorCode m_ss_error_code;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsErrIndArg& SsErrIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsErrIndArg!\n");
    return ((SsErrIndArg &) arg);
}



/*  ======================================================================
    Class SsGetPasswordIndArg
    ====================================================================== */

class SsGetPasswordIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsGetPasswordIndArg();
        
        static const SsGetPasswordIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1014
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsGetPasswordIndArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsGetPasswordIndArg& SsGetPasswordIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsGetPasswordIndArg!\n");
    return ((SsGetPasswordIndArg &) arg);
}



/*  ======================================================================
    Class SsGetPasswordRejArg
    ====================================================================== */

class SsGetPasswordRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsGetPasswordRejArg();
        
        static const SsGetPasswordRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetRejectCause(const MnCause& reject_cause) { m_reject_cause = reject_cause; }
        const MnCause& GetRejectCause() const { return m_reject_cause; }
        
        enum  {
            ID = 1015
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsGetPasswordRejArg*) arg); }
        
        Tipd m_tipd;
        MnCause m_reject_cause;
        
    };

// Inline definitions
inline const SsGetPasswordRejArg& SsGetPasswordRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsGetPasswordRejArg!\n");
    return ((SsGetPasswordRejArg &) arg);
}



/*  ======================================================================
    Class SsCauseIndArg
    ====================================================================== */

class SsCauseIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCauseIndArg();
        
        static const SsCauseIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetRejectCause(const MnCause& reject_cause) { m_reject_cause = reject_cause; }
        const MnCause& GetRejectCause() const { return m_reject_cause; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1018
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCauseIndArg*) arg); }
        
        Tipd m_tipd;
        MnCause m_reject_cause;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsCauseIndArg& SsCauseIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCauseIndArg!\n");
    return ((SsCauseIndArg &) arg);
}



/*  ======================================================================
    Class SsUssdIndArg
    ====================================================================== */

class SsUssdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUssdIndArg();
        
        static const SsUssdIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetDcs(const DataCodingScheme& dcs) { m_dcs = dcs; }
        const DataCodingScheme& GetDcs() const { return m_dcs; }
        void SetCtrlInfoString(const WString& ctrl_info_string) { m_ctrl_info_string = ctrl_info_string; }
        const WString& GetCtrlInfoString() const { return m_ctrl_info_string; }
        void SetReleaseComplete(BOOLEAN release_complete) { m_release_complete = release_complete; }
        BOOLEAN IsReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1016
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUssdIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        DataCodingScheme m_dcs;
        WString m_ctrl_info_string;
        BOOLEAN m_release_complete;
        
    };

// Inline definitions
inline const SsUssdIndArg& SsUssdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUssdIndArg!\n");
    return ((SsUssdIndArg &) arg);
}



/*  ======================================================================
    Class SsUssdResentIndArg
    ====================================================================== */

class SsUssdResentIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUssdResentIndArg();
        
        static const SsUssdResentIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1017
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUssdResentIndArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsUssdResentIndArg& SsUssdResentIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUssdResentIndArg!\n");
    return ((SsUssdResentIndArg &) arg);
}



/*  ======================================================================
    Class UssdAnswerIndArg
    ====================================================================== */

class UssdAnswerIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UssdAnswerIndArg();
        
        static const UssdAnswerIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetDcs(const DataCodingScheme& dcs) { m_dcs = dcs; }
        const DataCodingScheme& GetDcs() const { return m_dcs; }
        void SetCtrlInfoString(const WString& ctrl_info_string) { m_ctrl_info_string = ctrl_info_string; }
        const WString& GetCtrlInfoString() const { return m_ctrl_info_string; }
        
        enum  {
            ID = 1033
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UssdAnswerIndArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        DataCodingScheme m_dcs;
        WString m_ctrl_info_string;
        
    };

// Inline definitions
inline const UssdAnswerIndArg& UssdAnswerIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UssdAnswerIndArg!\n");
    return ((UssdAnswerIndArg &) arg);
}



/*  ======================================================================
    Class SsUus1QueryIndArg
    ====================================================================== */

class SsUus1QueryIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUus1QueryIndArg();
        
        static const SsUus1QueryIndArg& Cast(const StackMsgArgument& arg);
        void SetTextList(const Vector<UusText>& text_list) { m_text_list = text_list; }
        const Vector<UusText>& GetTextList() const { return m_text_list; }
        
        enum  {
            ID = 1026
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUus1QueryIndArg*) arg); }
        
        Vector<UusText> m_text_list;
        
    };

// Inline definitions
inline const SsUus1QueryIndArg& SsUus1QueryIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUus1QueryIndArg!\n");
    return ((SsUus1QueryIndArg &) arg);
}



/*  ======================================================================
    Class SsUus1QueryRejArg
    ====================================================================== */

class SsUus1QueryRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUus1QueryRejArg();
        
        static const SsUus1QueryRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1027
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUus1QueryRejArg*) arg); }
        
    };

// Inline definitions
inline const SsUus1QueryRejArg& SsUus1QueryRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUus1QueryRejArg!\n");
    return ((SsUus1QueryRejArg &) arg);
}



/*  ======================================================================
    Class SsUus1IndArg
    ====================================================================== */

class SsUus1IndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUus1IndArg();
        
        static const SsUus1IndArg& Cast(const StackMsgArgument& arg);
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetType(const UusInTextType& type) { m_type = type; }
        const UusInTextType& GetType() const { return m_type; }
        
        enum  {
            ID = 1028
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUus1IndArg*) arg); }
        
        WString m_text;
        UusInTextType m_type;
        
    };

// Inline definitions
inline const SsUus1IndArg& SsUus1IndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUus1IndArg!\n");
    return ((SsUus1IndArg &) arg);
}



/*  ======================================================================
    Class SsCcbsReCallIndArg
    ====================================================================== */

class SsCcbsReCallIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCcbsReCallIndArg();
        
        static const SsCcbsReCallIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCcbsEntry(const CcbsEntry& ccbs_entry) { m_ccbs_entry = ccbs_entry; }
        const CcbsEntry& GetCcbsEntry() const { return m_ccbs_entry; }
        
        enum  {
            ID = 1030
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCcbsReCallIndArg*) arg); }
        
        Tipd m_tipd;
        CcbsEntry m_ccbs_entry;
        
    };

// Inline definitions
inline const SsCcbsReCallIndArg& SsCcbsReCallIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCcbsReCallIndArg!\n");
    return ((SsCcbsReCallIndArg &) arg);
}



/*  ======================================================================
    Class SsCcbsStatusIndArg
    ====================================================================== */

class SsCcbsStatusIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCcbsStatusIndArg();
        
        static const SsCcbsStatusIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCcbsStatus(const CcbsStatus& ccbs_status) { m_ccbs_status = ccbs_status; }
        const CcbsStatus& GetCcbsStatus() const { return m_ccbs_status; }
        
        enum  {
            ID = 1031
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCcbsStatusIndArg*) arg); }
        
        Tipd m_tipd;
        CcbsStatus m_ccbs_status;
        
    };

// Inline definitions
inline const SsCcbsStatusIndArg& SsCcbsStatusIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCcbsStatusIndArg!\n");
    return ((SsCcbsStatusIndArg &) arg);
}



/*  ======================================================================
    Class SsCcbsResultIndArg
    ====================================================================== */

class SsCcbsResultIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCcbsResultIndArg();
        
        static const SsCcbsResultIndArg& Cast(const StackMsgArgument& arg);
        void SetCcbsAction(const CcbsAction& ccbs_action) { m_ccbs_action = ccbs_action; }
        const CcbsAction& GetCcbsAction() const { return m_ccbs_action; }
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCcbsStatus(const CcbsStatus& ccbs_status) { m_ccbs_status = ccbs_status; }
        const CcbsStatus& GetCcbsStatus() const { return m_ccbs_status; }
        void SetInterrogateCcbsResult(const InterrogateCcbsResult& interrogate_ccbs_result) { m_interrogate_ccbs_result = interrogate_ccbs_result; }
        const InterrogateCcbsResult& GetInterrogateCcbsResult() const { return m_interrogate_ccbs_result; }
        void SetReleaseComplete(const ReleaseComplete& release_complete) { m_release_complete = release_complete; }
        const ReleaseComplete& GetReleaseComplete() const { return m_release_complete; }
        
        enum  {
            ID = 1032
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCcbsResultIndArg*) arg); }
        
        CcbsAction m_ccbs_action;
        Tipd m_tipd;
        CcbsStatus m_ccbs_status;
        InterrogateCcbsResult m_interrogate_ccbs_result;
        ReleaseComplete m_release_complete;
        
    };

// Inline definitions
inline const SsCcbsResultIndArg& SsCcbsResultIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCcbsResultIndArg!\n");
    return ((SsCcbsResultIndArg &) arg);
}



/*  ======================================================================
    Class SsSendReqArg
    ====================================================================== */

class SsSendReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsSendReqArg(const Tipd& tipd, const WString& ctrl_info);
        SsSendReqArg();
        
        static const SsSendReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCtrlInfo(const WString& ctrl_info) { m_ctrl_info = ctrl_info; }
        const WString& GetCtrlInfo() const { return m_ctrl_info; }
        
        enum  {
            ID = 2000
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsSendReqArg*) arg); }
        
        Tipd m_tipd;
        WString m_ctrl_info;
        
    };

// Inline definitions
inline const SsSendReqArg& SsSendReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsSendReqArg!\n");
    return ((SsSendReqArg &) arg);
}



/*  ======================================================================
    Class SsSendEndReqArg
    ====================================================================== */

class SsSendEndReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsSendEndReqArg(const Tipd& tipd);
        SsSendEndReqArg();
        
        static const SsSendEndReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2001
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsSendEndReqArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsSendEndReqArg& SsSendEndReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsSendEndReqArg!\n");
    return ((SsSendEndReqArg &) arg);
}



/*  ======================================================================
    Class SsGetPasswordRspArg
    ====================================================================== */

class SsGetPasswordRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsGetPasswordRspArg(const Tipd& tipd, const WString& password);
        SsGetPasswordRspArg();
        
        static const SsGetPasswordRspArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetPassword(const WString& password) { m_password = password; }
        const WString& GetPassword() const { return m_password; }
        
        enum  {
            ID = 2002
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsGetPasswordRspArg*) arg); }
        
        Tipd m_tipd;
        WString m_password;
        
    };

// Inline definitions
inline const SsGetPasswordRspArg& SsGetPasswordRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsGetPasswordRspArg!\n");
    return ((SsGetPasswordRspArg &) arg);
}



/*  ======================================================================
    Class SsErrReqArg
    ====================================================================== */

class SsErrReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsErrReqArg(const Tipd& tipd, const SsErrorCode& error_code);
        SsErrReqArg();
        
        static const SsErrReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetErrorCode(const SsErrorCode& error_code) { m_error_code = error_code; }
        const SsErrorCode& GetErrorCode() const { return m_error_code; }
        
        enum  {
            ID = 2003
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsErrReqArg*) arg); }
        
        Tipd m_tipd;
        SsErrorCode m_error_code;
        
    };

// Inline definitions
inline const SsErrReqArg& SsErrReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsErrReqArg!\n");
    return ((SsErrReqArg &) arg);
}



/*  ======================================================================
    Class SsRejReqArg
    ====================================================================== */

class SsRejReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsRejReqArg(const Tipd& tipd, const TaggedProblemCode& tagged_problem_code);
        SsRejReqArg();
        
        static const SsRejReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetTaggedProblemCode(const TaggedProblemCode& tagged_problem_code) { m_tagged_problem_code = tagged_problem_code; }
        const TaggedProblemCode& GetTaggedProblemCode() const { return m_tagged_problem_code; }
        
        enum  {
            ID = 2004
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsRejReqArg*) arg); }
        
        Tipd m_tipd;
        TaggedProblemCode m_tagged_problem_code;
        
    };

// Inline definitions
inline const SsRejReqArg& SsRejReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsRejReqArg!\n");
    return ((SsRejReqArg &) arg);
}



/*  ======================================================================
    Class SsUssdReqArg
    ====================================================================== */

class SsUssdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUssdReqArg(const Tipd& tipd, const SsOperationCode& operation_code, const WString& ctrl_info);
        SsUssdReqArg();
        
        static const SsUssdReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetOperationCode(const SsOperationCode& operation_code) { m_operation_code = operation_code; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        void SetCtrlInfo(const WString& ctrl_info) { m_ctrl_info = ctrl_info; }
        const WString& GetCtrlInfo() const { return m_ctrl_info; }
        
        enum  {
            ID = 2005
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUssdReqArg*) arg); }
        
        Tipd m_tipd;
        SsOperationCode m_operation_code;
        WString m_ctrl_info;
        
    };

// Inline definitions
inline const SsUssdReqArg& SsUssdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUssdReqArg!\n");
    return ((SsUssdReqArg &) arg);
}



/*  ======================================================================
    Class SsCcbsInvokeArg
    ====================================================================== */

class SsCcbsInvokeArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCcbsInvokeArg(const Tipd& tipd);
        SsCcbsInvokeArg();
        
        static const SsCcbsInvokeArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2030
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCcbsInvokeArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsCcbsInvokeArg& SsCcbsInvokeArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCcbsInvokeArg!\n");
    return ((SsCcbsInvokeArg &) arg);
}



/*  ======================================================================
    Class SsCcbsRejectArg
    ====================================================================== */

class SsCcbsRejectArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCcbsRejectArg(const Tipd& tipd);
        SsCcbsRejectArg();
        
        static const SsCcbsRejectArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2031
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCcbsRejectArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsCcbsRejectArg& SsCcbsRejectArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCcbsRejectArg!\n");
    return ((SsCcbsRejectArg &) arg);
}



/*  ======================================================================
    Class SsCcbsReCallRequestArg
    ====================================================================== */

class SsCcbsReCallRequestArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsCcbsReCallRequestArg(const Tipd& tipd);
        SsCcbsReCallRequestArg();
        
        static const SsCcbsReCallRequestArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2032
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsCcbsReCallRequestArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SsCcbsReCallRequestArg& SsCcbsReCallRequestArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsCcbsReCallRequestArg!\n");
    return ((SsCcbsReCallRequestArg &) arg);
}



/*  ======================================================================
    Class SsUus1ReqArg
    ====================================================================== */

class SsUus1ReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUus1ReqArg();
        
        static const SsUus1ReqArg& Cast(const StackMsgArgument& arg);
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetType(const UusOutTextType& type) { m_type = type; }
        const UusOutTextType& GetType() const { return m_type; }
        
        enum  {
            ID = 2033
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUus1ReqArg*) arg); }
        
        WString m_text;
        UusOutTextType m_type;
        
    };

// Inline definitions
inline const SsUus1ReqArg& SsUus1ReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUus1ReqArg!\n");
    return ((SsUus1ReqArg &) arg);
}



/*  ======================================================================
    Class SsUus1QueryReqArg
    ====================================================================== */

class SsUus1QueryReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SsUus1QueryReqArg();
        
        static const SsUus1QueryReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2035
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SsUus1QueryReqArg*) arg); }
        
    };

// Inline definitions
inline const SsUus1QueryReqArg& SsUus1QueryReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SsUus1QueryReqArg!\n");
    return ((SsUus1QueryReqArg &) arg);
}


#endif // Apc_SsStackMsgArgs_hpp

