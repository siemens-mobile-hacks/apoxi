/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\HS\BtHsNotificationMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_HS_BtHsNotificationMessageArgument_hpp)
#define Bluetooth_HS_BtHsNotificationMessageArgument_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/HS/BtTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHsNmaConnect
    ====================================================================== */

class BtHsNmaConnect : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaConnect(const BtResultCode& result, const BtDevice& device);
        BtHsNmaConnect();
        ~BtHsNmaConnect();
        
        static const BtHsNmaConnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        const BtDevice& GetDevice() const { return m_device; }
        
        enum  {
            ID = 10
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaConnect*) arg); }
        
        BtResultCode m_result;
        BtDevice m_device;
        
    };

// Inline definitions
inline const BtHsNmaConnect& BtHsNmaConnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaConnect!\n");
    return ((BtHsNmaConnect &) arg);
}



/*  ======================================================================
    Class BtHsNmaDisconnect
    ====================================================================== */

class BtHsNmaDisconnect : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaDisconnect(const BtResultCode& result);
        BtHsNmaDisconnect();
        ~BtHsNmaDisconnect();
        
        static const BtHsNmaDisconnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 11
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaDisconnect*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHsNmaDisconnect& BtHsNmaDisconnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaDisconnect!\n");
    return ((BtHsNmaDisconnect &) arg);
}



/*  ======================================================================
    Class BtHsNmaTransferAudioToAccessory
    ====================================================================== */

class BtHsNmaTransferAudioToAccessory : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaTransferAudioToAccessory(const BtResultCode& result);
        BtHsNmaTransferAudioToAccessory();
        ~BtHsNmaTransferAudioToAccessory();
        
        static const BtHsNmaTransferAudioToAccessory& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 12
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaTransferAudioToAccessory*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHsNmaTransferAudioToAccessory& BtHsNmaTransferAudioToAccessory::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaTransferAudioToAccessory!\n");
    return ((BtHsNmaTransferAudioToAccessory &) arg);
}



/*  ======================================================================
    Class BtHsNmaTransferAudioToPhone
    ====================================================================== */

class BtHsNmaTransferAudioToPhone : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaTransferAudioToPhone(const BtResultCode& result);
        BtHsNmaTransferAudioToPhone();
        ~BtHsNmaTransferAudioToPhone();
        
        static const BtHsNmaTransferAudioToPhone& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 13
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaTransferAudioToPhone*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHsNmaTransferAudioToPhone& BtHsNmaTransferAudioToPhone::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaTransferAudioToPhone!\n");
    return ((BtHsNmaTransferAudioToPhone &) arg);
}



/*  ======================================================================
    Class BtHsNmaAudioConnectionLost
    ====================================================================== */

class BtHsNmaAudioConnectionLost : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaAudioConnectionLost(const BtResultCode& result);
        BtHsNmaAudioConnectionLost();
        ~BtHsNmaAudioConnectionLost();
        
        static const BtHsNmaAudioConnectionLost& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 14
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaAudioConnectionLost*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHsNmaAudioConnectionLost& BtHsNmaAudioConnectionLost::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaAudioConnectionLost!\n");
    return ((BtHsNmaAudioConnectionLost &) arg);
}



/*  ======================================================================
    Class BtHsNmaMicrophoneGain
    ====================================================================== */

class BtHsNmaMicrophoneGain : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaMicrophoneGain(const BtResultCode& result, UINT8 gain);
        BtHsNmaMicrophoneGain();
        ~BtHsNmaMicrophoneGain();
        
        static const BtHsNmaMicrophoneGain& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        UINT8 GetGain() const { return m_gain; }
        
        enum  {
            ID = 15
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaMicrophoneGain*) arg); }
        
        BtResultCode m_result;
        UINT8 m_gain;
        
    };

// Inline definitions
inline const BtHsNmaMicrophoneGain& BtHsNmaMicrophoneGain::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaMicrophoneGain!\n");
    return ((BtHsNmaMicrophoneGain &) arg);
}



/*  ======================================================================
    Class BtHsNmaSpeakerGain
    ====================================================================== */

class BtHsNmaSpeakerGain : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaSpeakerGain(const BtResultCode& result, UINT8 gain);
        BtHsNmaSpeakerGain();
        ~BtHsNmaSpeakerGain();
        
        static const BtHsNmaSpeakerGain& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        UINT8 GetGain() const { return m_gain; }
        
        enum  {
            ID = 16
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaSpeakerGain*) arg); }
        
        BtResultCode m_result;
        UINT8 m_gain;
        
    };

// Inline definitions
inline const BtHsNmaSpeakerGain& BtHsNmaSpeakerGain::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaSpeakerGain!\n");
    return ((BtHsNmaSpeakerGain &) arg);
}



/*  ======================================================================
    Class BtHsNmaLowPowerModeNotPossible
    ====================================================================== */

class BtHsNmaLowPowerModeNotPossible : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaLowPowerModeNotPossible(const BtResultCode& result);
        BtHsNmaLowPowerModeNotPossible();
        ~BtHsNmaLowPowerModeNotPossible();
        
        static const BtHsNmaLowPowerModeNotPossible& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 17
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaLowPowerModeNotPossible*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHsNmaLowPowerModeNotPossible& BtHsNmaLowPowerModeNotPossible::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaLowPowerModeNotPossible!\n");
    return ((BtHsNmaLowPowerModeNotPossible &) arg);
}



/*  ======================================================================
    Class BtHsNmaCallEvent
    ====================================================================== */

class BtHsNmaCallEvent : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsNmaCallEvent(const BtHsCallEvent& call_event);
        BtHsNmaCallEvent();
        ~BtHsNmaCallEvent();
        
        static const BtHsNmaCallEvent& Cast(const StackMsgArgument& arg);
        const BtHsCallEvent& GetCallEvent() const { return m_call_event; }
        
        enum  {
            ID = 18
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsNmaCallEvent*) arg); }
        
        BtHsCallEvent m_call_event;
        
    };

// Inline definitions
inline const BtHsNmaCallEvent& BtHsNmaCallEvent::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsNmaCallEvent!\n");
    return ((BtHsNmaCallEvent &) arg);
}


#endif // Bluetooth_HS_BtHsNotificationMessageArgument_hpp

