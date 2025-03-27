/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(AddOns_Translation_EnumTranslationTable_hpp)
#define AddOns_Translation_EnumTranslationTable_hpp

#include <AddOns/Translation/ValueTextMap.hpp>

class EnumTranslationTable {
    public:
        static const ValueTextMap::Table* HandlerId() { return (m_handler_id); }
        static const ValueTextMap::Table* ChvNo() { return (m_chv_no); }
        static const ValueTextMap::Table* ChvStatus() { return (m_chv_status); }
        static const ValueTextMap::Table* RegisterStatus() { return (m_register_status); }
        static const ValueTextMap::Table* RegisterRejectCause() { return (m_register_reject_cause); }
        static const ValueTextMap::Table* AudioToneToneType() { return (m_audio_tone_tone_type); }
        static const ValueTextMap::Table* CallApiRc() { return (m_call_api_rc); }
        static const ValueTextMap::Table* CallErrorCause() { return (m_call_error_cause); }
        static const ValueTextMap::Table* SmsResult() { return (m_sms_result); }
        static const ValueTextMap::Table* SmsWarningLevel() { return (m_sms_warning_level); }
        static const ValueTextMap::Table* MessageClass() { return (m_dcs_message_class); }
        static const ValueTextMap::Table* TpduStatus() { return (m_tpdu_status); }
        static const ValueTextMap::Table* MessageTypeIndicator() { return (m_message_type_indicator); }
        static const ValueTextMap::Table* DcsGroupId() { return (m_dcs_group_id); }
        static const ValueTextMap::Table* SmsStorageType() { return (m_sms_storage_type); }
        static const ValueTextMap::Table* MessageStatus() { return (m_message_status); }
        static const ValueTextMap::Table* MessageResultReason() { return (m_message_result_reason); }
        static const ValueTextMap::Table* SimIndicator() { return (m_sim_indicator); }
        static const ValueTextMap::Table* SsErrorCode() { return (m_ss_error_code); }
        static const ValueTextMap::Table* Alphabet() { return (m_alphabet); }
        static const ValueTextMap::Table* Compression() { return (m_compression); }
        static const ValueTextMap::Table* WaitingMessageIndication() { return (m_waiting_message_indication); }
        static const ValueTextMap::Table* WaitingMessage() { return (m_waiting_message); }
        static const ValueTextMap::Table* PidInterworking() { return (m_interworking); }
        static const ValueTextMap::Table* TelematicDevice() { return (m_telematic_device); }
        static const ValueTextMap::Table* MessageType() { return (m_message_type); }
        static const ValueTextMap::Table* ValidityPeriodFormat() { return (m_validity_period_format); }
        static const ValueTextMap::Table* PdpContextManagerState() { return (m_pdp_context_manager_state); }
        static const ValueTextMap::Table* PdpContextErrorCause() { return (m_pdp_context_error_cause); }
        static const ValueTextMap::Table* PdpContextOrigin() { return (m_pdp_context_origin); }
        static const ValueTextMap::Table* PdpContextState() { return (m_pdp_context_state); }
        static const ValueTextMap::Table* AocChargingStatus() { return (m_aoc_charging_status); }
        static const ValueTextMap::Table* CallRelatedSsCode() { return (m_call_related_ss_code); }
        static const ValueTextMap::Table* SsOperationCode() { return (m_ss_operation_code); }
        static const ValueTextMap::Table* ServiceGroup() { return (m_service_group); }
        static const ValueTextMap::Table* ProblemCode() { return (m_problem_code); }
        static const ValueTextMap::Table* ProblemTag() { return (m_problem_tag); }
        static const ValueTextMap::Table* SecLockResult() { return (m_sec_lock_result); }
        static const ValueTextMap::Table* SsBaseHandlerReturnCode() { return (m_ss_base_hdl_rc); }
    
    #if defined(APOXI_LIB_ADDON_VR)

        static const ValueTextMap::Table* VrHandlerVrCommand() { return (m_vr_command); }
        static const ValueTextMap::Table* VrErrorCode() { return (m_vr_error_code); }
        static const ValueTextMap::Table* VrWarningCode() { return (m_vr_warning_code); }
    #endif
    
    private:
        static const ValueTextMap::Table m_handler_id[];
        static const ValueTextMap::Table m_chv_no[];
        static const ValueTextMap::Table m_chv_status[];
        static const ValueTextMap::Table m_register_status[];
        static const ValueTextMap::Table m_register_reject_cause[];
        static const ValueTextMap::Table m_audio_tone_tone_type[];
        static const ValueTextMap::Table m_call_api_rc[];
        static const ValueTextMap::Table m_call_error_cause[];
        static const ValueTextMap::Table m_sms_result[];
        static const ValueTextMap::Table m_sms_warning_level[];
        static const ValueTextMap::Table m_dcs_message_class[];
        static const ValueTextMap::Table m_tpdu_status[];
        static const ValueTextMap::Table m_message_type_indicator[];
        static const ValueTextMap::Table m_dcs_group_id[];
        static const ValueTextMap::Table m_sms_storage_type[];
        static const ValueTextMap::Table m_message_status[];
        static const ValueTextMap::Table m_message_result_reason[];
        static const ValueTextMap::Table m_sim_indicator[];
        static const ValueTextMap::Table m_ss_error_code[];
        static const ValueTextMap::Table m_alphabet[];
        static const ValueTextMap::Table m_compression[];
        static const ValueTextMap::Table m_waiting_message_indication[];
        static const ValueTextMap::Table m_waiting_message[];
        static const ValueTextMap::Table m_interworking[];
        static const ValueTextMap::Table m_telematic_device[];
        static const ValueTextMap::Table m_message_type[];
        static const ValueTextMap::Table m_validity_period_format[];
        static const ValueTextMap::Table m_pdp_context_manager_state[];
        static const ValueTextMap::Table m_pdp_context_error_cause[];
        static const ValueTextMap::Table m_pdp_context_origin[];
        static const ValueTextMap::Table m_pdp_context_state[];
        static const ValueTextMap::Table m_aoc_charging_status[];
        static const ValueTextMap::Table m_call_related_ss_code[];
        static const ValueTextMap::Table m_ss_operation_code[];
        static const ValueTextMap::Table m_service_group[];
        static const ValueTextMap::Table m_problem_tag[];
        static const ValueTextMap::Table m_problem_code[];
        static const ValueTextMap::Table m_sec_lock_result[];
        static const ValueTextMap::Table m_ss_base_hdl_rc[];
    #if defined(APOXI_LIB_ADDON_VR)
        static const ValueTextMap::Table m_vr_command[];
        static const ValueTextMap::Table m_vr_error_code[];
        static const ValueTextMap::Table m_vr_warning_code[];
    #endif
};

#define EnumTr(enum_translation_table, enum_value) \
    ValueTextMap(EnumTranslationTable::enum_translation_table()).GetText(enum_value)

#endif  // AddOns_Translation_EnumTranslationTable_hpp

