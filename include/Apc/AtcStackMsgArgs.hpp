/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "dallaros_apoxitest_dv\lnz_apoxi\Apoxi\Apc\AtcArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_AtcStackMsgArgs_hpp)
#define Apc_AtcStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/AtcTypes.hpp>
#include <Apc/Accessory.hpp>
#include <Apc/SimTkTypes.hpp>
#include <Devices/Device.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AtAlphaTagReqArg
    ====================================================================== */

class AtAlphaTagReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtAlphaTagReqArg();
        
        static const AtAlphaTagReqArg& Cast(const StackMsgArgument& arg);
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        
        enum  {
            ID = 1150
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtAlphaTagReqArg*) arg); }
        
        PhoneNumber m_phone_number;
        
    };

// Inline definitions
inline const AtAlphaTagReqArg& AtAlphaTagReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtAlphaTagReqArg!\n");
    return ((AtAlphaTagReqArg &) arg);
}



/*  ======================================================================
    Class AtPbSelectReqArg
    ====================================================================== */

class AtPbSelectReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtPbSelectReqArg();
        
        static const AtPbSelectReqArg& Cast(const StackMsgArgument& arg);
        void SetMePhoneBookType(const MePhoneBookType& me_phone_book_type) { m_me_phone_book_type = me_phone_book_type; }
        const MePhoneBookType& GetMePhoneBookType() const { return m_me_phone_book_type; }
        
        enum  {
            ID = 1151
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtPbSelectReqArg*) arg); }
        
        MePhoneBookType m_me_phone_book_type;
        
    };

// Inline definitions
inline const AtPbSelectReqArg& AtPbSelectReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtPbSelectReqArg!\n");
    return ((AtPbSelectReqArg &) arg);
}



/*  ======================================================================
    Class AtPbListReqArg
    ====================================================================== */

class AtPbListReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtPbListReqArg();
        
        static const AtPbListReqArg& Cast(const StackMsgArgument& arg);
        void SetMePhoneBookType(const MePhoneBookType& me_phone_book_type) { m_me_phone_book_type = me_phone_book_type; }
        const MePhoneBookType& GetMePhoneBookType() const { return m_me_phone_book_type; }
        void SetRecordNumber(INT record_number) { m_record_number = record_number; }
        INT GetRecordNumber() const { return m_record_number; }
        
        enum  {
            ID = 1152
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtPbListReqArg*) arg); }
        
        MePhoneBookType m_me_phone_book_type;
        INT m_record_number;
        
    };

// Inline definitions
inline const AtPbListReqArg& AtPbListReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtPbListReqArg!\n");
    return ((AtPbListReqArg &) arg);
}



/*  ======================================================================
    Class AtGenericCmdReqArg
    ====================================================================== */

class AtGenericCmdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtGenericCmdReqArg();
        
        static const AtGenericCmdReqArg& Cast(const StackMsgArgument& arg);
        void SetCmd(const AtGenericCmdType& cmd) { m_cmd = cmd; }
        const AtGenericCmdType& GetCmd() const { return m_cmd; }
        
        enum  {
            ID = 1153
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtGenericCmdReqArg*) arg); }
        
        AtGenericCmdType m_cmd;
        
    };

// Inline definitions
inline const AtGenericCmdReqArg& AtGenericCmdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtGenericCmdReqArg!\n");
    return ((AtGenericCmdReqArg &) arg);
}



/*  ======================================================================
    Class AtAccessoryRegisterReqArg
    ====================================================================== */

class AtAccessoryRegisterReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtAccessoryRegisterReqArg(BOOLEAN enabled);
        AtAccessoryRegisterReqArg();
        
        static const AtAccessoryRegisterReqArg& Cast(const StackMsgArgument& arg);
        void SetEnabled(BOOLEAN enabled) { m_enabled = enabled; }
        BOOLEAN IsEnabled() const { return m_enabled; }
        
        enum  {
            ID = 1154
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtAccessoryRegisterReqArg*) arg); }
        
        BOOLEAN m_enabled;
        
    };

