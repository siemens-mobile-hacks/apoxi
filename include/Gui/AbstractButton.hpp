/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_AbstractButton_hpp)
#define Apoxi_AbstractButton_hpp

class Action;
struct BitmapRes;
#include <Gui/Control.hpp>

class AbstractButton : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 0
        };

        AbstractButton();

        AbstractButton(Control* parent, Action* action);

        virtual ~AbstractButton();

        void Init(Control* parent, Action* action);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        BOOLEAN IsPressed() const { return m_pressed; }

        void SetBitmap(const BitmapRes* bitmap);

        const BitmapRes* GetBitmap() const;

        void SetText(const WCHAR* text);

        const WCHAR* GetText() const;

        void SetEnabled(BOOLEAN enabled);

        BOOLEAN IsEnabled() const;

        void Trigger();

        void SetAction(Action* action);

        Action* GetAction() const { return m_action; }

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnClick();

        virtual void OnRelease();

        virtual void OnLanguageChanged();

        void SetAbstractAction(Action* action) { SetAction(action); };

        Action* GetAbstractAction() const { return GetAction(); }
        
    private:
        BOOLEAN m_pressed;
        Action* m_action;
};

#endif  // Apoxi_AbstractButton_hpp


