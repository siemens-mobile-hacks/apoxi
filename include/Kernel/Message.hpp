/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\RootMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Kernel_Message_hpp)
#define Kernel_Message_hpp

#include <Kernel/DispatcherAction.hpp>
#include <Auxiliary/ObjectReferrer.hpp>
#include <Auxiliary/Macros.hpp>
#include <Kernel/Types.hpp>
#include <Kernel/MsgCategory.hpp>
#include <Kernel/MessageRouter.hpp>

class Application;
class Control;
class ExecutionContext;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class Message
    ====================================================================== */

class Message {
    public:
        Message();
        virtual ~Message();

        virtual const MsgMetaData& GetMetaData() const = 0;
        MsgId Id() const { return GetMetaData().msg_id; }
        MsgCategory Category() const { return GetMetaData().msg_class; }
        MsgOrigin Origin() const { return GetMetaData().msg_origin; }
        void Post() const { MessageRouter::Post(*this); }
        virtual Message* Clone() const = 0;

    private:
        friend class MessageReferrer;
        friend class MessageRouter;
        friend class AppContainer;

        Message(const Message &msg);                // forbid copy construction
        Message& operator=(const Message &msg);     // forbid assignment operation

        void AddRef(INT n = 1);

        UINT m_focus_transfer   :  1;
        INT m_refcount          : 15;

    };


/*  ======================================================================
    Class ContextMsg
    ====================================================================== */

class ContextMsg : public Message {
    public:
        ContextMsg(ExecutionContext* context);
        virtual ~ContextMsg();

        virtual const MsgMetaData& GetMetaData() const = 0;
        void SetContext(ExecutionContext* context) { m_context = context; }
        ExecutionContext* GetContext() const { return m_context; }

        // for backward compatibility only
        void SetApplication(Application* app);
        Application* GetApplication() const;

    private:
        ExecutionContext* m_context;

    };


/*  ======================================================================
    Class ControlMsg
    ====================================================================== */

class ControlMsg : public Message {
    public:
        ControlMsg(Control* control);
        virtual ~ControlMsg();

        virtual const MsgMetaData& GetMetaData() const = 0;
        void SetControl(Control* control) { m_control = control; }
        Control* GetControl() const { return m_control; }

    private:
        Control* m_control;

    };

typedef ContextMsg ApplicationMsg;

template<class DestClassPointer>
inline void CastMsg(DestClassPointer &dest_msg, const Message *src_msg)
{
    ASSERT_DEBUG(src_msg->Id() == DestClassPointer()->ID);
    dest_msg = static_cast<DestClassPointer>(const_cast<Message*>(src_msg));
}   // CastMsg

#endif  // Kernel_Message_hpp

