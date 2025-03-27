/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_MenuWindow_hpp)
#define Apoxi_MenuWindow_hpp

#include <Gui/Window.hpp>

class AbstractMenuList;

class MenuWindow : public Window {
    typedef Window Base;

    public:
        MenuWindow();

        virtual ~MenuWindow();

    protected:
        virtual BOOLEAN OnCancel();
};


#endif  // Apoxi_MenuWindow_hpp


