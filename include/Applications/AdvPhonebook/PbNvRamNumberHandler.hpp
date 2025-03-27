/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_PbNvRamNumberHandler_hpp)
#define Mmi_PbNvRamNumberHandler_hpp

#include <AddOns/AdcExtensions/NvRamDataRecordHandler.hpp>
#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordHandler.hpp>

class PbNvRamNumberHandler : public PbRecordHandler {
    typedef PbRecordHandler Base;

    public:

        PbNvRamNumberHandler();
        PbNvRamNumberHandler(DataRecordHandler * record_handler);
        virtual ~PbNvRamNumberHandler(); 
        
        void Init();

        virtual INT MaxRowCount() { return c_max_pb_number_entries; }

    protected:
        virtual DataRecordHandler* GetDataRecordHandler() { return &m_record_handler; }
        virtual DataRecord* GetDataRecord() { return &m_rec; }

    private:
        NvRamDataRecordHandler  m_record_handler;
        PbNumberRecord          m_rec;

        
};


#endif  
