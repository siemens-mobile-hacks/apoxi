/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\Common\LcsCommonMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_Common_LcsCommonMsgTypes_hpp)
#define AddOns_Lcs_Common_LcsCommonMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>
#include <AddOns/Lcs/Common/LcsProviderImplBase.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class LocationNotifInvokeMsg
    ====================================================================== */

class LocationNotifInvokeMsg : public ContextMsg {
    public:
        LocationNotifInvokeMsg(ExecutionContext* context, UINT16 invoke_id, const LcsNotificationType& notif_type, const LocationType& location_type, const ClientInfo& client_info);
        virtual ~LocationNotifInvokeMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT16 GetInvokeId() const { return m_invoke_id; }
        const LcsNotificationType& GetNotifType() const { return m_notif_type; }
        const LocationType& GetLocationType() const { return m_location_type; }
        const ClientInfo& GetClientInfo() const { return m_client_info; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4205
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT16 m_invoke_id;
        LcsNotificationType m_notif_type;
        LocationType m_location_type;
        ClientInfo m_client_info;
        
    };


/*  ======================================================================
    Class LocationResMsg
    ====================================================================== */

class LocationResMsg : public ContextMsg {
    public:
        LocationResMsg(ExecutionContext* context, const LocationEstimate& location_estimate);
        virtual ~LocationResMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const LocationEstimate& GetLocationEstimate() const { return m_location_estimate; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4206
            };
        
    private:
        static const MsgMetaData m_meta_data;
        LocationEstimate m_location_estimate;
        
    };


/*  ======================================================================
    Class LocationErrMsg
    ====================================================================== */

class LocationErrMsg : public ContextMsg {
    public:
        LocationErrMsg(ExecutionContext* context, const LcsErrorCode& err_code);
        virtual ~LocationErrMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const LcsErrorCode& GetErrCode() const { return m_err_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4207
            };
        
    private:
        static const MsgMetaData m_meta_data;
        LcsErrorCode m_err_code;
        
    };


/*  ======================================================================
    Class AbortResMsg
    ====================================================================== */

class AbortResMsg : public ContextMsg {
    public:
        AbortResMsg(ExecutionContext* context);
        virtual ~AbortResMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 4208
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class ProviderChangedMsg
    ====================================================================== */

class ProviderChangedMsg : public Message {
    public:
        ProviderChangedMsg(const LcsTransportType& protocol, LcsProviderImplBase* provider);
        virtual ~ProviderChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const LcsTransportType& GetProtocol() const { return m_protocol; }
        LcsProviderImplBase* GetProvider() const { return m_provider; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4209
            };
        
    private:
        static const MsgMetaData m_meta_data;
        LcsTransportType m_protocol;
        LcsProviderImplBase* m_provider;
        
    };


/*  ======================================================================
    Class ProcessMolrMsg
    ====================================================================== */

class ProcessMolrMsg : public Message {
    public:
        ProcessMolrMsg(MolrInfo* molr_info);
        virtual ~ProcessMolrMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        MolrInfo* GetMolrInfo() const { return m_molr_info; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4210
            };
        
    private:
        static const MsgMetaData m_meta_data;
        MolrInfo* m_molr_info;
        
    };

#endif // AddOns_Lcs_Common_LcsCommonMsgTypes_hpp

