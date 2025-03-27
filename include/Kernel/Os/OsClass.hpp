/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_OsClass_hpp)
#define Apoxi_OsClass_hpp


#include <Kernel/Types.hpp>
#include <Kernel/Os/Ticks.hpp>

#if !defined(APOXI_CONFIG_DBG_OUT_RANGE_ARRAY)
    #define APOXI_CONFIG_DBG_OUT_RANGE_ARRAY 5
#endif

// Implementation of the following prototypes has to be done in the Os
// dependent files Ose166.cpp, Win32.cpp etc.

class Os {
    public:
        static BOOLEAN IsWhiteSpace(WCHAR ch);
        static BOOLEAN IsLineBreak(WCHAR ch);
        static void DbgOut(const WCHAR* fmt, ...);
        static void DbgOut(const CHAR* fmt, ...);
        static void DbgOut(UINT16 index, const WCHAR* fmt, ...);
        static void DbgOut(UINT16 index, const CHAR* fmt, ...);
        static void DbgOutStackUsage();
        static Ticks GetTicks(void);

        static void Sleep(UINT32 timeout);

        static void* Alloc(INT size, UINT heapid = 0);
        static void* Realloc(void* oldaddress, INT newsize, BOOLEAN shallcopy = FALSE);
        static void Free(void* p, UINT virtid = ~0);

        static void HUGE* HugeAlloc(UINT32 size, UINT heapid = 0);
        static void HUGE* HugeRealloc(void HUGE*  oldaddress, UINT32 newsize, BOOLEAN shallcopy = FALSE);
        static void HugeFree(void HUGE* p, UINT virtid = ~0);

        static void* StackAlloc(INT size);
        static void StackFree(void* p);
        
};

#if defined(APOXI_ENABLE_RUNTIME_CONFIGURATION)
    class String;

    class DbgOutConfigurator {
        public:
            DbgOutConfigurator();
                            
            static BOOLEAN IsInRange(UINT idx);
                        
        private:
            struct Range {
                UINT16 from;
                UINT16 to;
            };
            
            static Range m_range[APOXI_CONFIG_DBG_OUT_RANGE_ARRAY];
            
            static BOOLEAN Parse(const String& str);
    };
#endif

#endif  // Apoxi_OsClass_hpp

