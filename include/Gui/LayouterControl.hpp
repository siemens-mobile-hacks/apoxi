/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#pragma message("The class LayouterControl has been renamed to GridLayout. Please use " \
    "Gui/GridLayout.hpp instead.")

#if defined(APOXI_COMPAT_2_4_0)
    #include <Gui/GridLayout.hpp>
#else
    #error Gui/LayouterControl has been renamed to Gui/GridLayout. Nevertheless, to use it from here define APOXI_COMPAT_2_4_0.
#endif

