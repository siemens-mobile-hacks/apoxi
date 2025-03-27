/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SimTkTypes_hpp)
#define Apc_SimTkTypes_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>

#include <Apc/SignalTypes.hpp>
#include <Apc/SimDataTypes.hpp>


/*  ========================================================================
                            Sim Toolkit Enums
    ========================================================================*/
// sim toolkit proactive cause (ms.h: T_MI_PROACTIVE_CAUSE)
enum ProactiveCause {
    // causes indicate, that command has been performed
    SimTkSuccessful                                                = 0x00ff,
    CommandPerformedWithPartialComprehension                       = 0x01ff,
    CommandPerformedWithMissingInformation                         = 0x02ff,
    RefreshPerformedWithAdditionalEFsRead                          = 0x03ff,
    SuccessfulButIconNotDisplayed                                  = 0x04ff,
    CommandPerformedWithButModifiedByCallControlBySim              = 0x05ff,
    CommandPerformedSuccessfullyLimitedService                     = 0x06ff,
    CommandPerformedWithModification                               = 0x07ff,
    TerminateByUser                                                = 0x10ff,
    BackwardMove                                                   = 0x11ff,
    NoResponse                                                     = 0x12ff,
    HelpInfo                                                       = 0x13ff,
    UssdOrSsTransactionTerminatedByUser                            = 0x14ff,

    // causes indicate, that it may be worth re-trying the command at later opportunity
    CurrentlyUnable                                                = 0x2000,
    ScreenBusy                                                     = 0x2001,
    BusyOnCall                                                     = 0x2002,
    MeCurrentlyUnableBusyOnSsTransaction                           = 0x2003,
    MeCurrentlyUnableNoService                                     = 0x2004,
    MeCurrentlyUnableAccessControlClassBar                         = 0x2005,
    MeCurrentlyUnableRadioResourceNotGranted                       = 0x2006,
    MeCurrentlyUnableNotInSpeechCall                               = 0x2007,
    MeCurrentlyUnableBusyOnUssdTransaction                         = 0x2008,
    MeCurrentlyUnableBusyOnSendDtmfCommand                         = 0x2009,
    NetworkCurrentlyUnableToProcessCommand                         = 0x2100,
    UserDidNotAcceptCallSetupRequest                               = 0x22ff,
    UserClearedDownCallBeforeConnectionOrNetworkRelease            = 0x23ff,
    ActionInContradictionWithTheCurrentTimerState                  = 0x24ff,
    InteractionWithCallControlBySimTemporaryProblem                = 0x25ff,
    LaunchBrowserError                                             = 0x2600,
    LaunchBrowserBearerUnavailable                                 = 0x2601,
    LaunchBrowserBrowserUnavailable                                = 0x2602,
    LaunchBrowserMeUnableToReadProvisioningData                    = 0x2603,

    // causes indicate, that's not worth re-trying with an identical command
    CommandBeyondCapability                                        = 0x30ff,
    CommandTypeNotUnderstoodByMe                                   = 0x31ff,
    CommandDataNotUnderstoodByMe                                   = 0x32ff,
    CommandNumberNotKnownByMe                                      = 0x33ff,
    SsReturnError                                                  = 0x3400,
    SmsRpError                                                     = 0x3500,
    RequiredValuesAreMissing                                       = 0x36ff,
    UssdReturnError                                                = 0x3700,
    MultipleCardCommandsError                                      = 0x3800,
    MultipleCardCommandsErrorCardReaderRemovedOrNotPresent         = 0x3801,
    MultipleCardCommandsErrorCardRemovedOrNotPresent               = 0x3802,
    MultipleCardCommandsErrorCardReaderBusy                        = 0x3803,
    MultipleCardCommandsErrorCardPoweredOff                        = 0x3804,
    MultipleCardCommandsErrorCApduFormatError                      = 0x3805,
    MultipleCardCommandsErrorMuteCard                              = 0x3806,
    MultipleCardCommandsErrorTransmissionError                     = 0x3807,
    MultipleCardCommandsErrorProtocolNotSupported                  = 0x3808,
    MultipleCardCommandsErrorSpecifiedReaderNotValid               = 0x3808,
    CallControlMoSmsControlPermanentProblem                        = 0x3900,
    CallControlMoSmsControlPermanentProblemActionNotAllowed        = 0x3901,
    CallControlMoSmsControlPermanentProblemTypeOfRequestChanged    = 0x3902,
    BearerIndependentProtocolError                                 = 0x3a00,
    BearerIndependentProtocolErrorNoChannelAvailable               = 0x3a01,
    BearerIndependentProtocolErrorChannelClosed                    = 0x3a02,
    BearerIndependentProtocolErrorChannelIdentifierNotValid        = 0x3a03,
    BearerIndependentProtocolErrorRequestedBufferSizeNotAvailable  = 0x3a03,
};

