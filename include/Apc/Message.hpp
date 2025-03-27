/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef Apc_Message_hpp
#define Apc_Message_hpp

#include <Kernel/Message.hpp>
#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>


class StackMsgArgument;

/*  ======================================================================
    FromStackMsg
    ====================================================================== */
class FromStackMsg : public Message {
    public:
        FromStackMsg(StackMsgArgument *arg = 0);
        FromStackMsg(const FromStackMsg &msg);
        virtual ~FromStackMsg();

        enum { ID = 15000 };

        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;

        virtual FromStackMsg& operator =(const FromStackMsg &msg);

        StackMsgArgument* GetArg() const { return m_arg; }

    private:
        static MsgMetaData m_meta_data;
        StackMsgArgument *m_arg;
};

/*  ======================================================================
    ToStackMsg
    ====================================================================== */
class ToStackMsg : public Message {
    public:
        ToStackMsg(StackMsgArgument *arg = 0);
        ToStackMsg(const ToStackMsg &msg);
        virtual ~ToStackMsg();

        enum { ID = 15001 };

        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;

        virtual ToStackMsg& operator =(const ToStackMsg &msg);

        StackMsgArgument* GetArg() const { return m_arg; }

    private:
        static MsgMetaData m_meta_data;
        StackMsgArgument *m_arg;
};


#endif  // Apc_Message_hpp