// Inline definitions
inline const AtAccessoryRegisterReqArg& AtAccessoryRegisterReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtAccessoryRegisterReqArg!\n");
    return ((AtAccessoryRegisterReqArg &) arg);
}



/*  ======================================================================
    Class AtAlphaTagCnfArg
    ====================================================================== */

class AtAlphaTagCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtAlphaTagCnfArg(const WString& alpha_id, const PhoneNumber& phone_number);
        AtAlphaTagCnfArg();
        
        static const AtAlphaTagCnfArg& Cast(const StackMsgArgument& arg);
        void SetAlphaId(const WString& alpha_id) { m_alpha_id = alpha_id; }
        const WString& GetAlphaId() const { return m_alpha_id; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        
        enum  {
            ID = 2150
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtAlphaTagCnfArg*) arg); }
        
        WString m_alpha_id;
        PhoneNumber m_phone_number;
        
    };

// Inline definitions
inline const AtAlphaTagCnfArg& AtAlphaTagCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtAlphaTagCnfArg!\n");
    return ((AtAlphaTagCnfArg &) arg);
}



/*  ======================================================================
    Class AtPbSelectCnfArg
    ====================================================================== */

class AtPbSelectCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtPbSelectCnfArg(const MePhoneBookStatus& status, const MePhoneBookType& me_phone_book_type, INT used_entries, INT total_entries, INT max_alpha_length);
        AtPbSelectCnfArg();
        
        static const AtPbSelectCnfArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const MePhoneBookStatus& status) { m_status = status; }
        const MePhoneBookStatus& GetStatus() const { return m_status; }
        void SetMePhoneBookType(const MePhoneBookType& me_phone_book_type) { m_me_phone_book_type = me_phone_book_type; }
        const MePhoneBookType& GetMePhoneBookType() const { return m_me_phone_book_type; }
        void SetUsedEntries(INT used_entries) { m_used_entries = used_entries; }
        INT GetUsedEntries() const { return m_used_entries; }
        void SetTotalEntries(INT total_entries) { m_total_entries = total_entries; }
        INT GetTotalEntries() const { return m_total_entries; }
        void SetMaxAlphaLength(INT max_alpha_length) { m_max_alpha_length = max_alpha_length; }
        INT GetMaxAlphaLength() const { return m_max_alpha_length; }
        
        enum  {
            ID = 2151
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtPbSelectCnfArg*) arg); }
        
        MePhoneBookStatus m_status;
        MePhoneBookType m_me_phone_book_type;
        INT m_used_entries;
        INT m_total_entries;
        INT m_max_alpha_length;
        
    };

// Inline definitions
inline const AtPbSelectCnfArg& AtPbSelectCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtPbSelectCnfArg!\n");
    return ((AtPbSelectCnfArg &) arg);
}



/*  ======================================================================
    Class AtPbListCnfArg
    ====================================================================== */

class AtPbListCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtPbListCnfArg(const MePhoneBookStatus& status, const MePhoneBookType& me_phone_book_type, INT record_number, const WString& alpha_identifier, const PhoneNumber& phone_number);
        AtPbListCnfArg();
        
        static const AtPbListCnfArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const MePhoneBookStatus& status) { m_status = status; }
        const MePhoneBookStatus& GetStatus() const { return m_status; }
        void SetMePhoneBookType(const MePhoneBookType& me_phone_book_type) { m_me_phone_book_type = me_phone_book_type; }
        const MePhoneBookType& GetMePhoneBookType() const { return m_me_phone_book_type; }
        void SetRecordNumber(INT record_number) { m_record_number = record_number; }
        INT GetRecordNumber() const { return m_record_number; }
        void SetAlphaIdentifier(const WString& alpha_identifier) { m_alpha_identifier = alpha_identifier; }
        const WString& GetAlphaIdentifier() const { return m_alpha_identifier; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        
        enum  {
            ID = 2152
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtPbListCnfArg*) arg); }
        
        MePhoneBookStatus m_status;
        MePhoneBookType m_me_phone_book_type;
        INT m_record_number;
        WString m_alpha_identifier;
        PhoneNumber m_phone_number;
        
    };

