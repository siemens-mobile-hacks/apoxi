/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_UsbObexTransport_hpp)
#define Apoxi_UsbObexTransport_hpp

#include <Obex/ObexTransport.hpp>
#include <AddOns/StreamObex/StreamObexTransport.hpp>
#include <AddOns/StreamObex/StreamObexImpl.hpp>
#include "UsbObexServerAddress.hpp"

class UsbTransport;

class UsbObexTransport : public StreamObexTransport {

    typedef StreamObexTransport Base;   

    public:         

        virtual ~UsbObexTransport();

        void Init(UsbTransport& usb_transport);
        
        virtual ObexProtocol* GetProtocol(ObexProtocolId level);

        virtual void ResolveServerAddr(const String &   server_url,
                                          ObexProtocolId    prot_id,
                                          BOOLEAN           sdb_autocreate,
                                          ObexOperationId   job_id) ;
        virtual void ResolveClientAddr(const String &   client_url,
                                          ObexProtocolId    prot_id,
                                          ObexOperationId   job_id);


        UsbObexTransport();
                
    protected:
        virtual void OnUpdate(ObservableObject *obs_obj);
                
    private:
        

    private:
            
        ObexAddrPtr m_server_addr;

        //StreamObexImpl m_obex_impl;
    
};

#endif // Apoxi_UsbObexTransport_hpp

