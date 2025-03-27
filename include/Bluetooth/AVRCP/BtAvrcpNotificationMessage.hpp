/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpNotificationMessage_hpp)
#define BtAvrcpNotificationMessage_hpp

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/AVRCP/BtAvrcpOperationService.hpp>

class BtAvrcpNotificationMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtAvrcpNotificationMessage(StackMsgArgument *argument = 0);
        
        BtAvrcpNotificationMessage(BtAvrcpOperationService* service, StackMsgArgument *argument = 0);

        BtAvrcpNotificationMessage(const BtAvrcpNotificationMessage &message);

        virtual ~BtAvrcpNotificationMessage();



        BtAvrcpOperationService* GetService() const;


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtAvrcpNotificationMessage& operator=(const BtAvrcpNotificationMessage& message);


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10450 };

    private:
        BtAvrcpOperationService* m_service;

    private:
        static const MsgMetaData m_meta_data;
};

#endif // BtAvrcpNotificationMessage_hpp

