/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "pointner_leopard_development_pu_dv\lnz_apoxi\Apoxi\Bluetooth\HF\BtHfControllerMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_HF_BtHfControllerMessageArgument_hpp)
#define Bluetooth_HF_BtHfControllerMessageArgument_hpp

#include <Apc/StackMsgArgument.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHfCmaPhoneNumberRequired
    ====================================================================== */

class BtHfCmaPhoneNumberRequired : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfCmaPhoneNumberRequired(const BtResultCode& result);
        BtHfCmaPhoneNumberRequired();
        ~BtHfCmaPhoneNumberRequired();
        
        static const BtHfCmaPhoneNumberRequired& Cast(const StackMsgArgument& arg);
        void SetResult(const BtResultCode& result) { m_result = result; }
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 0
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfCmaPhoneNumberRequired*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtHfCmaPhoneNumberRequired& BtHfCmaPhoneNumberRequired::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfCmaPhoneNumberRequired!\n");
    return ((BtHfCmaPhoneNumberRequired &) arg);
}



/*  ======================================================================
    Class BtHfCmaMTC
    ====================================================================== */

class BtHfCmaMTC : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfCmaMTC();
        ~BtHfCmaMTC();
        
        static const BtHfCmaMTC& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfCmaMTC*) arg); }
        
    };

// Inline definitions
inline const BtHfCmaMTC& BtHfCmaMTC::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfCmaMTC!\n");
    return ((BtHfCmaMTC &) arg);
}



/*  ======================================================================
    Class BtHfCmaMOC
    ====================================================================== */

class BtHfCmaMOC : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfCmaMOC();
        ~BtHfCmaMOC();
        
        static const BtHfCmaMOC& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfCmaMOC*) arg); }
        
    };

// Inline definitions
inline const BtHfCmaMOC& BtHfCmaMOC::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfCmaMOC!\n");
    return ((BtHfCmaMOC &) arg);
}



/*  ======================================================================
    Class BtHfCmaAudioAsynchronous
    ====================================================================== */

class BtHfCmaAudioAsynchronous : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfCmaAudioAsynchronous(BOOLEAN sco_path_status, BOOLEAN audio_connected, BOOLEAN audio_switch_path);
        BtHfCmaAudioAsynchronous();
        ~BtHfCmaAudioAsynchronous();
        
        static const BtHfCmaAudioAsynchronous& Cast(const StackMsgArgument& arg);
        void SetScoPathStatus(BOOLEAN sco_path_status) { m_sco_path_status = sco_path_status; }
        BOOLEAN IsScoPathStatus() const { return m_sco_path_status; }
        void SetAudioConnected(BOOLEAN audio_connected) { m_audio_connected = audio_connected; }
        BOOLEAN IsAudioConnected() const { return m_audio_connected; }
        void SetAudioSwitchPath(BOOLEAN audio_switch_path) { m_audio_switch_path = audio_switch_path; }
        BOOLEAN IsAudioSwitchPath() const { return m_audio_switch_path; }
        
        enum  {
            ID = 3
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfCmaAudioAsynchronous*) arg); }
        
        BOOLEAN m_sco_path_status;
        BOOLEAN m_audio_connected;
        BOOLEAN m_audio_switch_path;
        
    };

// Inline definitions
inline const BtHfCmaAudioAsynchronous& BtHfCmaAudioAsynchronous::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfCmaAudioAsynchronous!\n");
    return ((BtHfCmaAudioAsynchronous &) arg);
}



/*  ======================================================================
    Class BtHfCmaAtChldOneCommandReceived
    ====================================================================== */

class BtHfCmaAtChldOneCommandReceived : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfCmaAtChldOneCommandReceived();
        ~BtHfCmaAtChldOneCommandReceived();
        
        static const BtHfCmaAtChldOneCommandReceived& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 4
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfCmaAtChldOneCommandReceived*) arg); }
        
    };

// Inline definitions
inline const BtHfCmaAtChldOneCommandReceived& BtHfCmaAtChldOneCommandReceived::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfCmaAtChldOneCommandReceived!\n");
    return ((BtHfCmaAtChldOneCommandReceived &) arg);
}



/*  ======================================================================
    Class BtHfCmaCheckPendingAudioCallback
    ====================================================================== */

class BtHfCmaCheckPendingAudioCallback : public StackMsgArgument {
    friend class BtHfMessageArgumentsDestroyTableNode;
    public:
        BtHfCmaCheckPendingAudioCallback();
        ~BtHfCmaCheckPendingAudioCallback();
        
        static const BtHfCmaCheckPendingAudioCallback& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHfCmaCheckPendingAudioCallback*) arg); }
        
    };

// Inline definitions
inline const BtHfCmaCheckPendingAudioCallback& BtHfCmaCheckPendingAudioCallback::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHfCmaCheckPendingAudioCallback!\n");
    return ((BtHfCmaCheckPendingAudioCallback &) arg);
}


#endif // Bluetooth_HF_BtHfControllerMessageArgument_hpp

