/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_PbNumberHandler_hpp)
#define Mmi_PbNumberHandler_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <AddOns/AdcExtensions/FfsDataRecordHandler.hpp>
#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordHandler.hpp>


class PbNameProvider;
class PbNumberHandler : public PbRecordHandler {
    typedef PbRecordHandler Base;

    public:

        PbNumberHandler();
        PbNumberHandler(DataRecordHandler * record_handler);
        virtual ~PbNumberHandler(); 

        //tmp
        void InitFile(PbNameProvider* name_prov);
        
    protected:
        virtual DataRecord* GetDataRecord() { return &m_rec; }
        virtual DataRecordHandler* GetDataRecordHandler() { return &m_record_handler; }

    private:
        FfsDataRecordHandler    m_record_handler;
        PbNumberRecord          m_rec;

        
};


#endif  
