/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_NvRamStorage_hpp)
#define Apoxi_AdcExtensions_NvRamStorage_hpp

#include <AddOns/AdcExtensions/DataRecord.hpp>

struct NvRamBlockInfo {
        DataRecordId id;
        INT size;
        INT array_size;
};

class NvRamStorage {
    public:
        static NvRamStorage *GetStorage();
        static void SetNvRamStorageInfo(const NvRamBlockInfo *info) { m_info = info; }
        BOOLEAN Read(DataRecord *record, INT idx = 0);
        BOOLEAN Store(const DataRecord *record, INT idx = 0);
        BOOLEAN GetBlockInfo(DataRecordId block_id, NvRamBlockInfo &info);

    private:
        NvRamStorage();
        static void Init();
        static BOOLEAN IsInitialized();
        static INT GetBlockOffset(DataRecordId block_id, INT idx);

        static const NvRamBlockInfo *m_info;
        static CHAR* m_start_address;
        static INT m_size;
        static NvRamStorage m_storage;
};

#endif // Apoxi_AdcExtensions_NvRamStorage_hpp

