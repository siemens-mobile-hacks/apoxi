/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_DeviceManager_hpp)
#define Apoxi_Devices_DeviceManager_hpp

#include <Kernel/Types.hpp>
#include <Devices/AbstractDevice.hpp>

class Display;
class ClientDc;

#if !defined(APOXI_MAX_DISPLAY_COUNT)
#define APOXI_MAX_DISPLAY_COUNT 2
#endif

class DeviceManager {
    public:
        class Iterator {
            public:
                Iterator();
                ~Iterator();

                BOOLEAN Begin();

                Iterator& operator++();

                Iterator operator++(INT);

                AbstractDevice* Get() const { return m_device; }

            private:
                AbstractDevice* m_device;
        };

        static DeviceManager& GetInstance();

        AbstractDevice* GetDevice(AbstractDevice::Category category, INT index = 0) const;

        void AddDevice(AbstractDevice& device);

        void RemoveDevice(AbstractDevice& device);
        
        static Display* GetDisplay(INT display_idx = 0) { return m_display[display_idx]; }

        static ClientDc* GetSharedDc(INT display_idx = 0) { return m_shared_dc[display_idx]; }

    private:
        AbstractDevice* m_first;
        mutable Semaphore m_sem;

        static BOOLEAN m_initialized;
        static Display* m_display[APOXI_MAX_DISPLAY_COUNT];
        static ClientDc* m_shared_dc[APOXI_MAX_DISPLAY_COUNT];

        DeviceManager();

        void Startup();

        void Shutdown();

        void NotifyDevice(BOOLEAN startup);

        AbstractDevice* GetNextDevice(const AbstractDevice& device) const;

        friend class StartUp;   // invokes StartUp 
        friend class ShutDown;  // invokes ShutDown
        friend class Iterator;
};

#endif  // Apoxi_Devices_DeviceManager_hpp

