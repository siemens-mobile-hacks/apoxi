/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifdef APOXI_LETTERCLASSE_SUPPORT

#if !defined(Asc_SimTkLceDispatcher_hpp)
#define Asc_SimTkLceDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>
#include <Apc/SimTkTypes.hpp>

#include <Socket/CsdDataConnProfile.hpp>
#include <Socket/PsdDataConnProfile.hpp>

#include <Socket/SocketHandler.hpp>
#include <Socket/NetAdapterHandler.hpp>

#define SIMTK_LCE_SOCKET_RECV_BUFFER_SIZE 1024
#define SIMTK_LCE_SOCKET_SEND_BUFFER_SIZE 1024
#define SIMTK_LCE_SIM_SEND_BUFFER_SIZE 1024

class SocketData;

class SiRxBuf {
    public:
        SiRxBuf(const INT len);
        ~SiRxBuf();
        UINT8 * m_data; // Takes the whole size of SIMTK_LCE_SOCKET_RECV_BUFFER_SIZE.
        ChannelData * chdata; // Takes only 244 bytes for delivery to SIM.
        INT filledbytes;
        BOOLEAN delivered;
        INT readposition;
        INT GetCapacity()  const { return m_capacity; }
        void SetCapacity(const UINT capacity) {  m_capacity = capacity; }
        BOOLEAN FillNextChanBufForSim(const INT NumBytes) ;

    private:
        UINT m_capacity;
};

class SiTxBuf {
    public:
        SiTxBuf(const INT len);
        ~SiTxBuf();
        UINT8 * m_data; // Takes the whole size of SIMTK_LCE_SIM_SEND_BUFFER_SIZE.
        ChannelData * chdata; // Takes only 244 bytes for receiving from SIM.
        //UINT filledbytes;
        BOOLEAN delivered;
        UINT readposition;
        UINT writeposition; //also used as filledbytes counter
        UINT GetCapacity()  const { return m_capacity; }
        void SetCapacity(const UINT capacity) {  m_capacity = capacity; }
        BOOLEAN IncReadPosition(const INT IncNumBytes) ;
        BOOLEAN FillNextChanBufFromSim() ;
        BOOLEAN ZeroReadWritePosition() { readposition = 0; writeposition = 0;   return TRUE; }

    private:
        UINT m_capacity;
};

/*  ========================================================================
    SimTkLceDispatcher
    ======================================================================== */
class SimTkLceDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

    friend class DataConn;
    friend class CsdDataConn;
    friend class PsdDataConn;

    public:
        SimTkLceDispatcher();
        virtual ~SimTkLceDispatcher();

        enum csd_speed {
//CSD T_SI_BEARER_DESC parameters
/*<speed>: GSM 27.007 */
            csd_autobauding = 0,        //(automatic selection of the speed; this setting is possible in case of 3.1 kHz modem and non-transparent service)
            csd_300_bps_V_21 = 1,
            csd_1200_bps_V_22 = 2,
            csd_1200_75_bps_V_23 = 3,
            csd_2400_bps_V_22bis = 4,
            csd_2400_bps_V_26ter = 5,
            csd_4800_bps_V_32 = 6,
            csd_9600_bps_V_32 = 7,
            csd_9600_bps_V_34 = 12,
            csd_14400_bps_V_34 = 14,
            csd_19200_bps_V_34 = 15,
            csd_28800_bps_V_34 = 16,
            csd_33600_bps_V_34 = 17,
            csd_1200_bps_V_120 = 34,
            csd_2400_bps_V_120 = 36,
            csd_4800_bps_V_120 = 38,
            csd_9600_bps_V_120 = 39,
            csd_14400_bps_V_120 = 43,
            csd_19200_bps_V_120 = 47,
            csd_28800_bps_V_120 = 48,
            csd_38400_bps_V_120 = 49,
            csd_48000_bps_V_120 = 50,
            csd_56000_bps_V_120 = 51,
            csd_300_bps_V_110 = 65,
            csd_1200_bps_V_110 = 66,
            csd_2400_bps_V_110_or_X31_flag_stuffing = 68,
            csd_4800_bps_V_110_or_X31_flag_stuffing = 70,
            csd_9600_bps_V_110_or_X31_flag_stuffing = 71,
            csd_14400_bps_V_110_or_X31_flag_stuffing = 75,
            csd_19200_bps_V_110_or_X31_flag_stuffing = 79,
            csd_28800_bps_V_110_or_X31_flag_stuffing = 80,
            csd_38400_bps_V_110_or_X31_flag_stuffing = 81,
            csd_48000_bps_V_110_or_X31_flag_stuffing = 82,
            csd_56000_bps_V_110_or_X31_flag_stuffing = 83,
            csd_64000_bps_X31_flag_stuffing = 84,
            csd_56000_bps_bit_transparent = 115,
            csd_64000_bps_bit_transparent = 116,
            csd_32000_bps_PIAFS32k = 120,
            csd_64000_bps_PIAFS64k = 121,
            csd_28800_bps_multimedia = 130,
            csd_32000_bps_multimedia = 131,
            csd_33600_bps_multimedia = 132,
            csd_56000_bps_multimedia = 133,
            csd_64000_bps_multimedia = 134,

        };

