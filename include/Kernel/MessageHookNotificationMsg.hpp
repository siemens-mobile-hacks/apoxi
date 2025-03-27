/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageHookNotificationMsg_hpp)
#define Apoxi_MessageHookNotificationMsg_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/MsgTypes.hpp>
#include <Kernel/MessageHookList.hpp>

class HookedMessageReferrer;

class MessageHookNotificationMsg : public ContextExecuteMsg {
    typedef ContextExecuteMsg Base;
    public:
        MessageHookNotificationMsg(HookedMessageReferrer *hooked_message_referrer, const MessageHookReferrer &message_hook_referrer);
        virtual ~MessageHookNotificationMsg();

        virtual void Execute();

        virtual Message* Clone() const;

    private:
        HookedMessageReferrer *m_hooked_message_referrer;
        MessageHookReferrer m_message_hook_referrer;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_MessageHookNotificationMsg_hpp


