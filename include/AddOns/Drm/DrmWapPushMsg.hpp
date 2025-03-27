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
    defined in "lnz_apoxi\Apoxi\AddOns\Drm\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(DrmWapPushMsg_hpp__ST_1101449473226)
#define DrmWapPushMsg_hpp__ST_1101449473226
#include <Kernel/Message.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class DrmWapPushMsg
    ====================================================================== */
class DrmWapPushMsg : public Message {
    public:
        DrmWapPushMsg(const DrmLocalId& local_id = c_drm_invalid_local_id);
        virtual ~DrmWapPushMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetLocalId(const DrmLocalId& local_id) { m_local_id = local_id; }
        const DrmLocalId& GetLocalId() const { return m_local_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4350
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DrmLocalId m_local_id;
        
    };
#endif // DrmWapPushMsg_hpp__ST_1101449473226

