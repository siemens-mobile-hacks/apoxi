/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_ValueMap_hpp)
#define Asc_ValueMap_hpp

/*  ------------------------------------------------------------------------
    This file is used to support value mapping macros to supply the use of 
    configuration independent definition of constants and enums.
    The values of the so-defined constants and enums are assinged within the
    various configuration dependant ValueMap.hpp files.
    If a new class-scope is used, then an accordingly configuration independant 
    scope macro must be defined.
    ------------------------------------------------------------------------ */

/*  ------------------------------------------------------------------------
    macros for configuration independent definition of constants and enums.
    these macros form the programmer's interface.
    ------------------------------------------------------------------------ */
// general macros for configuration independent value definitions
#define ApoxiDefineEntity(val) APOXI_DEFINE_ENTITY_##val


// general assignement macro for configuration independent value definitions using a scope qualifier
#define ApoxiDefineScopeEntity(val, scope) APOXI_DEFINE_SCOPE_ENTITY_##scope##_##val


/*  ------------------------------------------------------------------------
    configuration dependent ValueMap.hpp's
    ------------------------------------------------------------------------ */
#include <Asc/Target/ValueMap.hpp>

#endif  // Asc_ValueMap_hpp

