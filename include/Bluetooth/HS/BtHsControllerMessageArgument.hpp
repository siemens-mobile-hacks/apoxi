/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "pointner_leopard_development_pu_dv\lnz_apoxi\Apoxi\Bluetooth\HS\BtHsControllerMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_HS_BtHsControllerMessageArgument_hpp)
#define Bluetooth_HS_BtHsControllerMessageArgument_hpp

#include <Apc/StackMsgArgument.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHsCmaHangUp
    ====================================================================== */

class BtHsCmaHangUp : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsCmaHangUp();
        ~BtHsCmaHangUp();
        
        static const BtHsCmaHangUp& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsCmaHangUp*) arg); }
        
    };

// Inline definitions
inline const BtHsCmaHangUp& BtHsCmaHangUp::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsCmaHangUp!\n");
    return ((BtHsCmaHangUp &) arg);
}



/*  ======================================================================
    Class BtHsCmaAudioAsynchronous
    ====================================================================== */

class BtHsCmaAudioAsynchronous : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsCmaAudioAsynchronous(BOOLEAN sco_path_status, BOOLEAN audio_connected, BOOLEAN audio_switch_path);
        BtHsCmaAudioAsynchronous();
        ~BtHsCmaAudioAsynchronous();
        
        static const BtHsCmaAudioAsynchronous& Cast(const StackMsgArgument& arg);
        void SetScoPathStatus(BOOLEAN sco_path_status) { m_sco_path_status = sco_path_status; }
        BOOLEAN IsScoPathStatus() const { return m_sco_path_status; }
        void SetAudioConnected(BOOLEAN audio_connected) { m_audio_connected = audio_connected; }
        BOOLEAN IsAudioConnected() const { return m_audio_connected; }
        void SetAudioSwitchPath(BOOLEAN audio_switch_path) { m_audio_switch_path = audio_switch_path; }
        BOOLEAN IsAudioSwitchPath() const { return m_audio_switch_path; }
        
        enum  {
            ID = 2
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsCmaAudioAsynchronous*) arg); }
        
        BOOLEAN m_sco_path_status;
        BOOLEAN m_audio_connected;
        BOOLEAN m_audio_switch_path;
        
    };

// Inline definitions
inline const BtHsCmaAudioAsynchronous& BtHsCmaAudioAsynchronous::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsCmaAudioAsynchronous!\n");
    return ((BtHsCmaAudioAsynchronous &) arg);
}



/*  ======================================================================
    Class BtHsCmaEnterLowPowerMode
    ====================================================================== */

class BtHsCmaEnterLowPowerMode : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsCmaEnterLowPowerMode();
        ~BtHsCmaEnterLowPowerMode();
        
        static const BtHsCmaEnterLowPowerMode& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 3
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsCmaEnterLowPowerMode*) arg); }
        
    };

// Inline definitions
inline const BtHsCmaEnterLowPowerMode& BtHsCmaEnterLowPowerMode::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsCmaEnterLowPowerMode!\n");
    return ((BtHsCmaEnterLowPowerMode &) arg);
}



/*  ======================================================================
    Class BtHsCmaAudioTransferOutOfCall
    ====================================================================== */

class BtHsCmaAudioTransferOutOfCall : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsCmaAudioTransferOutOfCall();
        ~BtHsCmaAudioTransferOutOfCall();
        
        static const BtHsCmaAudioTransferOutOfCall& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 4
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsCmaAudioTransferOutOfCall*) arg); }
        
    };

// Inline definitions
inline const BtHsCmaAudioTransferOutOfCall& BtHsCmaAudioTransferOutOfCall::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsCmaAudioTransferOutOfCall!\n");
    return ((BtHsCmaAudioTransferOutOfCall &) arg);
}



/*  ======================================================================
    Class BtHsCmaCheckPendingAudioCallback
    ====================================================================== */

class BtHsCmaCheckPendingAudioCallback : public StackMsgArgument {
    friend class BtHsMessageArgumentsDestroyTableNode;
    public:
        BtHsCmaCheckPendingAudioCallback();
        ~BtHsCmaCheckPendingAudioCallback();
        
        static const BtHsCmaCheckPendingAudioCallback& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtHsCmaCheckPendingAudioCallback*) arg); }
        
    };

// Inline definitions
inline const BtHsCmaCheckPendingAudioCallback& BtHsCmaCheckPendingAudioCallback::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtHsCmaCheckPendingAudioCallback!\n");
    return ((BtHsCmaCheckPendingAudioCallback &) arg);
}


#endif // Bluetooth_HS_BtHsControllerMessageArgument_hpp

