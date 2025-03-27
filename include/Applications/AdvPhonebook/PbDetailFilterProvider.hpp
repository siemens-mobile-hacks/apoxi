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

#if ! defined(Mmi_PbDetailFilterProvider_hpp)
#define Mmi_PbDetailFilterProvider_hpp

#include <Auxiliary/FilterProvider.hpp>

class PbDetailProvider : public AbstractDelegationProvider {
    typedef AbstractDelegationProvider Base;

    public:
        PbDetailProvider();
        PbDetailProvider(Provider *provider, INT detail_row = c_no_row);

        ~PbDetailProvider();

        void Init(Provider *provider, INT detail_row = c_no_row);

        void SetProvider(Provider* provider) { m_provider = provider; }

        virtual void SetDetailRow(INT detail_row);
        virtual INT GetDetailRow();

        void SetKeyItem(const DataItem &key_item) { m_key_item = key_item; }
        const DataItem& GetKeyItem() { return m_key_item; }

        virtual INT RowCount();

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem &item);

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN Update(ProviderListener *listener = 0);

    protected:

    private:
        Provider *  m_provider;
        INT         m_detail_row;
        DataItem    m_key_item;
};

class PbProvider;
class PbNumberFilterProvider : public PbDetailProvider {
    typedef PbDetailProvider Base;

    public:
        PbNumberFilterProvider();
        PbNumberFilterProvider(Provider *provider, INT name_row = c_no_row);

        ~PbNumberFilterProvider();

        void Init(Provider *provider, INT name_row = c_no_row);

        virtual INT RowCount();

        virtual INT GetProviderId() const;

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem &item);

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN Update(ProviderListener *listener = 0);

        virtual BOOLEAN SetParameter(const DataItem& item);

        virtual Status GetStatus() const;
        
    private:
        Provider *          m_pb_provider;
        INT                 m_name_row;

        FilterProvider      m_filter;
        QuickSortProvider   m_sort_prov;
        EqualsRule          m_rule;
        DataItem            m_filt_item;
        DataItem            m_old_key_item;

        BOOLEAN             m_both_affected;
};

#endif  
