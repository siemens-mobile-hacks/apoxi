/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_PdpContext_hpp)
#define Asc_PdpContext_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/IpAddr.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/BitField.hpp>
#include <Auxiliary/IpPortNo.hpp>
#include <Asc/ValueMap.hpp>
#include <Asc/PppFrame.hpp>

class PdpContext : public Linkable<PdpContext>
{
    friend class PdpContextSignalProcessor;
    friend class PdpContextManager;

    public:
        typedef INT Id;
        
        typedef UINT8 NsApi;
        
        typedef UINT32 DataUnits;

        enum DataCompression {
            NoDataCompression = 0,              // default if value is omitted
            PreferredDataCompression = 1,       // manufacturer preferred compression
            V42bis = 2,
            V44 = 3
        };

        enum HeaderCompression {
            NoHeaderCompression = 0,            // default if value is omitted
            PreferredHeaderCompression = 1,     // manufacturer preferred compression
            Rfc1144 = 2,                        // applicable for SNDCP only
            Rfc2507 = 3,
            Rfc3095 = 4                     // applicable for PDCP only
        };

        enum {
            ApoxiDefineScopeEntity(c_max_access_point_name_len, PdpContext)
        };

        enum Type {
//          ApoxiDefineScopeEntity(X25Type, PdpContext),
            ApoxiDefineScopeEntity(IpType, PdpContext),
            ApoxiDefineScopeEntity(IpStaticType, PdpContext),
            ApoxiDefineScopeEntity(IpDynamicType, PdpContext),
//          ApoxiDefineScopeEntity(OspihType, PdpContext),
            ApoxiDefineScopeEntity(PppType, PdpContext),
            ApoxiDefineScopeEntity(NoType, PdpContext)
        };

        enum Protocol {
            ApoxiDefineScopeEntity(NullProtocol, PdpContext),
            ApoxiDefineScopeEntity(PppProtocol, PdpContext),
            ApoxiDefineScopeEntity(PadProtocol, PdpContext),
            ApoxiDefineScopeEntity(X25Protocol, PdpContext),
//          ApoxiDefineScopeEntity(ManufProtocol, PdpContext),
            ApoxiDefineScopeEntity(NoProtocol, PdpContext)
        };

        enum Origin {
            ApoxiDefineScopeEntity(Network, PdpContext),
            ApoxiDefineScopeEntity(MobileStation, PdpContext),
            ApoxiDefineScopeEntity(UnknownOrigin, PdpContext)
        };

        enum ErrorCause {       // should be mapped to an enum, for now value 0 indicates no error.
            ApoxiDefineScopeEntity(IllegalMs, PdpContext),
            ApoxiDefineScopeEntity(IllegalMe, PdpContext),
            ApoxiDefineScopeEntity(GprsServiceNotAllowed, PdpContext),
            ApoxiDefineScopeEntity(PlmnNotAllowed, PdpContext),
            ApoxiDefineScopeEntity(LaNotAllowed, PdpContext),
            ApoxiDefineScopeEntity(NationalRoamingNotAllowed, PdpContext),

            ApoxiDefineScopeEntity(LlcOrSndcpFailure, PdpContext),
            ApoxiDefineScopeEntity(InsufficientRessources, PdpContext),
            ApoxiDefineScopeEntity(MissingOrUnknownApn, PdpContext),
            ApoxiDefineScopeEntity(UnknownPdpAddress, PdpContext),
            ApoxiDefineScopeEntity(AuthenticationFailure, PdpContext),
            ApoxiDefineScopeEntity(ActivationRejectedByGgsn, PdpContext),
            ApoxiDefineScopeEntity(UnspecifiedActivationRejection, PdpContext),
            ApoxiDefineScopeEntity(ServiceOptionNotSupported, PdpContext),
            ApoxiDefineScopeEntity(RequestedServiceOptionNotSubscribed, PdpContext),
            ApoxiDefineScopeEntity(ServiceOptionTemporaryOutOfOrder, PdpContext),
            ApoxiDefineScopeEntity(NsapiAlreadyUsed, PdpContext),
            ApoxiDefineScopeEntity(RegularDeactivation, PdpContext),
            ApoxiDefineScopeEntity(QosNotAccepted, PdpContext),
            ApoxiDefineScopeEntity(NetworkFailure, PdpContext),
            ApoxiDefineScopeEntity(ReactivationRequired, PdpContext),
            ApoxiDefineScopeEntity(InvalidTi, PdpContext),
            ApoxiDefineScopeEntity(SemanticIncorrectMsg, PdpContext),
            ApoxiDefineScopeEntity(InvalidMandatoryIe, PdpContext),
            ApoxiDefineScopeEntity(MsgTypeNotExistent, PdpContext),
            ApoxiDefineScopeEntity(MsgTypeNotCompatible, PdpContext),
            ApoxiDefineScopeEntity(IeNonExistent, PdpContext),
            ApoxiDefineScopeEntity(ConditionalIeError, PdpContext),
            ApoxiDefineScopeEntity(MsgNotCompatible, PdpContext),
            ApoxiDefineScopeEntity(UnspecifiedProtocolError, PdpContext),

