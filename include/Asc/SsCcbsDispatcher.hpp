          /*    ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SsCcbsDispatcher_hpp)
#define Asc_SsCcbsDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    SsCcbsDispatcher
    ======================================================================== */
class SsCcbsDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        SsCcbsDispatcher();
        virtual ~SsCcbsDispatcher();

    protected:

        BOOLEAN OnSsCcbsReCallInd(const StackMsgArgument &arg);
        BOOLEAN OnSsCcbsStatusInd(const StackMsgArgument &arg);
        BOOLEAN OnSsCcbsResultInd(const StackMsgArgument &arg);


    private:
        static const StackMsgArgMap<SsCcbsDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SsCcbsDispatcher> m_arg_map_container;
};

#endif // Asc_SsCcbsDispatcher_hpp


