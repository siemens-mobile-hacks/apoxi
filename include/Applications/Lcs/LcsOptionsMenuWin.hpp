/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsOptionsMenuWin_hpp)
#define Mmi_LcsOptionsMenuWin_hpp

#include "TransferLocationDialogWin.hpp"

#include <GuiExtensions/MmiMenuWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include <Gui/Action.hpp>

class LcsOptionsMenuWin : public MmiMenuWindow 
{
    typedef MmiMenuWindow Base;

    public:

        LcsOptionsMenuWin();

        virtual ~LcsOptionsMenuWin();

        void Init();

        void SetStatus(INT status);

        void SetTime(WString time_str);
    

    protected:

        virtual void OnOpen();

        virtual void OnActionExecuted(Action *action);


    private:

        ActionAccessor m_accessor;

        Action m_self_loc_action;

        Action m_transfer_loc_action;

        TransferLocationDialog m_transfer_loc_dlg;

        INT m_status;

        WString m_real_time;

}; // LcsOptionsMenuWin

#endif // Mmi_LcsOptionsMenuWin_hpp
