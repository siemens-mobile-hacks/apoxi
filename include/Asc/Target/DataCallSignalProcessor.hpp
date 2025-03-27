/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Target_DataCallSignalProcessor_hpp)
#define Asc_Target_DataCallSignalProcessor_hpp

#include <Apc/SignalHandler/ProcessNode.hpp>

/*  ========================================================================
    DataCallSignalProcessor
    ======================================================================== */
class DataCallSignalProcessor {
    public:
        /*  ================================================================
            Circuit switched data call signal-transformation
            ================================================================ */
        static void PostIpdsSetupCnf(const ProcessPtr &process_ptr);
        static void PostIpdsSetupRej(const ProcessPtr &process_ptr);
        static void PostIpdsReleaseInd(const ProcessPtr &process_ptr);
        static void PostIpdsReleaseCnf(const ProcessPtr &process_ptr);
};

#endif  // Asc_Target_DataCallSignalProcessor_hpp

