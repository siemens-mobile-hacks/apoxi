/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DrmSubsystem_hpp)
#define Apoxi_DrmSubsystem_hpp


#include <Kernel/SubSystem.hpp>

/*  ========================================================================
    DrmSubsystem
    ======================================================================== */
class DrmSubsystem : public SubSystem {
    
    public:
        DrmSubsystem();

        static DrmSubsystem* GetInstance() { return m_instance; }

        virtual const WCHAR* GetName() const { return L"APOXI DrmSubsystem"; }

        virtual BootSequenceState InvokeAt() const { return (SubSystemManager::c_run_level_3); }

        virtual UINT8 GetPriority() const { return (100); } 

        virtual void OnPowerUp();

        virtual void OnPowerDown();

    private:

        static DrmSubsystem     *m_instance;
};

#endif // Apoxi_DrmSubsystem_hpp

