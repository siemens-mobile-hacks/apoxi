/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
 
#if ! defined(UibSettingsProvider_hpp)
#define UibSettingsProvider_hpp


#include <AddOns/AdcExtensions/RecordHandler.hpp>
#include <Common/SettingsProvider.hpp>

#include <UnifiedInbox/UibSettingsRecord.hpp>

/*  UibSettingsProvider provides settings data of the UIB.
    This Provider consists of two columns:
    c_uib_sort_crit_colid
    c_uib_sort_asc_colid */
class UibSettingsProvider : public SettingsProvider {

    typedef SettingsProvider Base;

    public:
        UibSettingsProvider();

        virtual ~UibSettingsProvider();

        virtual INT GetProviderId() const;

        void Init();

        virtual void RestoreFactorySettings();
        
        virtual INT RowCount();

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem &item);

        virtual BOOLEAN SetDataItem(const DataItem& item, INT columnid);

        virtual BOOLEAN SelectRow(INT row);
        
        virtual BOOLEAN CommitRow(INT row);

    private:
        RecordHandler m_handler;
        UibSettingsRecord m_record;
        UibSettingsRecord m_commit_record;
};

#endif /* UibSettingsProvider_hpp */
