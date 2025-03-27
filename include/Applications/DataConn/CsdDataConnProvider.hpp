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

#if ! defined(Mmi_CsdDataConnProvider_hpp)
#define Mmi_CsdDataConnProvider_hpp

#include <Socket/CsdDataConnProfile.hpp>

#include <DataConn/DataConnProvider.hpp>

class CsdDataConnProvider : public DataConnProvider
{
    public:
        typedef DataConnProvider Base;

        CsdDataConnProvider();

        virtual ~CsdDataConnProvider();

        virtual INT GetProviderId() const { return c_invalid_colid; }

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        
        virtual BOOLEAN SetDataItem(const DataItem & item, INT column);

    protected:
        virtual DataConnProfile* GetProfileInstance() { return &m_csd_profile; }
        virtual void ClearProfile();

    private:
        CsdDataConnProfile  m_csd_profile;
};

#endif
