/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CheckBoxList_hpp)
#define Apoxi_CheckBoxList_hpp

#include <Gui/Lib.hpp>
#include <Gui/AbstractListBox.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Gui/AbstractMenuList.hpp>
#include <Gui/CheckBoxItem.hpp>
#include <Gui/CheckBox.hpp>


typedef AbstractMenuListModel<CheckBoxItem> CheckBoxListModel;

class CheckBoxList : public AbstractMenuList {
    typedef AbstractMenuList Base;

    public:
        CheckBoxList();

        CheckBoxList(Control *parent);

        virtual ~CheckBoxList();

        void Init(Control *parent);

        void AddItem(CheckBoxItem *item, CheckBoxItem *after = 0);

        void AddItem(CheckBoxItem *item, const WCHAR *text, BOOLEAN selected = FALSE) const;

        void RemoveItem(CheckBoxItem *item);

        void RemoveAllItems() const;

        CheckBoxItem* GetFirstItem() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void Refresh(const Rect &rect);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnItemSelected();

    private:
        CheckBoxListModel* GetMyModel() const { return (CheckBoxListModel *)GetModel(); }
};

class CheckBoxListView : public AbstractListBoxView {
    typedef AbstractListBoxView Base;

    public:
        // Constructor of the view of a checkbox-list.
        CheckBoxListView();
        CheckBoxListView(CheckBoxView *view, XYDIM item_height);

        virtual ~CheckBoxListView();

        virtual void DrawItem(const AbstractListBox &listbox, DeviceContext *dc, INT index, const Rect &item_rect) const;

    protected:
        const CheckBoxView *m_view;
        
        virtual void DrawCheckBoxItem(const CheckBoxItem &item, DeviceContext *dc, const Rect &item_rect, BOOLEAN highlighted) const = 0;
};


#endif  // Apoxi_CheckBoxList_hpp


