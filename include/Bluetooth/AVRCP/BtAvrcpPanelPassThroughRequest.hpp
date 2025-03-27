/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpPanelPassThroughRequest_hpp)
#define BtAvrcpPanelPassThroughRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpPanelPassThroughParams.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpOperationService;
class BtAvrcpOperationController;


class BtAvrcpPanelPassThroughRequest : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpPanelPassThroughRequest(BtAvrcpOperationService& avrcp_service);

        virtual ~BtAvrcpPanelPassThroughRequest();

        void SetPanelPassThroughParams(BtAvrcpPanelPassThroughParams ppt_params) { m_ppt_params = ppt_params; };

        BtAvrcpPanelPassThroughParams GetPanelPassThroughParams() const { return m_ppt_params; };

        void SetResponse(btapi_avrcp_response_code_t response) { m_response = (BtAvrcpResponseType)response; };

        BtAvrcpResponseType GetResponse() { return m_response; };

        BOOLEAN ReleaseParams();

        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


    private:

        btapi_avrcp_panel_passthrough_t*    GetApiSettings();
        btapi_avrcp_panel_passthrough_t     m_api_settings;
        BtAvrcpPanelPassThroughParams       m_ppt_params; 
        BtAvrcpResponseType                 m_response;
    private:
        friend class BtAvrcpOperationService;
        friend class BtAvrcpOperationController;

};

#endif  // BtAvrcpPanelPassThroughRequest_hpp

