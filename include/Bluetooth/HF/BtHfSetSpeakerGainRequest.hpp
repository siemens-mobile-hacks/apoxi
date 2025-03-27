/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfSetSpeakerGainRequest_hpp)
#define BtHfSetSpeakerGainRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/HF/BtHfRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtHfController;
class BtHfService;

class BtHfSetSpeakerGainRequest: public BtHfRequest
{
    private:
        typedef BtHfRequest Base;

    public:
        BtHfSetSpeakerGainRequest(BtHfService& hf_service);

        virtual ~BtHfSetSpeakerGainRequest();


        virtual BtRequestType GetRequestType() const;


        UINT8 GetSpeakerGain() const;


        void SetSpeakerGain(UINT8 speaker_gain);

    protected:

        virtual BOOLEAN Execute();

    private:

        btapi_u8_t GetApiSettings() const;

    private:
        btapi_u8_t m_speaker_gain;

    private:
        friend class BtHfController;
        friend class BtHfService;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHfSetSpeakerGainRequest_hpp


