/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.     
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.    
   Passing on and copying of this document, use and communication of its   
   contents is not permitted without prior written authorisation.          
   ------------------------------------------------------------------------ */

#if !defined(Mmi_DataConnTextMaps_hpp)
#define Mmi_DataConnTextMaps_hpp

#include <Asc/PdpContext.hpp>
#include <Socket/DataConnProfile.hpp>
#include <Kernel/Types.hpp>
#include <Common/EnumTextMap.hpp>
#include <DataConn/DataConnApp.hpp>


typedef PdpContext::QualityOfService QoS;
typedef PdpContext::Authentication::Type AuthType;

class DataConnCommonSettingsTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetSetting(DataConnApp::BasicSettingsTypeId setting) { 
            return Base::GetText(m_common_settings, m_common_settings_size, setting); }

    private:
        static const UINT m_common_settings_size;
        static const EnumTextTableEntry m_common_settings[];    
};

class CsdSettingsTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetSetting(DataConnApp::CsdSettingsTypeId setting) { 
            return Base::GetText(m_csd_settings, m_csd_settings_size, setting); }

    private:
        static const UINT m_csd_settings_size;
        static const EnumTextTableEntry m_csd_settings[];   
};

#if !defined(DATA_CONN_APP_EXCLUDE_SERIAL)
class SerSettingsTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetSetting(DataConnApp::SerSettingsTypeId setting) { 
            return Base::GetText(m_ser_settings, m_ser_settings_size, setting); }

    private:
        static const UINT m_ser_settings_size;
        static const EnumTextTableEntry m_ser_settings[];   
};
#endif

class PsdSettingsTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:

        static const WCHAR* GetSetting(DataConnApp::PsdSettingsTypeId setting) { 
            return Base::GetText(m_psd_settings, m_psd_settings_size, setting); }

    private:
        static const UINT m_psd_settings_size;
        static const EnumTextTableEntry m_psd_settings[];   
};

class PdpQoSReliabilityTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static QoS::Reliability GetQoSType(INT idx) { return (QoS::Reliability) m_qos[idx].code; }
        static const WCHAR* GetQoS(QoS::Reliability qos_reliability) { 
            return Base::GetText(m_qos, m_size, qos_reliability); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_qos[];    
};

class PdpQoSDelayTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static QoS::Delay GetQoSType(INT idx) { return (QoS::Delay) m_qos[idx].code; }
        static const WCHAR* GetQoS(QoS::Delay qos_delay) { 
            return Base::GetText(m_qos, m_size, qos_delay); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_qos[];    
};

class PdpQoSPrecedenceTable : public EnumTextMap 
{
    typedef EnumTextMap Base;
    
    public:
        static const UINT GetSize() { return m_size; }
        static QoS::Precedence GetQoSType(INT idx) { return (QoS::Precedence) m_qos[idx].code; }
        static const WCHAR* GetQoS(QoS::Precedence qos_precedence) { 
            return Base::GetText(m_qos, m_size, qos_precedence); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_qos[];    
};

class PdpQoSMeanRateTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static QoS::MeanRate GetQoSType(INT idx) { return (QoS::MeanRate) m_qos[idx].code; }
        static const WCHAR* GetQoS(PdpContext::QualityOfService::MeanRate qos_mean_rate) { 
            return Base::GetText(m_qos, m_size, qos_mean_rate); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_qos[];    
};

class PdpQoSPeakRateTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static QoS::PeakRate GetQoSType(INT idx) { return (QoS::PeakRate) m_qos[idx].code; }
        static const WCHAR* GetQoS(PdpContext::QualityOfService::PeakRate qos_peak_rate) { 
            return Base::GetText(m_qos, m_size, qos_peak_rate); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_qos[];    
};

class PdpAuthTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static AuthType GetAuthType(INT idx) { return (AuthType) m_auth[idx].code; }
        static const WCHAR* GetAuthentication(AuthType auth_type) { 
            return Base::GetText(m_auth, m_size, auth_type); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_auth[];   
};

class DataRateTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static CsdDataConnProfile::DataRate GetDataRateType(INT idx) { return (CsdDataConnProfile::DataRate) m_data_rate[idx].code; }
        static const WCHAR* GetDataRate(CsdDataConnProfile::DataRate data_rate) { 
            return Base::GetText(m_data_rate, m_size, data_rate); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_data_rate[];  
};

class CallTypeTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const UINT GetSize() { return m_size; }
        static const WCHAR* GetCallType(CsdDataConnProfile::CallType call_type) { 
            return Base::GetText(m_call_type, m_size, call_type); }

    private:
        static const UINT m_size;
        static const EnumTextTableEntry m_call_type[];  
};

#endif  //Mmi_DataConnTextMaps_hpp

