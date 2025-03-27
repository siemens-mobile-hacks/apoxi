/*  ------------------------------------------------------------------------
    Copyright (C) 2003 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Desktop_hpp)
#define Apoxi_Desktop_hpp

#include <Kernel/UserDispatcher.hpp>
#include <Kernel/Dispatcher.hpp>
#include <Gui/Window.hpp>

class GlassPane;

class Desktop : public UserDispatcher {
    typedef UserDispatcher Base;

    public:
        enum PanelAlignment {
            PanelOnLeft,
            PanelOnRight,
            PanelOnTop,
            PanelOnBottom
        };

        enum SectionType {
            LeftSection = 0,
            TopSection = 1,
            RightSection = 2,
            BottomSection = 3,
            LastSectionEntry = 4
        };

        enum SectionAlignment {
            HorizBorderAlign,
            VertBorderAlign
        };
 
        static Desktop* CreateInstance(PanelAlignment panel_align = PanelOnBottom,
                                       SectionAlignment section_align = HorizBorderAlign);

        virtual ~Desktop();

        static Desktop* GetInstance() { return m_desktop; }

        void Release();
    
        void SetPanelAlignment(PanelAlignment alignment);

        PanelAlignment GetPanelAlignment() const { return m_panel_align; }

        void SetPanelEnabled(BOOLEAN enable);

        BOOLEAN IsPanelEnabled () const { return m_panel_enabled; }

        Rect GetPanelBounds() const;

        GlassPane* GetGlassPane();
            
        Component* GetSection(SectionType section_type);

        void SetCenter(Window* win,
                       XYDIM left_gap = 0,
                       XYDIM top_gap = 0,
                       XYDIM right_gap = 0,
                       XYDIM bottom_gap = 0);

        Rect GetCenterBounds() const;
        
        Rect GetSectionContainerBounds() const;

    protected:
        virtual GlassPane* CreateGlassPane();

        virtual Component* CreateSection(SectionType section_type);

        virtual BOOLEAN OnMessage(const Message& msg);
                
        Desktop(PanelAlignment panel_align,
                SectionAlignment section_align);

    private:    
        // The SectionWindow is a container for all sections.
        class SectionWindow : public Window {
            public:
                SectionWindow();
                virtual ~SectionWindow();

            protected:
                virtual void OnLayoutClient();
        };

        void LayoutSections();
            
        PanelAlignment m_panel_align;
        SectionAlignment m_section_align;
        BOOLEAN m_panel_enabled;
        XYDIM m_left_gap;
        XYDIM m_top_gap;
        XYDIM m_right_gap;
        XYDIM m_bottom_gap;
        GlassPane* m_glass_pane;
        Component* m_section[LastSectionEntry];
        Window* m_center_win;
        SectionWindow* m_section_win;

        static Desktop* m_desktop;
};


#endif // Apoxi_Desktop_hpp


