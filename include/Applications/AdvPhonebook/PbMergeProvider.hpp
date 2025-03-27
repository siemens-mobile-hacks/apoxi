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

#if ! defined(Mmi_PbMergeProvider_hpp)
#define Mmi_PbMergeProvider_hpp

#include <AddOns/AuxExtensions/MergeProvider.hpp>
#include <AddOns/AuxExtensions/JoinRule.hpp>
//CN200013749 
#include <AdvPhonebook/PbNextFreeIdRecord.hpp>
//END CN200013749 

#include <Phonebook/PbProvIds.hpp>
#include <Config/Config.hpp>

/*------------------------------------------------------------------
                            PbMergeProvider
 ------------------------------------------------------------------*/
//CN200013749 
const UINT32 c_max_unique_id = 0xFFFFFFFF;
//END CN200013749 
class PbNameProvider;
class PbNumberProvider;
class PbMergeProvider : public MergeProvider {
    typedef MergeProvider Base;

    public:
        
        PbMergeProvider();
        virtual ~PbMergeProvider();
            
        void Init(PbNameProvider* name_prov, PbNumberProvider* no_prov);

        virtual BOOLEAN GetDefaultDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN AppendRow();
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);
        virtual BOOLEAN Update(ProviderListener *listener = 0);

        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual INT MaxRowCount();
        
//CN200013749 
        UINT32 GetLastDeletedUniqueId(){return m_last_deleted_unique_id;}
//END CN200013749 
    private:
        BOOLEAN     PbPerformMerge(ProviderListener *listener);
        Provider*           m_name_prov;
        Provider*           m_no_prov;
        BOOLEAN             m_both_affected;
        StandardJoinRule    m_join_rule;
        
        INT                 m_rollback_row;
//CN200013749 
        PbNextFreeIdRecord  m_next_free_id_record;
        UINT32 m_last_deleted_unique_id;
        //RecordHandler instance is used to access data stroed on FFS.
        RecordHandler       m_handler;
        //Renumbers the unique ids in Number Provider
        void  RenumberUniqueIds();
//END CN200013749 
};

#endif  
