/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestDefines_hpp)
#define ApoxiApp_SocketTestDefines_hpp

enum ErrorCode {
    ST_ERR_ALLOCATION               = 200,  
    ST_ERR_SOCKALLOC                = 201,  
    ST_ERR_CLOSE                    = 202,  
    ST_ERR_WRONGDATA                = 203,  
    ST_ERR_USERINTERRUPT            = 204,  
    ST_ERR_WRITESOCK_CONTEXT        = 205,  
    ST_ERR_WRITESOCK_UNKNOWN        = 206,  
    ST_ERR_NOT_ALL_PACKETS_RECEIVED = 207,  
    ST_ERR_SET_DATACONN_PROFILE_ID  = 208,  
    ST_ERR_SERVER_SOCK_LISTEN       = 209   
};

#define KBYTE 1024

#endif // ApoxiApp_SocketTestDefines_hpp
