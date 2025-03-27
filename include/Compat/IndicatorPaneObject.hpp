/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_IndicatorPaneObject_hpp)
#define Atl_Gui_IndicatorPaneObject_hpp

#include <Kernel/Types.hpp>
#include <Gui/PaintDc.hpp>
#include <Gui/GlassPane.hpp>
#include <Atl/Gui/Indicator.hpp>
#include <Atl/Gui/IndicatorBar.hpp>

class IndicatorPaneObject : public Observer, 
                            public PaneObject {

    typedef PaneObject Base;

    public:

        IndicatorPaneObject();

        virtual ~IndicatorPaneObject();

        void Init(Indicator* indicator, const Rect& bounding_rect = Rect());

        virtual void OnUpdate (ObservableObject *obs_obj);

        virtual void Draw(DeviceContext* dc);

    private:

        Indicator* m_indicator;
        
};


class IndicatorBarPaneObject : public PaneObject {
    
    typedef PaneObject Base;

    public:

        IndicatorBarPaneObject();

        virtual ~IndicatorBarPaneObject();

        void Init(IndicatorBar* indicator_bar, const Rect& bounding_rect = Rect());

        virtual void Draw(DeviceContext* dc);

    private:

        IndicatorBar* m_indicator_bar;              

};
#endif  // Atl_Gui_IndicatorPaneObject_hpp


