/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpRegistrationService_hpp)
#define BtAvrcpRegistrationService_hpp

#include <Bluetooth/AVRCP/BtAvrcpService.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRegisterParams.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRegisterRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpDeRegisterRequest.hpp>

class BtAvrcpRegistrationService : public BtAvrcpService
{
    private:
        typedef BtAvrcpService Base;

    public:
        BtAvrcpRegistrationService();

        virtual ~BtAvrcpRegistrationService();

        virtual BtRequestState GetRequestState(BtRequestType request_type) const;

        void RegisterRequest(BtAvrcpRegisterParams unit_info);

        void DeRegisterRequest(BtAvrcpRole role);


    protected:
        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtAvrcpRegisterRequest      m_register_request;
        BtAvrcpDeRegisterRequest    m_deregister_request;
};

#endif  // BtAvrcpRegistrationService_hpp

