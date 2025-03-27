/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ConfirmAction_hpp)
#define Apoxi_ConfirmAction_hpp

#include <Gui/Action.hpp>
#include <Gui/Control.hpp>
#include <Gui/MsgTypes.hpp>

class ConfirmAction : public Action {
    typedef Action Base;

    public:
        ConfirmAction();

        ConfirmAction(Control* control, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        virtual ~ConfirmAction();

        void Init(Control* control, const WCHAR* text = 0, const BitmapRes* bitmap = 0, BOOLEAN enabled = TRUE);

        virtual BOOLEAN Execute();
};

#endif  // Apoxi_ConfirmAction_hpp


