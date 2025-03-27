/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\grossau_mp1ue_sv\lnz_apoxi\Apoxi\Apc\SimTkArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_SimTkStackMsgArgs_hpp)
#define Apc_SimTkStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/AudioTypes.hpp>
#include <Apc/SimTkTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SimTkCallSetupIndArg
    ====================================================================== */

class SimTkCallSetupIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkCallSetupIndArg();
        
        static const SimTkCallSetupIndArg& Cast(const StackMsgArgument& arg);
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        void SetSubAddress(const SimSubAddress& sub_address) { m_sub_address = sub_address; }
        const SimSubAddress& GetSubAddress() const { return m_sub_address; }
        void SetDummy(const SimDummy& dummy) { m_dummy = dummy; }
        const SimDummy& GetDummy() const { return m_dummy; }
        void SetCallInfoAlpha(const SimAlphaIdentifier& call_info_alpha) { m_call_info_alpha = call_info_alpha; }
        const SimAlphaIdentifier& GetCallInfoAlpha() const { return m_call_info_alpha; }
        void SetCallInfoIcon(const SimIconIdentifier& call_info_icon) { m_call_info_icon = call_info_icon; }
        const SimIconIdentifier& GetCallInfoIcon() const { return m_call_info_icon; }
        void SetCallEstablishedInfoAlpha(const SimAlphaIdentifier& call_established_info_alpha) { m_call_established_info_alpha = call_established_info_alpha; }
        const SimAlphaIdentifier& GetCallEstablishedInfoAlpha() const { return m_call_established_info_alpha; }
        void SetCallEstablishedInfoIcon(const SimIconIdentifier& call_established_info_icon) { m_call_established_info_icon = call_established_info_icon; }
        const SimIconIdentifier& GetCallEstablishedInfoIcon() const { return m_call_established_info_icon; }
        
        enum  {
            ID = 1300
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkCallSetupIndArg*) arg); }
        
        PhoneNumber m_phone_number;
        SimSubAddress m_sub_address;
        SimDummy m_dummy;
        SimAlphaIdentifier m_call_info_alpha;
        SimIconIdentifier m_call_info_icon;
        SimAlphaIdentifier m_call_established_info_alpha;
        SimIconIdentifier m_call_established_info_icon;
        
    };

// Inline definitions
inline const SimTkCallSetupIndArg& SimTkCallSetupIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkCallSetupIndArg!\n");
    return ((SimTkCallSetupIndArg &) arg);
}



/*  ======================================================================
    Class SimTkSmsPpIndArg
    ====================================================================== */

class SimTkSmsPpIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSmsPpIndArg();
        
        static const SimTkSmsPpIndArg& Cast(const StackMsgArgument& arg);
        void SetSmsInfoAlpha(const SimAlphaIdentifier& sms_info_alpha) { m_sms_info_alpha = sms_info_alpha; }
        const SimAlphaIdentifier& GetSmsInfoAlpha() const { return m_sms_info_alpha; }
        void SetSmsInfoIcon(const SimIconIdentifier& sms_info_icon) { m_sms_info_icon = sms_info_icon; }
        const SimIconIdentifier& GetSmsInfoIcon() const { return m_sms_info_icon; }
        void SetReferenceNumber(const SimReferenceNumber& reference_number) { m_reference_number = reference_number; }
        const SimReferenceNumber& GetReferenceNumber() const { return m_reference_number; }
        
        enum  {
            ID = 1301
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSmsPpIndArg*) arg); }
        
        SimAlphaIdentifier m_sms_info_alpha;
        SimIconIdentifier m_sms_info_icon;
        SimReferenceNumber m_reference_number;
        
    };

// Inline definitions
inline const SimTkSmsPpIndArg& SimTkSmsPpIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSmsPpIndArg!\n");
    return ((SimTkSmsPpIndArg &) arg);
}



/*  ======================================================================
    Class SimTkSsIndArg
    ====================================================================== */

class SimTkSsIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSsIndArg();
        
        static const SimTkSsIndArg& Cast(const StackMsgArgument& arg);
        void SetSsInfoAlpha(const SimAlphaIdentifier& ss_info_alpha) { m_ss_info_alpha = ss_info_alpha; }
        const SimAlphaIdentifier& GetSsInfoAlpha() const { return m_ss_info_alpha; }
        void SetSsInfoIcon(const SimIconIdentifier& ss_info_icon) { m_ss_info_icon = ss_info_icon; }
        const SimIconIdentifier& GetSsInfoIcon() const { return m_ss_info_icon; }
        void SetReferenceNumber(const SimReferenceNumber& reference_number) { m_reference_number = reference_number; }
        const SimReferenceNumber& GetReferenceNumber() const { return m_reference_number; }
        void SetUserInput(const WString& user_input) { m_user_input = user_input; }
        const WString& GetUserInput() const { return m_user_input; }
        void SetUserInputLanguage(const DataCodingScheme::Language& user_input_language) { m_user_input_language = user_input_language; }
        const DataCodingScheme::Language& GetUserInputLanguage() const { return m_user_input_language; }
        void SetSimServiceType(const SimSsType& sim_service_type) { m_sim_service_type = sim_service_type; }
        const SimSsType& GetSimServiceType() const { return m_sim_service_type; }
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        
        enum  {
            ID = 1302
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSsIndArg*) arg); }
        
        SimAlphaIdentifier m_ss_info_alpha;
        SimIconIdentifier m_ss_info_icon;
        SimReferenceNumber m_reference_number;
        WString m_user_input;
        DataCodingScheme::Language m_user_input_language;
        SimSsType m_sim_service_type;
        Tipd m_tipd;
        
    };

// Inline definitions
inline const SimTkSsIndArg& SimTkSsIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSsIndArg!\n");
    return ((SimTkSsIndArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshReqArg
    ====================================================================== */

class SimTkRefreshReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshReqArg();
        
        static const SimTkRefreshReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetEfRefresh(const SimEfRefresh& ef_refresh) { m_ef_refresh = ef_refresh; }
        const SimEfRefresh& GetEfRefresh() const { return m_ef_refresh; }
        
        enum  {
            ID = 1303
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimEfRefresh m_ef_refresh;
        
    };

// Inline definitions
inline const SimTkRefreshReqArg& SimTkRefreshReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshReqArg!\n");
    return ((SimTkRefreshReqArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshResetReqArg
    ====================================================================== */

class SimTkRefreshResetReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshResetReqArg();
        
        static const SimTkRefreshResetReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        
        enum  {
            ID = 1304
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshResetReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        
    };

// Inline definitions
inline const SimTkRefreshResetReqArg& SimTkRefreshResetReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshResetReqArg!\n");
    return ((SimTkRefreshResetReqArg &) arg);
}



/*  ======================================================================
    Class SimTkResetCnfReqArg
    ====================================================================== */

class SimTkResetCnfReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkResetCnfReqArg();
        
        static const SimTkResetCnfReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetRefreshPossible(BOOLEAN refresh_possible) { m_refresh_possible = refresh_possible; }
        BOOLEAN IsRefreshPossible() const { return m_refresh_possible; }
        
        enum  {
            ID = 1305
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkResetCnfReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        BOOLEAN m_refresh_possible;
        
    };

// Inline definitions
inline const SimTkResetCnfReqArg& SimTkResetCnfReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkResetCnfReqArg!\n");
    return ((SimTkResetCnfReqArg &) arg);
}



/*  ======================================================================
    Class SimTkResetCnfArg
    ====================================================================== */

class SimTkResetCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkResetCnfArg();
        
        static const SimTkResetCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1306
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkResetCnfArg*) arg); }
        
    };

// Inline definitions
inline const SimTkResetCnfArg& SimTkResetCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkResetCnfArg!\n");
    return ((SimTkResetCnfArg &) arg);
}



/*  ======================================================================
    Class DisplayTextReqArg
    ====================================================================== */

class DisplayTextReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DisplayTextReqArg();
        
        static const DisplayTextReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetOptions(const SimDisplayTextOptions& options) { m_options = options; }
        const SimDisplayTextOptions& GetOptions() const { return m_options; }
        void SetTextString(const SimTextString& text_string) { m_text_string = text_string; }
        const SimTextString& GetTextString() const { return m_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        void SetImmediateResponse(BOOLEAN immediate_response) { m_immediate_response = immediate_response; }
        BOOLEAN IsImmediateResponse() const { return m_immediate_response; }
        
        enum  {
            ID = 1307
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DisplayTextReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimDisplayTextOptions m_options;
        SimTextString m_text_string;
        SimIconIdentifier m_icon;
        BOOLEAN m_immediate_response;
        
    };

// Inline definitions
inline const DisplayTextReqArg& DisplayTextReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DisplayTextReqArg!\n");
    return ((DisplayTextReqArg &) arg);
}



/*  ======================================================================
    Class GetInputReqArg
    ====================================================================== */

class GetInputReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        GetInputReqArg();
        
        static const GetInputReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetOptions(const SimGetInputOptions& options) { m_options = options; }
        const SimGetInputOptions& GetOptions() const { return m_options; }
        void SetTextString(const SimTextString& text_string) { m_text_string = text_string; }
        const SimTextString& GetTextString() const { return m_text_string; }
        void SetMinInputLen(INT min_input_len) { m_min_input_len = min_input_len; }
        INT GetMinInputLen() const { return m_min_input_len; }
        void SetMaxInputLen(INT max_input_len) { m_max_input_len = max_input_len; }
        INT GetMaxInputLen() const { return m_max_input_len; }
        void SetDefaultTextString(const SimTextString& default_text_string) { m_default_text_string = default_text_string; }
        const SimTextString& GetDefaultTextString() const { return m_default_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1308
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((GetInputReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimGetInputOptions m_options;
        SimTextString m_text_string;
        INT m_min_input_len;
        INT m_max_input_len;
        SimTextString m_default_text_string;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const GetInputReqArg& GetInputReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to GetInputReqArg!\n");
    return ((GetInputReqArg &) arg);
}



/*  ======================================================================
    Class GetInkeyReqArg
    ====================================================================== */

class GetInkeyReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        GetInkeyReqArg();
        
        static const GetInkeyReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetOptions(const SimGetInkeyOptions& options) { m_options = options; }
        const SimGetInkeyOptions& GetOptions() const { return m_options; }
        void SetTextString(const SimTextString& text_string) { m_text_string = text_string; }
        const SimTextString& GetTextString() const { return m_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1309
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((GetInkeyReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimGetInkeyOptions m_options;
        SimTextString m_text_string;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const GetInkeyReqArg& GetInkeyReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to GetInkeyReqArg!\n");
    return ((GetInkeyReqArg &) arg);
}



/*  ======================================================================
    Class SelectItemReqArg
    ====================================================================== */

class SelectItemReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SelectItemReqArg();
        
        static const SelectItemReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetOptions(const SimSelectItemOptions& options) { m_options = options; }
        const SimSelectItemOptions& GetOptions() const { return m_options; }
        void SetDefaultItemId(const SimItemId& default_item_id) { m_default_item_id = default_item_id; }
        const SimItemId& GetDefaultItemId() const { return m_default_item_id; }
        void SetTitleAlpha(const SimAlphaIdentifier& title_alpha) { m_title_alpha = title_alpha; }
        const SimAlphaIdentifier& GetTitleAlpha() const { return m_title_alpha; }
        void SetItemList(const SimItemIdentifierList& item_list) { m_item_list = item_list; }
        const SimItemIdentifierList& GetItemList() const { return m_item_list; }
        void SetItemsNai(const SimNextActionIdentifier& items_nai) { m_items_nai = items_nai; }
        const SimNextActionIdentifier& GetItemsNai() const { return m_items_nai; }
        void SetTitleIcon(const SimIconIdentifier& title_icon) { m_title_icon = title_icon; }
        const SimIconIdentifier& GetTitleIcon() const { return m_title_icon; }
        void SetIconList(const SimIconIdentifier& icon_list) { m_icon_list = icon_list; }
        const SimIconIdentifier& GetIconList() const { return m_icon_list; }
        
        enum  {
            ID = 1310
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SelectItemReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimSelectItemOptions m_options;
        SimItemId m_default_item_id;
        SimAlphaIdentifier m_title_alpha;
        SimItemIdentifierList m_item_list;
        SimNextActionIdentifier m_items_nai;
        SimIconIdentifier m_title_icon;
        SimIconIdentifier m_icon_list;
        
    };

// Inline definitions
inline const SelectItemReqArg& SelectItemReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SelectItemReqArg!\n");
    return ((SelectItemReqArg &) arg);
}



/*  ======================================================================
    Class SetupMenuReqArg
    ====================================================================== */

class SetupMenuReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetupMenuReqArg();
        
        static const SetupMenuReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetOptions(const SimSetupMenuOptions& options) { m_options = options; }
        const SimSetupMenuOptions& GetOptions() const { return m_options; }
        void SetTitleAlpha(const SimAlphaIdentifier& title_alpha) { m_title_alpha = title_alpha; }
        const SimAlphaIdentifier& GetTitleAlpha() const { return m_title_alpha; }
        void SetItemList(const SimItemIdentifierList& item_list) { m_item_list = item_list; }
        const SimItemIdentifierList& GetItemList() const { return m_item_list; }
        void SetItemsNai(const SimNextActionIdentifier& items_nai) { m_items_nai = items_nai; }
        const SimNextActionIdentifier& GetItemsNai() const { return m_items_nai; }
        void SetTitleIcon(const SimIconIdentifier& title_icon) { m_title_icon = title_icon; }
        const SimIconIdentifier& GetTitleIcon() const { return m_title_icon; }
        void SetIconList(const SimIconIdentifier& icon_list) { m_icon_list = icon_list; }
        const SimIconIdentifier& GetIconList() const { return m_icon_list; }
        
        enum  {
            ID = 1311
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetupMenuReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimSetupMenuOptions m_options;
        SimAlphaIdentifier m_title_alpha;
        SimItemIdentifierList m_item_list;
        SimNextActionIdentifier m_items_nai;
        SimIconIdentifier m_title_icon;
        SimIconIdentifier m_icon_list;
        
    };

// Inline definitions
inline const SetupMenuReqArg& SetupMenuReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetupMenuReqArg!\n");
    return ((SetupMenuReqArg &) arg);
}



/*  ======================================================================
    Class MenuSelectionRejArg
    ====================================================================== */

class MenuSelectionRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MenuSelectionRejArg();
        
        static const MenuSelectionRejArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1312
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MenuSelectionRejArg*) arg); }
        
    };

// Inline definitions
inline const MenuSelectionRejArg& MenuSelectionRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MenuSelectionRejArg!\n");
    return ((MenuSelectionRejArg &) arg);
}



/*  ======================================================================
    Class PlayToneReqArg
    ====================================================================== */

class PlayToneReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlayToneReqArg();
        
        static const PlayToneReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetTone(const AudioTone& tone) { m_tone = tone; }
        const AudioTone& GetTone() const { return m_tone; }
        void SetInfoAlpha(const SimAlphaIdentifier& info_alpha) { m_info_alpha = info_alpha; }
        const SimAlphaIdentifier& GetInfoAlpha() const { return m_info_alpha; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1313
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlayToneReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        AudioTone m_tone;
        SimAlphaIdentifier m_info_alpha;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const PlayToneReqArg& PlayToneReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlayToneReqArg!\n");
    return ((PlayToneReqArg &) arg);
}



/*  ======================================================================
    Class SetupIdleModeTextReqArg
    ====================================================================== */

class SetupIdleModeTextReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetupIdleModeTextReqArg();
        
        static const SetupIdleModeTextReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetOptions(const SimSetupIdleModeTextOptions& options) { m_options = options; }
        const SimSetupIdleModeTextOptions& GetOptions() const { return m_options; }
        void SetTextString(const SimTextString& text_string) { m_text_string = text_string; }
        const SimTextString& GetTextString() const { return m_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1314
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetupIdleModeTextReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimSetupIdleModeTextOptions m_options;
        SimTextString m_text_string;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SetupIdleModeTextReqArg& SetupIdleModeTextReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetupIdleModeTextReqArg!\n");
    return ((SetupIdleModeTextReqArg &) arg);
}



/*  ======================================================================
    Class EndSimToolkitIndArg
    ====================================================================== */

class EndSimToolkitIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        EndSimToolkitIndArg();
        
        static const EndSimToolkitIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1315
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((EndSimToolkitIndArg*) arg); }
        
    };

// Inline definitions
inline const EndSimToolkitIndArg& EndSimToolkitIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to EndSimToolkitIndArg!\n");
    return ((EndSimToolkitIndArg &) arg);
}



/*  ======================================================================
    Class SimTkLanguageNotificationIndArg
    ====================================================================== */

class SimTkLanguageNotificationIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkLanguageNotificationIndArg();
        
        static const SimTkLanguageNotificationIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetExtLanguage(const ExtLanguage& ext_language) { m_ext_language = ext_language; }
        const ExtLanguage& GetExtLanguage() const { return m_ext_language; }
        
        enum  {
            ID = 1316
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkLanguageNotificationIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        ExtLanguage m_ext_language;
        
    };

// Inline definitions
inline const SimTkLanguageNotificationIndArg& SimTkLanguageNotificationIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkLanguageNotificationIndArg!\n");
    return ((SimTkLanguageNotificationIndArg &) arg);
}



/*  ======================================================================
    Class SimTkSetupEventReqArg
    ====================================================================== */

class SimTkSetupEventReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSetupEventReqArg();
        
        static const SimTkSetupEventReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetEventList(const SimEventList& event_list) { m_event_list = event_list; }
        const SimEventList& GetEventList() const { return m_event_list; }
        
        enum  {
            ID = 1317
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSetupEventReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimEventList m_event_list;
        
    };

// Inline definitions
inline const SimTkSetupEventReqArg& SimTkSetupEventReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSetupEventReqArg!\n");
    return ((SimTkSetupEventReqArg &) arg);
}



/*  ======================================================================
    Class LanguageSettingReqArg
    ====================================================================== */

class LanguageSettingReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        LanguageSettingReqArg();
        
        static const LanguageSettingReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        
        enum  {
            ID = 1318
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LanguageSettingReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        
    };

// Inline definitions
inline const LanguageSettingReqArg& LanguageSettingReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LanguageSettingReqArg!\n");
    return ((LanguageSettingReqArg &) arg);
}



/*  ======================================================================
    Class ExtProactiveCmdReqArg
    ====================================================================== */

class ExtProactiveCmdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ExtProactiveCmdReqArg(SimApduData * apdu_data_ptr);
        ExtProactiveCmdReqArg();
        
        static const ExtProactiveCmdReqArg& Cast(const StackMsgArgument& arg);
        void SetApduDataPtr(SimApduData * apdu_data_ptr) { m_apdu_data_ptr = apdu_data_ptr; }
        SimApduData * GetApduDataPtr() const { return m_apdu_data_ptr; }
        
        enum  {
            ID = 1319
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ExtProactiveCmdReqArg*) arg); }
        
        SimApduData * m_apdu_data_ptr;
        
    };

// Inline definitions
inline const ExtProactiveCmdReqArg& ExtProactiveCmdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ExtProactiveCmdReqArg!\n");
    return ((ExtProactiveCmdReqArg &) arg);
}



/*  ======================================================================
    Class ExtProactiveCmdCnfArg
    ====================================================================== */

class ExtProactiveCmdCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ExtProactiveCmdCnfArg();
        
        static const ExtProactiveCmdCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1320
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ExtProactiveCmdCnfArg*) arg); }
        
    };

// Inline definitions
inline const ExtProactiveCmdCnfArg& ExtProactiveCmdCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ExtProactiveCmdCnfArg!\n");
    return ((ExtProactiveCmdCnfArg &) arg);
}



/*  ======================================================================
    Class TermRspCnfArg
    ====================================================================== */

class TermRspCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        TermRspCnfArg();
        
        static const TermRspCnfArg& Cast(const StackMsgArgument& arg);
        void SetLastStatus(const SimStatusCondition& last_status) { m_last_status = last_status; }
        const SimStatusCondition& GetLastStatus() const { return m_last_status; }
        void SetFinishedCommand(const Toc& finished_command) { m_finished_command = finished_command; }
        const Toc& GetFinishedCommand() const { return m_finished_command; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 1321
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((TermRspCnfArg*) arg); }
        
        SimStatusCondition m_last_status;
        Toc m_finished_command;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const TermRspCnfArg& TermRspCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to TermRspCnfArg!\n");
    return ((TermRspCnfArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshQueryReqArg
    ====================================================================== */

class SimTkRefreshQueryReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshQueryReqArg();
        
        static const SimTkRefreshQueryReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetRefreshIndicator(UINT8 refresh_indicator) { m_refresh_indicator = refresh_indicator; }
        UINT8 GetRefreshIndicator() const { return m_refresh_indicator; }
        void SetEfRefresh(const SimEfRefresh& ef_refresh) { m_ef_refresh = ef_refresh; }
        const SimEfRefresh& GetEfRefresh() const { return m_ef_refresh; }
        
        enum  {
            ID = 1322
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshQueryReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_refresh_indicator;
        SimEfRefresh m_ef_refresh;
        
    };

// Inline definitions
inline const SimTkRefreshQueryReqArg& SimTkRefreshQueryReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshQueryReqArg!\n");
    return ((SimTkRefreshQueryReqArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshCnfReqArg
    ====================================================================== */

class SimTkRefreshCnfReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshCnfReqArg();
        
        static const SimTkRefreshCnfReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetRefreshPossible(BOOLEAN refresh_possible) { m_refresh_possible = refresh_possible; }
        BOOLEAN IsRefreshPossible() const { return m_refresh_possible; }
        
        enum  {
            ID = 1323
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshCnfReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        BOOLEAN m_refresh_possible;
        
    };

// Inline definitions
inline const SimTkRefreshCnfReqArg& SimTkRefreshCnfReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshCnfReqArg!\n");
    return ((SimTkRefreshCnfReqArg &) arg);
}



/*  ======================================================================
    Class SimLaunchBrowserPromptReqArg
    ====================================================================== */

class SimLaunchBrowserPromptReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLaunchBrowserPromptReqArg();
        
        static const SimLaunchBrowserPromptReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetUrl(const WString& url) { m_url = url; }
        const WString& GetUrl() const { return m_url; }
        void SetTextString(const SimAlphaIdentifier& text_string) { m_text_string = text_string; }
        const SimAlphaIdentifier& GetTextString() const { return m_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1324
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLaunchBrowserPromptReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        WString m_url;
        SimAlphaIdentifier m_text_string;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SimLaunchBrowserPromptReqArg& SimLaunchBrowserPromptReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLaunchBrowserPromptReqArg!\n");
    return ((SimLaunchBrowserPromptReqArg &) arg);
}



/*  ======================================================================
    Class SimLaunchBrowserReqArg
    ====================================================================== */

class SimLaunchBrowserReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLaunchBrowserReqArg();
        
        static const SimLaunchBrowserReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCommandDetails(UINT8 command_details) { m_command_details = command_details; }
        UINT8 GetCommandDetails() const { return m_command_details; }
        void SetBearerList(const SiBearerList& bearer_list) { m_bearer_list = bearer_list; }
        const SiBearerList& GetBearerList() const { return m_bearer_list; }
        void SetProvisionFileRef(const SiProvFileRef& provision_file_ref) { m_provision_file_ref = provision_file_ref; }
        const SiProvFileRef& GetProvisionFileRef() const { return m_provision_file_ref; }
        void SetUrl(const WString& url) { m_url = url; }
        const WString& GetUrl() const { return m_url; }
        void SetGateway(const SimTextString& gateway) { m_gateway = gateway; }
        const SimTextString& GetGateway() const { return m_gateway; }
        
        enum  {
            ID = 1325
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLaunchBrowserReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_command_details;
        SiBearerList m_bearer_list;
        SiProvFileRef m_provision_file_ref;
        WString m_url;
        SimTextString m_gateway;
        
    };

// Inline definitions
inline const SimLaunchBrowserReqArg& SimLaunchBrowserReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLaunchBrowserReqArg!\n");
    return ((SimLaunchBrowserReqArg &) arg);
}



/*  ======================================================================
    Class SimBrowserTermResArg
    ====================================================================== */

class SimBrowserTermResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimBrowserTermResArg();
        
        static const SimBrowserTermResArg& Cast(const StackMsgArgument& arg);
        void SetSimResult(UINT8 sim_result) { m_sim_result = sim_result; }
        UINT8 GetSimResult() const { return m_sim_result; }
        
        enum  {
            ID = 1326
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimBrowserTermResArg*) arg); }
        
        UINT8 m_sim_result;
        
    };

// Inline definitions
inline const SimBrowserTermResArg& SimBrowserTermResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimBrowserTermResArg!\n");
    return ((SimBrowserTermResArg &) arg);
}



/*  ======================================================================
    Class SiChannelOpenPromptReqArg
    ====================================================================== */

class SiChannelOpenPromptReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelOpenPromptReqArg();
        
        static const SiChannelOpenPromptReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetBearerType(const SiBearerType& bearer_type) { m_bearer_type = bearer_type; }
        const SiBearerType& GetBearerType() const { return m_bearer_type; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        void SetSubAddr(const SimSubAddress& sub_addr) { m_sub_addr = sub_addr; }
        const SimSubAddress& GetSubAddr() const { return m_sub_addr; }
        void SetApn(const WString& apn) { m_apn = apn; }
        const WString& GetApn() const { return m_apn; }
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1327
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelOpenPromptReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        SiBearerType m_bearer_type;
        PhoneNumber m_phone_number;
        SimSubAddress m_sub_addr;
        WString m_apn;
        WString m_text;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SiChannelOpenPromptReqArg& SiChannelOpenPromptReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelOpenPromptReqArg!\n");
    return ((SiChannelOpenPromptReqArg &) arg);
}



/*  ======================================================================
    Class SiChannelCloseInfoIndArg
    ====================================================================== */

class SiChannelCloseInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelCloseInfoIndArg();
        
        static const SiChannelCloseInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetCloseCause(const SiChannelCloseCause& close_cause) { m_close_cause = close_cause; }
        const SiChannelCloseCause& GetCloseCause() const { return m_close_cause; }
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1328
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelCloseInfoIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        SiChannelCloseCause m_close_cause;
        WString m_text;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SiChannelCloseInfoIndArg& SiChannelCloseInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelCloseInfoIndArg!\n");
    return ((SiChannelCloseInfoIndArg &) arg);
}



/*  ======================================================================
    Class SiChannelSendInfoIndArg
    ====================================================================== */

class SiChannelSendInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelSendInfoIndArg();
        
        static const SiChannelSendInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetChannelDataLength(UINT8 channel_data_length) { m_channel_data_length = channel_data_length; }
        UINT8 GetChannelDataLength() const { return m_channel_data_length; }
        void SetText(const SimAlphaIdentifier& text) { m_text = text; }
        const SimAlphaIdentifier& GetText() const { return m_text; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1329
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelSendInfoIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_channel_data_length;
        SimAlphaIdentifier m_text;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SiChannelSendInfoIndArg& SiChannelSendInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelSendInfoIndArg!\n");
    return ((SiChannelSendInfoIndArg &) arg);
}



/*  ======================================================================
    Class SiChannelReceiveInfoIndArg
    ====================================================================== */

class SiChannelReceiveInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelReceiveInfoIndArg();
        
        static const SiChannelReceiveInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetChannelDataLength(UINT8 channel_data_length) { m_channel_data_length = channel_data_length; }
        UINT8 GetChannelDataLength() const { return m_channel_data_length; }
        void SetText(const SimAlphaIdentifier& text) { m_text = text; }
        const SimAlphaIdentifier& GetText() const { return m_text; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1330
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelReceiveInfoIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_channel_data_length;
        SimAlphaIdentifier m_text;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SiChannelReceiveInfoIndArg& SiChannelReceiveInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelReceiveInfoIndArg!\n");
    return ((SiChannelReceiveInfoIndArg &) arg);
}



/*  ======================================================================
    Class DhChannelOpenReqArg
    ====================================================================== */

class DhChannelOpenReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelOpenReqArg();
        
        static const DhChannelOpenReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetBufferSize(UINT16 buffer_size) { m_buffer_size = buffer_size; }
        UINT16 GetBufferSize() const { return m_buffer_size; }
        void SetCmdQualifier(UINT8 cmd_qualifier) { m_cmd_qualifier = cmd_qualifier; }
        UINT8 GetCmdQualifier() const { return m_cmd_qualifier; }
        void SetTranspLayer(const SiTransportLayer& transp_layer) { m_transp_layer = transp_layer; }
        const SiTransportLayer& GetTranspLayer() const { return m_transp_layer; }
        void SetPort(UINT16 port) { m_port = port; }
        UINT16 GetPort() const { return m_port; }
        void SetBearerDesc(const SiBearerDesc& bearer_desc) { m_bearer_desc = bearer_desc; }
        const SiBearerDesc& GetBearerDesc() const { return m_bearer_desc; }
        void SetLocalIpAddr(const SiIpAddress& local_ip_addr) { m_local_ip_addr = local_ip_addr; }
        const SiIpAddress& GetLocalIpAddr() const { return m_local_ip_addr; }
        void SetDestIpAddr(const SiIpAddress& dest_ip_addr) { m_dest_ip_addr = dest_ip_addr; }
        const SiIpAddress& GetDestIpAddr() const { return m_dest_ip_addr; }
        void SetDuration1(const SiDuration& duration1) { m_duration1 = duration1; }
        const SiDuration& GetDuration1() const { return m_duration1; }
        void SetDuration2(const SiDuration& duration2) { m_duration2 = duration2; }
        const SiDuration& GetDuration2() const { return m_duration2; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        void SetSubAddr(const SimSubAddress& sub_addr) { m_sub_addr = sub_addr; }
        const SimSubAddress& GetSubAddr() const { return m_sub_addr; }
        void SetUserLogin(const SimTextString& user_login) { m_user_login = user_login; }
        const SimTextString& GetUserLogin() const { return m_user_login; }
        void SetUserPassword(const SimTextString& user_password) { m_user_password = user_password; }
        const SimTextString& GetUserPassword() const { return m_user_password; }
        void SetEnablePassword(BOOLEAN enable_password) { m_enable_password = enable_password; }
        BOOLEAN IsEnablePassword() const { return m_enable_password; }
        void SetApn(const String& apn) { m_apn = apn; }
        const String& GetApn() const { return m_apn; }
        
        enum  {
            ID = 1331
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelOpenReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT16 m_buffer_size;
        UINT8 m_cmd_qualifier;
        SiTransportLayer m_transp_layer;
        UINT16 m_port;
        SiBearerDesc m_bearer_desc;
        SiIpAddress m_local_ip_addr;
        SiIpAddress m_dest_ip_addr;
        SiDuration m_duration1;
        SiDuration m_duration2;
        PhoneNumber m_phone_number;
        SimSubAddress m_sub_addr;
        SimTextString m_user_login;
        SimTextString m_user_password;
        BOOLEAN m_enable_password;
        String m_apn;
        
    };

// Inline definitions
inline const DhChannelOpenReqArg& DhChannelOpenReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelOpenReqArg!\n");
    return ((DhChannelOpenReqArg &) arg);
}



/*  ======================================================================
    Class DhChannelCloseReqArg
    ====================================================================== */

class DhChannelCloseReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelCloseReqArg();
        
        static const DhChannelCloseReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        
        enum  {
            ID = 1332
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelCloseReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        
    };

// Inline definitions
inline const DhChannelCloseReqArg& DhChannelCloseReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelCloseReqArg!\n");
    return ((DhChannelCloseReqArg &) arg);
}



/*  ======================================================================
    Class DhChannelSendReqArg
    ====================================================================== */

class DhChannelSendReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelSendReqArg();
        
        static const DhChannelSendReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetSendDataType(const SiSendDataType& send_data_type) { m_send_data_type = send_data_type; }
        const SiSendDataType& GetSendDataType() const { return m_send_data_type; }
        void SetChannelData(const ChannelData& channel_data) { m_channel_data = channel_data; }
        const ChannelData& GetChannelData() const { return m_channel_data; }
        
        enum  {
            ID = 1333
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelSendReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        SiSendDataType m_send_data_type;
        ChannelData m_channel_data;
        
    };

// Inline definitions
inline const DhChannelSendReqArg& DhChannelSendReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelSendReqArg!\n");
    return ((DhChannelSendReqArg &) arg);
}



/*  ======================================================================
    Class DhChannelDataAvailableResArg
    ====================================================================== */

class DhChannelDataAvailableResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelDataAvailableResArg();
        
        static const DhChannelDataAvailableResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetSimResult(UINT8 sim_result) { m_sim_result = sim_result; }
        UINT8 GetSimResult() const { return m_sim_result; }
        
        enum  {
            ID = 1334
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelDataAvailableResArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_sim_result;
        
    };

// Inline definitions
inline const DhChannelDataAvailableResArg& DhChannelDataAvailableResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelDataAvailableResArg!\n");
    return ((DhChannelDataAvailableResArg &) arg);
}



/*  ======================================================================
    Class DhChannelReceiveReqArg
    ====================================================================== */

class DhChannelReceiveReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelReceiveReqArg();
        
        static const DhChannelReceiveReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetChannelDataLength(UINT8 channel_data_length) { m_channel_data_length = channel_data_length; }
        UINT8 GetChannelDataLength() const { return m_channel_data_length; }
        
        enum  {
            ID = 1335
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelReceiveReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_channel_data_length;
        
    };

// Inline definitions
inline const DhChannelReceiveReqArg& DhChannelReceiveReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelReceiveReqArg!\n");
    return ((DhChannelReceiveReqArg &) arg);
}



/*  ======================================================================
    Class DhChannelChangeStatusResArg
    ====================================================================== */

class DhChannelChangeStatusResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelChangeStatusResArg();
        
        static const DhChannelChangeStatusResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetSimResult(UINT8 sim_result) { m_sim_result = sim_result; }
        UINT8 GetSimResult() const { return m_sim_result; }
        
        enum  {
            ID = 1336
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelChangeStatusResArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_sim_result;
        
    };

// Inline definitions
inline const DhChannelChangeStatusResArg& DhChannelChangeStatusResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelChangeStatusResArg!\n");
    return ((DhChannelChangeStatusResArg &) arg);
}



/*  ======================================================================
    Class SimTkRunAtCmdInfoIndArg
    ====================================================================== */

class SimTkRunAtCmdInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRunAtCmdInfoIndArg();
        
        static const SimTkRunAtCmdInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetTextString(const SimAlphaIdentifier& text_string) { m_text_string = text_string; }
        const SimAlphaIdentifier& GetTextString() const { return m_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1340
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRunAtCmdInfoIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimAlphaIdentifier m_text_string;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SimTkRunAtCmdInfoIndArg& SimTkRunAtCmdInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRunAtCmdInfoIndArg!\n");
    return ((SimTkRunAtCmdInfoIndArg &) arg);
}



/*  ======================================================================
    Class SimTkSendDtmfIndArg
    ====================================================================== */

class SimTkSendDtmfIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSendDtmfIndArg();
        
        static const SimTkSendDtmfIndArg& Cast(const StackMsgArgument& arg);
        void SetTextString(const SimAlphaIdentifier& text_string) { m_text_string = text_string; }
        const SimAlphaIdentifier& GetTextString() const { return m_text_string; }
        void SetIcon(const SimIconIdentifier& icon) { m_icon = icon; }
        const SimIconIdentifier& GetIcon() const { return m_icon; }
        
        enum  {
            ID = 1341
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSendDtmfIndArg*) arg); }
        
        SimAlphaIdentifier m_text_string;
        SimIconIdentifier m_icon;
        
    };

// Inline definitions
inline const SimTkSendDtmfIndArg& SimTkSendDtmfIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSendDtmfIndArg!\n");
    return ((SimTkSendDtmfIndArg &) arg);
}



/*  ======================================================================
    Class SimTkSendDtmfEndIndArg
    ====================================================================== */

class SimTkSendDtmfEndIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSendDtmfEndIndArg();
        
        static const SimTkSendDtmfEndIndArg& Cast(const StackMsgArgument& arg);
        void SetCause(const CallErrorCause& cause) { m_cause = cause; }
        const CallErrorCause& GetCause() const { return m_cause; }
        
        enum  {
            ID = 1342
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSendDtmfEndIndArg*) arg); }
        
        CallErrorCause m_cause;
        
    };

// Inline definitions
inline const SimTkSendDtmfEndIndArg& SimTkSendDtmfEndIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSendDtmfEndIndArg!\n");
    return ((SimTkSendDtmfEndIndArg &) arg);
}



/*  ======================================================================
    Class SimTkInterfaceIndArg
    ====================================================================== */

class SimTkInterfaceIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkInterfaceIndArg();
        
        static const SimTkInterfaceIndArg& Cast(const StackMsgArgument& arg);
        void SetProcessId(const ProcessId& process_id) { m_process_id = process_id; }
        const ProcessId& GetProcessId() const { return m_process_id; }
        
        enum  {
            ID = 5300
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkInterfaceIndArg*) arg); }
        
        ProcessId m_process_id;
        
    };

// Inline definitions
inline const SimTkInterfaceIndArg& SimTkInterfaceIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkInterfaceIndArg!\n");
    return ((SimTkInterfaceIndArg &) arg);
}



/*  ======================================================================
    Class SmsControlIndArg
    ====================================================================== */

class SmsControlIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsControlIndArg();
        
        static const SmsControlIndArg& Cast(const StackMsgArgument& arg);
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetTextInfoAlpha(const SimAlphaIdentifier& text_info_alpha) { m_text_info_alpha = text_info_alpha; }
        const SimAlphaIdentifier& GetTextInfoAlpha() const { return m_text_info_alpha; }
        void SetScNumber(const PhoneNumber& sc_number) { m_sc_number = sc_number; }
        const PhoneNumber& GetScNumber() const { return m_sc_number; }
        void SetDestinationNumber(const PhoneNumber& destination_number) { m_destination_number = destination_number; }
        const PhoneNumber& GetDestinationNumber() const { return m_destination_number; }
        void SetOrig1TextInfoAlpha(const SimAlphaIdentifier& orig_1_text_info_alpha) { m_orig_1_text_info_alpha = orig_1_text_info_alpha; }
        const SimAlphaIdentifier& GetOrig1TextInfoAlpha() const { return m_orig_1_text_info_alpha; }
        void SetSimtkRelated(BOOLEAN simtk_related) { m_simtk_related = simtk_related; }
        BOOLEAN IsSimtkRelated() const { return m_simtk_related; }
        
        enum  {
            ID = 5301
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsControlIndArg*) arg); }
        
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_text_info_alpha;
        PhoneNumber m_sc_number;
        PhoneNumber m_destination_number;
        SimAlphaIdentifier m_orig_1_text_info_alpha;
        BOOLEAN m_simtk_related;
        
    };

