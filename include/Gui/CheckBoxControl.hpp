/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_CheckBoxControl_hpp)
#define Apoxi_CheckBoxControl_hpp

#include <Gui/AbstractButton.hpp>
#include <Gui/CheckBoxAction.hpp>
#include <Gui/View.hpp>

class CheckBoxControlView : public View {
    typedef View Base;

    public:
        CheckBoxControlView();
        CheckBoxControlView(XYDIM default_height);
        virtual ~CheckBoxControlView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        virtual void Update(const Theme& theme);
};

class CheckBoxControl : public AbstractButton {
    typedef AbstractButton Base;

    public:
        enum {
            ID = 6
        };

        CheckBoxControl();

        CheckBoxControl(Control* parent, const WCHAR* text, BOOLEAN selected = FALSE);

        virtual ~CheckBoxControl();

        void Init(Control* parent, const WCHAR* text, BOOLEAN selected = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void Toggle();

        void SetSelected(BOOLEAN selected) { m_checkbox_action.SetSelected(selected); }

        BOOLEAN IsSelected() const { return m_checkbox_action.IsSelected(); }

        void SetValue(INT value) { m_checkbox_action.SetValue(value); }

        INT GetValue() const { return m_checkbox_action.GetValue(); }

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void OnThemeChanged();

    private:
        CheckBoxAction m_checkbox_action;
        static CheckBoxControlView m_view;
};

#endif  // Apoxi_CheckBoxControl_hpp