// Inline definitions
inline const AtPbListCnfArg& AtPbListCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtPbListCnfArg!\n");
    return ((AtPbListCnfArg &) arg);
}



/*  ======================================================================
    Class AtPbInfoIndArg
    ====================================================================== */

class AtPbInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtPbInfoIndArg(const MePhonebookDescription& desc);
        AtPbInfoIndArg();
        
        static const AtPbInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetDesc(const MePhonebookDescription& desc) { m_desc = desc; }
        const MePhonebookDescription& GetDesc() const { return m_desc; }
        
        enum  {
            ID = 2153
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtPbInfoIndArg*) arg); }
        
        MePhonebookDescription m_desc;
        
    };

// Inline definitions
inline const AtPbInfoIndArg& AtPbInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtPbInfoIndArg!\n");
    return ((AtPbInfoIndArg &) arg);
}



/*  ======================================================================
    Class AtGenericCmdIndArg
    ====================================================================== */

class AtGenericCmdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtGenericCmdIndArg(const AtStatusType& status, BOOLEAN final, const AtGenericCmdType& cmd);
        AtGenericCmdIndArg();
        
        static const AtGenericCmdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const AtStatusType& status) { m_status = status; }
        const AtStatusType& GetStatus() const { return m_status; }
        void SetFinal(BOOLEAN final) { m_final = final; }
        BOOLEAN IsFinal() const { return m_final; }
        void SetCmd(const AtGenericCmdType& cmd) { m_cmd = cmd; }
        const AtGenericCmdType& GetCmd() const { return m_cmd; }
        
        enum  {
            ID = 2154
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtGenericCmdIndArg*) arg); }
        
        AtStatusType m_status;
        BOOLEAN m_final;
        AtGenericCmdType m_cmd;
        
    };

// Inline definitions
inline const AtGenericCmdIndArg& AtGenericCmdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtGenericCmdIndArg!\n");
    return ((AtGenericCmdIndArg &) arg);
}



/*  ======================================================================
    Class AtAccessoryNotificationIndArg
    ====================================================================== */

class AtAccessoryNotificationIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtAccessoryNotificationIndArg(const AtGenericCmdType& cmd);
        AtAccessoryNotificationIndArg();
        
        static const AtAccessoryNotificationIndArg& Cast(const StackMsgArgument& arg);
        void SetCmd(const AtGenericCmdType& cmd) { m_cmd = cmd; }
        const AtGenericCmdType& GetCmd() const { return m_cmd; }
        
        enum  {
            ID = 2155
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtAccessoryNotificationIndArg*) arg); }
        
        AtGenericCmdType m_cmd;
        
    };

// Inline definitions
inline const AtAccessoryNotificationIndArg& AtAccessoryNotificationIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtAccessoryNotificationIndArg!\n");
    return ((AtAccessoryNotificationIndArg &) arg);
}



/*  ======================================================================
    Class AtAccessoryRegisterCnfArg
    ====================================================================== */

class AtAccessoryRegisterCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        AtAccessoryRegisterCnfArg(const AtStatusType& status);
        AtAccessoryRegisterCnfArg();
        
        static const AtAccessoryRegisterCnfArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const AtStatusType& status) { m_status = status; }
        const AtStatusType& GetStatus() const { return m_status; }
        
        enum  {
            ID = 2156
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AtAccessoryRegisterCnfArg*) arg); }
        
        AtStatusType m_status;
        
    };

// Inline definitions
inline const AtAccessoryRegisterCnfArg& AtAccessoryRegisterCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AtAccessoryRegisterCnfArg!\n");
    return ((AtAccessoryRegisterCnfArg &) arg);
}


#endif // Apc_AtcStackMsgArgs_hpp

