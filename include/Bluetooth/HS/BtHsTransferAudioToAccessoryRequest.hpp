/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsTransferAudioToAccessoryRequest_hpp)
#define BtHsTransferAudioToAccessoryRequest_hpp
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

class BtHsTransferAudioToAccessoryRequest: public BtHsRequest
{
    private:
        typedef BtHsRequest Base;

    public:
        BtHsTransferAudioToAccessoryRequest(BtHsService& hs_service);

        virtual ~BtHsTransferAudioToAccessoryRequest();


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
#endif  // BtHsTransferAudioToAccessoryRequest_hpp

