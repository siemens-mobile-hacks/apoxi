/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_PowerDownDispatcher_hpp)
#define Asc_PowerDownDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    PowerDownDispatcher
    ======================================================================== */
class PowerDownDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        PowerDownDispatcher();
        virtual ~PowerDownDispatcher();

    protected:
        BOOLEAN OnPowerDownCnf(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<PowerDownDispatcher> m_arg_map[];
        StackMsgArgMapContainer<PowerDownDispatcher> m_arg_map_container;
};

#endif // Asc_PowerDownDispatcher_hpp


