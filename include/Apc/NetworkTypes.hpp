/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_NetworkTypes_hpp)
#define Apc_NetworkTypes_hpp

#include <Kernel/Types.hpp>
#include <Apc/SignalTypes.hpp>

enum GsmService {
    CircuitSwitched = CIRCUIT_SWITCHED,
    PacketSwitched = PACKET_SWITCHED,
    CircuitSwitchedPreferred = CIRCUIT_SWITCHED_PREFERED,
    PacketSwitchedPreferred = PACKET_SWITCHED_PREFERED,
    InvalidGsmService
};

enum RegisterStatus {
    NormalService       = NORMAL_SERVICE,       // able to place calls
    RegistrationFailure = REGISTRATION_FAILURE, // able to place calls, registration is needed before
    LimitedService      = LIMITED_SERVICE,      // emergency calls only
    NoService           = NO_SERVICE,           // no calls allowed (no network found)
    AtNotRegistered     = AT_NOT_REGISTERED,    // no calls allowed
    ServiceDisabled     = SERVICE_DISABLED,     // no PLMN search will be performed. equals to NoService
    ServiceDetached     = SERVICE_DETACHED,     // no PLMN search will be performed
};                  

enum RegisterRejectCause {
    RrcNotRegistered      = RC_NOT_REGISTERED,    // not registered
    RrcInvalidSim         = RC_INVALID_SIM,       // sim invalid
    RrcNRegReq            = RC_NREG_REQ,          // deregistration (AT)
    RrcNoCell             = RC_NO_CELL,
    RrcNoCarrier          = RC_NO_CARRIER,
    RrcPlmnSearch         = RC_PLMN_SEARCH,
    RrcPlmnSearchEnded    = RC_PLMN_SEARCH_ENDED,
    RrcAuthFailure        = RC_AUTH_FAILURE,
    RrcPowerDown          = RC_POWER_DOWN,
    RrcForbPlmn           = RC_FORB_PLMN,
    RrcForbLai            = RC_FORB_LAI,
    RrcDetached           = RC_DETACHED,
    RrcDisabled           = RC_DISABLED,
    RrcInvalidParameter   = RC_INVALID_PARAMETER,
    RrcRejByNetwork       = RC_REJ_BY_NETWORK,
    RrcInternalFailure    = RC_INTERNAL_FAILURE,
    RrcAttachTempBarred   = RC_ATTACH_TEMP_BARRED,
    RrcNoCause            = RC_NO_CAUSE,        // initialization value (no cause)
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    RrcAttachNotAllowed   = RC_ATTACH_NOT_ALLOWED,
#else
    RrcAttachNotAllowed
#endif
};              

enum UserCause {
    UcPowerDown       = POWER_DOWN,
    UcInvalidSim      = SIM_DETACH,
    UcNotAllowed      = NOT_ALLOWED,
    UcAbortByUser     = ABORT_BY_USER,
    UcNotPossible     = NOT_POSSIBLE,
    UcDisableService  = DISABLE_SERVICE,
    UcDetachService   = DETACH_SERVICE,
    UcAttachService   = ATTACH_SERVICE,
    UcEnableService   = ENABLE_SERVICE,
    UcUserReselection = USER_RESELECTION,
};              

enum PlmnScanMode {
    PlmnScanOff     = PLMN_LIST_OFF,
    PlmnListScan    = PLMN_LIST,
};


enum ProcessSource {
    PsMmi = MN_MMI,
    PsAtc = MN_ATC,
    PsNet = MN_NET,
    PsOm  = MN_OM,
    PsInvalid
};              

enum FdnState {
    FdnOn               = MN_FDN_ON,    // FDN activated 
    FdnOff              = MN_FDN_OFF,   // FDN deactivated
    FdnNotPossible      = MN_FDN_NOT_POSSIBLE,  // No service on SIM 
};

enum BdnState {
    BdnOn               = MN_BDN_ON,    // BDN activated 
    BdnOff              = MN_BDN_OFF,   // BDN deactivated
    BdnNotPossible      = MN_BDN_NOT_POSSIBLE,  // No service on SIM 
};                  


/**************************************************************************/
/*                                     Homezone                           */
/**************************************************************************/



/* T_ZONAL_INDICATOR */
enum HomezoneIndicator {
    NoTextNoIcon = ZONAL_INDICATOR_OFF,
    WithTextWithIcon = ZONAL_INDICATOR_ON_WITH_TEXT_AND_ICON,
    WithTextNoIcon = ZONAL_INDICATOR_ON_WITH_TEXT_NO_ICON,
    NoTextWithIcon = ZONAL_INDICATOR_ON_WITH_ICON_NO_TEXT,
};


/* T_ZONAL_TEXT */
struct HomezoneText {
    UINT8 length;
    UINT8 label[15];
};


/**************************************************************************/
/*                     TimeZoneAndTime  T_TIME_ZONE_AND_TIME                           */
/**************************************************************************/

/* T_TIME_ZONE_AND_TIME */
struct TimeZoneAndTime {

    UINT8 A[SDL_INTEGER_LIT(6)+1];
};


/**************************************************************************/
/*                     LsaIdentifier  T_LSA_IDENTIFIER                             */
/**************************************************************************/


typedef struct {
    byte  A[SDL_INTEGER_LIT(2)+1];
} LsaIdentifierArray;


/* T_LSA_IDENTIFIER */
struct LsaIdentifier {
    SDL_Integer  length;
    LsaIdentifierArray  lsa_id;
};


enum MultiSlotCapability {
    DefaultMultiSlotCapability = NO_MULTI_SLOT_CAPABILITY    //0
    //Allowed values for HSCSD: 0..18    
    //Allowed values for GPRS : 0..29
    //For currently allowed number of slots see oms_conf.h
};

/*----------------------------------------------------------------------------*/
/*               struct MultiSlot                                             */
/*              (T_MULTI_SLOT, /ms-interface-src/pr/ms_signals_om.pr,69,11)   */
/*----------------------------------------------------------------------------*/

struct MultiSlotMode {
    UINT8   multi_slot_class;
    
    MultiSlotMode():
    multi_slot_class(0xff)
    {}
    MultiSlotMode operator =(T_MULTI_SLOT multi_slot);
};//MultiSlotMode

 /* -------------------------------------------------------------------- */
/* -------- T _ M U L T I _ S L O T _ C L A S S ----------------------- */
/* -------------------------------------------------------------------- */
/*

 Definitions for the Multi Slot Class as defined in GSM 05.02.


  SYNTYPE T_MULTI_SLOT_CLASS #NAME 'T_MULTI_SLOT_CLASS' = Byte
  ENDSYNTYPE;

  Allowed values for HSCSD: 0..18    
  Allowed values for GPRS : 0..29    

  SYNONYM NO_MULTI_SLOT_CAPABILITY #NAME 'NO_MULTI_SLOT_CAPABILITY' Integer = 0;

 */

//T_MMRR_CAUSE in /vobs/ms-hosttest/mi/src/../../../stack-interface/globals/cause.pr,212,9)
enum MmRrReason { 
    //GSM
    No_cause =           MMRR_NO_CAUSE,
    No_carrier =         NO_CARRIER, 
    No_cell =            NO_CELL,  
    Invalid_plmn =       INVALID_PLMN ,
    Handover =           HANDOVER,
    Chn_realase =        CHN_RELEASE,
    Link_estab_fail =    LINK_ESTAB_FAILURE, 
    Ra_fail =            RA_FAILURE,
    Link_abortion =      LINK_ABORTION,
    L2_l1_fail =         L2_L1_FAILURE,
    Hplmn_search_fail =  HPLMN_SEARCH_FAIL,
    Imm_ass_reject =     IMM_ASS_REJECT,
    Abnormal_release =   ABNORMAL_RELEASE,
    Access_not_allowed = ACCESS_NOT_ALLOWED,

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    MmRrcNormalEvent                    = MMRRC_NORMAL_EVENT,                       /*#NAME 'MMRRC_NORMAL_EVENT' */
    MmRrcNoCause                        = MMRRC_NO_CAUSE,                           /*#NAME 'MMRRC_NO_CAUSE'*/
    MmRrcPreEmtiveRelease               = MMRRC_PRE_EMPTIVE_RELEASE,                /*#NAME 'MMRRC_PRE_EMPTIVE_RELEASE' */
    MmRrcCongestion                     = MMRRC_CONGESTION,                         /*#NAME 'MMRRC_CONGESTION' */
    MmRrcReEstablishmentReject          = MMRRC_RE_ESTABLISHMENT_REJECT,            /*#NAME 'MMRRC_RE_ESTABLISHMENT_REJECT' */
    MmRrcDirectedSigconnReEstablishment = MMRRC_DIRECTED_SIGCONN_RE_ESTABLISHMENT,  /*#NAME 'MMRRC_DIRECTED_SIGCONN_RE_ESTABLISHMENT' */
    MmRrcUserInactivity                 = MMRRC_USER_INACTIVITY,                    /*#NAME 'MMRRC_USER_INACTIVITY' */
    MmRrcConnEstablished                = MMRRC_CONN_ESTABLISHED,                   /*#NAME 'MMRRC_CONN_ESTABLISHED' */ 
    MmRrcConnRelease                    = MMRRC_CONN_RELEASE,                       /*#NAME 'MMRRC_CONN_RELEASE' */      
    MmRrcInterratHandover               = MMRRC_INTERRAT_HANDOVER,                  /*#NAME 'MMRRC_INTERRAT_HANDOVER' */
    MmRrcCellBarred                     = MMRRC_CELL_BARRED,                        /*#NAME 'MMRRC_CELL_BARRED' */
    MmRrcnactive                        = INACTIVE,                                 /*#NAME 'INACTIVE' */
#else
    MmRrcNormalEvent,
    MmRrcNoCause,
    MmRrcPreEmtiveRelease,
    MmRrcCongestion,
    MmRrcReEstablishmentReject,
    MmRrcDirectedSigconnReEstablishment,
    MmRrcUserInactivity,
    MmRrcConnEstablished,
    MmRrcConnRelease,
    MmRrcInterratHandover,
    MmRrcCellBarred,
    MmRrcInactive,
#endif
    InvalidMmRrReason = 0xff
};//MmRrReason


