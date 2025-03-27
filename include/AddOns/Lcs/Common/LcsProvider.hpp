/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsProvider_hpp)
#define AddOns_Lcs_Common_LcsProvider_hpp

#include "LcsTypes.hpp"

class LcsProviderImplBase;

class LcsProvider
{
    public:

        ~LcsProvider();

        static LcsProvider* GetInstance();

        LcsErrorCode SendVerificationResult(UINT16 invoke_id, BOOLEAN user_response);

        LcsErrorCode SelfLocationReq(LcsCost lcs_cost = Low,
                                    const LcsMmiQos& lcs_mmi_qos = LcsMmiQos(),
                                    INT32 repeat_interval = -1);
        
        LcsErrorCode TransferLocationReq(const LcsMmiQos& lcs_mmi_qos,
                                        const ClientId& client_id,
                                        const MlcNumber& mlc_number,
                                        INT32 repeat_interval = -1);
        
        LcsErrorCode AbortSelfLocReq();

        LastLocationEstimate GetLastKnownLocation() const;

        BOOLEAN SetProtocol(LcsTransportType new_protocol);

        LcsErrorCode RegisterForMtlr(const Application* app);

        BOOLEAN SetNmeaUartSettings(BOOLEAN nmea_switch, const NmeaUartSettings& nmea_uart_settings);


    private:

        LcsProvider();

        void Init();

        LcsProviderImplBase* SelectProvider(LcsCost lcs_cost, MolrType& molr_type);

        void UnloadProtProvider();


    private:

        static LcsProvider m_lcs_provider;

        static BOOLEAN m_initialized;

        LcsProviderImplBase* m_prot_provider;

        LcsProviderImplBase* m_sa_provider;

}; // LcsProvider

#endif // AddOns_Lcs_Common_LcsProvider_hpp