// Inline definitions
inline const SmsControlIndArg& SmsControlIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsControlIndArg!\n");
    return ((SmsControlIndArg &) arg);
}



/*  ======================================================================
    Class CallControlSetupIndArg
    ====================================================================== */

class CallControlSetupIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallControlSetupIndArg();
        
        static const CallControlSetupIndArg& Cast(const StackMsgArgument& arg);
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetTextInfoAlpha(const SimAlphaIdentifier& text_info_alpha) { m_text_info_alpha = text_info_alpha; }
        const SimAlphaIdentifier& GetTextInfoAlpha() const { return m_text_info_alpha; }
        void SetCalledPartyNumber(const PhoneNumber& called_party_number) { m_called_party_number = called_party_number; }
        const PhoneNumber& GetCalledPartyNumber() const { return m_called_party_number; }
        void SetOrig1TextInfoAlpha(const SimAlphaIdentifier& orig_1_text_info_alpha) { m_orig_1_text_info_alpha = orig_1_text_info_alpha; }
        const SimAlphaIdentifier& GetOrig1TextInfoAlpha() const { return m_orig_1_text_info_alpha; }
        void SetOrig2TextInfoAlpha(const SimAlphaIdentifier& orig_2_text_info_alpha) { m_orig_2_text_info_alpha = orig_2_text_info_alpha; }
        const SimAlphaIdentifier& GetOrig2TextInfoAlpha() const { return m_orig_2_text_info_alpha; }
        void SetSimtkRelated(BOOLEAN simtk_related) { m_simtk_related = simtk_related; }
        BOOLEAN IsSimtkRelated() const { return m_simtk_related; }
        
        enum  {
            ID = 5302
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallControlSetupIndArg*) arg); }
        
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_text_info_alpha;
        PhoneNumber m_called_party_number;
        SimAlphaIdentifier m_orig_1_text_info_alpha;
        SimAlphaIdentifier m_orig_2_text_info_alpha;
        BOOLEAN m_simtk_related;
        
    };

// Inline definitions
inline const CallControlSetupIndArg& CallControlSetupIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallControlSetupIndArg!\n");
    return ((CallControlSetupIndArg &) arg);
}



/*  ======================================================================
    Class CallControlSsIndArg
    ====================================================================== */

class CallControlSsIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallControlSsIndArg();
        
        static const CallControlSsIndArg& Cast(const StackMsgArgument& arg);
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetTextInfoAlpha(const SimAlphaIdentifier& text_info_alpha) { m_text_info_alpha = text_info_alpha; }
        const SimAlphaIdentifier& GetTextInfoAlpha() const { return m_text_info_alpha; }
        void SetUserInput(const WString& user_input) { m_user_input = user_input; }
        const WString& GetUserInput() const { return m_user_input; }
        void SetUserInputLanguage(const DataCodingScheme::Language& user_input_language) { m_user_input_language = user_input_language; }
        const DataCodingScheme::Language& GetUserInputLanguage() const { return m_user_input_language; }
        void SetOrig1TextInfoAlpha(const SimAlphaIdentifier& orig_1_text_info_alpha) { m_orig_1_text_info_alpha = orig_1_text_info_alpha; }
        const SimAlphaIdentifier& GetOrig1TextInfoAlpha() const { return m_orig_1_text_info_alpha; }
        void SetSimtkRelated(BOOLEAN simtk_related) { m_simtk_related = simtk_related; }
        BOOLEAN IsSimtkRelated() const { return m_simtk_related; }
        
        enum  {
            ID = 5303
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallControlSsIndArg*) arg); }
        
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_text_info_alpha;
        WString m_user_input;
        DataCodingScheme::Language m_user_input_language;
        SimAlphaIdentifier m_orig_1_text_info_alpha;
        BOOLEAN m_simtk_related;
        
    };

// Inline definitions
inline const CallControlSsIndArg& CallControlSsIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallControlSsIndArg!\n");
    return ((CallControlSsIndArg &) arg);
}



/*  ======================================================================
    Class CallControlUssdIndArg
    ====================================================================== */

class CallControlUssdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CallControlUssdIndArg();
        
        static const CallControlUssdIndArg& Cast(const StackMsgArgument& arg);
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetTextInfoAlpha(const SimAlphaIdentifier& text_info_alpha) { m_text_info_alpha = text_info_alpha; }
        const SimAlphaIdentifier& GetTextInfoAlpha() const { return m_text_info_alpha; }
        void SetUserInput(const WString& user_input) { m_user_input = user_input; }
        const WString& GetUserInput() const { return m_user_input; }
        void SetUserInputLanguage(const DataCodingScheme::Language& user_input_language) { m_user_input_language = user_input_language; }
        const DataCodingScheme::Language& GetUserInputLanguage() const { return m_user_input_language; }
        void SetOrig1TextInfoAlpha(const SimAlphaIdentifier& orig_1_text_info_alpha) { m_orig_1_text_info_alpha = orig_1_text_info_alpha; }
        const SimAlphaIdentifier& GetOrig1TextInfoAlpha() const { return m_orig_1_text_info_alpha; }
        void SetSimtkRelated(BOOLEAN simtk_related) { m_simtk_related = simtk_related; }
        BOOLEAN IsSimtkRelated() const { return m_simtk_related; }
        
        enum  {
            ID = 5304
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CallControlUssdIndArg*) arg); }
        
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_text_info_alpha;
        WString m_user_input;
        DataCodingScheme::Language m_user_input_language;
        SimAlphaIdentifier m_orig_1_text_info_alpha;
        BOOLEAN m_simtk_related;
        
    };

// Inline definitions
inline const CallControlUssdIndArg& CallControlUssdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CallControlUssdIndArg!\n");
    return ((CallControlUssdIndArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshNewReqArg
    ====================================================================== */

class SimTkRefreshNewReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshNewReqArg();
        
        static const SimTkRefreshNewReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetEfRefresh(const SimEfRefresh& ef_refresh) { m_ef_refresh = ef_refresh; }
        const SimEfRefresh& GetEfRefresh() const { return m_ef_refresh; }
        
        enum  {
            ID = 5305
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshNewReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        SimEfRefresh m_ef_refresh;
        
    };

// Inline definitions
inline const SimTkRefreshNewReqArg& SimTkRefreshNewReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshNewReqArg!\n");
    return ((SimTkRefreshNewReqArg &) arg);
}



/*  ======================================================================
    Class SimTkSmsPpRspArg
    ====================================================================== */

class SimTkSmsPpRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSmsPpRspArg(const ProactiveCause& proactive_cause, const SimReferenceNumber& reference_number);
        SimTkSmsPpRspArg();
        
        static const SimTkSmsPpRspArg& Cast(const StackMsgArgument& arg);
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetReferenceNumber(const SimReferenceNumber& reference_number) { m_reference_number = reference_number; }
        const SimReferenceNumber& GetReferenceNumber() const { return m_reference_number; }
        
        enum  {
            ID = 2300
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSmsPpRspArg*) arg); }
        
        ProactiveCause m_proactive_cause;
        SimReferenceNumber m_reference_number;
        
    };

// Inline definitions
inline const SimTkSmsPpRspArg& SimTkSmsPpRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSmsPpRspArg!\n");
    return ((SimTkSmsPpRspArg &) arg);
}



/*  ======================================================================
    Class SimTkSsRspArg
    ====================================================================== */

class SimTkSsRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSsRspArg(const ProactiveCause& proactive_cause, const SimReferenceNumber& reference_number);
        SimTkSsRspArg();
        
        static const SimTkSsRspArg& Cast(const StackMsgArgument& arg);
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetReferenceNumber(const SimReferenceNumber& reference_number) { m_reference_number = reference_number; }
        const SimReferenceNumber& GetReferenceNumber() const { return m_reference_number; }
        
        enum  {
            ID = 2301
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSsRspArg*) arg); }
        
        ProactiveCause m_proactive_cause;
        SimReferenceNumber m_reference_number;
        
    };

// Inline definitions
inline const SimTkSsRspArg& SimTkSsRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSsRspArg!\n");
    return ((SimTkSsRspArg &) arg);
}



/*  ======================================================================
    Class SimTkCallSetupAccArg
    ====================================================================== */

class SimTkCallSetupAccArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkCallSetupAccArg(const ProactiveCause& proactive_cause, BOOLEAN ctm);
        SimTkCallSetupAccArg();
        
        static const SimTkCallSetupAccArg& Cast(const StackMsgArgument& arg);
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetCtm(BOOLEAN ctm) { m_ctm = ctm; }
        BOOLEAN IsCtm() const { return m_ctm; }
        
        enum  {
            ID = 2302
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkCallSetupAccArg*) arg); }
        
        ProactiveCause m_proactive_cause;
        BOOLEAN m_ctm;
        
    };

// Inline definitions
inline const SimTkCallSetupAccArg& SimTkCallSetupAccArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkCallSetupAccArg!\n");
    return ((SimTkCallSetupAccArg &) arg);
}



/*  ======================================================================
    Class SimTkCallSetupRejArg
    ====================================================================== */

class SimTkCallSetupRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkCallSetupRejArg(const ProactiveCause& proactive_cause);
        SimTkCallSetupRejArg();
        
        static const SimTkCallSetupRejArg& Cast(const StackMsgArgument& arg);
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2303
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkCallSetupRejArg*) arg); }
        
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SimTkCallSetupRejArg& SimTkCallSetupRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkCallSetupRejArg!\n");
    return ((SimTkCallSetupRejArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshRspArg
    ====================================================================== */

class SimTkRefreshRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        SimTkRefreshRspArg();
        
        static const SimTkRefreshRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2304
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SimTkRefreshRspArg& SimTkRefreshRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshRspArg!\n");
    return ((SimTkRefreshRspArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshResetRspArg
    ====================================================================== */

class SimTkRefreshResetRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshResetRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        SimTkRefreshResetRspArg();
        
        static const SimTkRefreshResetRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2305
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshResetRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SimTkRefreshResetRspArg& SimTkRefreshResetRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshResetRspArg!\n");
    return ((SimTkRefreshResetRspArg &) arg);
}



/*  ======================================================================
    Class SimTkResetCnfIndArg
    ====================================================================== */

class SimTkResetCnfIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkResetCnfIndArg(const SimTkTransactionId& tid);
        SimTkResetCnfIndArg();
        
        static const SimTkResetCnfIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        
        enum  {
            ID = 2306
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkResetCnfIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        
    };

// Inline definitions
inline const SimTkResetCnfIndArg& SimTkResetCnfIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkResetCnfIndArg!\n");
    return ((SimTkResetCnfIndArg &) arg);
}



/*  ======================================================================
    Class DisplayTextRspArg
    ====================================================================== */

class DisplayTextRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DisplayTextRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        DisplayTextRspArg();
        
        static const DisplayTextRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2307
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DisplayTextRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const DisplayTextRspArg& DisplayTextRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DisplayTextRspArg!\n");
    return ((DisplayTextRspArg &) arg);
}



/*  ======================================================================
    Class GetInputRspArg
    ====================================================================== */

class GetInputRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        GetInputRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause, const WString& text, const DataCodingScheme& dcs, BOOLEAN packed);
        GetInputRspArg();
        
        static const GetInputRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetDcs(const DataCodingScheme& dcs) { m_dcs = dcs; }
        const DataCodingScheme& GetDcs() const { return m_dcs; }
        void SetPacked(BOOLEAN packed) { m_packed = packed; }
        BOOLEAN IsPacked() const { return m_packed; }
        
        enum  {
            ID = 2308
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((GetInputRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        WString m_text;
        DataCodingScheme m_dcs;
        BOOLEAN m_packed;
        
    };

// Inline definitions
inline const GetInputRspArg& GetInputRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to GetInputRspArg!\n");
    return ((GetInputRspArg &) arg);
}



/*  ======================================================================
    Class GetInkeyRspArg
    ====================================================================== */

class GetInkeyRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        GetInkeyRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause, const WString& text, const DataCodingScheme& dcs, const SimKey& key = SimKeyInvalid);
        GetInkeyRspArg();
        
        static const GetInkeyRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetDcs(const DataCodingScheme& dcs) { m_dcs = dcs; }
        const DataCodingScheme& GetDcs() const { return m_dcs; }
        void SetKey(const SimKey& key) { m_key = key; }
        const SimKey& GetKey() const { return m_key; }
        
        enum  {
            ID = 2309
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((GetInkeyRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        WString m_text;
        DataCodingScheme m_dcs;
        SimKey m_key;
        
    };

// Inline definitions
inline const GetInkeyRspArg& GetInkeyRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to GetInkeyRspArg!\n");
    return ((GetInkeyRspArg &) arg);
}



/*  ======================================================================
    Class SelectItemRspArg
    ====================================================================== */

class SelectItemRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SelectItemRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause, const SimItemId& item_id);
        SelectItemRspArg();
        
        static const SelectItemRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetItemId(const SimItemId& item_id) { m_item_id = item_id; }
        const SimItemId& GetItemId() const { return m_item_id; }
        
        enum  {
            ID = 2310
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SelectItemRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        SimItemId m_item_id;
        
    };

// Inline definitions
inline const SelectItemRspArg& SelectItemRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SelectItemRspArg!\n");
    return ((SelectItemRspArg &) arg);
}



/*  ======================================================================
    Class SetupMenuRspArg
    ====================================================================== */

class SetupMenuRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetupMenuRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        SetupMenuRspArg();
        
        static const SetupMenuRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2311
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetupMenuRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SetupMenuRspArg& SetupMenuRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetupMenuRspArg!\n");
    return ((SetupMenuRspArg &) arg);
}



/*  ======================================================================
    Class MenuSelectionReqArg
    ====================================================================== */

class MenuSelectionReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MenuSelectionReqArg(const SimItemId& item_id, BOOLEAN info_requested);
        MenuSelectionReqArg();
        
        static const MenuSelectionReqArg& Cast(const StackMsgArgument& arg);
        void SetItemId(const SimItemId& item_id) { m_item_id = item_id; }
        const SimItemId& GetItemId() const { return m_item_id; }
        void SetInfoRequested(BOOLEAN info_requested) { m_info_requested = info_requested; }
        BOOLEAN IsInfoRequested() const { return m_info_requested; }
        
        enum  {
            ID = 2312
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MenuSelectionReqArg*) arg); }
        
        SimItemId m_item_id;
        BOOLEAN m_info_requested;
        
    };

// Inline definitions
inline const MenuSelectionReqArg& MenuSelectionReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MenuSelectionReqArg!\n");
    return ((MenuSelectionReqArg &) arg);
}



/*  ======================================================================
    Class PlayToneRspArg
    ====================================================================== */

class PlayToneRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PlayToneRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        PlayToneRspArg();
        
        static const PlayToneRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2313
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PlayToneRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const PlayToneRspArg& PlayToneRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PlayToneRspArg!\n");
    return ((PlayToneRspArg &) arg);
}



/*  ======================================================================
    Class SetupIdleModeTextRspArg
    ====================================================================== */

class SetupIdleModeTextRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetupIdleModeTextRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        SetupIdleModeTextRspArg();
        
        static const SetupIdleModeTextRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2314
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetupIdleModeTextRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SetupIdleModeTextRspArg& SetupIdleModeTextRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetupIdleModeTextRspArg!\n");
    return ((SetupIdleModeTextRspArg &) arg);
}



/*  ======================================================================
    Class SetupEventCnfArg
    ====================================================================== */

class SetupEventCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SetupEventCnfArg(const SimTkTransactionId& tid, BOOLEAN accept);
        SetupEventCnfArg();
        
        static const SetupEventCnfArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetAccept(BOOLEAN accept) { m_accept = accept; }
        BOOLEAN IsAccept() const { return m_accept; }
        
        enum  {
            ID = 2315
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SetupEventCnfArg*) arg); }
        
        SimTkTransactionId m_tid;
        BOOLEAN m_accept;
        
    };

// Inline definitions
inline const SetupEventCnfArg& SetupEventCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SetupEventCnfArg!\n");
    return ((SetupEventCnfArg &) arg);
}



/*  ======================================================================
    Class UserActivityEventArg
    ====================================================================== */

class UserActivityEventArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UserActivityEventArg();
        
        static const UserActivityEventArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2316
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UserActivityEventArg*) arg); }
        
    };

// Inline definitions
inline const UserActivityEventArg& UserActivityEventArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UserActivityEventArg!\n");
    return ((UserActivityEventArg &) arg);
}



/*  ======================================================================
    Class IdleScreenAvailEventArg
    ====================================================================== */

class IdleScreenAvailEventArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        IdleScreenAvailEventArg();
        
        static const IdleScreenAvailEventArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2317
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((IdleScreenAvailEventArg*) arg); }
        
    };

// Inline definitions
inline const IdleScreenAvailEventArg& IdleScreenAvailEventArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to IdleScreenAvailEventArg!\n");
    return ((IdleScreenAvailEventArg &) arg);
}



/*  ======================================================================
    Class LanguageSelectEventArg
    ====================================================================== */

class LanguageSelectEventArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        LanguageSelectEventArg(const ExtLanguage& ext_language);
        LanguageSelectEventArg();
        
        static const LanguageSelectEventArg& Cast(const StackMsgArgument& arg);
        void SetExtLanguage(const ExtLanguage& ext_language) { m_ext_language = ext_language; }
        const ExtLanguage& GetExtLanguage() const { return m_ext_language; }
        
        enum  {
            ID = 2318
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LanguageSelectEventArg*) arg); }
        
        ExtLanguage m_ext_language;
        
    };

// Inline definitions
inline const LanguageSelectEventArg& LanguageSelectEventArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LanguageSelectEventArg!\n");
    return ((LanguageSelectEventArg &) arg);
}



/*  ======================================================================
    Class LanguageSettingIndArg
    ====================================================================== */

class LanguageSettingIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        LanguageSettingIndArg(const ExtLanguage& ext_language);
        LanguageSettingIndArg();
        
        static const LanguageSettingIndArg& Cast(const StackMsgArgument& arg);
        void SetExtLanguage(const ExtLanguage& ext_language) { m_ext_language = ext_language; }
        const ExtLanguage& GetExtLanguage() const { return m_ext_language; }
        
        enum  {
            ID = 2319
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LanguageSettingIndArg*) arg); }
        
        ExtLanguage m_ext_language;
        
    };

// Inline definitions
inline const LanguageSettingIndArg& LanguageSettingIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LanguageSettingIndArg!\n");
    return ((LanguageSettingIndArg &) arg);
}



/*  ======================================================================
    Class ExtProactiveCmdIndArg
    ====================================================================== */

class ExtProactiveCmdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ExtProactiveCmdIndArg(UINT8 result, SimApduData * apdu_data_ptr);
        ExtProactiveCmdIndArg();
        
        static const ExtProactiveCmdIndArg& Cast(const StackMsgArgument& arg);
        void SetResult(UINT8 result) { m_result = result; }
        UINT8 GetResult() const { return m_result; }
        void SetApduDataPtr(SimApduData * apdu_data_ptr) { m_apdu_data_ptr = apdu_data_ptr; }
        SimApduData * GetApduDataPtr() const { return m_apdu_data_ptr; }
        
        enum  {
            ID = 2320
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ExtProactiveCmdIndArg*) arg); }
        
        UINT8 m_result;
        SimApduData * m_apdu_data_ptr;
        
    };

// Inline definitions
inline const ExtProactiveCmdIndArg& ExtProactiveCmdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ExtProactiveCmdIndArg!\n");
    return ((ExtProactiveCmdIndArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshQueryResArg
    ====================================================================== */

class SimTkRefreshQueryResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshQueryResArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause, UINT8 general_result, UINT8 additional_result);
        SimTkRefreshQueryResArg();
        
        static const SimTkRefreshQueryResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        void SetGeneralResult(UINT8 general_result) { m_general_result = general_result; }
        UINT8 GetGeneralResult() const { return m_general_result; }
        void SetAdditionalResult(UINT8 additional_result) { m_additional_result = additional_result; }
        UINT8 GetAdditionalResult() const { return m_additional_result; }
        
        enum  {
            ID = 2321
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshQueryResArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        UINT8 m_general_result;
        UINT8 m_additional_result;
        
    };

// Inline definitions
inline const SimTkRefreshQueryResArg& SimTkRefreshQueryResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshQueryResArg!\n");
    return ((SimTkRefreshQueryResArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshCnfIndArg
    ====================================================================== */

class SimTkRefreshCnfIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshCnfIndArg(const SimTkTransactionId& tid);
        SimTkRefreshCnfIndArg();
        
        static const SimTkRefreshCnfIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        
        enum  {
            ID = 2322
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshCnfIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        
    };

// Inline definitions
inline const SimTkRefreshCnfIndArg& SimTkRefreshCnfIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshCnfIndArg!\n");
    return ((SimTkRefreshCnfIndArg &) arg);
}



/*  ======================================================================
    Class BrowserRegisterReqArg
    ====================================================================== */

class BrowserRegisterReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BrowserRegisterReqArg(const SiClientFlags& si_client_flags);
        BrowserRegisterReqArg();
        
        static const BrowserRegisterReqArg& Cast(const StackMsgArgument& arg);
        void SetSiClientFlags(const SiClientFlags& si_client_flags) { m_si_client_flags = si_client_flags; }
        const SiClientFlags& GetSiClientFlags() const { return m_si_client_flags; }
        
        enum  {
            ID = 2323
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BrowserRegisterReqArg*) arg); }
        
        SiClientFlags m_si_client_flags;
        
    };

// Inline definitions
inline const BrowserRegisterReqArg& BrowserRegisterReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BrowserRegisterReqArg!\n");
    return ((BrowserRegisterReqArg &) arg);
}



/*  ======================================================================
    Class LaunchBrowserPromptIndArg
    ====================================================================== */

class LaunchBrowserPromptIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        LaunchBrowserPromptIndArg(const SimTkTransactionId& tid, UINT8 general_result);
        LaunchBrowserPromptIndArg();
        
        static const LaunchBrowserPromptIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetGeneralResult(UINT8 general_result) { m_general_result = general_result; }
        UINT8 GetGeneralResult() const { return m_general_result; }
        
        enum  {
            ID = 2324
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LaunchBrowserPromptIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_general_result;
        
    };

// Inline definitions
inline const LaunchBrowserPromptIndArg& LaunchBrowserPromptIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LaunchBrowserPromptIndArg!\n");
    return ((LaunchBrowserPromptIndArg &) arg);
}



/*  ======================================================================
    Class LaunchBrowserIndArg
    ====================================================================== */

class LaunchBrowserIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        LaunchBrowserIndArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        LaunchBrowserIndArg();
        
        static const LaunchBrowserIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2325
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LaunchBrowserIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const LaunchBrowserIndArg& LaunchBrowserIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LaunchBrowserIndArg!\n");
    return ((LaunchBrowserIndArg &) arg);
}



/*  ======================================================================
    Class BrowserTermEventArg
    ====================================================================== */

class BrowserTermEventArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BrowserTermEventArg(UINT8 term_cause);
        BrowserTermEventArg();
        
        static const BrowserTermEventArg& Cast(const StackMsgArgument& arg);
        void SetTermCause(UINT8 term_cause) { m_term_cause = term_cause; }
        UINT8 GetTermCause() const { return m_term_cause; }
        
        enum  {
            ID = 2326
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BrowserTermEventArg*) arg); }
        
        UINT8 m_term_cause;
        
    };

// Inline definitions
inline const BrowserTermEventArg& BrowserTermEventArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BrowserTermEventArg!\n");
    return ((BrowserTermEventArg &) arg);
}



/*  ======================================================================
    Class SiChannelOpenPromptResArg
    ====================================================================== */

class SiChannelOpenPromptResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelOpenPromptResArg(const SimTkTransactionId& tid, const GenResultCode& gen_result);
        SiChannelOpenPromptResArg();
        
        static const SiChannelOpenPromptResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetGenResult(const GenResultCode& gen_result) { m_gen_result = gen_result; }
        const GenResultCode& GetGenResult() const { return m_gen_result; }
        
        enum  {
            ID = 2327
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelOpenPromptResArg*) arg); }
        
        SimTkTransactionId m_tid;
        GenResultCode m_gen_result;
        
    };

// Inline definitions
inline const SiChannelOpenPromptResArg& SiChannelOpenPromptResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelOpenPromptResArg!\n");
    return ((SiChannelOpenPromptResArg &) arg);
}



/*  ======================================================================
    Class SiChannelCloseReqArg
    ====================================================================== */

class SiChannelCloseReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelCloseReqArg(const SimTkTransactionId& tid, UINT8 cidx);
        SiChannelCloseReqArg();
        
        static const SiChannelCloseReqArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        
        enum  {
            ID = 2328
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelCloseReqArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        
    };

// Inline definitions
inline const SiChannelCloseReqArg& SiChannelCloseReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelCloseReqArg!\n");
    return ((SiChannelCloseReqArg &) arg);
}



/*  ======================================================================
    Class SiChannelCloseInfoResArg
    ====================================================================== */

class SiChannelCloseInfoResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelCloseInfoResArg(const SimTkTransactionId& tid, UINT8 cidx, const GenResultCode& gen_result);
        SiChannelCloseInfoResArg();
        
        static const SiChannelCloseInfoResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetGenResult(const GenResultCode& gen_result) { m_gen_result = gen_result; }
        const GenResultCode& GetGenResult() const { return m_gen_result; }
        
        enum  {
            ID = 2329
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelCloseInfoResArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        GenResultCode m_gen_result;
        
    };

// Inline definitions
inline const SiChannelCloseInfoResArg& SiChannelCloseInfoResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelCloseInfoResArg!\n");
    return ((SiChannelCloseInfoResArg &) arg);
}



/*  ======================================================================
    Class SiChannelSendInfoResArg
    ====================================================================== */

class SiChannelSendInfoResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelSendInfoResArg(const SimTkTransactionId& tid, UINT8 cidx, const GenResultCode& gen_result);
        SiChannelSendInfoResArg();
        
        static const SiChannelSendInfoResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetGenResult(const GenResultCode& gen_result) { m_gen_result = gen_result; }
        const GenResultCode& GetGenResult() const { return m_gen_result; }
        
        enum  {
            ID = 2330
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelSendInfoResArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        GenResultCode m_gen_result;
        
    };

// Inline definitions
inline const SiChannelSendInfoResArg& SiChannelSendInfoResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelSendInfoResArg!\n");
    return ((SiChannelSendInfoResArg &) arg);
}



/*  ======================================================================
    Class SiChannelReceiveInfoResArg
    ====================================================================== */

class SiChannelReceiveInfoResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SiChannelReceiveInfoResArg(const SimTkTransactionId& tid, UINT8 cidx, const GenResultCode& gen_result);
        SiChannelReceiveInfoResArg();
        
        static const SiChannelReceiveInfoResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetGenResult(const GenResultCode& gen_result) { m_gen_result = gen_result; }
        const GenResultCode& GetGenResult() const { return m_gen_result; }
        
        enum  {
            ID = 2331
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SiChannelReceiveInfoResArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        GenResultCode m_gen_result;
        
    };

// Inline definitions
inline const SiChannelReceiveInfoResArg& SiChannelReceiveInfoResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SiChannelReceiveInfoResArg!\n");
    return ((SiChannelReceiveInfoResArg &) arg);
}



/*  ======================================================================
    Class DhChannelOpenCnfArg
    ====================================================================== */

class DhChannelOpenCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelOpenCnfArg(const SimTkTransactionId& tid, UINT8 cidx, UINT16 buffer_size, const SiBearerDesc& bearer_desc, UINT8 gen_result, UINT8 adn_result);
        DhChannelOpenCnfArg();
        
        static const DhChannelOpenCnfArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetBufferSize(UINT16 buffer_size) { m_buffer_size = buffer_size; }
        UINT16 GetBufferSize() const { return m_buffer_size; }
        void SetBearerDesc(const SiBearerDesc& bearer_desc) { m_bearer_desc = bearer_desc; }
        const SiBearerDesc& GetBearerDesc() const { return m_bearer_desc; }
        void SetGenResult(UINT8 gen_result) { m_gen_result = gen_result; }
        UINT8 GetGenResult() const { return m_gen_result; }
        void SetAdnResult(UINT8 adn_result) { m_adn_result = adn_result; }
        UINT8 GetAdnResult() const { return m_adn_result; }
        
        enum  {
            ID = 2332
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelOpenCnfArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT16 m_buffer_size;
        SiBearerDesc m_bearer_desc;
        UINT8 m_gen_result;
        UINT8 m_adn_result;
        
    };

