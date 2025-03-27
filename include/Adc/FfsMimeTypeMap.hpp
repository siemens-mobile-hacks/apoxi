/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if defined(APOXI_COMPILER_MSVC)
#pragma message("Reference to old Adc/FfsMimeTypeMap.hpp. Please use " \
    "Afs/Ffs/FfsMimeTypeMap.hpp instead.")
#endif

#if defined(APOXI_COMPAT_2_2_0)
    #include <Afs/Ffs/FfsMimeTypeMap.hpp>
#else
    #error Adc/FfsMimeTypeMap.hpp was moved to Afs/Ffs. Nevertheless, to use it from here define APOXI_COMPAT_2_2_0.
#endif


