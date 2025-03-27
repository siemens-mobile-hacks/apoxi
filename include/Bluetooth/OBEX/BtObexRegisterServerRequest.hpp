/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexRegisterServerRequest_hpp)
#define BtObexRegisterServerRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/OBEX/BtObexRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexServerService;
class BtObexController;

class BtObexRegisterServerRequest: public BtObexRequest
{
    private:
        typedef BtObexRequest Base;

    public:
        BtObexRegisterServerRequest(BtObexServerService& obex_server_service);

        virtual ~BtObexRegisterServerRequest();


        virtual BtRequestType GetRequestType() const;


        BtSecuritySettings GetSecuritySettings() const;


        void SetSecuritySettings(BtSecuritySettings security_settings);


        const UINT8* GetHeaderBuffer(void) const;


        UINT8* GetHeaderBuffer(void);


        UINT16 GetHeaderBufferSize(void) const;
        

        void SetHeaderBuffer(UINT8* header_buffer, UINT16 header_buffer_size);


        const void* GetApoxiHandle(void) const;


        void* GetApoxiHandle(void);


        void SetApoxiHandle(void* apoxi_handle);


        UINT8 GetRfComChannel() const;

    protected:

        virtual BOOLEAN Execute();


        void OnRfComChannel(UINT8 rfcom_channel);


        virtual void ExecutionCallback(BtResultCode result);

    private:

        btapi_goep_register_app_t* GetApiSettings();

    private:
        btapi_goep_register_app_t m_registration_settings;

        UINT8 m_rfcom_channel;

    private:
        friend class BtObexController;
};

#endif  // BtObexRegisterServerRequest_hpp


