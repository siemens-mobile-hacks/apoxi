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

#if !defined(Adc_SstProvider_hpp)
#define Adc_SstProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>

/*------------------------------------------------------------------
                            SstProvider
 ------------------------------------------------------------------*/

enum SstTableIndexes { 
    c_sst_chv1_disable_function     = 1,
    c_sst_adn                       = 2,
    c_sst_fdn                       = 3,
    c_sst_sms                       = 4,
    c_sst_aoc                       = 5,
    c_sst_ccp                       = 6,
    c_sst_plmn_sel                  = 7,
//  c_reserved
    c_sst_msisdn                    = 9,
    c_sst_ext1                      = 10,
    c_sst_ext2                      = 11,
    c_sst_sms_parameters            = 12,
    c_sst_lnd                       = 13,
    c_sst_cbmi                      = 14,
    c_sst_gil1                      = 15,
    c_sst_gil2                      = 16,
    c_sst_spn                       = 17,
    c_sst_sdn                       = 18,
    c_sst_ext3                      = 19,
//  c_reserved
    c_sst_vgcs_gil                  = 21,
    c_sst_vbs_gil                   = 22,
    c_sst_emlpp                     = 23,
    c_sst_emlpp_answer              = 24,
    c_sst_dwld_sms_cb               = 25,
    c_sst_dwld_sms_pp               = 26,
    c_sst_menu_selection            = 27,
    c_sst_call_control              = 28,
    c_sst_proactive_sim             = 29,
    c_sst_cbmi_ranges               = 30,
    c_sst_bdn                       = 31,
    c_sst_ext4                      = 32,
    c_sst_depers_control_keys       = 33,
    c_sst_coop_network_list         = 34,
    c_sst_sms_reports               = 35,
    c_sst_networkind_alerting       = 36,
    c_sst_mo_sm_sim                 = 37,
    c_sst_gprs                      = 38,
    c_sst_image                     = 39,
    c_sst_solsa                     = 40,
    c_sst_ussd_in_callcontrol       = 41,
    c_sst_run_at_command            = 42,
    c_sst_plmn_sel_access_tech      = 43,
    c_sst_oplmn_sel_access_tech     = 44,
    c_sst_hplmn_access_tech         = 45,
    c_sst_cpbcch_info               = 46,
    c_sst_investigation_scan        = 47,
    c_sst_eccp                      = 48,
    c_sst_mexe                      = 49,
//  c_sst_reserved                  = 50,
    c_sst_pnn                       = 51,
    c_sst_opl                       = 52,
    c_sst_mbdn                      = 53,
    c_sst_mwis                      = 54,
    c_sst_cfis                      = 55,
    c_sst_spdi                      = 56,
    c_sst_mms                       = 57,
    c_sst_ext8                      = 58,
    c_sst_mms_user_con_params       = 59
};

class SstProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        SstProvider();
        virtual ~SstProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        SimAuxHandler * m_aux_handler;
};

/*------------------------------------------------------------------
                            UstProvider
 ------------------------------------------------------------------*/

