/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsRingRequest_hpp)
#define BtHsRingRequest_hpp
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

class BtHsRingRequest: public BtHsRequest
{
    private:
        typedef BtHsRequest Base;

    public:
        BtHsRingRequest(BtHsService& hs_service);

        virtual ~BtHsRingRequest();


        virtual BtRequestType GetRequestType() const;


        UINT16 GetRingInterval() const;


        void SetRingInterval(UINT16 ring_interval);


        UINT8 GetNumberOfRingSignals() const;


        void SetNumberOfRingSignals(UINT8 number_of_ring_signals);

    protected:

        virtual BOOLEAN Execute();


        void Abort();


        BOOLEAN GetUseInbandRinging() const;


        void SetUseInbandRinging(BOOLEAN use_inband_ringing);


        BOOLEAN GetKeepAudio() const;


        void SetKeepAudio(BOOLEAN keep_audio);

    private:

        const btapi_ring_settings_t* GetApiSettings() const;

    private:
        btapi_ring_settings_t m_ring_settings;

    private:
        friend class BtHsController;
        friend class BtHsService;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHsRingRequest_hpp


