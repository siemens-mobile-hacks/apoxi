/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtRequestRespondRequest_hpp)
#define BtRequestRespondRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

class BtRequestRespondRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtRequestRespondRequest(const BtDevice& device);

        virtual ~BtRequestRespondRequest();

    protected:

        virtual BtRequestState ChangeRequestState(BOOLEAN success);


        virtual BOOLEAN EvaluateMessageResult(const BtRequestMessage& message);
};

#endif  // BtRequestRespondRequest_hpp


