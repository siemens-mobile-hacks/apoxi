/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsMainMenuWin_hpp)
#define Mmi_LcsMainMenuWin_hpp

#include "LcsOptionsMenuWin.hpp"

#include <GuiExtensions/MmiMenuWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include <Gui/Action.hpp>
#include <Auxiliary/WString.hpp>

class LcsMainMenuWin : public MmiMenuWindow 
{
    typedef MmiMenuWindow Base;

    public:

        LcsMainMenuWin();

        virtual ~LcsMainMenuWin();

        void Init();

        void SetStatus(INT status);

        void SetTime(WString time_str);
    

    protected:

        virtual void OnOpen();

        virtual void OnGetFocus();

        virtual void OnActionExecuted(Action *action);


    private:

        ActionAccessor m_accessor;

        Action m_gps_recv_action;

        Action m_wai_action;

        Action m_ff_action;

        LcsOptionsMenuWin m_lcs_options_dlg;

        INT m_status;

        WString m_real_time;

}; // LcsMainMenuWin

#endif // Mmi_LcsMainMenuWin_hpp