// Inline definitions
inline const DhChannelOpenCnfArg& DhChannelOpenCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelOpenCnfArg!\n");
    return ((DhChannelOpenCnfArg &) arg);
}



/*  ======================================================================
    Class DhChannelOpenRejArg
    ====================================================================== */

class DhChannelOpenRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelOpenRejArg(const SimTkTransactionId& tid, UINT8 cidx, UINT8 gen_result, UINT8 adn_result);
        DhChannelOpenRejArg();
        
        static const DhChannelOpenRejArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetGenResult(UINT8 gen_result) { m_gen_result = gen_result; }
        UINT8 GetGenResult() const { return m_gen_result; }
        void SetAdnResult(UINT8 adn_result) { m_adn_result = adn_result; }
        UINT8 GetAdnResult() const { return m_adn_result; }
        
        enum  {
            ID = 2333
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelOpenRejArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_gen_result;
        UINT8 m_adn_result;
        
    };

// Inline definitions
inline const DhChannelOpenRejArg& DhChannelOpenRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelOpenRejArg!\n");
    return ((DhChannelOpenRejArg &) arg);
}



/*  ======================================================================
    Class DhChannelCloseIndArg
    ====================================================================== */

class DhChannelCloseIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelCloseIndArg(const SimTkTransactionId& tid, UINT8 cidx, UINT8 gen_result, UINT8 adn_result);
        DhChannelCloseIndArg();
        
        static const DhChannelCloseIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetGenResult(UINT8 gen_result) { m_gen_result = gen_result; }
        UINT8 GetGenResult() const { return m_gen_result; }
        void SetAdnResult(UINT8 adn_result) { m_adn_result = adn_result; }
        UINT8 GetAdnResult() const { return m_adn_result; }
        
        enum  {
            ID = 2334
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelCloseIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT8 m_gen_result;
        UINT8 m_adn_result;
        
    };

// Inline definitions
inline const DhChannelCloseIndArg& DhChannelCloseIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelCloseIndArg!\n");
    return ((DhChannelCloseIndArg &) arg);
}



/*  ======================================================================
    Class DhChannelSendIndArg
    ====================================================================== */

class DhChannelSendIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelSendIndArg(const SimTkTransactionId& tid, UINT8 cidx, UINT16 empty_bytes_in_tx, UINT8 gen_result, UINT8 adn_result);
        DhChannelSendIndArg();
        
        static const DhChannelSendIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetEmptyBytesInTx(UINT16 empty_bytes_in_tx) { m_empty_bytes_in_tx = empty_bytes_in_tx; }
        UINT16 GetEmptyBytesInTx() const { return m_empty_bytes_in_tx; }
        void SetGenResult(UINT8 gen_result) { m_gen_result = gen_result; }
        UINT8 GetGenResult() const { return m_gen_result; }
        void SetAdnResult(UINT8 adn_result) { m_adn_result = adn_result; }
        UINT8 GetAdnResult() const { return m_adn_result; }
        
        enum  {
            ID = 2335
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelSendIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT16 m_empty_bytes_in_tx;
        UINT8 m_gen_result;
        UINT8 m_adn_result;
        
    };

// Inline definitions
inline const DhChannelSendIndArg& DhChannelSendIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelSendIndArg!\n");
    return ((DhChannelSendIndArg &) arg);
}



/*  ======================================================================
    Class DhChannelDataAvailEventArg
    ====================================================================== */

class DhChannelDataAvailEventArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelDataAvailEventArg(const SimTkTransactionId& tid, UINT8 cidx, UINT16 channel_data_length, const SiChannelChangedState& changed_state);
        DhChannelDataAvailEventArg();
        
        static const DhChannelDataAvailEventArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetChannelDataLength(UINT16 channel_data_length) { m_channel_data_length = channel_data_length; }
        UINT16 GetChannelDataLength() const { return m_channel_data_length; }
        void SetChangedState(const SiChannelChangedState& changed_state) { m_changed_state = changed_state; }
        const SiChannelChangedState& GetChangedState() const { return m_changed_state; }
        
        enum  {
            ID = 2369
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelDataAvailEventArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT16 m_channel_data_length;
        SiChannelChangedState m_changed_state;
        
    };

// Inline definitions
inline const DhChannelDataAvailEventArg& DhChannelDataAvailEventArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelDataAvailEventArg!\n");
    return ((DhChannelDataAvailEventArg &) arg);
}



/*  ======================================================================
    Class DhChannelReceiveIndArg
    ====================================================================== */

class DhChannelReceiveIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelReceiveIndArg(const SimTkTransactionId& tid, UINT8 cidx, UINT16 remaining_data_length, UINT8 gen_result, UINT8 adn_result, const ChannelData& channel_data);
        DhChannelReceiveIndArg();
        
        static const DhChannelReceiveIndArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetRemainingDataLength(UINT16 remaining_data_length) { m_remaining_data_length = remaining_data_length; }
        UINT16 GetRemainingDataLength() const { return m_remaining_data_length; }
        void SetGenResult(UINT8 gen_result) { m_gen_result = gen_result; }
        UINT8 GetGenResult() const { return m_gen_result; }
        void SetAdnResult(UINT8 adn_result) { m_adn_result = adn_result; }
        UINT8 GetAdnResult() const { return m_adn_result; }
        void SetChannelData(const ChannelData& channel_data) { m_channel_data = channel_data; }
        const ChannelData& GetChannelData() const { return m_channel_data; }
        
        enum  {
            ID = 2367
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelReceiveIndArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        UINT16 m_remaining_data_length;
        UINT8 m_gen_result;
        UINT8 m_adn_result;
        ChannelData m_channel_data;
        
    };

// Inline definitions
inline const DhChannelReceiveIndArg& DhChannelReceiveIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelReceiveIndArg!\n");
    return ((DhChannelReceiveIndArg &) arg);
}



/*  ======================================================================
    Class DhChannelChangeStatusEventArg
    ====================================================================== */

class DhChannelChangeStatusEventArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        DhChannelChangeStatusEventArg(const SimTkTransactionId& tid, UINT8 cidx, const SiChannelChangedState& changed_state);
        DhChannelChangeStatusEventArg();
        
        static const DhChannelChangeStatusEventArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetCidx(UINT8 cidx) { m_cidx = cidx; }
        UINT8 GetCidx() const { return m_cidx; }
        void SetChangedState(const SiChannelChangedState& changed_state) { m_changed_state = changed_state; }
        const SiChannelChangedState& GetChangedState() const { return m_changed_state; }
        
        enum  {
            ID = 2368
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((DhChannelChangeStatusEventArg*) arg); }
        
        SimTkTransactionId m_tid;
        UINT8 m_cidx;
        SiChannelChangedState m_changed_state;
        
    };

// Inline definitions
inline const DhChannelChangeStatusEventArg& DhChannelChangeStatusEventArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to DhChannelChangeStatusEventArg!\n");
    return ((DhChannelChangeStatusEventArg &) arg);
}



/*  ======================================================================
    Class SimTkRunAtCmdInfoResArg
    ====================================================================== */

class SimTkRunAtCmdInfoResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRunAtCmdInfoResArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        SimTkRunAtCmdInfoResArg();
        
        static const SimTkRunAtCmdInfoResArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2380
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRunAtCmdInfoResArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SimTkRunAtCmdInfoResArg& SimTkRunAtCmdInfoResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRunAtCmdInfoResArg!\n");
    return ((SimTkRunAtCmdInfoResArg &) arg);
}



/*  ======================================================================
    Class SimTkSendDtmfCnfArg
    ====================================================================== */

class SimTkSendDtmfCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkSendDtmfCnfArg(const ProactiveCause& proactive_cause);
        SimTkSendDtmfCnfArg();
        
        static const SimTkSendDtmfCnfArg& Cast(const StackMsgArgument& arg);
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2381
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkSendDtmfCnfArg*) arg); }
        
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SimTkSendDtmfCnfArg& SimTkSendDtmfCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkSendDtmfCnfArg!\n");
    return ((SimTkSendDtmfCnfArg &) arg);
}



/*  ======================================================================
    Class SimTkStopSendDtmfReqArg
    ====================================================================== */

class SimTkStopSendDtmfReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkStopSendDtmfReqArg();
        
        static const SimTkStopSendDtmfReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2382
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkStopSendDtmfReqArg*) arg); }
        
    };

// Inline definitions
inline const SimTkStopSendDtmfReqArg& SimTkStopSendDtmfReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkStopSendDtmfReqArg!\n");
    return ((SimTkStopSendDtmfReqArg &) arg);
}



/*  ======================================================================
    Class SimTkRefreshNewRspArg
    ====================================================================== */

class SimTkRefreshNewRspArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimTkRefreshNewRspArg(const SimTkTransactionId& tid, const ProactiveCause& proactive_cause);
        SimTkRefreshNewRspArg();
        
        static const SimTkRefreshNewRspArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetProactiveCause(const ProactiveCause& proactive_cause) { m_proactive_cause = proactive_cause; }
        const ProactiveCause& GetProactiveCause() const { return m_proactive_cause; }
        
        enum  {
            ID = 2383
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimTkRefreshNewRspArg*) arg); }
        
        SimTkTransactionId m_tid;
        ProactiveCause m_proactive_cause;
        
    };

// Inline definitions
inline const SimTkRefreshNewRspArg& SimTkRefreshNewRspArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimTkRefreshNewRspArg!\n");
    return ((SimTkRefreshNewRspArg &) arg);
}


#endif // Apc_SimTkStackMsgArgs_hpp

