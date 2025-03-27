/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SubSystemManager_hpp)
#define Apoxi_SubSystemManager_hpp

#include <Kernel/Types.hpp>

class SubSystem;

class SubSystemManager {
    public:
        enum BootSequenceState {
            c_run_level_1 = 3,      
            c_run_level_3 = 2,      
            c_run_level_5 = 1,      
            c_run_level_7 = 0       
        };

        static void SendPowerUpNotification(BootSequenceState state);

        static void SendPowerDownNotification(BootSequenceState state);

        friend class SubSystem;

    private:
        static SubSystem* m_anchor;

        static void Attach(SubSystem* subsys);
        static void Detach(SubSystem* subsys);
        static void DoPowerDownRecursion(SubSystem* subsys);

        static UINT GetKey(const SubSystem* subsys);
        static void SortSubSystems();
};

#endif  // Apoxi_SubSystemManager_hpp


