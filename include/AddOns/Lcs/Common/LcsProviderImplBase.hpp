/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsProviderImplBase_hpp)
#define AddOns_Lcs_Common_LcsProviderImplBase_hpp

#include "LcsTypes.hpp"
#include "LcsDecls.hpp"
#include "LcsTimer.hpp"

class LcsProviderImplBase
{
    public:

        explicit LcsProviderImplBase(LcsTransportType protocol);

        virtual ~LcsProviderImplBase();

        virtual LcsErrorCode TransferLocationReq(MolrType molr_type,
                                                LocationMethod location_method,
                                                const LcsMmiQos& lcs_mmi_qos,
                                                const ClientId& client_id,
                                                const MlcNumber& mlc_number,
                                                INT32 repeat_interval) = 0;

        virtual void OnTimeOut(LcsTimerType timer_type) = 0;

        virtual void Init();

        virtual LcsErrorCode SendVerificationResult(UINT16 invoke_id, BOOLEAN user_response);

        LcsErrorCode SelfLocationReq(MolrType molr_type,
                                    LocationMethod location_method,
                                    const LcsMmiQos& lcs_mmi_qos,
                                    INT32 repeat_interval);

        LcsTransportType GetProtocol() const { return m_protocol; }

        BOOLEAN SetNmeaUartSettings(BOOLEAN nmea_switch, const NmeaUartSettings& nmea_uart_settings);

        static LcsErrorCode RegisterForMtlr(const Application* app);

        static LastLocationEstimate GetLastKnownLocation() { return m_last_loc_est; }

        static LcsErrorCode AbortSelfLocReq();


    protected:

        virtual BOOLEAN OnAbortResponse(const StackMsgArgument& arg);

        void SendNmeaData();


    private:

        LcsProviderImplBase();

        BOOLEAN SendNmeaGGA(const LocationEstimate& loc_est);

        BOOLEAN SendNmeaGSV(const GpsFixData& fix_data);

        void AddNmeaChecksum(String& nmea_data);


    protected:
        
        static LastLocationEstimate m_last_loc_est;

        static Application* m_mtlr_app;

        LcsTimer m_molr_timer;

        
    private:

        LcsTransportType m_protocol;

        BOOLEAN m_nmea_switch;

        static INT32 m_uart_fd;

}; // LcsProviderImplBase

#endif // AddOns_Lcs_Common_LcsProviderImplBase_hpp

