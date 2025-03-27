/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Control_hpp)
#define Apoxi_Control_hpp

#include <Gui/Component.hpp>
#include <Kernel/MsgCategory.hpp>

class Timer;
class Rect;
class Point;
class Size;
class ControlFrameView;
class Window;
class DrawableObject;
class ClientDc;
class Message;
class InputMapItem;
class ResourceParser;

class Control : public Component {
    typedef Component Base;

    public:
        enum {
            ID = 9
        };

        enum FrameType {
            NoFrame,
            DefaultFrame,
            StaticFrame,
            DynamicFrame
        };  // when extending the enum, the bit-size for m_bits.frame_type must be adjusted

        class NavigationGuidance {
            public:
                enum Type {
                    Left    = 0,
                    Right   = 2,
                    Up      = 4,
                    Down    = 6,
                    Center  = 8
                };

                enum State {
                    Off         = 0,
                    Disabled    = 1,
                    Enabled     = 2
                };

                NavigationGuidance();
                NavigationGuidance(State left_state,
                                   State right_state = Off,
                                   State up_state = Off,
                                   State down_state = Off,
                                   State center_state = Off);
                ~NavigationGuidance();

                void SetState(Type type, State state);

                State GetState(Type type) const;

                void Merge(NavigationGuidance nav_guid);
                
                BOOLEAN operator == (NavigationGuidance nav_guid) const { return nav_guid.m_value == m_value; }
                BOOLEAN operator != (NavigationGuidance nav_guid) const { return nav_guid.m_value != m_value; }

            private:
                UINT16 m_value;
        };

        class ComponentIterator {
            public:
                enum Type {
                    All,
                    Controls,
                    DrawableObjects
                };
                
                ComponentIterator(const Control& control, Type type = All);

                ~ComponentIterator();

                BOOLEAN Begin();

                ComponentIterator& operator++();

                ComponentIterator operator++(INT);

                BOOLEAN Next();

                Component* Get() const { return m_comp; }

            private:
                Type m_type;
                BOOLEAN m_iterate_controls;
                const Control& m_control;
                Component* m_comp;
        };
        
        Control(Control* parent = 0, const View* view = 0);
        
        /*  Constructor used by Aragon to create the instance out of a resource file.
            This constructor may not be used by the MMI in a direct manner
            and the interface may be changed in future releases. */
        virtual ~Control();

        void Init(Control* parent = 0, const View* view = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void SetParent(Control* parent);

        Application* GetApplication() const;

        void SetFrameType(FrameType frame_type) { m_bits.frame_type = frame_type; }

        FrameType GetFrameType() const { return (FrameType)m_bits.frame_type; }

        void SetNavigationGuidance(NavigationGuidance navigation_guidance);
        
        NavigationGuidance GetNavigationGuidance() const { return m_navigation_guidance; }

        BOOLEAN IsParentWindowOpen() const;

        BOOLEAN HasFocus() const { return m_bits.focused; }

        BOOLEAN IsInForeground() const;

        void PutToForeground();

        virtual void Maximize();

        BOOLEAN IsMaximized() const { return m_bits.maximized; }

        void Invalidate();

        void Invalidate(const Rect& rect, BOOLEAN erase = TRUE);


        void InvalidateClient();

        void InvalidateClient(const Rect& rect, BOOLEAN erase = TRUE);

        XYDIM GetClientXPos() const;

        XYDIM GetClientYPos() const;

        XYDIM GetClientWidth() const;

        XYDIM GetClientHeight() const;

        Size GetClientSize() const;

        virtual Rect GetClientRect() const;

        Window* GetParentWindow() const;

        void SetNext(Control* next) { m_next = next; }

        Control* GetNext() const { return m_next; }

        Control* GetNext(const Control* control) const;

        Control* GetPrevious(Control* control) const;
        
        void AddDrawableObject(DrawableObject* drawable_object, BOOLEAN at_end = TRUE);

        void RemoveDrawableObject(DrawableObject* drawable_object);

        BOOLEAN ContainsDrawableObject(const DrawableObject* obj) const;

        DrawableObject* GetFirstDrawableObject() const { return m_first_drawable_object; }

        void AddControl(Control* control, BOOLEAN at_end = TRUE);

        void RemoveControl(Control* control);

        BOOLEAN ContainsControl(const Control* control) const;

        Control* GetFirstControl() const { return m_first_control; }

        Control* GetFocusedControl() const;

        Control* GetLastFocusedControl() const { return m_last_focused_control; }
        
        Component* GetComponent(INT id) const;

        BOOLEAN GrabFocus();

        void SetDisabled(BOOLEAN disabled);

        BOOLEAN IsDisabled() const { return (BOOLEAN)m_bits.disabled; }

        void LayoutClient();

        void SetAutoClearEnabled(BOOLEAN enabled);

        BOOLEAN IsAutoClearEnabled() const { return (BOOLEAN)m_bits.auto_clear_enabled; }

        void SetAutoLayoutEnabled(BOOLEAN enabled) { m_bits.auto_layout_enabled = enabled; }

        BOOLEAN IsAutoLayoutEnabled() const { return (BOOLEAN)m_bits.auto_layout_enabled; }

        void Draw();

        virtual void DrawLayer();

        const Rect& GetRepaintRect() const { return m_repaint_rect; }

        BOOLEAN SetDisplayIndex(INT index);

        INT GetDisplayIndex() const { return (INT)m_bits.display_idx; }

        ClientDc* GetDeviceContext();

        const ClientDc* GetDeviceContext() const;

        XYDIM GetAbsXPos() const;

        XYDIM GetAbsYPos() const;

        Rect GetAbsRect() const;

        XYDIM GetAbsClientXPos() const;

        XYDIM GetAbsClientYPos() const;

        Rect GetAbsClientRect() const;

        BOOLEAN IsChild() const { return GetParent() != 0; }

        INT GetLanguageId() const { return static_cast<INT>(m_language_id); }
        
#if defined(APOXI_COMPAT_1_11_0)        

        void SetAutoLayout(BOOLEAN auto_layout);

        BOOLEAN IsAutoLayout() const { return FALSE; }
#endif

#if defined(APOXI_COMPAT_2_0_0)

        BOOLEAN IsWindowInstance() const;
#endif // APOXI_COMPAT_2_0_0
        
        BOOLEAN IsOpen() const;

        Control* GetForegroundControl() const;


    protected:
        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

        virtual BOOLEAN RouteMessage(const Message& msg);
    
        virtual void OnMove(XYDIM dx, XYDIM dy);

        virtual void OnResize(XYDIM dx, XYDIM dy);

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual void OnPaint(const Rect& repaint_rect);

        virtual void OnLayoutClient();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnKeyUp(KeyCode key_code, UINT32 duration);

        virtual BOOLEAN OnKeyAutoRepeat(KeyCode key_code);

        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);

