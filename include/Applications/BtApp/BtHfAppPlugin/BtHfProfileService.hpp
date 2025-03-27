/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfProfileService_hpp)
#define BtHfProfileService_hpp

#include <Bluetooth/HF/BtHfService.hpp>

/*  ------------------------------------------------------------------------
    forward declartions
    ------------------------------------------------------------------------ */

class BtHfProfileWindow;

class BtHfProfileService : public BtHfService
{
    private:
        typedef BtHfService Base;

    public:
        BtHfProfileService(BtHfProfileWindow& hf_profile_window);

        virtual ~BtHfProfileService();

    protected:

        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);


        virtual void OnPhoneNumberRequired(BtResultCode result);

    private:
        BtHfProfileWindow& m_hf_profile_window;
};

#endif /* BtHfProfileService_hpp */
