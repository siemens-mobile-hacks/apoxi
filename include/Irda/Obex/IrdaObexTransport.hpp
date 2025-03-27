/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_IrdaObexTransport_hpp)
#define Apoxi_IrdaObexTransport_hpp

#include <Kernel/SubSystem.hpp>

#include <Irda/Obex/IrdaObexImpl.hpp>

#include <Obex/ObexTransport.hpp>
#include <Devices/AbstractTransport.hpp>

#define C_IR_CONNECTIONS_MAX_NUM 1

#if defined(_DEBUG)
static const char * ir_status_stringtab[] ={
        "IR_STATUS_SUCCESS" ,
        "IR_STATUS_FAILED"  ,
        "IR_STATUS_PENDING",
        "IR_STATUS_DISCONNECT" ,
        "IR_STATUS_NO_IRLAP"  ,
        "IR_STATUS_IN_USE"     ,
        "IR_STATUS_MEDIA_BUSY"  ,
        "IR_STATUS_MEDIA_NOT_BUSY",
        "IR_STATUS_NO_PROGRESS"   ,
        "IR_STATUS_LINK_OK"       ,
        "IR_STATUS_SDU_OVERRUN"
};
#endif

class IrConnection
{
    public:
        ObexOperationId m_job_id_client;
        BOOLEAN ir_bind_was_succesful;
    protected:
    private:
};

class IrdaObexTransport : public ObexAbstractTransport {

    public:

        typedef ObexAbstractTransport Base;

        IrdaObexTransport();
        virtual ~IrdaObexTransport();

        static IrdaObexTransport & GetInstance();

        virtual ObexProtocol *  GetProtocol(ObexProtocolId  level);

        virtual void    ResolveServerAddr(const String &    server_url,
                                          ObexProtocolId    prot_id,
                                          BOOLEAN           sdb_autocreate,
                                          ObexOperationId   job_id);

        virtual void    ResolveClientAddr(const String &    client_url,
                                          ObexProtocolId    prot_id,
                                          ObexOperationId   job_id);

        virtual void    AbortResolveClientAddr(const ObexOperationId &  job_id);


            // Callback prototype

        static void ServerCallBack(IrConnect* con, IrCallBackParms* parms);
        static void ClientCallBack(IrConnect* con, IrCallBackParms* parms);

        void UnbindStack(void* arg);
        IrConnection irconnections[C_IR_CONNECTIONS_MAX_NUM];
        static UINT16 m_client_discovery_poll_repeat_counter;
        static SystemTimer m_clienttimer;
        static BOOLEAN ir_discoverreq_in_progress;

    private:


        enum discovery_poll_repeat_interval{  c_ir_discovery_poll_repeat_interval = 4000 // try every 4 second , because IR_STATUS_NO_PROGRESS means that IrLAP has no progress for 3 seconds
        };
        enum discovery_poll_repeat_number{  c_ir_discovery_poll_repeat_maxnumber = 5, // 5 x 4 second trying
                                            c_ir_discovery_finalized = c_ir_discovery_poll_repeat_maxnumber+50
        };
        

        IrdaObexImpl    m_obex_impl;
        static void OnClientTimer(void* arg);


        //IrStackContext m_irstackcontext;
        // (Global) IrLMP/Tiny TP connection structure:
        IrConnect m_appCon; //assuming this is common for all connections
        // Server: Accepting an Incoming IrLMP Connection: Packet structure for responses:
        static IrPacket m_appPacket;
        static ObexOperationId s_operationid;

};

/*
    IrdaObexSubSystem initialises IrdaObexTransport
*/
class IrdaObexSubSystem : public SubSystem {
    public:
        virtual const WCHAR* GetName() const { return L"IrDA Obex"; };
        virtual void OnPowerUp();
        virtual BootSequenceState InvokeAt() const { return SubSystemManager::c_run_level_1; };
    private:
        static IrdaObexSubSystem    m_irda_obex_sub_system;
};

#endif  // Apoxi_IrdaObexTransport_hpp

