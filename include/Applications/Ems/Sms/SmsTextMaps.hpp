/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.     
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.    
   Passing on and copying of this document, use and communication of its   
   contents is not permitted without prior written authorisation.          
   ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsTextMaps_hpp)
#define Mmi_SmsTextMaps_hpp

#include <Common/EnumTextMap.hpp>

class SmsTelematicDeviceNameTable : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetDeviceName(ProtocolIdentifier::TelematicDevice device) { 
            return Base::GetText(m_devices, m_devices_size, device); }

    private:
        static const UINT m_devices_size;
        static const EnumTextTableEntry m_devices[];    
};

class SmsResultTextMap : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetResult(Sms::Result result) { return Base::GetText(m_results, m_results_size, (INT)result); }

    private:
        static const UINT m_results_size;
        static const EnumTextTableEntry m_results[];    
};

class SmsStatusReportTextMap : public EnumTextMap 
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetStatus(ShortMessageStatus::Status state) { return Base::GetText(m_states, m_states_size, (INT)state); }
        static const WCHAR* GetReason(ShortMessageStatus::Reason reason) { return Base::GetText(m_reasons, m_reasons_size, (INT)reason); }

    private:
        static const UINT m_states_size;
        static const UINT m_reasons_size;
        static const EnumTextTableEntry m_states[];
        static const EnumTextTableEntry m_reasons[];
    
};

class SmsTemplateTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetTemplateTitle(INT index) { return Base::GetText(m_template_titles, m_template_count, index); }
        static const WCHAR* GetTemplateText(INT index) { return Base::GetText(m_templates, m_template_count, index); }
        static UINT GetTemplateCount() { return m_template_count; }

    private:
        static const UINT m_template_count;
        static const EnumTextTableEntry m_templates[];
        static const EnumTextTableEntry m_template_titles[];
};

class SmsStorageTypeTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetStorageTypeName(INT index) { return Base::GetText(m_storage_types, m_storage_type_count, index); }
        static UINT GetStorageTypeCount() { return m_storage_type_count; }

    private:
        static const UINT m_storage_type_count;
        static const EnumTextTableEntry m_storage_types[];
};

class SmsGsmServiceTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetGsmServiceName(INT index) { return Base::GetText(m_gsm_services, m_gsm_service_count, index); }
        static UINT GetGsmServiceCount() { return m_gsm_service_count; }

    private:
        static const UINT m_gsm_service_count;
        static const EnumTextTableEntry m_gsm_services[];
};

class SmsMsgTypeTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetMsgTypeName(INT index) { return Base::GetText(m_msg_types, m_msg_type_count, index); }
        static UINT GetMsgTypeCount() { return m_msg_type_count; }

    private:
        static const UINT m_msg_type_count;
        static const EnumTextTableEntry m_msg_types[];
};

class SmsMsgTypeUsageTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetMsgTypeUsageName(INT index) { return Base::GetText(m_msg_type_usages, m_msg_type_usage_count, index); }
        static UINT GetMsgTypeUsageCount() { return m_msg_type_usage_count; }

    private:
        static const UINT m_msg_type_usage_count;
        static const EnumTextTableEntry m_msg_type_usages[];
};

class SmsStatusTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetStatusName(INT index) { return Base::GetText(m_stati, m_status_count, index); }
        static UINT GetStatusCount() { return m_status_count; }

    private:
        static const UINT m_status_count;
        static const EnumTextTableEntry m_stati[];
};

class SmsConcatStatusTextMap : public EnumTextMap
{
    typedef EnumTextMap Base;

    public:
        static const WCHAR* GetStatusName(INT index) { return Base::GetText(m_stati, m_status_count, index); }
        static UINT GetStatusCount() { return m_status_count; }

    private:
        static const UINT m_status_count;
        static const EnumTextTableEntry m_stati[];
};

#endif  //Mmi_SmsTextMaps_hpp