//<name>:
        enum csd_name {
            data_circuit_asynchronous_UDI_or_31kHz_modem = 0,
            data_circuit_synchronous_UDI_or_31kHz_modem = 1,
            PAD_Access_asynchronous_UDI = 2,
            Packet_Access_synchronous_UDI = 3,
            data_circuit_asynchronous_RDI = 4,
            data_circuit_synchronous_RDI = 5,
            PAD_Access_asynchronous_RDI = 6,
            Packet_Access_synchronous_RDI = 7,
        };

        enum connectionelement {
//<ce>:
            transparent = 0,
            non_transparent = 1,
            both_transparent_preferred = 2,
            both_non_transparent_preferred = 3,

        };

//PSD T_SI_BEARER_DESC parameters
/* QoS: GSM 23.107 ,  9.1.2.3 Table 7:  Determining R97/98 attributes from R99 attributes*/
/*NEWTYPE T_QOS //#NAME 'T_QOS'
    STRUCT
  // 2G parameters
      delay_class               Byte;
      reliability_class         Byte;
      precedence_class          Byte;
      peak_throughput           Byte;
      mean_throughput           Byte;
  // 3G parameters
      present_3g        Boolean;
      traffic_class             Byte;
      delivery_order            Byte;
      error_sdu_delivery        Byte;
      max_sdu_size              Byte;
      max_bit_rate_up           Byte;
      max_bit_rate_down         Byte;
      residual_ber              Byte;
      sdu_error_ratio           Byte;
      transfer_delay            Byte;
      traffic_priority          Byte;
      guaranteed_bit_rate_up    Byte;
      guaranteed_bit_rate_down  Byte;
  ENDNEWTYPE;
*/

        enum qos_traffic_delay_class {
           delayclass_subscribed  = 0,
           delayclass1  = 1,
           delayclass2  = 2,
           delayclass3  = 3,
           delayclass4  = 4,
           delayclassreserved  = 7,
        };
        enum qos_reliability_class {
            reliabilitysubscribed = 0,
            reliabilityclass1 = 1,
            reliabilityclass2 = 2,
            reliabilityclass3 = 3,
            reliabilityclass4 = 4,
            reliabilityclass5 = 5,
            reliabilityclass6 = 6,
            reliabilityreserved = 7,
        };
        enum qos_precedence_class {
            precedencesubscribed    = 0,
            precedencehigh          = 1,
            precedencenormal        = 2,
            precedencelow           = 3,
            precedencereserved      = 7,
        };
        enum qos_peak_throughput_class  {
//          peakrateundef = 0,
            peakratesubscribed  = 0,
            peakrate1K  = 1,
            peakrate2K  = 2,
            peakrate4K  = 3,
            peakrate8K  = 4,
            peakrate16K     = 5,
            peakrate32K     = 6,
            peakrate64K     = 7,
            peakrate128K    = 8,
            peakrate256K    = 9,
            peakratereserved = 15,
        };

        enum qos_mean_throughput_class {
            MeanRateSubscribed = 0,
            MeanRate100 = 1,
            MeanRate200 = 2,
            MeanRate500 = 3,
            MeanRate1K = 4,
            MeanRate2K = 5,
            MeanRate5K = 6,
            MeanRate10K = 7,
            MeanRate20K = 8,
            MeanRate50K = 9,
            MeanRate100K = 10,
            MeanRate200K = 11,
            MeanRate500K = 12,
            MeanRate1M = 13,
            MeanRate2M = 14,
            MeanRate5M = 15,
            MeanRate10M = 16,
            MeanRate20M = 17,
            MeanRate50M = 18,
            MeanRateReserved = 30,
            MeanRateBestEffort = 31, //always_set_to_31 = 31, // 0x1F
        };

