/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbRequest_hpp)
#define BtSddbRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/BtServiceRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtSddbService;

class BtSddbRequest: public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtSddbRequest(BtSddbService& sddb_service);

        virtual ~BtSddbRequest();
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtSddbRequest_hpp


