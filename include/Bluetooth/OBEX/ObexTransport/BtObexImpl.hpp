
#if !defined(Apoxi_BtObexImpl_hpp)
#define Apoxi_BtObexImpl_hpp

#include <Auxiliary/String.hpp>
#include <Obex/ObexLayer.hpp>
#include <Obex/ObexChannel.hpp>
#include <Obex/ObexAddress.hpp>

#include <Bluetooth/OBEX/ObexTransport/BtObexClientServiceImpl.hpp>
#include <Bluetooth/OBEX/ObexTransport/BtObexServerServiceImpl.hpp>
#include <Bluetooth/OBEX/ObexTransport/BtObexClientObserverImpl.hpp>
#include <Bluetooth/OBEX/ObexTransport/BtObexServerObserverImpl.hpp>
#include <Bluetooth/OBEX/ObexTransport/BtObexSddbServiceObserverImpl.hpp>
#include <Bluetooth/OBEX/ObexTransport/BtObexSddbImpl.hpp>
#include <Kernel/Os/Mutex.hpp>

#define BT_OBEX_DEBUG_OUT 40230

//Forward declaration for friend class
class BtObexClientObserverImpl;
//class Mutex;

class BtObexImpl : public ObexLayer
{
    typedef ObexLayer Base;

    class BtObexClientConnection;
    class BtObexServerConnection;

    friend class BtObexClientConnection;
    friend class BtObexServerConnection;

    public:
        BtObexImpl();

        virtual ~BtObexImpl();

        virtual ObexResult AcquireClientChannel( ObexChannel& result,
                                                                const ObexAddrPtr & addr_ptr,
                                                                BOOLEAN reserve = FALSE);

        virtual void OpenClientChannel( const ObexChannel & client_chan,
                                                    ObexOperationId oper_id,
                                                    const ObexAddrPtr & addr_ptr );


        virtual ObexResult AcquireServerChannel( ObexChannel& result,
                                                                const ObexAddrPtr & addr_ptr,
                                                                BOOLEAN reserve = FALSE );


        virtual void BindServerChannel( const ObexChannel & server_chan,
                                                    ObexOperationId oper_id,
                                                    const ObexAddrPtr & addr_ptr );


        virtual void CloseChannel(const ObexChannel &  channel,
                                  ObexOperationId      oper_id);


        virtual ObexResult ReleaseChannel(ObexChannel &  channel);


        virtual void Connect( const ObexChannel & client_chan,
                                    ObexOperationId oper_id,
                                    const ObexObject & conn_req );


        virtual void Put( const ObexChannel &   client_chan,
                            ObexOperationId oper_id,
                            const ObexObject & put_req);


        virtual void Get(const ObexChannel & client_chan,
                            ObexOperationId oper_id,
                            const ObexObject & get_req);


        virtual void Abort(const ObexChannel & client_chan, ObexOperationId oper_id, const ObexObject & abort_req);


        virtual void SetPath( const ObexChannel & client_chan,
                                    ObexOperationId oper_id,
                                    const ObexObject & setp_req);


            virtual void Disconnect( const ObexChannel & client_chan,
                                        ObexOperationId oper_id,
                                        const ObexObject & disc_req);

        virtual void ReturnResponse(const ObexChannel & server_chan,
                                                ObexOperationId oper_id,
                                                const ObexObject & server_resp);

        virtual void DataProcessed(const ObexChannel & channel, ObexOperationId oper_id, ObexBuffer & obex_buffer);

        Mutex* GetTransportMutex() {return &m_transport_mutex;};

    private:
        void Init();

#ifdef APOXI_PLATFORM_BP30

        #define MAX_BT_CLIENT_CHANNELS 1

        #define MAX_BT_SERVER_CHANNELS 1
#else /* APOXI_PLATFORM_BP30 */

        #define MAX_BT_CLIENT_CHANNELS 3

        #define MAX_BT_SERVER_CHANNELS 2
#endif /* APOXI_PLATFORM_BP30 */

        #define MAX_BT_AVAILABLE_CHANNELS (MAX_BT_CLIENT_CHANNELS + MAX_BT_SERVER_CHANNELS)

        #define OBEX_HEADER_SIZE 1320

        //XXXXX
        //#define LOCAL_BUFFER_SIZE 512
        #define LOCAL_BUFFER_SIZE (1024)

        //XXXXX
        //#define OBEX_BUFFER_MAX_SIZE 600
        #define OBEX_BUFFER_MAX_SIZE (LOCAL_BUFFER_SIZE)

        enum ChannelPoolStatus
        {
            Free,           
            Allocated,  
            Associated  
        };

        class  ChannelPool
        {
            public:
                ObexChannel m_chp_channel;      
                ObexAddrPtr m_chp_addr_p;           
                UINT8 m_chp_cs_idx;                     
                ChannelPoolStatus m_chp_status;     
        };

