/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_SubSystem_hpp)
#define Apoxi_SubSystem_hpp

#include <Kernel/SubSystemManager.hpp>

/*  -------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------- */

class SubSystem {
    public:
        typedef SubSystemManager::BootSequenceState BootSequenceState;

        SubSystem();

        virtual ~SubSystem();

        virtual const WCHAR* GetName() const = 0;

        virtual void OnPowerUp();

        virtual void OnPowerDown();

        virtual UINT8 GetPriority() const;

        virtual BootSequenceState InvokeAt() const = 0;

        friend class SubSystemManager;

    private:
        SubSystem* m_next;

        SubSystem(const SubSystem& sub_system);

        SubSystem& operator=(const SubSystem& sub_system);
};

#endif  // Apoxi_SubSystem_hpp


