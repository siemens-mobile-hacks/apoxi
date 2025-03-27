/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of thi document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AdcInterface_hpp)
#define Asc_AdcInterface_hpp

#include <Apc/NetworkTypes.hpp>

RegisterStatus GetRegistrationState();

ClirMode GetClirSetting();

CugDescriptor GetCugSetting();

BOOLEAN IsRedialingActive();

#endif  // Asc_AdcInterface_hpp


