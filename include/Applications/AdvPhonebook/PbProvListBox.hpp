/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbProvListBox_hpp)
#define Mmi_PbProvListBox_hpp

#include <Auxiliary/SortProvider.hpp>
#include <GuiExtensions/LabelListBoxModel.hpp>
#include <AdvPhonebook/PbTypes.hpp>

class PhonebookApp;
class PbProvider;

class PbProvListBoxModel : public LabelListBoxModel {
    typedef LabelListBoxModel Base;

    public:
        PbProvListBoxModel();   
        PbProvListBoxModel(DrawableObjectListBox *listbox);
        virtual ~PbProvListBoxModel();
    
        virtual const WCHAR* GetCellText(INT index, BOOLEAN highlighted);
        virtual const BitmapRes* GetCellIcon(INT index, BOOLEAN highlighted);
        
        virtual void UpdateNoOfItems();

        virtual void SetProvider(Provider *provider);
        virtual Provider* GetProvider();

        virtual void SetSelectedRow(INT recno);

        virtual INT GetSelectedProvRow();
        virtual INT GetSelectedColumnId();

        const WCHAR* GetProvText(INT index);

    protected:
        virtual INT GetRow(INT index);
        virtual INT GetColumnId(INT index) = 0;
        virtual INT GetProvRow(INT index);

    private:
        Provider    *m_provider;
        WString     m_text;

};

class PbProvColListBoxModel : public PbProvListBoxModel {
    typedef PbProvListBoxModel Base;

    public:
        PbProvColListBoxModel();
        PbProvColListBoxModel(DrawableObjectListBox *listbox, INT colid, INT sort_colid);
        virtual ~PbProvColListBoxModel();
        
        void Init(DrawableObjectListBox *listbox, INT colid, INT sort_colid);

        virtual const BitmapRes* GetCellIcon(INT index, BOOLEAN highlighted);

        void SetColumnId(INT colid) { m_column_id = colid; }
        
//      virtual void SetSelectedRow(INT row);

//      virtual void SetProvider(Provider *provider);
//      virtual Provider* GetProvider() { return &m_sort_provider; }

    protected:
        virtual INT GetColumnId(INT index) { return m_column_id; }
//      virtual INT GetProvRow(INT index);

    private:
        INT                 m_column_id;
        INT                 m_sort_column_id;
//      QuickSortProvider   m_sort_provider;
};

class ProvListBoxWin;
class PbProvListBox : public DrawableObjectListBox {
    typedef DrawableObjectListBox Base;

    public:

        PbProvListBox();
        PbProvListBox(ProvListBoxWin *parent);
        virtual ~PbProvListBox();

        void Init(ProvListBoxWin *parent);

        Provider* GetProvider() { return GetMyModel()->GetProvider(); }
        void SetProvider(Provider *provider) { GetMyModel()->SetProvider(provider); }

        virtual void Update(INT item_count = -1);

        void SetSelectedRow(INT row);
        INT GetSelectedRow() const { return GetMyModel()->GetSelectedProvRow(); };

        INT GetSelectedColumnId() const { return GetMyModel()->GetSelectedColumnId(); };

    protected:
        virtual void OnSelectionChanged();
        ProvListBoxWin * GetParent() { return m_parent; }

    private:
        PbProvListBoxModel* GetMyModel() const { return (PbProvListBoxModel *)GetModel(); }
        ProvListBoxWin *    m_parent;
};

class PbProvColListBox : public PbProvListBox {
    typedef PbProvListBox Base;

    public:
        void Init(ProvListBoxWin *parent, INT colid, INT sort_colid);

        void SetColumnId(INT colid) const { GetMyModel()->SetColumnId(colid); }

    protected:
        virtual Model* CreateModel() const;

    private:
        PbProvColListBoxModel* GetMyModel() const { return (PbProvColListBoxModel *)GetModel(); }
};

#endif  // Mmi_PbProvListBox_hpp
