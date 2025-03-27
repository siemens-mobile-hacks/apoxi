/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtFaxProfileService_hpp)
#define BtFaxProfileService_hpp

#include <Bluetooth/FAX/BtFaxService.hpp>

class BtFaxProfileService : public BtFaxService{
    private:

    typedef BtFaxService Base;

    public:
        BtFaxProfileService();

        virtual ~BtFaxProfileService();

    protected:

        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);
};

#endif /* BtFaxProfileService_hpp */
