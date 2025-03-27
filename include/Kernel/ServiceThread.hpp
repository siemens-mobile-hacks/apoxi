/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ServiceThread_hpp)
#define Apoxi_ServiceThread_hpp


#include <Kernel/ApoxiThread.hpp>
#include <Kernel/ExecutionContext.hpp>
#include <Kernel/MsgQueue.hpp>
#include <Kernel/Timer.hpp>
#include <Auxiliary/Vector.hpp>

class ServiceThread : private ApoxiThread, public ExecutionContext {
    typedef ApoxiThread Base;

    public:
        ServiceThread();

        virtual ~ServiceThread();

        BOOLEAN Run(UINT32 stacksize = 4096, void *stack = 0);      

        void Stop(INT exit_code = 0);

        virtual ExecutionContext::Type GetType() const;

        virtual void RegisterMessage(MsgId msg_id);

        virtual void UnregisterMessage(MsgId msg_id);

        using Base::GetPriority;
        using Base::SetPriority;
        using Base::IncreasePriority;
        using Base::DecreasePriority;

        using Base::Terminate;

    protected:
        virtual BOOLEAN AcceptMsg(const Message& msg);

        virtual BOOLEAN HandleMsg(const MessageReferrer& msg_ref);

        virtual void AddTimer(Timer& timer);

        virtual void RemoveTimer(Timer& timer);

        virtual void OnPowerUp();

        virtual void OnPowerDown();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual BOOLEAN OnTimeout(const Timer& timer);

    private:
        friend class StartUp;

        BOOLEAN m_running;
        INT m_exit_code;
        MsgQueue m_msg_queue;
        Vector<MsgId> m_msg_registration;
        TimerList m_timer_list;

        virtual ExecutionContext& GetContext();
        virtual const ExecutionContext& GetContext() const;
        
        virtual void DoWait(const Condition& cond);

        virtual INT ThreadFn();

        void WaitForMessageOrTimer();       
        void RouteMessage(Message& msg);
};

#endif  // Apoxi_ServiceThread_hpp


