/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AocDispatcher_hpp)
#define Asc_AocDispatcher_hpp

#include <Asc/StackMsgDispatcher.hpp>
#include "StackIndicationMsgTypes.hpp"

class AocDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        AocDispatcher();
        virtual ~AocDispatcher();

    protected:
        BOOLEAN OnAocInd(const StackMsgArgument &arg);

        BOOLEAN OnChargeUnitsInd(const StackMsgArgument &arg);

        BOOLEAN OnChargeInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<AocDispatcher> m_arg_map[];
        StackMsgArgMapContainer<AocDispatcher> m_arg_map_container;
};

#endif // Asc_AocDispatcher_hpp