/*GSM 11.14, 12.52.2    Bearer parameters for GPRS  packet service*/
        enum qos_pd_protocol_type {
            internet_protocol_IETF_STD_5 = 2,
        };

        UINT8 GetSimCallSetupOption() const { return m_sim_command_qualifier; };
        const PhoneNumber & GetStkCallSetupNo() const { return m_stk_phone_no; };

        SimTkTransactionId stktransid;

        //regular messages: SIM -> Proactive Client
        BOOLEAN OnSiChannelOpenPromptReq(const StackMsgArgument &arg);
        BOOLEAN OnSiChannelCloseInfoInd(const StackMsgArgument &arg);
        BOOLEAN OnSiChannelSendInfoInd(const StackMsgArgument &arg);
        BOOLEAN OnSiChannelReceiveInfoInd(const StackMsgArgument &arg);

        //messages: SIM -> IP-Socket
        BOOLEAN OnDhChannelOpenReq(const StackMsgArgument &arg);
        BOOLEAN OnDhChannelCloseReq(const StackMsgArgument &arg);
        BOOLEAN OnDhChannelSendReq(const StackMsgArgument &arg);
        BOOLEAN OnDhChannelDataAvailableRes(const StackMsgArgument &arg);
        BOOLEAN OnDhChannelReceiveReq(const StackMsgArgument &arg);
        BOOLEAN OnDhChannelChangeStatusRes(const StackMsgArgument &arg);

        //some commands, could be moved to another class
        BOOLEAN OpenBearerUndefChan();
        BOOLEAN OpenBearerCsdChan(UINT8 csd_speed, UINT8 csd_name, UINT8 csd_connectionelement);
        BOOLEAN OpenBearerPsdChan(qos_precedence_class precedence, qos_traffic_delay_class delay, qos_reliability_class reliability, qos_peak_throughput_class peakthroughput, qos_mean_throughput_class meanthroughput, qos_pd_protocol_type pdprotocoltype);
        BOOLEAN OpenBearerDefaultChan();
#if defined(APOXI_SER_DATACONN_SUPPORT)
        BOOLEAN OpenBearerSerChan(); //not an option in SiBearerList
