/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestResultsWin_hpp)
#define ApoxiApp_SocketTestResultsWin_hpp

#include <GuiExtensions/MmiWindow.hpp>

class SocketTestResultsWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        SocketTestResultsWin();
        virtual ~SocketTestResultsWin();

        void Init();

    protected:
        virtual void OnActionExecuted(Action* action);
        
    private:
        Action m_select_action;
        Action m_close_action;
        ItemMenu m_menu;

        void AddTestItems();
};

#endif  // ApoxiApp_SocketTestResultsWin_hpp
