/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Adc_SimCphsHandler_hpp)
#define Adc_SimCphsHandler_hpp

#include <Adc/BaseDataHandler.hpp>

// length of Cphs-Sst
const INT c_cphs_sst_len = 2;
const INT c_cphs_sst_count = c_cphs_sst_len*4;

// length of Cphs-Operator name shortform
const INT c_op_srt_name_file_len = 10;

class SimCphsHandler : public BaseDataHandler
{
    typedef BaseDataHandler Base;

    public:
        // values are used for shifting
        enum VoiceMsgType {
            MsgTypeLine1    = 8,
            MsgTypeLine2    = 12,
            MsgTypeFax      = 0,
            MsgTypeData     = 4,
        };
        // MS byte represents the Service Group Code,
        // LS byte represents the bit significance for each SGC
        enum CphsServGroupCode {
            ServCfu             = 0x0180,
            ServCfb             = 0x0140,
            ServCfnry           = 0x0120,
            ServCfnrc           = 0x0110,
            ServCt              = 0x0108,
            ServBoac            = 0x0280,
            ServBoic            = 0x0240,
            ServBoicExHc        = 0x0220,
            ServBaic            = 0x0210,
            ServBicRoam         = 0x0208,
            ServMpty            = 0x0380,
            ServCug             = 0x0340,
            ServAoC             = 0x0320,
            ServPrefCug         = 0x0310,
            ServCugOA           = 0x0308,
            ServHold            = 0x0480,
            ServCw              = 0x0440,
            ServCcbs            = 0x0420,
            ServUserUserSig     = 0x0410,
            ServSmMt            = 0x0580,
            ServSmMo            = 0x0540,
            ServSmCb            = 0x0520,
            ServReplyPath       = 0x0510,
            ServDelConf         = 0x0508,
            ServProtId          = 0x0504,
            ServValPeriod       = 0x0502,
            ServAls             = 0x0680,
            ServClip            = 0x0880,
            ServCoLr            = 0x0820,
            ServCoLp            = 0x0810,
            ServMci             = 0x0808,
            ServCliSend         = 0x0802,
            ServCliBlock        = 0x0801,
            ServGprs            = 0x0980,
            ServHscsd           = 0x0940,
            ServVoiceGrpCall    = 0x0920,
            ServVoiceBcstServ   = 0x0910,
            ServMtplSubscrPfl   = 0x0908,
            ServMtplBand        = 0x0904,
            ServPlmnMode        = 0xc080,
            ServVps             = 0xc040,  
            ServSmmoPaging      = 0xc020,  
            ServSmmoEmail       = 0xc010,  
            ServFax             = 0xc008,  
            ServData            = 0xc004,  
            ServLanguage        = 0xc001,  
            ServInfoNumbers     = 0xd5ff, 
        };

        SimCphsHandler();
        virtual ~SimCphsHandler();

        void Reset();

        BOOLEAN GetCphsPhase(UINT8 &phase);
        BOOLEAN IsServiceAllocated(UINT idx, BOOLEAN & allocated);
        BOOLEAN IsServiceActivated(UINT idx, BOOLEAN & activated);

        BOOLEAN GetOpName(WString &name);

        BOOLEAN GetOpShortName(WString &name);

        BOOLEAN IsVoiceMsgWaiting(VoiceMsgType type, BOOLEAN &waiting);
        BOOLEAN IsCallFwdUncondActive(VoiceMsgType type, BOOLEAN &active);
        BOOLEAN SetVoiceMsgWaiting(VoiceMsgType type, BOOLEAN waiting);
        BOOLEAN SetCallFwdUncondActive(VoiceMsgType type, BOOLEAN active);

        BOOLEAN IsCphsServAccessible(LineSelector line, SimCphsHandler::CphsServGroupCode code, BOOLEAN &accessible);
        BOOLEAN SetCphsServAccessible(LineSelector line, SimCphsHandler::CphsServGroupCode code, BOOLEAN accessible);
        BOOLEAN RetrieveCspData();

        BOOLEAN GetLineInUse(INT & line);
        BOOLEAN SetLineInUse(INT line);
        BOOLEAN GetLineLocked(BOOLEAN & locked);
        BOOLEAN SetLineLocked(BOOLEAN locked);
        void InitMruDynflags(const SimInfo & info);

        BOOLEAN IsCphsPresent(BOOLEAN & present);

        BOOLEAN GetOrangeWelcomeMsg(WString & welcomemsg);

// Cingular 
        BOOLEAN RetrieveCingularTst();
        BOOLEAN IsCingularNetworkSelectionMenuControlSupportEnabled(BOOLEAN & enabled);
        BOOLEAN IsCspPlmnModeBitSet(BOOLEAN & isset);

    
// Mark unread for Simtoolkit & other Async notifications
        void MarkOpNameUnread() { m_is_op_name_retr = FALSE; }
        void MarkOpSNameUnread() { m_is_op_sname_retr = FALSE; }
        void MarkCphsInfoUnread() { m_is_cphs_info_retr = FALSE; }
        void MarkCspUnread() { m_is_csp_init = FALSE; }
        void MarkVmwfUnread() { m_is_vmwf_init = FALSE; }
        void MarkCfufUnread() { m_is_cfuf_init = FALSE; }
        void MarkLineInUseUnread() { m_is_line_in_use_init = FALSE; }
        void MarkLineLockedUnread() { m_is_line_locked_init = FALSE; }
        void MarkWelcomeMsgUnread() { m_is_welcome_msg_init = FALSE; }

    private:
        BOOLEAN RetrieveCphsInfo();
        BOOLEAN RetrieveOpShortName();
        UINT8 * GetCspBuffer(LineSelector line);

        BOOLEAN m_is_op_name_retr;
        BOOLEAN m_is_op_sname_retr;
        BOOLEAN m_is_cphs_info_retr;
        BOOLEAN m_is_csp_init;
        BOOLEAN m_is_line_in_use_init;
        BOOLEAN m_is_line_locked_init;
        BOOLEAN m_is_welcome_msg_init;
        BOOLEAN m_is_vmwf_init;
        BOOLEAN m_is_cfuf_init;
        BOOLEAN m_is_tst_present;
        
        WString m_op_name;
        WString m_op_sname;
        WString m_welcome_msg;

        CphsCspArray m_cphs_csp;
        CphsCspArray m_cphs_csp2;
        CphsIstArray m_cphs_info;
        CphsVmwfArray m_vmwf_data;
        CphsCfufArray m_cfuf_data;

        UINT8   m_line_in_use;
        UINT8   m_line_locked;
        UINT8   m_cingular_network_selection;
        UINT8   m_mru_dyn;
        UINT8   m_mru_dyn2;
};

#endif

