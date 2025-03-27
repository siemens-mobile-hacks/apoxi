/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_development\src\Applications\UnifiedInbox\UibMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(UnifiedInbox_UibMsgTypes_hpp)
#define UnifiedInbox_UibMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Auxiliary/Provider.hpp>
#include <Auxiliary/WString.hpp>
#include <Gui/EditorDocument.hpp>
#include <Kernel/InputStream.hpp>
#include <Kernel/OutputStream.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class UibRegisterMsg
    ====================================================================== */

class UibRegisterMsg : public ApplicationMsg {
    public:
        UibRegisterMsg(Application* application, UINT8 box_type, Provider* folder);
        virtual ~UibRegisterMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetBoxType(UINT8 box_type) { m_box_type = box_type; }
        UINT8 GetBoxType() const { return m_box_type; }
        void SetFolder(Provider* folder) { m_folder = folder; }
        Provider* GetFolder() const { return m_folder; }
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const UibRegisterMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, UibRegisterMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 30000
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        UINT8 m_box_type;
        Provider* m_folder;
        
    };


/*  ======================================================================
    Class UibNotifyMsg
    ====================================================================== */

class UibNotifyMsg : public ApplicationMsg {
    public:
        UibNotifyMsg(Application* application);
        virtual ~UibNotifyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const UibNotifyMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, UibNotifyMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 30001
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class UibUpdateMsg
    ====================================================================== */

class UibUpdateMsg : public ApplicationMsg {
    public:
        UibUpdateMsg(Application* application);
        virtual ~UibUpdateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const UibUpdateMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, UibUpdateMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 30002
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // UnifiedInbox_UibMsgTypes_hpp

