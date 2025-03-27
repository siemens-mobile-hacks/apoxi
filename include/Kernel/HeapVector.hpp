/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HeapVector_hpp)
#define Apoxi_HeapVector_hpp

#include <Kernel/Types.hpp>

#if defined(APOXI_RTOS_WIN32)
    #if ! defined(APOXI_HEAP_MEM_ACCESS_CHECK)
        #define APOXI_HEAP_MEM_ACCESS_CHECK
    #endif
    #if ! defined(APOXI_HEAP_MEM_DETECT_CONFIG)
        #define APOXI_HEAP_MEM_DETECT_CONFIG
    #endif
#endif

#if defined(APOXI_HEAP_MEM_ACCESS_API)
    #if ! defined(APOXI_HEAP_MEM_CONTEXT_TRACE)
        #define APOXI_HEAP_MEM_CONTEXT_TRACE
    #endif
    #if ! defined(APOXI_HEAP_MEM_POOL_TRACE)
        #define APOXI_HEAP_MEM_POOL_TRACE
    #endif
#endif

// 
#if defined(APOXI_HEAP_MEM_DETECT_CONFIG) || defined(APOXI_HEAP_MEM_ACCESS_API)
    #if ! defined(APOXI_HEAP_MEM_ALLOCS_PER_SIZE)
        #define APOXI_HEAP_MEM_ALLOCS_PER_SIZE
    #endif
#endif

// this check defines if the length vector shall be used
#if defined(APOXI_HEAP_MEM_ACCESS_CHECK) || defined(APOXI_HEAP_MEM_DETECT_CONFIG)
    #if ! defined(APOXI_HEAP_LENGTH_VECTOR)
        #define APOXI_HEAP_LENGTH_VECTOR
    #endif
#endif

// this check defines if the caller id and length id shall be used inside 
#if defined(APOXI_HEAP_MEM_CONTEXT_TRACE)
    #if ! defined(APOXI_HEAP_MEM_POOL_TRACE)
        #define APOXI_HEAP_MEM_POOL_TRACE
    #endif
    #if ! defined(APOXI_HEAP_CONTEXT_USAGE)
        #define APOXI_HEAP_CONTEXT_USAGE
    #endif
    #if ! defined(APOXI_HEAP_LENGTH_VECTOR)
        #define APOXI_HEAP_LENGTH_VECTOR
    #endif
#endif

// this check defines if the pool name shall be created inside memory config
#if defined(APOXI_HEAP_MEM_ALLOC_TRACE) || defined(APOXI_HEAP_MEM_POOL_TRACE)
    #if ! defined(APOXI_HEAP_NAME_USAGE)
        #define APOXI_HEAP_NAME_USAGE
    #endif
#endif

// this check defines if the statistics struct shall be created inside memory config
#if defined(APOXI_HEAP_MEM_POOL_TRACE)
    #if ! defined(APOXI_HEAP_STATS_USAGE)
        #define APOXI_HEAP_STATS_USAGE
    #endif
#endif


class HeapVector
{
    public:
        enum {
            BITS_PER_UINT = sizeof(UINT) * 8
        };

        struct Page;

        // statistic pages 
        struct Stats {
            UINT32  m_allocations;
            UINT32  m_frees;
            UINT32  m_overflows;
            UINT16  m_peak;
            UINT16  m_current;
            UINT    m_overhead;
        };

        // ContextId
        typedef UINT8 ContextId;

        // prototypes of used functions
        typedef void (*InitializeFunction)(Page * page);
        typedef void*  (*AllocateFunction)(Page * page, size_t nrofbytes);
        typedef void*  (*ReAllocateFunction)(Page * page, UINT heapid, void*  oldaddress, 
                                             size_t newsize, BOOLEAN shallcopy);
        typedef void (*FreeFunction)(Page * page, const void*  address);
        typedef void (*DbgOutFunction)(Page * page);
        typedef INT32 (*SizeFunction)(Page * page, const void*  address);
        typedef BOOLEAN (*IsFreePageFunction)(Page * page);
        typedef Stats * (*GetStatsFunction)(Page * page);
        typedef void (*OverwriteCheckFunction)(Page * page);
        typedef void (*DbgOutContextFunction)(Page * page);

        // function table, one instance for each page type necessary in heapvector.cpp
        struct FctTable {
            InitializeFunction      m_init_fct;
            AllocateFunction        m_alloc_fct;
            ReAllocateFunction      m_realloc_fct;
            FreeFunction            m_free_fct;
            SizeFunction            m_size_fct;
            DbgOutFunction          m_dbgout_fct;
            IsFreePageFunction      m_isfree_fct;
            GetStatsFunction        m_getstats_fct;
            OverwriteCheckFunction  m_overwritecheck_fct;
            DbgOutFunction          m_dbgout_context_fct;
        };

