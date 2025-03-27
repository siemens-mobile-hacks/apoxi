/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_Win32_Charger_hpp)
#define Apoxi_Devices_Win32_Charger_hpp

#include <Devices/AbstractDevice.hpp>

class Charger: public AbstractDevice {
    typedef AbstractDevice Base;

    #include <Devices/ChargerInterface.hpp>

    protected:
        virtual void OnStart();
};

#endif

