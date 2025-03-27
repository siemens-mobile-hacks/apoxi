/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Obex\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Obex_ObexAppMsg_hpp)
#define Obex_ObexAppMsg_hpp
#include <Kernel/Message.hpp>
#include <Obex/ObexTypes.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class ObexAppMsg
    ====================================================================== */
class ObexAppMsg : public ContextMsg {
    public:
        ObexAppMsg(ExecutionContext* context, const ObexAppMsgType& msg_type);
        virtual ~ObexAppMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ObexAppMsgType& GetMsgType() const { return m_msg_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 11005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ObexAppMsgType m_msg_type;
        
    };
#endif // Obex_ObexAppMsg_hpp


