/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpSubunitInfoRequest_hpp)
#define BtAvrcpSubunitInfoRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpSubunitInfoParams.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpOperationService;
class BtAvrcpOperationController;


class BtAvrcpSubunitInfoRequest : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpSubunitInfoRequest(BtAvrcpOperationService& avrcp_service);

        virtual ~BtAvrcpSubunitInfoRequest();


        virtual BtRequestType GetRequestType() const;

        //BtAvrcpSubunitInfoParams
        BtAvrcpSubunitInfoParams GetSubunitInfoParams() { return m_subunit_info_params; };

        void SetSubunitInfoParams(BtAvrcpSubunitInfoParams subunit_info_params) { m_subunit_info_params = subunit_info_params; };

        BtAvrcpResponseType GetResponse() { return m_response; };

        void SetResponse(btapi_avrcp_response_code_t response) { m_response = (BtAvrcpResponseType)response; };


    protected:

        virtual BOOLEAN Execute();


    private:
        btapi_u8_t GetApiSettings() { return (btapi_u8_t)m_subunit_info_params.GetPage(); };
        void SetPage(UINT8 page)    { m_subunit_info_params.SetPage(page); };

    private:
        BtAvrcpSubunitInfoParams    m_subunit_info_params;
        BtAvrcpResponseType         m_response; 

    private:
        friend class BtAvrcpOperationService;
        friend class BtAvrcpOperationController;

};

#endif  // BtAvrcpSubunitInfoRequest_hpp

