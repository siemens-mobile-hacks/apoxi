/*  ------------------------------------------------------------------------
    Copyright (C) 2002 COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_DataCall_DataCallContext_hpp)
#define Asc_DataCall_DataCallContext_hpp

#include <Apc/SignalTypes.hpp>

class DataCallContext {
    public:
        enum ConnectionElement {    // T_CONN_ELEMENT
            Transparent             = TRANSPARENT,
            NonTransparent          = NON_TRANSPARENT,
            TransparentPreferred    = TRANSPARENT_PREF,
            NonTransparentPreferred = NON_TRANSPARENT_PREF,
            ElementUndefined        = CONN_ELEMENT_UNDEFINED,
            InvalidConnectionElement
        };
        
        DataCallContext();

        ~DataCallContext();

        void Reset();

        void SetConnectionElement(ConnectionElement connection_element) { m_connection_element = connection_element; }
        
        ConnectionElement GetConnectionElement() const { return (m_connection_element); }
        
    private:
        ConnectionElement m_connection_element;
    
}; // class DataCallContext

    
/* The following types are not needed yet.


        enum ServiceMode {  // T_SERVICE_MODE
            SingleData                          = SINGLE_DATA,
            SingleFax                           = SINGLE_FAX,
            SingleVoice                         = SINGLE_VOICE,
            DualBs61                            = DUAL_BS61,
            DualBs81                            = DUAL_BS81,
            DualTs61                            = DUAL_TS61,
            GprsData                            = GPRS_DATA,
            Data3gAsync                         = DATA_3G_ASYNC,
            Data3gSync                          = DATA_3G_SYNC,
            GprsDdata3gMultimediaTelephonyta    = GPRS_DDATA_3G_MULTIMEDIA_TELEPHONYTA,
            InvalidServiceMode
        };

        enum SystemMode {   // T_SYSTEM_MODE
            Gem = GEM_MODE,
            Gsm = GSM_MODE,
            Umts = GSM_MODE,
            InvalidSystemMode
        };

        enum DataRate {     // T_DATA_RATE
            AutoBauding         = D_AUTOBAUDING,
            V110V22Bis_2400     = D_2400_V110_V22BIS,
            V110V26Ter_2400     = D_2400_V110_V26TER,
            V110V32_4800        = D_4800_V110_V32,
            V110V32_9600        = D_9600_V110_V32,
            V110None_2400       = D_2400_V110_NONE,
            V110None_4800       = D_4800_V110_NONE,
            V110None_9600       = D_9600_V110_NONE,
            V34_28800           = D_28800_V34,
            V110_56000          = D_56000_V110,
            BitTransp_56000     = D_56000_BIT_TRANSP,
            BitTransp_64000     = D_64000_BIT_TRANSP,
            Mulitmedia_28000    = D_28000_MULTIMEDIA,
            Mulitmedia_32000    = D_32000_MULTIMEDIA,
            Mulitmedia_56000    = D_56000_MULTIMEDIA,
            Mulitmedia_64000    = D_64000_MULTIMEDIA,
            Piafs_32000         = D_32000_PIAFS,
            Piafs_64000         = D_64000_PIAFS,
            Ftm_56000           = D_56000_FTM,
            Ftm_64000           = D_64000_FTM,
            NoneTrans_64000     = D_64000_NONE_TRANS,
            InvalidDataRate
        };

        enum SynchronType {     // T_SYNCHRON_TYPE 
            AsynModem   = ASYN_MODEM,
            SynModem    = SYN_MODEM,
            InvalidSynchonType
        };

struct RlpPar { // T_RLP_PAR
    INT rlp_vers;
    INT rlp_kim;
    INT rlp_kmi;
    INT rlp_t1;
    INT rlp_n2;
    INT rlp_t2;
};


typedef INT DcDirection;
// Value for T_DC_DIRECTION: Compression in neither direction (used for 
// V.25ter commands +DS and +DR and for XID parameter P0 in GSM 04.22)
const INT DsDcNone = DS_DC_NONE;            // 0

// Value for T_DC_DIRECTION: Compression in transmit direction only (used for 
// V.25ter commands +DS and +DR and for XID parameter P0 in GSM 04.22)
const INT DsDcV42bTd = DS_DC_V42B_TD;       // 1;

// Value for T_DC_DIRECTION: Compression in receive direction only (used for 
// V.25ter commands +DS and +DR and for XID parameter P0 in GSM 04.22)
const INT DsDcV42bRd = DS_DC_V42B_RD;       // 2;

// Value for T_DC_DIRECTION: Compression in both directions (used for V.25ter 
// commands +DS and +DR and for XID parameter P0 in GSM 04.22)
const INT DsDcV42bBd = DS_DC_V42B_BD;       // 3;

// Value for T_DC_DIRECTION: Error value (if DTN gets a value out of 
// the range 0-3)
const INT DsDcDirError = DS_DC_DIR_ERROR;   // 255;

struct DcPar {  // T_DC_PAR
    DcDirection direction;
    ULONG       max_dict; 
    INT         max_string;
};


INT DcNegotiation; // T_DC_NEGOTIATION; (0 or 1)
const DcNotDisconnect   = DS_DC_NOT_DISCONNECT;     // 0;
const DcDisconnect      = DS_DC_DISCONNECT          // 1;

struct T_ETBM {
    Integer pending_td;
    Integer pending_rd;
    Integer max_time;
};


enum AtCause {  // AT_CAUSE
    AtUserRel = AT_USER_REL,
    AtV24Failure = AT_V24_FAILURE,
    AtTimeOut = AT_TIMER_OUT
};

*/

#endif  // Asc_DataCall_DataCallContext_hpp