        virtual BOOLEAN OnTimeout(const Timer& timer);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnFocusNextControl();

        virtual void OnFocusPreviousControl();

        void SetLastFocusedControl(Control* control) { m_last_focused_control = control; }

        virtual const ControlFrameView* GetFrameView() const;

        void OptimizeAutoClear();

        void SetInternalDisplayIndex(INT index) { m_bits.display_idx = index; }

        MsgId GetTriggeredMessage(InputMapId map_id, const InputMapItem& input_map_item) const;

        INT GetInternalDisplayIndex() const { return (INT)m_bits.display_idx; }
        
        void SetLastFocusedChild(Control* control) { SetLastFocusedControl(control); }

        Control* GetLastFocusedChild() const { return GetLastFocusedControl(); }

        // Obsolete - provided for backward compatibility with older APOXI releases. 
        virtual BOOLEAN OnInputMap(const InputMapItem& input_map_item);

#if defined(APOXI_COMPAT_1_8_0)     

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();
        
        virtual BOOLEAN OnSoftkeyPressed(INT idx);
#endif // APOXI_COMPAT_1_8_0
        
#if defined(APOXI_COMPAT_1_12_0)

        virtual BOOLEAN OnSoftkeyReleased(INT idx);
#endif // APOXI_COMPAT_1_12_0

#if defined(APOXI_COMPAT_2_0_0)

        virtual BOOLEAN OnInputChar(WCHAR chr);
#endif // APOXI_COMPAT_2_0_0
        
    private:
        struct {
            UINT clear               : 1;
            UINT maximized           : 1;
            UINT focused             : 1;
            UINT received_key_down   : 1;
            UINT disabled            : 1;
            UINT auto_clear_enabled  : 1;
            UINT optimize_auto_clear : 1;
            UINT internal_redraw     : 2;
            UINT frame_type          : 2;
            UINT display_idx         : 1;
            UINT auto_layout_enabled : 1;
        } m_bits;

        UINT8 m_language_id;
        Control* m_last_focused_control;
        Control* m_next;
        Control* m_first_control;
        DrawableObject* m_first_drawable_object;

        Rect m_repaint_rect;
        NavigationGuidance m_navigation_guidance;

        void InitProperties(Control* parent);

        BOOLEAN IsRepaintInsideClient() const;

        Rect OptimizeInvArea(const Control& control, const Rect& abs_inv_rect) const;

        void AbsInvalidate(Control* control, const Rect& abs_inv_rect, BOOLEAN erase);

        void AbsInvalidateBackground(const Control* control,
                                     const Rect& abs_inv_rect,
                                     BOOLEAN is_next = FALSE);

        void DrawFrame();
        BOOLEAN HasChildren() { return m_first_control != 0; }
        void BroadcastMsgToDrawableObjects(const Message& msg);
        BOOLEAN HandleMessage(const Message& msg);
        
        void UpdateNavigationGuidance();

        void ShowNavigationGuidance();
        

        friend class Application;   // Application::RouteMessage() accesses Control::RouteMessage()
        friend class Window;        // Window::Close() accesses Control::AbsInvalidate()

#if defined(APOXI_COMPAT_1_8_0)     
        friend class Animation;
#endif
};

typedef Control::FrameType FrameType;

#endif  // Apoxi_Control_hpp

