/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MemoryConfig_hpp)
#define Apoxi_MemoryConfig_hpp

#include <Kernel/Types.hpp>
#include <Kernel/HeapVector.hpp>

class MemoryConfig {
    public:
        static HeapVector::HeapTableEntry * GetHeapBase();
        
        static BOOLEAN IsInRom(const void* ptr);
};

#endif  // Apoxi_MemoryConfig_hpp

