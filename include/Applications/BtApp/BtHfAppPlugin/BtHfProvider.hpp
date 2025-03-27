/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_BtHfProvider_hpp)
#define Mmi_BtHfProvider_hpp

#include <AddOns/AdcExtensions/RecordHandler.hpp>
#include <Common/SettingsProvider.hpp>
#include "BtHfRecord.hpp"

enum BtHfColIds {
    c_default_audiopath_id
};


class BtHfProvider : public SettingsProvider {
    typedef SettingsProvider Base;
    public:
        BtHfProvider();
        virtual ~BtHfProvider();
        void Init();

        virtual INT MaxRowCount(); 
        virtual INT GetProviderId() const;
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);
        virtual BOOLEAN SetDataItem(const DataItem &item, INT column_id);
        virtual BOOLEAN SelectRow(INT row);
        virtual BOOLEAN CommitRow(INT row);
        virtual void RestoreFactorySettings();

    private:
        RecordHandler   m_handler;
        BtHfRecord      m_record;
        BtHfRecord      m_commit_record;        
};

#endif  // Mmi_BtHfProvider_hpp
