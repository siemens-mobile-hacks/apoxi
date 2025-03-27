/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SetLanguageAction_hpp)
#define Apoxi_SetLanguageAction_hpp

#include <Gui/Action.hpp>
#include <Gui/Window.hpp>
#include <Kernel/MsgTypes.hpp>

class SetLanguageAction : public Action {
    typedef Action Base;

    public:
        SetLanguageAction();

        SetLanguageAction(INT lang_id, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        virtual ~SetLanguageAction();

        void Init(INT lang_id,  const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        virtual BOOLEAN Execute();

    private:
        INT m_lang_id;
};

#endif  // Apoxi_SetLanguageAction_hpp


