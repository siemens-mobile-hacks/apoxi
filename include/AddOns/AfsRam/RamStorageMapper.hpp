/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamStorageMapper_hpp
#define Apoxi_RamStorageMapper_hpp

#include <AddOns/AfsRam/RamTypes.hpp>
#include <Auxiliary/DynamicBitVector.hpp>
#include <Auxiliary/SimpleMap.hpp>

class RamStorageMapper
{
    friend class RamFileObj;

public:
    ~RamStorageMapper();

    static RamStorageMapper* GetInstance() { return &m_instance; }

    UINT32 GetSize() const;

    UINT32 GetUsedSize() const;

    UINT32 GetFreeSize() const;

    UINT16 GetBlockSize() const;

    BOOLEAN GetFreeBlockIndex(UINT32 &block_index);

    BOOLEAN ReadBlock(UINT32 block_index, void HUGE *block_buffer); // read one block

    BOOLEAN ReadBlocks(UINT32 block_index, void HUGE *buffer, UINT32 count);

    BOOLEAN WriteBlock(UINT32 block_index, const void HUGE *block_data);

    BOOLEAN WriteBlocks(UINT32 block_index, const void HUGE *buffer, UINT32 count);

    BOOLEAN DeleteBlock(UINT32 block_index);

    BOOLEAN DeleteBlocks(UINT32 block_index, UINT32 count);

    BOOLEAN FormatStorage(UINT16 block_size = c_ram_storage_default_block_size);

    BOOLEAN IsBlockUsed(UINT32 block_index) const;

    RamError GetLastError() const;

protected:
    void HUGE* GetBlock(UINT32 block_index) const;

private:
    RamStorageMapper(UINT16 block_size = c_ram_storage_default_block_size);

    void InitStorage(UINT16 block_size);

    BOOLEAN DeleteStorage();

    static RamStorageMapper m_instance;

    UINT16 m_block_size;

    mutable RamError m_last_error;

    SimpleMap<UINT, void HUGE*> m_blocks;

    UINT32 m_free_block_index;
};

#endif  // Apoxi_RamStorageMapper_hpp


