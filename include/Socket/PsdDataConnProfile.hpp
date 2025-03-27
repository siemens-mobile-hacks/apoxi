/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PsdDataConnProfile_hpp)
#define Apoxi_PsdDataConnProfile_hpp

#include <Socket/DataConnProfile.hpp>
#include <Asc/PdpContext.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

typedef NiSharedPtr<PdpContext::PacketFilter> PdpPacketFilterPtr;

class PsdDataConnProfile : public DataConnProfile
{
    typedef DataConnProfile Base;

    public:
        typedef PdpContext::Authentication::Type AuthType;
        typedef PdpContext::QualityOfService::Precedence QosPrecedence;
        typedef PdpContext::QualityOfService::Delay QosDelay;
        typedef PdpContext::QualityOfService::Reliability QosReliability;
        typedef PdpContext::QualityOfService::PeakRate QosPeakRate;
        typedef PdpContext::QualityOfService::MeanRate QosMeanRate;

        struct Bit {
            UINT m_auth_type                : 2;
            UINT m_data_compr               : 1;
            UINT m_header_compr             : 1;
            UINT m_qos_precedence           : 2;
            UINT m_qos_delay                : 3;
            UINT m_qos_reliability          : 3;
            UINT m_qos_peak_rate            : 4;
            UINT m_qos_mean_rate            : 5;
#if defined(APOXI_RAT_UMTS) || defined(APOXI_RAT_DUAL)
            UINT m_present_3g               : 1;
            UINT m_traffic_class            : 8;
            UINT m_delivery_order           : 8;
            UINT m_error_sdu_delivery       : 8;
            UINT m_max_sdu_size             : 8;
            UINT m_max_bit_rate_up          : 8;
            UINT m_max_bit_rate_down        : 8;
            UINT m_residual_ber             : 8;
            UINT m_sdu_error_ratio          : 8;
            UINT m_transfer_delay           : 8;
            UINT m_traffic_priority         : 8;
            UINT m_guaranteed_bit_rate_up   : 8;
            UINT m_guaranteed_bit_rate_down : 8;
#endif  // APOXI_RAT_UMTS || APOXI_RAT_DUAL
        };

    public:
        PsdDataConnProfile();
        virtual ~PsdDataConnProfile();

        const String& GetApnName() const 
            { return m_apn; }

        void SetApnName(const String &apn) 
            { m_apn = apn; }

        const IpAddr& GetLocalAddr() const 
            { return m_local; }

        void SetLocalAddr(const IpAddr &local) 
            { m_local = local; }

        AuthType GetAuthType() const 
            { return (AuthType)m_bit.m_auth_type; }

        void SetAuthType(AuthType at) 
            { m_bit.m_auth_type = at; }

        BOOLEAN DoDataCompr() const 
            { return m_bit.m_data_compr; }

        void EnableDataCompr(BOOLEAN enable = TRUE) 
            { m_bit.m_data_compr = enable; }

        BOOLEAN DoHeaderCompr() const 
            { return m_bit.m_header_compr; }

        void EnableHeaderCompr(BOOLEAN enable = TRUE) 
            { m_bit.m_header_compr = enable; }

        BOOLEAN SetPrimaryProfileId(DataConnProfileId profile_id);

        DataConnProfileId GetPrimaryProfileId() const
            { return m_primary_id; }

        BOOLEAN UsesSecondaryPdpContext() const {
            return GetPrimaryProfileId() != c_invalid_data_conn_profile_id;
        }

        BOOLEAN SetPacketFilter(const PdpPacketFilterPtr &filter);

        BOOLEAN UnsetPacketFilter(UINT8 id);

        PdpPacketFilterPtr GetPacketFilter(UINT8 id) const;

        QosPrecedence GetQosPrecedence() const 
            { return (QosPrecedence)m_bit.m_qos_precedence; }
        void SetQosPrecedence(QosPrecedence qp) 
            { m_bit.m_qos_precedence = qp; }

        QosDelay GetQosDelay() const 
            { return (QosDelay)m_bit.m_qos_delay; }
        void SetQosDelay(QosDelay qd) 
            { m_bit.m_qos_delay = qd; }

        QosReliability GetQosReliability() const 
            { return (QosReliability)m_bit.m_qos_reliability; }
        void SetQosReliability(QosReliability qr) 
            { m_bit.m_qos_reliability = qr; }

