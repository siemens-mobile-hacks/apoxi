/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsControllerMessage_hpp)
#define BtHsControllerMessage_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Apc/Message.hpp>
#include <Apc/StackMsgArgument.hpp>

class BtHsControllerMessage: public FromStackMsg
{
    private:
        typedef FromStackMsg Base;

    public:
        BtHsControllerMessage(const BtDevice& device = bt_c_unknown_device, StackMsgArgument *argument = 0);

        BtHsControllerMessage(const BtHsControllerMessage &message);

        virtual ~BtHsControllerMessage();


        const BtDevice& GetDevice() const;


        virtual FromStackMsg& operator=(const FromStackMsg &message);


        virtual BtHsControllerMessage& operator=(const BtHsControllerMessage &message);


        virtual const MsgMetaData& GetMetaData() const;


        virtual Message* Clone() const;

    public:
        enum { ID = 10404 };

    private:
        BtDevice m_device;

    private:
        static const MsgMetaData m_meta_data;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif // BtHsControllerMessage_hpp