enum SimKey {
    SimKeyInvalid = -1,
    SimKeyYes = 1,
    SimKeyNo = 0
};

// sim toolkit proactive cause (ms.h: T_MI_PROACTIVE_CAUSE)
enum ElementaryFilePos {
    AcmEfPos      = SIMI_EF_ACM_POS,
    AcmMaxEfPos   = SIMI_EF_ACMMAX_POS,
    AdnEfPos      = SIMI_EF_ADN_POS,
    FdnEfPos      = SIMI_EF_FDN_POS,
    LndEfPos      = SIMI_EF_LND_POS,
    MsisdnEfPos   = SIMI_EF_MSISDN_POS,
    PhaseEfPos    = SIMI_EF_PHASE_POS,
    PuctEfPos     = SIMI_EF_PUCT_POS,
    SmsEfPos      = SIMI_EF_SMS_POS,
    SmspEfPos     = SIMI_EF_SMSP_POS,
    SmssEfPos     = SIMI_EF_SMSS_POS,
    SstEfPos      = SIMI_EF_SST_POS,
    ImsiEfPos     = SIMI_EF_IMSI_POS,
    LpEfPos       = SIMI_EF_LP_POS,
    ElpEfPos      = SIMI_EF_ELP_POS,
    PlmnEfPos     = SIMI_EF_PLMNS_POS,
    SpnEfPos      = SIMI_EF_SPN_POS,
    CbmiEfPos     = SIMI_EF_CBMI_POS,
    EccEfPos      = SIMI_EF_ECC_POS,
    CbmirEfPos    = SIMI_EF_CBMIR_POS,
    BdnEfPos      = SIMI_EF_BDN_POS,
    SmsrEfPos     = SIMI_EF_SMSR_POS,
    GraphicsDfPos = SIMI_DF_GRAPHICS_POS,
    SdnEfPos      = SIMI_EF_SDN_POS,
    Ext1EfPos     = SIMI_EF_EXT1_POS,
    Ext2EfPos     = SIMI_EF_EXT2_POS,
    Ext3EfPos     = SIMI_EF_EXT3_POS,
    Ext4EfPos     = SIMI_EF_EXT4_POS,
    NiaEfPos      = SIMI_EF_NIA_POS,
    CmiEfPos      = SIMI_EF_CMI_POS,
    CphsCsp2EfPos = SIMI_EF_CPHS_CSP2_POS,
    CphsAcm2EfPos = SIMI_EF_CPHS_ACM2_POS,
    CcpEfPos      = SIMI_EF_CCP_POS,
    OParamEfPos   = SIMI_EF_O_PARAM_POS,
    OJcEfPos      = SIMI_EF_O_JC_POS,
    ODynEfPos     = SIMI_EF_O_DYN_POS,
    ODyn2EfPos    = SIMI_EF_O_DYN2_POS,
    OZon1EfPos    = SIMI_EF_O_ZON1_POS,
    OZon2EfPos    = SIMI_EF_O_ZON2_POS,
    OSct2EfPos    = SIMI_EF_O_SCT_POS,
    CphsVmwfEfPos   = SIMI_EF_CPHS_VMWF_POS,
    CphsSrvstEfPos  = SIMI_EF_CPHS_SRVST_POS,
    CphsCfufEfPos   = SIMI_EF_CPHS_CFUF_POS,
    CphsOnmEfPos    = SIMI_EF_CPHS_ONM_POS,
    CphsCspEfPos    = SIMI_EF_CPHS_CSP_POS,
    CphsIstEfPos    = SIMI_EF_CPHS_IST_POS,
    CphsMboxEfPos   = SIMI_EF_CPHS_MBOX_POS,
    CphsInfumEfPos  = SIMI_EF_CPHS_INFNUM_POS,
    ViHzParamEfPos  = SIMI_EF_VI_HZ_PARAM_POS,
    ViHzCache1EfPos = SIMI_EF_VI_HZ_CACHE1_POS,
    ViHzCache2EfPos = SIMI_EF_VI_HZ_CACHE2_POS,
    ViHzCache3EfPos = SIMI_EF_VI_HZ_CACHE3_POS,
    ViHzCache4EfPos = SIMI_EF_VI_HZ_CACHE4_POS,
    CphsOnsEfPos    = SIMI_EF_CPHS_ONS_POS,
    VgcsEfPos,      // #define SIMI_EF_VGCS_POS SDL_INTEGER_LIT(54)
    VgcssEfPos,     // #define SIMI_EF_VGCSS_POS SDL_INTEGER_LIT(55)
    VbsEfPos,       // #define SIMI_EF_VBS_POS SDL_INTEGER_LIT(56)
    VbssEfPos,      // #define SIMI_EF_VBSS_POS SDL_INTEGER_LIT(57)
    EmlppEfPos,     // #define SIMI_EF_EMLPP_POS SDL_INTEGER_LIT(58)
    AaemEfPos,      // #define SIMI_EF_AAEM_POS SDL_INTEGER_LIT(59)
    InvScanEfPos,   // #define SIMI_EF_INV_SCAN_POS SDL_INTEGER_LIT(60)
    EccpEfPos,      // #define SIMI_EF_ECCP_POS SDL_INTEGER_LIT(61)
    PlmnWactEfPos,  // #define SIMI_EF_PLMN_WACT_POS SDL_INTEGER_LIT(62)
    OplmnWactEfPos, // #define SIMI_EF_OPLMN_WACT_POS SDL_INTEGER_LIT(63)
    CpbcchEfPos,    // #define SIMI_EF_CPBCCH_POS SDL_INTEGER_LIT(64)
    HplmnWact,      // #define SIMI_EF_HPLMN_WACT_POS SDL_INTEGER_LIT(65)

