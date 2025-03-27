/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbUnregisterServiceRecordRequest_hpp)
#define BtSddbUnregisterServiceRecordRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtSddbRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtSddbService;
class BtGapAndSdapController;

class BtSddbUnregisterServiceRecordRequest: public BtSddbRequest
{
    private:
        typedef BtSddbRequest Base;

    public:
        BtSddbUnregisterServiceRecordRequest(BtSddbService& sddb_service);

        virtual ~BtSddbUnregisterServiceRecordRequest();


        virtual BtRequestType GetRequestType() const;


        UINT32 GetServiceRecordHandle();


        void SetServiceRecordHandle(UINT32 service_record_handle);

    protected:

        virtual BOOLEAN Execute();


        virtual void ExecutionCallback(BtResultCode result);

    private:

        btapi_u32_t GetApiSettings() const;

    private:
        btapi_u32_t m_service_record_handle;

    private:
        friend class BtGapAndSdapController;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtSddbUnregisterServiceRecordRequest_hpp


