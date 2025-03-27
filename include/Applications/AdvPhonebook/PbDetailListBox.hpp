/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbDetail_ListBox_hpp)
#define Mmi_PbDetail_ListBox_hpp

#include <AdvPhonebook/PbProvListBox.hpp>

class PbProvider;
class PbDetailListBoxModel : public PbProvListBoxModel {
    typedef PbProvListBoxModel Base;

    public:
        PbDetailListBoxModel();
        PbDetailListBoxModel(DrawableObjectListBox *listbox, const INT* detail_columns, INT filt_colid = c_phone_no_id);
    
        void Init(DrawableObjectListBox *listbox, const INT* detail_columns, INT filt_colid = c_phone_no_id);

        void SetDetailColumns(const INT *detail_columns);

        virtual void UpdateNoOfItems();

        INT GetSelectedNoIndex(INT index = -1);
        void SetSelectedNoIndex(INT no_index);

        INT GetSelectedNoRow(INT index = -1);

    protected:
        virtual INT GetRow(INT index);
        virtual INT GetColumnId(INT index);

    private:
        INT GetColIdIndex(INT colid) const;

        INT                     m_name_row;     
        INT                     m_column_cnt;
        DataItem                m_key_item;
        const INT *             m_detail_columns;
        INT                     m_filt_colid;
};

class PbDetailListBox : public PbProvListBox {
    typedef PbProvListBox Base;

    public:
        PbDetailListBox();
        PbDetailListBox(ProvListBoxWin *parent, const INT* detail_columns, INT filt_colid = c_phone_no_id);

        virtual ~PbDetailListBox();

        void Init(ProvListBoxWin *parent, const INT* detail_columns, INT filt_colid = c_phone_no_id);

        XYDIM GetSelectedYPos() const;
        
        const WCHAR* GetSelectedText() { return GetMyModel()->GetProvText(GetSelectedIndex()); };

        INT GetSelectedNoRow() { return GetMyModel()->GetSelectedNoRow(); };

        INT GetSelectedNoIndex() { return GetMyModel()->GetSelectedNoIndex(); };
        void SetSelectedNoIndex(INT no_idx) { GetMyModel()->SetSelectedNoIndex(no_idx); };

        void SetDetailColumns(const INT *detail_columns) { GetMyModel()->SetDetailColumns(detail_columns); }

    protected:
        virtual Model* CreateModel() const;

    private:
        PbDetailListBoxModel* GetMyModel() const { return (PbDetailListBoxModel *)GetModel(); }
};

#endif  // Mmi_PbDetailListBox_hpp
