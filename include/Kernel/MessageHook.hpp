/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageHook_hpp)
#define Apoxi_MessageHook_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Condition.hpp>
#include <Kernel/MsgCategory.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Kernel/Os/Semaphore.hpp>

class ExecutionContext;
class HookedMessageReferrer;
class MessageHookReferrer;
class MessageReferrer;

class MessageHook {
    friend class MessageRouter;
    
    public:
        enum Mode {
            Asynchronous,   
            Synchronous,
        };

        MessageHook();
        virtual ~MessageHook();

        virtual BOOLEAN Attach(MsgId message_id, Mode mode = Asynchronous);

        virtual void Detach();

        MsgId GetMessageId() const { return (m_message_id); }

        ExecutionContext* GetExecutionContext() const { return (m_execution_context); }

        BOOLEAN IsAttached() const { return (m_is_attached); }

        BOOLEAN IsAsynchronous() const { return (m_mode == Asynchronous); }

    protected:
        virtual BOOLEAN OnMessage(Message &message) = 0;

    private:
        BOOLEAN m_marked_for_detach;
        BOOLEAN m_is_attached;
        MsgId m_message_id;
        Mode m_mode;
        INT m_refcount;
        ExecutionContext *m_execution_context;

        class Protector {
            public:
                void Lock() { 
                    static BOOLEAN initialized = FALSE;
                    if (!initialized) {
                        initialized = TRUE;
                        m_mutex.Create(FALSE);
                    } // if
                    m_mutex.Obtain(); 
                }

                void Unlock() { m_mutex.Release(); }

            private:
                Mutex m_mutex;
        };

        friend class MessageHookReferrer;
        // interface for MessageHookReferrer, to manipulate reference counter (method must be secured by caller)
        void AddRef(INT n = 1);
        // returns the flag, which signals, that this instance of message hook is marked for deletion from the global message hook list
        BOOLEAN IsMarkedForDetach() const { return (m_marked_for_detach); }
        // return TRUE, if there is more than one reference (one at least for the global message hook list) to this message hook
        BOOLEAN IsReferenced(INT ref_reference = 0) const { return (m_refcount > ref_reference); }
        // removes this instance from the global message hook list (method must be secured by caller)
        void RemoveFromGlobalList();


        // protector for secure list access
        static Protector m_protector;

        friend class MessageHookNotificationMsg;
        // suspends the distribution of the message until the hooking instances have finished their work (MessageHook::OnMessage)
        static BOOLEAN Suspend(const MessageReferrer &msg_ref); 
        /*  calls the message's hooks OnMessage, and returns TRUE, if the hooked message should be released and 
            dispatched to the official registered recipients. */
        static BOOLEAN Notify(HookedMessageReferrer *hooked_message_referrer, const MessageHookReferrer &message_hook_referrer);
        // resumes the message hook for the given referrer
        static void Resume(HookedMessageReferrer *hooked_message_referrer, const MessageHookReferrer &message_hook_referrer, BOOLEAN discard_message = FALSE); 
};

#endif // Apoxi_MessageHook_hpp


