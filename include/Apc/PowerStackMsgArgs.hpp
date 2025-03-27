/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Apc\PowerArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_PowerStackMsgArgs_hpp)
#define Apc_PowerStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class PowerDownCnfArg
    ====================================================================== */

class PowerDownCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PowerDownCnfArg();
        
        static const PowerDownCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1240
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PowerDownCnfArg*) arg); }
        
    };

// Inline definitions
inline const PowerDownCnfArg& PowerDownCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PowerDownCnfArg!\n");
    return ((PowerDownCnfArg &) arg);
}



/*  ======================================================================
    Class OmControlIndArg
    ====================================================================== */

class OmControlIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmControlIndArg(const PowerMode& power_mode);
        OmControlIndArg();
        ~OmControlIndArg();
        
        static const OmControlIndArg& Cast(const StackMsgArgument& arg);
        void SetPowerMode(const PowerMode& power_mode) { m_power_mode = power_mode; }
        const PowerMode& GetPowerMode() const { return m_power_mode; }
        
        enum  {
            ID = 1241
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmControlIndArg*) arg); }
        
        PowerMode m_power_mode;
        
    };

// Inline definitions
inline const OmControlIndArg& OmControlIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmControlIndArg!\n");
    return ((OmControlIndArg &) arg);
}



/*  ======================================================================
    Class PowerDownIndArg
    ====================================================================== */

class PowerDownIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PowerDownIndArg();
        
        static const PowerDownIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5240
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PowerDownIndArg*) arg); }
        
    };

// Inline definitions
inline const PowerDownIndArg& PowerDownIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PowerDownIndArg!\n");
    return ((PowerDownIndArg &) arg);
}



/*  ======================================================================
    Class OmPowerUpArg
    ====================================================================== */

class OmPowerUpArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmPowerUpArg(const PowerMode& power_mode);
        OmPowerUpArg();
        
        static const OmPowerUpArg& Cast(const StackMsgArgument& arg);
        void SetPowerMode(const PowerMode& power_mode) { m_power_mode = power_mode; }
        const PowerMode& GetPowerMode() const { return m_power_mode; }
        
        enum  {
            ID = 2240
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmPowerUpArg*) arg); }
        
        PowerMode m_power_mode;
        
    };

// Inline definitions
inline const OmPowerUpArg& OmPowerUpArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmPowerUpArg!\n");
    return ((OmPowerUpArg &) arg);
}



/*  ======================================================================
    Class PowerDownReqArg
    ====================================================================== */

class PowerDownReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PowerDownReqArg();
        
        static const PowerDownReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2241
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PowerDownReqArg*) arg); }
        
    };

// Inline definitions
inline const PowerDownReqArg& PowerDownReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PowerDownReqArg!\n");
    return ((PowerDownReqArg &) arg);
}



/*  ======================================================================
    Class ClientRegistrationArg
    ====================================================================== */

class ClientRegistrationArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ClientRegistrationArg(const Client& client = MmiClient);
        
        static const ClientRegistrationArg& Cast(const StackMsgArgument& arg);
        void SetClient(const Client& client) { m_client = client; }
        const Client& GetClient() const { return m_client; }
        
        enum  {
            ID = 2242
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ClientRegistrationArg*) arg); }
        
        Client m_client;
        
    };

// Inline definitions
inline const ClientRegistrationArg& ClientRegistrationArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ClientRegistrationArg!\n");
    return ((ClientRegistrationArg &) arg);
}



/*  ======================================================================
    Class ClientDeregistrationArg
    ====================================================================== */

class ClientDeregistrationArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ClientDeregistrationArg(const Client& client = MmiClient);
        
        static const ClientDeregistrationArg& Cast(const StackMsgArgument& arg);
        void SetClient(const Client& client) { m_client = client; }
        const Client& GetClient() const { return m_client; }
        
        enum  {
            ID = 2243
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ClientDeregistrationArg*) arg); }
        
        Client m_client;
        
    };

// Inline definitions
inline const ClientDeregistrationArg& ClientDeregistrationArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ClientDeregistrationArg!\n");
    return ((ClientDeregistrationArg &) arg);
}



/*  ======================================================================
    Class StopBatteryLoadListeningArg
    ====================================================================== */

class StopBatteryLoadListeningArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StopBatteryLoadListeningArg();
        
        static const StopBatteryLoadListeningArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2245
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StopBatteryLoadListeningArg*) arg); }
        
    };

// Inline definitions
inline const StopBatteryLoadListeningArg& StopBatteryLoadListeningArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StopBatteryLoadListeningArg!\n");
    return ((StopBatteryLoadListeningArg &) arg);
}



/*  ======================================================================
    Class StartSignalStrengthListeningArg
    ====================================================================== */

class StartSignalStrengthListeningArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StartSignalStrengthListeningArg(UINT threshold_percentage = 0);
        
        static const StartSignalStrengthListeningArg& Cast(const StackMsgArgument& arg);
        void SetThresholdPercentage(UINT threshold_percentage) { m_threshold_percentage = threshold_percentage; }
        UINT GetThresholdPercentage() const { return m_threshold_percentage; }
        
        enum  {
            ID = 2246
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StartSignalStrengthListeningArg*) arg); }
        
        UINT m_threshold_percentage;
        
    };

// Inline definitions
inline const StartSignalStrengthListeningArg& StartSignalStrengthListeningArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StartSignalStrengthListeningArg!\n");
    return ((StartSignalStrengthListeningArg &) arg);
}



/*  ======================================================================
    Class StopSignalStrengthListeningArg
    ====================================================================== */

class StopSignalStrengthListeningArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        StopSignalStrengthListeningArg();
        
        static const StopSignalStrengthListeningArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2247
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((StopSignalStrengthListeningArg*) arg); }
        
    };

// Inline definitions
inline const StopSignalStrengthListeningArg& StopSignalStrengthListeningArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to StopSignalStrengthListeningArg!\n");
    return ((StopSignalStrengthListeningArg &) arg);
}



/*  ======================================================================
    Class ControlHwDataOnlyArg
    ====================================================================== */

class ControlHwDataOnlyArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ControlHwDataOnlyArg();
        
        static const ControlHwDataOnlyArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2249
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ControlHwDataOnlyArg*) arg); }
        
    };

// Inline definitions
inline const ControlHwDataOnlyArg& ControlHwDataOnlyArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ControlHwDataOnlyArg!\n");
    return ((ControlHwDataOnlyArg &) arg);
}


#endif // Apc_PowerStackMsgArgs_hpp

