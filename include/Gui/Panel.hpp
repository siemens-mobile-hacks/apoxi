/*  ------------------------------------------------------------------------
    Copyright (C) 2003 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Panel_hpp)
#define Apoxi_Panel_hpp

#include <Gui/View.hpp>
#include <Gui/Window.hpp>

class Panel;

class PanelView : public View {
    typedef View Base;

    public:
        PanelView();

        PanelView(XYDIM default_height);
    
        virtual ~PanelView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;
        
    protected:
        virtual void DrawPanel(const Panel& panel, DeviceContext* dc, const Rect& repaint_rect) const = 0;
};

class Panel : public Window {
    typedef Window Base;

    public:
        enum {
            ID = 17
        };

        Panel();

        virtual ~Panel();

        XYDIM GetComponentsSize() const;
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetOwner(Window* owner) { m_owner = owner; }

        const Window* GetOwner() const { return m_owner; }
        
    protected:
        virtual void OnThemeChanged();
        
        virtual void OnLayoutClient();

    private:
        const Window* m_owner;
        
        void AlignOnDesktop();

        void AdjustPosition(Component& comp, XYDIM& x);
};

#endif // Apoxi_Panel_hpp


