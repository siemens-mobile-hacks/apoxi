/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_CallReleaseDispatcher_hpp)
#define Asc_CallReleaseDispatcher_hpp

// #include <Asc/StackMsgActiveWaitDispatcher.hpp>
#include <Asc/TipdBasedActiveWaitDispatcher.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Asc/CallDispatcher.hpp>


/*  ========================================================================
    TipdList
    ======================================================================== */
class LinkableTipd : public Linkable<LinkableTipd> {
    public:
        LinkableTipd(const Tipd tipd) : m_tipd(tipd) {}
        Tipd GetTipd() const { return m_tipd; } 
    private: 
        Tipd m_tipd;
};

/*  ========================================================================
    TipdList
    ======================================================================== */
typedef LinkedList<LinkableTipd> TipdList;


class CallReleaseDispatcher : public TipdBasedActiveWaitDispatcher {
    typedef TipdBasedActiveWaitDispatcher Base;
    public:
        CallReleaseDispatcher(Tipd tipd, CallDispatcher* call_disp);
        
        CallReleaseDispatcher(TipdList* tipd_list, CallDispatcher* call_disp);
        
        virtual ~CallReleaseDispatcher();

    protected:

        BOOLEAN OnCallRelCnf(const StackMsgArgument &arg);
        
        BOOLEAN OnCallDiscInd(const StackMsgArgument &arg);

        BOOLEAN OnCallRelInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<CallReleaseDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CallReleaseDispatcher> m_arg_map_container;
        CallDispatcher* m_call_disp;
        TipdList* m_tipd_list;

};

#endif  // Asc_CallReleaseDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