//T_DL_SC  in vobs/ms-hosttest/mi/src/../../../stack-interface/globals/radio_res.pr,66,11)
typedef UINT16 DlSc;    // = ushort

//T_UARFCN in /vobs/ms-hosttest/mi/src/../../../stack-interface/globals/radio_res.pr,77,11
typedef UINT16 Uarfcn;    //= ushort

//T_MMRR_CAUSE in /vobs/ms-hosttest/mi/src/../../../stack-interface/globals/cause.pr,212,9)
//enum MmrrCause {
//};

/*  ========================================================================
                                  Rat
    ========================================================================*/
enum Rat {
    Gsm = 0, 
    Fdd = 1
};

/*  ========================================================================
                                  RrMode
    ========================================================================*/
enum RrMode {
    RrModeUmts = 0, //rat_umts,
    RrModeGsm  = 1  //rat_gsm
};

/*----------------------------------------------------------------------------*/
/*                  UMTS enum's                                               */
/*----------------------------------------------------------------------------*/
//T_EM_EVENT /vobs/ms-hosttest/mi/src/../../../stack-interface/api/umts_testparam.pr,41,9
enum EmEventType {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    UrrcParamReq        =   EM_URRC_TESTPARAM_REQ,   /*#NAME 'EM_URRC_TESTPARAM_REQ'*/
    ReportingTimer      =   EM_REPORTING_TIMER,      /*#NAME 'EM_REPORTING_TIMER'*/
    UrrcTestCountReq    =   EM_URRC_TEST_COUNT_REQ   /*#NAME 'EM_URRC_TEST_COUNT_REQ'*/
#else
    UrrcParamReq,
    ReportingTimer,
    UrrcTestCountReq
#endif
};//EmEvent

//T_CELL_TYPE in /vobs/ms-hosttest/mi/src/../../../stack-interface/api/umts_testparam.pr,307,9
enum EmCellType {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    ActiveSet           =   EM_ACTIVE_SET,              /* Cell belongs to the Active set (CELL_DCH)*/
    VirtualActiveSet    =   EM_VIRTUAL_ACTIVE_SET,      /* Cell belongs to the Virtual Active set (CELL_DCH)*/
    Monitored           =   EM_MONITORED,               /* Cells in the SIB 11/12 "BA"-list */
    Detected            =   EM_DETECTED,                /* Cell is a detected UMTS cell (CELL_DCH) */
    UmtsCell            =   EM_UMTS_CELL,               /* Cell is a UMTS neighbour cell in GSM mode */
    UmtsRanked          =   EM_UMTS_RANKED,             /* Cell is a UMTS neighbour cell (all states but CELL_DCH) */
    UmtsNotRanked       =   EM_UMTS_NOT_RANKED          /* Cell is a UMTS neighbour cell (all states but CELL_DCH) */   
#else
    ActiveSet,
    VirtualActiveSet,
    Monitored,
    Detected,
    UmtsCell,
    UmtsRanked,
    UmtsNotRanked
#endif
};//EmCellType

//T_RANKING_STATUS in /vobs/ms-hosttest/mi/src/../../../stack-interface/api/umts_testparam.pr,318,9
enum EmRankingStatus {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    CellSuitable    =   EM_CELL_SUITABLE,     /* Cell is OK! */
    NotMeasured     =   EM_NOT_MEASURED,      /* No measurement results available */
    CellBarred      =   EM_CELL_BARRED,       /* Cell is barred )*/
    WrongPlmn       =   EM_WRONG_PLMN,        /* Wrong PLMN */
    HcsCriteriaPrio =   EM_HCS_CRITERIA_PRIO, /* Removed due to H criteria priority (HCS active)*/
    HcsHValue       =   EM_HCS_H_VALUE,       /* Removed due to HCS priority */
    SValue          =   EM_S_VALUE            /* Removed due to cell selection criteria */
#else
    CellSuitable,
    NotMeasured,
    CellBarred,
    WrongPlmn,
    HcsCriteriaPrio,
    HcsHValue,
    SValue
#endif
};//EmRankingStatus


//T_POWER_SAVING_MODE in /vobs/ms-hosttest/mi/src/../../../stack-interface/api/umts_testparam.pr,329,9
enum PowerSavingMode {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    PowerSavingMode1 = POWER_SAVING_MODE_1
#else
    PowerSavingMode1
#endif
};//PowerSavingMode


/*----------------------------------------------------------------------------*/
/*                       struct MmCellChangeCnts                              */
/*                       (T_MM_CELL_CHANGE_CNTS in ms_testparam.pr)           */
/*----------------------------------------------------------------------------*/
struct MmCellChangeCnts {
    UINT8 ir_ho_attempt;    //Number of attemted inter rat HO or cell changes
    UINT8 ir_ho_success;    //Number of successfull inter rat HO or cell changes
    UINT8 ir_cr_attempt;    //Number of attemted inter rat cell reselections
    UINT8 ir_cr_success;    //Number of successfull inter rat cell reselections
    UINT8 cr_success;       //Total number of inter and intra rat cell reselections
};//MmCellChangeCnts


/**************************************************************************************************/
/**************************** UMTS Related Type ***************************************************/
/**************************************************************************************************/
enum EngineeringModeControl {
#if defined(APOXI_EM_CONTROL_ENABLED)
  EmcLockSCell           = EM_LOCK_SCELL,
  EmcUnlockSCell         = EM_UNLOCK_SCELL,
  EmcTrigger3g2gHandover = EM_TRIGGER_3G_2G_HANDOVER 
#else
  EmcLockSCell,
  EmcUnlockSCell,
  EmcTrigger3g2gHandover
#endif
};

enum EmControlRetValue {
#if defined(APOXI_EM_CONTROL_ENABLED)
    EmcFailed       = E_EM_CTRL_FAILED,
    EmcSuccess      = 1, //E_EM_CTRL_SUCCESS, not available yet
    EmcUnsuported   = 0, //E_EM_CTRL_NOT_SUPPORT, not available yet
#else
    EmcFailed       = 2,
    EmcSuccess      = 1,
    EmcUnsuported   = 0
#endif

};


/* --------------------------------------------------------------------- */
/* ------------------ T _ B L E R _ T R C H _I N F O ------------------- */
/* --------------------------------------------------------------------- */
/*#NAME 'T_BLER_TRCH_INFO' */
struct BlerTrchInfo {
    UINT8   trch_id;
    UINT8   meas_bler; 
    UINT16  nof_crc_err;
    ULONG   tot_nof_blocks;
};

/*
 *  T_BLER_TRCH_INFO_ARRAY
 */
struct BlerTrchInfoList {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum {LengthOfBlerArray = MAX_TRCH};
#else
    enum {LengthOfBlerArray = 8};
#endif

    INT     length;
    BlerTrchInfo    plmn_array[LengthOfBlerArray];  

    BOOLEAN IsEmpty();
    BlerTrchInfo& operator[](INT index);
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    BlerTrchInfoList operator =(T_BLER_TRCH_INFO_ARRAY bler_array);
#endif
};

/*#NAME 'T_EM_DCH_REPORT' */
struct DchReport {
      UINT32            meas_bler;      /* 0xFFFFFFFF if not present */
      INT16     target_sir;     /* 0xFFFF if not present */
      INT16     meas_sir;       /* 0xFFFF if not present */

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
      DchReport operator =(T_EM_DCH_REPORT t_dch_report);
#endif
};

/*****
 * T_UPLMN 
 * /ms-hosttest/mi/src/../../../stack-interface/globals/identity.pr,350,9)
******/
struct Uplmn {
    UINT16  mcc;
    UINT16  mnc;
    
    Uplmn() : mcc(0xffff), mnc(0xffff) {}

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    Uplmn operator =(T_UPLMN t_uplmn);
#else
    Uplmn operator =(UINT8 val){return *this; }
#endif
};

