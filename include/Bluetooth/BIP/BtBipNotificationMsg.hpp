/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipServerNotificationMsg_hpp)
#define BtBipServerNotificationMsg_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Kernel/Message.hpp>
#include <Bluetooth/BIP/BtBipServerService.hpp>
#include <Bluetooth/BIP/BtBipNotificationMsgArg.hpp>

class BtBipServerNotificationMsg : public Message
{
    private:
        typedef Message Base;

    public:
        BtBipServerNotificationMsg(BtBipServerService* service, BtBipServerNotificationMsgArgPtr argument);

        BtBipServerNotificationMsg(const BtBipServerNotificationMsg &message);

        virtual ~BtBipServerNotificationMsg();


        virtual BtBipServerNotificationMsg& operator=(const BtBipServerNotificationMsg &message);

        BtBipServerService* GetService() const;

        BtBipServerNotificationMsgArgPtr    GetArgument() const;


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10501  };

    private:
        BtBipServerService*                 m_service;
        BtBipServerNotificationMsgArgPtr    m_arg;

    private:
        static const MsgMetaData m_meta_data;
};
#endif
#endif // BtBipServerNotificationMsg_hpp

