/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "auzinger_view_latest\lnz_apoxi\Apoxi\Apc\MocArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_MocStackMsgArgs_hpp)
#define Apc_MocStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class MocSetupRejArg
    ====================================================================== */

class MocSetupRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MocSetupRejArg();
        
        static const MocSetupRejArg& Cast(const StackMsgArgument& arg);
        void SetRejectCause(const CallErrorCause& reject_cause) { m_reject_cause = reject_cause; }
        const CallErrorCause& GetRejectCause() const { return m_reject_cause; }
        
        enum  {
            ID = 1140
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MocSetupRejArg*) arg); }
        
        CallErrorCause m_reject_cause;
        
    };

// Inline definitions
inline const MocSetupRejArg& MocSetupRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MocSetupRejArg!\n");
    return ((MocSetupRejArg &) arg);
}



/*  ======================================================================
    Class MocSetupAccArg
    ====================================================================== */

class MocSetupAccArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MocSetupAccArg();
        
        static const MocSetupAccArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetEstCause(const CallEstCause& est_cause) { m_est_cause = est_cause; }
        const CallEstCause& GetEstCause() const { return m_est_cause; }
        void SetEccCategory(const EccCategory& ecc_category) { m_ecc_category = ecc_category; }
        const EccCategory& GetEccCategory() const { return m_ecc_category; }
        
        enum  {
            ID = 1141
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MocSetupAccArg*) arg); }
        
        Tipd m_tipd;
        CallEstCause m_est_cause;
        EccCategory m_ecc_category;
        
    };

// Inline definitions
inline const MocSetupAccArg& MocSetupAccArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MocSetupAccArg!\n");
    return ((MocSetupAccArg &) arg);
}



/*  ======================================================================
    Class MocAlertIndArg
    ====================================================================== */

class MocAlertIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MocAlertIndArg();
        
        static const MocAlertIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1142
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MocAlertIndArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const MocAlertIndArg& MocAlertIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MocAlertIndArg!\n");
    return ((MocAlertIndArg &) arg);
}



/*  ======================================================================
    Class MocSetupCnfArg
    ====================================================================== */

class MocSetupCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MocSetupCnfArg();
        
        static const MocSetupCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetConnectedNo(const PhoneNumber& connected_no) { m_connected_no = connected_no; }
        const PhoneNumber& GetConnectedNo() const { return m_connected_no; }
        void SetCrssCode(const CallRelatedSsCode& crss_code) { m_crss_code = crss_code; }
        const CallRelatedSsCode& GetCrssCode() const { return m_crss_code; }
        
        enum  {
            ID = 1143
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MocSetupCnfArg*) arg); }
        
        Tipd m_tipd;
        PhoneNumber m_connected_no;
        CallRelatedSsCode m_crss_code;
        
    };

// Inline definitions
inline const MocSetupCnfArg& MocSetupCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MocSetupCnfArg!\n");
    return ((MocSetupCnfArg &) arg);
}



/*  ======================================================================
    Class RedialIndArg
    ====================================================================== */

class RedialIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RedialIndArg();
        
        static const RedialIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1144
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RedialIndArg*) arg); }
        
    };

// Inline definitions
inline const RedialIndArg& RedialIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RedialIndArg!\n");
    return ((RedialIndArg &) arg);
}



/*  ======================================================================
    Class RedialSetupIndArg
    ====================================================================== */

class RedialSetupIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RedialSetupIndArg();
        
        static const RedialSetupIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCalledPartyNo(const PhoneNumber& called_party_no) { m_called_party_no = called_party_no; }
        const PhoneNumber& GetCalledPartyNo() const { return m_called_party_no; }
        void SetServedCallApp(const ServedCallApplication& served_call_app) { m_served_call_app = served_call_app; }
        const ServedCallApplication& GetServedCallApp() const { return m_served_call_app; }
        void SetEstCause(const CallEstCause& est_cause) { m_est_cause = est_cause; }
        const CallEstCause& GetEstCause() const { return m_est_cause; }
        void SetEccCategory(const EccCategory& ecc_category) { m_ecc_category = ecc_category; }
        const EccCategory& GetEccCategory() const { return m_ecc_category; }
        
        enum  {
            ID = 1145
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RedialSetupIndArg*) arg); }
        
        Tipd m_tipd;
        PhoneNumber m_called_party_no;
        ServedCallApplication m_served_call_app;
        CallEstCause m_est_cause;
        EccCategory m_ecc_category;
        
    };

// Inline definitions
inline const RedialSetupIndArg& RedialSetupIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RedialSetupIndArg!\n");
    return ((RedialSetupIndArg &) arg);
}



/*  ======================================================================
    Class RedialStopIndArg
    ====================================================================== */

class RedialStopIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RedialStopIndArg();
        
        static const RedialStopIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1146
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RedialStopIndArg*) arg); }
        
    };

// Inline definitions
inline const RedialStopIndArg& RedialStopIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RedialStopIndArg!\n");
    return ((RedialStopIndArg &) arg);
}



/*  ======================================================================
    Class AutoCallRestrictIndArg
    ====================================================================== */

class AutoCallRestrictIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AutoCallRestrictIndArg();
        
        static const AutoCallRestrictIndArg& Cast(const StackMsgArgument& arg);
        void SetRestricted(BOOLEAN restricted) { m_restricted = restricted; }
        BOOLEAN IsRestricted() const { return m_restricted; }
        
        enum  {
            ID = 1147
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AutoCallRestrictIndArg*) arg); }
        
        BOOLEAN m_restricted;
        
    };

// Inline definitions
inline const AutoCallRestrictIndArg& AutoCallRestrictIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AutoCallRestrictIndArg!\n");
    return ((AutoCallRestrictIndArg &) arg);
}



/*  ======================================================================
    Class ClearBlackListCnfArg
    ====================================================================== */

class ClearBlackListCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ClearBlackListCnfArg();
        
        static const ClearBlackListCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1148
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ClearBlackListCnfArg*) arg); }
        
    };

// Inline definitions
inline const ClearBlackListCnfArg& ClearBlackListCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ClearBlackListCnfArg!\n");
    return ((ClearBlackListCnfArg &) arg);
}



/*  ======================================================================
    Class MocSetupReqArg
    ====================================================================== */

class MocSetupReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MocSetupReqArg(const CallEstCause& call_est_cause, const PhoneNumber& phone_no, const ClirMode& clir_mode, const CugDescriptor& cug, BOOLEAN auto_call_setup, const LineSelector& call_line, BOOLEAN ctm, const EccCategory& ecc_category);
        MocSetupReqArg();
        
        static const MocSetupReqArg& Cast(const StackMsgArgument& arg);
        void SetCallEstCause(const CallEstCause& call_est_cause) { m_call_est_cause = call_est_cause; }
        const CallEstCause& GetCallEstCause() const { return m_call_est_cause; }
        void SetPhoneNo(const PhoneNumber& phone_no) { m_phone_no = phone_no; }
        const PhoneNumber& GetPhoneNo() const { return m_phone_no; }
        void SetClirMode(const ClirMode& clir_mode) { m_clir_mode = clir_mode; }
        const ClirMode& GetClirMode() const { return m_clir_mode; }
        void SetCug(const CugDescriptor& cug) { m_cug = cug; }
        const CugDescriptor& GetCug() const { return m_cug; }
        void SetAutoCallSetup(BOOLEAN auto_call_setup) { m_auto_call_setup = auto_call_setup; }
        BOOLEAN IsAutoCallSetup() const { return m_auto_call_setup; }
        void SetCallLine(const LineSelector& call_line) { m_call_line = call_line; }
        const LineSelector& GetCallLine() const { return m_call_line; }
        void SetCtm(BOOLEAN ctm) { m_ctm = ctm; }
        BOOLEAN IsCtm() const { return m_ctm; }
        void SetEccCategory(const EccCategory& ecc_category) { m_ecc_category = ecc_category; }
        const EccCategory& GetEccCategory() const { return m_ecc_category; }
        
        enum  {
            ID = 2140
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MocSetupReqArg*) arg); }
        
        CallEstCause m_call_est_cause;
        PhoneNumber m_phone_no;
        ClirMode m_clir_mode;
        CugDescriptor m_cug;
        BOOLEAN m_auto_call_setup;
        LineSelector m_call_line;
        BOOLEAN m_ctm;
        EccCategory m_ecc_category;
        
    };

// Inline definitions
inline const MocSetupReqArg& MocSetupReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MocSetupReqArg!\n");
    return ((MocSetupReqArg &) arg);
}



/*  ======================================================================
    Class RedialRejArg
    ====================================================================== */

class RedialRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RedialRejArg();
        
        static const RedialRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2141
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RedialRejArg*) arg); }
        
    };

// Inline definitions
inline const RedialRejArg& RedialRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RedialRejArg!\n");
    return ((RedialRejArg &) arg);
}



/*  ======================================================================
    Class RediallingDisabledIndArg
    ====================================================================== */

class RediallingDisabledIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RediallingDisabledIndArg(BOOLEAN disable);
        RediallingDisabledIndArg();
        
        static const RediallingDisabledIndArg& Cast(const StackMsgArgument& arg);
        void SetDisable(BOOLEAN disable) { m_disable = disable; }
        BOOLEAN IsDisable() const { return m_disable; }
        
        enum  {
            ID = 2142
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RediallingDisabledIndArg*) arg); }
        
        BOOLEAN m_disable;
        
    };

// Inline definitions
inline const RediallingDisabledIndArg& RediallingDisabledIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RediallingDisabledIndArg!\n");
    return ((RediallingDisabledIndArg &) arg);
}



/*  ======================================================================
    Class ClearBlacklistReqArg
    ====================================================================== */

class ClearBlacklistReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ClearBlacklistReqArg();
        
        static const ClearBlacklistReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2143
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ClearBlacklistReqArg*) arg); }
        
    };

// Inline definitions
inline const ClearBlacklistReqArg& ClearBlacklistReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ClearBlacklistReqArg!\n");
    return ((ClearBlacklistReqArg &) arg);
}


#endif // Apc_MocStackMsgArgs_hpp

