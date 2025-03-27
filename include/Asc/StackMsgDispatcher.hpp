/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_StackMsgDispatcher_hpp)
#define Asc_StackMsgDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/UserDispatcher.hpp>

class AbstractStackMsgArgMapContainer;
class ExecutionContext;
class Message;

/*  ========================================================================
    StackMsgDispatcher
    ======================================================================== */
class StackMsgDispatcher : public UserDispatcher {
    friend class BaseHandler;
    typedef UserDispatcher Base;
    public:
        StackMsgDispatcher(const AbstractStackMsgArgMapContainer *arg_map_container = 0);

        virtual ~StackMsgDispatcher();
        
    protected:
        void Init(const AbstractStackMsgArgMapContainer *arg_map_container) { m_arg_map_container_ptr = arg_map_container; }

        BOOLEAN Activate(ExecutionContext *context = 0);
        BOOLEAN Deactivate(ExecutionContext *context = 0);

        virtual BOOLEAN OnMessage(const Message &msg);

    private:
        const AbstractStackMsgArgMapContainer *m_arg_map_container_ptr;

};

#endif // Asc_StackMsgDispatcher_hpp