    NumberOfEfPos   = SI_MI_NUMBER_OF_EF
};

/*  ========================================================================
    SimEventList
    ========================================================================*/
// sim toolkit event List (ms.h: T_SI_EVENT_LIST)
struct SimEventList {
    UINT8 val[2];
};

/*  ========================================================================
    SimSubAddress
    ========================================================================*/
// alpha identifier (ms.h: T_CALLED_SUBADDR)
struct SimSubAddress {
    UINT8 val[22];
};

/*  ========================================================================
    SimEfRefreshTable
    ========================================================================*/
// refresh table for elementary files on sim card
struct SimEfRefreshTable {
    BOOLEAN refresh[NumberOfEfPos];
};

/*  ========================================================================
    SimEfRefresh
    ========================================================================*/
// refresh option for elementary files on sim card
struct SimEfRefresh {
    BOOLEAN full_refresh;
    SimEfRefreshTable table;
    BOOLEAN IsFullRefreshed() { return (full_refresh); }
    BOOLEAN IsRefreshed(UINT i) { ASSERT(i < NumberOfEfPos); return (full_refresh ? full_refresh : table.refresh[i]); }
};


/*  ========================================================================
    SimToolkitBrowser
    ========================================================================*/
//  (ms.h: T_SI_URL_ARRAY)
typedef struct {
    byte  val[244];
}  SiUrlArray;

//  (ms.h: T_SI_URL)
typedef struct TSiUrl_s {
    byte  length;
    SiUrlArray  data;
} TSiUrl;

//  (ms.h: T_ALPHA_IDENTIFIER_ARRAY)

typedef struct {
    byte  val[SI_MAX_ALPHA_IDENTIFIER_SIZE];
}  TAlphaIdentifierArray;

//  (ms.h: T_ALPHA_IDENTIFIER)
typedef struct TAlphaIdentifier_s {
    SDL_Boolean  identifier_valid;
    byte  length;
    TAlphaIdentifierArray  data;
} TAlphaIdentifier;

