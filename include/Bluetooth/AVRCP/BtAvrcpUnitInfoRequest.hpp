/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpUnitInfoRequest_hpp)
#define BtAvrcpUnitInfoRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpUnitInfoParams.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpOperationService;
class BtAvrcpOperationController;


class BtAvrcpUnitInfoRequest : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpUnitInfoRequest(BtAvrcpOperationService& avrcp_service);

        virtual ~BtAvrcpUnitInfoRequest();


        virtual BtRequestType GetRequestType() const;

        BtAvrcpUnitInfoParams GetUnitInfoParams();

        void SetUnitInfoParams(BtAvrcpUnitInfoParams unit_info_params) { m_unit_info_params = unit_info_params; };

        BtAvrcpResponseType GetResponse() { return m_response; };

        void SetResponse(btapi_avrcp_response_code_t response) { m_response = (BtAvrcpResponseType)response; };

    protected:

        virtual BOOLEAN Execute();


    private:

        BtAvrcpUnitInfoParams       m_unit_info_params;
        BtAvrcpResponseType         m_response;

    private:
        friend class BtAvrcpOperationService;
        friend class BtAvrcpOperationController;

};

#endif  // BtAvrcpUnitInfoRequest_hpp

