/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_RadioButtonControl_hpp)
#define Apoxi_RadioButtonControl_hpp

#include <Gui/AbstractButton.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <Gui/View.hpp>

class RadioButtonGroup;

class RadioButtonControlView : public View {
    typedef View Base;

    public:
        RadioButtonControlView();

        RadioButtonControlView(XYDIM default_height);
    
        virtual ~RadioButtonControlView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        virtual void Update(const Theme& theme);
};

class RadioButtonControl : public AbstractButton {
    typedef AbstractButton Base;

    public:
        enum {
            ID = 21
        };

        RadioButtonControl();

        RadioButtonControl(Control* parent,
                           RadioButtonGroup* group,
                           const WCHAR* text,
                           BOOLEAN selected = FALSE);

        virtual ~RadioButtonControl();

        void Init(Control* parent,
                  RadioButtonGroup* group,
                  const WCHAR* text,
                  BOOLEAN selected = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetGroup(RadioButtonGroup* group) { m_radiobutton_action.SetGroup(group); }

        void SetSelected(BOOLEAN selected) { m_radiobutton_action.SetSelected(selected); }

        BOOLEAN IsSelected() const { return m_radiobutton_action.IsSelected(); }

        void SetValue(INT value) { m_radiobutton_action.SetValue(value); }

        INT GetValue() const { return m_radiobutton_action.GetValue(); }

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void OnThemeChanged();

    private:
        RadioButtonAction m_radiobutton_action;
        static RadioButtonControlView m_view;
};

#endif  // Apoxi_RadioButtonControl_hpp


