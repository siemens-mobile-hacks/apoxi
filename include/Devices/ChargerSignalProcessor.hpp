/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_ChargerSignalProcessor_hpp)
#define Apoxi_Devices_ChargerSignalProcessor_hpp


#include <Apc/SignalHandler/SignalMapTableEntry.hpp>

class ChargerSignalProcessor {
    public:
        static void PostStopChargingBatteryInd(const ProcessPtr &process_ptr);
        static void PostChargingBatteryInd(const ProcessPtr &process_ptr);
        static void PostChargingPausedInd(const ProcessPtr &process_ptr);
        static void PostChargingResumedInd(const ProcessPtr &process_ptr);
        static void PostLowBatteryInd(const ProcessPtr &process_ptr);
        static void PostEmptyBatteryInd(const ProcessPtr &process_ptr);
        static void PostRemoveChargerInd(const ProcessPtr &process_ptr);
        static void PostBatteryLoadLevelInd(const ProcessPtr &process_ptr);
};

#endif  // Apoxi_Devices_ChargerSignalProcessor_hpp