/*----------------------------------------------------------------------------*/
/*                       struct UmtsRrcScellParam                             */
/*                       (T_UMTS_RRC_SCELL_PARAM in ms_testparam_umts.pr)         */
/*----------------------------------------------------------------------------*/
struct UmtsRrcScellParam {
    DlSc    p_sc;           //Primary scrambling code %d (0xFFFF)
    UINT16  lac;            //LAI/LAC (0xffff) %x
    UINT32  cell_identity;  //Cell identity 32bit (0xFFFFFFFF) % x
    Uarfcn  ul_uarfcn;      //UL UARFCN of serving cell (0xFFFF) %d
    Uarfcn  dl_uarfcn;      //DL UARFCN of serving cell (0xFFFF)  
    Uplmn   plmn_id;         //PLMN ID w/ MCC and MNC.   
        UINT16  cpich_rscp;     //RSCP (dBm - absolute value) of serving cell (0xFF) %d
    UINT8   cpich_ecn0;     //ECN0 (dB - absolute value) of servicing cell (0xFF) %d                            */
    BOOLEAN cipher_on;      //Ciphering: present if true
    BOOLEAN hcs_used;       //HCS is used: present if true
    BOOLEAN high_mobility;  //High mobilityis detected: present if true
        BOOLEAN limited_service;//Limited service camped (true) or normal service camped (false) 
                            //only valid if dl_uarfcn is not INVALID_ARFCN
                            //reporting period                          
    BOOLEAN out_of_service; //present if out of service otherwise '-'.
   
    UINT16 ranking_value;
    
    /* GPRS parameters */
    UINT8   rac;            //RAC (0xFF)  %x

    UmtsRrcScellParam() :
        p_sc(0xffff), lac(0xffff), cell_identity(0xffffffff), ul_uarfcn(0xffff), dl_uarfcn(0xffff),
        cpich_rscp(0xffff), cpich_ecn0(0xff), rac(0xff)
        {} //UmtsRrcScellParam
    
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    UmtsRrcScellParam operator =(T_UMTS_RRC_SCELL_PARAM umts_rrc_scell_param);
#endif

    BOOLEAN IsPScInvalid()          { return p_sc == 0xffff; }
    BOOLEAN IsLacInvalid()          { return lac == 0xfff; }
    BOOLEAN IsCellIdentityInvalid() { return cell_identity == 0xffffffff; }
    BOOLEAN IsUlUarfcnInvalid()     { return ul_uarfcn == 0xffff; }
    BOOLEAN IsDlUarfcnInvalid()     { return dl_uarfcn == 0xffff; }
    BOOLEAN IsCpichRscpInvalid()    { return cpich_rscp == 0xffff; }
    BOOLEAN IsCpichEcn0Invalid()    { return cpich_ecn0 == 0xff; }
    BOOLEAN IsRankingValueInvalid() { return ranking_value == 0xffff;}
    BOOLEAN IsRacInvalid()          { return rac == 0xff; }
};//UmtsRrcScellParam

/*----------------------------------------------------------------------------*/
/*                       struct UmtsMeasIdParam                               */
/*                       (T_UMTS_MEAS_ID_PARAM_ARRAY in ms_testparam_umts.pr)     */
/*----------------------------------------------------------------------------*/
struct UmtsMeasIdParam {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum MaxDataElements{MaxDataElementsPerMeasId = MAX_DATA_ELEMENTS_PER_MEAS_ID};
#else
    enum MaxDataElements{MaxDataElementsPerMeasId = 6};
#endif

    UINT8 meas_id;  //T_UMTS_MEAS_ID_PARAM_s
    UINT8 event_id; //T_UMTS_MEAS_ID_PARAM_s
    UINT8 data_elements[MaxDataElementsPerMeasId];

    UmtsMeasIdParam() :
        meas_id(0xff),event_id(0xff)
        {}//UmtsMeasIdParam

    BOOLEAN IsMeasIdInvalid()   { return meas_id  == 0xff; }
    BOOLEAN IsEventIdInvalid()  { return event_id == 0xff; }

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    UmtsMeasIdParam operator = (T_UMTS_MEAS_ID_PARAM umts_meas_id_param_array);
#endif
};//UmtsMeasIdParam

/*----------------------------------------------------------------------------*/
/*                       struct UmtsMeasEvalParam                             */
/*                       (T_UMTS_MEAS_EVAL_PARAM in ms_testparam_umts.pr)     */
/*----------------------------------------------------------------------------*/
struct UmtsMeasEvalParam {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum MaxDataElements{MaxMeas = MAXMEAS};
#else
    enum MaxDataElements{MaxMeas = 16};
#endif

    UINT8 p1;       //T_GENERAL_MEAS_PARAMS_s
    UINT8 p2;       //T_GENERAL_MEAS_PARAMS_s
    UmtsMeasIdParam umts_meas_id_params[MaxMeas];
    
    UmtsMeasEvalParam() :
        p1(0xff),p2(0xff)
        {}//UmtsMeasEvalParam

    BOOLEAN IsP1Invalid()       { return p1       == 0xff; }
    BOOLEAN IsP2Invalid()       { return p2       == 0xff; }

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    UmtsMeasEvalParam operator = (T_UMTS_MEAS_EVAL_PARAM umts_meas_eval_param);
#endif
};//UmtsMeasEvalParam




/*----------------------------------------------------------------------------*/
/*                       struct UmtsNcellParam                                */
/*                       (T_UMTS_NCELL_PARAM in ms_testparam_umts.pr)         */
/*----------------------------------------------------------------------------*/
struct UmtsNcellParam {
    EmCellType  cell_type;          //Kind of cell
    DlSc        cpich_sc;           //Primary scrambling code %d (0xFFFF)%d
    Uarfcn      dl_uarfcn;          //DL UARFCN (0xFFFF) %d
    UINT16      cpich_rscp;         //RSCP (dBm - positive value presented positive) of serving cell (0xff) %d
    UINT8       cpich_ecn0;         //EC2N0 (dBm - positive value presented positive) of serving cell (0xff) %d
    UINT8       rank_pos;           //Cell reselection ranking of the cell(0 for the best cell)
                                    //This value is used to order UMTS and GSM cells for the presentation - only in UMTS mode
    UINT16 ranking_value;           //The calculated ranking value %d - only in UMTS mode
    EmRankingStatus ranking_status; //Reason why the cell was not ranked %d - only in UMTS mode

    UmtsNcellParam() :
        cpich_sc(0xffff), dl_uarfcn(0xffff), cpich_rscp(0xffff), cpich_ecn0(0xff), rank_pos(0xff), ranking_value(0xffff)
        {}//UmtsNcellParam
    
    BOOLEAN IsCpichScInvalid()      { return cpich_sc == 0xffff; }
    BOOLEAN DlUarfcnInvalid()       { return dl_uarfcn == 0xffff; }
    BOOLEAN IsCpichRscpInvalid()    { return cpich_rscp == 0xffff; }
    BOOLEAN IsCpichEcn0Invalid()    { return cpich_ecn0 == 0xff; }
    BOOLEAN IsRankPosInvalid()      { return rank_pos == 0xff;}
    BOOLEAN IsRankingValueInvalid() { return ranking_value == 0xffff;}

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    UmtsNcellParam operator = (T_UMTS_NCELL_PARAM umts_ncell_param);
#endif
};//UmtsNcellParam


/*----------------------------------------------------------------------------*/
/*                       struct UmtsCellList                                  */
/*                       (T_UMTS_CELL_LIST in ms_testparam_umts.pr)           */
/*----------------------------------------------------------------------------*/
struct UmtsCellList {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum {MaxTotalUmtsCells = EM_MAX_TOTAL_UMTS_CELLS};
#else
    enum {MaxTotalUmtsCells = 24};
#endif

    UmtsNcellParam  umts_neighbour_cells[MaxTotalUmtsCells];    

    UmtsNcellParam& operator[](INT index) { return umts_neighbour_cells[index]; }    

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    UmtsCellList operator = (T_UMTS_CELL_LIST umts_cell_list);
#endif
};//UmtsCellList


/*----------------------------------------------------------------------------*/
/*                       struct RrcProcessState                               */
/*                       (T_RRC_PROCESS_STATE in ms_testparam_umts.pr)        */
/*----------------------------------------------------------------------------*/
struct RrcProcessState {
    UINT8   event;          //Bit map for RRC process event - zero means no event %x
    UINT8   process_state;  //RRC process SDL state %d

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    RrcProcessState operator = (T_RRC_PROCESS_STATE rrc_process_state);
#endif
};//RrcProcessState


/* --------------------------------------------------------------------- */
/* -------------    struct CellChangeCnts  ----------------------------- */
/*                  T_CELL_CHANGE_CNTS in ms_testparam_umts.pr           */
/* --------------------------------------------------------------------- */
struct CellChangeCnts {
   UINT8    cr_cnt;         /* number of successful intra UMTS or GSM cell reselections */
   UINT8    cr_cnt_at;      /* number of attempted intra UMTS or GSM cell reselections  */
   UINT8    ir_cr_cnt_su;   /* number of successful UMTS to GSM cell reselections       */
   UINT8    ir_cr_cnt_at;   /* number of attempted UMTS to GSM cell reselections        */
   UINT8    ir_hocc_cnt_su; /* number of successful UMTS to GSM HO or cell changes      */
   UINT8    ir_hocc_cnt_at; /* number of attempted UMTS to GSM HO or cell changes       */
   BOOLEAN  reset_mm_cnt;   /* Reset counters in MM - parameter only used from RRC      */

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
   CellChangeCnts operator = (T_CELL_CHANGE_CNTS cell_change_cnts);
#endif
};//CellChangeCnts


