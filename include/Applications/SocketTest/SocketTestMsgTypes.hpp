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
    defined in "src\koglerm_host\lnz_development\src\Applications\SocketTest\SocketTestMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(SocketTestMsgTypes_hpp__ST_1092045237546)
#define SocketTestMsgTypes_hpp__ST_1092045237546

#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class StartSocketTestMsg
    ====================================================================== */

class StartSocketTestMsg : public ContextMsg {
    public:
        StartSocketTestMsg(ExecutionContext* context);
        virtual ~StartSocketTestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21900
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class NextSocketTestMsg
    ====================================================================== */

class NextSocketTestMsg : public ContextMsg {
    public:
        NextSocketTestMsg(ExecutionContext* context);
        virtual ~NextSocketTestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21901
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class ContinueSocketTestMsg
    ====================================================================== */

class ContinueSocketTestMsg : public ContextMsg {
    public:
        ContinueSocketTestMsg(ExecutionContext* context);
        virtual ~ContinueSocketTestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21902
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class StopSocketTestMsg
    ====================================================================== */

class StopSocketTestMsg : public ContextMsg {
    public:
        StopSocketTestMsg(ExecutionContext* context);
        virtual ~StopSocketTestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21903
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SkipSocketTestMsg
    ====================================================================== */

class SkipSocketTestMsg : public ContextMsg {
    public:
        SkipSocketTestMsg(ExecutionContext* context);
        virtual ~SkipSocketTestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21904
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // SocketTestMsgTypes_hpp__ST_1092045237546

