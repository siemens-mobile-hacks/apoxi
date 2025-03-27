/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Apc\MiscArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_MiscStackMsgArgs_hpp)
#define Apc_MiscStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/Accessory.hpp>
#include <Apc/SimTkTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SignalStrengthLevelIndArg
    ====================================================================== */

class SignalStrengthLevelIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SignalStrengthLevelIndArg();
        
        static const SignalStrengthLevelIndArg& Cast(const StackMsgArgument& arg);
        void SetLevel(const SignalStrengthLevel& level) { m_level = level; }
        const SignalStrengthLevel& GetLevel() const { return m_level; }
        void SetQualityValid(BOOLEAN quality_valid) { m_quality_valid = quality_valid; }
        BOOLEAN IsQualityValid() const { return m_quality_valid; }
        void SetQuality(const SignalQualityLevel& quality) { m_quality = quality; }
        const SignalQualityLevel& GetQuality() const { return m_quality; }
        void SetSignalStrengthMax(const SignalStrengthMax& signal_strength_max) { m_signal_strength_max = signal_strength_max; }
        const SignalStrengthMax& GetSignalStrengthMax() const { return m_signal_strength_max; }
        void SetSignalQualityMax(const SignalQualityMax& signal_quality_max) { m_signal_quality_max = signal_quality_max; }
        const SignalQualityMax& GetSignalQualityMax() const { return m_signal_quality_max; }
        
        enum  {
            ID = 1100
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SignalStrengthLevelIndArg*) arg); }
        
        SignalStrengthLevel m_level;
        BOOLEAN m_quality_valid;
        SignalQualityLevel m_quality;
        SignalStrengthMax m_signal_strength_max;
        SignalQualityMax m_signal_quality_max;
        
    };

// Inline definitions
inline const SignalStrengthLevelIndArg& SignalStrengthLevelIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SignalStrengthLevelIndArg!\n");
    return ((SignalStrengthLevelIndArg &) arg);
}



/*  ======================================================================
    Class ImeiReadIndArg
    ====================================================================== */

class ImeiReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ImeiReadIndArg();
        
        static const ImeiReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetImei1(const Imei& imei1) { m_imei1 = imei1; }
        const Imei& GetImei1() const { return m_imei1; }
        void SetImei2(const Imei& imei2) { m_imei2 = imei2; }
        const Imei& GetImei2() const { return m_imei2; }
        
        enum  {
            ID = 1110
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ImeiReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        Imei m_imei1;
        Imei m_imei2;
        
    };

// Inline definitions
inline const ImeiReadIndArg& ImeiReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ImeiReadIndArg!\n");
    return ((ImeiReadIndArg &) arg);
}



/*  ======================================================================
    Class AccessoryIndArg
    ====================================================================== */

class AccessoryIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AccessoryIndArg();
        
        static const AccessoryIndArg& Cast(const StackMsgArgument& arg);
        void SetAccessory(const Accessory& accessory) { m_accessory = accessory; }
        const Accessory& GetAccessory() const { return m_accessory; }
        
        enum  {
            ID = 1111
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AccessoryIndArg*) arg); }
        
        Accessory m_accessory;
        
    };

// Inline definitions
inline const AccessoryIndArg& AccessoryIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AccessoryIndArg!\n");
    return ((AccessoryIndArg &) arg);
}



/*  ======================================================================
    Class OmGetTermProfileCnfArg
    ====================================================================== */

class OmGetTermProfileCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmGetTermProfileCnfArg();
        
        static const OmGetTermProfileCnfArg& Cast(const StackMsgArgument& arg);
        void SetSimTkProfile(const SimTkProfile& sim_tk_profile) { m_sim_tk_profile = sim_tk_profile; }
        const SimTkProfile& GetSimTkProfile() const { return m_sim_tk_profile; }
        
        enum  {
            ID = 1114
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmGetTermProfileCnfArg*) arg); }
        
        SimTkProfile m_sim_tk_profile;
        
    };

// Inline definitions
inline const OmGetTermProfileCnfArg& OmGetTermProfileCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmGetTermProfileCnfArg!\n");
    return ((OmGetTermProfileCnfArg &) arg);
}



/*  ======================================================================
    Class OmSetTermProfileCnfArg
    ====================================================================== */

class OmSetTermProfileCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmSetTermProfileCnfArg();
        
        static const OmSetTermProfileCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1115
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmSetTermProfileCnfArg*) arg); }
        
    };

// Inline definitions
inline const OmSetTermProfileCnfArg& OmSetTermProfileCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmSetTermProfileCnfArg!\n");
    return ((OmSetTermProfileCnfArg &) arg);
}



/*  ======================================================================
    Class OmSetTermProfileRejArg
    ====================================================================== */

class OmSetTermProfileRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmSetTermProfileRejArg();
        
        static const OmSetTermProfileRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1116
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmSetTermProfileRejArg*) arg); }
        
    };

// Inline definitions
inline const OmSetTermProfileRejArg& OmSetTermProfileRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmSetTermProfileRejArg!\n");
    return ((OmSetTermProfileRejArg &) arg);
}



/*  ======================================================================
    Class EngineeringModeControlResponseArg
    ====================================================================== */

class EngineeringModeControlResponseArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        EngineeringModeControlResponseArg();
        
        static const EngineeringModeControlResponseArg& Cast(const StackMsgArgument& arg);
        void SetFunction(INT function) { m_function = function; }
        INT GetFunction() const { return m_function; }
        void SetResult(INT result) { m_result = result; }
        INT GetResult() const { return m_result; }
        
        enum  {
            ID = 1117
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((EngineeringModeControlResponseArg*) arg); }
        
        INT m_function;
        INT m_result;
        
    };

// Inline definitions
inline const EngineeringModeControlResponseArg& EngineeringModeControlResponseArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to EngineeringModeControlResponseArg!\n");
    return ((EngineeringModeControlResponseArg &) arg);
}



/*  ======================================================================
    Class CfuDataIndArg
    ====================================================================== */

class CfuDataIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CfuDataIndArg();
        
        static const CfuDataIndArg& Cast(const StackMsgArgument& arg);
        void SetCfuServiceArray(const CfuServiceArray& cfu_service_array) { m_cfu_service_array = cfu_service_array; }
        const CfuServiceArray& GetCfuServiceArray() const { return m_cfu_service_array; }
        
        enum  {
            ID = 1118
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CfuDataIndArg*) arg); }
        
        CfuServiceArray m_cfu_service_array;
        
    };

// Inline definitions
inline const CfuDataIndArg& CfuDataIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CfuDataIndArg!\n");
    return ((CfuDataIndArg &) arg);
}



/*  ======================================================================
    Class EccListIndArg
    ====================================================================== */

class EccListIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        EccListIndArg(const EccNetworkArray& ecc_network_array);
        EccListIndArg();
        
        static const EccListIndArg& Cast(const StackMsgArgument& arg);
        void SetEccNetworkArray(const EccNetworkArray& ecc_network_array) { m_ecc_network_array = ecc_network_array; }
        const EccNetworkArray& GetEccNetworkArray() const { return m_ecc_network_array; }
        
        enum  {
            ID = 1380
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((EccListIndArg*) arg); }
        
        EccNetworkArray m_ecc_network_array;
        
    };

// Inline definitions
inline const EccListIndArg& EccListIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to EccListIndArg!\n");
    return ((EccListIndArg &) arg);
}



/*  ======================================================================
    Class BootDispatchingArg
    ====================================================================== */

class BootDispatchingArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BootDispatchingArg();
        
        static const BootDispatchingArg& Cast(const StackMsgArgument& arg);
        void SetSequence(INT sequence) { m_sequence = sequence; }
        INT GetSequence() const { return m_sequence; }
        
        enum  {
            ID = 1381
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BootDispatchingArg*) arg); }
        
        INT m_sequence;
        
    };

// Inline definitions
inline const BootDispatchingArg& BootDispatchingArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BootDispatchingArg!\n");
    return ((BootDispatchingArg &) arg);
}



/*  ======================================================================
    Class ImeiReadReqArg
    ====================================================================== */

class ImeiReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ImeiReadReqArg();
        
        static const ImeiReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2103
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ImeiReadReqArg*) arg); }
        
    };

// Inline definitions
inline const ImeiReadReqArg& ImeiReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ImeiReadReqArg!\n");
    return ((ImeiReadReqArg &) arg);
}



/*  ======================================================================
    Class TestparamReqArg
    ====================================================================== */

class TestparamReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        TestparamReqArg(BOOLEAN test = FALSE);
        
        static const TestparamReqArg& Cast(const StackMsgArgument& arg);
        void SetTest(BOOLEAN test) { m_test = test; }
        BOOLEAN IsTest() const { return m_test; }
        
        enum  {
            ID = 2104
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((TestparamReqArg*) arg); }
        
        BOOLEAN m_test;
        
    };

// Inline definitions
inline const TestparamReqArg& TestparamReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to TestparamReqArg!\n");
    return ((TestparamReqArg &) arg);
}



/*  ======================================================================
    Class BandSelectionReqArg
    ====================================================================== */

class BandSelectionReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BandSelectionReqArg(const GsmBandList& gsm_band_list);
        BandSelectionReqArg();
        
        static const BandSelectionReqArg& Cast(const StackMsgArgument& arg);
        void SetGsmBandList(const GsmBandList& gsm_band_list) { m_gsm_band_list = gsm_band_list; }
        const GsmBandList& GetGsmBandList() const { return m_gsm_band_list; }
        
        enum  {
            ID = 2105
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BandSelectionReqArg*) arg); }
        
        GsmBandList m_gsm_band_list;
        
    };

// Inline definitions
inline const BandSelectionReqArg& BandSelectionReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BandSelectionReqArg!\n");
    return ((BandSelectionReqArg &) arg);
}



/*  ======================================================================
    Class OmFactoryResetIndArg
    ====================================================================== */

class OmFactoryResetIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmFactoryResetIndArg();
        
        static const OmFactoryResetIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2106
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmFactoryResetIndArg*) arg); }
        
    };

// Inline definitions
inline const OmFactoryResetIndArg& OmFactoryResetIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmFactoryResetIndArg!\n");
    return ((OmFactoryResetIndArg &) arg);
}



/*  ======================================================================
    Class OmGetTermProfileReqArg
    ====================================================================== */

class OmGetTermProfileReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmGetTermProfileReqArg();
        
        static const OmGetTermProfileReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2107
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmGetTermProfileReqArg*) arg); }
        
    };

// Inline definitions
inline const OmGetTermProfileReqArg& OmGetTermProfileReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmGetTermProfileReqArg!\n");
    return ((OmGetTermProfileReqArg &) arg);
}



/*  ======================================================================
    Class OmSetTermProfileReqArg
    ====================================================================== */

class OmSetTermProfileReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmSetTermProfileReqArg(const SimTkProfile& sim_tk_profile);
        OmSetTermProfileReqArg();
        
        static const OmSetTermProfileReqArg& Cast(const StackMsgArgument& arg);
        void SetSimTkProfile(const SimTkProfile& sim_tk_profile) { m_sim_tk_profile = sim_tk_profile; }
        const SimTkProfile& GetSimTkProfile() const { return m_sim_tk_profile; }
        
        enum  {
            ID = 2108
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmSetTermProfileReqArg*) arg); }
        
        SimTkProfile m_sim_tk_profile;
        
    };

// Inline definitions
inline const OmSetTermProfileReqArg& OmSetTermProfileReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmSetTermProfileReqArg!\n");
    return ((OmSetTermProfileReqArg &) arg);
}



/*  ======================================================================
    Class EngineeringModeControlRequestArg
    ====================================================================== */

class EngineeringModeControlRequestArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        EngineeringModeControlRequestArg(const EngineeringModeControl& function, ULONG param = 0);
        EngineeringModeControlRequestArg();
        
        static const EngineeringModeControlRequestArg& Cast(const StackMsgArgument& arg);
        void SetFunction(const EngineeringModeControl& function) { m_function = function; }
        const EngineeringModeControl& GetFunction() const { return m_function; }
        void SetParam(ULONG param) { m_param = param; }
        ULONG GetParam() const { return m_param; }
        
        enum  {
            ID = 2109
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((EngineeringModeControlRequestArg*) arg); }
        
        EngineeringModeControl m_function;
        ULONG m_param;
        
    };

// Inline definitions
inline const EngineeringModeControlRequestArg& EngineeringModeControlRequestArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to EngineeringModeControlRequestArg!\n");
    return ((EngineeringModeControlRequestArg &) arg);
}


#endif // Apc_MiscStackMsgArgs_hpp