        ChannelPool m_channel_pool[MAX_BT_AVAILABLE_CHANNELS];

        UINT8 m_num_cli_idx;

        UINT8 m_num_srv_idx;

        BOOLEAN m_empty_buff_rec;

        BOOLEAN AllocateIndex( UINT16 &returned_index );

        BOOLEAN DeallocateIndex( UINT16 index );


        //TBD: Is it really necessary?
        BOOLEAN CheckAddressInThePool( const ObexAddrPtr &addr_ptr );

        enum ClientConnectionStatus
        {
            ClientFree,         
            ClientReady,            
            ClientOpened,       
            ClientConnected 
        };

        enum ClientOperationStatus
        {
            ClientOperationReady,       
            ClientOpenRequested,            
            ClientCloseRequested,           
            ClientConnectRequested,     
            ClientPut,                          
            ClientAbortRequested,           
            ClientGetRequested,         
            ClientGetEnd,                   
            ClientSetPathRequested,     
            ClientDisconnectRequested   
        };

        enum ServerConnectionStatus
        {
            ServerFree,         
            ServerReady,        
            ServerBounded,      
            ServerConnected 
        };

        enum ServerOperationStatus
        {
            ServerOperationReady,       
            ServerBindRequested,            
            ServerCloseRequested,       
            ServerConnectIncoming,      
            ServerPutIncoming,          
            ServerPutContinue,          
            ServerPutEnd,                   
            ServerAbortIncoming,            
            ServerGetIncoming,          
            ServerGetContinue,          
            ServerSetPathIncoming,      
            ServerDisconnectIncoming    
        };

        class BtObexClientConnection
        {
            public:
                BtObexClientServiceImpl m_service;      
                ClientConnectionStatus m_status;            
                ClientOperationStatus m_op_status;      
                ObexOperationId m_op_id;                    
                ObexBuffer m_obj_buffer;                    
                ObexObject m_obex_abort;
                BOOLEAN m_obj_is_end_of_data;       
                BOOLEAN m_ready;
                UINT8 m_header[OBEX_HEADER_SIZE];   
                UINT16 m_index;                         

                void            BeginOperation(const ObexOperationId &  oper_id,
                                               ClientOperationStatus    status);

                ObexOperationId EndOperation();
        };

        class BtObexServerConnection
        {
            public:
                BtObexServerServiceImpl m_service;  
                BtObexSddbImpl m_sddb_service;  
                ServerConnectionStatus m_status;            
                ServerOperationStatus m_op_status;      
                ObexOperationId m_op_id;                    
                ObexBuffer m_obj_buffer;                    
                BOOLEAN m_obj_is_end_of_data;       
                BOOLEAN m_ready;
                BOOLEAN m_isAborted;
                ObexServerId    m_obex_server_id;   
                UINT8 m_header[OBEX_HEADER_SIZE];   
                UINT16 m_index;                         

                void            BeginOperation(const ObexOperationId &  oper_id,
                                               ServerOperationStatus    status);

                ObexOperationId EndOperation();

                void            HandleAbortIfPending();
        };

        static  void            AddHeader(ObexObject &          obex_obj,
                                          const BtObexHeader &  header);

        BOOLEAN AllocateClientInstance( UINT16 index );

        BOOLEAN AllocateServerInstance( UINT16 index );

        BOOLEAN GetServiceIndex( const ObexChannel &ob_chan, UINT8 &instance_index );

        BOOLEAN GetServiceIndex( UINT16 index, UINT8 &instance_index );

        void ObexClientHeadersToServiceHeaders( const ObexObject &obj, UINT8 i );
        void ObexServerHeadersToServiceHeaders( const ObexObject &obj, UINT8 i );

        void    AcceptServerOperation(UINT8                     conn_no,
                                      ServerOperationStatus     status);

        void    FinishClientOperation(UINT8             conn_no,
                                      const ObexResult  result);

        void    FinishServerOperation(UINT8             conn_no,
                                      const ObexResult  result);

        BOOLEAN CreateObexServiceRecord( UINT16 index );

        void DbgOut( String dbg_str );

        BtObexClientConnection m_cli[MAX_BT_CLIENT_CHANNELS];

        BtObexClientObserverImpl m_cli_obs[MAX_BT_CLIENT_CHANNELS];

        BtObexServerConnection m_srv[MAX_BT_SERVER_CHANNELS];

        BtObexServerObserverImpl m_srv_obs[MAX_BT_SERVER_CHANNELS];

        BtObexSddbServiceObserverImpl m_srv_sddb_service[MAX_BT_SERVER_CHANNELS];

        Mutex m_transport_mutex;

        friend class BtObexServerObserverImpl;

        friend class BtObexClientObserverImpl; 

        friend class BtObexSddbServiceObserverImpl;
};

#endif

