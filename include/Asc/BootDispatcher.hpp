/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_BootDispatcher_hpp)
#define Asc_BootDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    BootDispatcher
    ======================================================================== */
class BootDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

    public:
        BootDispatcher();
        virtual ~BootDispatcher();

    protected:
        BOOLEAN OnBootDispatching(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<BootDispatcher> m_arg_map[];
        StackMsgArgMapContainer<BootDispatcher> m_arg_map_container;
};

#endif // Asc_BootDispatcher_hpp


