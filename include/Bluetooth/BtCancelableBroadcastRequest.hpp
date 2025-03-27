/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtCancelableBroadcastRequest_hpp)
#define BtCancelableBroadcastRequest_hpp

#include <Bluetooth/BtCancelableRequest.hpp>

class BtCancelableBroadcastRequest: public BtCancelableRequest
{
    private:
        typedef BtCancelableRequest Base;

    public:
        BtCancelableBroadcastRequest();

        virtual ~BtCancelableBroadcastRequest();
};

#endif  // BtCancelableBroadcastRequest_hpp


