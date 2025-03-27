/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_development\src\Apoxi\Apc\CdArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_CdStackMsgArgs_hpp)
#define Apc_CdStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class CallDeflectionIndArg
    ====================================================================== */

class CallDeflectionIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallDeflectionIndArg();
        
        static const CallDeflectionIndArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1069
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallDeflectionIndArg*) arg); }
        
        Tipd m_tipd;
        
    };

// Inline definitions
inline const CallDeflectionIndArg& CallDeflectionIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallDeflectionIndArg!\n");
    return ((CallDeflectionIndArg &) arg);
}



/*  ======================================================================
    Class CallDeflectSsReqArg
    ====================================================================== */

class CallDeflectSsReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallDeflectSsReqArg(const Tipd& tipd, const CallRelatedSs& call_related_ss, const PhoneNumber& deflect_number);
        CallDeflectSsReqArg();
        
        static const CallDeflectSsReqArg& Cast(const StackMsgArgument& arg);
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetCallRelatedSs(const CallRelatedSs& call_related_ss) { m_call_related_ss = call_related_ss; }
        const CallRelatedSs& GetCallRelatedSs() const { return m_call_related_ss; }
        void SetDeflectNumber(const PhoneNumber& deflect_number) { m_deflect_number = deflect_number; }
        const PhoneNumber& GetDeflectNumber() const { return m_deflect_number; }
        
        enum  {
            ID = 2065
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallDeflectSsReqArg*) arg); }
        
        Tipd m_tipd;
        CallRelatedSs m_call_related_ss;
        PhoneNumber m_deflect_number;
        
    };

// Inline definitions
inline const CallDeflectSsReqArg& CallDeflectSsReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallDeflectSsReqArg!\n");
    return ((CallDeflectSsReqArg &) arg);
}


#endif // Apc_CdStackMsgArgs_hpp

