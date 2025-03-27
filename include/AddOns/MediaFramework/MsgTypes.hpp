/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "APOXI\SDK\bin\MessageGenerator\samples\SampleMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(MsgTypes_hpp__ST_1122019187332)
#define MsgTypes_hpp__ST_1122019187332

#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>
#include <AddOns/MediaFramework/MediaManager.hpp>
#include <Kernel/InputStream.hpp>
#include <Kernel/OutputStream.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class MediaManagerMsg
    ====================================================================== */

class MediaManagerMsg : public ContextMsg {
    public:
        MediaManagerMsg(ExecutionContext* application, const MediaManager::MmfMsgType& type, const MediaManager::MmfResult& mmfresult, void* instanceptr = 0);
        virtual ~MediaManagerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetType(const MediaManager::MmfMsgType& type) { m_type = type; }
        const MediaManager::MmfMsgType& GetType() const { return m_type; }
        void SetMmfresult(const MediaManager::MmfResult& mmfresult) { m_mmfresult = mmfresult; }
        const MediaManager::MmfResult& GetMmfresult() const { return m_mmfresult; }

        void SetInstanceptr(void* instanceptr) { m_p_instance = instanceptr; }
        void* GetInstanceptr() { return m_p_instance; }

        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const MediaManagerMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, MediaManagerMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 54000
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        MediaManager::MmfMsgType m_type;
        MediaManager::MmfResult m_mmfresult;
        void*                   m_p_instance;
        
    };

/*  ======================================================================
    Class MCServiceInterfaceMsg
    ====================================================================== */

class MCServiceInterfaceMsg : public ApplicationMsg {
    public:
        MCServiceInterfaceMsg(Application* application, INT32 type, const WString& pathname);
        virtual ~MCServiceInterfaceMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetType(INT32 type) { m_type = type; }
        INT32 GetType() const { return m_type; }
        void SetPathname(const WString& pathname) { m_pathname = pathname; }
        const WString& GetPathname() const { return m_pathname; }
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const MCServiceInterfaceMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, MCServiceInterfaceMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 54001
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        INT32 m_type;
        WString m_pathname;
        
    };


#endif // MsgTypes_hpp__ST_1122019187332

