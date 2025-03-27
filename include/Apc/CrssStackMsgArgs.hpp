/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_development\src\Apoxi\Apc\CrssArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_CrssStackMsgArgs_hpp)
#define Apc_CrssStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class CallRelatedSsCnfArg
    ====================================================================== */

class CallRelatedSsCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallRelatedSsCnfArg();
        
        static const CallRelatedSsCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1060
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallRelatedSsCnfArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const CallRelatedSsCnfArg& CallRelatedSsCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallRelatedSsCnfArg!\n");
    return ((CallRelatedSsCnfArg &) arg);
}



/*  ======================================================================
    Class CallRelatedSsRejArg
    ====================================================================== */

class CallRelatedSsRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallRelatedSsRejArg();
        
        static const CallRelatedSsRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1061
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallRelatedSsRejArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const CallRelatedSsRejArg& CallRelatedSsRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallRelatedSsRejArg!\n");
    return ((CallRelatedSsRejArg &) arg);
}



/*  ======================================================================
    Class CallHoldCnfArg
    ====================================================================== */

class CallHoldCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallHoldCnfArg();
        
        static const CallHoldCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCrssState(const CallRelatedSsState& crss_state) { m_crss_state = crss_state; }
        const CallRelatedSsState& GetCrssState() const { return m_crss_state; }
        
        enum  {
            ID = 1062
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallHoldCnfArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSsState m_crss_state;
        
    };

// Inline definitions
inline const CallHoldCnfArg& CallHoldCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallHoldCnfArg!\n");
    return ((CallHoldCnfArg &) arg);
}



/*  ======================================================================
    Class CallHoldRejArg
    ====================================================================== */

class CallHoldRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallHoldRejArg();
        
        static const CallHoldRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCrssState(const CallRelatedSsState& crss_state) { m_crss_state = crss_state; }
        const CallRelatedSsState& GetCrssState() const { return m_crss_state; }
        void SetCallDiscCause(const CallErrorCause& call_disc_cause) { m_call_disc_cause = call_disc_cause; }
        const CallErrorCause& GetCallDiscCause() const { return m_call_disc_cause; }
        
        enum  {
            ID = 1063
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallHoldRejArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSsState m_crss_state;
        CallErrorCause m_call_disc_cause;
        
    };

// Inline definitions
inline const CallHoldRejArg& CallHoldRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallHoldRejArg!\n");
    return ((CallHoldRejArg &) arg);
}



/*  ======================================================================
    Class MptyCnfArg
    ====================================================================== */

class MptyCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MptyCnfArg();
        
        static const MptyCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCrss(const CallRelatedSs& crss) { m_crss = crss; }
        const CallRelatedSs& GetCrss() const { return m_crss; }
        
        enum  {
            ID = 1064
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MptyCnfArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSs m_crss;
        
    };

// Inline definitions
inline const MptyCnfArg& MptyCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MptyCnfArg!\n");
    return ((MptyCnfArg &) arg);
}



/*  ======================================================================
    Class EctCnfArg
    ====================================================================== */

class EctCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        EctCnfArg();
        
        static const EctCnfArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1065
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((EctCnfArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const EctCnfArg& EctCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to EctCnfArg!\n");
    return ((EctCnfArg &) arg);
}



/*  ======================================================================
    Class AocIndArg
    ====================================================================== */

class AocIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AocIndArg();
        
        static const AocIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetStatus(const CallRelatedSsCode& status) { m_status = status; }
        const CallRelatedSsCode& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1066
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AocIndArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSsCode m_status;
        
    };

// Inline definitions
inline const AocIndArg& AocIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AocIndArg!\n");
    return ((AocIndArg &) arg);
}



/*  ======================================================================
    Class ChargeIndArg
    ====================================================================== */

class ChargeIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChargeIndArg();
        
        static const ChargeIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetThisCallCharge(const AocChargeData& this_call_charge) { m_this_call_charge = this_call_charge; }
        const AocChargeData& GetThisCallCharge() const { return m_this_call_charge; }
        void SetAllCallsCharge(const AocChargeData& all_calls_charge) { m_all_calls_charge = all_calls_charge; }
        const AocChargeData& GetAllCallsCharge() const { return m_all_calls_charge; }
        
        enum  {
            ID = 1067
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChargeIndArg*) arg); }
        
        Tipd m_tipd;
        AocChargeData m_this_call_charge;
        AocChargeData m_all_calls_charge;
        
    };

