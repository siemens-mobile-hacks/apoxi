/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS 

#if !defined(Asc_MocVoiceDispatcher_hpp)
#define Asc_MocVoiceDispatcher_hpp

// #include <Asc/StackMsgActiveWaitDispatcher.hpp>
#include <Asc/TipdBasedActiveWaitDispatcher.hpp>
#include <Apc/StackMsgArgument.hpp>

class MocVoiceDispatcher : public TipdBasedActiveWaitDispatcher {
    typedef TipdBasedActiveWaitDispatcher Base;
    public:
        MocVoiceDispatcher();
        virtual ~MocVoiceDispatcher();


        CallErrorCause GetRejectCause() const { return m_rej_cause; } 

        void SetRejectCause(CallErrorCause rej_cause) { m_rej_cause = rej_cause; }


        BOOLEAN OnMocSetupRej(const StackMsgArgument &arg);

        BOOLEAN OnMocSetupAcc(const StackMsgArgument &arg);

        BOOLEAN OnHoldCnf(const StackMsgArgument &arg);

        BOOLEAN OnHoldRej(const StackMsgArgument &arg);

        BOOLEAN OnMptyCnf(const StackMsgArgument &arg);

        BOOLEAN OnSsErrInd(const StackMsgArgument &arg);
        BOOLEAN OnSsControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnUssdControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnCallControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnCallSetupBySimtTkReq(const StackMsgArgument &arg);
        
        static void SetIsPhoneRinging(BOOLEAN activate) { m_is_phone_ringing = activate; }
        static BOOLEAN IsPhoneRinging() { return m_is_phone_ringing; }

    private:
        static const StackMsgArgMap<MocVoiceDispatcher> m_arg_map[];
        StackMsgArgMapContainer<MocVoiceDispatcher> m_arg_map_container;

        CallErrorCause  m_rej_cause;
        static BOOLEAN  m_is_phone_ringing;
};

#endif  // Asc_MocVoiceDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS 