        QosPeakRate GetQosPeakRate() const 
            { return (QosPeakRate)m_bit.m_qos_peak_rate; }
        void SetQosPeakRate(QosPeakRate qpr) 
            { m_bit.m_qos_peak_rate = qpr; }

        QosMeanRate GetQosMeanRate() const 
            { return (QosMeanRate)m_bit.m_qos_mean_rate; }
        void SetQosMeanRate(QosMeanRate qmr) 
            { m_bit.m_qos_mean_rate = qmr; }

#if defined(APOXI_RAT_UMTS) || defined(APOXI_RAT_DUAL)
        INT GetQos3GPresent() const 
            { return (INT) m_bit.m_present_3g; }
        void SetQos3GPresent(INT present_3g) 
            { m_bit.m_present_3g = present_3g; }

        INT GetQosTrafficClass() const 
            { return (INT) m_bit.m_traffic_class; }
        void SetQosTrafficClass(INT traffic_class) 
            { m_bit.m_traffic_class = traffic_class; }

        INT GetQosDeliveryOrder() const 
            { return (INT) m_bit.m_delivery_order; }
        void SetQosDeliveryOrder(INT delivery_order) 
            { m_bit.m_delivery_order = delivery_order; }

        INT GetQosErrorSduDelivery() const 
            { return (INT) m_bit.m_error_sdu_delivery; }
        void SetQosErrorSduDelivery(INT error_sdu_delivery) 
            { m_bit.m_error_sdu_delivery = error_sdu_delivery; }

        INT GetQosMaxSduSize() const 
            { return (INT) m_bit.m_max_sdu_size; }
        void SetQosMaxSduSize(INT max_sdu_size) 
            { m_bit.m_max_sdu_size = max_sdu_size; }

        INT GetQosBitRateUp() const 
            { return (INT) m_bit.m_max_bit_rate_up; }
        void SetQosBitRateUp(INT max_bit_rate_up) 
            { m_bit.m_max_bit_rate_up = max_bit_rate_up; }

        INT GetQosBitRateDown() const 
            { return (INT) m_bit.m_max_bit_rate_down; }
        void SetQosBitRateDown(INT max_bit_rate_down) 
            { m_bit.m_max_bit_rate_down = max_bit_rate_down; }

        INT GetQosResidualBer() const 
            { return (INT) m_bit.m_residual_ber; }
        void SetQosResidualBer(INT residual_ber) 
            { m_bit.m_residual_ber = residual_ber; }

        INT GetQosSduErrorRatio() const 
            { return (INT) m_bit.m_sdu_error_ratio; }
        void SetQosSduErrorRatio(INT sdu_error_ratio) 
            { m_bit.m_sdu_error_ratio = sdu_error_ratio; }

        INT GetQosTransferDelay() const 
            { return (INT) m_bit.m_transfer_delay; }
        void SetQosTransferDelay(INT transfer_delay) 
            { m_bit.m_transfer_delay = transfer_delay; }

        INT GetQosTrafficPriority() const 
            { return (INT) m_bit.m_traffic_priority; }
        void SetQosTrafficPriority(INT traffic_priority) 
            { m_bit.m_traffic_priority = traffic_priority; }

        INT GetQosGuaranteedBitRateUp() const 
            { return (INT) m_bit.m_guaranteed_bit_rate_up; }
        void SetQosGuaranteedBitRateUp(INT guaranteed_bit_rate_up) 
            { m_bit.m_guaranteed_bit_rate_up = guaranteed_bit_rate_up; }

        INT GetQosGuaranteedBitRateDown() const 
            { return (INT) m_bit.m_guaranteed_bit_rate_down; }
        void SetQosGuaranteedBitRateDown(INT guaranteed_bit_rate_down) 
            { m_bit.m_guaranteed_bit_rate_down = guaranteed_bit_rate_down; }
#endif  // APOXI_RAT_UMTS || APOXI_RAT_DUAL

    protected:
        virtual void SaveFrom(const PersistDataConnProfile &bpp);
        virtual void SaveTo(PersistDataConnProfile &bpp) const;

        virtual DataConnProfile* New() const;

        virtual void Assign(const DataConnProfile& from_dcp);

    private:
        Bit m_bit;
        String m_apn;
        IpAddr m_local;
        DataConnProfileId m_primary_id;
        PdpPacketFilterPtr m_packet_filter[8];

    public:
        struct Persist {
            CHAR m_apn[c_apn_name_len_max + 1];
            Bit m_bit;
            IpAddr::Persist m_local;
        };
};

#endif  // Apoxi_PsdDataConnProfile_hpp


