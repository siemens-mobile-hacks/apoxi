/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfConnectRequest_hpp)
#define BtHfConnectRequest_hpp
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

class BtHfService;

class BtHfConnectRequest: public BtConnectRequest
{
    private:
        typedef BtConnectRequest Base;

    public:
        BtHfConnectRequest(BtHfService& hf_service);

        virtual ~BtHfConnectRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN PerformConnectControllerCall();
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHfConnectRequest_hpp


