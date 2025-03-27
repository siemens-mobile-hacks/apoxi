/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_PbNameHandler_hpp)
#define Mmi_PbNameHandler_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <AddOns/AdcExtensions/DataRecordHandler.hpp>
#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordHandler.hpp>

class PbNameHandler : public PbRecordHandler {
    typedef PbRecordHandler Base;

    public:
        PbNameHandler();
        virtual ~PbNameHandler(); 
        
        virtual void Init(); 

    protected:
        virtual DataRecordHandler* GetDataRecordHandler() { return &m_record_handler; }
        virtual DataRecord* GetDataRecord() { return &m_rec; }

    private:
        void InitFile();
        FfsDataRecordHandler    m_record_handler;
        PbRecord                m_rec;
};


#endif  
