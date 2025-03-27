/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#include <Auxiliary/Macros.hpp>
#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <Kernel/System.hpp>
#include "../AudioDef.hpp"

//This should not be necessary, because this file is part of the Win2 platform anyway.
//TODO: This should check for a _platform_ instead of a compiler anyway.
#if defined(APOXI_COMPILER_MSVC) 
#define huge // ToDo: workaround due to HUGE define in aud_drv.h
             // remove when HUGE define in aud_drv.h is fixed.
#include <Devices/Win32/aud_drv.h>
#else
#include <stack/target/aud_drv.h>
#endif

