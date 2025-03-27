/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\HF\BtHfNotificationMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_HF_BtHfNotificationMessageArgument_hpp)
#define Bluetooth_HF_BtHfNotificationMessageArgument_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/HF/BtTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHfNmaConnect
    ====================================================================== */

class BtHfNmaConnect : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaConnect(const BtResultCode& result, const BtDevice& device);
        BtHfNmaConnect();
        ~BtHfNmaConnect();
        
        static const BtHfNmaConnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        const BtDevice& GetDevice() const { return m_device; }
        
        enum  {
            ID = 10
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaConnect*) arg); }
        
        BtResultCode m_result;
        BtDevice m_device;
        
    };

// Inline definitions
inline const BtHfNmaConnect& BtHfNmaConnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaConnect!\n");
    return ((BtHfNmaConnect &) arg);
}



/*  ======================================================================
    Class BtHfNmaDisconnect
    ====================================================================== */

class BtHfNmaDisconnect : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaDisconnect(const BtResultCode& result);
        BtHfNmaDisconnect();
        ~BtHfNmaDisconnect();
        
        static const BtHfNmaDisconnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 11
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaDisconnect*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHfNmaDisconnect& BtHfNmaDisconnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaDisconnect!\n");
    return ((BtHfNmaDisconnect &) arg);
}



/*  ======================================================================
    Class BtHfNmaTransferAudioToAccessory
    ====================================================================== */

class BtHfNmaTransferAudioToAccessory : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaTransferAudioToAccessory(const BtResultCode& result);
        BtHfNmaTransferAudioToAccessory();
        ~BtHfNmaTransferAudioToAccessory();
        
        static const BtHfNmaTransferAudioToAccessory& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 12
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaTransferAudioToAccessory*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHfNmaTransferAudioToAccessory& BtHfNmaTransferAudioToAccessory::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaTransferAudioToAccessory!\n");
    return ((BtHfNmaTransferAudioToAccessory &) arg);
}



/*  ======================================================================
    Class BtHfNmaTransferAudioToPhone
    ====================================================================== */

class BtHfNmaTransferAudioToPhone : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaTransferAudioToPhone(const BtResultCode& result);
        BtHfNmaTransferAudioToPhone();
        ~BtHfNmaTransferAudioToPhone();
        
        static const BtHfNmaTransferAudioToPhone& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 13
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaTransferAudioToPhone*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHfNmaTransferAudioToPhone& BtHfNmaTransferAudioToPhone::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaTransferAudioToPhone!\n");
    return ((BtHfNmaTransferAudioToPhone &) arg);
}



/*  ======================================================================
    Class BtHfNmaAudioConnectionLost
    ====================================================================== */

class BtHfNmaAudioConnectionLost : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaAudioConnectionLost(const BtResultCode& result);
        BtHfNmaAudioConnectionLost();
        ~BtHfNmaAudioConnectionLost();
        
        static const BtHfNmaAudioConnectionLost& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 14
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaAudioConnectionLost*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHfNmaAudioConnectionLost& BtHfNmaAudioConnectionLost::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaAudioConnectionLost!\n");
    return ((BtHfNmaAudioConnectionLost &) arg);
}



/*  ======================================================================
    Class BtHfNmaMicrophoneGain
    ====================================================================== */

class BtHfNmaMicrophoneGain : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaMicrophoneGain(const BtResultCode& result, UINT8 gain);
        BtHfNmaMicrophoneGain();
        ~BtHfNmaMicrophoneGain();
        
        static const BtHfNmaMicrophoneGain& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        UINT8 GetGain() const { return m_gain; }
        
        enum  {
            ID = 15
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaMicrophoneGain*) arg); }
        
        BtResultCode m_result;
        UINT8 m_gain;
        
    };

// Inline definitions
inline const BtHfNmaMicrophoneGain& BtHfNmaMicrophoneGain::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaMicrophoneGain!\n");
    return ((BtHfNmaMicrophoneGain &) arg);
}



/*  ======================================================================
    Class BtHfNmaSpeakerGain
    ====================================================================== */

class BtHfNmaSpeakerGain : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaSpeakerGain(const BtResultCode& result, UINT8 gain);
        BtHfNmaSpeakerGain();
        ~BtHfNmaSpeakerGain();
        
        static const BtHfNmaSpeakerGain& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        UINT8 GetGain() const { return m_gain; }
        
        enum  {
            ID = 16
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaSpeakerGain*) arg); }
        
        BtResultCode m_result;
        UINT8 m_gain;
        
    };

// Inline definitions
inline const BtHfNmaSpeakerGain& BtHfNmaSpeakerGain::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaSpeakerGain!\n");
    return ((BtHfNmaSpeakerGain &) arg);
}



/*  ======================================================================
    Class BtHfNmaLowPowerModeNotPossible
    ====================================================================== */

class BtHfNmaLowPowerModeNotPossible : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaLowPowerModeNotPossible(const BtResultCode& result);
        BtHfNmaLowPowerModeNotPossible();
        ~BtHfNmaLowPowerModeNotPossible();
        
        static const BtHfNmaLowPowerModeNotPossible& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 17
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaLowPowerModeNotPossible*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHfNmaLowPowerModeNotPossible& BtHfNmaLowPowerModeNotPossible::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaLowPowerModeNotPossible!\n");
    return ((BtHfNmaLowPowerModeNotPossible &) arg);
}



/*  ======================================================================
    Class BtHfNmaCallEvent
    ====================================================================== */

class BtHfNmaCallEvent : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfNmaCallEvent(const BtHfCallEvent& call_event);
        BtHfNmaCallEvent();
        ~BtHfNmaCallEvent();
        
        static const BtHfNmaCallEvent& Cast(const StackMsgArgument& arg);
        const BtHfCallEvent& GetCallEvent() const { return m_call_event; }
        
        enum  {
            ID = 18
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfNmaCallEvent*) arg); }
        
        BtHfCallEvent m_call_event;
        
    };

// Inline definitions
inline const BtHfNmaCallEvent& BtHfNmaCallEvent::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfNmaCallEvent!\n");
    return ((BtHfNmaCallEvent &) arg);
}


#endif // Bluetooth_HF_BtHfNotificationMessageArgument_hpp

