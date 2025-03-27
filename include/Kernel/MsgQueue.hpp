/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MsgQueue_hpp)
#define Apoxi_MsgQueue_hpp

#include <Auxiliary/FifoLinkedList.hpp>
#include <Kernel/Os/Os.hpp>
#include <Kernel/MessageReferrer.hpp>

class Timer;

class MsgQueue {
    public:
        MsgQueue();

        BOOLEAN Push(const MessageReferrer& msg_ref);

        BOOLEAN Wait(MessageReferrer& msg_ref, Ticks timeout = Ticks::Infinite());
        
        void TriggerIsrDataProcessing() { m_sem_wait.Release(); }

        static BOOLEAN PushFocusMsg(const MessageReferrer& msg_ref);

        static BOOLEAN PassBackFocusMsg(const MessageReferrer& msg_ref);

        static void SetFocusMsgProcessingBlocked(BOOLEAN block) { 
            DBG_OUT((122, "MsgQueue: blocking of MC_FOCUS messages %s\n", block ? "starts" : "stops"));
            m_block_focus_messages = block; 
        }

        static BOOLEAN IsFocusMsgProcessingBlocked() { return m_block_focus_messages; }
        
    private:
        friend class AppContainer;
        friend class ServiceThread;

        class QueueEntry : public Linkable<QueueEntry> {
            public:
                QueueEntry(const MessageReferrer& msg_ref) : m_msg_ref(msg_ref) {}
                const MessageReferrer& GetMessageReferrer() const { return m_msg_ref; }

            private:
                MessageReferrer m_msg_ref;
        };

        static BOOLEAN m_block_focus_messages;
        static INT m_key_dn_count;
        static INT m_key_up_count;
        static Semaphore* m_sem_focus_list;
        static LinkedList<QueueEntry>* m_focus_list;
    #ifdef APOXI_COMPAT_2_0_0
        INT m_yield_count;
    #endif
        INT m_focus_entry_count;
        Semaphore m_sem_wait;
        Semaphore m_sem_list;
        FifoLinkedList<QueueEntry> m_list;
        Ticks m_next_yield;

        MsgQueue(const MsgQueue& msg_queue);            // never implemented (non cloneable)
        MsgQueue& operator=(const MsgQueue& msg_queue); // never implemented (non cloneable)

        BOOLEAN DeleteTimerTimeoutMsg(const Timer& timer);

        static BOOLEAN PushFocusEntry(const MessageReferrer& msg_ref, BOOLEAN pass_back = FALSE);
        BOOLEAN PopFocusEntry(MessageReferrer& msg_ref);
        void Wakeup();
};

#endif  // Apoxi_MsgQueue_hpp


