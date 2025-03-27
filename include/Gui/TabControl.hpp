/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TabControl_hpp)
#define Apoxi_TabControl_hpp

#if !defined(APOXI_DISABLE_TAB_CONTROL)

class Layouter;
class TabButton;
class TabControl;
class Control;
class WString;
class ImageObtainer;
struct BitmapRes;
#include <Kernel/Types.hpp>
#include <Gui/View.hpp>
#include <Gui/Control.hpp>
#include <Auxiliary/Vector.hpp>

class TabControlView : public View {
    typedef View Base;

    public:
        TabControlView(XYDIM border_size, XYDIM header_height = 0);
    
        virtual ~TabControlView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        XYDIM GetBorderSize() const { return m_border_size; }

        XYDIM GetHeaderHeight() const { return m_header_height; }

        virtual void Update(const Theme& theme);

    protected:
        virtual void DrawTabControl(const TabControl& tab_control,
                                    DeviceContext* dc,
                                    const Rect& repaint_rect) const = 0;

    private:
        XYDIM m_border_size;
        XYDIM m_header_height;
};

class TabControl : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 23
        };

        TabControl();

        TabControl(Control* parent);
        
        virtual ~TabControl();

        void Init(Control* parent);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        INT AddTab(Control* page, const WString& text, const BitmapRes* icon = 0);

        INT AddTab(Control* page, const WString& text, const ImageObtainer& icon);

        INT InsertTab(INT index, Control* page, const WString& text, const BitmapRes* icon = 0);

        INT InsertTab(INT index, Control* page, const WString& text, const ImageObtainer& icon);

        void RemoveTab(INT index);

        void SetActiveTab(INT index);

        INT GetActiveTab() const { return m_active_tab; }

        void SetTabEnabled(INT index, BOOLEAN enabled);

        BOOLEAN IsTabEnabled(INT index) const;

        void SetHeaderEnabled(BOOLEAN enabled);

        BOOLEAN IsHeaderEnabled() const { return m_header_enabled; }

        INT GetTabCount() const { return m_tab_vector.GetSize(); }

        Control* GetPage(INT index) const;

        const WString& GetText(INT index) const;

        const ImageObtainer& GetIcon(INT index) const;
        
    protected:
        virtual void OnActiveTabChanged(INT old_tab_index);

        virtual void Refresh(const Rect& rect);

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnThemeChanged();

        virtual void OnLayoutClient();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnFocusNextControl();

        virtual void OnFocusPreviousControl();
        
        virtual void OnLanguageChanged();

    private:
        class Tab {
            public:
                Tab() : m_button(0), m_page(0) {}               
                Tab(TabButton* button, Control* page) : m_button(button), m_page(page) {}
                TabButton* GetButton() const { return m_button; }
                Control* GetPage() const { return m_page; }

            private:
                TabButton* m_button;
                Control* m_page;
        };

        BOOLEAN m_header_enabled;
        INT m_active_tab;
        INT m_first_visible_tab;
        Vector<Tab> m_tab_vector;

        void InitProperties();
        void UpdatePositionHints() const;
        BOOLEAN AssureValidIndex(INT& index) const;
        void UpdateNavigationGuidance();

        void ActivateEnabledTab(BOOLEAN next);

        void AdjustFirstVisibleTab();

        void LayoutTabButtons();

        XYDIM GetTabButtonWidth() const;

        XYDIM GetTabButtonHeight() const;
};

#endif // APOXI_DISABLE_TAB_CONTROL

#endif  // Apoxi_TabControl_hpp

