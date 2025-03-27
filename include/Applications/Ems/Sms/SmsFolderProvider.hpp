/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsFolderProvider_hpp)
#define Mmi_SmsFolderProvider_hpp

#include "SmsBasicProvider.hpp"


class SmsFolderProvider : public AbstractDelegationProvider
{
    typedef AbstractDelegationProvider Base;

    public:
        SmsFolderProvider();
        virtual ~SmsFolderProvider();

        void Init(Provider *provider);
        
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem& item);

        virtual BOOLEAN GetChildRow(INT& childrow, INT row);

    protected:
        virtual INT GetMappedColumnId(INT colid);

    private:
        UINT8 GetUibStatus(Tpdu::Status sms_status);
        SmsBasicProvider m_basic_provider;
};

#endif  // Mmi_SmsFolderProvider_hpp
