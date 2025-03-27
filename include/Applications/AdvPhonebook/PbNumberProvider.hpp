/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(Mmi_PbNumberProvider_hpp)
#define Mmi_PbNumberProvider_hpp

#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordProvider.hpp>
#include <Config/Config.hpp>

class PbNumberProvider : public PbRecordProvider {

    public:
        typedef PbRecordProvider Base;

        PbNumberProvider();
        
        PbNumberProvider(Protector *protector, PbRecordHandler *no_handler);
        
        virtual ~PbNumberProvider();
        
        void Init(Protector *protector, PbRecordHandler *m_handler);

        virtual INT GetProviderId() const;

        virtual BOOLEAN GetDataItem(IN INT columnid, 
                                    IN INT row, 
                                    OUT DataItem & item);

        virtual BOOLEAN SetDataItem(IN const DataItem & item, 
                                    IN INT columnid);

        virtual BOOLEAN AppendRow();

        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);

        virtual BOOLEAN Update(ProviderListener *listener = 0);
    
    protected:
        virtual Record* GetDataRecord();
        virtual void InitRecord();

    private:
        BOOLEAN UpdNumberIds(const DataItem &key_item, UINT8 no_id, BOOLEAN increase);

        PbNumberRecord  m_no_record;
};

#endif  
