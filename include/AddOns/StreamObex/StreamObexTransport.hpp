/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_StreamObexTransport_hpp)
#define Apoxi_StreamObexTransport_hpp

#include <Obex/ObexTransport.hpp>
#include "StreamObexImpl.hpp"

class UsbTransport;

class StreamObexTransport : public ObexAbstractTransport {

    typedef ObexAbstractTransport Base; 

    public:         

        virtual ~StreamObexTransport();

        //static StreamObexTransport* GetInstance();

        //static void ReleaseInstance();

        void            Init(AbstractTransport &    device_abs,
                             const CHAR *           scheme_url);

        
        //virtual ObexProtocol* GetProtocol(ObexProtocolId level);

        //virtual void ResolveServerAddr(const String &     server_url,
        //                                ObexProtocolId    prot_id,
        //                                BOOLEAN           sdb_autocreate,
        //                                ObexOperationId   job_id) ;
                            //virtual void ResolveClientAddr(const String & client_url,
                            //                                ObexProtocolId    prot_id,
                            //            ObexOperationId   job_id);


        inline StreamObexImpl& GetStreamObexImpl() { return m_obex_impl; }

    protected:
        
        StreamObexTransport();
                

    private:
            
        static StreamObexTransport* m_obex_transport;

        //ObexAddrPtr m_server_addr;

        StreamObexImpl m_obex_impl;
    
};

#endif // Apoxi_StreamObexTransport_hpp

