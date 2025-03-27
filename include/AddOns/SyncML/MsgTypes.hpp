/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\koglerm_snap_host\lnz_development\src\Apoxi\AddOns\SyncML\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(SyncML_MsgTypes_hpp)
#define SyncML_MsgTypes_hpp

#include <Kernel/Message.hpp>
#include <AddOns/SyncML/SyncMLManager.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class DBItemChangedMsg
    ====================================================================== */

class DBItemChangedMsg : public ContextMsg {
    public:
        DBItemChangedMsg(ExecutionContext* context, UINT16 db_uri, UINT32 item_uri, const DateTime& time_stamp, const SyncMLChangeType& opcode);
        virtual ~DBItemChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT16 GetDbUri() const { return m_db_uri; }
        UINT32 GetItemUri() const { return m_item_uri; }
        const DateTime& GetTimeStamp() const { return m_time_stamp; }
        const SyncMLChangeType& GetOpcode() const { return m_opcode; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4100
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT16 m_db_uri;
        UINT32 m_item_uri;
        DateTime m_time_stamp;
        SyncMLChangeType m_opcode;
        
    };

#endif // SyncML_MsgTypes_hpp