typedef struct TSiIconID_s {
    SDL_Boolean  exists;
    byte  qualifier;
    byte  id;
} TSiIconID;

//  (ms.h: SI_LAUNCH_BROWSER_PROMPT_REQ)
typedef struct SimLaunchBrowserPromptReq_s {
    TSiUrl  Param1;
    TAlphaIdentifier  Param2;
    TSiIconID  Param3;
} SimLaunchBrowserPromptReq;

enum SiClientFlags{
    ClientFlagConfirmedRefresh     = 0x01,
    ClientFlagLocationStatusReport = 0x02,
    ClientFlagMccOnStartInd        = 0x04,

};

/*  ========================================================================
    BearerList
    ========================================================================*/
//  (ms.h: SI_BEARER_LIST_ARRAY)
typedef struct {
        UINT8 val[4];
}  SiBearerListArray;
//  (ms.h: SI_BEARER_LIST)
typedef struct SiBearerList_s {
    byte  br_number;
    SiBearerListArray  data;
} SiBearerList;

//  (ms.h: T_SI_BEARER_DESC_ARRAY)
typedef struct {
        UINT8 val[6];
}  SiBearerDescArray;
//  (ms.h: T_SI_BEARER_DESC)
typedef struct SiBearerDesc_s {
    byte  bearer_type;
    SiBearerDescArray  data;
} SiBearerDesc;

// sim Provisioning File Reference (ms.h: T_SI_PROV_FILE_REF_ARRAY)
typedef struct {
    UINT8  val[60];
}  SiProvFileRefArray;
// sim Provisioning File Reference (ms.h: T_SI_PROV_FILE_REF)
typedef struct SiProvFileRef_s {
    byte  file_number;
    SiProvFileRefArray  data;
} SiProvFileRef;


//  (ms.h: MSAP_PACKED_DATA_REF)
//unsigned long MsapPackedDataRef;

//  (ms.h: T_MSAP_PACKED_DATA_ARRAY)
typedef struct {
    byte  val[256];
}  TMsapPackedDataArray;

//  (ms.h: T_MSAP_PACKED_DATA)
typedef struct MsapPackedData_s {
    byte  result;
    unsigned short  private_idx;
    TMsapPackedDataArray  data;
} MsapPackedData;

//  (ms.h: T_SI_TEXT_ARRAY)
typedef struct {
    byte  val[242];
}  SiTextArray;

//  (ms.h: T_SI_TEXT)
typedef struct SiText_s {
    byte  data_coding_scheme;
    byte  length;
    SiTextArray  text;
} SiText;


/*  ========================================================================
    SimToolkit Letter Class E
    ========================================================================*/
enum GenResultCode { // TS 11.14 ch 12.12
    // command has been performed
    gr_Command_performed_successfully                     = 0x00,
    gr_Command_performed_with_partial_comprehension       = 0x01,
    gr_Command_performed_with_missing_information         = 0x02,
    gr_Refresh_performed_with_add_EFs_read                = 0x03,
    gr_Command_performed_successfully_but_icon_not_disp   = 0x04,
    gr_Command_performed_but_modified_by_SIM              = 0x05,
    gr_Command_performed_successfully_but_limited_service = 0x06,
    gr_Command_performed_with_modification                = 0x07,
    gr_Proactive_SIM_Session_terminated_by_user           = 0x10,
    gr_Backward_move_requested_by_user                    = 0x11,
    gr_No_response_from_user                              = 0x12,
    gr_Help_information_required_by_user                  = 0x13,
    gr_ss_transaction_terminated_by_user                  = 0x14,

    // command failed, may be worth re-tried at a later time
    gr_ME_currently_unable                                = 0x20,
    gr_Network_currently_unable                           = 0x21,
    gr_User_did_not_accept_proactive_command              = 0x22,
    gr_User_cleared_call_before_network_release           = 0x23,
    gr_Action_in_contradiction_with_current_timer         = 0x24,
    gr_Interaction_with_SIM_temporary_problem             = 0x25,
    gr_Launch_browser_generic_error                       = 0x26,

