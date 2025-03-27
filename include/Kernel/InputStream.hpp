/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined(APOXI_COMPILER_MSVC)
    #pragma message("Reference to old Kernel/InputStream.hpp. Please use " \
        "Compat/InputStream.hpp instead.")
#endif

#if defined(APOXI_COMPAT_2_0_0)
    // Kernel/InputStream.hpp moved to Compat.
    #include <Compat/InputStream.hpp>
#endif


