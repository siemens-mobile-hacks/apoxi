/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RuntimeConfigurator_hpp)
#define Apoxi_RuntimeConfigurator_hpp

#if defined(APOXI_ENABLE_RUNTIME_CONFIGURATION)

#include <Kernel/Types.hpp>
#include <Auxiliary/String.hpp>
#include <Kernel/Os/Semaphore.hpp>
#include <Auxiliary/SimpleMap.hpp>

class RuntimeConfigurator {
    public:
        typedef BOOLEAN (*CallBackFn)(const String&);
        
        static RuntimeConfigurator& GetInstance();

        BOOLEAN Parse(const String& str);

        BOOLEAN Register(const String& command_str, CallBackFn fn);

        BOOLEAN Unregister(const String& command_str);

    private:
        Semaphore m_sem;
        SimpleMap<String, CallBackFn> m_map;
};

#endif  // APOXI_ENABLE_RUNTIME_CONFIGURATION

#endif  // Apoxi_RuntimeConfigurator_hpp

