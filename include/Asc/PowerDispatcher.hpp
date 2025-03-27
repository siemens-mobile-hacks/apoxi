/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_PowerDispatcher_hpp)
#define Asc_PowerDispatcher_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Asc/StackMsgDispatcher.hpp>


/*  ========================================================================
    PowerDispatcher
    ======================================================================== */
class PowerDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        PowerDispatcher();
        
        virtual ~PowerDispatcher();

    protected:
        BOOLEAN OnOmControlInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<PowerDispatcher> m_arg_map[];
        StackMsgArgMapContainer<PowerDispatcher> m_arg_map_container;
};

#endif // Asc_PowerDispatcher_hpp