    // command failed, may not be worth re-tried at a later time
    gr_Command_beyond_ME_capabilities                     = 0x30,
    gr_Command_type_not_understood_by_ME                  = 0x31,
    gr_Command_data_not_understood_by_ME                  = 0x32,
    gr_Command_number_not_known_by_ME                     = 0x33,
    gr_SS_return_error                                    = 0x34,
    gr_SMS_rp_error                                       = 0x35,
    gr_Error_required_values_missing                      = 0x36,
    gr_USSD_error                                         = 0x37,
    gr_MultipleCard_error                                 = 0x38,
    gr_Interaction_with_SIM_permanent_problem             = 0x39,
    gr_Bearer_independent_protocol_error                  = 0x3A,
    };

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
//  (ms.h: T_SI_BEARER_TYPE)
enum SiBearerType{
    SiBearerUndef   = SI_BEARER_UNDEF,
    SiBearerCsd     = SI_BEARER_CSD,
    SiBearerGprs    = SI_BEARER_GPRS,
    SiBearerDefault = SI_BEARER_DEFAULT,
}  ;


//  (ms.h: T_SI_CHANNEL_CLOSE_CAUSE)
enum SiChannelCloseCause{
    SiChannelCloseUndef     = SI_CHANNEL_CLOSE_UNDEF,
    SiChannelCloseRej       = SI_CHANNEL_CLOSE_REJ,
    SiChannelClosedBySat    = SI_CHANNEL_CLOSED_BY_SAT,
    SiChannelClosedByUser   = SI_CHANNEL_CLOSED_BY_USER,
}  ;

//  (ms.h: T_SI_TRANSPORT_LAYER)
enum SiTransportLayer{
    SiTrLayerRaw        = SI_TR_LAYER_RAW,
    SiTrLayerUdp        = SI_TR_LAYER_UDP,
    SiTrLayerTcp        = SI_TR_LAYER_TCP,
}  ;
#else
//  (ms.h: T_SI_BEARER_TYPE)
enum SiBearerType{
    SiBearerUndef,
    SiBearerCsd,
    SiBearerGprs,
    SiBearerDefault,
}  ;


//  (ms.h: T_SI_CHANNEL_CLOSE_CAUSE)
enum SiChannelCloseCause{
    SiChannelCloseUndef,
    SiChannelCloseRej,
    SiChannelClosedBySat,
    SiChannelClosedByUser,
}  ;

//  (ms.h: T_SI_TRANSPORT_LAYER)
enum SiTransportLayer{
    SiTrLayerRaw,
    SiTrLayerUdp,
    SiTrLayerTcp,
}  ;
#endif

//from Applications\Wap\Mic\include\aapinet.h
#define NET_SOCKET_TYPE_UDP             1
#define NET_SOCKET_TYPE_TCP             2
#define NET_SOCKET_TYPE_SMS             3
//----------------

//  (ms.h: T_SI_IP_ADDRESS_ARRAY)
typedef struct {
    byte  val[16];
}  SiIpAddressArray;

//  (ms.h: T_SI_IP_ADDRESS)
typedef struct SiIpAddress_s {
    byte  ip_type;
    SiIpAddressArray  data;
} SiIpAddress;

//  (ms.h: T_DURATION)
typedef struct SiDuration_s {
    byte  time_units;
    byte  time_interval;
} SiDuration;

//  (ms.h: T_SI_SEND_DATA_TYPE )
enum SiSendDataType{
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    SiSendDataImmediately       = SI_SEND_DATA_IMMEDIATELY,
    SiSendDataStoreInBuffer     = SI_SEND_DATA_STORE_IN_BUFFER,
#else
    SiSendDataImmediately,
    SiSendDataStoreInBuffer
#endif
};

//  (ms.h: T_SI_CHANNEL_DATA_ARRAY )
typedef struct {
    byte  A[244];  //more makes no sense due to T_SI_CHANNEL_DATA_ARRAY definition
}  ChannelDataArray;

//  (ms.h: T_CHANNEL_DATA )
typedef struct ChannelData_s {
    byte  length;
    ChannelDataArray  data;
} ChannelData;

