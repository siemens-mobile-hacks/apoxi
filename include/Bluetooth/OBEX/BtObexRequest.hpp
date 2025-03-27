/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexRequest_hpp)
#define BtObexRequest_hpp

#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/OBEX/BtObexService.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexController;

class BtObexRequest: public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtObexRequest(BtObexService& obex_service);

        virtual ~BtObexRequest();

    protected:

        virtual BtRequestState ChangeRequestState(BOOLEAN success);


        virtual BOOLEAN EvaluateExecutionResult(BtResultCode result);

    private:
        friend class BtObexController;
};

#endif  // BtObexRequest_hpp

