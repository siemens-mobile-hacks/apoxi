/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_DataRecordHandler_hpp)
#define Apoxi_AdcExtensions_DataRecordHandler_hpp

class DataRecord;

class DataRecordHandler {
    public:
        DataRecordHandler(INT record_length);

        virtual BOOLEAN LoadRecord(INT row, DataRecord *rec) = 0;

        virtual BOOLEAN StoreRecord(INT row, const DataRecord *rec) = 0;

        virtual BOOLEAN AddRecord(const DataRecord *rec) = 0;

        virtual BOOLEAN DeleteRecord(INT row) = 0;

    protected:
        BOOLEAN IsRecordDeleted(const DataRecord &rec) const;
        void MarkRecordDeleted(DataRecord &rec);
        INT m_record_length;
};


#endif  // Apoxi_AdcExtensions_DataRecordHandler_hpp

