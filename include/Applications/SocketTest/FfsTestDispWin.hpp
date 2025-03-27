/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestDispWin_hpp)
#define ApoxiApp_FfsTestDispWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <SocketTest/FfsTestThreadlet.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

#if !defined(ADLER_JUPITER) 
    #include <GuiExtensions/CommonMessageBox.hpp>
#endif

#include <Kernel/Os/Os.hpp>

class FfsTestDispWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        FfsTestDispWin(); 
        virtual ~FfsTestDispWin(); 
        
        void Init(); 

        void RefreshScreen(); 

        void OnTimer();
        
        static FfsTestThreadlet* GetThreadlet() { return  m_threadlet; }
        static void ClearThreadlet() { m_threadlet = NULL; }

        FfsTestBase* GetFfsTestBase() { return m_tests; }
        Mutex&       GetMutex() { return m_mutex; }

    protected:
        virtual void OnOpen(); 
        virtual void OnClose(); 
        virtual void OnPaint(const Rect& repaint_rect); 
        virtual BOOLEAN OnSoftkeyPressed(INT idx); 
        
    private:
        ActionAccessor m_left_menu; 
        ActionAccessor m_right_menu; 
        Action m_stop_action; 
        Action m_start_action; 

        friend class TriggerTimer<FfsTestDispWin>;
        TriggerTimer<FfsTestDispWin> m_refresh_timer;

#if !defined(ADLER_JUPITER)
        CommonMessageBox m_wait_msgbox;
#endif
        static FfsTestThreadlet* m_threadlet;

        FfsTestBase* m_tests;
        
        BOOLEAN m_start_testing;

        Mutex m_mutex;

        void CloseThreadlet();
};

#endif  // ApoxiApp_FfsTestDispWin_hpp

