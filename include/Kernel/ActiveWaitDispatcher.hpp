/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ActiveWaitDispatcher_hpp)
#define Apoxi_ActiveWaitDispatcher_hpp

#include <Kernel/MessageMapDispatcher.hpp>
#include <Kernel/Condition.hpp>

class ActiveWaitDispatcher : public MessageMapDispatcher {
    typedef MessageMapDispatcher Base;

    public:
        ActiveWaitDispatcher(const AbstractMessageMapContainer *msg_map_container = 0, BOOLEAN add_immediately = FALSE);

        virtual ~ActiveWaitDispatcher();

        void Init(const AbstractMessageMapContainer *msg_map_container);

        virtual BOOLEAN Wait(UINT32 timeout = 0);

        void Done();

    private:
        TimeoutCondition m_condition;
};

#endif  // Apoxi_ActiveWaitDispatcher_hpp


