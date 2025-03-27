/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageRouter_hpp)
#define Apoxi_MessageRouter_hpp

#include <Auxiliary/SingleArgHook.hpp>

class Message;
class MessageReferrer;
class ExternalCommunicationHandler;
class AbstractExternalData;
class MsgQueue;

class MessageRouter {
    public:
        static void Init(ExternalCommunicationHandler* external_communicator = 0) {
            m_external_communicator = external_communicator;
        }

        static ExternalCommunicationHandler* GetExternalCommunicator() { return m_external_communicator; }

        static void Post(const Message& msg);

        static void Post(const AbstractExternalData& external_data);

        static void PostFocusTransferMsg(const Message& msg);

        typedef SingleArgHook<const Message&> PostMsgHook;
        typedef PostMsgHook::HookFn PostMsgHookFn;

        static BOOLEAN AddPostMsgHook(PostMsgHookFn fn);

        static BOOLEAN RemovePostMsgHook(PostMsgHookFn fn);

    private:
        friend class MessageHook;
        friend class StartUp;

        static BOOLEAN m_ready_to_post;
        static ExternalCommunicationHandler* m_external_communicator;
        static PostMsgHook m_post_msg_hook;
        
        static void PostMessage(const MessageReferrer &msg_ref);
        static void StartPostingMessages();
        static MsgQueue& GetMsgQueue();
};


#endif  // Apoxi_MessageRouter_hpp


