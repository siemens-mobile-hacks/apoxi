/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexServerNotificationMessage_hpp)
#define BtObexServerNotificationMessage_hpp

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/OBEX/BtObexServerService.hpp>
#include <Bluetooth/OBEX/BtObexClientService.hpp>

class BtObexServerNotificationMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtObexServerNotificationMessage(BtObexServerService* service, StackMsgArgument *argument = 0);

        BtObexServerNotificationMessage(const BtObexServerNotificationMessage &message);

        virtual ~BtObexServerNotificationMessage();


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtObexServerNotificationMessage& operator=(const BtObexServerNotificationMessage &message);


        BtObexServerService* GetService() const;


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10106 };

    private:
        BtObexServerService* m_service;

    private:
        static const MsgMetaData m_meta_data;
};

class BtObexClientNotificationMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtObexClientNotificationMessage(BtObexClientService* service, StackMsgArgument *argument = 0);

        BtObexClientNotificationMessage(const BtObexClientNotificationMessage&message);

        virtual ~BtObexClientNotificationMessage();


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtObexClientNotificationMessage& operator=(const BtObexClientNotificationMessage &message);


        BtObexClientService* GetService() const;


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10107 };

    private:
        BtObexClientService* m_service;

    private:
        static const MsgMetaData m_meta_data;
};

#endif // BtObexServerNotificationMessage_hpp