//  (ms.h: T_SI_CHANNEL_CHANGED_STATE )
enum SiChannelChangedState{
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    SiChannelChangedNoInfo      = SI_CHANNEL_CHANGED_NO_INFO,
    SiChannelChanged1           = SI_CHANNEL_CHANGED_1,
    SiChannelChanged2           = SI_CHANNEL_CHANGED_2,
    SiChannelChanged3           = SI_CHANNEL_CHANGED_3,
    SiChannelChanged4           = SI_CHANNEL_CHANGED_4,
    SiChannelChangedToDropped   = SI_CHANNEL_CHANGED_TO_DROPPED,
#else
    SiChannelChangedNoInfo,
    SiChannelChanged1,
    SiChannelChanged2,
    SiChannelChanged3,
    SiChannelChanged4,
    SiChannelChangedToDropped
#endif
};


/*  ========================================================================
                    Command Qualifier (GSM 11.14 [12.6])
    used for options for various sim toolkit commands
    ======================================================================== */
/*  ========================================================================
    SimDisplayTextOptions
    ========================================================================*/
class SimDisplayTextOptions {
    public:
        SimDisplayTextOptions(SdlByte bit_field = 0);
        ~SimDisplayTextOptions();

        BOOLEAN HighPriority() const    { return ( m_bit_field.GetBit(0)); };
        BOOLEAN ClearAfterDelay() const { return (!m_bit_field.GetBit(7)); };

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<SdlByte> m_bit_field;
};

/*  ========================================================================
    SimGetInputOptions
    ========================================================================*/
class SimGetInputOptions {
    public:
        SimGetInputOptions(SdlByte bit_field = 0);
        ~SimGetInputOptions();

        BOOLEAN DigitsOnly() const    { return (!m_bit_field.GetBit(0)); };
        BOOLEAN Ucs2() const          { return ( m_bit_field.GetBit(1)); };
        BOOLEAN HideUserInput() const { return ( m_bit_field.GetBit(2)); };
        BOOLEAN PackUserInput() const { return ( m_bit_field.GetBit(3)); };
        BOOLEAN HelpAvailable() const { return ( m_bit_field.GetBit(7)); };

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<SdlByte> m_bit_field;
};

/*  ========================================================================
    SimGetInkeyOptions
    ========================================================================*/
class SimGetInkeyOptions {
    public:
        SimGetInkeyOptions(SdlByte bit_field = 0);
        ~SimGetInkeyOptions();

        BOOLEAN DigitsOnly() const    { return (!m_bit_field.GetBit(0)); };
        BOOLEAN Ucs2() const          { return ( m_bit_field.GetBit(1)); };
        BOOLEAN ActivateYesNo() const { return ( m_bit_field.GetBit(2)); };
        BOOLEAN HelpAvailable() const { return ( m_bit_field.GetBit(7)); };

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<SdlByte> m_bit_field;
};

/*  ========================================================================
    SimSelectItemOptions
    ========================================================================*/
class SimSelectItemOptions {
    public:
        SimSelectItemOptions(SdlByte bit_field = 0);
        ~SimSelectItemOptions();

        BOOLEAN PresentationTypeAvailable() const       { return ( m_bit_field.GetBit(0)); };
        BOOLEAN PresentationAsNavigationOptions() const { return ( m_bit_field.GetBit(1)); };
        BOOLEAN SelectionByUsingSoftkey() const         { return ( m_bit_field.GetBit(2)); };
        BOOLEAN HelpAvailable() const                   { return ( m_bit_field.GetBit(7)); };

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<SdlByte> m_bit_field;
};

/*  ========================================================================
    SimSetupMenuOptions
    ========================================================================*/
class SimSetupMenuOptions {
    public:
        SimSetupMenuOptions(SdlByte bit_field = 0);
        ~SimSetupMenuOptions();

        BOOLEAN SelectionByUsingSoftkey() const { return ( m_bit_field.GetBit(0)); };
        BOOLEAN HelpAvailable() const           { return ( m_bit_field.GetBit(7)); };

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<SdlByte> m_bit_field;
};

/*  ========================================================================
    SimSetupIdleModeTextOptions
    ========================================================================*/
class SimSetupIdleModeTextOptions {
    public:
        SimSetupIdleModeTextOptions(SdlByte bit_field = 0);
        ~SimSetupIdleModeTextOptions();

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<SdlByte> m_bit_field;
};

