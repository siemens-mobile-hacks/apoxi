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

#if ! defined(Mmi_PbNameProvider_hpp)
#define Mmi_PbNameProvider_hpp

#include <AdvPhonebook/PbRecord.hpp>
#include <AdvPhonebook/PbRecordProvider.hpp>
#include <Config/Config.hpp>

class PbNameProvider : public PbRecordProvider {

    public:
        typedef PbRecordProvider Base;

        PbNameProvider();

        PbNameProvider(Protector *protector, PbRecordHandler *name_handler);

        virtual ~PbNameProvider();

        void Init(Protector *protector, PbRecordHandler *name_handler);
        
        virtual INT GetProviderId() const;

        virtual BOOLEAN GetDataItem(IN INT columnid, 
                                    IN INT row, 
                                    OUT DataItem & item);

        virtual BOOLEAN SetDataItem(IN const DataItem & item, 
                                    IN INT columnid);

        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN AppendRow();
        
        virtual BOOLEAN DeleteAllRows(ProviderListener *listener = 0);
        
        virtual BOOLEAN Update(ProviderListener *listener = 0);

        /*Gets a corresponding Name row for the given record Number*/
        INT GetNameRowForRecNo(Number record_number);

    protected:
        virtual Record* GetDataRecord();
        virtual void InitRecord();
        
    private:
        void DeleteNoRows(INT row);
        INT GetDefaultNoRow(INT row);

        PbRecord            m_pb_record;
        Provider *          m_grp_prov;
        
        INT                 m_icc_id;
};

#endif  
