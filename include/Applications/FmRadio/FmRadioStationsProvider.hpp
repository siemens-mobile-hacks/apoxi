
/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_FmRadioStationsProvider_hpp)
#define Mmi_FmRadioStationsProvider_hpp

#include <AddOns/AdcExtensions/RecordHandler.hpp>
#include <Common/SettingsProvider.hpp>
#include <Config/Config.hpp>

#include "FmRadioStationsRecord.hpp"
enum FmRadioStationsColIds {

    c_radio_freq,
    c_radio_stat_text
};


class FmRadioStationsProvider : public SettingsProvider
{
    typedef Provider Base;

    public:

        FmRadioStationsProvider();
        virtual ~FmRadioStationsProvider();
        void Init();
    
        virtual INT GetProviderId() const;
    
        virtual INT MaxRowCount();   

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN CommitRow(INT row);

        virtual INT RowCount();

        virtual void RestoreFactorySettings();

        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        FmRadioStationsRecord   m_record;
        FmRadioStationsRecord   m_commit_record;
        RecordHandler           m_handler;
};

#endif // Mmi_FmRadioStationsProvider_hpp
