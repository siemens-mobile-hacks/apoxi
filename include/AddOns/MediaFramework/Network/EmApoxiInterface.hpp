/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiInterface_hpp)
#define EmApoxiInterface_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

typedef enum
{
    c_em_event_conn_req_pending,
    c_em_event_conn_closed,
    c_em_event_data_sent,
    c_em_event_data_received,
    c_em_event_bearer_lost 
}EmSockEvent;

typedef EmApoxiUINT8 EmApoxiDataConnProfileId;

typedef void (*EmSockEventCbFn(EmSockEvent a_sock_event, void *a_sock,
              void *a_user_data));

typedef void (*EmNetworkExecCbFn(EmApoxiUINT32 a_msg, void *a_user_data));
typedef enum
{
    c_em_network_exec_request,
    c_em_network_periodic_exec_request,
    c_em_network_response,
    c_em_network_timeout_registercb,
    c_em_release_socket_handler,
    c_em_init_socket_handler,
    c_em_start_buffering_timer,
    c_em_cancel_buffering_timer,
    c_em_start_network_timer,
    c_em_start_ff_rwd_network_timer,
    c_em_stop_ff_rwd_network_timer,
    c_em_create_network_instance,
    c_em_delete_network_instance

}EmNetworkServiceThreadMsgType;

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiInterface_hpp

