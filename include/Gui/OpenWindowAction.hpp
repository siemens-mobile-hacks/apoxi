/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_OpenWindowAction_hpp)
#define Apoxi_OpenWindowAction_hpp

#include <Gui/Action.hpp>
#include <Gui/Window.hpp>
#include <Kernel/MsgTypes.hpp>

class OpenWindowAction : public Action {
    typedef Action Base;

    public:
        OpenWindowAction();

        OpenWindowAction(Dispatcher* dispatcher,
                         Window* win,
                         const WString& text,
                         const ImageObtainer& icon = ImageObtainer(),
                         BOOLEAN modal = FALSE);

        virtual ~OpenWindowAction();

        void Init(Dispatcher* dispatcher,
                  Window* win,
                  const WString& text,
                  const ImageObtainer& icon = ImageObtainer(),
                  BOOLEAN modal = FALSE);
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual BOOLEAN Execute();

        OpenWindowAction(Window* win, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        OpenWindowAction(Window* win, BOOLEAN modal, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        void Init(Window* win, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        void Init(Window* win, BOOLEAN modal,  const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        void SetWindow(Window* win) { m_win = win; }

    private:
        BOOLEAN m_modal;
        Window* m_win;
};

#endif  // Apoxi_OpenWindowAction_hpp