            ApoxiDefineScopeEntity(UndefinedError, PdpContext),
            ApoxiDefineScopeEntity(NoError, PdpContext)
        };

        enum State {
            Undefined,
            Defined,
            Activated,
            Connected
        };

        class Address {
            public:
                enum {
                    ApoxiDefineScopeEntity(c_max_len, PdpContext_Address)
                };

                Address(UINT8 *data = 0, INT len = c_max_len);

                Address(IpAddr ip_addr);

                IpAddr GetIpAddr() const;

                String GetIPv4String() const;

                const UINT8* GetData() const;

                UINT GetLength() const;

                BOOLEAN IsIPv4() const;

                BOOLEAN IsValid() const;

                void Reset();

            private:
                UINT8 m_buffer[c_max_len];
        };

        class Authentication {
            public:
                enum {
                    ApoxiDefineScopeEntity(c_max_account_len, PdpContext_Authentication),
                    ApoxiDefineScopeEntity(c_max_password_len, PdpContext_Authentication)
                };

                enum Type {
                    ApoxiDefineScopeEntity(None, PdpContext_Authentication),
                    ApoxiDefineScopeEntity(Pap, PdpContext_Authentication),
                    ApoxiDefineScopeEntity(Chap, PdpContext_Authentication)
                };

                Authentication(Type type = None, const String& account = String(), const String& password = String());

                ~Authentication();

                Type GetType() const { return (m_type); }
                void SetType(Type type) { m_type = type; }

                const String& GetAccount() const { return (m_account); }
                void SetAccount(const String& account) { m_account = account; }

                const String& GetPassword() const { return (m_password); }
                void SetPassword(const String& password) { m_password = password; }

            private:
                Type m_type;
                String m_account;
                String m_password;
        };

        class QualityOfService {
            public:
                enum Precedence {
                    ApoxiDefineScopeEntity(PrecedenceSubscribed, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PrecedenceHigh, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PrecedenceNormal, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PrecedenceLow, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PrecedenceReserved, PdpContext_QualityOfService)
                };

