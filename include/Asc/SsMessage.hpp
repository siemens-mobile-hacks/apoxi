/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\koglerm_snap_host\lnz_development\src\Apoxi\Asc\SsMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Asc_SsMessage_hpp)
#define Asc_SsMessage_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/LockTypes.hpp>
#include <Asc/Types.hpp>
#include <Asc/CallHdl.hpp>
#include <Asc/MsgArgs.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/TimeZone.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SsMessage
    ====================================================================== */

class SsMessage : public ContextMsg {
    public:
        SsMessage(ExecutionContext* context);
        virtual ~SsMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18499
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Asc_SsMessage_hpp

