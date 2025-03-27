/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtService_hpp)
#define BtService_hpp

#include <Kernel/UserDispatcher.hpp>
#include <Bluetooth/BtDevice.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtServiceRequest;

class BtService: public UserDispatcher
{
    private:
        typedef UserDispatcher Base;

    public:
        BtService();

        BtService(const BtDevice& target_device);

        virtual ~BtService();


        virtual BtProfile GetProfile() const = 0;
 

        const BtDevice& GetTargetDevice() const;


        BtDevice& GetTargetDevice();


        virtual void SetTargetDevice(const BtDevice& target_device);


        virtual BtRequestState GetRequestState(BtRequestType request_type) const = 0;

    protected:

        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state) = 0;


        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state) = 0;

    private:
        BtDevice m_target_device;

    private:
        friend class BtServiceRequest;
}; //BtService

#endif  // BtService_hpp


