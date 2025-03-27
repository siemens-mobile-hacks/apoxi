/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#pragma message("Reference to old Adc/RootFileImp.hpp. Please use " \
    "AddOns/AfsRfs/RootFileImp.hpp instead.")

#if defined(APOXI_COMPAT_2_2_0)
    #include <AddOns/AfsRfs/RootFileImp.hpp>
#else
    #error Adc/RootFileImp.hpp was moved to AddOns/AfsRfs. Nevertheless, to use it from here define APOXI_COMPAT_2_2_0.
#endif


