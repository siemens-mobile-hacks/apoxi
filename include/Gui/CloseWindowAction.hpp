/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CloseWindowAction_hpp)
#define Apoxi_CloseWindowAction_hpp

#include <Gui/Action.hpp>
#include <Gui/Window.hpp>
#include <Kernel/MsgTypes.hpp>

class CloseWindowAction : public Action {
    typedef Action Base;

    public:
        CloseWindowAction();

        CloseWindowAction(Dispatcher* dispatcher,
                          Window* win,
                          const WString& text,
                          const ImageObtainer& icon = ImageObtainer());

        virtual ~CloseWindowAction();

        void Init(Dispatcher* dispatcher,
                  Window* win,
                  const WString& text,
                  const ImageObtainer& icon = ImageObtainer());


        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual BOOLEAN Execute();

        CloseWindowAction(Window* win, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        void Init(Window* win, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);
        
        void SetWindow (Window* win) { m_win = win; }

    private:
        Window* m_win;
};

#endif  // Apoxi_CloseWindowAction_hpp


