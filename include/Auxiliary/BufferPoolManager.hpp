/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BufferPoolManager_hpp)
#define Apoxi_BufferPoolManager_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/DynamicBitVector.hpp>

#define MAX_POOL_COUNT 10
#define MEM_POOL 0

class BufferPoolManager {
    public:
        
        enum ResultType {
            NoError,
            BufferPoolNotAvailableError,
            BufferNotExistentError,
            BufferAdjustedWarning,
            NoBufferFreeError,
            OutOfMemoryError
        };


        static BufferPoolManager* GetInstance(); 

        BufferPoolManager::ResultType CreateBufferPool(UINT8& buff_count, 
                                                       UINT32 buff_len, 
                                                       UINT32& pool_handle);

        BufferPoolManager::ResultType DeleteBufferPool(UINT32& pool_handle);

        BufferPoolManager::ResultType GetBufferPoolStatus(UINT32 pool_handle, 
                                                          UINT8& free_buff_count);
        BufferPoolManager::ResultType GetBuffer(UINT32 pool_handle, UINT8 HUGE* &buff_ptr);

        BufferPoolManager::ResultType ReleaseBuffer(UINT8 HUGE* &buff_ptr);

    private:
        
        // private constructor for singleton
        BufferPoolManager();

        //methods for allocating and freeing memory
        void* MemAlloc(UINT32 nr_of_bytes);
        void MemFree(void* object);
        
        // just to keep structure of one buffer in a pool in mind
        struct Buffer {
            UINT32      m_pool_id;          // + offset 0
            UINT32      m_buff_id;          // + offset 4
            UINT32      m_buff_len;         // + offset 8
            UINT32      m_buff_act_len;     // + offset 12
            UINT8 HUGE* m_buff;             // + offset 16
        };

        struct Pool {
            UINT8 m_count;
            UINT8 m_free;
            UINT8 m_last_returned;
        };


/* needed for singleton */
        
        static BufferPoolManager m_instance;
        
        Pool* m_pools[MAX_POOL_COUNT];      //array of pool pointers
        Buffer** m_buffers[MAX_POOL_COUNT]; //for each pool there is an array of Buffers
        DynamicBitVector* m_buffer_status[MAX_POOL_COUNT]; //array of bit vectors to indicate free buffers
        UINT8 m_new_pool;                   //current position in pool array
        UINT8 m_pool_filled;                //number of filled pools
        
};

#endif  // Apoxi_BufferPoolManager_hpp


