/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_RegManager_hpp)
#define Apoxi_RegManager_hpp
//class RegNodeFile;


#include <Kernel/SubSystem.hpp>

/*  ========================================================================
    RegManager
    ======================================================================== */
class RegManager : public SubSystem {
    
    public:
        RegManager();

        static RegManager* GetInstance() { return m_instance; }

        virtual const WCHAR* GetName() const { return L"APOXI RegManager"; }

        virtual BootSequenceState InvokeAt() const { return (SubSystemManager::c_run_level_3); }

        virtual UINT8 GetPriority() const { return (100); } 

        virtual void OnPowerUp();

        virtual void OnPowerDown();

    private:
        static BOOLEAN Rescan();

        static INT16 GetRootFileId();

        static void ConstructUriMapTable(INT16 file_id);

        static void DeleteUnlinkedFiles();

        static RegManager       *m_instance;
};

#endif

