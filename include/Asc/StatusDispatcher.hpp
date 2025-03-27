/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SatusDispatcher_hpp)
#define Asc_StatusDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

class StatusDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        StatusDispatcher();
        virtual ~StatusDispatcher();

    protected:

    private:
        static const StackMsgArgMap<StatusDispatcher> m_arg_map[];
        StackMsgArgMapContainer<StatusDispatcher> m_arg_map_container;
};

#endif // Asc_StatusDispatcher_hpp


