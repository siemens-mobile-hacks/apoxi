/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfDisonnectRequest_hpp)
#define BtHfDisonnectRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/BtDisconnectRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtHfService;

class BtHfDisconnectRequest: public BtDisconnectRequest
{
    private:
        typedef BtDisconnectRequest Base;

    public:
        BtHfDisconnectRequest(BtHfService& hf_service);

        virtual ~BtHfDisconnectRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN PerformDisconnectControllerCall();
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHfDisonnectRequest_hpp


