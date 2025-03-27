/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpOperationServiceMessage_hpp)
#define BtAvrcpOperationServiceMessage_hpp

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/AVRCP/BtAvrcpOperationService.hpp>

class BtAvrcpOperationServiceMessage : public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtAvrcpOperationServiceMessage(StackMsgArgument *argument = 0);
        
        BtAvrcpOperationServiceMessage(BtAvrcpOperationService* service, StackMsgArgument *argument = 0);

        BtAvrcpOperationServiceMessage(const BtAvrcpOperationServiceMessage &message);

        virtual ~BtAvrcpOperationServiceMessage();



        BtAvrcpOperationService* GetService() const;


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtAvrcpOperationServiceMessage& operator=(const BtAvrcpOperationServiceMessage& message);


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10451 };

    private:
        BtAvrcpOperationService* m_service;

    private:
        static const MsgMetaData m_meta_data;
};

#endif // BtAvrcpOperationServiceMessage_hpp

