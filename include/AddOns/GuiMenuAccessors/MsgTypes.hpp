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
    defined in "src\koglerm_snap_host\lnz_development\src\Apoxi\AddOns\GuiMenuAccessors\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(MenuAccessors_MsgTypes_hpp)
#define MenuAccessors_MsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Gui/Action.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AppActionExecutedMsg
    ====================================================================== */

class AppActionExecutedMsg : public ContextMsg {
    public:
        AppActionExecutedMsg(ExecutionContext* context, Action* action);
        virtual ~AppActionExecutedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Action* GetAction() const { return m_action; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Action* m_action;
        
    };

#endif // MenuAccessors_MsgTypes_hpp

