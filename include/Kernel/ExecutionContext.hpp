/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ExecutionContext_hpp)
#define Apoxi_ExecutionContext_hpp

#include <Kernel/MsgCategory.hpp>

class UserDispatcher;
class Condition;
class MessageReferrer;
class Timer;
class Guid;

class ExecutionContext {
    public:
        enum Type {
            APPLICATION,
            SERVICE_THREAD
        };
        
        ExecutionContext();
        virtual ~ExecutionContext();

        virtual Type GetType() const = 0;

        virtual const Guid& GetGuid() const;

        void AddDispatcher(UserDispatcher* disp);

        void RemoveDispatcher(UserDispatcher* disp);

        BOOLEAN ContainsDispatcher(const UserDispatcher* disp) const;

        virtual void RegisterMessage(MsgId msg_id) = 0;

        virtual void UnregisterMessage(MsgId msg_id) = 0;

        static ExecutionContext& GetCurrentContext();

        static BOOLEAN IsInContext(const ExecutionContext* context = 0);

        static void Wait(const Condition& cond) { GetCurrentContext().DoWait(cond); }

    protected:
        virtual BOOLEAN AcceptMsg(const Message& msg) = 0;

        virtual BOOLEAN HandleMsg(const MessageReferrer& msg_ref) = 0;

        virtual void AddTimer(Timer& timer) = 0;

        virtual void RemoveTimer(Timer& timer) = 0;

        BOOLEAN HandleDispatcherList(const Message& msg);
        
    private:
        friend class MessageRouter;
        friend class Timer;
        
        UserDispatcher* m_first_disp;

        virtual void DoWait(const Condition& cond) = 0;
};

#endif  // Apoxi_ExecutionContext_hpp


