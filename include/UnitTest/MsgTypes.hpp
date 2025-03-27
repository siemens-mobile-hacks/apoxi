/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_development\src\Apoxi\UnitTest\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(UnitTest_MsgTypes_hpp)
#define UnitTest_MsgTypes_hpp
#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class AsyncUnitTestMsg
    ====================================================================== */
class AsyncUnitTestMsg : public ApplicationMsg {
    public:
        AsyncUnitTestMsg(Application* application, const WString& MessageText);
        virtual ~AsyncUnitTestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMessageText(const WString& MessageText) { m_MessageText = MessageText; }
        const WString& GetMessageText() const { return m_MessageText; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19300
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_MessageText;
        
    };
/*  ======================================================================
    Class UtcStatusMessage
    ====================================================================== */
class UtcStatusMessage : public ApplicationMsg {
    public:
        UtcStatusMessage(Application* application, const WString& MessageText, BOOLEAN ConnectionLost);
        virtual ~UtcStatusMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMessageText(const WString& MessageText) { m_MessageText = MessageText; }
        const WString& GetMessageText() const { return m_MessageText; }
        void SetConnectionLost(BOOLEAN ConnectionLost) { m_ConnectionLost = ConnectionLost; }
        BOOLEAN IsConnectionLost() const { return m_ConnectionLost; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19301
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_MessageText;
        BOOLEAN m_ConnectionLost;
        
    };
#endif // UnitTest_MsgTypes_hpp


