/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_PbFfsNumberHandler_hpp)
#define Mmi_PbFfsNumberHandler_hpp

#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordHandler.hpp>
    
class PbFfsNumberHandler : public PbRecordHandler {
    typedef PbRecordHandler Base;

    public:

        PbFfsNumberHandler();

        virtual ~PbFfsNumberHandler(); 

        void Init();

        virtual INT MaxRowCount();

    protected:

        virtual RecordHandler* GetDataRecordHandler();

        virtual Record* GetDataRecord();

    private:
        RecordHandler       m_record_handler;
        PbNumberRecord      m_rec;
        PbNumberRecord      m_delete_rec;
};

#endif  
