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

#if ! defined(Mmi_PbSimProvider_hpp)
#define Mmi_PbSimProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>

class PbSimProvider : public AbstractDelegationProvider
{
    public:
        typedef AbstractDelegationProvider Base;

        PbSimProvider();
        PbSimProvider(Provider *provider, INT provider_id = c_invalid_colid);
        virtual ~PbSimProvider();

        void Init(Provider *provider = 0, INT provider_id = c_invalid_colid);

        virtual INT GetProviderId() const;

        virtual INT ColumnCount() const;

        virtual const ColumnInfo * GetColumnInfo(INT column);

        BOOLEAN ExistColumn(INT colid) { return Provider::ExistColumn(colid); }

        INT GetColumnId(INT column) { return Provider::GetColumnId(column); } 

        const ColumnInfo * GetColumnInfoPerId(INT id) { return Provider::GetColumnInfoPerId(id); }

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem &item);

        virtual BOOLEAN GetChildRow(INT & child_row, INT row);

        virtual Status GetStatus() const;

        virtual INT GetProgress();

    private:
        INT m_provider_id;
};

#endif
