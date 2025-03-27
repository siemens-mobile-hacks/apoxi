/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AccDispatcher_hpp)
#define Asc_AccDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

class AccDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        AccDispatcher();
        virtual ~AccDispatcher();

    protected:
        BOOLEAN OnAccessoryInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<AccDispatcher> m_arg_map[];
        StackMsgArgMapContainer<AccDispatcher> m_arg_map_container;
};

#endif // Asc_AccDispatcher_hpp


