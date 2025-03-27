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
#include <Auxiliary/WString.hpp>
#include <Auxiliary/Macros.hpp>

class Provider;

typedef void (* TrapCB)(CHAR * filename, INT line);

class Trap {
    public:             
        static void Init();
        
        static void SetHandler(TrapCB hdl) { m_hdl = hdl; }

        static void Assertion(BOOLEAN arg);
        
        static void Assertion(BOOLEAN arg, CHAR * filename, INT line);

        static Provider& GetProvider();
        
    private:
        static BOOLEAN      m_RunnigClassBTrap;
        static BOOLEAN      m_SoftTrap;
        static TrapCB       m_hdl;
        
        static INT DrawText(XYDIM, XYDIM, const CHAR*);
};

#endif  // Apoxi_Trap_hpp

