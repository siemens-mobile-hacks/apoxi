/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MultiSlotDispatcher_hpp)
#define Asc_MultiSlotDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    MultiSlotDispatcher
    ======================================================================== */
class MultiSlotDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        MultiSlotDispatcher();
        virtual ~MultiSlotDispatcher();

        BOOLEAN GetMultiModeSetResult(){ return m_multimode_success; }

    protected:
        BOOLEAN OnOmMultiSlotInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<MultiSlotDispatcher> m_arg_map[];
        StackMsgArgMapContainer<MultiSlotDispatcher> m_arg_map_container;
        BOOLEAN m_multimode_success;
};

#endif  // Asc_MultiSlotDispatcher_hpp


