/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfControllerMessage_hpp)
#define BtHfControllerMessage_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>

class BtHfControllerMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtHfControllerMessage(const BtDevice& device = bt_c_unknown_device, StackMsgArgument *argument = 0);

        BtHfControllerMessage(const BtHfControllerMessage &message);

        virtual ~BtHfControllerMessage();


        const BtDevice& GetDevice() const;


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtHfControllerMessage& operator=(const BtHfControllerMessage &message);


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10405 };

    private:
        BtDevice m_device;

    private:
        static const MsgMetaData m_meta_data;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif // BtHfControllerMessage_hpp