// Inline definitions
inline const ChargeIndArg& ChargeIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChargeIndArg!\n");
    return ((ChargeIndArg &) arg);
}



/*  ======================================================================
    Class ChargeUnitsIndArg
    ====================================================================== */

class ChargeUnitsIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChargeUnitsIndArg();
        
        static const ChargeUnitsIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetThisCallCcm(ULONG this_call_ccm) { m_this_call_ccm = this_call_ccm; }
        ULONG GetThisCallCcm() const { return m_this_call_ccm; }
        void SetAllCallsCcm(ULONG all_calls_ccm) { m_all_calls_ccm = all_calls_ccm; }
        ULONG GetAllCallsCcm() const { return m_all_calls_ccm; }
        
        enum  {
            ID = 1068
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChargeUnitsIndArg*) arg); }
        
        Tipd m_tipd;
        ULONG m_this_call_ccm;
        ULONG m_all_calls_ccm;
        
    };

// Inline definitions
inline const ChargeUnitsIndArg& ChargeUnitsIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChargeUnitsIndArg!\n");
    return ((ChargeUnitsIndArg &) arg);
}



/*  ======================================================================
    Class CallRelatedSsReqArg
    ====================================================================== */

class CallRelatedSsReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallRelatedSsReqArg(const Tipd& tipd, const CallRelatedSs& call_related_ss);
        CallRelatedSsReqArg();
        
        static const CallRelatedSsReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallRelatedSs(const CallRelatedSs& call_related_ss) { m_call_related_ss = call_related_ss; }
        const CallRelatedSs& GetCallRelatedSs() const { return m_call_related_ss; }
        
        enum  {
            ID = 2060
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallRelatedSsReqArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSs m_call_related_ss;
        
    };

// Inline definitions
inline const CallRelatedSsReqArg& CallRelatedSsReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallRelatedSsReqArg!\n");
    return ((CallRelatedSsReqArg &) arg);
}



/*  ======================================================================
    Class SetAutoChargeArg
    ====================================================================== */

class SetAutoChargeArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetAutoChargeArg(BOOLEAN activate_reporting);
        SetAutoChargeArg();
        
        static const SetAutoChargeArg& Cast(const StackMsgArgument& arg);
        void SetActivateReporting(BOOLEAN activate_reporting) { m_activate_reporting = activate_reporting; }
        BOOLEAN IsActivateReporting() const { return m_activate_reporting; }
        
        enum  {
            ID = 2061
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetAutoChargeArg*) arg); }
        
        BOOLEAN m_activate_reporting;
        
    };

// Inline definitions
inline const SetAutoChargeArg& SetAutoChargeArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetAutoChargeArg!\n");
    return ((SetAutoChargeArg &) arg);
}



/*  ======================================================================
    Class ChargeReqArg
    ====================================================================== */

class ChargeReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChargeReqArg(const Tipd& tipd);
        ChargeReqArg();
        
        static const ChargeReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2062
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChargeReqArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const ChargeReqArg& ChargeReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChargeReqArg!\n");
    return ((ChargeReqArg &) arg);
}



/*  ======================================================================
    Class SetChargeUnitsArg
    ====================================================================== */

class SetChargeUnitsArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetChargeUnitsArg(BOOLEAN activate_reporting);
        SetChargeUnitsArg();
        
        static const SetChargeUnitsArg& Cast(const StackMsgArgument& arg);
        void SetActivateReporting(BOOLEAN activate_reporting) { m_activate_reporting = activate_reporting; }
        BOOLEAN IsActivateReporting() const { return m_activate_reporting; }
        
        enum  {
            ID = 2063
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetChargeUnitsArg*) arg); }
        
        BOOLEAN m_activate_reporting;
        
    };

// Inline definitions
inline const SetChargeUnitsArg& SetChargeUnitsArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetChargeUnitsArg!\n");
    return ((SetChargeUnitsArg &) arg);
}



/*  ======================================================================
    Class ChargeUnitsReqArg
    ====================================================================== */

class ChargeUnitsReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChargeUnitsReqArg(const Tipd& tipd);
        ChargeUnitsReqArg();
        
        static const ChargeUnitsReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2064
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChargeUnitsReqArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const ChargeUnitsReqArg& ChargeUnitsReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChargeUnitsReqArg!\n");
    return ((ChargeUnitsReqArg &) arg);
}


#endif // Apc_CrssStackMsgArgs_hpp

