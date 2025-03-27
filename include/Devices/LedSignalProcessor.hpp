/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_LedSignalProcessor_hpp)
#define Apoxi_Devices_LedSignalProcessor_hpp


#include <Apc/SignalHandler/SignalMapTableEntry.hpp>

class LedSignalProcessor {
    public:
        static void PostLedStreamStatus(const ProcessPtr& process_ptr);
};

#endif  // Apoxi_Devices_LedSignalProcessor_hpp


