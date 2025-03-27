/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ServiceThreadStarter_hpp)
#define Apoxi_ServiceThreadStarter_hpp


#include <Kernel/SubSystem.hpp>
#include <Kernel/SubSystemManager.hpp>

class ServiceThread;

class  ServiceThreadStarter : private SubSystem {
    public:
        struct StartParam {
            INT priority;       
            UINT32 stacksize;   
            void* stack;        
            SubSystemManager::BootSequenceState run_level;  
        };
        
        ServiceThreadStarter(ServiceThread& service_thread, StartParam* param = 0);
        virtual ~ServiceThreadStarter();

    private:
        ServiceThread& m_service_thread;
        StartParam* m_param;

        virtual const WCHAR* GetName() const;
        virtual void OnPowerUp();
        virtual void OnPowerDown();
        virtual BootSequenceState InvokeAt() const;
};

#endif  // Apoxi_ServiceThreadStarter_hpp

