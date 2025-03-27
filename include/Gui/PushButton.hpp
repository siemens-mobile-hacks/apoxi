/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_PushButton_hpp)
#define Apoxi_PushButton_hpp

class PushButton;
#include <Gui/AbstractButton.hpp>
#include <Gui/View.hpp>

class PushButtonView : public View {
    typedef View Base;

    public:
        PushButtonView();

        PushButtonView(XYDIM default_height);
    
        virtual ~PushButtonView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

    protected:
        virtual void DrawPushButton(const PushButton& push_button, DeviceContext* dc, const Rect& repaint_rect) const = 0;
};

class PushButton : public AbstractButton {
    typedef AbstractButton Base;

    public:
        enum {
            ID = 20
        };

        PushButton();

        PushButton(Control* parent, Action* action);
        
        virtual ~PushButton();

    
        void Init(Control* parent, Action* action);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetAction(Action* action) { SetAbstractAction(action); }

        Action* GetAction() const { return GetAbstractAction(); }

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void OnThemeChanged();
};

#endif  // Apoxi_PushButton_hpp


