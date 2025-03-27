/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_NvRamDataRecordHandler_hpp)
#define Apoxi_AdcExtensions_NvRamDataRecordHandler_hpp

#include <AddOns/AdcExtensions/DataRecordHandler.hpp>

class NvRamStorage;

class NvRamDataRecordHandler : public DataRecordHandler {
    typedef DataRecordHandler Base;
    public:
        NvRamDataRecordHandler(const INT record_length, DataRecord &record);
        void Init();

        virtual BOOLEAN LoadRecord(INT row, DataRecord *rec);
        virtual BOOLEAN StoreRecord(INT row, const DataRecord *rec);
        virtual BOOLEAN AddRecord(const DataRecord *rec);
        virtual BOOLEAN DeleteRecord(INT row);

    private:
        virtual BOOLEAN DoesRecordExist(INT row);

        DataRecord &m_record;
        NvRamStorage *m_nv_ram;
};


#endif  // Apoxi_AdcExtensions_NvRamDataRecordHandler_hpp