        // the blockpage type 
        struct BlockPage
        {
            UINT8 *  m_memory;
            UINT *   m_bits;
            UINT     m_blockcounter;
#if defined(APOXI_HEAP_LENGTH_VECTOR)
            UINT16 * m_sizevector;
#endif
#if defined(APOXI_HEAP_CONTEXT_USAGE)
            ContextId * m_contextvector;
#endif
            BOOLEAN  m_free;
#if defined(APOXI_HEAP_STATS_USAGE)
            Stats    m_stats;
#endif

            static void Initialize(Page * page);

            static void*  Allocate(Page * page, size_t nrofbytes);
            static void*  ReAllocate(Page * page, UINT heapid, void*  oldaddress, 
                                     size_t newsize, BOOLEAN shallcopy);
            static void Free(Page * page, const void*  address);
            static INT32 Size(Page * page, const void*  address);

            static void DbgOut(Page * page);
            static BOOLEAN IsFreePage(Page * page);
            static Stats * GetStats(Page * page);
            static void OverwriteCheck(Page * page);
            static void DbgOutContext(Page * page);
        };

        struct VarPage
        {
            UINT8 *      m_memory;
            UINT8 HUGE * m_base_huge;
            UINT8 HUGE * m_end_huge;

            UINT16 *     m_length;
            UINT         m_shiftval;
#if defined(APOXI_HEAP_LENGTH_VECTOR)
            UINT32 *     m_sizevector;
#endif
#if defined(APOXI_HEAP_CONTEXT_USAGE)
            ContextId * m_contextvector;
#endif
            BOOLEAN      m_free;
#if defined(APOXI_HEAP_STATS_USAGE)
            Stats        m_stats;
#endif


            static void Initialize(Page * page);

            static void * Allocate(Page * page, size_t nrofbytes);
            static void * ReAllocate(Page * page, UINT heapid, void*  oldaddress, 
                                     size_t newsize, BOOLEAN shallcopy);
            static void Free(Page * page, const void*  address);
            static INT32 Size(Page * page, const void*  address);

            static void HUGE*  HugeAllocate(Page * page, UINT32 nrofbytes);
            static void HUGE*  HugeReAllocate(Page * page, UINT heapid, void HUGE*  oldaddress, 
                                              UINT32 newsize, BOOLEAN shallcopy);

            static void HugeFree(Page * page, const void HUGE*  address);

            static void DbgOut(Page * page);
            static BOOLEAN IsFreePage(Page * page);
            static Stats * GetStats(Page * page);
            static void OverwriteCheck(Page * page);
            static void DbgOutContext(Page * page);

            static UINT16 GetBlockNo(Page * vpage, UINT32 nrofbytes, UINT cnt = 0);
            static void SubFree(Page * page, UINT32 address, UINT blockno);

        };

        // the root page which contains the description of a page
        struct Page {
            BOOLEAN      m_ishuge;
#if defined(APOXI_HEAP_NAME_USAGE)
            CHAR *       m_name;
#endif
            UINT         m_blocksize;
            UINT16       m_low;
            UINT32       m_high;
            UINT8 *      m_base;
            UINT8 *      m_end;
            UINT           m_N;
            const FctTable *   m_fct_table;
            Page *       m_page;
        };

        struct HeapTableEntry
        {
            Page ** m_startpage; 
            UINT   m_heap_id;
            UINT   m_virtual_heap_id;
            UINT32 m_max_virtual_size;
            INT32  m_current_virtual_size;
            const CHAR *  m_name;
        };
        
};

// invalid context id 
const HeapVector::ContextId c_invalid_context_id = ~0;

// constant fct tables are present in Heapvector.cpp
extern const HeapVector::FctTable g_fcts_block_page;
extern const HeapVector::FctTable g_fcts_var_page;
extern const HeapVector::FctTable g_fcts_huge_page;

#define HEAP_BYTES_PER_UINT sizeof(UINT)

// macros if statistics shall be present in memory config
#if defined(APOXI_HEAP_STATS_USAGE)
    #define HEAP_STAT_STRUCT_VALUES ,{ 0, 0, 0, 0, 0 ,0 }
#else
    #define HEAP_STAT_STRUCT_VALUES 
#endif

// macros if size vector shall be present in memory config
#if defined(APOXI_HEAP_LENGTH_VECTOR)
    #define BLOCK_HEAP_SIZE_VECTOR(name, size, high)        static UINT16 m_size_vector_##name[(size / high)+1];
    #define VAR_HEAP_SIZE_VECTOR(name, size, blocksize)     static UINT32 m_size_vector_##name[(size / blocksize)+1];
    #define HEAP_SIZE_VECTOR_PTR(name)                      m_size_vector_##name,