/* --------------------------------------------------------------------- */
/* ----------   struct UmtsNcellParamList                --------------- */
/*              T_UMTS_NCELL_PARAM_LIST in ms_testparam_umts.pr          */
/* --------------------------------------------------------------------- */
struct UmtsNcellParamList {
   UINT8        no_active_set_cells;          /* Number of ACTIVE SET cells (CELL_DCH)*/
   UINT8        no_virtual_active_set_cells;  /* Number of VIRTUAL ACTIVE SET cells (CELL_DCH)*/
   UINT8        no_umts_cells;                /* Number of DETECTED UMTS cells (CELL_DCH) or
                                                 Number of UMTS neighbour cells (all states but CELL_DCH) */
   UmtsCellList umts_ncell_param_list; 

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
   UmtsNcellParamList operator = (T_UMTS_NCELL_PARAM_LIST umts_ncell_param_list);
#endif
};//UmtsNcellParamList





/* --------------------------------------------------------------------- */
/* ----------   struct AsTestparamDatabase               --------------- */
/*              T_AS_TESTPARAM_DATABASE in ms_testparam_umts.pr          */
/* --------------------------------------------------------------------- */
struct AsTestparamDatabase {
    BOOLEAN         reset_em;               /* Indication that MM shall reset cell change 
                                               counters.                                 */
    RrcProcessState rrcdc_state;            /* State and present procedure run in URRCDC */
    RrcProcessState rrcbp_state;            /* State and present procedure run in URRCBP */
    RrcProcessState rrcm_state;             /* State and present procedure run in URRCM  */
   
    MmRrReason      chn_rel_cause;          /* Channel release cause                     */
    BOOLEAN         cipher_on;              /* Ciphering: present if true                */
    BOOLEAN         ps_transfer;            /* Data has been transfered during the last  */ 
    PowerSavingMode power_saving_mode;      /* Inidcation about the powersaving mode     */
    UINT8           as_error_code;          /* Indication about error in UAS             */   
    CellChangeCnts  cell_change_ind;        /* Indication that a cell change has taken 
                                               place. The MM reads the info and merges info
                                               about started and successful cell changes
                                               from both GSM and UMTS                    */
    UINT8           ul_meas_cnt;            /* Number of measurements sent during the last
                                               reporting period                          */
    BOOLEAN         limited_service;        /* Limited service camped (true) or
                                               normal service camped (false) 
                                               only valid if arfcn is not INVALID_ARFCN
                                               reporting period                          */
    BOOLEAN         out_of_service;         /* Out of service detected (present if true 
                                               otherwise blank.                          */

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    AsTestparamDatabase operator = (T_AS_TESTPARAM_DATABASE as_testparam_database);
#endif
};//AsTestparamDatabase




/***************************************************************************************************
                                    END OF UMTS SPEC TYPES
***************************************************************************************************/


/*  ========================================================================
                                  NetType
    ========================================================================*/
enum NetType
{
    Gsm900              = NET_GSM900,
    Gsm1800             = NET_GSM1800,
    Gsm900_1800         = NET_GSM900_1800,
    Gsm1900             = NET_GSM1900,
    Gsm900_1900         = NET_GSM900_1900,
    Gsm1800_1900        = NET_GSM1800_1900,
    Gsm900_1800_1900,   // = NET_GSM900_1800_1900,
    ThirdGeneration     // = NET_3G
}; 


/*  ========================================================================
                                  NetworkSearchMode
    ========================================================================*/
enum NetworkSearchMode {
    NormalSearchMode = NORMAL_SEARCH_MODE,
    FastSearchMode = FAST_SEARCH_MODE,
    InvalidSearchMode = 0xff
};//NetworkSearchMode



/*  ========================================================================
                              Plmn
    ========================================================================*/
enum RegisterMode {
    Automatic = AUTOMATIC_MODE,     // automatic registration
    Manual    = MANUAL_MODE,        // manual registration
    RegisterModeUnavailable     // undefined state
};


enum PlmnIndicator {
    PlmnNotProvided = PLMN_NOT_PROVIDED,
    PlmnProvided    = PLMN_PROVIDED
};


enum PlmnForbiddenIndicator {
    PlmnNotForbidden = PLMN_NOT_FORBIDDEN,
    PlmnForbidden    = PLMN_FORBIDDEN
};


typedef INT PlmnPlacementIndicator;

/*  -----------------------------------------------------------------------
    Plmn bcd coded
    ----------------------------------------------------------------------- */
typedef UINT16 BcdMcc;
typedef UINT8 BcdMnc;

const BcdMcc    InvalidBcdMcc = 0xffff;
const BcdMnc    InvalidBcdMnc = 0xff;

class BcdPlmn {
    public:
        BcdPlmn() : mcc(0xffff), mnc(0xff) {}
        BcdPlmn(BcdMcc _mcc, BcdMnc _mnc) : mcc(_mcc), mnc(_mnc) {}
        BcdPlmn(const BcdPlmn & plmn) {
             mcc = plmn.mcc;
             mnc = plmn.mnc;
        }
        BcdPlmn(const T_PLMN & plmn) {
             mcc = plmn.mcc;
             mnc = plmn.mnc;
        }


        BOOLEAN IsInvalid() const { return (mcc == InvalidBcdMcc && mnc == InvalidBcdMnc); }
        void SetInvalid() { mcc = InvalidBcdMcc; mnc = InvalidBcdMnc; }
        void Init(BcdMcc _mcc, BcdMnc _mnc) { mcc = _mcc; mnc = _mnc; }
        BOOLEAN IsEqual(const BcdPlmn & plmn) const { return (mcc == plmn.mcc && mnc == plmn.mnc); }

        BcdPlmn operator = (const BcdPlmn & plmn){
            mcc = plmn.mcc;
            mnc = plmn.mnc;
            return *this;
        }
        BcdPlmn operator = (const T_PLMN & plmn){
            mcc = plmn.mcc;
            mnc = plmn.mnc;
            return *this;
        }

        BcdMcc  mcc;        // Mobile Country Code (3-digits, 2 bytes)
        BcdMnc  mnc;        // Mobile Network Code (3-digits, 1 byte)


};                          

#define InvalidBcdPlmn BcdPlmn()

/*  -----------------------------------------------------------------------
    Plmn decimal coded
    ----------------------------------------------------------------------- */
// plmn identification (ms.h: T_PLMN)
typedef UINT16 Mcc;
typedef UINT16 Mnc;

const Mcc       InvalidMcc = 0xffff;
const Mnc       InvalidMnc = 0xffff;

class Plmn {
    public:
        Plmn() : mcc(0xffff), mnc(0xffff), threedigitmnc(FALSE) {}
        Plmn(Mcc _mcc, Mnc _mnc, BOOLEAN _threedigitmnc = FALSE) 
            : mcc(_mcc), mnc(_mnc), threedigitmnc(_threedigitmnc) {}
        Plmn(const Plmn & plmn) { 
             mcc = plmn.mcc;
             mnc = plmn.mnc;
             threedigitmnc = plmn.threedigitmnc;
        }
        BOOLEAN IsInvalid() const { return (mcc == InvalidMcc && mnc == InvalidMnc); }
        void SetInvalid() { mcc = InvalidMcc; mnc = InvalidMnc; threedigitmnc=FALSE; }
        void Init(Mcc _mcc, Mnc _mnc, BOOLEAN _threedigitmnc = FALSE) { 
            mcc = _mcc; mnc = _mnc; threedigitmnc = _threedigitmnc;
        }
        BOOLEAN IsEqual(const Plmn & plmn) const { 
            return (mcc == plmn.mcc && mnc == plmn.mnc && threedigitmnc==plmn.threedigitmnc); 
        }
        Plmn operator = (const BcdPlmn & bcdplmn);
        
        Mcc mcc;    
        Mnc mnc;                
        BOOLEAN threedigitmnc;  
   
};                          

#define InvalidPlmn Plmn()

/*  -----------------------------------------------------------------------
    Usim Plmn 
    ----------------------------------------------------------------------- */
// T_USIMAP_PLMN_ELEM
struct UsimPlmn {
    BcdPlmn m_plmn;
    UINT16  m_rat;
};

/*  -----------------------------------------------------------------------
    Usim Plmn List
    ----------------------------------------------------------------------- */
#if ! defined(USIMAP_PLMN_LIST_LEN)
    #define USIMAP_PLMN_LIST_LEN 8
#endif

const INT c_maxno_usim_plmns = USIMAP_PLMN_LIST_LEN;

// T_USIMAP_PLMN_LIST
struct UsimPlmnList {
    UsimPlmn val[c_maxno_usim_plmns];
};

/*  ------------------------------------------------------------------------
    plmn array
    ------------------------------------------------------------------------ */
// plmn orginal T_SI_DATA
/*
struct PlmnArray {
    UINT8 val[32];
    const BcdPlmn & GetPlmn(INT recno) const {
                    ASSERT(recno*3<sizeof(PlmnArray));
                    return *(BcdPlmn*)&val[recno*3];   // sizeof Plmn would deliver 4 under MSDEV
                };
};
*/

