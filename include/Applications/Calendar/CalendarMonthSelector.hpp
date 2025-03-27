/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(CalendarMonthSelector_hpp)
#define CalendarMonthSelector_hpp

#include "CalendarGrid.hpp"


#include <Gui/View.hpp>
#include <Gui/AbstractGrid.hpp>
#include <Kernel/Os/Os.hpp>

#include <Auxiliary/Date.hpp>

class CalendarMonthSelector;


class CalendarMonthSelectorView : public View {
    typedef View Base;

    public:
        CalendarMonthSelectorView();

        virtual ~CalendarMonthSelectorView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;
};
    
class CalendarMonthSelector : public AbstractGrid {
    typedef AbstractGrid Base;

    public:
        CalendarMonthSelector();

        virtual ~CalendarMonthSelector();

        void Init(Control* parent);

        virtual INT GetCellCount() const {return 1;}

        virtual INT GetColumnCount() const {return 1;}

        virtual XYDIM GetCellHeight() const {return 16;}

        BOOLEAN OnInputMap(const InputMapItem& input_map_item);

    private:
        BOOLEAN OnKeyDown(KeyCode key_code);
            
        
        static CalendarMonthSelectorView m_view;
        TextLine            m_text_line;
};

#endif 

