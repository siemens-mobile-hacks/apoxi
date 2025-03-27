/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Menu_hpp)
#define Apoxi_Menu_hpp

#include <Gui/View.hpp>
#include <Gui/AbstractGrid.hpp>
#include <Kernel/Os/Os.hpp>

class MenuView : public View {
    typedef View Base;

    public:
        MenuView();
        virtual ~MenuView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        BOOLEAN IsBackgrDrawingEnabled() const { return m_backgr_drawing; } 

    private:
        mutable BOOLEAN m_backgr_drawing;
};


class AbstractMenuAccessor;

class Menu : public AbstractGrid {
    typedef AbstractGrid Base;

    public:
        Menu();
        virtual ~Menu();
        
        void Init(Control* parent, AbstractMenuAccessor* menu_accessor);

        AbstractMenuAccessor* GetMenuAccessor() const { return m_menu_accessor; }   //lint !e1763

        virtual void ChangeMenuAccessor(AbstractMenuAccessor* accessor, BOOLEAN is_sub_accessor = FALSE);

        virtual INT GetCellCount() const;

        virtual INT GetColumnCount() const;

        virtual XYDIM GetCellWidth() const;

        virtual XYDIM GetCellHeight() const;
        
        virtual void Trigger(INT index = -1);

        virtual void Back();

        void UpdateItemCount();

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnLanguageChanged();

        virtual void OnSelectionChanged();
        
        virtual void OnTrigger();

        virtual void OnBack();
        
    private:
        INT m_item_count;
        AbstractMenuAccessor* m_menu_accessor;
        
        static MenuView m_menu_view;
};

#endif  // Apoxi_Menu_hpp