/*  ========================================================================
                              Connection info
    ========================================================================*/
typedef UINT32  CellId;  //Cell Identity (attention: the corresponding stack type for gfs18 is still UINT16, while gfs20 is using UINT32)
typedef UINT16  Lac;     //Location Area Code


const CellId  InvalidCellId= 0xffff;
const Lac     InvalidLac= 0xffff;




struct Lai {
    Plmn plmn;
    Lac lac;
};

/********************************************************/
/*          RAT - Radio Access Technology (T_RAT)       */
/********************************************************/
enum RadioAccessTechnology {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    RatNotAvailable = RAT_NOT_AVAILABLE,
    RatGsm          = RAT_GSM,
    RatUmts         = RAT_UMTS
#else
    RatNotAvailable,
    RatGsm,
    RatUmts
#endif
};//RadioAccessTechnology


/********************************************************/
/*           (T_RAT_CHANGE_MODE)                        */
/********************************************************/
enum RatChangeMode {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    RatChangeModeGsm    = RAT_CHANGE_MODE_GSM,
    RatChangeModeUmts   = RAT_CHANGE_MODE_UMTS,
    RatChangeModeDual   = RAT_CHANGE_MODE_DUAL,
#else
    RatChangeModeGsm,
    RatChangeModeUmts,
    RatChangeModeDual,
#endif
    InvalidRatChangeMode                        //for APOXI use only
};

/********************************************************/
/*           TransformRatToUsimAct                      */
/********************************************************/
inline UINT16 TransformRatToUsimAct(RadioAccessTechnology rat) 
{
    switch(rat) {
        case RatGsm: return  0x0080;    // b8 set of low byte
        case RatUmts: return 0x8000;    // b8 set of high byte
    }
    return 0x0000;
}

/********************************************************/
/*           TransformUsimActToRat                      */
/********************************************************/
inline RadioAccessTechnology TransformUsimActToRat(UINT16 act) 
{
    if((act & 0x8000)==0x8000) {
        return RatUmts;
    } else if((act & 0x0080)==0x0080) {
        return RatGsm;
    }
    return RatNotAvailable;
}


/********************************************************/
/*           (T_GSM_BAND)                               */
/********************************************************/
enum GsmBand {
    GsmBand900 = MS_GSM900,
    GsmBand900P = MS_GSM900_P, 
    GsmBand900E = MS_GSM900_E,
    GsmBand1800 = MS_GSM1800, 
    GsmBand1900 = MS_GSM1900,  
    GsmBand850 =  MS_GSM850,
    GsmBand450 = MS_GSM450,
    GsmBand480 = MS_GSM480,
    GsmBand900R = MS_GSM900_R,
    GsmMultiband = MS_MULTIBAND,
    InvalidGsmBand = INVALID_BAND
};//GsmBand



/*----------------------------------------------------------------------------------------------*/
/* struct GsmBandList                                                                           */
/* (T_BAND_LIST in /ms-hosttest/mi/src/../../../ms-interface-src/pr/ms_gsm_multiband.pr,100,9)) */
/*----------------------------------------------------------------------------------------------*/
struct GsmBandList {
    enum {MaxGsmBands = BAND_LIST_LENGTH};
    GsmBand gsm_bands[MaxGsmBands]; 
    GsmBand& operator[](INT index) { return gsm_bands[index]; }  
    GsmBandList operator = (T_BAND_LIST gsm_band_list);
};//GsmBandList


enum GprsClass {
    GprsClassA  = GPRS_CLASS_A,
    GprsClassB  = GPRS_CLASS_B,
    GprsClassC  = GPRS_CLASS_C,
    GprsClassCg = GPRS_CLASS_CG,
    GprsClassCc = GPRS_CLASS_CC,
    GprsNoClass = GPRS_NO_CLASS,
    InvalidGprsClass = 0xff
};              




/**************************************************************************************************/
/**************************************************************************************************/
/**************************** Structures for Engineering Mode *************************************/
/**************************************************************************************************/
/**************************************************************************************************/

enum NetworkOpMode {
    NoGprsCell= NO_GPRS_CELL,
    NwOpMode1=  NW_OP_MODE_1,
    NwOpMode2=  NW_OP_MODE_2,
    NwOpMode3=  NW_OP_MODE_3,
    InvalidOpMode = 0xff
};//enum NetworkOpMode

enum RegState {
    Regst_user_attach_pending = REGST_USER_ATTACH_PENDING,
    Regst_user_detach_pending = REGST_USER_DETACH_PENDING,
    Regst_ps_suspended        = REGST_PS_SUSPENDED,
    Regst_cs_connection       = REGST_CS_CONNECTION,
    Regst_indep_registration  = REGST_INDEP_REGISTRATION,
    Regst_plmn_selection      = REGST_PLMN_SELECTION,
    Regst_search_for_network  = REGST_SEARCH_FOR_NETWORK,
    Invalid_reg_state         = 0xff
};//RegState

//T_RR_CELL_RESEL_REASON in ms_testparam_gsm.pr
enum RrCellReselReason {
    ReselPlmnChange             =   RESEL_PLMN_CHANGE,              /*#NAME 'RESEL_PLMN_CHANGE' */
    MonReselServCellNotSuitable =   MON_RESEL_SERV_CELL_NOT_SUITABLE,/*#NAME 'MON_RESEL_SERV_CELL_NOT_SUITABLE' */
    ReselBetterC2C32            =   RESEL_BETTER_C2_C32,            /*#NAME 'RESEL_BETTER_C2_C32' */
    ReselDownlinkFail           =   RESEL_DOWNLINK_FAIL,            /*#NAME 'RESEL_DOWNLINK_FAIL' */
    ReselRaFailure              =   RESEL_RA_FAILURE,               /*#NAME 'RESEL_RA_FAILURE' */
    ReselSiReceiptFailure       =   RESEL_SI_RECEIPT_FAILURE,       /*#NAME 'RESEL_SI_RECEIPT_FAILURE' */
    ReselC1LessNull             =   RESEL_C1_LESS_NULL,             /*#NAME 'RESEL_C1_LESS_NULL' */
    ReselCallReestTimeout       =   RESEL_CALL_REEST_TIMEOUT,       /*#NAME 'RESEL_CALL_REEST_TIMEOUT' */
    ReselAbnormalResel          =   RESEL_ABNORMAL_RESEL,           /*#NAME 'RESEL_ABNORMAL_RESEL' */
    ReselCellChangeOrder        =   RESEL_CELL_CHANGE_ORDER,        /*#NAME 'RESEL_CELL_CHANGE_ORDER' */
    ReselNotOccurred            =   RESEL_NOT_OCCURRED              /*#NAME 'RESEL_NOT_OCCURRED' */
};//RrCellReselReason

// T_C_OVER_I_LIST in gsm_testparam.pr
struct COverIList {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum {LengthOfCOverIArray = TESTPARAM_CI_CS_COUNT};
#else
    enum {LengthOfCOverIArray = 4};
#endif
    INT length;
    SignalStrengthLevel c_over_i_array[LengthOfCOverIArray];

    BOOLEAN IsEmpty();
    SignalStrengthLevel& operator[](INT index);

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    COverIList operator = (T_C_OVER_I_LIST c_over_i_list);
#endif
};

// T_ACK_NACK_CNT in gsm_testparam.pr
struct AckNackCnt {
    INT ack_blocks;
    INT nack_blocks;

    AckNackCnt() : ack_blocks(0xFFFF), nack_blocks(0xFFFF)  {}

    BOOLEAN IsAckBlocksInvalid() { return ack_blocks == 0xFFFF; }
    BOOLEAN IsNackBlocksInvalid() { return nack_blocks == 0xFFFF; }

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    AckNackCnt operator =(T_ACK_NACK_CNT ack_nack_cnt);
#endif
};

// T_ACK_NACK_TESTPARAM_CNT in gsm_testparam.pr
struct AckNackTestparamCnt {
    AckNackCnt dl_blocks;   /* ack/nack blocks in downlink */
    AckNackCnt ul_blocks;   /* ack/nack blocks in uplink */

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    AckNackTestparamCnt operator =(T_ACK_NACK_TESTPARAM_CNT ack_nack_testparam_cnt);
#endif
};

// T_ACK_NACK_PARAM_LIST) in gsm_testparam.pr
struct AckNackParamList {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum {LengthOfAckNackTestParamCntArray = TESTPARAM_CI_CS_COUNT};
#else
    enum {LengthOfAckNackTestParamCntArray = 4};
#endif
    INT     length;
    AckNackTestparamCnt ack_nack_testparam_cnt_array[LengthOfAckNackTestParamCntArray];

    BOOLEAN IsEmpty();  
    AckNackTestparamCnt& operator[](INT index);

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    AckNackParamList operator = (T_ACK_NACK_PARAM_LIST ack_nack_param_list);
#endif
};

