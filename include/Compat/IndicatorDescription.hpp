/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_Indicator_Description_hpp)
#define Atl_Gui_Indicator_Description_hpp

#include <Kernel/Types.hpp>

#include <Gui/Point.hpp>
#include <Atl/Gui/IndicatorID.hpp>
#include <Atl/Gui/IndicatorBarID.hpp>


class IndicatorLocation {
    public:
        enum Alignment {
            Start = 0,  // order must not be changed
            Middle = 1,
            End = 2
        };

        IndicatorLocation();

        IndicatorLocation(const IndicatorBarID& barId, Alignment align, INT pos);
            
        IndicatorLocation(const Point& glass_pane_pos);

        ~IndicatorLocation();

        void SetIndicatorBarId(const IndicatorBarID& barId) { m_bar_id = barId; }

        const IndicatorBarID& GetIndicatorBarId() const { return m_bar_id; }
        
        void SetAlignment(Alignment align) { m_align = align; }

        Alignment GetAlignment() const { return m_align; }

        void SetIndicatorBarPosition(INT pos) { m_pos = pos; }

        INT GetIndicatorBarPosition() const { return m_pos; }

        void SetGlassPanePosition(const Point& pos) { m_glass_pane_pos = pos; }

        const Point& GetGlassPanePosition() const   { return m_glass_pane_pos; }

        BOOLEAN DisplayOnGlassPane() const { return m_display_on_glasspane; }

        private:
            Alignment       m_align;
            INT             m_pos;
            IndicatorBarID  m_bar_id;
            Point           m_glass_pane_pos;
            BOOLEAN         m_display_on_glasspane;
};


class IndicatorDescription {
public:
        IndicatorDescription();

        IndicatorDescription(const IndicatorID& id, const IndicatorLocation& pos);

        ~IndicatorDescription();

        void Init(const IndicatorID& id, const IndicatorLocation& pos);

        void SetIndicatorLocation(const IndicatorLocation& pos) { m_pos = pos; }

        const IndicatorLocation& GetIndicatorLocation() const   { return m_pos; }
        
        void SetIndicatorId(const IndicatorID& id) { m_id = id; }

        const IndicatorID& GetIndicatorId() const { return m_id; }

        private:
            IndicatorID         m_id;
            IndicatorLocation   m_pos;

};

#endif  // Atl_Gui_Indicator_Description_hpp

