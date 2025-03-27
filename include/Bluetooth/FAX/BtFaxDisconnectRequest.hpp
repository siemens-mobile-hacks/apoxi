/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtFaxDisconnectRequest_hpp)
#define BtFaxDisconnectRequest_hpp
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

class BtFaxService;

class BtFaxDisconnectRequest: public BtDisconnectRequest
{
    private:
        typedef BtDisconnectRequest Base;

    public:

        BtFaxDisconnectRequest(BtFaxService& fax_service);

        virtual ~BtFaxDisconnectRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN PerformDisconnectControllerCall();
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtFaxDisconnectRequest_hpp