/*----------------------------------------------------------------------------*/
/*                       struct GprsParam (for GPRS)                          */
/*                       T_GPRS_PARAM is part of T_SCELL_PARAM                */
/*----------------------------------------------------------------------------*/
struct GprsParam {
    BOOLEAN gprs_sup;          //is GPRS supported
    BYTE rac;                  //Routing Area Code  
    BOOLEAN split_pg_cycle;    //Split pg cycle on ccch by network
    INT nco;     // ??? SDL_Integer => INT not BYTE??
    NetworkOpMode net_op_mode; //Network Operation Mode
    UINT16 t3192;
    INT acc_burst_type;        //Access Burst Type
    BYTE drx_max;              //DRX Timer maximal
    BOOLEAN pbcch_present;     //PBCCH present
    INT emo;                   //extended measurement order
    BYTE psi1_repeat;          //PSI1 repeat period
    BYTE psi_count_lr;         //PSI count LR
    BYTE psi_count_hr;         //PSI count HR
    BYTE cr_hyst;              //cell reselect hysteresis
    INT  c31;                  //C31
    INT  c32;                  //C32
    BYTE acc_thr;              //Priority access THR
    BOOLEAN si13_present;      //SI13 present
    COverIList c_over_i;       //(Ccs - I) for coding scheme 1,2,3,4 (resolution acc. GSM05.08,8.1.4)
    AckNackParamList no_ack_nack_blocks; // number of received/lost RLC data blocks for coding scheme 1,2,3,4

    GprsParam() :
        gprs_sup(FALSE), rac(0xff), split_pg_cycle(FALSE), nco(0), net_op_mode(InvalidOpMode),
        t3192(0xffff), acc_burst_type(0), drx_max(0xff), pbcch_present(FALSE), emo(0), psi1_repeat(0xff),
        psi_count_lr(0xff), psi_count_hr(0xff), cr_hyst(0xff), c31(0), c32(0), acc_thr(0xff), si13_present(FALSE)
    {} // GprsParam()

    BOOLEAN IsGprsSupported()           { return gprs_sup; }
    BOOLEAN IsRacInvalid()              { return rac == 0xff; }
    BOOLEAN IsSplitPgCycle()            { return split_pg_cycle; }
    BOOLEAN IsNcoInvalid()              { return nco == 0; }
    BOOLEAN IsNetworkOpModeInvalid()    { return net_op_mode == InvalidOpMode; }
    BOOLEAN IsT3192Invalid()            { return t3192 == 0xffff; }
    BOOLEAN IsAccessBurstTypeInvalid()  { return acc_burst_type == 0; }
    BOOLEAN IsDrxMaxInvalid()           { return drx_max == 0xff; }
    BOOLEAN IsPbcchPresent()            { return pbcch_present; }
    BOOLEAN IsEmoInvalid()              { return emo == 0; }
    BOOLEAN IsPsi1RepeatPeriodInvalid() { return psi1_repeat == 0xff; }
    BOOLEAN IsPsiCountLrInvalid()       { return psi_count_lr == 0xff; }
    BOOLEAN IsPsiCountHrInvalid()       { return psi_count_hr == 0xff; }
    BOOLEAN IsCellReselectHystInvalid() { return cr_hyst == 0xff; }
    BOOLEAN IsC31Invalid()              { return c31 == 0; }
    BOOLEAN IsC32Invalid()              { return c32 == 0; }
    BOOLEAN IsAccThrInvalid()           { return acc_thr == 0xff; }
    BOOLEAN IsSi13Present()             { return si13_present; }

    GprsParam operator = (T_GPRS_PARAM gprs_param);
};//struct GprsParam



/*----------------------------------------------------------------------------*/
/*                            struct MmcsParam (for GPRS, GSM97)              */
/*                            T_MMCS_TESTPARAM                                */
/*----------------------------------------------------------------------------*/
struct MmcsParam { 
    INT state;                  //State of Mobility Management
    INT update_status;      //Location update status
    INT service_state;     //Mobility Management Service State
    INT timer;               //Bitmap indicating active timers

    MmcsParam() :
        state(0xff), update_status(0xff), service_state(0xff),
        timer(0xff)
    {}//MmcsParam()

    BOOLEAN IsStateInvalid()        { return state == 0xff; }
    BOOLEAN IsUpdateStatusInvalid() { return update_status == 0xff; }
    BOOLEAN IsServiceStateInvalid() { return service_state == 0xff; }
    BOOLEAN IsTimerInvalid()        { return timer == 0xff; }

    MmcsParam operator = (T_MMCS_TESTPARAM mmcs_testparam);
};//MmcsParam


/*----------------------------------------------------------------------------*/
/*                            struct GmmParam (for GPRS)                      */
/*                            T_GMM_TESTPARAM                                 */
/*----------------------------------------------------------------------------*/
struct GmmParam { 
    INT state;               //State of Mobility Management
    INT update_status;   //Location update status
    INT service_state;   //Mobility Management Service State
    INT timer;            //Bitmap indicating active timers
    BOOLEAN ready_connected;     //Ready or PMM_Connected

    GmmParam() :
        state(0xff), update_status(0xff), service_state(0xff),
        timer(0xff), ready_connected(FALSE)
    {}//GmmParam()

    BOOLEAN IsStateInvalid()        { return state == 0xff; }
    BOOLEAN IsUpdateStatusInvalid() { return update_status == 0xff; }
    BOOLEAN IsServiceStateInvalid() { return service_state == 0xff; }
    BOOLEAN IsTimerInvalid()        { return timer == 0xff; }

    GmmParam operator = (T_GMM_TESTPARAM gmm_testparam);
};//GmmParam


/*----------------------------------------------------------------------------*/
/*                            struct MmCoordParam (for GPRS)                  */
/*                            T_MMCOORD_TESTPARAM                             */
/*----------------------------------------------------------------------------*/
struct MmCoordParam { 
    INT state;           //State of Mobility Management
    RegState reg_state;      //MM service state
    INT timer;        //Bitmap indicating active timers
    GprsClass gprs_class;    //GPRS class 
    GsmBand gsm_band;        //GSM band

    MmCoordParam() :
        state(0xff), reg_state(Invalid_reg_state), timer(0xff),
        gprs_class(InvalidGprsClass), gsm_band(InvalidGsmBand)
    {}//MMCoordParam

    BOOLEAN IsStateInvalid()        { return state == 0xff; }   
    BOOLEAN IsRegStateInvalid()        { return reg_state == Invalid_reg_state; }   
    BOOLEAN IsTimerInvalid()        { return timer == 0xff; }
    BOOLEAN IsGprsClassInvalid()    { return gprs_class == InvalidGprsClass; }
    BOOLEAN IsGsmBandInvalid()      { return gsm_band == InvalidGsmBand; }

    MmCoordParam operator = (T_MMCOORD_TESTPARAM mmcoord_testparam);
};//MmCoordParam


/*----------------------------------------------------------------------------*/
/*                       struct NeighbourCell (for GPRS, GSM97, GSM97ds)      */
/*                       T_NCELL_PARAM                                        */
/*----------------------------------------------------------------------------*/
struct NeighbourCell {                                                                 // GPRS GSM97 GSM97ds  UMTS
    UINT16 mcc;                 //Mobile Country Code                                       x   x              x
    UINT16  mnc;                //Mobile Network Code                                       x   x              x
    Plmn plmn;                  //Mobile Network code and mobile country cod + three digits
    UINT16 lac;                 //Location Area Code                                        x   x              x
    UINT16 cell_id;             //Cell Identity                                             x   x              x
    BYTE   bsic;                //Base Transceiver Station Identity Code                    x   x   x          x
    UINT16 arfcn;               //Absolut Radio Frequency Channel Number                    x   x   x          x
    SignalStrengthLevel  rxlev; //Received Signal Level                                     x   x   x          x
    INT c1;                     //C1 of neighbour cell                                      x   x              x
    INT c2;                     //C2 of neighbour cell                                      x   x              x
    INT c31;                    //C31 of neighbour cell                                     x                  x
    INT c32;                    //C32 of neighbour cell                                     x                  x
    
    UINT8               rank_pos;       //Cell reselection ranking of the cell                                 x
                                        //(0 for the best cell)
                                        //This value is used to order UMTS and GSM cells 
                                        //for the presentation - only in UMTS mode                           
    UINT16              ranking_value;  //The calculated ranking value %d - only in UMTS mode                  x
    EmRankingStatus     ranking_status; //Reason why the cell was not ranked %d - only in UMTS mode            x

    NeighbourCell() : 
        mcc(0xffff), mnc(0xffff), plmn(), lac(0xffff), cell_id(0xffff), bsic(0xff), arfcn(0xffff),
        rxlev(InvalidSignalStrengthLevel), c1(0xffff), c2(0xffff), c31(0xffff), c32(0xffff),
        rank_pos(0xff), ranking_value(0xffff)
    {}//NeighbourCell()

