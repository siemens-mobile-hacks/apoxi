/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BackLight_hpp)
#define Apoxi_BackLight_hpp

#include "Kernel/Types.hpp"
#include <Devices/AbstractDevice.hpp>




class BackLight : public AbstractDevice {
    public:
    
        enum BackLightMode {
            BackLightOn  ,
            BackLightOff 
        };
        
        static void Init();
        
        virtual const WCHAR* GetName() const;
        
        static void Switch(BackLightMode mode);

        static BOOLEAN GetStatus();
    
        static void CleanUp(){};
        
};



#endif  // Apoxi_BackLight_hpp


