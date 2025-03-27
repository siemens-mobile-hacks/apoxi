/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Host_DataCallSignalProcessor_hpp)
#define Asc_Host_DataCallSignalProcessor_hpp

/*  ========================================================================
    DataCallSignalProcessor
    ======================================================================== */
class DataCallSignalProcessor {
    public:
        /*  ================================================================
            Circuit switched data call signal-transformation
            ================================================================ */
        static void PostIpdsSetupCnf();
        static void PostIpdsSetupRej();
        static void PostIpdsReleaseInd();
        static void PostIpdsReleaseCnf();
};

#endif  // Asc_Host_DataCallSignalProcessor_hpp

