/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_PbRecordHandler_hpp)
#define Mmi_PbRecordHandler_hpp

#include <AddOns/AdcExtensions/RecordHandler.hpp>

class Record;
class RecordHandler;
class PbRecordHandler {

    public:

        PbRecordHandler();
        virtual ~PbRecordHandler(); 

        virtual void Init(); 

        BOOLEAN Lock();

        BOOLEAN Unlock();

        virtual INT MaxRowCount() = 0;

        INT RowCount() 
            { return GetDataRecordHandler()->GetRowCount(); };

        INT GetProgress() const { return m_progress; };

        virtual BOOLEAN DeleteEntries(ProviderListener * listener = 0);

        BOOLEAN ExistsEntry(INT recno) 
            { return GetDataRecordHandler()->ExistsRecord(recno); };

        virtual BOOLEAN GetEntry(INT recno, Record *pb_rec);
        virtual BOOLEAN UpdateEntry(INT recno, Record *pb_entry);
        virtual BOOLEAN DeleteEntry(INT recno);

    protected:
        virtual Record* GetDataRecord() = 0;
        virtual RecordHandler* GetDataRecordHandler() = 0;


    private:                
        INT                     m_progress;

};

#endif  
