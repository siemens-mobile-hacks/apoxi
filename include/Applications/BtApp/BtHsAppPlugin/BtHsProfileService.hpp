/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsProfileService_hpp)
#define BtHsProfileService_hpp

#include <Bluetooth/HS/BtHsService.hpp>

class BtHsProfileService : public BtHsService{
    private:

    typedef BtHsService Base;

    public:
        BtHsProfileService();

        virtual ~BtHsProfileService();

    protected:

        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);

        void OnConnect(BtRequestState old_request_state, BtRequestState new_request_state);


        void OnDisonnect(BtRequestState old_request_state, BtRequestState new_request_state);


        void OnCallTransferToPhone(BtRequestState old_request_state, BtRequestState new_request_state);


        void OnCallTransferToHeadset(BtRequestState old_request_state, BtRequestState new_request_state);

};

#endif /* BtHsProfileService_hpp */
