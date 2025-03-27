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

#if ! defined(Mmi_DataConnProvider_hpp)
#define Mmi_DataConnProvider_hpp

#include <Auxiliary/Provider.hpp>

class DataItem;

enum DataConnColids {
    c_dataconn_icon_id = 100,
    c_dataconn_display_text_id,
    c_dataconn_profile_id,
    c_dataconn_profile_count_id,
    c_dataconn_profile_type_id,
    c_dataconn_next_free_row_id,
    c_dataconn_is_readonly_id
};

class DataConnProfileManager;
class DataConnProvider : public Provider
{
    public:
        typedef Provider Base;

        DataConnProvider();

        virtual ~DataConnProvider();

        virtual INT GetProviderId() const;

        virtual INT RowCount();

        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        
        virtual BOOLEAN SetDataItem(const DataItem & item, INT column);

        virtual BOOLEAN CommitRow(INT row);
        
        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN AppendRow();

    protected:
        virtual DataConnProfile* GetProfileInstance() = 0;
        virtual void ClearProfile() = 0;

        DataConnProfileManager* GetProfileManager() { return m_profile_manager; }

        DataConnProfileId GetProfileId(INT row) const;
        DataConnProfile* GetProfile()  { return m_actual_profile_ptr.Get(); }
        DataConnProfile* GetProfile(DataConnProfileId profile_id);
        DataConnProfile::ProfileType GetProfileType(INT row) const;

    private:
        DataConnProfileManager* m_profile_manager;

        INT GetProfileCount() const;
        DataConnProfileId GetFirstUsedProfileId() const;
        INT GetFirstFreeProfileRow() const;

        DataConnProfilePtr m_actual_profile_ptr;
        DataConnProfilePtr m_profile_ptr;
};

#endif
