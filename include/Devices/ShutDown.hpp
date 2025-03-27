/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ShutDown_hpp)
#define Apoxi_ShutDown_hpp

#include <Kernel/Os/SystemTimer.hpp>

class ShutDown {
    public:
        enum Mode {
            PowerOff,           
            Restart,            
            SilentReset,        
            FirmwareUpdate      
        };
        
        static void Execute(Mode mode = PowerOff);

        static void PowerDown(BOOLEAN restart = FALSE);

    private:
        static BOOLEAN m_mobile_network_stopped;
        static Mode m_mode;
        static SystemTimer m_timer;
        static UINT32 m_timeout;

        friend class CommonSignalProcessor;

        static void OnTimer(void* arg);
        static void OnMobileNetworkStopped();
};

#endif


