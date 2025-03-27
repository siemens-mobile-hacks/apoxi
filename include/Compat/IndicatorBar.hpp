/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_IndicatorBar_hpp)
#define Mmi_IndicatorBar_hpp

#include <Gui/DrawableObject.hpp>
#include <Gui/Desktop.hpp>
#include <Auxiliary/Vector.hpp>
#include <Atl/Gui/Indicator.hpp>
#include <Auxiliary/Observer.hpp>

#include "IndicatorBarID.hpp"

class IndicatorBarView : public View {

    typedef View Base;

public:
    IndicatorBarView();
    virtual ~IndicatorBarView();

    virtual void Draw(const Component &component, 
        DeviceContext *dc, 
        const Rect &repaint_rect) const;

    enum IndicatorBarOrientation {
        horizontal = 0,
        vertical = 1
    };

private:
};

class IndicatorBar : public Control, public Observer {
    typedef Control Base;

    public:
        IndicatorBar();

        virtual ~IndicatorBar();

        void Init(const IndicatorBarID& id, Control *control, Desktop::SectionType section, BOOLEAN auto_draw = TRUE);
        
        void AddIndicator(Indicator* indicator);

        void RemoveIndicator(Indicator* indicator);

        void RemoveAllIndicators();

        virtual DrawableObjectView* GetView() const;

        XYDIM GetIndicatorbarExpansion();

        void SetIndicatorbarExpansion(XYDIM indicatorbar_expansion);

        IndicatorBarView::IndicatorBarOrientation GetOrientation();

        // Used for temporary workaround, should be removed when parent-switching works in APOXI
/*      void AddToControl(Control* parent);
        void RemoveFromControl(Control* parent);*/

        const IndicatorBarID &GetId() { return m_indicator_bar_id; };

        Desktop::SectionType GetSection() const { return m_section; };
        
        BOOLEAN IsEmpty() const { return m_indicators.IsEmpty(); };

    protected:
        virtual void OnUpdate(ObservableObject *obs_obj);
        virtual BOOLEAN OnMessage(const Message &msg);

    private:
        friend class IndicatorBarView;
        Vector<Indicator*> m_indicators;

        IndicatorBarID     m_indicator_bar_id;
        Desktop::SectionType    m_section;
        IndicatorBarView::IndicatorBarOrientation m_orientation;
};


#endif  // Mmi_IndicatorBar_hpp


