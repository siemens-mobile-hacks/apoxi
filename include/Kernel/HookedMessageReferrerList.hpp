/*  ------------------------------------------------------------------------
Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(Apoxi_HookedMessageReferrerList_hpp)
#define Apoxi_HookedMessageReferrerList_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Kernel/MessageReferrer.hpp>
#include <Kernel/MessageHookList.hpp>

class MessageHook;
class HookedMessageReferrerListIterator;

class HookedMessageReferrer : public Linkable<HookedMessageReferrer>
{
    friend class HookedMessageReferrerList;
    public:
        HookedMessageReferrer(MessageReferrer message_referrer);
        virtual ~HookedMessageReferrer();

        const MessageReferrer& GetMessageReferrer() const { return (m_message_referrer); }

        BOOLEAN IsHooked() { return (!m_message_hook_reference_list.IsEmpty()); }

        BOOLEAN AddReference(MessageHook *message_hook);
        void RemoveReference(MessageHook *message_hook);

        void SetDiscardMessage(BOOLEAN discard_message) { m_discard_message = m_discard_message || discard_message; }
        BOOLEAN GetDiscardMessage() const { return (m_discard_message); }

    private:
        MessageReferrer m_message_referrer;
        BOOLEAN m_discard_message;
        LinkedList<MessageHookReferrer> m_message_hook_reference_list; 
};

class HookedMessageReferrerList 
{
    public:
        static HookedMessageReferrer* Append(const MessageReferrer &message_referrer, const MessageHookReferrer &message_hook_referrer);
        static BOOLEAN Remove(HookedMessageReferrer *&hooked_message_referrer, const MessageHookReferrer &message_hook_referrer, BOOLEAN discard_message);
        static HookedMessageReferrerListIterator* CreateIterator();

    private:
        friend class HookedMessageReferrerListIterator;
        static LinkedList<HookedMessageReferrer> m_hooked_message_referrer_list;
};

class HookedMessageReferrerListIterator
{
    public:
        HookedMessageReferrerListIterator() : entry(0) {}
        
        void First() { entry = HookedMessageReferrerList::m_hooked_message_referrer_list.GetFront(); }
        
        void Next() { entry = entry->GetNext(); }
        
        BOOLEAN IsDone() { return (entry == 0); }
        
        HookedMessageReferrer* GetCurrentItem() { return (entry); }

    private:
        HookedMessageReferrer *entry;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_HookedMessageReferrerList_hpp

