/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\Ehlersh_MP1E_Multi_V1\lnz_apps_int\Applications\Camera\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Common_MsgTypes_hpp)
#define Common_MsgTypes_hpp
#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class CameraMsgStartViewfinding
    ====================================================================== */
class CameraMsgStartViewfinding : public ContextMsg {
    public:
        CameraMsgStartViewfinding(ExecutionContext* context);
        virtual ~CameraMsgStartViewfinding();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 22700
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class CameraMsgStopViewfinding
    ====================================================================== */
class CameraMsgStopViewfinding : public ContextMsg {
    public:
        CameraMsgStopViewfinding(ExecutionContext* context);
        virtual ~CameraMsgStopViewfinding();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 22701
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif // Common_MsgTypes_hpp
