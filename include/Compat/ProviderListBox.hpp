/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ProviderListBox_hpp)
#define Apoxi_ProviderListBox_hpp

#include <Gui/AbstractListBox.hpp>
#include <Auxiliary/DataItem.hpp>


class ProviderListBoxModel : public AbstractListBoxModel {
    typedef AbstractListBoxModel Base;

    public:
        ProviderListBoxModel();
        ProviderListBoxModel(Provider *provider, INT col_id);

        void Init(Provider *provider, INT col_id);

        virtual ~ProviderListBoxModel();

        virtual BOOLEAN GetProviderEntry(INT col_id, INT row, DataItem &item)const;

        virtual void SetProvider(Provider *provider);

        virtual Provider* GetProvider() const { return m_provider; }

        virtual void UpdateNoOfItems();

        virtual void SetColId(INT col_id);

        virtual INT GetColId() const;

    private:
        INT m_col_id;
        Provider *m_provider;
};

class ProviderListBoxView : public AbstractListBoxView {
    typedef AbstractListBoxView Base;
    public:
        ProviderListBoxView();
        ProviderListBoxView(XYDIM item_height);

        virtual ~ProviderListBoxView();

        virtual void DrawItem(const AbstractListBox &listbox, DeviceContext *dc, INT index, const Rect &item_rect) const;
};


class ProviderListBox : public AbstractListBox {
    typedef AbstractListBox Base;

    public:
        ProviderListBox();

        ProviderListBox(Control *parent, Provider *provider, INT col_id);

        virtual ~ProviderListBox();

        void Init(Control *parent, Provider *provider, INT col_id);

        virtual void Update();

    protected:
        virtual Model* CreateModel() const;

    private:
        ProviderListBoxView m_view;
        ProviderListBoxModel* GetMyModel() const { return (ProviderListBoxModel *)GetModel(); }
};

#endif  // Apoxi_ProviderListBox_hpp


