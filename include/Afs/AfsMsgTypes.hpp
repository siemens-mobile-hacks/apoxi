/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "ayyalaso_apoxi_usb_rel_view\lnz_apoxi\Apoxi\Afs\AfsMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Afs_AfsMsgTypes_hpp)
#define Afs_AfsMsgTypes_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Kernel/MsgTypes.hpp>
#include <Kernel/Application.hpp>
#include <Afs/Uri.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class RegNotifyMsg
    ====================================================================== */

class RegNotifyMsg : public ContextMsg {
    public:
        RegNotifyMsg(ExecutionContext* context, const Uri& uri);
        virtual ~RegNotifyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Uri& GetUri() const { return m_uri; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 16000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Uri m_uri;
        
    };

#endif // Afs_AfsMsgTypes_hpp

