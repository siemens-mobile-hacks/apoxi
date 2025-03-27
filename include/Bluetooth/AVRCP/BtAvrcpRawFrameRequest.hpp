/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpRawFrameRequest_hpp)
#define BtAvrcpRawFrameRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRawFrameParams.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpOperationService;
class BtAvrcpOperationController;


class BtAvrcpRawFrameRequest : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpRawFrameRequest(BtAvrcpOperationService &avrcp_service);

        virtual ~BtAvrcpRawFrameRequest();


        void SetRawFrameParams(BtAvrcpRawFrameParams raw_frame_params) { m_raw_frame_params = raw_frame_params; };

        BtAvrcpRawFrameParams GetRawFrameParams() const { return m_raw_frame_params; };

        void SetResponse(btapi_avrcp_response_code_t response) { m_response = (BtAvrcpResponseType)response; };

        BtAvrcpResponseType GetResponse() { return m_response; };

        BOOLEAN ReleaseParams();

        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


    private:

        btapi_avrcp_raw_frame_t*    GetApiSettings();
        btapi_avrcp_raw_frame_t     m_api_settings;
        BtAvrcpRawFrameParams       m_raw_frame_params; 
        BtAvrcpResponseType         m_response;
    
    private:
        friend class BtAvrcpOperationService;
        friend class BtAvrcpOperationController;

};

#endif  // BtAvrcpRawFrameRequest_hpp

