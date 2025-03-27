/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "auzinger_mpe_pu_dv\lnz_apoxi\Apoxi\Apc\MtcArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_MtcStackMsgArgs_hpp)
#define Apc_MtcStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class MtcConfIndArg
    ====================================================================== */

class MtcConfIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MtcConfIndArg();
        
        static const MtcConfIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1160
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MtcConfIndArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const MtcConfIndArg& MtcConfIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MtcConfIndArg!\n");
    return ((MtcConfIndArg &) arg);
}



/*  ======================================================================
    Class MtcSetupIndArg
    ====================================================================== */

class MtcSetupIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MtcSetupIndArg();
        
        static const MtcSetupIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetConnectedNo(const PhoneNumber& connected_no) { m_connected_no = connected_no; }
        const PhoneNumber& GetConnectedNo() const { return m_connected_no; }
        void SetGsmSignal(const GsmSignal& gsm_signal) { m_gsm_signal = gsm_signal; }
        const GsmSignal& GetGsmSignal() const { return m_gsm_signal; }
        void SetCallLine(const LineSelector& call_line) { m_call_line = call_line; }
        const LineSelector& GetCallLine() const { return m_call_line; }
        void SetCtm(BOOLEAN ctm) { m_ctm = ctm; }
        BOOLEAN IsCtm() const { return m_ctm; }
        void SetCallType(const CallType& call_type) { m_call_type = call_type; }
        const CallType& GetCallType() const { return m_call_type; }
        
        enum  {
            ID = 1161
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MtcSetupIndArg*) arg); }
        
        Tipd m_tipd;
        PhoneNumber m_connected_no;
        GsmSignal m_gsm_signal;
        LineSelector m_call_line;
        BOOLEAN m_ctm;
        CallType m_call_type;
        
    };

// Inline definitions
inline const MtcSetupIndArg& MtcSetupIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MtcSetupIndArg!\n");
    return ((MtcSetupIndArg &) arg);
}



/*  ======================================================================
    Class MtcSetupComplArg
    ====================================================================== */

class MtcSetupComplArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MtcSetupComplArg();
        
        static const MtcSetupComplArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCrssCode(const CallRelatedSsCode& crss_code) { m_crss_code = crss_code; }
        const CallRelatedSsCode& GetCrssCode() const { return m_crss_code; }
        void SetCallType(const CallType& call_type) { m_call_type = call_type; }
        const CallType& GetCallType() const { return m_call_type; }
        
        enum  {
            ID = 1162
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MtcSetupComplArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSsCode m_crss_code;
        CallType m_call_type;
        
    };

// Inline definitions
inline const MtcSetupComplArg& MtcSetupComplArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MtcSetupComplArg!\n");
    return ((MtcSetupComplArg &) arg);
}



/*  ======================================================================
    Class MtcAcceptRejArg
    ====================================================================== */

class MtcAcceptRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MtcAcceptRejArg();
        
        static const MtcAcceptRejArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1163
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MtcAcceptRejArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const MtcAcceptRejArg& MtcAcceptRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MtcAcceptRejArg!\n");
    return ((MtcAcceptRejArg &) arg);
}



/*  ======================================================================
    Class MtcAcceptArg
    ====================================================================== */

class MtcAcceptArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MtcAcceptArg(const Tipd& tipd);
        MtcAcceptArg();
        
        static const MtcAcceptArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2160
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MtcAcceptArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const MtcAcceptArg& MtcAcceptArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MtcAcceptArg!\n");
    return ((MtcAcceptArg &) arg);
}



/*  ======================================================================
    Class MtcAlertReqArg
    ====================================================================== */

class MtcAlertReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MtcAlertReqArg(const Tipd& tipd);
        MtcAlertReqArg();
        
        static const MtcAlertReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 2161
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MtcAlertReqArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const MtcAlertReqArg& MtcAlertReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MtcAlertReqArg!\n");
    return ((MtcAlertReqArg &) arg);
}


#endif // Apc_MtcStackMsgArgs_hpp

