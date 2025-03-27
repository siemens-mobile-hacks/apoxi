/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpOperationRequestResponse_hpp)
#define BtAvrcpOperationRequestResponse_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpOperationService;
class BtAvrcpOperationController;


class BtAvrcpOperationRequestResponse : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpOperationRequestResponse(BtAvrcpOperationService& avrcp_service);

        virtual ~BtAvrcpOperationRequestResponse();


        virtual BtRequestType GetRequestType() const;

        void SetRequestType(BtRequestType request_type);

        BtAvrcpResponseType GetResponse() { return m_response; };

        void SetResponseType(BtAvrcpResponseType response) { m_response = response; };

    protected:

        virtual BOOLEAN Execute();

    private:
        BtRequestType           m_request_type;
        BtAvrcpResponseType     m_response;

    private:
        friend class BtAvrcpOperationController;
        friend class BtAvrcpOperationService;
};

#endif  // BtAvrcpOperationRequestResponse_hpp

