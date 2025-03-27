/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpTypes_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpTypes_hpp


// DBG_OUT Range
#define HTTPSERVER_DBG_OUT_RANGE 35920

// default value for backlog of HttpServerSocket when listening
#define APOXI_HTTPSERVER_DEFAULT_BACKLOG 15

// default maximum of currently connected clients
#define APOXI_HTTPSERVER_DEFAULT_MAX_USERS 5

// default size for transmitting data from or to clients
#if defined(APOXI_TARGETSYSTEM_HOST)
#define HTTPSERVER_DEFAULT_TRANSMISSION_SIZE (128*1024)
#elif defined(APOXI_TARGETSYSTEM_HW)
#define HTTPSERVER_DEFAULT_TRANSMISSION_SIZE (8*1024)
#endif

// used ASCII codes
#define HTTPSERVER_ASCII_LF 10 // line feed
#define HTTPSERVER_ASCII_CR 13 // carriage return
#define HTTPSERVER_ASCII_SP 32 // blank space ' '
#define HTTPSERVER_ASCII_QM 63 // question mark '?'
#define HTTPSERVER_ASCII_EQU    61 // equals sign '='
#define HTTPSERVER_ASCII_AMP    38 // ampersand '&'
#define HTTPSERVER_ASCII_PER    37 // percent sign '%'
#define HTTPSERVER_ASCII_DOT    46 // dot '.'
#define HTTPSERVER_ASCII_SL 47 // forward slash '/'
#define HTTPSERVER_ASCII_PL 43 // plus sign '+'

/* Commands used internally by HttpServer to keep public interface but 
    initialize SocketHandler in the right ExecutionContext.
*/
enum HttpServiceCommand {
    c_http_service_command_init,
    c_http_service_command_terminate,
    c_http_service_command_start,
    c_http_service_command_stop
};

enum HttpServiceCommandError {
    c_http_service_command_error_success,
    c_http_service_command_error_failed
};

// return codes for HttpRequest-handling methods
enum HttpResponseCode {
    c_http_response_code_200,   // OK
    c_http_response_code_400,   // Bad request
    c_http_response_code_404    // Not found
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpTypes_hpp

