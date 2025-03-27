/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if !defined(Adc_StatusProvider_hpp)
#define Adc_StatusProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Apc/NetworkTypes.hpp>

#include <Adc/ProvIds.hpp>


/*------------------------------------------------------------------
                            StatusProvider
 ------------------------------------------------------------------*/

class StatusProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        StatusProvider();
        virtual ~StatusProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);

        void Reset();

// this method sets an initial value for the concateneted sms   
        void SetMaxConcRefNo(UINT16 refno) { m_succ_16bit_conc_sms_ref_no = refno; }

// this methods are called by ASC therefore they are inline, used once
        void SetLastCcm(UINT32 last_ccm) { m_last_ccm= last_ccm; }
        void GetLastCcm(UINT32 &last_ccm) { last_ccm= m_last_ccm; }
        // for Line2 when using ALS
        void SetLastCcm2(UINT32 last_ccm) { m_last_ccm2= last_ccm; }
        // for Line2 when using ALS
        void GetLastCcm2(UINT32 &last_ccm) { last_ccm= m_last_ccm2; }
        void SetTimeZone(const TimeZone &timezone);
        void GetTimeZone(TimeZone &timezone);
        void GetLsaIdentifier(LsaIdentifier &lsaidentifier) { lsaidentifier = m_lsaidentifier; }
        void SetLsaIdentifier(const LsaIdentifier &lsaidentifier) { m_lsaidentifier = lsaidentifier; }
        void GetIsLsaIdentifierPresent(BOOLEAN & lsaidentifier) { lsaidentifier = m_islsaidentifierpresent; }
        void SetIsLsaIdentifierPresent(const BOOLEAN lsaidentifier) { m_islsaidentifierpresent = lsaidentifier; }
        void SetNetworkNameLong(const WString &network_name_long) { m_network_name_long = network_name_long; }
        void GetNetworkNameLong(WString &network_name_long) { network_name_long = m_network_name_long; }
        void SetNetworkNameShort(const WString &network_name_short) { m_network_name_short= network_name_short; }
        void GetNetworkNameShort(WString &network_name_short) { network_name_short= m_network_name_short; }
        void SetBatteryLoadLevel(const BatteryLoadLevel level) { m_battery_load = level; }
        void SetRegisterMode(const RegisterMode mode) { m_registration_mode = mode; }
        void SetRegisterStatus(const RegisterStatus status) { m_registration_state = status; }
        void SetRegisteredPlmn(const Plmn & plmn) { m_registered_plmn = plmn; }
        void SetRegisterRejectCause(const RegisterRejectCause rejectcause) { m_registration_reject_cause = rejectcause; }
        void SetSignalStrengthLevel(const SignalStrengthLevel signalstrength) { m_signal_strength = signalstrength; };
        void SetSignalQualityLevel(const SignalQualityLevel signalquality) {m_signal_quality = signalquality; }
        void SetGprsAttached(BOOLEAN gprs_attached) { m_gprs_attached = gprs_attached; }
        void SetLai(const Lai & lai) { m_lai = lai; }
        void SetCellId(const CellId & cellid) { m_cellid = cellid; }
        void SetGprsClass(const GprsClass gprs_class) { m_gprs_class = gprs_class; }
        void SetGprsClassChangeOrigin(const ProcessSource gprs_class_change_origin) { m_gprs_class_change_origin = gprs_class_change_origin; }
        void SetRadioAccessTechnology(const RadioAccessTechnology rat)  { m_rat = rat; }
        void SetRatChangeMode(const RatChangeMode mode) { m_rat_change_mode = mode; }
        void SetGsmBand(const GsmBand band) { m_gsm_band = band; }
        Plmn GetRegisteredPlmn() const { return m_registered_plmn; }
        void GetRegisteredPlmn(Plmn &plmn) { plmn = m_registered_plmn; }

        UINT16 GetRegisteredLac() const { return m_lai.lac; }


        BatteryLoadLevel GetBatteryLoadLevel(){return m_battery_load;}
        SignalStrengthLevel GetSignalStrengthLevel(){return m_signal_strength;}
        SignalQualityLevel GetSignalQualityLevel(){return m_signal_quality;}
        
        void SetSignalStrengthMax(const SignalStrengthMax signalstrength){m_signal_strength_max = signalstrength;}
        void SetSignalQualityMax(const SignalQualityMax signalquality){m_signal_quality_max = signalquality;}
        SignalStrengthMax GetSignalStrengthMax(){return m_signal_strength_max;}
        SignalQualityMax GetSignalQualityMax(){return m_signal_quality_max;}

        RadioAccessTechnology GetRadioAccessTechnology(){return m_rat;}
        RatChangeMode GetRatChangeMode(){return m_rat_change_mode;}
        GsmBand GetGsmBand(){return m_gsm_band;}

        // Get the calibration status of the eeprom
        void GetEepCalibrationStatus(BOOLEAN &eep_calibration_status);
        void SetPowerMode(PowerMode power_mode){m_power_mode = power_mode;}
        PowerMode GetPowerMode(){return m_power_mode;}

        void SetCfuServiceArray(const CfuServiceArray & servicearray) {
            m_cfu_servicearray = servicearray;
        }           
        const CfuServiceArray & GetCfuServiceArray() const {
            return m_cfu_servicearray;
        }
        
        void SetScanStatus(BOOLEAN scan_status){ m_scan_status = scan_status; }
        BOOLEAN GetScanStatus(){ return m_scan_status; }            
        
    private:
        RegisterMode         m_registration_mode;           // registration mode
        RegisterStatus       m_registration_state;          // registration state
        RegisterRejectCause  m_registration_reject_cause;   // registration reject  cause
        Plmn                 m_registered_plmn;             // registered plmn  
        SignalStrengthLevel  m_signal_strength;             // radio signal strength level
        SignalQualityLevel   m_signal_quality;              // radio signal quality level (only valid on active calls)
        SignalStrengthMax    m_signal_strength_max;             // maximum possible radio signal strength level
        SignalQualityMax     m_signal_quality_max;              // maximum possible radio signal quality level (only valid on active calls)

        BatteryLoadLevel     m_battery_load;                // battery  load level
        WString              m_network_name_long;           // network information long
        WString              m_network_name_short;          // network information short        
        BOOLEAN              m_gprs_attached;               // indicates if gprs service is attached
        INT                  m_tz_offset;                   // time zone offset from UT (GMT) in units of 15 minutes        
        UINT8                m_tz_dst;                      // daylight saving time (adjustment can be +1h of +2h)
        LsaIdentifier        m_lsaidentifier;               // LSA (Localized Service Area) Identifier (from MM_INFORMATION message, TS 24.008)
        BOOLEAN              m_islsaidentifierpresent;      // indicates, if LSA (Localized Service Area) Identifier is present
        UINT16               m_succ_16bit_conc_sms_ref_no;  // successive 16-bit reference counter for concatenated sms (should be stored permanent) 
        UINT32               m_last_ccm;                    // last current call meter of AOCI
        UINT32               m_last_ccm2;                   // last current call meter of AOCI for line 2 (ALS)
        Lai                  m_lai;                         // location area information
        CellId               m_cellid;                      // cell id from CellInfoIndArg
        GprsClass            m_gprs_class;                  // current active GPRS mobile class
        ProcessSource        m_gprs_class_change_origin;    // process source, which initiatiated last gprs class change
        RadioAccessTechnology m_rat;
        RatChangeMode           m_rat_change_mode;
        GsmBand                 m_gsm_band;

// these settings has to be implemented in NVRAM
        ClirMode             m_clir_mode;                   // Clir mode setting
        BOOLEAN              m_redialing_active;            // Redialing mode setting
        
// settings of eeprom       
        BOOLEAN             m_eep_calibration_status;       // Calibration status of eeprom
        PowerMode           m_power_mode;                   // current power mode
        GsmService          m_pref_service;
        CfuServiceArray     m_cfu_servicearray;             // CFU flags array, accessed via DataHandler
        BOOLEAN             m_scan_status;                  //Plmn-scan in progress


};

#endif

