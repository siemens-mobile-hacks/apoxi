/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ProgressBar_hpp)
#define Apoxi_ProgressBar_hpp

#include <Gui/Model.hpp>
#include <Gui/View.hpp>
#include <Gui/Rect.hpp>
#include <Gui/DrawableObject.hpp>

class ProgressBar : public DrawableObject {
    public:
        enum {
            ID = 19
        };

        typedef DrawableObject Base;
    
        ProgressBar();

        ProgressBar(Control* control, INT progress = 0);

        virtual ~ProgressBar();

        void Init(Control* control, INT progress = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetProgress(INT progress);

        INT GetProgress() const { return m_progress; }

    protected:
        virtual void OnThemeChanged();

    private:
        INT m_progress;
};

class ProgressBarView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        ProgressBarView();
        ProgressBarView(XYDIM default_height);

        virtual ~ProgressBarView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

    protected:
        virtual void DrawProgressBar(const ProgressBar& progress_bar, DeviceContext* dc, const Rect& repaint_rect) const = 0;
};

#endif  // Apoxi_ProgressBar_hpp


