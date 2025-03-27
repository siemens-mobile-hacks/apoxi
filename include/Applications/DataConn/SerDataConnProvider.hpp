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

#if ! defined(Mmi_SerDataConnProvider_hpp)
#define Mmi_SerDataConnProvider_hpp

#include <Socket/SerDataConnProfile.hpp>

#include <DataConn/DataConnProvider.hpp>

class SerDataConnProvider : public DataConnProvider
{
    public:
        typedef DataConnProvider Base;

        SerDataConnProvider();

        virtual ~SerDataConnProvider();

        virtual INT GetProviderId() const { return c_invalid_colid; }

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        
        virtual BOOLEAN SetDataItem(const DataItem & item, INT column);

    protected:
        virtual DataConnProfile* GetProfileInstance() { return &m_ser_profile; }
        virtual void ClearProfile();

    private:
        SerDataConnProfile  m_ser_profile;
};

#endif
