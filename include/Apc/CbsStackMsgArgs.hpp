/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Apc\CbsArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_CbsStackMsgArgs_hpp)
#define Apc_CbsStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/Cbs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class CbsNewDataIndArg
    ====================================================================== */

class CbsNewDataIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsNewDataIndArg();
        
        static const CbsNewDataIndArg& Cast(const StackMsgArgument& arg);
        void SetCbs(const Cbs& cbs) { m_cbs = cbs; }
        const Cbs& GetCbs() const { return m_cbs; }
        
        enum  {
            ID = 1020
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsNewDataIndArg*) arg); }
        
        Cbs m_cbs;
        
    };

// Inline definitions
inline const CbsNewDataIndArg& CbsNewDataIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsNewDataIndArg!\n");
    return ((CbsNewDataIndArg &) arg);
}



/*  ======================================================================
    Class CbsStartRejArg
    ====================================================================== */

class CbsStartRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsStartRejArg();
        
        static const CbsStartRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1021
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsStartRejArg*) arg); }
        
    };

// Inline definitions
inline const CbsStartRejArg& CbsStartRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsStartRejArg!\n");
    return ((CbsStartRejArg &) arg);
}



/*  ======================================================================
    Class CbsStopRejArg
    ====================================================================== */

class CbsStopRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsStopRejArg();
        
        static const CbsStopRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1022
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsStopRejArg*) arg); }
        
    };

// Inline definitions
inline const CbsStopRejArg& CbsStopRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsStopRejArg!\n");
    return ((CbsStopRejArg &) arg);
}



/*  ======================================================================
    Class CbsStartCnfArg
    ====================================================================== */

class CbsStartCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsStartCnfArg();
        
        static const CbsStartCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1023
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsStartCnfArg*) arg); }
        
    };

// Inline definitions
inline const CbsStartCnfArg& CbsStartCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsStartCnfArg!\n");
    return ((CbsStartCnfArg &) arg);
}



/*  ======================================================================
    Class CbsStopCnfArg
    ====================================================================== */

class CbsStopCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsStopCnfArg();
        
        static const CbsStopCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1024
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsStopCnfArg*) arg); }
        
    };

// Inline definitions
inline const CbsStopCnfArg& CbsStopCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsStopCnfArg!\n");
    return ((CbsStopCnfArg &) arg);
}



/*  ======================================================================
    Class CbsLimitIndArg
    ====================================================================== */

class CbsLimitIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsLimitIndArg();
        
        static const CbsLimitIndArg& Cast(const StackMsgArgument& arg);
        void SetMaxMessageId(UINT16 max_message_id) { m_max_message_id = max_message_id; }
        UINT16 GetMaxMessageId() const { return m_max_message_id; }
        
        enum  {
            ID = 1025
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsLimitIndArg*) arg); }
        
        UINT16 m_max_message_id;
        
    };

// Inline definitions
inline const CbsLimitIndArg& CbsLimitIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsLimitIndArg!\n");
    return ((CbsLimitIndArg &) arg);
}



/*  ======================================================================
    Class CbsNewDataRejArg
    ====================================================================== */

class CbsNewDataRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsNewDataRejArg(const Cbs::SerialNumber& serial_number, const MessageIdentifier& message_identifier);
        CbsNewDataRejArg();
        ~CbsNewDataRejArg();
        
        static const CbsNewDataRejArg& Cast(const StackMsgArgument& arg);
        void SetSerialNumber(const Cbs::SerialNumber& serial_number) { m_serial_number = serial_number; }
        const Cbs::SerialNumber& GetSerialNumber() const { return m_serial_number; }
        void SetMessageIdentifier(const MessageIdentifier& message_identifier) { m_message_identifier = message_identifier; }
        const MessageIdentifier& GetMessageIdentifier() const { return m_message_identifier; }
        
        enum  {
            ID = 2020
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsNewDataRejArg*) arg); }
        
        Cbs::SerialNumber m_serial_number;
        MessageIdentifier m_message_identifier;
        
    };

// Inline definitions
inline const CbsNewDataRejArg& CbsNewDataRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsNewDataRejArg!\n");
    return ((CbsNewDataRejArg &) arg);
}



/*  ======================================================================
    Class CbsStartReqArg
    ====================================================================== */

class CbsStartReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsStartReqArg(const Cbs::Filter& filter);
        CbsStartReqArg();
        
        static const CbsStartReqArg& Cast(const StackMsgArgument& arg);
        void SetFilter(const Cbs::Filter& filter) { m_filter = filter; }
        const Cbs::Filter& GetFilter() const { return m_filter; }
        
        enum  {
            ID = 2021
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsStartReqArg*) arg); }
        
        Cbs::Filter m_filter;
        
    };

// Inline definitions
inline const CbsStartReqArg& CbsStartReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsStartReqArg!\n");
    return ((CbsStartReqArg &) arg);
}



/*  ======================================================================
    Class CbsStopReqArg
    ====================================================================== */

class CbsStopReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CbsStopReqArg();
        
        static const CbsStopReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2022
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CbsStopReqArg*) arg); }
        
    };

// Inline definitions
inline const CbsStopReqArg& CbsStopReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CbsStopReqArg!\n");
    return ((CbsStopReqArg &) arg);
}


#endif // Apc_CbsStackMsgArgs_hpp

