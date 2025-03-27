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

#if ! defined(Apoxi_AuxExtensions_MergeProvider_hpp)
#define Apoxi_AuxExtensions_MergeProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>
#include <Auxiliary/IndexTable.hpp>
#include <AddOns/AuxExtensions/ProviderIds.hpp>

class JoinRule;

class MergeProvider : public AbstractDelegationProvider
{
    typedef AbstractDelegationProvider Base;
    public:

        enum AffectedProvider {
            Both,
            ChildOnly,
            MergeOnly,
            None
        };

        MergeProvider();

        MergeProvider(INT provider_id, Provider* child_provider, Provider* merge_provider, INT child_key_colid, INT merge_key_colid, JoinRule* merge_rule, UINT max_cache_depth = 6);
        
        virtual ~MergeProvider();

        void Init(INT provider_id, Provider* child_provider, Provider* merged_provider, INT child_key_colid, INT merge_key_colid, JoinRule* merge_rule, UINT max_cache_depth = 6);

        AffectedProvider GetAffectedProvider() { return m_param; }

        Provider* GetMergedProvider() { return m_merge_provider; }

        void SetMergedProvider(Provider* merged_provider, INT merge_key_colid);

        INT GetChildKeyColumnId() const { return m_child_key_id; }

        INT GetMergedKeyColumnId() const { return m_merge_key_id; }

        JoinRule* GetMergeRule() { return m_merge_rule; }

        void SetMergeRule(JoinRule* merge_rule);

        virtual INT GetProviderId() const;

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN GetDefaultDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN CommitRow(INT row);

        virtual BOOLEAN AppendRow();

        virtual BOOLEAN InsertRow(INT row);

        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN ToggleRow(INT row);

        virtual BOOLEAN DeleteAllRows(ProviderListener* listener = 0);

        virtual BOOLEAN Update(ProviderListener* listener = 0);

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual INT ColumnCount() const;

        virtual const ColumnInfo * GetColumnInfo(INT column);
        
        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

        virtual void OnExecutingListener(Provider* provider = 0);

        void SetForceUpdate() { m_merge_needed = TRUE; }
        
    protected:
        virtual void OnChildProviderModification(Provider* provider, const Provider::Modification& modification);   
        
        virtual BOOLEAN IsLess(const DataItem& item1, const DataItem& item2);
        
        BOOLEAN UpdateIndexTable(ModificationType type, BOOLEAN child_prov_affected, INT row = c_no_row);       

        Provider*           m_merge_provider;
        INT                 m_merge_key_id;

        void InitIndexTable();
        void QuickSortDataItems(INT& size, INT low, INT high);
        INT BinSearchRow(INT size, const DataItem& item, DataItem* cache = 0, UINT cache_size = 0, UINT8 cache_depth = 0);

        UINT GetCacheSize(UINT8 max_cache_depth, INT row_count);

        IndexTable<INT>     m_sorted_table;
        JoinRule*           m_merge_rule;
        INT8                m_max_progress;
        INT8                m_min_progress;
        BOOLEAN             m_merge_needed;
        INT                 m_child_key_id;
        IndexTable<INT>     m_merged_rows;
        UINT                m_max_cache_depth;

    private:        
        INT GetMergeRow(INT child_row);
        BOOLEAN MatchRows(INT child_row, INT merge_row);
        
        BOOLEAN Alter(ModificationType type, INT row = -1); 
    
        AffectedProvider    m_param;
        INT                 m_provider_id;
        static ColumnInfo   m_colinfo[];
};

#endif  // Apoxi_AuxExtensions_MergeProvider_hpp


