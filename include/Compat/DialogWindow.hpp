/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DialogWindow_hpp)
#define Apoxi_DialogWindow_hpp

#include <Gui/Window.hpp>

class DialogWindow : public Window {
    typedef Window Base;

    public:
        enum ReturnId {
            ConfirmId,
            CancelId,
        };

        virtual ~DialogWindow();

    protected:
        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();
};

#endif  // Apoxi_DialogWindow_hpp


