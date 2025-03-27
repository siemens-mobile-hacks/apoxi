/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpConnectRequest_hpp)
#define BtAvrcpConnectRequest_hpp
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

class BtAvrcpService;
class BtAvrcpOperationController;

class BtAvrcpConnectRequest : public BtConnectRequest
{
    private:
        typedef BtConnectRequest Base;

    public:
        BtAvrcpConnectRequest(BtAvrcpService& avrcp_service);

        virtual ~BtAvrcpConnectRequest();

        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN PerformConnectControllerCall();

    private:
        friend class BtAvrcpOperationController;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtAvrcpConnectRequest_hpp


