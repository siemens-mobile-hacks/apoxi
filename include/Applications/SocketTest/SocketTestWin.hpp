/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestWin_hpp)
#define ApoxiApp_SocketTestWin_hpp

#include <GuiExtensions/MmiMenuWindow.hpp>
#include <SocketTest/SocketTestProgressWin.hpp>
#include <SocketTest/SocketTestSettingsWin.hpp>
#include <SocketTest/FfsMenu.hpp>
#include <SocketTest/SocketTestResultsWin.hpp>

class SocketTestWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        SocketTestWin();
        virtual ~SocketTestWin();

        void Init();

    protected:
        virtual void OnOpen();
        virtual void OnPaint(const Rect& repaint_rect);
        virtual void OnActionExecuted(Action* action);

    private:
        SocketTestResultsWin m_results_win;
        SocketTestProgressWin m_progress_win;
        SocketTestSettingsWin m_settings_win;

        MmiMenuWindow           m_ffs_win; 
        FfsMenu                 m_ffs_menu; 

        OpenContextMenuAction m_menu_action;

        Action m_start_action;
        OpenWindowAction m_results_action;
        OpenWindowAction m_ffs_test_action;
        OpenWindowAction m_settings_action;
        CloseWindowAction m_close_action;

        void RefreshScreen();
};

#endif  // ApoxiApp_SocketTestWin_hpp