#else
    #define BLOCK_HEAP_SIZE_VECTOR(name, size, high)    
    #define VAR_HEAP_SIZE_VECTOR(name, size, blocksize) 
    #define HEAP_SIZE_VECTOR_PTR(name)  
#endif

// macros if caller context vector shall be present in memory config
#if defined(APOXI_HEAP_CONTEXT_USAGE)
    #define BLOCK_HEAP_CONTEXT_VECTOR(name, size, high)     static HeapVector::ContextId m_context_vector_##name[(size / high)+1];
    #define VAR_HEAP_CONTEXT_VECTOR(name, size, blocksize)  static HeapVector::ContextId m_context_vector_##name[(size / blocksize)+1];
    #define HEAP_CONTEXT_VECTOR_PTR(name)                   m_context_vector_##name,
#else
    #define BLOCK_HEAP_CONTEXT_VECTOR(name, size, high)     
    #define VAR_HEAP_CONTEXT_VECTOR(name, size, blocksize)  
    #define HEAP_CONTEXT_VECTOR_PTR(name)                   
#endif

// macros if the name of a page shall be present in memory config
#if defined(APOXI_HEAP_NAME_USAGE)
    #define APOXI_HEAP_NAME(name)       static CHAR m_name_##name[] = #name;
    #define APOXI_HEAP_NAME_PTR(name)   m_name_##name,
#else
    #define APOXI_HEAP_NAME(name)    
    #define APOXI_HEAP_NAME_PTR(name)   
#endif

// constant of the additional size per blockpage for memory checking
#if defined(APOXI_HEAP_MEM_ACCESS_CHECK)
    // dont change that values !!!!!
    #define NO_CHECK_BYTES 4
#else
    #define NO_CHECK_BYTES 0
#endif

 
//
//  BLOCK_HEAP_PAGE(name, size, low, high)
//
/* Configuration:
    name: name of the page
    size: overall size of the memorypool, for C166 shall be smaller then < 16K
    low:  elements which are greater equal than low can be held by this page
    high: elements which are less equal than high can be held by this page
          ATTENTION: high must be a multiple of 2 it represents also the blocksize.

    Example:
        BLOCK_HEAP_PAGE(page_10, 10*1024,9,10);
    will allocate a 10 K page where elements between 9 and 10 bytes can be held.
    1024 blocks can be used.
*/


