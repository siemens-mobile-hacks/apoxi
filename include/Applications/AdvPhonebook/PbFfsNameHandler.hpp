/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_PbFfsNameHandler_hpp)
#define Mmi_PbFfsNameHandler_hpp

#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordHandler.hpp>

class PbFfsNameHandler : public PbRecordHandler {
    typedef PbRecordHandler Base;

    public:
        PbFfsNameHandler();
        
        virtual ~PbFfsNameHandler(); 
        
        virtual void Init(); 

        virtual INT MaxRowCount();

    protected:
        virtual RecordHandler* GetDataRecordHandler() { return &m_record_handler; }
        virtual Record* GetDataRecord() { return &m_rec; }

    private:
        RecordHandler   m_record_handler;
        PbRecord        m_rec;
        PbRecord        m_delete_rec;
};

#endif  
