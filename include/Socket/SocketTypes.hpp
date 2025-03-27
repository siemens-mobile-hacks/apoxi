/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketTypes_hpp)
#define Apoxi_SocketTypes_hpp

#include <Kernel/Types.hpp>

typedef UINT8 DataConnProfileId;

enum SocketError {
    c_socket_no_error = 0,                  

    c_socket_unknown_error = 1,             
    c_socket_no_bearer = 2,                 
    c_socket_bearer_busy = 3,               
    c_socket_bearer_not_supported = 4,      
    c_socket_fatal_system_error = 5,        
    c_socket_wrong_execution_context = 6,   
    c_socket_subsystem_not_init = 7,        
    c_socket_no_data_conn_profile = 8,      
    c_socket_conn_setup_failed = 9,         
    c_socket_conn_in_release = 10,          
    c_socket_conn_in_setup = 11,            
    c_socket_conn_blocked = 12,             
    c_socket_conn_perform_setup = 13,       
    c_socket_conn_timed_out = 14,           
    c_socket_conn_lost = 15,                
    c_socket_wait_for_send_unblocked = 16,  
    c_socket_wait_for_recv_unblocked = 17,  

    c_socket_ebadf = 100,                   
    c_socket_eintr = 101,                   

    c_socket_einval = 102,                  

    c_socket_enotsock = 103,                

    c_socket_eopnotsupp = 104,              

    c_socket_ewouldblock = 105,             

    c_socket_eaddrnotavail = 106,           

    c_socket_eacces = 107,                  

    c_socket_eisconn = 108,                 

    c_socket_etimedout = 109,               

    c_socket_econnrefused = 110,            

    c_socket_enetunreach = 111,             

    c_socket_eaddrinuse = 112,              

    c_socket_ealready = 113,                

    c_socket_einprogress = 114,             

    c_socket_enotconn = 115,                

    c_socket_emsgsize = 116,                

    c_socket_enobufs = 117,                 

    c_socket_enoprotoopt = 118,             

    c_socket_emfile = 119,                  

    c_socket_econnreset = 120,              

    c_socket_ehostunreach = 121,            

    c_socket_econnaborted = 122,            

    c_socket_efault = 123,                  

    c_socket_edestaddrreq = 124,            

    c_socket_eprototype = 125,              

    c_socket_eprotonosupport = 126,         

    c_socket_esocktnosupport = 127,         

    c_socket_epfnosupport = 128,            

    c_socket_eafnosupport = 129,            

    c_socket_enetdown = 130,                

    c_socket_enetreset = 131,               

    c_socket_eshutdown = 132,               

    c_socket_ehostdown =133                 

};

enum SocketControlMsgType {
    c_scmt_rx_data_arrived,             
    c_scmt_tx_data_ready,               

    c_scmt_ppp_setup_err,               
    c_scmt_ppp_setup,                   
    c_scmt_ppp_stop_err,                
    c_scmt_ppp_stop,                    

    c_scmt_csd_setup_err,               
    c_scmt_csd_datacall_setup,          
    c_scmt_csd_datacall_setup_success,  
    c_scmt_csd_datacall_setup_fail,     
    c_scmt_csd_datacall_release,        
    c_scmt_csd_lost,                    

    c_scmt_psd_setup_err,               
    c_scmt_psd_ctx_defined,             
    c_scmt_psd_ctx_undefined,           
    c_scmt_psd_ctx_dns_neg_set,         
    c_scmt_psd_ctx_packet_filter_set,   
    c_scmt_psd_ctx_authenticated,       
    c_scmt_psd_ctx_qos_set,             
    c_scmt_psd_ctx_deactivated,         
    c_scmt_psd_ctx_connected,           
    c_scmt_psd_ctx_neg_dns_read,        
    c_scmt_psd_ctx_link_up,             
    c_scmt_psd_ctx_link_down,           
    c_scmt_psd_lost,                    

    c_scmt_data_conn_established,       
    c_scmt_idle_timeout,                
    c_scmt_init_context_err,            

    c_scmt_data_conn_cancelled,         

    c_scmt_control_data_available,      

    c_scmt_undefined
};

enum DataConnInfoMsgType {
    c_csd_data_conn_init,
    c_csd_data_conn_established,
    c_csd_data_conn_setup_failed,
    c_csd_data_conn_init_release,
    c_csd_data_conn_released,
    c_csd_data_conn_setup_blocked,

    c_psd_data_conn_init,
    c_psd_data_conn_established,
    c_psd_data_conn_setup_failed,
    c_psd_data_conn_init_release,
    c_psd_data_conn_released,
    c_psd_data_conn_setup_blocked,