    BOOLEAN IsMccInvalid()          { return mcc == 0xffff; }
    BOOLEAN IsMncInvalid()          { return mnc == 0xffff; }
    BOOLEAN IsPlmnInvalid()         { return plmn.IsInvalid(); }
    BOOLEAN IsLacInvalid()          { return lac     == 0xffff; }
    BOOLEAN IsCellIdInvalid()       { return cell_id == 0xffff; }
    BOOLEAN IsBsicInvalid()         { return bsic    == 0xff; }
    BOOLEAN IsArfcnInvalid()        { return arfcn   == 0xffff; }
    BOOLEAN IsRxlevInvalid()        { return rxlev   == InvalidSignalStrengthLevel; }   
    BOOLEAN IsC1Invalid()           { return c1 == 0xffff; }
    BOOLEAN IsC2Invalid()           { return c2 == 0xffff; }
    BOOLEAN IsC31Invalid()          { return c31 == 0xffff; }
    BOOLEAN IsC32Invalid()          { return c32 == 0xffff; }
    BOOLEAN IsRankPosInvalid()      { return rank_pos == 0xff;}
    BOOLEAN IsRankingValueInvalid() { return ranking_value == 0xffff;}

    NeighbourCell operator = (T_NCELL_PARAM ncell_param);
}; //struct NeighbourCell


/*----------------------------------------------------------------------------*/
/*                       struct NeighbourCellList (for GPRS, GSM97, GSM97ds)  */
/*                       T_GSM_NCELL_PARAM_LIST , T_NCELL_PARAM_LIST          */
/*----------------------------------------------------------------------------*/
struct NeighbourCellList {  
    enum {MaxListSize= MAX_NCELL_PARAM};
    UINT8 nr_of_cells;
    NeighbourCell neighbour_cells[MaxListSize]; 

    BOOLEAN IsEmpty()   { return nr_of_cells == 0;  }
    NeighbourCell& operator[](INT index) { return neighbour_cells[index]; } 

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    NeighbourCellList operator = (T_GSM_NCELL_PARAM_LIST gsm_ncell_param_list);
#else
    NeighbourCellList operator = (T_NCELL_PARAM_LIST gsm_ncell_param_list);
#endif
};//struct NeighbourCellList

/*----------------------------------------------------------------------------*/
/*                       struct CellParam (for GPRS, GSM97, GSM97ds)          */
/*                       T_SCELL_PARAM                                        */
/*----------------------------------------------------------------------------*/
struct CellParam {                                                                    // GPRS GSM97 GSM97ds
    UINT16 mcc;                     //Mobile Country Code                                   x   x   x   
    UINT16 mnc;                     //Mobile Network Code                                   x   x   x
    Plmn plmn;                      //Mobile Network code and mobile country code + three digits
    UINT16 lac;                     //Location Area Code                                    x   x   x
    UINT16 cell_id;                 //Cell Identity                                         x   x   x
    BYTE   bsic;                    //Base Transceiver Station Identity Code                x   x
    BYTE   bsic_ncc;                //Base Transceiver Station Identity Code / NCC                  x
    BYTE   bsic_bcc;                //Base Transceiver Station Identity Code / BCC                  x
    UINT16  arfcn;                  //Absolut Radio Frequency Channel Number                x   x   x
    SignalStrengthLevel rxlev_serv; //RXLEV of serving cell                                 x   x
    INT no_rf_chans;                //Number of frequencies in MA                           x   x
    UINT16 arfcn_ded;               //Single absolut radio-frequency of dedicated channel   x   x   
    SignalStrengthLevel rxlev_full; //Received Signal Strength Level Full                   x   x   x
    SignalStrengthLevel rxlev_sub;  //Received Signal Strength Level Sub                    x   x   x
    SignalQualityLevel rxqual_full; //Received Signal Quality Full                          x   x   x
    SignalQualityLevel rxqual_sub;  //Received Signal Quality Sub                           x   x   x
    BOOLEAN cipher_on;              //Ciphering off(=false) or on(=true)                    x   x
    BYTE ms_tx_power_max_cch;       //Ms transmit power max cch                             x   x   x
    BYTE rxlev_access_min;          //received signal level access minimum                  x   x   x
    BYTE cell_bar_qualify;          //cell bar qualify                                      x   x   x
    BYTE cell_bar_access;           //cell bar access                                       x   x   x
    BYTE c2_valid_params;           //CELL_RESELECT_PARAM_IND (invalid if no c2 params)     x   x   x
    BYTE cell_reselect_offset;      //Cell reselect offset                                  x   x   x
    BYTE tmp_offset;                //Temporary offset                                      x   x   x
    BYTE penalty_time;              //Penalty Time                                          x   x   x
    INT  c1;                        //C1                                                    x   x   x
    INT  c2;                        //C2                                                    x   x   x
    BYTE channel_type;              //Channel Type                                          x   x   x
    BYTE channel_mode;              //Channel Mode                                          x   x   x
    BYTE tx_power_level;            //Transmit power level                                  x   x   x
    BYTE dtx_used;                  //DTX used                                              x   x   x
    UINT16 t3212;                   //T3212                                                 x   x   x
    UINT16 access_control_class;    //Access control class                                  x   x   x
    BYTE timing_advance;            //Timing advance                                        x   x   x
    BYTE bs_pa_mfrms;               //BS_PA_MFRMS                                           x   x   x
    BYTE dsc;                       //Downlink Signal Counter                               x   x
    BYTE rll;                       //Radio Link Loss Counter (for GPRS)                    x
    INT  cell_change_cnt;           //Number of sucessful intra GSM cell changes            x


    CellParam()  : 
        mcc(0xffff), mnc(0xffff), lac(0xffff), cell_id(0xffff), bsic(0xff), bsic_ncc(0xff),bsic_bcc(0xff), arfcn(0xffff),
        rxlev_serv(InvalidSignalStrengthLevel), no_rf_chans(0), arfcn_ded(0xffff), rxlev_full(InvalidSignalStrengthLevel),
        rxlev_sub(InvalidSignalStrengthLevel), rxqual_full(InvalidSignalStrengthLevel),
        rxqual_sub(InvalidSignalStrengthLevel), cipher_on(FALSE), ms_tx_power_max_cch(0xff),
        rxlev_access_min(0xff), cell_bar_qualify(0xff), cell_bar_access(0xff), c2_valid_params(0xff), 
        cell_reselect_offset(0xff), tmp_offset(0xff), penalty_time(0xff), c1(0), c2(0), channel_type(0xff), 
        channel_mode(0xff), tx_power_level(0xff), dtx_used(0xff), t3212(0xffff), access_control_class(0xffff), 
        timing_advance(0xff), bs_pa_mfrms(0xff), dsc(0xff), rll(0xff), cell_change_cnt(0)
    {} //CellParam()


    BOOLEAN IsMccInvalid()    { return mcc == 0xffff; }
    BOOLEAN IsMncInvalid()    { return mnc == 0xffff; }
    BOOLEAN IsPlmnInvalid()    { return plmn.IsInvalid(); }
    BOOLEAN IsLacInvalid()    { return lac     == 0xffff; }
    BOOLEAN IsCellIdInvalid() { return cell_id == 0xffff; }
    BOOLEAN IsBsicInvalid()   { return bsic    == 0xff; }
    BOOLEAN IsBsicNccInvalid()   { return bsic_ncc    == 0xff; }
    BOOLEAN IsBsicBccInvalid()   { return bsic_bcc    == 0xff; }
    BOOLEAN IsArfcnInvalid()  { return arfcn   == 0xffff; }
    BOOLEAN IsRxlevServInvalid() { return rxlev_serv == InvalidSignalStrengthLevel; }
    BOOLEAN IsNoRfChansInvalid() { return no_rf_chans == 0; }
    BOOLEAN IsArfcnDedInvalid()  { return arfcn_ded == 0xffff; }
    BOOLEAN IsRxlevFullInvalid()  { return rxlev_full == InvalidSignalStrengthLevel; }  
    BOOLEAN IsRxlevSubInvalid()  { return rxlev_sub == InvalidSignalStrengthLevel; }        
    BOOLEAN IsRxqualFullInvalid()  { return rxqual_full == InvalidSignalQualityLevel; } 
    BOOLEAN IsRxqualSubInvalid()  { return rxqual_sub == InvalidSignalQualityLevel; }   
    BOOLEAN IsMsTxPowerMaxCchInvalid() { return ms_tx_power_max_cch == 0xff; }
    BOOLEAN IsRxlevAccessMinInvalid() { return rxlev_access_min == 0xff; }
    BOOLEAN IsCellBarQualifyInvalid() { return cell_bar_qualify == 0xff; }
    BOOLEAN IsCellBarAccessInvalid() { return cell_bar_access == 0xff; }
    BOOLEAN IsC2ValidParamsInvalid() { return c2_valid_params == 0xff; }
    BOOLEAN IsCellReselectOffsetInvalid() { return cell_reselect_offset == 0xff; }
    BOOLEAN IsTmpOffsetInvalid() { return tmp_offset == 0xff; }
    BOOLEAN IsPenaltyTimeInvalid() { return penalty_time == 0xff; }
    BOOLEAN IsC1Invalid() { return c1 == 0; }
    BOOLEAN IsC2Invalid() { return c2 == 0; }
    BOOLEAN IsChannelTypeInvalid() { return channel_type == 0xff; }
    BOOLEAN IsChannelModeInvalid() { return channel_mode == 0xff; }
    BOOLEAN IsTxPowerLevelInvalid() { return tx_power_level == 0xff; }
    BOOLEAN IsDtxUsedInvalid() { return dtx_used == 0xff; }
    BOOLEAN IsT3212Invalid() { return t3212 == 0xffff; }
    BOOLEAN IsAccessControlClassInvalid() { return access_control_class == 0xffff; }
    BOOLEAN IsTimingAdvanceInvalid() { return timing_advance == 0xff; }
    BOOLEAN IsBsPaMfrmsInvalid() { return bs_pa_mfrms == 0xff; }
    BOOLEAN IsDscInvalid() { return dsc == 0xff; }
    BOOLEAN IsRllInvalid() { return rll == 0xff; }
    BOOLEAN IsCellChangeCntInvalid() { return cell_change_cnt == 0; }

