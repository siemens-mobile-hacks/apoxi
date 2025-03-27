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

#if ! defined(Mmi_PbNameNumberProvider_hpp)
#define Mmi_PbNameNumberProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>
#include <Config/Config.hpp>


class PbNameNumberProvider : public AbstractDelegationProvider
{
    public:
        typedef AbstractDelegationProvider Base;

        PbNameNumberProvider();
        PbNameNumberProvider(Provider *provider);
        virtual ~PbNameNumberProvider();

        void Init(Provider *provider);

        virtual INT GetProviderId() const;

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem &item);

        virtual BOOLEAN GetChildRow(INT & child_row, INT row);

    private:
        Provider *   m_prov;
};

#endif
