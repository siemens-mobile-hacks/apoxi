/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SetThemeAction_hpp)
#define Apoxi_SetThemeAction_hpp

#include <Gui/Action.hpp>
#include <Gui/Window.hpp>
#include <Kernel/MsgTypes.hpp>

class SetThemeAction : public Action {
    typedef Action Base;

    public:
        SetThemeAction();

        SetThemeAction(INT theme_id, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        virtual ~SetThemeAction();

        void Init(INT theme_id, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        virtual BOOLEAN Execute();

    private:
        INT m_theme_id;
};

#endif  // Apoxi_SetThemeAction_hpp


