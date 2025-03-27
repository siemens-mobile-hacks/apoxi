/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#pragma message("Reference to old Adc/MimeTypeTable.hpp. Please use " \
    "Auxiliary/MimeTypeTable.hpp and/or Adc/FfsMimeTypeMap.hpp instead.")

#if defined(APOXI_COMPAT_1_13_0)
    // Adc/MimeTypeTable.hpp moved to Auxiliary and the FFS related methods 
    // moved to new file Adc/FfsMimeTypeMap.hpp.
    #include <Auxiliary/MimeTypeTable.hpp>
#else
    #error Adc/MimeTypeTable.hpp is out of date. Nevertheless, to use it define APOXI_COMPAT_1_13_0.
#endif


