/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpRegisterRequest_hpp)
#define BtAvrcpRegisterRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRegisterParams.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpRegistrationService;
class BtAvrcpRegistrationController;


class BtAvrcpRegisterRequest : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpRegisterRequest(BtAvrcpRegistrationService& avrcp_service);

        virtual ~BtAvrcpRegisterRequest();

        void SetRegisterParams(BtAvrcpRegisterParams register_params) { m_register_params = register_params; };

        BtAvrcpRegisterParams GetRegisterParams() const { return m_register_params; };
        
        BOOLEAN ReleaseParams();

        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


    private:
        btapi_avrcp_service_unit_info_t*    GetApiSettings();
        btapi_avrcp_service_unit_info_t     m_api_settings;
        BtAvrcpRegisterParams               m_register_params;
        
    private:
        friend class BtAvrcpRegistrationService;
        friend class BtAvrcpRegistrationController;

};

#endif  // BtAvrcpRegisterRequest_hpp

