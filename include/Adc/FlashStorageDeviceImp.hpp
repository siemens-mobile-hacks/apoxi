/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#pragma message("Reference to old Adc/FlashStorageDeviceImp.hpp. Please use " \
    "AddOns/AfsFfs/FlashStorageDeviceImp.hpp instead.")

#if defined(APOXI_COMPAT_2_2_0)
    #include <AddOns/AfsFfs/FlashStorageDeviceImp.hpp>
#else
    #error Adc/FlashStorageDeviceImp.hpp was moved to AddOns/AfsFfs. Nevertheless, to use it from here define APOXI_COMPAT_2_2_0.
#endif


