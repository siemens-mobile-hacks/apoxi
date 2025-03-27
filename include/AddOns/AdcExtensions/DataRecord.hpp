/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_DataRecord_hpp)
#define Apoxi_AdcExtensions_DataRecord_hpp

#include <AddOns/AdcExtensions/DataRecordHandler.hpp>

typedef INT DataRecordId;
const DataRecordId c_no_data_record_id = -1;

class DataRecord {
    public:
        DataRecord(DataRecordId id, BOOLEAN deleted=FALSE);
        DataRecordId GetId() const { return m_id; }

    private:
        BOOLEAN IsDeleted() const;
        void Delete();

        DataRecordId m_id;
        BOOLEAN m_deleted;

        friend class DataRecordHandler;
};

#endif  // Apoxi_AdcExtensions_DataRecord_hpp

