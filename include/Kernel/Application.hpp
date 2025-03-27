/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Apoxi_Application_hpp)
#define Apoxi_Application_hpp

#include <Kernel/Dispatcher.hpp>
#include <Kernel/ExecutionContext.hpp>
#include <Gui/Control.hpp>
#include <Devices/StartUp.hpp>
#include <Kernel/Trace.hpp>
#include <Gui/DeviceContext.hpp>

class AppContainer;
class Window;
class Panel;
class Timer;

class Application : public Dispatcher, public ExecutionContext, public Linkable<Application> {
    typedef Dispatcher Base;

    public:
        Application(const WCHAR* app_name, UINT stacksize = 0);

        virtual ~Application();

        virtual Type GetType() const;

        virtual void RegisterMessage(MsgId msg_id);

        virtual void UnregisterMessage(MsgId msg_id);

        void Post(const Message& msg) const;

        BOOLEAN GrabFocus();

        BOOLEAN HasFocus() const;

        Window* GetFocusedWindow() const;

        Window* GetFirstWindow() const { return (Window*)m_first_control; }

        void AddWindow(Window* win);

        void RemoveWindow(Window* win);

        BOOLEAN ContainsWindow(const Window* win) const;

        void SetName(const WCHAR* name) { m_app_name = name; }

        const WCHAR* GetName() const { return m_app_name; }

        void SetAppContainer(AppContainer* app_container);

        AppContainer* GetAppContainer() const { return m_app_container; }

        void UpdateDisplay(INT display_idx = 0);

        UINT GetRequestedStackSize() const { return m_requested_stacksize; }

        void SetShutdownAllowed(BOOLEAN shutdown_allowed) { m_bits.shutdown_allowed = shutdown_allowed; }

        BOOLEAN IsShutdownAllowed() const { return m_bits.shutdown_allowed; }

        BOOLEAN IsRunning() const { return m_bits.running; }

        BOOLEAN DoesSynchronousDrawing() const { return (BOOLEAN)m_bits.synchronous_drawing; }

        Panel* GetPanel() const;

        void SetAppName(const WCHAR* app_name) { m_app_name = app_name; }
        
        const WCHAR* GetAppName() const { return m_app_name; }

        void TransferFocus();

        void GrabFocus(BOOLEAN assign_to_win);

        void SetPriority(INT priority);

        INT GetPriority() const;

        Window* GetForegroundWindow(INT display_idx = 0) const;

    protected:
        virtual BOOLEAN RouteMessage(const Message& msg);

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual BOOLEAN AcceptMsg(const Message& msg);

        virtual BOOLEAN HandleMsg(const MessageReferrer& msg_ref);

        virtual void AddTimer(Timer& timer);

        virtual void RemoveTimer(Timer& timer);

        virtual void OnStartup();

        virtual BOOLEAN OnShutdownRequest();

        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnKeyUp(KeyCode key_code, UINT32 duration);

        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);

        virtual BOOLEAN OnVeryLongKeyPress(KeyCode key_code);

        virtual BOOLEAN OnKeyAutoRepeat(KeyCode key_code);

        virtual BOOLEAN OnLockedKeyDown(KeyCode key_code);

        virtual BOOLEAN OnTimeout(const Timer& timer);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual Panel* CreatePanel() const;

        virtual void DestroyPanel(Panel* panel) const;
        
        void SetRequestedStackSize(UINT size);

#if defined(APOXI_COMPAT_2_0_0)
        virtual BOOLEAN OnInputChar(WCHAR chr);
#endif
        
    private:
        struct {
            UINT win_event              : 1;
            UINT received_key_down      : 1;
            UINT shutdown_allowed       : 1;
            UINT running                : 1;
            UINT synchronous_drawing    : 1;
            UINT has_focus              : 1;    // TRUE if Application::OnGetFocus has been invoked
        } m_bits;

        UINT                m_requested_stacksize;
        const WCHAR         *m_app_name;
        AppContainer        *m_app_container;
        Control             *m_first_control;
        AppTracer           m_app_tracer;
        mutable Panel*      m_panel;
        static Application* m_app_close_subsystems;

        virtual void DoWait(const Condition& cond);

        void ProcessWinEvents();
        void DrawControls(Control* control);
        void ProcessWinEventsFrontFirst(Window* win);
        
        void RemarkWinEvent() { m_bits.win_event = TRUE; };
        BOOLEAN HasWinEvent() { return (BOOLEAN) m_bits.win_event; };

        void SetRunning(BOOLEAN running) { m_bits.running = running; }
        void AdjustFocusOrder();
        
        BOOLEAN HandleMessage(const Message& msg);

        friend void Control::PutToForeground();                 // adjusts m_first_control (note: avoid for later releases)
        friend void Control::AbsInvalidate(Control* control,    // remarks window event (m_bits.win_event)
                                          const Rect& abs_inv_rect,
                                          BOOLEAN erase);
        friend void DeviceContext::EndUpdate();                 // adjusts m_blit_rect
        friend class AppContainer;                              // invokes HasWinEvent() for optimization in MsgLoop()
        friend void StartUp::Restart(const StartUp::Data &startup_data);    // for requesting the stacksize via StartUpConfig
};

#endif  // Apoxi_Application_hpp

