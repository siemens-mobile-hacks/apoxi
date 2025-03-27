/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\grossau_latest_sv\lnz_apoxi\Apoxi\Apc\ChvArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_ChvStackMsgArgs_hpp)
#define Apc_ChvStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>


const UINT8 c_chv_padding_char  = 0xff;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class ChvVerifyIndArg
    ====================================================================== */

class ChvVerifyIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvVerifyIndArg();
        
        static const ChvVerifyIndArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        void SetChvAttempts(const ChvAttemptsStruct& chv_attempts) { m_chv_attempts = chv_attempts; }
        const ChvAttemptsStruct& GetChvAttempts() const { return m_chv_attempts; }
        
        enum  {
            ID = 1040
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvVerifyIndArg*) arg); }
        
        ChvNo m_chvno;
        ChvStatus m_status;
        ChvAttemptsStruct m_chv_attempts;
        
    };

// Inline definitions
inline const ChvVerifyIndArg& ChvVerifyIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvVerifyIndArg!\n");
    return ((ChvVerifyIndArg &) arg);
}



/*  ======================================================================
    Class ChvChangeIndArg
    ====================================================================== */

class ChvChangeIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvChangeIndArg();
        
        static const ChvChangeIndArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        void SetChvAttempts(const ChvAttemptsStruct& chv_attempts) { m_chv_attempts = chv_attempts; }
        const ChvAttemptsStruct& GetChvAttempts() const { return m_chv_attempts; }
        
        enum  {
            ID = 1041
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvChangeIndArg*) arg); }
        
        ChvNo m_chvno;
        ChvStatus m_status;
        ChvAttemptsStruct m_chv_attempts;
        
    };

// Inline definitions
inline const ChvChangeIndArg& ChvChangeIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvChangeIndArg!\n");
    return ((ChvChangeIndArg &) arg);
}



/*  ======================================================================
    Class ChvUnblockIndArg
    ====================================================================== */

class ChvUnblockIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvUnblockIndArg();
        
        static const ChvUnblockIndArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        void SetChvAttempts(const ChvAttemptsStruct& chv_attempts) { m_chv_attempts = chv_attempts; }
        const ChvAttemptsStruct& GetChvAttempts() const { return m_chv_attempts; }
        
        enum  {
            ID = 1042
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvUnblockIndArg*) arg); }
        
        ChvNo m_chvno;
        ChvStatus m_status;
        ChvAttemptsStruct m_chv_attempts;
        
    };

// Inline definitions
inline const ChvUnblockIndArg& ChvUnblockIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvUnblockIndArg!\n");
    return ((ChvUnblockIndArg &) arg);
}



/*  ======================================================================
    Class Chv1EnableIndArg
    ====================================================================== */

class Chv1EnableIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        Chv1EnableIndArg();
        
        static const Chv1EnableIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        void SetChvAttempts(const ChvAttemptsStruct& chv_attempts) { m_chv_attempts = chv_attempts; }
        const ChvAttemptsStruct& GetChvAttempts() const { return m_chv_attempts; }
        
        enum  {
            ID = 1043
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((Chv1EnableIndArg*) arg); }
        
        ChvStatus m_status;
        ChvAttemptsStruct m_chv_attempts;
        
    };

// Inline definitions
inline const Chv1EnableIndArg& Chv1EnableIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to Chv1EnableIndArg!\n");
    return ((Chv1EnableIndArg &) arg);
}



/*  ======================================================================
    Class Chv1DisableIndArg
    ====================================================================== */

class Chv1DisableIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        Chv1DisableIndArg();
        
        static const Chv1DisableIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        void SetChvAttempts(const ChvAttemptsStruct& chv_attempts) { m_chv_attempts = chv_attempts; }
        const ChvAttemptsStruct& GetChvAttempts() const { return m_chv_attempts; }
        
        enum  {
            ID = 1044
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((Chv1DisableIndArg*) arg); }
        
        ChvStatus m_status;
        ChvAttemptsStruct m_chv_attempts;
        
    };

// Inline definitions
inline const Chv1DisableIndArg& Chv1DisableIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to Chv1DisableIndArg!\n");
    return ((Chv1DisableIndArg &) arg);
}



/*  ======================================================================
    Class ChvRefreshIndArg
    ====================================================================== */

class ChvRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvRefreshIndArg();
        
        static const ChvRefreshIndArg& Cast(const StackMsgArgument& arg);
        void SetChvAction(const ChvAction& chv_action) { m_chv_action = chv_action; }
        const ChvAction& GetChvAction() const { return m_chv_action; }
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        void SetResult(BOOLEAN result) { m_result = result; }
        BOOLEAN IsResult() const { return m_result; }
        void SetChvAttempts(const ChvAttemptsStruct& chv_attempts) { m_chv_attempts = chv_attempts; }
        const ChvAttemptsStruct& GetChvAttempts() const { return m_chv_attempts; }
        
        enum  {
            ID = 1045
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvRefreshIndArg*) arg); }
        
        ChvAction m_chv_action;
        ChvNo m_chvno;
        ChvStatus m_status;
        BOOLEAN m_result;
        ChvAttemptsStruct m_chv_attempts;
        
    };

// Inline definitions
inline const ChvRefreshIndArg& ChvRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvRefreshIndArg!\n");
    return ((ChvRefreshIndArg &) arg);
}



/*  ======================================================================
    Class PinEnableIndArg
    ====================================================================== */

class PinEnableIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PinEnableIndArg();
        
        static const PinEnableIndArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetResult(BOOLEAN result) { m_result = result; }
        BOOLEAN IsResult() const { return m_result; }
        void SetAddResult(INT8 add_result) { m_add_result = add_result; }
        INT8 GetAddResult() const { return m_add_result; }
        
        enum  {
            ID = 1046
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PinEnableIndArg*) arg); }
        
        ChvNo m_chvno;
        BOOLEAN m_result;
        INT8 m_add_result;
        
    };

// Inline definitions
inline const PinEnableIndArg& PinEnableIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PinEnableIndArg!\n");
    return ((PinEnableIndArg &) arg);
}



/*  ======================================================================
    Class PinDisableIndArg
    ====================================================================== */

class PinDisableIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PinDisableIndArg();
        
        static const PinDisableIndArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetResult(BOOLEAN result) { m_result = result; }
        BOOLEAN IsResult() const { return m_result; }
        void SetAddResult(INT8 add_result) { m_add_result = add_result; }
        INT8 GetAddResult() const { return m_add_result; }
        
        enum  {
            ID = 1047
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PinDisableIndArg*) arg); }
        
        ChvNo m_chvno;
        BOOLEAN m_result;
        INT8 m_add_result;
        
    };

// Inline definitions
inline const PinDisableIndArg& PinDisableIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PinDisableIndArg!\n");
    return ((PinDisableIndArg &) arg);
}



/*  ======================================================================
    Class ChvVerifyReqArg
    ====================================================================== */

class ChvVerifyReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvVerifyReqArg(const ChvNo& chvno, const CHAR* pin);
        ChvVerifyReqArg(const ChvNo& chvno, const T_SI_CHV& chv);
        ChvVerifyReqArg();
        
        static const ChvVerifyReqArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetChv(const T_SI_CHV& chv) { m_chv = chv; }
        const T_SI_CHV& GetChv() const { return m_chv; }
        
        enum  {
            ID = 2040
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvVerifyReqArg*) arg); }
        
        ChvNo m_chvno;
        T_SI_CHV m_chv;
        
    };

// Inline definitions
inline const ChvVerifyReqArg& ChvVerifyReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvVerifyReqArg!\n");
    return ((ChvVerifyReqArg &) arg);
}



/*  ======================================================================
    Class ChvChangeReqArg
    ====================================================================== */

class ChvChangeReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvChangeReqArg(const ChvNo& chvno, const CHAR* oldpin, const CHAR* newpin);
        ChvChangeReqArg(const ChvNo& chvno, const T_SI_CHV& oldchv, const T_SI_CHV& newchv);
        ChvChangeReqArg();
        
        static const ChvChangeReqArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetOldchv(const T_SI_CHV& oldchv) { m_oldchv = oldchv; }
        const T_SI_CHV& GetOldchv() const { return m_oldchv; }
        void SetNewchv(const T_SI_CHV& newchv) { m_newchv = newchv; }
        const T_SI_CHV& GetNewchv() const { return m_newchv; }
        
        enum  {
            ID = 2041
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvChangeReqArg*) arg); }
        
        ChvNo m_chvno;
        T_SI_CHV m_oldchv;
        T_SI_CHV m_newchv;
        
    };

// Inline definitions
inline const ChvChangeReqArg& ChvChangeReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvChangeReqArg!\n");
    return ((ChvChangeReqArg &) arg);
}



/*  ======================================================================
    Class ChvUnblockReqArg
    ====================================================================== */

class ChvUnblockReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ChvUnblockReqArg(const ChvNo& chvno, const CHAR* unblockpin, const CHAR* newpin);
        ChvUnblockReqArg(const ChvNo& chvno, const T_SI_CHV& unblockchv, const T_SI_CHV& newchv);
        ChvUnblockReqArg();
        
        static const ChvUnblockReqArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetUnblockchv(const T_SI_CHV& unblockchv) { m_unblockchv = unblockchv; }
        const T_SI_CHV& GetUnblockchv() const { return m_unblockchv; }
        void SetNewchv(const T_SI_CHV& newchv) { m_newchv = newchv; }
        const T_SI_CHV& GetNewchv() const { return m_newchv; }
        
        enum  {
            ID = 2042
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ChvUnblockReqArg*) arg); }
        
        ChvNo m_chvno;
        T_SI_CHV m_unblockchv;
        T_SI_CHV m_newchv;
        
    };

// Inline definitions
inline const ChvUnblockReqArg& ChvUnblockReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ChvUnblockReqArg!\n");
    return ((ChvUnblockReqArg &) arg);
}



/*  ======================================================================
    Class Chv1EnableReqArg
    ====================================================================== */

class Chv1EnableReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        Chv1EnableReqArg(const CHAR* pin);
        Chv1EnableReqArg(const T_SI_CHV& chv);
        Chv1EnableReqArg();
        
        static const Chv1EnableReqArg& Cast(const StackMsgArgument& arg);
        void SetChv(const T_SI_CHV& chv) { m_chv = chv; }
        const T_SI_CHV& GetChv() const { return m_chv; }
        
        enum  {
            ID = 2043
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((Chv1EnableReqArg*) arg); }
        
        T_SI_CHV m_chv;
        
    };

// Inline definitions
inline const Chv1EnableReqArg& Chv1EnableReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to Chv1EnableReqArg!\n");
    return ((Chv1EnableReqArg &) arg);
}



/*  ======================================================================
    Class Chv1DisableReqArg
    ====================================================================== */

class Chv1DisableReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        Chv1DisableReqArg(const CHAR* pin);
        Chv1DisableReqArg(const T_SI_CHV& chv);
        Chv1DisableReqArg();
        
        static const Chv1DisableReqArg& Cast(const StackMsgArgument& arg);
        void SetChv(const T_SI_CHV& chv) { m_chv = chv; }
        const T_SI_CHV& GetChv() const { return m_chv; }
        
        enum  {
            ID = 2044
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((Chv1DisableReqArg*) arg); }
        
        T_SI_CHV m_chv;
        
    };

// Inline definitions
inline const Chv1DisableReqArg& Chv1DisableReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to Chv1DisableReqArg!\n");
    return ((Chv1DisableReqArg &) arg);
}



/*  ======================================================================
    Class PinEnableReqArg
    ====================================================================== */

class PinEnableReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PinEnableReqArg(const ChvNo& chvno, const CHAR* pin);
        PinEnableReqArg(const ChvNo& chvno, const T_SI_CHV& chv);
        PinEnableReqArg();
        
        static const PinEnableReqArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetChv(const T_SI_CHV& chv) { m_chv = chv; }
        const T_SI_CHV& GetChv() const { return m_chv; }
        
        enum  {
            ID = 2045
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PinEnableReqArg*) arg); }
        
        ChvNo m_chvno;
        T_SI_CHV m_chv;
        
    };

// Inline definitions
inline const PinEnableReqArg& PinEnableReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PinEnableReqArg!\n");
    return ((PinEnableReqArg &) arg);
}



/*  ======================================================================
    Class PinDisableReqArg
    ====================================================================== */

class PinDisableReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PinDisableReqArg(const ChvNo& chvno, const CHAR* pin);
        PinDisableReqArg(const ChvNo& chvno, const T_SI_CHV& chv);
        PinDisableReqArg();
        
        static const PinDisableReqArg& Cast(const StackMsgArgument& arg);
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetChv(const T_SI_CHV& chv) { m_chv = chv; }
        const T_SI_CHV& GetChv() const { return m_chv; }
        
        enum  {
            ID = 2046
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PinDisableReqArg*) arg); }
        
        ChvNo m_chvno;
        T_SI_CHV m_chv;
        
    };

// Inline definitions
inline const PinDisableReqArg& PinDisableReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PinDisableReqArg!\n");
    return ((PinDisableReqArg &) arg);
}


#endif // Apc_ChvStackMsgArgs_hpp

