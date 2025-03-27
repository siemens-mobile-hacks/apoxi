/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbRegisterServiceRecordRequest_hpp)
#define BtSddbRegisterServiceRecordRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtSddbServiceRecord.hpp>
#include <Bluetooth/BtSddbRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtSddbService;
class BtGapAndSdapController;

class BtSddbRegisterServiceRecordRequest: public BtSddbRequest
{
    private:
        typedef BtSddbRequest Base;

    public:
        BtSddbRegisterServiceRecordRequest(BtSddbService& sddb_service);

        virtual ~BtSddbRegisterServiceRecordRequest();


        virtual BtRequestType GetRequestType() const;


        const BtSddbServiceRecord& GetServiceRecord() const;


        BtSddbServiceRecord& GetServiceRecord();


        void SetServiceRecord(const BtSddbServiceRecord& service_record);


        UINT32 GetServiceRecordHandle() const;


        void SetServiceRecordHandle(UINT32 service_record_handle);

    protected:

        virtual BOOLEAN Execute();


        void ServiceRecordHandleCallback(UINT32 service_record_handle);


        virtual void ExecutionCallback(BtResultCode result);

    private:
        BtSddbServiceRecord m_service_record;

        UINT32 m_service_record_handle;

    private:
        friend class BtGapAndSdapController;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtSddbRegisterServiceRecordRequest_hpp