    CellParam operator = (T_SCELL_PARAM scell_param);
};//struct CellParam


/*----------------------------------------------------------------------------*/
/*                       struct RrParam (Radio Ressources)  (for GPRS, GSM97) */
/*                       T_RR_TESTPARAM                                       */
/*----------------------------------------------------------------------------*/
struct RrParam {
    INT        state;                   //SDL state of GRR  
    INT        cell_reselection_reason; //Cause of cell reselection
    MmRrReason channel_release_reason;  //Cause of channel release
    BOOLEAN    limited_service;         //Limited service campted (true), Normal service campted (false) ->only valid if invalid arfcn  
                                        //Normal service campted (false) 
                                        //->only valid if invalid arfcn 
    RrParam() :
        state(0xff), cell_reselection_reason(0xff), 
        channel_release_reason(InvalidMmRrReason), limited_service(FALSE)
    {}//RrParam()
        
    BOOLEAN IsStateInvalid() { return state == 0xff; }
    BOOLEAN IsCellReselectionReasonInvalid() { return cell_reselection_reason == 0xff; }
    BOOLEAN IsChannelReleaseReasonInvalid() { return channel_release_reason == InvalidMmRrReason; }

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    RrParam operator = (T_RR_TESTPARAM *rr_testparam);
#else
    RrParam operator = (T_RR_TESTPARAM rr_testparam);
#endif
};//RrParam

/*----------------------------------------------------------------------------*/
/*                       struct RrcParam                                      */
/*                       (T_RRC_TESTPARAM in ms_testparam_umts.pr)            */
/*----------------------------------------------------------------------------*/
struct RrcParam {
    UINT8               rrc_state;          /* RRC state                                 */
    RrcProcessState     rrcdc_state;        /* State and events in URRCDC                */
    RrcProcessState     rrcbp_state;        /* State and events in URRCBP                */
    RrcProcessState     rrcm_state;         /* State and events in URRCM                 */
   
    PowerSavingMode     power_saving_mode;  /* Indication about the powersaving mode     */
   
    MmRrReason          chn_rel_cause;      /* Channel release cause      %d             */
    BOOLEAN             ps_transfer;        /* Data has been transfered during the last 
                                               report period, present if true.           */ 
    UINT8               as_error_code;      /* Indication about error in UAS      %d     */
    UINT8               ul_meas_cnt;        /* Number of measurements sent during the last
                                               reporting period %d                       */
    INT8                oos_cnt;             /* Number of times UE went out of service    */
    UINT8               tx_pwr;             /* Tx output power */
    DchReport           l1_data;             /* containing BLER and other L1 data */
   
    UmtsRrcScellParam   umts_scell;         /* Parameters of UMTS serving cell                */
    
    UmtsMeasEvalParam   umts_meas_eval_param; /* UMTS measurement evaluation parameters    */
    
    RrcParam() :
        rrc_state(0xff), chn_rel_cause(InvalidMmRrReason), as_error_code(0xff), ul_meas_cnt(0xff)
    {}//RrcParam

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    RrcParam operator = (T_RRC_TESTPARAM *rrc_testparam);
#endif
};//RrcParam

/*
 *  T_EQUIV_PLMN_LIST, T_EQUIV_PLMN_ARRAY
 */
struct EquivPlmnLists {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum {LengthOfPlmnArray = LENGTH_OF_PLMN_ARRAY};
#else
    enum {LengthOfPlmnArray = 6};
#endif

    INT     length;
    Plmn    plmn_array[LengthOfPlmnArray];  

    BOOLEAN IsEmpty();
    Plmn& operator[](INT index);

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    EquivPlmnLists operator =(T_EQUIV_PLMN_LIST equiv_plmn_list);
#endif
};

/*----------------------------------------------------------------------------*/
/*                       struct TestparamReport (for GPRS, GSM97, GSM97ds)    */
/*                       T_TESTPARAM_REPORT                                   */
/*----------------------------------------------------------------------------*/    
struct TestparamReport {
    //T_MM_TESTPARAM_s
    
    MmcsParam cs_param;                 //data of circuit-switched MM (Mobility Management)) T_MMCS_TESTPARAM
    GmmParam ps_param;                  //data of packet-switched (Mobility Management)
    MmCoordParam coord_param;           //co-ordination parameter (Mobility Management)
    RrParam rr_param;                   //Radio Ressources 
    GprsParam gprs;                     //Gprs related Params  T_GPRS_PARAM is part of T_SCELL_PARAM
    
    //GSM
    CellParam serving_cell;             //Serving Cell for GSM
    NeighbourCellList neighbour_cells;  //Neighbour Cells for GSM   

    //UMTS
    UINT8               rat;             
    CellChangeCnts      cell_change_cnts;
    EquivPlmnLists      eq_plmn_list;    // added to T_MM_TESTPARAM_s => also for GSM?  
    NetworkOpMode       nom;             /* network operation mode                 */

    RrMode              rr_mode;        //umts or gsm-parameters(RRC or RR)
    
    RrcParam rrc_param; 
    UmtsNcellParamList umts_ncell_param;//UmtsNeighbour Cells => member of T_RR_TESTPARAM
    
    //UmtsNcellParamList in RR and RRC ???????????????

    enum TestParamReportComponent {
        CsParam,
        PsParam,
        CoordParam,
        RrParam,
        Gprs,
        ServingCell,
        NeighbourCells,

        Rat,                
        EqUplmList,         
        CellChangeCnts,

        RrMode,
        
        RrcParam,           
        UmtsNeighbourCells  
    };//TestParamReportComponent

    BOOLEAN IsComponentSupported(TestParamReportComponent comp) const {
        return true;
    } // IsComponentSupported
};// TestparamReport

/**************************************************************************************************/
/**************************** Engineering Mode: L1 Reporting **************************************/
/**************************************************************************************************/

// T_CI_TEST_PARAM in testparam.pr
struct CiTestParam {
    UINT8 no_blocks;      // Number of received blocks
    INT   sum_c_over_i;   /* Sum of (Ccs - I) over no_blocks for respective coding scheme
                             (resolution according GSM 05.08, 8.1.4) */
    CiTestParam() : no_blocks(0xFF), sum_c_over_i(0xFFFF) {}

    BOOLEAN IsNoBlocksInvalid() { return no_blocks == 0xFF; }
    BOOLEAN IsSumCOverIInvalid() { return sum_c_over_i == 0xFFFF; }

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    CiTestParam operator =(T_CI_TESTPARAM ci_testparam);
#endif
};

// T_CI_TESTPARAM_LIST in testparam.pr
struct CiTestParamList {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    enum {LengthOfCiTestparamArray = TESTPARAM_CI_CS_COUNT};
#else
    enum {LengthOfCiTestparamArray = 4};
#endif
    INT     length;
    CiTestParam ci_testparam_array[LengthOfCiTestparamArray];   

    BOOLEAN IsEmpty();
    CiTestParam& operator[](INT index);

#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    CiTestParamList operator =(T_CI_TESTPARAM_LIST ci_testparam_list);
#endif
};

/*----------------------------------------------------------------------------*/
/*                       struct L1Param (for GPRS)                            */
/*                       T_L1_TESTPARAM_s                                     */
/*----------------------------------------------------------------------------*/
struct L1Param {
    BYTE timing_advance;     //Timing advance 
    BYTE tx_power_level;     //Transmit power level
    BYTE dsc_pch;            //Downlink Signal Counter for cs-paging
    UINT16 dsc_ppch;         //Downlink Signal Counter for ps-paging
    BYTE rll;                //Radiolink Signal Counter
    BYTE rxqual;             //RXQUAL in idle mode, otherwise undefined
    CiTestParamList ci_param;  //C over I results array

    L1Param() : 
        timing_advance(0xff), tx_power_level(0xff), dsc_pch(0xff), 
        dsc_ppch(0xff), rll(0xff), rxqual(0xff)
    {} //L1Param
    
    BOOLEAN IsTimingAdvanceInvalid() { return timing_advance == 0xff; }
    BOOLEAN IsTxPowerLevelInvalid()  { return tx_power_level == 0xff; }
    BOOLEAN IsDscPchInvalid()        { return dsc_pch == 0xff; }
    BOOLEAN IsDscPpchInvalid()       { return dsc_ppch == 0xff; }
    BOOLEAN IsRllInvalid()           { return rll == 0xff; }
    BOOLEAN IsRxqualInvalid()        { return rxqual == 0xff; }

    L1Param operator = (T_L1_TESTPARAM_s l1_testparams);
};//L1Param

#endif  // Apc_NetworkTypes_hpp



