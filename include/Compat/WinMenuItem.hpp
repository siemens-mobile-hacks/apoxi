/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_WinMenuItem_hpp)
#define Apoxi_WinMenuItem_hpp

#include <Compat/MenuItem.hpp>
#include <Gui/OpenWindowAction.hpp>

class MenuList;
class Window;

class WinMenuItem : public MenuItem {
    typedef MenuItem Base;

    public:
        WinMenuItem();

        WinMenuItem(Window *win, const WCHAR *text = 0, const BitmapRes *bitmap = 0, BOOLEAN enabled = TRUE);

        void Init(Window *win, const WCHAR *text = 0, const BitmapRes *bitmap = 0, BOOLEAN enabled = TRUE);

        Window* GetWindow() { return m_win; }

    private:
        Window           *m_win;
        OpenWindowAction m_open_win_action;
};

#endif  // Apoxi_WinMenuItem_hpp


