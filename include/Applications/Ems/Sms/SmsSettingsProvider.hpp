/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsSettingsProvider_hpp)
#define Mmi_SmsSettingsProvider_hpp

#include <AddOns/AdcExtensions/RecordHandler.hpp>
// ************************************************
// CN200002234
// Edited/Fixed by Christoph Minkwitz
#include <Common/SettingsProvider.hpp>
#include <Config/Config.hpp>
#include <Sms/SmsSettingsRecord.hpp>

class SmsSettingsProvider : public SettingsProvider{
    typedef SettingsProvider Base;

    public:

        SmsSettingsProvider();

        virtual ~SmsSettingsProvider();

        void Init();

        virtual INT GetProviderId() const;

        virtual INT MaxRowCount();  

        virtual void RestoreFactorySettings();

        virtual INT RowCount();

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

        virtual BOOLEAN CommitRow(INT row);

    private:
        SmsSettingsRecord   m_record;           // SMS provider settings read from FFS will by stored here.
        SmsSettingsRecord   m_buffer_record;    // SMS provider settings changed by the user will be stored here.
        RecordHandler       m_handler;          // Record Handler to read and write data
};

#endif // Mmi_SmsSettingsProvider_hpp
