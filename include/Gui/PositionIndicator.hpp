/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PositionIndicator_hpp)
#define Apoxi_PositionIndicator_hpp

#include <Gui/Model.hpp>
#include <Gui/View.hpp>
#include <Gui/Rect.hpp>
#include <Gui/DrawableObject.hpp>

class PositionIndicator : public DrawableObject {
    typedef DrawableObject Base;

    public:
        enum {
            ID = 18
        };

        enum Orientation {
            Horizontal,
            Vertical
        };

        PositionIndicator();

        PositionIndicator(Control* control,
                          Orientation orientation,
                          INT min_value, 
                          INT max_value,
                          INT visible_values_count = -1,
                          INT value = -1,
                          BOOLEAN auto_draw = TRUE);

        virtual ~PositionIndicator();

        void Init(Control* control,
                  Orientation orientation,
                  INT min_value, 
                  INT max_value,
                  INT visible_values_count = -1,
                  INT value = -1,
                  BOOLEAN auto_draw = TRUE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetOrientation(Orientation orientation);

        Orientation GetOrientation() const { return m_orientation; }

        void SetMinValue(INT min_value);

        INT GetMinValue() const { return m_min_value; }

        void SetMaxValue(INT max_value);

        INT GetMaxValue() const { return m_max_value; }

        void SetRange(INT min_value, INT max_value);

        void SetVisibleValuesCount(INT visible_values_count);

        INT GetVisibleValuesCount() const { return m_visible_values_count; }

        void SetValue(INT value);

        INT GetValue() const { return m_value; }

        BOOLEAN IsFullsized() const;

    protected:
        virtual void OnThemeChanged();

    private:
        INT m_min_value;
        INT m_max_value;
        INT m_visible_values_count;
        INT m_value;
        Orientation m_orientation;

        void AssureConsistence();
};

class PositionIndicatorView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        PositionIndicatorView();
        PositionIndicatorView(XYDIM size);

        virtual ~PositionIndicatorView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        void SetSize(XYDIM size) { m_size = size; }

        XYDIM GetSize() const { return m_size; }

    protected:
        virtual void DrawPositionIndicator(const PositionIndicator& pos_ind, DeviceContext* dc, const Rect& repaint_rect) const = 0;

    private:
        XYDIM m_size;
};

#endif  // Apoxi_PositionIndicator_hpp


