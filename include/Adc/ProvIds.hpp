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

#if !defined(Adc_ProvIds_hpp)
#define Adc_ProvIds_hpp

// ////////////////////////////////////////////////////////////////////////

#include <Auxiliary/Provider.hpp>



enum __Colid
{

/*------------------------------------------------------------------
                            Main Columns
 ------------------------------------------------------------------*/

c_start_provider_range          = 1000, // must be the base !!!

c_aux_provider_id               = 1000, 
c_adn_provider_id               = 1001,
c_msisdn_provider_id            = 1002,
c_lnd_provider_id               = 1003,
c_fdn_provider_id               = 1004,
c_prefplmn_provider_id          = 1005,
c_preflang_provider_id          = 1006,
c_status_provider_id            = 1007,
c_chv_provider_id               = 1008,
c_ecc_provider_id               = 1009,

c_sst_provider_id               = 1010,
c_simtk_mainmenu_provider_id    = 1011,
c_prefextlang_provider_id       = 1012,
c_sms_provider_id               = 1013,
c_sms_unread_provider_id        = 1014,
c_sms_sent_provider_id          = 1015,
c_sms_unsent_provider_id        = 1016,
c_sms_read_provider_id          = 1017,
c_sms_parameter_provider_id     = 1018,
c_sms_class0_provider_id        = 1019,

c_sms_count_provider_id         = 1020,
c_sms_message_provider_id       = 1021,
c_country_provider_id           = 1022,
c_plmn_provider_id              = 1023,
c_bdn_provider_id               = 1024,
c_sdn_provider_id               = 1025,
c_cphs_aux_provider_id          = 1026,
c_cphs_mbox_provider_id         = 1027,
c_cphs_costumer_prof_provider_id= 1028,
c_cphs_infono_provider_id       = 1029,

c_lock_provider_id              = 1030,
c_cbmi_provider_id              = 1031,
c_cbmi_range_provider_id        = 1032,
c_ust_provider_id               = 1033,
c_est_provider_id               = 1034,
c_cmi_provider_id               = 1035,
c_sms_base_inbox_provider_id    = 1036,
c_sms_base_outbox_provider_id   = 1037,
c_sms_base_archive_provider_id  = 1038,
c_sms_base_statusreport_provider_id  = 1039,

c_sms_base_unread_provider_id   = 1040,
c_prefextlang2_provider_id      = 1041,
c_mbdn_provider_id              = 1042,
c_mbi_provider_id               = 1043,

c_usimpb_groupname_provider_id  = 1044,
c_usimpb_addnumberstring_provider_id    = 1045,
c_usimpb_property_provider_id   = 1046,
c_usimpb_provider_id            = 1047,

c_end_provider_range,               // provider ids must be start at 1000 


/*------------------------------------------------------------------
                            Auxilary Columns
 ------------------------------------------------------------------*/
c_imsi_id                       = 1100,
c_mcc_id                        = 1101,
c_mnc_id                        = 1102,
c_sim_ind_id                    = 1103,
c_icc_id                        = 1104,
c_sim_type_id                   = 1105,
c_sim_phase_id                  = 1106,
c_lang_pref_id                  = 1107,
c_fdn_state_id                  = 1108,
c_spn_id                        = 1109,
c_spn_display_condition_id      = 1110,
c_acm_id                        = 1111,
c_acmmax_id                     = 1112,
c_currency_code_id              = 1113,
c_currency_exp_id               = 1114,
c_currency_eppu_id              = 1115,
c_imei_id                       = 1116,
c_sim_init_result_id            = 1117,
c_acm2_id                       = 1118,
c_ofm_to_be_activated_id        = 1119,

c_network_lockstate_id          = 1125,
c_sp_lockstate_id               = 1126,
c_sim_lockstate_id              = 1127,
c_corporate_lockstate_id        = 1128,
c_sim_errorcode_id              = 1129,

c_loci_update_status_id         = 1130,
c_loci_mcc_id                   = 1131,     
c_loci_mnc_id                   = 1132, 
c_loci_lac_id                   = 1133, 
c_loci_mnc_threedigits_id       = 1134, 

c_acm_chv_id                    = 1140,     
c_acmmax_chv_id                 = 1141,     
c_puct_chv_id                   = 1142,     
    
c_mnc_threedigits_id            = 1150,


/*------------------------------------------------------------------
                        Adn,Msisdn,Fdn,Lnd Columns
 ------------------------------------------------------------------*/
c_simpos_id                     = 1200,
c_phone_no_id                   = 1201,
c_name_id                       = 1202,
c_alphatagsize_id               = 1203,
c_tagsize_id                    = 1204,
c_nextfreeposition_id           = 1205,
c_freeextrecords_id             = 1206,

// only relevant for CPHS_INFNUM
c_index_level_id                = 1220,
c_nw_spec_id                    = 1221,
c_premium_serv_id               = 1222,

// only relevant for BDN
c_cmi_record_id                 = 1223,


/*------------------------------------------------------------------
                    CountryProvider Columns
 ------------------------------------------------------------------*/
//c_mcc_id                      = 1300,     // mobile country code // already defined
c_cc_id                         = 1301,     // international country code
c_country_shortname_id          = 1302,     // short name of country

/*------------------------------------------------------------------
                    PlmnProvider Columns
 ------------------------------------------------------------------*/
//c_mcc_id                      = 1400,     // mobile country code          // already defined
//c_cc_id                       = 1401,     // international country code   // already defined
//c_country_shortname_id        = 1402,     // short name of country        // already defined
//c_mnc_id                      = 1403,     // mobile network code          // already defined
c_plmn_name_id                  = 1404,     // name of plmn
c_plmn_shortname_id             = 1405,     // short name of plmn
c_networktype_id                = 1406,     // type of network (GSM900, GSM1800, GSM1900, ...)

/*------------------------------------------------------------------
                            Pref Plmn Columns
 ------------------------------------------------------------------*/
//c_mcc_id                      = 1500,     // mobile country code          // already defined
//c_mnc_id                      = 1501,     // international country code   // already defined
c_access_technology_id          = 1502,     // access technology identifier 
c_act_supported_id              = 1503,     // is access technology supported


/*------------------------------------------------------------------
            StatusProvider Columns (registration, battery, nitz, ...)
 ------------------------------------------------------------------*/
c_mode_id                       = 1600,     // registration mode (automatic vs. manual)
c_state_id                      = 1601,     // registration state (normal, limited, no service)
c_reject_cause_id               = 1602,     // registration reject cause (on last registration change)
//c_mcc_id                      = 1603,     // mobile country code of registered plmn
//c_mnc_id                      = 1604,     // international country code of registered plmn
//c_mnc_threedigits_id          = 1150, // has the mnc three digits
c_signal_strength_id            = 1605,     // radio signal strength level
c_signal_quality_id             = 1606,     // radio signal quality level (only valid on active calls)
c_battery_load_id               = 1607,     // battery load level
c_clir_mode_id                  = 1608,     // clir mode
c_redialing_active_id           = 1609,     // redialing active ?
c_gprs_class_id                 = 1610,     // current active GPRS mobile class
c_gprs_class_change_origin_id   = 1611,     // process source, which initiatiated last gprs class change
c_network_name_long_id          = 1612,     // Network Identifier Name Long of NITZ Signal
c_network_name_short_id         = 1613,     // Network Identifier Name Short of NITZ Signal
c_tz_offset_id                  = 1614,     // time zone offset from UT (GMT) in units of 15 minutes
c_tz_dst_id                     = 1615,     // daylight saving time (adjustment can be +1h of +2h)
c_gprs_available_id             = 1616,     // indicates if gprs is available
c_gprs_attached_id              = 1617,     // indicates the gprs attach-status
c_succ_16bit_conc_sms_ref_no    = 1620,     // successive 16-bit reference counter for concatenated sms (should be stored permanent) 
c_last_ccm_id                   = 1621,     // last current call meter of AOC
c_last_ccm2_id                  = 1622,     // last current call meter of AOC for Line2 ALS
c_lai_mcc_id                    = 1623,     // mobile country code of lai plmn
c_lai_mnc_id                    = 1624,     // international country code of lai plmn
c_lai_lac_id                    = 1625,     // lac of lai
c_rat_id                        = 1626,     // Radio Access Technology
c_gsm_band_id                   = 1627,     // GSM-Band (900, 900P, 900E, 1800, ....)
c_rat_change_mode_id            = 1628,     // RAT Change Mode
c_eep_calibration_status_id     = 1629,     // calibration status of the eeprom
c_pref_service_id               = 1630,     // pref GsmService CS or PS, CS Paging active = CS, CS Paging deactive = PS
c_signal_strength_max_id        = 1631,     // radio signal strength level
c_signal_quality_max_id         = 1632,     // radio signal quality level (only valid on active calls)
c_cellid_id                     = 1633,     // cell id 

/*------------------------------------------------------------------
                            Pref Lang Columns
 ------------------------------------------------------------------*/
//c_lang_pref_id                = 1700,

/*------------------------------------------------------------------
                            Pref Ext Lang Columns
 ------------------------------------------------------------------*/
c_ext_lang_pref_id              = 1701,

/*------------------------------------------------------------------
                            Sms Columns
 ------------------------------------------------------------------*/
c_sms_string_id                 = 1800,
c_sms_phonenumber_id            = 1801,
c_sms_date_id                   = 1802,
c_sms_time_id                   = 1803,
c_sms_msg_class_id              = 1804,
c_sms_pdu_data_id               = 1805,
c_sms_status_id                 = 1807,
c_sms_recno_id                  = 1808,
c_sms_msg_type_id               = 1809,
c_sms_coding_group_id           = 1810,
c_sms_dcs_id                    = 1811,
c_sms_message_status_id         = 1812,
c_sms_datetime_id               = 1813,
c_sms_conc_status_id            = 1814,
c_sms_refno_id                  = 1815,
c_sms_compound_sms_id           = 1816,
c_sms_storage_media_id          = 1817,
c_sms_compound_tpdu_id          = 1818,
c_sms_protid_id                 = 1819,
c_sms_sca_id                    = 1820,
c_sms_reply_path_flag_id        = 1821,
c_sms_header_text_id            = 1822,

c_sms_conc_ref_no_id            = 1830,
c_sms_conc_max_no_id            = 1831,
c_sms_conc_seq_no_id            = 1832,

c_sms_pos_id                    = 1833,
c_sms_conc_tpdu_num_id          = 1834, 
c_sms_no_pdu_sim_id             = 1835, 
c_sms_no_pdu_flash_id           = 1836, 
c_sms_alpha_id                  = 1837,
c_sms_extended_data_id          = 1838,

c_sms_debugstring_id            = 1840,

/*------------------------------------------------------------------
                        Sms Count Columns
 ------------------------------------------------------------------*/
c_sms_sum_id                    = 1850,
c_sms_free_pdu_id               = 1851,
c_sms_tpdu_capacity_id          = 1852,
c_sms_tpdu_occupied_id          = 1853,
c_sms_tpdu_empty_id             = 1854,
c_sms_unread_count_id           = 1855,
c_sms_read_count_id             = 1856,
c_sms_unsent_count_id           = 1857,
c_sms_sent_count_id             = 1858,

/*------------------------------------------------------------------
                        Sms Message Columns
 ------------------------------------------------------------------*/
c_msg_ind_level_id              = 1880,
c_msg_count_id                  = 1881,
c_msg_ind_setting_id            = 1882,
c_msg_ind_sms_type_id           = 1883,
c_msg_update_id                 = 1884,
c_msg_position_id               = 1885,

/*------------------------------------------------------------------
                        ChvProvider Columns
 ------------------------------------------------------------------*/
c_no_id                         = 1900,     // cardholder verification (chv) number (type AdcChvNo)
//c_state_id                    = 1901,     // state of chv (type AdcChvStatus)
c_attempts_left_id              = 1902,     // attemts left to verify chv
c_unblocking_attempts_left_id   = 1903,     // attemts left to verify unblocking code of chv

/*------------------------------------------------------------------
                        EccProvider Columns
 ------------------------------------------------------------------*/
c_ecc_id                        = 2000,     // ecc number as wstring
c_ecc_alpha_id                  = 2001,     // alpha id (USIM)  
c_ecc_category_id               = 2002,     // category byte 
c_ecc_source_id                 = 2003,     // the source of the ECC 
c_ecc_phonenumber_id            = 2004,     // ECC as a phonenumber
c_ecc_sim_network_cnt_id        = 2005,     // summary of sim and network ECCs

/*------------------------------------------------------------------
                        SstProvider Columns
 ------------------------------------------------------------------*/
c_service_allocated_id          = 2100,
c_service_activated_id          = 2101,

/*------------------------------------------------------------------
                        SimTkMainMenuProvider Columns
 ------------------------------------------------------------------*/

c_options_id                    = 2200,
c_title_id                      = 2201,
c_title_icon_id                 = 2202,
c_title_icon_isselfexp_id       = 2203,
c_item_id                       = 2204,
c_next_action_id                = 2205,
c_icon_id                       = 2206,
c_item_string_id                = 2207,
c_icon_isselfexp_id             = 2208,

/*------------------------------------------------------------------
                        Sms Parameter Provider
 ------------------------------------------------------------------*/

c_service_center_address_id     = 2220,
c_destination_address_id        = 2221,
c_protocol_identifier_id        = 2222,
c_data_coding_scheme_id         = 2223,
c_validity_period_id            = 2224,
c_sms_param_name_id             = 2225,
c_smsp_alpha_id_len_id          = 2226,

/*------------------------------------------------------------------
                        Cphs Auxiliary provider
 ------------------------------------------------------------------*/

c_cphs_phase_id                 = 2300,      
c_infnrs_activated_id           = 2301,    
c_infnrs_allocated_id           = 2302,   
c_csp_activated_id              = 2303, 
c_csp_allocated_id              = 2304, 
c_sst_activated_id              = 2305, 
c_sst_allocated_id              = 2306, 
c_mboxnrs_activated_id          = 2307,  
c_mboxnrs_allocated_id          = 2308, 
c_opname_activated_id           = 2309,   
c_opname_allocated_id           = 2310,   

c_operator_name_id              = 2315, 
c_operator_shortname_id         = 2316, 
c_msg_wait_ind_line1_id         = 2317, 
c_msg_wait_ind_line2_id         = 2318, 
c_msg_wait_ind_fax_id           = 2319,
c_msg_wait_ind_data_id          = 2320,
c_call_fwd_line1_id             = 2321,
c_call_fwd_line2_id             = 2322,
c_call_fwd_fax_id               = 2323,   
c_call_fwd_data_id              = 2324,   

c_line_in_use_id                = 2330,   
c_line_is_locked_id             = 2331,   
c_cphs_is_present_id            = 2332,   
c_orange_welcome_msg_id         = 2333,   


/*------------------------------------------------------------------
                        Cphs Customer Service Profile provider
 ------------------------------------------------------------------*/

c_serv_cfu_id                   = 2400,      
c_serv_cfb_id                   = 2401,
c_serv_cfnry_id                 = 2402,
c_serv_cfnrc_id                 = 2403,
c_serv_ct_id                    = 2404,
c_serv_boac_id                  = 2405,
c_serv_boic_id                  = 2406,
c_serv_boic_exhc_id             = 2407,
c_serv_baic_id                  = 2408,
c_serv_bic_roam_id              = 2409,
c_serv_mpty_id                  = 2410,
c_serv_cug_id                   = 2411,
c_serv_aoc_id                   = 2412,
c_serv_pref_cug_id              = 2413,
c_serv_cug_oa_id                = 2414,
c_serv_hold_id                  = 2415,
c_serv_cw_id                    = 2416,
c_serv_ccbs_id                  = 2417,
c_serv_usr_usr_sig_id           = 2418,
c_serv_sm_mt_id                 = 2419,
c_serv_sm_mo_id                 = 2420,
c_serv_sm_cb_id                 = 2421,
c_serv_repl_path_id             = 2422,
c_serv_del_conf_id              = 2423,
c_serv_protid_id                = 2424,
c_serv_val_per_id               = 2425,
c_serv_als_id                   = 2426,
c_serv_clip_id                  = 2427,
c_serv_co_lr_id                 = 2428,
c_serv_co_lp_id                 = 2429,
c_serv_mci_id                   = 2430,
c_serv_cli_send_id              = 2431,
c_serv_cli_block_id             = 2432,
c_serv_gprs_id                  = 2433,
c_serv_hscsd_id                 = 2434,
c_serv_vgrp_call_id             = 2435,
c_serv_voice_bcst_serv_id       = 2436,
c_serv_mtpl_subs_pfl_id         = 2437,
c_serv_mtpl_band_id             = 2438,
c_serv_plmn_mode_id             = 2439,
c_serv_vps_id                   = 2440,
c_serv_smmo_paging_id           = 2441,
c_serv_smmo_email_id            = 2442,
c_serv_fax_id                   = 2443,
c_serv_data_id                  = 2444,
c_serv_language_id              = 2445,
c_serv_info_numbers_id          = 2446,

/*------------------------------------------------------------------
                        Lock provider
 ------------------------------------------------------------------*/

c_no_locks_id                   = 2500,      
c_no_files                      = 2501,    
c_cause_id                      = 2502,   
c_result_id                     = 2503, 
c_lock_type_id                  = 2504, 
c_lock_status_id                = 2505, 
c_lock_result_id                = 2506, 
c_lock_dcp_sup_id               = 2507,  
c_lock_retrial_method_id        = 2508, 
c_lock_retrial_count_id         = 2509,   
c_lock_time_id                  = 2510,   
c_lock_order_id                 = 2511,
c_unlock_startup                = 2512,
c_unlock_menubased              = 2513,
c_unlock_keybased               = 2514,

/*------------------------------------------------------------------
                        Cbmi provider
 ------------------------------------------------------------------*/

c_cbmi_id                       = 2600,      

/*------------------------------------------------------------------
                        Cbmi range provider
 ------------------------------------------------------------------*/

c_cbmi_range_low_id             = 2700,      
c_cbmi_range_high_id            = 2701,      


/*------------------------------------------------------------------
                        UstProvider Columns
 ------------------------------------------------------------------*/
c_service_available_id          = 2800,     // (USIM)

/*------------------------------------------------------------------
                        EstProvider Columns
 ------------------------------------------------------------------*/
//c_service_activated_id        = 2801,     // (USIM)   // already defined

/*------------------------------------------------------------------
                        CmiProvider Columns
 ------------------------------------------------------------------*/
c_cmi_alpha_id                  = 2900, 
c_cmi_id                        = 2901, 

/*------------------------------------------------------------------
                        MbiProvider Columns
 ------------------------------------------------------------------*/
c_mdni_voicemail_id             = 2910,
c_mdni_fax_id                   = 2911,
c_mdni_electronic_mail_id       = 2912,
c_mdni_other_id                 = 2913,
c_mdni_videomail_id             = 2914,

/*------------------------------------------------------------------
                    UsimPbXasProvider Columns
    used with c_usimpb_groupname_provider_id
    used with c_usimpb_addnumberstring_provider_id
 ------------------------------------------------------------------*/
//c_name_id                     = 1202,


/*------------------------------------------------------------------
                    UsimPbProvider Columns
 ------------------------------------------------------------------*/

//c_simpos_id                   = 1200,
//c_phone_no_id                 = 1201,
//c_name_id                     = 1202,
//c_alphatagsize_id             = 1203,
//c_tagsize_id                  = 1204,
//c_nextfreeposition_id         = 1205,
c_group_id                      = 3000, // used range 3000..3019
c_group_id_end                  = 3019, 
c_anr_id                        = 3020, // used range 3020..3039
c_anr_id_end                    = 3039, 
c_aas_id                        = 3040, // used range 3040..3059
c_aas_id_end                    = 3059, 
c_add_name_id                   = 3060, // used range 3060..3079
c_add_name_id_end               = 3079, 
c_email_adr_id                  = 3080, // used range 3080..3099
c_email_adr_id_end              = 3099, // used range 3080..3099
c_uid_id                        = 3100, 
c_hidden_info_id                = 3101,
c_slice_id                      = 3102,


/*------------------------------------------------------------------
                    UsimPbPropertyProvider Columns
 ------------------------------------------------------------------*/

c_total_rec_id                  = 3200,
c_max_rec_id                    = 3201,
c_first_rec_id                  = 3202,
c_last_rec_id                   = 3203,
//c_alphatagsize_id             = 3204,
c_max_group_columns_id          = 3205,
c_gas_size_id                   = 3206,
c_gas_max_rec_id                = 3207,
c_aas_size_id                   = 3208,
c_aas_max_rec_id                = 3209,
c_sync_supported_id             = 3210,
c_hiddenkey_supported_id        = 3211,
c_max_email_adr_columns_id      = 3212,
c_max_add_name_columns_id       = 3213,
c_max_anr_columns_id            = 3214,
c_is_free_ext_id                = 3220,
c_add_name_size_id              = 3300, // used range 3300..3319
c_email_adr_size_id             = 3320, // used range 3020..3039
c_is_free_anr_id                = 3340, // used range 3040..3059
c_is_free_add_name_id           = 3360, // used range 3060..3079
c_is_free_email_adr_id          = 3380, // used range 3080..3099


/*------------------------------------------------------------------
                        end of enumvalues
 ------------------------------------------------------------------*/


c_dummy                         = c_invalid_colid

};


typedef __Colid ProviderId;


#endif