enum UstTableIndexes { 
    c_ust_local_pb                      = 1,
    c_ust_fdn_pb                        = 2,
    c_ust_ext2                          = 3,
    c_ust_sdn_pb                        = 4,
    c_ust_ext3                          = 5,
    c_ust_bdn_pb                        = 6,
    c_ust_ext4                          = 7,
    c_ust_out_call_info                 = 8,
    c_ust_in_call_info                  = 9,
    c_ust_sms                           = 10,
    c_ust_smsr                          = 11,
    c_ust_smsp                          = 12,
    c_ust_aoc                           = 13,
    c_ust_ccp                           = 14,
    c_ust_cbmi                          = 15,
    c_ust_cbmir                         = 16,
    c_ust_gid_level1                    = 17,
    c_ust_gid_level2                    = 18,
    c_ust_spn                           = 19,
    c_ust_plmnwact                      = 20,
    c_ust_msisdn                        = 21,
    c_ust_image                         = 22,
    c_ust_notused                       = 23,
    c_ust_emlpp                         = 24,
    c_ust_auto_emlpp                    = 25,
    c_ust_rfu                           = 26,
    c_ust_gsm_access                    = 27,
    c_ust_datadownload_smspp            = 28,
    c_ust_datadownload_smscb            = 29,
    c_ust_callcontrol_usim              = 30,
    c_ust_mosmscontrol_usim             = 31,
    c_ust_runat_command                 = 32,
    c_ust_set_to_1                      = 33,
    c_ust_est                           = 34,
    c_ust_acl                           = 35,
    c_ust_dck                           = 36,
    c_ust_coop_network_list             = 37,
    c_ust_gsm_security_context          = 38,
    c_ust_cpbcch_info                   = 39,
    c_ust_inv_scan                      = 40,
    c_ust_mexe                          = 41,
    c_ust_opcont_plmnwact               = 42,
    c_ust_hplmnwact                     = 43,
    c_ust_ext5                          = 44,
    c_ust_plmn_networkname              = 45,
    c_ust_op_plmnlist                   = 46,
    c_ust_mbdn                          = 47,
    c_ust_mwis                          = 48,
    c_ust_cfis                          = 49,
    c_ust_res                           = 50,
    c_ust_spdi                          = 51,
    c_ust_mms                           = 52,
    c_ust_ext8                          = 53,
    c_ust_callcontrol_gprs_usim         = 54,
    c_ust_mms_ucp                       = 55,
    c_ust_nia                           = 56,
    c_ust_vgcs                          = 57,
    c_ust_vbs                           = 58,
    c_ust_pseudonym                     = 59,
    c_ust_user_plmn_sel_wlan_access     = 60,
    c_ust_operator_plmn_sel_wlan_access = 61,
    c_ust_user_wsid_list                = 62,
    c_ust_operator_wsid_list            = 63,
    c_ust_vgcs_security                 = 64,
    c_ust_vbs_security                  = 65,
    c_ust_wlan_reauthentication         = 66,
    c_ust_mms_storage                   = 67,
    c_ust_generic_bootstrapping         = 68,
    c_ust_mbms_security                 = 69,
    c_ust_datadownload_ussd_appl        = 70,
    c_ust_equivalent_hplmn              = 71

};

#if defined(APOXI_ICC_USIM)

class UstProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        UstProvider();
        virtual ~UstProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        SimAuxHandler * m_aux_handler;
};

#endif

enum EstTableIndexes { 
    c_est_fdn                           = 1,
    c_est_bdn                           = 2,
    c_est_apn_acl                       = 3,

};

#if defined(APOXI_ICC_USIM)

class EstProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        EstProvider();
        virtual ~EstProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        SimAuxHandler * m_aux_handler;
};

#endif

/* SimServices is the module which allow checking if certain services on SIM are enabled or not.
It works independent if an SIM or USIM is inserted by checking the SST or UST/EST. New
enumerations have to be introduced as the enumeration of SST and UST are not compatible.*/

enum SimServiceId { 
    SimServiceChv1Disable,
    SimServiceAdn,
    SimServiceFdn,
    SimServiceBdn,
    SimServiceMsisdn,
    SimServiceLnd,
    SimServiceSms,
    SimServiceAoc,
    SimServicePrefPlmn,
    SimServicePlmnwAct,
    SimServiceSmsParameter,
    SimServiceSdn,
    SimServiceCbmi,
    SimServiceCbmiRanges,
    SimServiceSpn,
    SimServiceImages,
    SimServiceMexe,
    SimServicePnn,
    SimServiceOpl,
    SimServiceMbdn,
    SimServiceMwis,
    SimServiceCfis,
    SimServiceSpdi,
    
    SimServiceInvalid
};

class SimServices 
{
    public:
        SimServices();
        virtual ~SimServices();
        void Init(SimAuxHandler * aux_handler);
        BOOLEAN IsSimServiceEnabled(SimServiceId id, BOOLEAN & isenabled);

    private:
        SimAuxHandler * m_aux_handler;
};



#endif


