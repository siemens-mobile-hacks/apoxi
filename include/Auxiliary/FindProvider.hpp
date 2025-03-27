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

#if ! defined(_Adc_FindProvider_hpp)
#define _Adc_FindProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>



class DataItem;
class FilterRule;

/*
NOTE: No writing is possible on a FindProvider. Use <em>GetChildRow</em> to get
the row of the child provider and update the child provider directly.
See also: <em>Provider, FilterProvider, Find2Provider, DataItem, FilterRule</em>.*/
class FindProvider : public AbstractDelegationProvider
{
    public:
        typedef AbstractDelegationProvider Base;
        FindProvider();

        FindProvider(Provider * provider, FilterRule * rule, INT columnid = 0);
        virtual ~FindProvider();

        void Init(Provider * provider, FilterRule * rule, INT columnid = 0);

        virtual INT RowCount();

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);

        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

        virtual void OnExecutingListener(Provider* provider = 0);

    protected:
        virtual void OnChildProviderModification(Provider* provider, const Provider::Modification& modification);

        INT          m_FindRow;
        INT          m_column;
        FilterRule * m_rule;
};

#endif


