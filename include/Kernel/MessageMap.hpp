/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageMap_hpp)
#define Apoxi_MessageMap_hpp

#include <Kernel/System.hpp>
#include <Kernel/MsgTypes.hpp>
#include <Kernel/Application.hpp>

template<class T> struct MessageMap {
    MsgId msg_id;
    BOOLEAN (T::*func)(const Message &msg);
};

class AbstractMessageMapContainer {
    public:
        virtual void Register() const = 0;
        virtual void Unregister() const = 0;
        virtual BOOLEAN Execute(const Message &msg) const = 0;
};

template<class T> class MessageMapContainer : public AbstractMessageMapContainer {
    public:
        MessageMapContainer(T *dispatcher = 0, const MessageMap<T> *msg_map = 0) :
            m_dispatcher(dispatcher), m_msg_map(msg_map) { }

        virtual void Init(T *dispatcher, const MessageMap<T> *msg_map) {
            m_dispatcher = dispatcher;
            m_msg_map = msg_map;
        }
        
        virtual void Register() const
        {
            ASSERT_ALWAYS(m_dispatcher != 0 && m_msg_map != 0);

            INT i = 0;
            Application* app = System::GetActiveApplication();

            while (m_msg_map[i].msg_id != NoMessage::ID) {
                ASSERT_DEBUG(m_msg_map[i].func != 0);
                app->RegisterMessage(m_msg_map[i].msg_id);
                i++;
            }
        }

        virtual void Unregister() const
        {
            ASSERT_ALWAYS(m_dispatcher != 0 && m_msg_map != 0);

            INT i = 0;
            Application* app = System::GetActiveApplication();

            while (m_msg_map[i].msg_id != NoMessage::ID) {
                ASSERT_DEBUG(m_msg_map[i].func != 0);
                app->UnregisterMessage(m_msg_map[i].msg_id);
                i++;
            }
        }
    
        virtual BOOLEAN Execute(const Message& msg) const
        {
            ASSERT_ALWAYS(m_dispatcher != 0 && m_msg_map != 0);

            INT i = 0;
            while (m_msg_map[i].msg_id != NoMessage::ID) {
                ASSERT_DEBUG(m_msg_map[i].func != 0);
                if (m_msg_map[i].msg_id == msg.Id())
                    return (m_dispatcher->*(m_msg_map[i].func))(msg);
                i++;
            }

            return FALSE;
        }

    private:
        T *m_dispatcher;
        const MessageMap<T>* m_msg_map;
};

#endif  // Apoxi_MessageMap_hpp


