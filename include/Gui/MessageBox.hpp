/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageBox_hpp)
#define Apoxi_MessageBox_hpp

#include <Gui/Window.hpp>
#include <Gui/MultiLineEditor.hpp>
#include <Gui/Action.hpp>

#ifdef APOXI_COMPAT_1_9_0
    #include <Gui/SoftkeyBar.hpp>
#endif

class MessageBox : public Window {
    typedef Window Base;

    public:
        enum {
            ID = 16
        };

        enum Type {
            Ok,
            OkCancel,
            YesNo
        };

        enum ReturnId {
            OkId,
            CancelId,
            YesId,
            NoId
        };

        MessageBox();

        MessageBox(Type type, const WCHAR* title = 0, const WCHAR* message = 0);

        virtual ~MessageBox();

        void Init(Type type, const WCHAR* title = 0, const WCHAR* message = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual INT Open(const WCHAR* title = 0, const WCHAR* message = 0);

    protected:
        virtual void OnActionExecuted(Action* action);

        virtual void OnLayoutClient();

    private:
        Type m_type;
        Action m_confirm_action;
        Action m_cancel_action;
        MultiLineEditor m_msg_container;
#ifdef APOXI_COMPAT_1_9_0
        SoftkeyBar m_softkey_bar;
#endif
        void InitProperties(MessageBox::Type type, const WCHAR* title, const WCHAR* message);
};

#endif  // Apoxi_MessageBox_hpp


