/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MenuList_hpp)
#define Apoxi_MenuList_hpp

#include <Auxiliary/LinkedList.hpp>
#include <Gui/Lib.hpp>
#include <Gui/AbstractListBox.hpp>
#include <Gui/AbstractMenuList.hpp>
#include <Compat/MenuItem.hpp>


typedef AbstractMenuListModel<MenuItem> MenuListModel;

class MenuListView : public AbstractListBoxView {
    typedef AbstractListBoxView Base;

    public:
        MenuListView();
        MenuListView(XYDIM item_height);

        virtual ~MenuListView();

        virtual void DrawItem(const AbstractListBox &listbox, DeviceContext *dc, INT index, const Rect &item_rect) const;

    protected:
        virtual void DrawMenuItem(const MenuItem &item, DeviceContext *dc, const Rect &item_rect, BOOLEAN highlighted) const;
};

class MenuList : public AbstractMenuList {
    typedef AbstractMenuList Base;

    public:
        MenuList();

        MenuList(Window *parent);

        virtual ~MenuList();

        void Init(Window *parent);

        void AddItem(MenuItem *item, MenuItem *after = 0);

        void AddItem(MenuItem *item, Action *action) const;

        void RemoveItem(MenuItem *item);

        void RemoveAllItems() const; 

        MenuItem* GetFirstItem() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void Refresh(const Rect &rect);

        virtual void OnItemSelected();

        virtual void OnLanguageChanged();

        virtual void OnThemeChanged();

    private:
        static MenuListView m_view;

        MenuListModel* GetMyModel() const { return (MenuListModel *)GetModel(); }
        void AdjustThemeDependencies();
};

#endif  // Apoxi_MenuList_hpp