                enum Delay {
                    ApoxiDefineScopeEntity(DelaySubscribed, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(DelayClass1, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(DelayClass2, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(DelayClass3, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(DelayBestEffort, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(DelayReserved, PdpContext_QualityOfService)
                };

                enum Reliability {
                    ApoxiDefineScopeEntity(ReliabilitySubscribed, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityClass1, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityClass2, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityClass3, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityClass4, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityClass5, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityClass6, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(ReliabilityReserved, PdpContext_QualityOfService)
                };

                enum PeakRate {
                    ApoxiDefineScopeEntity(PeakRateSubscribed, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate1K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate2K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate4K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate8K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate16K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate32K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate64K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate128K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRate256K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(PeakRateReserved, PdpContext_QualityOfService)
                };

                enum MeanRate {
                    ApoxiDefineScopeEntity(MeanRateSubscribed, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate100, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate200, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate500, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate1K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate2K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate5K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate10K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate20K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate50K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate100K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate200K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate500K, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate1M, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate2M, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate5M, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate10M, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate20M, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRate50M, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRateReserved, PdpContext_QualityOfService),
                    ApoxiDefineScopeEntity(MeanRateBestEffort, PdpContext_QualityOfService)
                };

                QualityOfService(Precedence precedence = PrecedenceSubscribed,
                                 Delay delay = DelaySubscribed,
                                 Reliability reliability = ReliabilitySubscribed,
                                 PeakRate peak_rate = PeakRateSubscribed,
                                 MeanRate mean_rate = MeanRateSubscribed
#if defined(APOXI_RAT_UMTS) || defined(APOXI_RAT_DUAL)
                                 ,
                                 int present_3g = 0,
                                 int traffic_class = 0,
                                 int delivery_order = 0,
                                 int error_sdu_delivery = 0,
                                 int max_sdu_size = 0,
                                 int max_bit_rate_up = 0,
                                 int max_bit_rate_down = 0,
                                 int residual_ber = 0,
                                 int sdu_error_ratio = 0,
                                 int transfer_delay = 0,
                                 int traffic_priority = 0,
                                 int guaranteed_bit_rate_up = 0,
                                 int guaranteed_bit_rate_down = 0
#endif  // APOXI_RAT_UMTS || APOXI_RAT_DUAL
                                 );

                ~QualityOfService();

                void Reset();

                Precedence GetPrecedence() const { return (m_precedence); }
                void SetPrecedence(Precedence precedence) { m_precedence = precedence; }

                Delay GetDelay() const { return (m_delay); }
                void SetDelay(Delay delay) { m_delay = delay; }

                Reliability GetReliability() const { return (m_reliability); }
                void SetReliability(Reliability reliability) { m_reliability = reliability; }

                PeakRate GetPeakRate() const { return (m_peak_rate); }
                void SetPeakRate(PeakRate peak_rate) { m_peak_rate = peak_rate; }

                MeanRate GetMeanRate() const { return (m_mean_rate); }
                void SetMeanRate(MeanRate mean_rate) { m_mean_rate = mean_rate; }

#if defined(APOXI_RAT_UMTS) || defined(APOXI_RAT_DUAL)
                int Get3GPresent() const { return (m_present_3g); }
                void Set3GPresent(int present_3g) { m_present_3g = present_3g; }

                int GetTrafficClass() const { return (m_traffic_class); }
                void SetTrafficClass(int traffic_class) { m_traffic_class = traffic_class; }

                int GetDeliveryOrder() const { return (m_delivery_order); }
                void SetDeliveryOrder(int delivery_order) { m_delivery_order = delivery_order; }

                int GetErrorSduDelivery() const { return (m_error_sdu_delivery); }
                void SetErrorSduDelivery(int error_sdu_delivery) { m_error_sdu_delivery = error_sdu_delivery; }

                int GetMaxSduSize() const { return (m_max_sdu_size); }
                void SetMaxSduSize(int max_sdu_size) { m_max_sdu_size = max_sdu_size; }

                int GetBitRateUp() const { return (m_max_bit_rate_up); }
                void SetBitRateUp(int max_bit_rate_up) { m_max_bit_rate_up = max_bit_rate_up; }

                int GetBitRateDown() const { return (m_max_bit_rate_down); }
                void SetBitRateDown(int max_bit_rate_down) { m_max_bit_rate_down = max_bit_rate_down; }

                int GetResidualBer() const { return (m_residual_ber); }
                void SetResidualBer(int residual_ber) { m_residual_ber = residual_ber; }

                int GetSduErrorRatio() const { return (m_sdu_error_ratio); }
                void SetSduErrorRatio(int sdu_error_ratio) { m_sdu_error_ratio = sdu_error_ratio; }

                int GetTransferDelay() const { return (m_transfer_delay); }
                void SetTransferDelay(int transfer_delay) { m_transfer_delay = transfer_delay; }

                int GetTrafficPriority() const { return (m_traffic_priority); }
                void SetTrafficPriority(int traffic_priority) { m_traffic_priority = traffic_priority; }

                int GetGuaranteedBitRateUp() const { return (m_guaranteed_bit_rate_up); }
                void SetGuaranteedBitRateUp(int guaranteed_bit_rate_up) { m_guaranteed_bit_rate_up = guaranteed_bit_rate_up; }

                int GetGuaranteedBitRateDown() const { return (m_guaranteed_bit_rate_down); }
                void SetGuaranteedBitRateDown(int guaranteed_bit_rate_down) { m_guaranteed_bit_rate_down = guaranteed_bit_rate_down; }
#endif  // APOXI_RAT_UMTS || APOXI_RAT_DUAL

            private:
                Precedence m_precedence;
                Delay m_delay;
                Reliability m_reliability;
                PeakRate m_peak_rate;
                MeanRate m_mean_rate;
#if defined(APOXI_RAT_UMTS) || defined(APOXI_RAT_DUAL)
                int m_present_3g;
                int m_traffic_class;
                int m_delivery_order;
                int m_error_sdu_delivery;
                int m_max_sdu_size;
                int m_max_bit_rate_up;
                int m_max_bit_rate_down;
                int m_residual_ber;
                int m_sdu_error_ratio;
                int m_transfer_delay;
                int m_traffic_priority;
                int m_guaranteed_bit_rate_up;
                int m_guaranteed_bit_rate_down;
#endif  // APOXI_RAT_UMTS || APOXI_RAT_DUAL
        };

        class ActivationStatus {

            public:

                enum State {
                    ApoxiDefineScopeEntity(StateAccepted, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(StateRejected, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(StateFiveTimeT3380Expiry, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(StateUserInteruption, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(StateUnknownCause, PdpContext_ActivationStatus),
                };

                enum RadioPriority {
                    ApoxiDefineScopeEntity(RadioPriorityLevel_1, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(RadioPriorityLevel_2, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(RadioPriorityLevel_3, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(RadioPriorityLevel_4, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(RadioPriorityLevel_Undefined, PdpContext_ActivationStatus),
                };

                enum LlcSapi {
                    ApoxiDefineScopeEntity(LlcSapi_NotAssigned, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_1, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_3, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_5, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_7, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_9, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_11, PdpContext_ActivationStatus),
                    ApoxiDefineScopeEntity(LlcSapi_Invalid, PdpContext_ActivationStatus),
                };

                ActivationStatus(State state = StateUnknownCause,
                                 INT reject_cause = 0,
                                 const QualityOfService& quality_of_service = QualityOfService(),
                                 LlcSapi llc_sapi = LlcSapi_NotAssigned,
                                 RadioPriority radio_priority = RadioPriorityLevel_Undefined,
                                 const Address& address = Address(),
                                 const String& apn = String(),
                                 INT t3380_expiries = 0);

                ~ActivationStatus();

                void Reset();

                State GetState() const { return (m_state); }
                void SetState(State state) { m_state = state; }

                INT GetRejectCause() const { return (m_reject_cause); }
                void SetRejectCause(INT reject_cause) { m_reject_cause = reject_cause; }

                const QualityOfService& GetQualityOfService() const { return m_quality_of_service; }
                void SetQualityOfService(const QualityOfService& quality_of_service) { m_quality_of_service = quality_of_service; }

                LlcSapi GetLlcSapi() const { return (m_llc_sapi); }
                void SetLlcSapi(LlcSapi llc_sapi) { m_llc_sapi = llc_sapi; }

                RadioPriority GetRadioPriority() const { return m_radio_priority; }
                void SetRadioPriority(RadioPriority radio_priority) { m_radio_priority = radio_priority; }

                const Address& GetAddress() const { return m_address; }
                void SetAddress(const Address& address) { m_address = address; }
    
                const String& GetAccessPointName() const { return m_apn; }
                void SetAccessPointName(const String& apn) { m_apn = apn; }

                INT GetT3380Expiries() const { return m_t3380_expiries; }
                void SetT3380Expiries(INT t3380_expiries) { m_t3380_expiries = t3380_expiries; }

            private:

                State            m_state;
                INT              m_reject_cause;
                QualityOfService m_quality_of_service;
                LlcSapi          m_llc_sapi;
                RadioPriority    m_radio_priority;
                Address          m_address;
                String           m_apn;
                INT              m_t3380_expiries;
        };


        class PacketFilter {

            friend class PdpContext;

            public:

                // Address and Mask (IPv4 or IPv6)
                union AddressAndMask {

                    AddressAndMask() {
                        memset(this, 0, sizeof(AddressAndMask));
                    }

                    struct {
                        UINT8 m_address[4];
                        UINT8 m_subnet[4];
                    } m_ipv4_address_and_mask;

                    struct {
                        UINT8 m_address[16];
                        UINT8 m_subnet[16];
                    } m_ipv6_address_and_mask;
                };

                enum Type {
                    ApoxiDefineScopeEntity(Type_1, PdpContext_PacketFilter),
                    ApoxiDefineScopeEntity(Type_2, PdpContext_PacketFilter),
                    ApoxiDefineScopeEntity(Type_3, PdpContext_PacketFilter),
                    ApoxiDefineScopeEntity(Type_Unknown, PdpContext_PacketFilter),
                };

                PacketFilter(UINT8 id,
                             UINT8 evaluation_precedence_index,
                             const AddressAndMask& src_addr_and_mask,
                             UINT8 prot_nbr_or_nxt_hdr,
                             const IpPortNo& lower_dst_port,
                             const IpPortNo& upper_dst_port,
                             const IpPortNo& lower_src_port,
                             const IpPortNo& upper_src_port,
                             UINT8 tos_or_traffic_class,
                             UINT8 tos_mask_or_traffic_class_mask);

                PacketFilter(UINT8 id,
                             UINT8 evaluation_precedence_index,
                             const AddressAndMask& src_addr_and_mask,
                             UINT8 prot_nbr_or_nxt_hdr,
                             UINT32 ipsec_security_param_idx,
                             UINT8 tos_or_traffic_class,
                             UINT8 tos_mask_or_traffic_class_mask);

                PacketFilter(UINT8 id,
                             UINT8 evaluation_precedence_index,
                             const AddressAndMask& src_addr_and_mask,
                             UINT8 tos_or_traffic_class,
                             UINT8 tos_mask_or_traffic_class_mask,
                             UINT32 flow_label);

                ~PacketFilter();

                Type GetType() const;

                UINT8 GetId() const { return m_id; }

                UINT8 GetEvaluationPrecedenceIndex() const { return m_evaluation_precedence_index; }

                BOOLEAN IsSourceAddressAndSubnetMaskPresent() const { return m_precedence.GetBit(0); }

                const AddressAndMask& GetSourceAddressAndSubnetMask() const { return m_source_address_and_subnet_mask; }

                BOOLEAN IsProtocolNumberOrNextHeaderPresent() const { return m_precedence.GetBit(1); }

                UINT8 GetProtocolNumberOrNextHeader() const { return m_protocol_number_or_next_header; }

                BOOLEAN IsDestinationPortRangePresent() const { return m_precedence.GetBit(2); }

                const IpPortNo& GetLowerDestinationPort() const { return m_lower_destination_port; }

                const IpPortNo& GetUpperDestinationPort() const { return m_upper_destination_port; }

                BOOLEAN IsSourcePortRangePresent() const { return m_precedence.GetBit(3); }

                const IpPortNo& GetLowerSourcePort() const { return m_lower_source_port; }

                const IpPortNo& GetUpperSourcePort() const { return m_upper_source_port; }

                BOOLEAN IsIpSecSecurityParameterIndexPresent() const { return m_precedence.GetBit(4); }

                UINT32 GetIpSecSecurityParameterIndex() const { return m_ipsec_security_parameter_index; }

                BOOLEAN IsTypeOfServiceAndMaskOrTrafficClassAndMaskPresent() const { return m_precedence.GetBit(5); }

                UINT8 GetTypeOfServiceOrTrafficClass() const { return m_tos_or_traffic_class; }

                UINT8 GetTypeOfServiceMaskOrTrafficClassMask() const { return m_tos_mask_or_traffic_class_mask; }

                BOOLEAN IsFlowLabelPresent() const { return m_precedence.GetBit(6); }

                UINT32 GetFlowLabel() const { return m_flow_label; }

            private:
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)

                PacketFilter(const T_PACKET_FILTER & packet_filter);

                operator T_PACKET_FILTER () const;
#endif              

                /*  Bit #0: Source Address and Subnet Mask
                    Bit #1: Protocol Number (IPv4) / Next Header (IPv6)
                    Bit #2: Destination Port Range
                    Bit #3: Source Port Range
                    Bit #4: IPSec Security Parameter Index (IPSec SPI)
                    Bit #5: Type of Service (TOS) (IPv4) / Traffic Class (IPv6) and Mask
                    Bit #6: Flow Label (IPv6)
                    Bit #7: <Not used yet> */
                BitField8 m_precedence;

                UINT8 m_id;

                UINT8 m_evaluation_precedence_index;

                AddressAndMask m_source_address_and_subnet_mask;

                UINT8 m_protocol_number_or_next_header;

                IpPortNo m_lower_destination_port, m_upper_destination_port;

                IpPortNo m_lower_source_port, m_upper_source_port;

                UINT32 m_ipsec_security_parameter_index;

                UINT8 m_tos_or_traffic_class;

                UINT8 m_tos_mask_or_traffic_class_mask;

                UINT32 m_flow_label;
        };


    private:
        PdpContext(Id id, Id primary_id);
        PdpContext(Id id);

        virtual ~PdpContext();

    public:
        Id GetId() const { return (m_id); }

        Id GetPrimaryId() const { return (m_primary_id); }

        State GetState() const { return (m_state); }

        BOOLEAN IsActive() const;

        BOOLEAN IsAddressAllocatedDynamically() const { return (m_address_is_dynamically_allocated); }

        Type GetType() const { return (m_type); }

        const Address& GetAddress() const { return m_address; }

        const String& GetAccessPointName() const { return m_access_point_name; }

        DataCompression GetDataCompression() const { return m_data_compression; }

        HeaderCompression GetHeaderCompression() const { return m_header_compression; }

        BOOLEAN IsAuthenticated() const { return (m_authenticated); }

        BOOLEAN IsSecondary() const { return (m_primary_id != 0); };

        const PppFrame& GetPppFrame() const { return m_ppp_frame; }

        const QualityOfService& GetQualityOfService() const { return m_quality_of_service; }

        Protocol GetProtocol() const { return m_protocol; }

        NsApi GetAccessPointId() const { return (m_access_point_id); }

        const QualityOfService& GetMinimumQualityOfService() const { return m_minimum_quality_of_service; }

        const ActivationStatus& GetActivationStatus() const { return m_activation_status; }

        BOOLEAN Define(Type type, const Address &address = Address(), const String &access_point_name = String(),
            DataCompression data_compression = NoDataCompression, HeaderCompression header_compression = NoHeaderCompression);

        BOOLEAN Define(DataCompression data_compression = NoDataCompression, HeaderCompression header_compression = NoHeaderCompression);

        BOOLEAN Undefine();

        BOOLEAN Authenticate(const Authentication &authentication);

        BOOLEAN SetQualityOfService(const QualityOfService &quality_of_service);

        BOOLEAN SetMinimumQualityOfService(const QualityOfService &quality_of_service);

        BOOLEAN Activate();

        BOOLEAN Activate(const PppFrame &ppp_frame);

        BOOLEAN Accept(Type type = NoType, const Address &address = Address());

        static void Reject();

        BOOLEAN Deactivate();

        BOOLEAN Connect(Protocol protocol);

        BOOLEAN SetCounter(DataUnits bytes_sent = 0, DataUnits bytes_received = 0);

        BOOLEAN ReadCounter();

        BOOLEAN SetPacketFilter(const PacketFilter &packet_filter);

        BOOLEAN UnsetPacketFilter(UINT8 packet_filter_id = 0);

        BOOLEAN SetAutomaticDnsServerNegotiation(BOOLEAN enable);
        
        BOOLEAN ReadNegotiatedDnsServerAddress();

    private:
        State m_state;

        Id m_id;
        Id m_primary_id;
        Type m_type;
        Address m_address;
        BOOLEAN m_address_is_dynamically_allocated;
        String m_access_point_name;
        DataCompression m_data_compression;
        HeaderCompression m_header_compression;

        BOOLEAN m_authenticated;
        PppFrame m_ppp_frame;

        QualityOfService m_quality_of_service;
        QualityOfService m_minimum_quality_of_service;
        QualityOfService m_temporary_quality_of_service;

        ActivationStatus m_activation_status;

        Protocol m_protocol;
        NsApi m_access_point_id;

        void Reset();
        void ResetOnDeactivation();

        // Sets the ActivationStatus and then posts a PdpContextActivationStatusMessage to inform applications about a context activation status update
        void SetActivationStatus(const ActivationStatus& activation_status);

        // Callback needed for reading the data counters of a pdp context before undefining it
        void OnSilentReadCounterCompleted(PdpContext::ErrorCause cause);
};

#endif  // Asc_PdpContext_hpp


