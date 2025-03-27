/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "bhisel_view_snap\lnz_apps_int\Applications\AdvPhonebook\MagTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Applications_AdvPbMsgTypes_hpp)
#define Applications_AdvPbMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>
#include <AdvPhonebook/PbAbstractWin.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class JumpToRowMsg
    ====================================================================== */

class JumpToRowMsg : public ControlMsg {
    public:
        JumpToRowMsg(Control* control);
        virtual ~JumpToRowMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 30003
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class OpenPbWinMsg
    ====================================================================== */

class OpenPbWinMsg : public ContextMsg {
    public:
        OpenPbWinMsg(ExecutionContext* context, PbAbstractWin* win);
        virtual ~OpenPbWinMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetWin(PbAbstractWin* win) { m_win = win; }
        PbAbstractWin* GetWin() const { return m_win; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30004
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PbAbstractWin* m_win;
        
    };


/*  ======================================================================
    Class SaveEntryInPhonebookMsg
    ====================================================================== */

class SaveEntryInPhonebookMsg : public ContextMsg {
    public:
        SaveEntryInPhonebookMsg(ExecutionContext* context, const WString& name, const PhoneNumber& phone_no, const WString& email);
        virtual ~SaveEntryInPhonebookMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetName(const WString& name) { m_name = name; }
        const WString& GetName() const { return m_name; }
        void SetPhoneNo(const PhoneNumber& phone_no) { m_phone_no = phone_no; }
        const PhoneNumber& GetPhoneNo() const { return m_phone_no; }
        void SetEmail(const WString& email) { m_email = email; }
        const WString& GetEmail() const { return m_email; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_name;
        PhoneNumber m_phone_no;
        WString m_email;
        
    };


/*  ======================================================================
    Class SyncProgressMsg
    ====================================================================== */

class SyncProgressMsg : public ContextMsg {
    public:
        SyncProgressMsg(ExecutionContext* context, INT progress);
        virtual ~SyncProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetProgress(INT progress) { m_progress = progress; }
        INT GetProgress() const { return m_progress; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30006
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_progress;
        
    };


/*  ======================================================================
    Class ProviderUpdateMsg
    ====================================================================== */

class ProviderUpdateMsg : public ContextMsg {
    public:
        ProviderUpdateMsg(ExecutionContext* context, Provider* provider, INT state);
        virtual ~ProviderUpdateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetProvider(Provider* provider) { m_provider = provider; }
        Provider* GetProvider() const { return m_provider; }
        void SetState(INT state) { m_state = state; }
        INT GetState() const { return m_state; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30007
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Provider* m_provider;
        INT m_state;
        
    };


/*  ======================================================================
    Class PhonebookRenumberedMsg
    ====================================================================== */

class PhonebookRenumberedMsg : public Message {
    public:
        PhonebookRenumberedMsg();
        virtual ~PhonebookRenumberedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 30008
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Applications_AdvPbMsgTypes_hpp