/*  ========================================================================
    ProactiveCauseMapper
    ========================================================================*/
class ProactiveCauseMapper {
    public:

        static T_MI_PROACTIVE_CAUSE ToSdl(ProactiveCause pc, BOOLEAN return_default = TRUE);

        static T_MI_PROACTIVE_CAUSE ToSdlExt(ProactiveCause pc, SdlByte &general_result, SdlByte &additional_result);

    private:

}; // ProactiveCauseMapper

/*  ========================================================================
    SimTkTransactionId
    ========================================================================*/
#if ! defined(APOXI_SIMTK_TRANSACTIONID_SUPPORT)
struct T_STK_TRANSACTION_ID 
{
    SdlByte transaction_id;        
    SdlByte cmd_number;   
};
#endif

class SimTkTransactionId {
    public:
        SimTkTransactionId() { m_id.transaction_id = 0; m_id.cmd_number = 0; }
        SimTkTransactionId(const T_STK_TRANSACTION_ID & id) : m_id(id) {}

        const T_STK_TRANSACTION_ID & GetId() const { return m_id; }

    private:
        T_STK_TRANSACTION_ID m_id;

}; // SimTkTransactionId

/*  ========================================================================
    SimTkProfile
    ========================================================================*/

class SimTkProfile {
    public:
        enum Feature {              // (byte-1)*8 + (bitno-1)
            MenuSelection =         (1-1)*8 + (4-1), 
            UCS2EntrySupported =    (2-1)*8 + (6-1), 
            UCS2DisplaySupported =  (2-1)*8 + (7-1), 
            DisplayExtensionText =  (2-1)*8 + (8-1), 
            BinaryChoiceGetInkey =  (8-1)*8 + (4-1), 
            ScreenSizingParameters =(14-1)*8 +(8-1), 
            VariableSizeFontSupport=(15-1)*8 +(8-1), 
            DisplayResizable =      (16-1)*8 +(1-1), 
            TextWrapping =          (16-1)*8 +(2-1), 
            TextScrolling =         (16-1)*8 +(3-1), 
            WidthReductionInAMenu = (16-1)*8 +(8-1), 

            // to be continued on request
        };

        SimTkProfile(const T_PROFILE & profile) : m_profile(profile) { }

        SimTkProfile(const SimTkProfile & profile) : m_profile(profile.m_profile) { }

        SimTkProfile() { memset((void*)&m_profile,0x00,sizeof(m_profile)); }

        const T_PROFILE & GetProfile() const { return m_profile; }

        void SetNumberOfCharsSupportedInDisplay(UINT8 no) {
            m_profile.data.A[13] = (m_profile.data.A[13] & 0xE0) + (no & 0x1F);
        }

        void SetNumberOfCharsAcrossDisplay(UINT8 no) {
            m_profile.data.A[14] = (m_profile.data.A[14] & 0x80) + (no & 0x7F);
        }

        void SetFeature(Feature no, BOOLEAN set = TRUE) {
            INT byteno = no / 8;
            UINT8 pbyte = m_profile.data.A[byteno];
            UINT8 mask = 1 << (no - (byteno*8));
            pbyte = set ? (pbyte | mask) : (pbyte & ~mask);
            m_profile.data.A[byteno] = pbyte; 
        }

    private:
        T_PROFILE m_profile;

}; // SimTkTransactionId


/*  ========================================================================
    SimTk Parameter Macros
    ========================================================================*/
//
// These macros are necessary because nearly all simtoolkit signals for certain
// stacks will contain an optional additional transactionid on first position of 
// the parameters. If compiling with the #define APOXI_SIMTK_TRANSACTIONID_SUPPORT 
// the order is without the first additional parameter

