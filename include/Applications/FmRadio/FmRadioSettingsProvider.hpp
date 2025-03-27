
/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_FmRadioSettingsProvider_hpp)
#define Mmi_FmRadioSettingsProvider_hpp

#include <AddOns/AdcExtensions/RecordHandler.hpp>
#include <Common/SettingsProvider.hpp>
#include <Config/Config.hpp>

#include "FmRadioSettingsRecord.hpp"
enum FmRadioSettingsColIds {

    c_radio_last_freq,
    c_radio_last_volume
};


class FmRadioSettingsProvider : public SettingsProvider
{
    typedef Provider Base;

    public:

        FmRadioSettingsProvider();
        virtual ~FmRadioSettingsProvider();
        void Init();
    
        virtual INT GetProviderId() const;
    
        virtual INT MaxRowCount();   

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        virtual BOOLEAN SelectRow(INT row = 0);

        virtual BOOLEAN CommitRow(INT row = 0);

        virtual void RestoreFactorySettings();

    private:
        FmRadioSettingsRecord   m_record;
        FmRadioSettingsRecord   m_commit_record;
        RecordHandler           m_handler;
};

#endif // Mmi_FmRadioSettingsProvider_hpp
