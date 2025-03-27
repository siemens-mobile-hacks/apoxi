/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsStopRingRequest_hpp)
#define BtHsStopRingRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/HS/BtHsRequest.hpp>

class BtHsStopRingRequest: public BtHsRequest
{
    private:
        typedef BtHsRequest Base;

    public:
        BtHsStopRingRequest(BtHsService& hs_service);

        virtual ~BtHsStopRingRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN GetKeepAudio() const;


        void SetKeepAudio(BOOLEAN keep_audio);

    protected:

        virtual BOOLEAN Execute();

    private:

        btapi_bool_t GetApiSettings() const;

    private:
        btapi_bool_t m_keep_audio;

    private:
        friend class BtHsController;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHsStopRingRequest_hpp

