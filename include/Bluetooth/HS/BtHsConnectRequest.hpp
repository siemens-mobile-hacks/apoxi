/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsConnectRequest_hpp)
#define BtHsConnectRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/BtConnectRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtHsService;

class BtHsConnectRequest: public BtConnectRequest
{
    private:
        typedef BtConnectRequest Base;

    public:
        BtHsConnectRequest(BtHsService& hs_service);

        virtual ~BtHsConnectRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN PerformConnectControllerCall();
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHsConnectRequest_hpp


