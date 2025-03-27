/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HeapManager_hpp)
#define Apoxi_HeapManager_hpp

#include <Kernel/HeapVector.hpp>
#include <Auxiliary/Macros.hpp>


class HeapManager 
{
    friend class HeapVector;

#if defined(APOXI_HEAP_MEM_ALLOCS_PER_SIZE) 

    public:
        struct HeapLogStruct {
            UINT32 m_size;
            UINT32 m_allocations;
            UINT32 m_frees;
            UINT16 m_current;
            UINT16 m_peek;
        };

        enum {
            c_max_indexed_size = 16384 / sizeof(HeapLogStruct)
        };

        enum HeapPageType {
            HeapUndefinedPage = 0,
            HeapBlockPage = 1,
            HeapVarPage   = 2,
            HeapHugePage  = 3
        };
        
        struct HeapLogGenerateStruct {
            UINT32       m_size;
            UINT32       m_low;
            UINT32       m_high;
            UINT32       m_blocksize;
            HeapPageType m_pagetype;
        };

        enum {
            c_max_gen_page_no = 200
        };

#endif

#if defined(APOXI_HEAP_MEM_CONTEXT_TRACE) 
    #if ! defined(APOXI_HEAP_MEM_CONTEXT_TRACE_MAX_CTX) 
        #define APOXI_HEAP_MEM_CONTEXT_TRACE_MAX_CTX 50
    #endif
        enum {
            c_max_context_no = APOXI_HEAP_MEM_CONTEXT_TRACE_MAX_CTX,
            c_max_context_name_len = 32
        };

        struct HeapContextStruct {
            UINT32      m_context_identifier;
            CHAR        m_name[c_max_context_name_len];
            UINT32      m_allocations;
            UINT32      m_frees;
            UINT32      m_frees_by_other_context;
            UINT32      m_mem_allocated;
            UINT32      m_mem_used;
            UINT32      m_peak_allocated;
            UINT32      m_peak_used;
        };
#endif

 
    public:
        HeapManager();
        static void* Allocate(size_t nrofbytes, UINT heapid = 0);
        static void* ReAllocate(void*  oldaddress, size_t newsize, BOOLEAN shallcopy);
        static void Free(void*  address, UINT virtid = ~0);

        static void HUGE*  HugeAllocate(UINT32 nrofbytes, UINT heapid = 0);
        static void HUGE*  HugeReAllocate(void HUGE*  oldaddress, UINT32 newsize, BOOLEAN shallcopy);
        static void HugeFree(void HUGE* address, UINT virtid = ~0);

        static void OverallOverwriteCheck();

        static BOOLEAN IsValidAddress(void * address);
        static BOOLEAN IsValidHugeAddress(void HUGE* address);

        static void DbgOut();
        static void Initialize();
        static BOOLEAN GetOverallMemUsage(UINT32 & totalram, UINT32 & currentram, UINT32 & peakram);
        static HeapVector::Page * GetFirstPageEntry();
        static HeapVector::Page * GetNextPageEntry();

        static BOOLEAN DumpMemoryConsumptionSnapshot();
        static BOOLEAN GenerateMemoryConfig(UINT32 safetypercent = 50);

#if defined(APOXI_HEAP_MEM_ALLOCS_PER_SIZE) 
        static void RecordAllocation(UINT32 size);
        static void RecordFree(UINT32 size);
        static void RecordHugeAllocation(UINT32 size);
        static void RecordHugeFree(UINT32 size);
#endif

#if defined(APOXI_HEAP_MEM_ACCESS_API) 
        static HeapVector::HeapTableEntry * GetFirstHeapEntry();
        static HeapVector::HeapTableEntry * GetNextHeapEntry();
        static HeapVector::Page * GetFirstHeapPageEntry(HeapVector::HeapTableEntry * heap);
        static HeapVector::Page * GetNextHeapPageEntry();

        static HeapManager::HeapLogStruct * GetFirstHeapLogStruct(BOOLEAN & ishuge);
        static HeapManager::HeapLogStruct * GetNextHeapLogStruct(BOOLEAN & ishuge);

        static HeapManager::HeapContextStruct * GetFirstHeapContextStruct();
        static HeapManager::HeapContextStruct * GetNextHeapContextStruct();
#endif

#if defined(APOXI_HEAP_MEM_CONTEXT_TRACE) 
        static UINT32 GetCurrentContext();
        static HeapVector::ContextId GetCurrentContextId();
        static CHAR * GetCurrentContextName();

        static HeapVector::ContextId RecordContextAllocation(UINT32 nrofbytes, UINT32 allocated);
        static void RecordContextFree(UINT32 nrofbytes, UINT32 allocated, HeapVector::ContextId id);
        static HeapContextStruct * GetHeapContextStruct(INT idx) { 
            ASSERT_DEBUG(idx<c_max_context_no);
            return &m_contexts[idx]; 
        }
#endif
        static BOOLEAN DumpMemoryContextSnapshot();
        static BOOLEAN EnablePeakMemoryContextOutput(BOOLEAN enable = TRUE);
        static void DbgOutContextUsage();

    private:
        static BOOLEAN m_initialized;
        static HeapVector::HeapTableEntry * m_iterator_heap;
        static HeapVector::Page ** m_iterator_page;

#if defined(APOXI_HEAP_MEM_DETECT_CONFIG) 
        static void AddGeneratedPage(UINT32 size, UINT32 low, UINT32 high, UINT32 blocksize, 
                                     HeapPageType pagetype);
        static BOOLEAN GenerateBlockPages(BOOLEAN shall16k, UINT32 safetypercent, 
                                          UINT32 low, UINT32 high, UINT32 prefpagesize);
        static BOOLEAN GenerateFixVarPages(BOOLEAN shall16k, UINT32 safetypercent, 
                                           UINT32 low, UINT32 high, UINT32 blocksize);
        static BOOLEAN GenerateDynVarPages(HeapLogStruct * var, BOOLEAN shall16k, UINT32 safetypercent, 
                                           UINT32 low, UINT32 high, UINT32 blocksize, HeapPageType type);
        static BOOLEAN DumpMemoryConfig();
#endif

#if defined(APOXI_HEAP_MEM_ALLOCS_PER_SIZE) 
        static INT AddVarRecord(HeapLogStruct * var, UINT32 size);
        static INT LookupRecord(HeapLogStruct * var, UINT32 size);
        static BOOLEAN ConsistencyCheck();

        static HeapLogStruct m_fix[c_max_indexed_size];
        static HeapLogStruct m_var[c_max_indexed_size];
        static HeapLogStruct m_huge[c_max_indexed_size];
        static HeapLogGenerateStruct m_genpage[c_max_gen_page_no];
        static UINT m_size_iterator_idx;
#endif

#if defined(APOXI_HEAP_MEM_CONTEXT_TRACE) 
        static HeapContextStruct m_contexts[c_max_context_no];
        static INT m_current_context_no;
        static BOOLEAN m_peak_value_trace_enabled;
        static UINT m_ctx_iterator_idx;
#endif


};

void TestHeaps();

#endif