    c_ser_data_conn_init,
    c_ser_data_conn_established,
    c_ser_data_conn_setup_failed,
    c_ser_data_conn_init_release,
    c_ser_data_conn_released,
    c_ser_data_conn_setup_blocked
};

enum DataConnProfileInfoMsgType {
    c_data_conn_profile_created,
    c_data_conn_profile_changed,
    c_data_conn_profile_deleted,
    c_data_conn_profile_set_as_default
};

/*  -------------------------------------------------------------------------
                                    Constants
    ------------------------------------------------------------------------- */
#if !defined(APOXI_MAX_INET_SOCKET_COUNT)
#    define APOXI_MAX_INET_SOCKET_COUNT 16
#endif

#if !defined(APOXI_DATA_CONN_PROFILE_COUNT)
#    define APOXI_DATA_CONN_PROFILE_COUNT 5
#endif

#if !defined(APOXI_DATA_CONN_TEMP_PROFILE_COUNT)
#    define APOXI_DATA_CONN_TEMP_PROFILE_COUNT 15
#endif

#if !defined(APOXI_HOST_NAME_LEN_MAX)
#    define APOXI_HOST_NAME_LEN_MAX 64
#endif

#if !defined(APOXI_APN_NAME_LEN_MAX)    // see UTP: PAX6000000190
#    define APOXI_APN_NAME_LEN_MAX 99
#endif

#if !defined(APOXI_BEARER_PROFILE_NAME_LEN_MAX)
#    define APOXI_BEARER_PROFILE_NAME_LEN_MAX 20
#endif

#if !defined(APOXI_BEARER_PROFILE_ACCOUNT_LEN_MAX)
#    define APOXI_BEARER_PROFILE_ACCOUNT_LEN_MAX 25
#endif

#if !defined(APOXI_BEARER_PROFILE_PASSWD_LEN_MAX)
#    define APOXI_BEARER_PROFILE_PASSWD_LEN_MAX 15
#endif

const UINT c_max_inet_socket_count = APOXI_MAX_INET_SOCKET_COUNT;

const UINT c_host_name_len_max = APOXI_HOST_NAME_LEN_MAX;

const UINT c_apn_name_len_max = APOXI_APN_NAME_LEN_MAX; // see UTP: PAX6000000190

const UINT c_data_conn_profile_count = APOXI_DATA_CONN_PROFILE_COUNT;

const UINT c_data_conn_temp_profile_count = APOXI_DATA_CONN_TEMP_PROFILE_COUNT;

const DataConnProfileId c_invalid_data_conn_profile_id = 0;

const DataConnProfileId c_default_data_conn_profile_id = c_invalid_data_conn_profile_id;

const DataConnProfileId c_max_data_conn_profile_id = (1 << (sizeof(DataConnProfileId) * 8 - 1)) - 1;

typedef DataConnProfileId DataConnProfileIdSet[c_data_conn_profile_count];

typedef DataConnProfileId DataConnTempProfileIdSet[c_data_conn_temp_profile_count];

/*  -------------------------------------------------------------------------
                                    Macros
    ------------------------------------------------------------------------- */
// Enable extended safety & debug features in paranoia mode.
#if defined (APOXI_SOCKET_PARANOIA)
    #if !defined (APOXI_SOCKET_ENSURE_CONTEXT)
        #define APOXI_SOCKET_ENSURE_CONTEXT
    #endif
    #if !defined (APOXI_SOCKET_OPERATION_LOCK)
        #define APOXI_SOCKET_OPERATION_LOCK
    #endif
    #if !defined (APOXI_TRACE_SOCKETS)
        #define APOXI_TRACE_SOCKETS
    #endif
    #if !defined (APOXI_SOCKET_EXTENDED_TRACE)
        #define APOXI_SOCKET_EXTENDED_TRACE
    #endif
#endif

#if defined(APOXI_TRACE_SOCKETS)

    enum SocketTraceId {
        c_socket_trace_no_start = 25030,
        c_socket_trace_no_end = 25039,

        c_socket_generic_trace_no = 25030,
        c_socket_sys_trace_no = 25031,
        c_socket_rx_trace_no = 25032,
        c_socket_tx_trace_no = 25033,
        c_socket_udp_trace_no = 25034,
        c_socket_tcp_trace_no = 25035,
        c_socket_data_conn_trace_no = 25036
    };

    #if defined (APOXI_SOCKET_EXTENDED_TRACE)

        void SocketExtendedDbgOut(UINT16 idx, const CHAR *fmt, ...);

        #define SocketTrace(x)  SocketExtendedDbgOut x
    #else
        #define SocketTrace(x)  DBG_OUT(x)
    #endif
#else
    #define SocketTrace(x)
#endif

#endif  // Apoxi_SocketTypes_hpp

