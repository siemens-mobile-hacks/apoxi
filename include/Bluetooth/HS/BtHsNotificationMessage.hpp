/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsNotificationMessage_hpp)
#define BtHsNotificationMessage_hpp

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>

class BtHsNotificationMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtHsNotificationMessage(StackMsgArgument *argument = 0);

        BtHsNotificationMessage(const BtHsNotificationMessage &message);

        virtual ~BtHsNotificationMessage();


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtHsNotificationMessage& operator=(const BtHsNotificationMessage &message);


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10104 };

    private:
        BtDevice m_device;

    private:
        static const MsgMetaData m_meta_data;
};

#endif // BtHsNotificationMessage_hpp


