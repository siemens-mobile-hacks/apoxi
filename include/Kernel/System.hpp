/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_System_hpp)
#define Apoxi_System_hpp

#include <Auxiliary/Macros.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Kernel/Os/Os.hpp>
#include <Kernel/Os/SemObtainer.hpp>
#include <Gui/Color.hpp>
#include <Gui/Font.hpp>
#include <Gui/LanguageManager.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Devices/DeviceManager.hpp>
#include <Devices/ShutDown.hpp>

class Application;
class AppContainer;
class ExternalCommunicationHandler;
class MessageRouter;
class ResourceManager;
class Theme;
class ClientDc;
class Display;
class ApoxiThread;

class System {
    public:
        static void Init(ExternalCommunicationHandler* external_communicator = 0);

        static BOOLEAN ShutDown(BOOLEAN force = FALSE, ShutDown::Mode mode = ShutDown::PowerOff);

        static AppContainer* GetFocusedAppContainer();

        static AppContainer* GetActiveAppContainer();

        static AppContainer* GetFirstAppContainer();

        static Application* GetFocusedApplication();
        
        static BOOLEAN GrabFocus(Application* app);

        static Application* GetActiveApplication();

        static Semaphore* GetSystemSemaphore() { return &m_system_sem; }

        static void SetTheme(ThemeId theme_id);

        static ColorValue GetColorValue(SystemColorId system_color_id);

        static const Font& GetFont(SystemFontId system_font_id);

        static const MessageRouter& GetMessageRouter() { 
            ASSERT_DEBUG(m_initialized);
            return m_message_router; 
        }

        static BOOLEAN IsInitialized() { return m_initialized; }

        static void AddAppContainer(AppContainer* app_cont);

        static void RemoveAppContainer(AppContainer* app_cont);
        
        /*  ********************************************************************
            obsolete methods 
            *******************************************************************/

        static INT GetLanguage();

        static const Theme& GetTheme();

        static INT GetThemeId();

        static INT GetCurrentFocusPriority();

        static void GrabFocus(Application* app, INT priority, BOOLEAN assign_to_win);

        static void InitLanguage(INT lang_id) { 
            LanguageManager::SetActiveLanguage(lang_id); 
        }

        static void SetLanguage(INT lang_id) {
            LanguageManager::SetActiveLanguage(lang_id);
        }

        static BOOLEAN LanguageChanged() { 
            return LanguageManager::HasActiveLanguageChanged();
        }

        static Display* GetDisplay(INT display_idx = 0); 

        static ClientDc* GetSharedDc(INT display_idx = 0); 

    private:
        friend class FocusObtainer;
        friend class StartUp;
        friend class ShutDown;
        friend class ServiceThread;
        friend class MessageRouter;
        friend class Os;

        static BOOLEAN m_initialized;
        static Application* m_focused_app;
        static LinkedList<ApoxiThread> m_thread_list;
        static MessageRouter m_message_router;
        static Mutex m_thread_list_mutex;
        static Semaphore m_system_sem;          // global system sem

        static void AddApoxiThread(ApoxiThread* thread);
        static void RemoveApoxiThread(ApoxiThread* thread);
        static ApoxiThread* GetFirstApoxiThread();
};

class FocusObtainer : public SemObtainer {
    typedef SemObtainer Base;

    public:
        FocusObtainer();

    private:
        friend class System;
        
        static Semaphore m_sem;
};

#endif  // Apoxi_System_hpp