#if ! defined(APOXI_SIMTK_TRANSACTIONID_SUPPORT)
// if no transaction id is supported by stack, return an empty object
    #define SimtkSignalTid     SimTkTransactionId()
    #define SimtkSignalParam1  ApoxiSdlSignalDataParam(1)
    #define SimtkSignalParam2  ApoxiSdlSignalDataParam(2)
    #define SimtkSignalParam3  ApoxiSdlSignalDataParam(3)
    #define SimtkSignalParam4  ApoxiSdlSignalDataParam(4)
    #define SimtkSignalParam5  ApoxiSdlSignalDataParam(5)
    #define SimtkSignalParam6  ApoxiSdlSignalDataParam(6)
    #define SimtkSignalParam7  ApoxiSdlSignalDataParam(7)
    #define SimtkSignalParam8  ApoxiSdlSignalDataParam(8)
    #define SimtkSignalParam9  ApoxiSdlSignalDataParam(9)
    #define SimtkSignalParam10  ApoxiSdlSignalDataParam(10)
    #define SimtkSignalParam11  ApoxiSdlSignalDataParam(11)

// if no transaction id is supported by stack, don³t expand the code
    #define SimtkSetSignalTid(param)     
    #define SimtkSetSignalParam1(param)  ApoxiSdlSetOutSignalParam(1,param)
    #define SimtkSetSignalParam2(param)  ApoxiSdlSetOutSignalParam(2,param)
    #define SimtkSetSignalParam3(param)  ApoxiSdlSetOutSignalParam(3,param)
    #define SimtkSetSignalParam4(param)  ApoxiSdlSetOutSignalParam(4,param)
    #define SimtkSetSignalParam5(param)  ApoxiSdlSetOutSignalParam(5,param)
    #define SimtkSetSignalParam6(param)  ApoxiSdlSetOutSignalParam(6,param)
    #define SimtkSetSignalParam7(param)  ApoxiSdlSetOutSignalParam(7,param)
    #define SimtkSetSignalParam8(param)  ApoxiSdlSetOutSignalParam(8,param)
    #define SimtkSetSignalParam9(param)  ApoxiSdlSetOutSignalParam(9,param)
    #define SimtkSetSignalParam10(param)  ApoxiSdlSetOutSignalParam(10,param)
    #define SimtkSetSignalParam11(param)  ApoxiSdlSetOutSignalParam(11,param)
#else
    #define SimtkSignalTid     ApoxiSdlSignalDataParam(1)
    #define SimtkSignalParam1  ApoxiSdlSignalDataParam(2)
    #define SimtkSignalParam2  ApoxiSdlSignalDataParam(3)
    #define SimtkSignalParam3  ApoxiSdlSignalDataParam(4)
    #define SimtkSignalParam4  ApoxiSdlSignalDataParam(5)
    #define SimtkSignalParam5  ApoxiSdlSignalDataParam(6)
    #define SimtkSignalParam6  ApoxiSdlSignalDataParam(7)
    #define SimtkSignalParam7  ApoxiSdlSignalDataParam(8)
    #define SimtkSignalParam8  ApoxiSdlSignalDataParam(9)
    #define SimtkSignalParam9  ApoxiSdlSignalDataParam(10)
    #define SimtkSignalParam10 ApoxiSdlSignalDataParam(11)
    #define SimtkSignalParam11 ApoxiSdlSignalDataParam(12)

    #define SimtkSetSignalTid(param)     ApoxiSdlSetOutSignalParam(1,param.GetId())
    #define SimtkSetSignalParam1(param)  ApoxiSdlSetOutSignalParam(2,param)
    #define SimtkSetSignalParam2(param)  ApoxiSdlSetOutSignalParam(3,param)
    #define SimtkSetSignalParam3(param)  ApoxiSdlSetOutSignalParam(4,param)
    #define SimtkSetSignalParam4(param)  ApoxiSdlSetOutSignalParam(5,param)
    #define SimtkSetSignalParam5(param)  ApoxiSdlSetOutSignalParam(6,param)
    #define SimtkSetSignalParam6(param)  ApoxiSdlSetOutSignalParam(7,param)
    #define SimtkSetSignalParam7(param)  ApoxiSdlSetOutSignalParam(8,param)
    #define SimtkSetSignalParam8(param)  ApoxiSdlSetOutSignalParam(9,param)
    #define SimtkSetSignalParam9(param)  ApoxiSdlSetOutSignalParam(10,param)
    #define SimtkSetSignalParam10(param)  ApoxiSdlSetOutSignalParam(11,param)
    #define SimtkSetSignalParam11(param)  ApoxiSdlSetOutSignalParam(12,param)
#endif


#endif  // Apc_SimTkTypes_hpp