#define BLOCK_HEAP_PAGE(name, size, low, high)                          \
const UINT c_add_bytes_##name = ((size / high)+1) * NO_CHECK_BYTES;     \
static UINT m_mem_##name[(size+c_add_bytes_##name)/HEAP_BYTES_PER_UINT];\
static UINT m_bits_##name[(size / high / HeapVector::BITS_PER_UINT)+1]; \
APOXI_HEAP_NAME(name)                                                   \
BLOCK_HEAP_SIZE_VECTOR(name, size, high)                                \
BLOCK_HEAP_CONTEXT_VECTOR(name, size, high)                             \
static HeapVector::BlockPage m_page_##name = {                          \
    (UINT8 *)&m_mem_##name[0],                                          \
    m_bits_##name,                                                      \
    0,                                                                  \
    HEAP_SIZE_VECTOR_PTR(name)                                          \
    HEAP_CONTEXT_VECTOR_PTR(name)                                       \
    TRUE                                                                \
    HEAP_STAT_STRUCT_VALUES                                             \
};                                                                      \
static const HeapVector::Page name = {                                  \
    FALSE,                                                              \
    APOXI_HEAP_NAME_PTR(name)                                           \
    high,                                                               \
    low,                                                                \
    high,                                                               \
    (UINT8 *)&m_mem_##name[0],                                          \
    ((UINT8 *)&m_mem_##name[0])+size+c_add_bytes_##name,                \
    size / high,                                                        \
    &g_fcts_block_page,                                                 \
    (HeapVector::Page*)&m_page_##name                                   \
};

//
//  VAR_HEAP_PAGE(name, size, blocksize, min, max)
//
/* Configuration:
    name: name of the page
    size: overall size of the memorypool, for C166 shall be smaller then < 16K
    blocksize: used blocksize for the page, ATTENTION: must be a value 2^N, 
               like 4, 8, 16, 32, 64 etc ... reason for that is faster divison, 
               through bit shift operation
    min:  elements which are greater equal than low can be held by this page
    max: elements which are less equal than high can be held by this page, this
          value has to be also smaller then the size of the pool
    
    This page is using a best fit algorithm, if a request wants to allocate blocks, 
    the best position will be found to avoid fragmentation throughout the blocklist.
    That means in the case:
        5 free, 3 used, 2 free, 4 used ...
    allocating of 2 blocks will result in
        5 free, 3 used, 2 used, 4 used 

    Example:
        VAR_HEAP_PAGE(page_d1, 64*127,64,64,1024); 
    will allocate 8128 bytes, with a blocksize of 64 bytes where elements between 
    64 and 1024 bytes can be held. If 100 bytes shall be allocated 2 blocks have to
    be used etc. 

*/

#define VAR_HEAP_PAGE(name, size, blocksize, low, high)                 \
static UINT   m_mem_##name[(size/HEAP_BYTES_PER_UINT)];                 \
static UINT16 m_length_##name[(size / blocksize)+1];                    \
APOXI_HEAP_NAME(name)                                                   \
VAR_HEAP_SIZE_VECTOR(name, size, blocksize)                             \
VAR_HEAP_CONTEXT_VECTOR(name, size, blocksize)                          \
static HeapVector::VarPage m_page_##name = {                            \
    (UINT8 *)&m_mem_##name[0],                                          \
    0,                                                                  \
    0,                                                                  \
    m_length_##name,                                                    \
    0,                                                                  \
    HEAP_SIZE_VECTOR_PTR(name)                                          \
    HEAP_CONTEXT_VECTOR_PTR(name)                                       \
    TRUE                                                                \
    HEAP_STAT_STRUCT_VALUES                                             \
};                                                                      \
static const HeapVector::Page name = {                                  \
    FALSE,                                                              \
    APOXI_HEAP_NAME_PTR(name)                                           \
    blocksize,                                                          \
    low,                                                                \
    high,                                                               \
    (UINT8 *)&m_mem_##name[0],                                          \
    ((UINT8 *)&m_mem_##name[0])+size,                                   \
    size / blocksize,                                                   \
    &g_fcts_var_page,                                                   \
    (HeapVector::Page*)&m_page_##name                                   \
};

//
//  HUGE_HEAP_PAGE(name, size, blocksize, min, max)
//
/* Configuration:
    see VAR_HEAP_PAGE but with HUGE memory model
*/

#define HUGE_HEAP_PAGE(name, size, blocksize, low, high)                \
static UINT HUGE m_mem_##name[((size+blocksize)/HEAP_BYTES_PER_UINT)];  \
static UINT16 m_length_##name[(size/blocksize)+1];                      \
APOXI_HEAP_NAME(name)                                                   \
VAR_HEAP_SIZE_VECTOR(name, size, blocksize)                             \
VAR_HEAP_CONTEXT_VECTOR(name, size, blocksize)                          \
static HeapVector::VarPage m_page_##name = {                            \
    0,                                                                  \
    (UINT8 HUGE *)&m_mem_##name[0],                                     \
    ((UINT8 HUGE *)&m_mem_##name[0])+size,                              \
    m_length_##name,                                                    \
    0,                                                                  \
    HEAP_SIZE_VECTOR_PTR(name)                                          \
    HEAP_CONTEXT_VECTOR_PTR(name)                                       \
    TRUE                                                                \
    HEAP_STAT_STRUCT_VALUES                                             \
};                                                                      \
static const HeapVector::Page name = {                                  \
    TRUE,                                                               \
    APOXI_HEAP_NAME_PTR(name)                                           \
    blocksize,                                                          \
    low,                                                                \
    high,                                                               \
    0,                                                                  \
    0,                                                                  \
    size / blocksize,                                                   \
    &g_fcts_huge_page,                                                  \
    (HeapVector::Page*)&m_page_##name                                   \
};


#define PAGE_TABLE_BEGIN(heapname)  static HeapVector::Page * m_pages_##heapname[] = {
#define PAGE_ENTRY(name) (HeapVector::Page*)& name, 
#define PAGE_TABLE_END 0 };


#define HEAP_TABLE_BEGIN()  static HeapVector::HeapTableEntry m_heap_table[] = {

#define HEAP_ENTRY(heapname, id)  {                                     \
    (HeapVector::Page**)(HeapVector::Page*)& m_pages_##heapname[0],     \
    id,                                                                 \
    id,                                                                 \
    0,                                                                  \
    0,                                                                  \
    #heapname                                                           \
},

#define VIRTUAL_HEAP_ENTRY(heapname, id, virtid, size)  {               \
    (HeapVector::Page**)(HeapVector::Page*)& m_pages_##heapname[0],     \
    id,                                                                 \
    virtid,                                                             \
    size,                                                               \
    0,                                                                  \
    #heapname                                                           \
},
#define HEAP_TABLE_END { 0, 0 } };


#define GET_HEAP_TABLE()& m_heap_table[0];

#endif  // Apoxi_HeapVector_hpp

