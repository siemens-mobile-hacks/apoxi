/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDunProfileService_hpp)
#define BtDunProfileService_hpp

#include <Bluetooth/DUN/BtDunService.hpp>

class BtDunProfileService : public BtDunService{
    private:

    typedef BtDunService Base;

    public:
        BtDunProfileService();

        virtual ~BtDunProfileService();

    protected:

        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);
};

#endif /* BtDunProfileService_hpp */
