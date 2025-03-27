/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpRequest_hpp)
#define BtAvrcpRequest_hpp

#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtAvrcpOperationController;
class BtAvrcpService;

class BtAvrcpRequest : public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtAvrcpRequest(BtAvrcpService& avrcp_service);

        virtual ~BtAvrcpRequest();

#ifdef _XXX_

        void SetRequestResponse(btapi_avrcp_response_t response) { m_request_response = (BtAvrcpResponseType)response; };

        const BtAvrcpResponseType GetRequestResponse() const { return m_request_response; };
#endif

    protected:

        virtual BtRequestState ChangeRequestState(BOOLEAN success);

    private:
        BtAvrcpResponseType m_request_response;

    private:
        friend class BtAvrcpOperationController;
        friend class BtAvrcpService;
};

#endif  // BtAvrcpRequest_hpp

