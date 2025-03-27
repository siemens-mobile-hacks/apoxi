/*  ------------------------------------------------------------------------
Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageHookList_hpp)
#define Apoxi_MessageHookList_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>

class MessageHook;
class MessageHookListIterator;

class MessageHookReferrer : public Linkable<MessageHookReferrer>
{
    public:
        MessageHookReferrer(MessageHook *message_hook = 0);
        virtual ~MessageHookReferrer();
        MessageHookReferrer(const MessageHookReferrer &message_hook_referrer);
        MessageHookReferrer& operator =(const MessageHookReferrer &message_hook_referrer);
        
        BOOLEAN operator ==(const MessageHookReferrer &message_hook_list_entry) const;
        BOOLEAN operator !=(const MessageHookReferrer &message_hook_list_entry) const;
        
        MessageHook* GetMessageHook() const { return m_message_hook; }
        BOOLEAN IsEqual(MessageHook *message_hook) const;
        

    private:
        MessageHook *m_message_hook;
};

class MessageHookList 
{
    public:
        static BOOLEAN Append(MessageHook *message_hook);
        static BOOLEAN Remove(MessageHook *message_hook);

        static MessageHookListIterator* CreateIterator();

    private:
        friend class MessageHookListIterator;
        static LinkedList<MessageHookReferrer> m_message_hook_list;
};

class MessageHookListIterator
{
public:
    MessageHookListIterator() : entry(0) {}
    void First() { entry = MessageHookList::m_message_hook_list.GetFront(); }
    void Next() { entry = entry->GetNext(); }
    BOOLEAN IsDone() { return (entry == 0); }
    MessageHookReferrer* GetCurrentItem() { return (entry); }

private:
    MessageHookReferrer *entry;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_MessageHookList_hpp


