/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipConnectReq_hpp)
#define BtBipConnectReq_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipConnectReq: public BtBipReq
{
    private:
        typedef BtBipReq Base;

    public:
        BtBipConnectReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipConnectReq();


        virtual BtRequestType GetRequestType() const;


        BtDevice GetTargetDevice() const;


        void SetTargetDevice(const BtDevice& target_device);

        BtBipSessionId GetSessionId();

        void SetSessionId(const BtBipSessionId session_id);


    protected:

        virtual BOOLEAN Execute();


//      virtual void ExecutionCallback(BtResultCode result);

        btapi_bip_connect_t* GetApiSettings();

    private:

        btapi_bip_connect_t m_operation_params;
    
        friend class BtBipController;
};
#endif

#endif  // BtBipConnectReq_hpp

