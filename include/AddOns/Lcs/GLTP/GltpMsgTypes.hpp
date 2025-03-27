/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\GLTP\GltpMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(AddOns_Lcs_GLTP_GltpMsgTypes_hpp)
#define AddOns_Lcs_GLTP_GltpMsgTypes_hpp
#include <AddOns/Lcs/GLTP/GltpTypes.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class SetupDataConnMsg
    ====================================================================== */
class SetupDataConnMsg : public ContextMsg {
    public:
        SetupDataConnMsg(ExecutionContext* context);
        virtual ~SetupDataConnMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 4230
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class SendRequestMsg
    ====================================================================== */
class SendRequestMsg : public ContextMsg {
    public:
        SendRequestMsg(ExecutionContext* context, BYTE* request, INT size);
        virtual ~SendRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        BYTE* GetRequest() const { return m_request; }
        INT GetSize() const { return m_size; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4231
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BYTE* m_request;
        INT m_size;
        
    };
/*  ======================================================================
    Class GltpConnStatusMsg
    ====================================================================== */
class GltpConnStatusMsg : public ContextMsg {
    public:
        GltpConnStatusMsg(ExecutionContext* context, const GltpConnStatus& status);
        virtual ~GltpConnStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const GltpConnStatus& GetStatus() const { return m_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4232
            };
        
    private:
        static const MsgMetaData m_meta_data;
        GltpConnStatus m_status;
        
    };
/*  ======================================================================
    Class CloseDataConnMsg
    ====================================================================== */
class CloseDataConnMsg : public ContextMsg {
    public:
        CloseDataConnMsg(ExecutionContext* context);
        virtual ~CloseDataConnMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 4233
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif // AddOns_Lcs_GLTP_GltpMsgTypes_hpp

