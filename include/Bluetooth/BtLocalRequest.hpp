/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtLocalRequest_hpp)
#define BtLocalRequest_hpp

#include <Kernel/UserDispatcher.hpp>
#include <Bluetooth/BtRequest.hpp>
#include <Bluetooth/BtRequestMessage.hpp>

class BtLocalRequest: public BtRequest, public UserDispatcher
{
    private:
        typedef BtRequest Base;

    public:
        BtLocalRequest();

        virtual ~BtLocalRequest();


        virtual BtRequestState ExecuteRequest();

    protected:

        virtual void SetRequestState(BtRequestState request_state);


        virtual void ExecutionCallback(BtResultCode result);


        BOOLEAN RegisterDispatcher();


        BOOLEAN UnregisterDispatcher();


//      BOOLEAN CheckMessage(const Message& message, MsgId id) const;


        virtual BOOLEAN EvaluateMessageResult(const BtRequestMessage& message);


        virtual BOOLEAN OnMessage(const Message& messsage) = 0;


        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state) = 0;

    private:
        BOOLEAN m_is_registered;
};

#endif  // BtLocalRequest_hpp


