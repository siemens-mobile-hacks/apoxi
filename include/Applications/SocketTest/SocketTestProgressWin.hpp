/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestProgressWin_hpp)
#define ApoxiApp_SocketTestProgressWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/MmiMenuWindow.hpp>
#include <GuiExtensions/PopupMenu.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

class SocketTestProgressWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        SocketTestProgressWin(); 
        virtual ~SocketTestProgressWin(); 
        
        void Init(); 

        void RefreshScreen(); 

        void OnTimer();

    protected:
        virtual void OnOpen(); 
        virtual void OnClose(); 
        virtual void OnPaint(const Rect &repaint_rect); 
        virtual void OnActionExecuted(Action *action); 
        
    private:
        ActionAccessor m_left_menu; 
        ActionAccessor m_right_menu; 
        Action m_stop_action; 
        Action m_next_action; 

        friend class TriggerTimer<SocketTestProgressWin>;
        TriggerTimer<SocketTestProgressWin> m_refresh_timer;
};

#endif  // ApoxiApp_SocketTestProgressWin_hpp
