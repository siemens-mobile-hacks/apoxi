/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_RecordHandler_hpp)
#define Apoxi_AdcExtensions_RecordHandler_hpp

#include <Afs/Rfs/File.hpp>
#include <Auxiliary/IndexTable.hpp>
#include <AddOns/AdcExtensions/Record.hpp>


class RecordHandler {
    public:

        RecordHandler();

        ~RecordHandler();

        BOOLEAN Init(FilePtr file, Record* record, INT max_rows, BOOLEAN sequential = TRUE);

        BOOLEAN Lock();

        BOOLEAN Unlock();

        virtual BOOLEAN ExistsRecord(INT row);

        virtual BOOLEAN LoadRecord(INT row, Record *rec);
        
        virtual BOOLEAN StoreRecord(INT row, Record *rec);
        
        virtual BOOLEAN AddRecord(Record *rec);
        
        virtual BOOLEAN DeleteRecord(INT row);

        virtual BOOLEAN DeleteAllRecords();

        INT GetRowCount() const;

        void SetRecordTableValue(INT logical, INT physical);


    private:

        void SetStoreFlag(INT row, BOOLEAN filled);
        
        BOOLEAN GetStoreFlag(INT row);

        BOOLEAN WriteStoreFlags();

        BOOLEAN OpenFile(File::OpenMode open_mode);

        BOOLEAN CloseFile();


        FilePtr         m_file;
        Record*         m_record;
        INT             m_row_count;
        INT             m_max_rows;
        INT             m_last_row;
        IndexTable<INT> m_record_table;

        struct StructuredDataHeader {
            UINT32      offset;
            UINT16      record_length;
            UINT16      row_count;
            UINT8       version;
        } m_header;

        UINT8*          m_store_flags;
        UINT8*          m_header_cache;

        INT             m_row_count_offset;
        INT             m_store_flags_offset;
        INT             m_nof_store_flag_bytes;
        BOOLEAN         m_sequential;
        BOOLEAN         m_locked;
        BOOLEAN         m_initialized;
};


#endif  // Apoxi_AdcExtensions_RecordHandler_hpp


