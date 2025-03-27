/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_Devices_BP30_Fota_hpp)
#define Apoxi_Devices_BP30_Fota_hpp

#include <Devices/AbstractDevice.hpp>

class Fota : public AbstractDevice {
    typedef AbstractDevice Base;

    #include <Devices/FotaInterface.hpp>

    private:
};

#endif  // Apoxi_Devices_BP30_Fota_hpp

