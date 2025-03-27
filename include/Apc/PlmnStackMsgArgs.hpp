/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "auzinger_view_latest\lnz_apoxi\Apoxi\Apc\PlmnArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_PlmnStackMsgArgs_hpp)
#define Apc_PlmnStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/PlmnScanList.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class PlmnListCnfArg
    ====================================================================== */

class PlmnListCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlmnListCnfArg();
        
        static const PlmnListCnfArg& Cast(const StackMsgArgument& arg);
        void SetPlmnScanList(const PlmnScanList& plmn_scan_list) { m_plmn_scan_list = plmn_scan_list; }
        const PlmnScanList& GetPlmnScanList() const { return m_plmn_scan_list; }
        
        enum  {
            ID = 1360
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlmnListCnfArg*) arg); }
        
        PlmnScanList m_plmn_scan_list;
        
    };

// Inline definitions
inline const PlmnListCnfArg& PlmnListCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlmnListCnfArg!\n");
    return ((PlmnListCnfArg &) arg);
}



/*  ======================================================================
    Class PlmnListRejArg
    ====================================================================== */

class PlmnListRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlmnListRejArg();
        
        static const PlmnListRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1361
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlmnListRejArg*) arg); }
        
    };

// Inline definitions
inline const PlmnListRejArg& PlmnListRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlmnListRejArg!\n");
    return ((PlmnListRejArg &) arg);
}



/*  ======================================================================
    Class NRegStateIndArg
    ====================================================================== */

class NRegStateIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        NRegStateIndArg();
        
        static const NRegStateIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const RegisterStatus& status) { m_status = status; }
        const RegisterStatus& GetStatus() const { return m_status; }
        void SetCause(const RegisterRejectCause& cause) { m_cause = cause; }
        const RegisterRejectCause& GetCause() const { return m_cause; }
        void SetGsmErrorCause(const GsmErrorCause& gsm_error_cause) { m_gsm_error_cause = gsm_error_cause; }
        const GsmErrorCause& GetGsmErrorCause() const { return m_gsm_error_cause; }
        void SetPlmnSearchActive(BOOLEAN plmn_search_active) { m_plmn_search_active = plmn_search_active; }
        BOOLEAN IsPlmnSearchActive() const { return m_plmn_search_active; }
        void SetRadioAccessTechnology(const RadioAccessTechnology& radio_access_technology) { m_radio_access_technology = radio_access_technology; }
        const RadioAccessTechnology& GetRadioAccessTechnology() const { return m_radio_access_technology; }
        void SetGsmBand(const GsmBand& gsm_band) { m_gsm_band = gsm_band; }
        const GsmBand& GetGsmBand() const { return m_gsm_band; }
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        
        enum  {
            ID = 5360
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((NRegStateIndArg*) arg); }
        
        RegisterStatus m_status;
        RegisterRejectCause m_cause;
        GsmErrorCause m_gsm_error_cause;
        BOOLEAN m_plmn_search_active;
        RadioAccessTechnology m_radio_access_technology;
        GsmBand m_gsm_band;
        Plmn m_plmn;
        
    };

// Inline definitions
inline const NRegStateIndArg& NRegStateIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to NRegStateIndArg!\n");
    return ((NRegStateIndArg &) arg);
}



/*  ======================================================================
    Class RegStateIndArg
    ====================================================================== */

class RegStateIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        RegStateIndArg();
        
        static const RegStateIndArg& Cast(const StackMsgArgument& arg);
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        void SetMode(const RegisterMode& mode) { m_mode = mode; }
        const RegisterMode& GetMode() const { return m_mode; }
        void SetRadioAccessTechnology(const RadioAccessTechnology& radio_access_technology) { m_radio_access_technology = radio_access_technology; }
        const RadioAccessTechnology& GetRadioAccessTechnology() const { return m_radio_access_technology; }
        void SetGsmBand(const GsmBand& gsm_band) { m_gsm_band = gsm_band; }
        const GsmBand& GetGsmBand() const { return m_gsm_band; }
        
        enum  {
            ID = 5361
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((RegStateIndArg*) arg); }
        
        Plmn m_plmn;
        RegisterMode m_mode;
        RadioAccessTechnology m_radio_access_technology;
        GsmBand m_gsm_band;
        
    };

// Inline definitions
inline const RegStateIndArg& RegStateIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to RegStateIndArg!\n");
    return ((RegStateIndArg &) arg);
}



/*  ======================================================================
    Class AttachCnfArg
    ====================================================================== */

class AttachCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AttachCnfArg();
        
        static const AttachCnfArg& Cast(const StackMsgArgument& arg);
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        void SetMode(const RegisterMode& mode) { m_mode = mode; }
        const RegisterMode& GetMode() const { return m_mode; }
        void SetRadioAccessTechnology(const RadioAccessTechnology& radio_access_technology) { m_radio_access_technology = radio_access_technology; }
        const RadioAccessTechnology& GetRadioAccessTechnology() const { return m_radio_access_technology; }
        void SetGsmBand(const GsmBand& gsm_band) { m_gsm_band = gsm_band; }
        const GsmBand& GetGsmBand() const { return m_gsm_band; }
        
        enum  {
            ID = 5362
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AttachCnfArg*) arg); }
        
        Plmn m_plmn;
        RegisterMode m_mode;
        RadioAccessTechnology m_radio_access_technology;
        GsmBand m_gsm_band;
        
    };

// Inline definitions
inline const AttachCnfArg& AttachCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AttachCnfArg!\n");
    return ((AttachCnfArg &) arg);
}



/*  ======================================================================
    Class AttachRejArg
    ====================================================================== */

class AttachRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AttachRejArg();
        
        static const AttachRejArg& Cast(const StackMsgArgument& arg);
        void SetCause(const RegisterRejectCause& cause) { m_cause = cause; }
        const RegisterRejectCause& GetCause() const { return m_cause; }
        
        enum  {
            ID = 5363
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AttachRejArg*) arg); }
        
        RegisterRejectCause m_cause;
        
    };

// Inline definitions
inline const AttachRejArg& AttachRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AttachRejArg!\n");
    return ((AttachRejArg &) arg);
}



/*  ======================================================================
    Class DetachCnfArg
    ====================================================================== */

class DetachCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DetachCnfArg();
        
        static const DetachCnfArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const RegisterStatus& status) { m_status = status; }
        const RegisterStatus& GetStatus() const { return m_status; }
        void SetCause(const UserCause& cause) { m_cause = cause; }
        const UserCause& GetCause() const { return m_cause; }
        
        enum  {
            ID = 5364
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DetachCnfArg*) arg); }
        
        RegisterStatus m_status;
        UserCause m_cause;
        
    };

// Inline definitions
inline const DetachCnfArg& DetachCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DetachCnfArg!\n");
    return ((DetachCnfArg &) arg);
}



/*  ======================================================================
    Class AttachAllowedIndArg
    ====================================================================== */

class AttachAllowedIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AttachAllowedIndArg();
        
        static const AttachAllowedIndArg& Cast(const StackMsgArgument& arg);
        void SetAllowed(BOOLEAN allowed) { m_allowed = allowed; }
        BOOLEAN IsAllowed() const { return m_allowed; }
        
        enum  {
            ID = 5365
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AttachAllowedIndArg*) arg); }
        
        BOOLEAN m_allowed;
        
    };

// Inline definitions
inline const AttachAllowedIndArg& AttachAllowedIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AttachAllowedIndArg!\n");
    return ((AttachAllowedIndArg &) arg);
}



/*  ======================================================================
    Class GprsClassIndArg
    ====================================================================== */

class GprsClassIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        GprsClassIndArg();
        
        static const GprsClassIndArg& Cast(const StackMsgArgument& arg);
        void SetGprsClass(const GprsClass& gprs_class) { m_gprs_class = gprs_class; }
        const GprsClass& GetGprsClass() const { return m_gprs_class; }
        void SetProcessSource(const ProcessSource& process_source) { m_process_source = process_source; }
        const ProcessSource& GetProcessSource() const { return m_process_source; }
        
        enum  {
            ID = 5366
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((GprsClassIndArg*) arg); }
        
        GprsClass m_gprs_class;
        ProcessSource m_process_source;
        
    };

// Inline definitions
inline const GprsClassIndArg& GprsClassIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to GprsClassIndArg!\n");
    return ((GprsClassIndArg &) arg);
}



/*  ======================================================================
    Class PlmnListAbortArg
    ====================================================================== */

class PlmnListAbortArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlmnListAbortArg();
        
        static const PlmnListAbortArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2363
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlmnListAbortArg*) arg); }
        
    };

// Inline definitions
inline const PlmnListAbortArg& PlmnListAbortArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlmnListAbortArg!\n");
    return ((PlmnListAbortArg &) arg);
}



/*  ======================================================================
    Class PrefPlmnChangeArg
    ====================================================================== */

class PrefPlmnChangeArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PrefPlmnChangeArg();
        
        static const PrefPlmnChangeArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2364
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PrefPlmnChangeArg*) arg); }
        
    };

// Inline definitions
inline const PrefPlmnChangeArg& PrefPlmnChangeArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PrefPlmnChangeArg!\n");
    return ((PrefPlmnChangeArg &) arg);
}



/*  ======================================================================
    Class PrefServiceSetReqArg
    ====================================================================== */

class PrefServiceSetReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PrefServiceSetReqArg(const GsmService& gsm_service);
        PrefServiceSetReqArg();
        
        static const PrefServiceSetReqArg& Cast(const StackMsgArgument& arg);
        const GsmService& GetGsmService() const { return m_gsm_service; }
        
        enum  {
            ID = 2366
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PrefServiceSetReqArg*) arg); }
        
        GsmService m_gsm_service;
        
    };

// Inline definitions
inline const PrefServiceSetReqArg& PrefServiceSetReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PrefServiceSetReqArg!\n");
    return ((PrefServiceSetReqArg &) arg);
}



/*  ======================================================================
    Class AttachReqArg
    ====================================================================== */

class AttachReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AttachReqArg(const RegisterMode& mode, const PlmnIndicator& indicator, const Plmn& plmn, const RadioAccessTechnology& rat);
        AttachReqArg();
        
        static const AttachReqArg& Cast(const StackMsgArgument& arg);
        void SetMode(const RegisterMode& mode) { m_mode = mode; }
        const RegisterMode& GetMode() const { return m_mode; }
        void SetIndicator(const PlmnIndicator& indicator) { m_indicator = indicator; }
        const PlmnIndicator& GetIndicator() const { return m_indicator; }
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        void SetRat(const RadioAccessTechnology& rat) { m_rat = rat; }
        const RadioAccessTechnology& GetRat() const { return m_rat; }
        
        enum  {
            ID = 6360
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AttachReqArg*) arg); }
        
        RegisterMode m_mode;
        PlmnIndicator m_indicator;
        Plmn m_plmn;
        RadioAccessTechnology m_rat;
        
    };

// Inline definitions
inline const AttachReqArg& AttachReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AttachReqArg!\n");
    return ((AttachReqArg &) arg);
}



/*  ======================================================================
    Class DetachReqArg
    ====================================================================== */

class DetachReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DetachReqArg();
        
        static const DetachReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 6361
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DetachReqArg*) arg); }
        
    };

// Inline definitions
inline const DetachReqArg& DetachReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DetachReqArg!\n");
    return ((DetachReqArg &) arg);
}



/*  ======================================================================
    Class PlmnInfoReqArg
    ====================================================================== */

class PlmnInfoReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlmnInfoReqArg(const RegisterMode& mode, const PlmnIndicator& indicator, const Plmn& plmn);
        PlmnInfoReqArg();
        
        static const PlmnInfoReqArg& Cast(const StackMsgArgument& arg);
        void SetMode(const RegisterMode& mode) { m_mode = mode; }
        const RegisterMode& GetMode() const { return m_mode; }
        void SetIndicator(const PlmnIndicator& indicator) { m_indicator = indicator; }
        const PlmnIndicator& GetIndicator() const { return m_indicator; }
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        
        enum  {
            ID = 6362
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlmnInfoReqArg*) arg); }
        
        RegisterMode m_mode;
        PlmnIndicator m_indicator;
        Plmn m_plmn;
        
    };

// Inline definitions
inline const PlmnInfoReqArg& PlmnInfoReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlmnInfoReqArg!\n");
    return ((PlmnInfoReqArg &) arg);
}



/*  ======================================================================
    Class GprsClassReqArg
    ====================================================================== */

class GprsClassReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        GprsClassReqArg(const GprsClass& gprs_class);
        GprsClassReqArg();
        
        static const GprsClassReqArg& Cast(const StackMsgArgument& arg);
        void SetGprsClass(const GprsClass& gprs_class) { m_gprs_class = gprs_class; }
        const GprsClass& GetGprsClass() const { return m_gprs_class; }
        
        enum  {
            ID = 6363
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((GprsClassReqArg*) arg); }
        
        GprsClass m_gprs_class;
        
    };

// Inline definitions
inline const GprsClassReqArg& GprsClassReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to GprsClassReqArg!\n");
    return ((GprsClassReqArg &) arg);
}



/*  ======================================================================
    Class PlmnListReqArg
    ====================================================================== */

class PlmnListReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlmnListReqArg(const PlmnScanMode& mode);
        PlmnListReqArg();
        
        static const PlmnListReqArg& Cast(const StackMsgArgument& arg);
        void SetMode(const PlmnScanMode& mode) { m_mode = mode; }
        const PlmnScanMode& GetMode() const { return m_mode; }
        
        enum  {
            ID = 6365
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlmnListReqArg*) arg); }
        
        PlmnScanMode m_mode;
        
    };

// Inline definitions
inline const PlmnListReqArg& PlmnListReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlmnListReqArg!\n");
    return ((PlmnListReqArg &) arg);
}


#endif // Apc_PlmnStackMsgArgs_hpp

