/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractMenuList_hpp)
#define Apoxi_AbstractMenuList_hpp

#include <Gui/AbstractListBox.hpp>
#include <Auxiliary/LinkedList.hpp>


class AbstractListBox;
class Window;

// TODO: template can be avoided by using a cast and hiding this cast in a method... (peter_p)
template<class Item> class AbstractMenuListModel : public AbstractListBoxModel {
    typedef AbstractListBoxModel Base;

    public:
        AbstractMenuListModel();

        AbstractMenuListModel(INT n_items, INT selected_index);

        AbstractMenuListModel(INT n_items);

        void Init(INT n_items, INT selected_index);
        void Init(INT n_items) {
            Init(n_items, 0);
        }

        void AddItem(Item *item, Item *after);
        void AddItem(Item *item) {
            AddItem(item, 0);
        }

        void RemoveItem(Item *item);

        void RemoveAllItems();

        Item* GetFirstItem() const;

        Item* GetItemForIndex(INT index) const;

    private:
        LinkedList<Item> m_items;
};

class AbstractMenuList : public AbstractListBox {
    typedef AbstractListBox Base;

    public:
        AbstractMenuList();

        AbstractMenuList(Control *parent,
                         INT n_items = 0,
                         Behavior behavior = DefaultBehavior,
                         INT selected_index = 0);

        virtual ~AbstractMenuList();

    protected:
        virtual BOOLEAN OnSoftkeyPressed(INT idx);

        virtual BOOLEAN OnInputMap(const InputMapItem &input_map_item);

        virtual BOOLEAN OnPenUp(const Point &pen_pos);

        virtual void OnItemSelected();
};


/*  ------------------------------------------------------------------------
                            Template implementation
    ------------------------------------------------------------------------ */

/*  ------------------------------------------------------------------------
    AbstractMenuListModel
    ------------------------------------------------------------------------ */
template<class Item> AbstractMenuListModel<Item>::AbstractMenuListModel()
{
}   // AbstractMenuListModel

/*  ------------------------------------------------------------------------
    AbstractMenuListModel
    ------------------------------------------------------------------------ */
template<class Item> AbstractMenuListModel<Item>::AbstractMenuListModel(INT n_items, INT selected_index) :
    Base(n_items, selected_index)
{
}   // AbstractMenuListModel

/*  ------------------------------------------------------------------------
    AbstractMenuListModel
    ------------------------------------------------------------------------ */
template<class Item> AbstractMenuListModel<Item>::AbstractMenuListModel(INT n_items) :
    Base(n_items, 0)
{
}   // AbstractMenuListModel

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template<class Item> void AbstractMenuListModel<Item>::Init(INT n_items, INT selected_index)
{ 
    Base::Init(n_items, selected_index); 
}   // Init

/*  ------------------------------------------------------------------------
    AddItem
    ------------------------------------------------------------------------ */
template<class Item> void AbstractMenuListModel<Item>::AddItem(Item *item, Item *after)
{
    if (after == 0)
        m_items.PushBack(item);
    else
        m_items.Insert(item, after);

    SetItemCount(GetItemCount() + 1);
}   // AddItem

/*  ------------------------------------------------------------------------
    RemoveItem
    ------------------------------------------------------------------------ */
template<class Item> void AbstractMenuListModel<Item>::RemoveItem(Item *item)
{
    ASSERT_DEBUG(GetNoOfItems() > 0);

    m_items.Remove(item);
    SetItemCount(GetItemCount() - 1);
}   // RemoveItem

/*  ------------------------------------------------------------------------
    RemoveAllItems
    ------------------------------------------------------------------------ */
template<class Item> void AbstractMenuListModel<Item>::RemoveAllItems()
{   
    while (GetItemCount() > 0)
        RemoveItem(m_items.GetFront());
}   // RemoveAllItems

/*  ------------------------------------------------------------------------
    GetFirstItem
    ------------------------------------------------------------------------ */
template<class Item> Item* AbstractMenuListModel<Item>::GetFirstItem() const
{
    return m_items.GetFront();
}   // GetFirstItem

/*  ------------------------------------------------------------------------
    GetItemForIndex
    ------------------------------------------------------------------------ */
template<class Item> Item* AbstractMenuListModel<Item>::GetItemForIndex(INT index) const
{
    INT curr_index = 0;
    Item *item = m_items.GetFront();
    while ((item != 0) && (curr_index != index)) {
        item = item->GetNext();
        curr_index++;
    }

    return item;
}   // GetItemForIndex

#endif  // Apoxi_AbstractMenuList_hpp


