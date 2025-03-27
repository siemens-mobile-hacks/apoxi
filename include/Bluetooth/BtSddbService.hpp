/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbService_hpp)
#define BtSddbService_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtObservableService.hpp>
#include <Bluetooth/BtSddbServiceObserver.hpp>
#include <Bluetooth/BtSddbServiceRecord.hpp>
#include <Bluetooth/BtSddbRegisterServiceRecordRequest.hpp>
#include <Bluetooth/BtSddbUnregisterServiceRecordRequest.hpp>

class BtSddbService: public BtObservableService
{
    private:
        typedef BtObservableService Base;

    public:
        BtSddbService();

        virtual ~BtSddbService();


        virtual BtProfile GetProfile() const;


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        UINT32 GetServiceRecordHandle();


        BtRequestState RegisterServiceRecordRequest(const BtSddbServiceRecord& service_record, UINT32 service_record_handle = 0);


        BtRequestState UnregisterServiceRecordRequest(UINT32 service_record_handle);

    public:

        BOOLEAN Attach(BtSddbServiceObserver* service_observer);


        BOOLEAN Detach(BtSddbServiceObserver* service_observer);

    protected:

        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);


        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


        void RegisterServiceCallback(BtResultCode result, UINT32 service_record_handle);


        void UnregisterServiceCallback(BtResultCode result);

    private:
        BtSddbRegisterServiceRecordRequest m_register_request;

        BtSddbUnregisterServiceRecordRequest m_unregister_request;

    private:
        friend class BtSddbRegisterServiceRecordRequest;
        friend class BtSddbUnregisterServiceRecordRequest;
};

#endif  // BtSddbService_hpp


