/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CalendarGrid_hpp)
#define Apoxi_CalendarGrid_hpp

#include <Gui/View.hpp>
#include <Gui/AbstractGrid.hpp>
#include <Kernel/Os/Os.hpp>

#include <Auxiliary/Date.hpp>

#define no_rows 7
#define no_cols 8

class CalendarGrid;

class CalendarGridView : public View {
    typedef View Base;

    public:
        CalendarGridView();

        virtual ~CalendarGridView();
        
        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;       
    
};


class AbstractMenuAccessor;

class CalendarGrid : public AbstractGrid {
    typedef AbstractGrid Base;

    public:
        
        CalendarGrid();

        virtual ~CalendarGrid();
        

        void Init(Control* parent);

        virtual INT GetCellCount() const {return no_cols*no_rows;}

        virtual INT GetColumnCount() const {return no_cols;}

        virtual XYDIM GetCellWidth() const;

        virtual XYDIM GetCellHeight() const;

        BOOLEAN OnInputMap(const InputMapItem& input_map_item);
        
        Date GetCurrentSelectedDay(){return m_current_selected_day;}

        void SetCurrentSelectedDay(Date date){m_current_selected_day = date;}

        void Invalidate(const Rect& rect = Rect(), BOOLEAN erase = TRUE);

    protected:
        void OnGetFocus();

        BOOLEAN OnKeyDown(KeyCode key_code);

    private:
        INT                         m_item_count;
        Date                        m_current_selected_day;
        static CalendarGridView     m_month_view;
        XYDIM                       m_grid_height;
        XYDIM                       m_grid_width;
};

#endif  // Apoxi_CalendarGrid_hpp
