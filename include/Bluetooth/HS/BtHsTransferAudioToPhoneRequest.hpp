/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsTransferAudioToPhoneRequest_hpp)
#define BtHsTransferAudioToPhoneRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/HS/BtHsRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtHsController;
class BtHsService;

class BtHsTransferAudioToPhoneRequest: public BtHsRequest
{
    private:
        typedef BtHsRequest Base;

    public:
        BtHsTransferAudioToPhoneRequest(BtHsService& hs_service);

        virtual ~BtHsTransferAudioToPhoneRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();

    private:

        btapi_bool_t GetApiSettings() const;


        BOOLEAN GetIsSynchronizationRequest() const;


        void SetIsSynchronizationRequest(BOOLEAN is_synchronization_request);

    private:

        BOOLEAN m_is_synchronization_request;

    private:
        friend class BtHsController;
        friend class BtHsService;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHsTransferAudioToPhoneRequest_hpp

