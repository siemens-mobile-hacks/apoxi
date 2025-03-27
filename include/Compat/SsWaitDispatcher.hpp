/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SsWaitDispatcher_hpp)
#define Asc_SsWaitDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    SsWaitDispatcher
    ======================================================================== */
class SsWaitDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        SsWaitDispatcher();
        virtual ~SsWaitDispatcher();
        
        BOOLEAN WasRejected() { return m_rejected; }
        BOOLEAN WasChangedToMoc() { return m_changed_to_moc; }

        Tipd GetTipd() { return m_tipd; }
        CallErrorCause GetCause() { return m_cause; }

    protected:
        BOOLEAN OnSsBeginAcc(const StackMsgArgument &arg);
        BOOLEAN OnSsFacilityRej(const StackMsgArgument &arg);
        BOOLEAN OnCallControlIndMsg(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<SsWaitDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SsWaitDispatcher> m_arg_map_container;
        
        Tipd m_tipd;
        BOOLEAN m_rejected;

        CallErrorCause m_cause;

        BOOLEAN m_changed_to_moc;
};

#endif  // Asc_SsWaitDispatcher_hpp