#endif

        BOOLEAN NewProfile(DataConnProfile::ProfileType type);
            //Helpers for NewProfile():
            BOOLEAN LoadProfile(DataConnProfile::ProfileType type, DataConnProfileId profile_id);
            INT     ProfileCount();
            DataConnProfile* GetProfile(DataConnProfile::ProfileType type);

        void EditBasicEntry(DataConnProfile* profile);
        void EditCsdEntry(UINT8 csd_speed, UINT8 csd_name, UINT8 csd_connectionelement);
        void EditSerEntry();
        void EditPsdEntry(qos_precedence_class precedence, qos_traffic_delay_class delay, qos_reliability_class reliability, qos_peak_throughput_class peakthroughput, qos_mean_throughput_class meanthroughput, qos_pd_protocol_type pdprotocoltype);

        //Notification, if Buffer was received
        void OnFillRecvBuf(INT id, UINT8*  BufferRecv, INT dataLen);
        //Notification, if Buffer was sent
        void OnSendBufSent(INT id, INT dataLen);

        // Callback invoked on NetAdapter events.
        static void LceNetAdapterCallBackHandler(void* client_arg, NetAdapterHandler &handler, NetAdapter &net_adapter, NetAdapter::Event event, const NetAdapter::EventArgs &event_args);


        BOOLEAN LceDhChannelOpenCnf(const UINT8 cidx, const UINT16 buffer_size, const SiBearerDesc bearer_desc,  const GenResultCode gen_result,  const UINT8 adn_result ) const;

        BOOLEAN LceDhChannelOpenRej(const UINT8 cidx, const GenResultCode gen_result,  const UINT8 adn_result ) const;

        BOOLEAN LceDhChannelCloseInd(const UINT8 cidx, const GenResultCode gen_result,  const UINT8 adn_result ) const;

        BOOLEAN LceDhChannelSendInd(const UINT8 cidx, const UINT16 empty_bytes_in_tx, const UINT8 gen_result,  const UINT8 adn_result ) const;

        BOOLEAN LceDhChannelDataAvailEvent(const UINT8 cidx, const UINT16 channel_data_length,  const SiChannelChangedState changed_state ) const;

        BOOLEAN LceDhChannelReceiveInd(const UINT8 cidx, const UINT16 remaining_data_length, const GenResultCode gen_result,  const UINT8 adn_result, const ChannelData& channel_data ) const;

        BOOLEAN LceDhChannelChangeStatusEvent(UINT8 cidx, const SiChannelChangedState& changed_state) const;

    private:
        static const StackMsgArgMap<SimTkLceDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SimTkLceDispatcher> m_arg_map_container;
        UINT8        m_sim_command_qualifier;
        BOOLEAN      m_events_present;
        PhoneNumber  m_stk_phone_no;
        SimEventList m_event_list;


        //Data keepers:
        mutable UINT16 keep_channel_data_length_for_resending;
        UINT8 channelId ;
        mutable UINT8   keep_cidx_for_resending;
        mutable SiChannelChangedState keep_changed_state_for_resending;
        UINT16 buffersize ;
        UINT8 cmdqualifier ;
        SiTransportLayer transportlayer ;
        SiBearerDesc bearerdesc ;
        SiIpAddress  localipaddr ;
        SiIpAddress destipaddr ;
        UINT16 destPort ;
        UINT16 localPort;
        SiDuration duration1 ;
        SiDuration duration2 ;
        PhoneNumber  phonenumber ;
        SimSubAddress subaddress ;
        SimTextString userlogin ;
        SimTextString password ;
        BOOLEAN enablepasswd;
        BOOLEAN immediate_link_establishment; //TRUE=immediate link establishment, FALSE=on demand link establishment
        BOOLEAN automatic_reconnection; //TRUE=automatic reconnection, FALSE=no automatic reconnection
        BOOLEAN link_establishment_now;

        IpAddr serverAddress;
        String apn;

        INT addressLen ; //currently only 4 = IP4

        CsdDataConnProfile m_csd_profile;
        PsdDataConnProfile m_psd_profile;

        DataConnProfileId m_dc_id;

        SocketHandler m_socket_handler; // Handler needed to receive for socket events.

        NetAdapterHandler* m_lce_net_adapter_handler;
        NetAdapter::Id     m_lce_net_adapter_id;
        NetAdapter::Type   m_lce_net_adapter_type;

        UINT32 m_last_send_request; // Amount of bytes passed to the last NetAdapterHandler::Send() method call.

        SiRxBuf * siRxBuf;
        SiTxBuf * siTxBuf;
};

#endif  // Asc_SimTkLceDispatcher_hpp

#endif  // APOXI_LETTERCLASSE_SUPPORT

