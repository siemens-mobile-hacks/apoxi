/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractLockableDevice_hpp)
#define Apoxi_AbstractLockableDevice_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>
#include <Devices/AbstractDevice.hpp>

class AbstractLockableDevice : public AbstractDevice {
    typedef AbstractDevice Base;

    public:

        AbstractLockableDevice(INT category, INT device_id) : Base(category, device_id) {};

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

    protected:
        
        virtual BOOLEAN& GetLock() = 0;     
        
    private:
        
        BOOLEAN InitSemaphore();
        static BOOLEAN m_initialized;
        static Semaphore m_sem;
        
        
};

#endif  // Apoxi_AbstractLockableDevice_hpp


