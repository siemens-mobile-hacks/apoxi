/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SysSocketBase_hpp)
#define Apoxi_SysSocketBase_hpp

#include <Auxiliary/IpAddr.hpp>

class PppDataConn;
class PsdDataConn;

struct PppCallBackData {};

struct PppSetupCallBackData : public PppCallBackData {

    void Reset() {
        m_interface_address.SetAddr(0);
        m_primary_dns_server_address.SetAddr(0);
        m_secondary_dns_server_address.SetAddr(0);
    }

    IpAddr m_interface_address;
    IpAddr m_primary_dns_server_address;
    IpAddr m_secondary_dns_server_address;
};

typedef void (*PppCallback)(INT error, PppDataConn &dc, const PppCallBackData *data);

typedef void (*PsdIfCallback)(INT error, void *client_arg);

class SysSocketBase
{
    public:

        enum Type {
            c_type_dgram,
            c_type_stream,
            c_type_raw
        };

        enum AddrFamily {
            c_addr_family_inet,
            c_addr_family_unspec
        };

        enum ShutdownMode {
            c_shutdown_stop_rx,
            c_shutdown_stop_tx,
            c_shutdown_stop_rx_tx
        };

        enum OptionType {
            c_option_error,
            c_option_debug,
            c_option_reuse_addr,
            c_option_keep_alive,
            c_option_linger,
            c_option_dont_route,
            c_option_broadcast,
            c_option_snd_buf,
            c_option_rcv_buf,
            c_option_type,
            c_option_tcp_no_delay,
            c_option_tcp_max_seg
        };

        struct LingerSetting {
            BOOLEAN m_on_off;
            INT32 m_timeout;
        };

    protected:
        static PppCallback          m_ppp_callback;
        static PppDataConn         *m_ppp_callback_dc;
        static PppCallBackData     *m_ppp_callback_data;
        static PppSetupCallBackData m_ppp_callback_data_setup;
};

#endif  // Apoxi_SysSocketBase_hpp

