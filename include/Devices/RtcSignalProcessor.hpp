/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_RtcSignalProcessor_hpp)
#define Apoxi_Devices_RtcSignalProcessor_hpp


#include <Apc/SignalHandler/SignalMapTableEntry.hpp>

class RtcSignalProcessor {
    public:
        static void PostRtcEventInd(const ProcessPtr& process_ptr);
        static void PostMinuteTickInd(const ProcessPtr& process_ptr);
        static void PostRtcNotValidInd(const ProcessPtr& process_ptr);

        typedef void (*RtcEventCallbackFn)();
        static void SetRtcEventCallbackFn(RtcEventCallbackFn fn) { m_callback_fn = fn; }

    private:
        static RtcEventCallbackFn m_callback_fn;
};

#endif  // Apoxi_Devices_RtcSignalProcessor_hpp


