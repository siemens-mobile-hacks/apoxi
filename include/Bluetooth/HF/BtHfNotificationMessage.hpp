/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfNotificationMessage_hpp)
#define BtHfNotificationMessage_hpp

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>

class BtHfNotificationMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtHfNotificationMessage(StackMsgArgument *argument = 0);

        BtHfNotificationMessage(const BtHfNotificationMessage &message);

        virtual ~BtHfNotificationMessage();


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtHfNotificationMessage& operator=(const BtHfNotificationMessage &message);


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10105 };

    private:
        BtDevice m_device;

    private:
        static const MsgMetaData m_meta_data;
};

#endif // BtHfNotificationMessage_hpp


