/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Trap_hpp)
#define Apoxi_Trap_hpp


#include <Kernel/Types.hpp>

class Provider;

class Trap {
    public:             
        static void Init();

        static void Assertion(BOOLEAN arg);

        static Provider& GetProvider();

    private:
};

#endif  // Apoxi_Trap_hpp

