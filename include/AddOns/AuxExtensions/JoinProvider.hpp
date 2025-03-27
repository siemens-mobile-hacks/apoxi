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

#if ! defined(Apoxi_AuxExtensions_JoinProvider_hpp)
#define Apoxi_AuxExtensions_JoinProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <Auxiliary/IndexTable.hpp>
#include <AddOns/AuxExtensions/ProviderIds.hpp>

class JoinRule;

class JoinProvider : public Provider
{
    typedef Provider Base;
    public:

        JoinProvider();

        JoinProvider(INT provider_id, Provider* first_provider, Provider* second_provider, INT first_key_colid, INT second_key_colid, JoinRule* join_rule);
        virtual ~JoinProvider();

        void Init(INT provider_id, Provider* first_provider, Provider* second_provider, INT first_key_colid, INT second_key_colid, JoinRule* join_rule);

        Provider* GetFirstProvider() { return m_first_provider; }

        Provider* GetSecondProvider() { return m_second_provider; }

        INT GetFirstKeyColumnId() const { return m_first_key_id; }

        INT GetSecondKeyColumnId() const { return m_second_key_id; }

        JoinRule* GetJoinRule() { return m_join_rule; }

//      /// <em>SetJoinRule</em> sets the current rule for merging.
//      void SetJoinRule(JoinRule* join_rule) { m_join_rule = join_rule; }

        virtual INT GetProviderId() const;

        virtual INT RowCount();

        virtual INT MaxRowCount();

        virtual INT ColumnCount() const;

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT column);

        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN CommitRow(INT row);

        virtual BOOLEAN AppendRow();

        virtual BOOLEAN InsertRow(INT row);

        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN ToggleRow(INT row);

        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

        virtual INT GetProgress();

        virtual const ColumnInfo * GetColumnInfo(INT column);
        
        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

        virtual void OnExecutingListener(Provider* child_provider);

        enum AffectedProvider {
            Both,
            FirstOnly,
            SecondOnly,
            None
        };

    protected:
        virtual void SetProgress (INT progress);

    private:        
        BOOLEAN             m_key_row_set;
        AffectedProvider    m_param;
        INT                 m_provider_id;
        INT                 m_first_key_id;
        INT                 m_second_key_id;
        INT                 m_rows;
        INT8                m_progress;
        JoinRule*           m_join_rule;
        Provider*           m_first_provider;
        Provider*           m_second_provider;
        IndexTable<INT>     m_first_joined_rows;
        IndexTable<INT>     m_second_joined_rows;
        static ColumnInfo   m_colinfo[];
};

/* For internal use in derived classes of <em>JoinProvider</em> to handle a accurate
progress indication.
Delegates only <em>OnExecuting</em> to the child-listener.
<em>OnStarted</em> and <em>OnFinished</em> on the child-listener should be invoked
directly by the <em>JoinProvider</em>. */
class JoinProviderListener : public ProviderListener {
    typedef ProviderListener Base;
    public:
        JoinProviderListener(JoinProvider* provider, Provider* child_provider, ProviderListener* child_listener);

        virtual ~JoinProviderListener();

        virtual void OnExecuting();

        void SetChildProvider(Provider* child_provider) { m_child_provider = child_provider; }

    private:
        JoinProvider*       m_join_provider;
        Provider*           m_child_provider;
        ProviderListener*   m_child_listener;
};  //lint !e1712

#endif  // Apoxi_AuxExtensions_JoinProvider_hpp

