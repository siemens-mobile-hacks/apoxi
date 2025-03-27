/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RadioButtonList_hpp)
#define Apoxi_RadioButtonList_hpp

#include <Gui/AbstractListBox.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Gui/AbstractMenuList.hpp>
#include <Gui/RadioButtonItem.hpp>
#include <Gui/RadioButton.hpp>


typedef AbstractMenuListModel<RadioButtonItem> RadioButtonListModel;

class RadioButtonList : public AbstractMenuList {
    typedef AbstractMenuList Base;

    public:
        RadioButtonList();

        RadioButtonList(Control *parent);

        virtual ~RadioButtonList();

        void Init(Control *parent);

        void AddItem(RadioButtonItem *item, RadioButtonItem *after = 0);

        void AddItem(RadioButtonItem *item, const WCHAR *text, INT value, BOOLEAN pressed = FALSE) const;

        void RemoveItem(RadioButtonItem *item);

        void RemoveAllItems() const;

        void SetPressedItem(RadioButtonItem *item);

        void SetPressedItem(INT value);

        RadioButtonItem* GetPressedItem(INT *index = 0) const;

        RadioButtonItem* GetFirstItem() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void Refresh(const Rect &rect);

        virtual BOOLEAN OnSoftkeyPressed(INT idx);

        virtual BOOLEAN OnSoftkeyReleased(INT idx);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnItemSelected();

    private:
        BOOLEAN m_item_selected;

        RadioButtonListModel* GetMyModel() const {return (RadioButtonListModel *)GetModel(); }
};

template<class Content> class TRadioButtonList : public RadioButtonList {
    typedef RadioButtonList Base;

    public:
        void AddItem(TRadioButtonItem<Content> *item, const WCHAR *text, Content content, BOOLEAN pressed = FALSE);

        void SetPressedItem(TRadioButtonItem<Content> *item) {  Base::SetPressedItem(item); }

        void SetPressedItem(Content content);

        TRadioButtonItem<Content>* GetFirstItem() const { return (TRadioButtonItem<Content>*)Base::GetFirstItem(); }

        TRadioButtonItem<Content>* GetPressedItem() const { return (TRadioButtonItem<Content>*)Base::GetPressedItem(); }

    private:
        RadioButtonListModel* GetMyModel() const { return (RadioButtonListModel *)GetModel(); }
};

class RadioButtonListView : public AbstractListBoxView {
    typedef AbstractListBoxView Base;

    public:
        RadioButtonListView();
        // Constructor of the view.
        RadioButtonListView(const RadioButtonView *view, XYDIM item_height);

        virtual ~RadioButtonListView();

        virtual void DrawItem(const AbstractListBox &listbox, DeviceContext *dc, INT index, const Rect &item_rect) const;

    protected:
        const RadioButtonView *m_view;

        virtual void DrawRadioButtonItem(const RadioButtonItem &item, DeviceContext *dc, const Rect &item_rect, BOOLEAN highlighted) const = 0;

};

/*  ------------------------------------------------------------------------
                            Template implementation
    ------------------------------------------------------------------------ */

/*  ------------------------------------------------------------------------
    AddItem
    ------------------------------------------------------------------------ */
template<class Content> void TRadioButtonList<Content>::AddItem(TRadioButtonItem<Content> *item,
                                                                const WCHAR *text, Content content,
                                                                BOOLEAN pressed)
{
    Base::AddItem(item, text, 0, pressed);
    item->SetContent(content);
}   // AddItem

/*  ------------------------------------------------------------------------
    SetPressedItem
    ------------------------------------------------------------------------ */
template<class Content> void TRadioButtonList<Content>::SetPressedItem(Content content)
{
    TRadioButtonItem<Content> *item = GetFirstItem();
    INT index = 0;

    while (item != 0) {
        if (item->GetContent() == content) {
            item->SetPressed(TRUE);
            GetMyModel()->SetSelectedIndex(index);
            return;
        }
        item = (TRadioButtonItem<Content>*)item->GetNext();
        index++;
    }

    ASSERT(FALSE);
}   // SetPressedItem

#endif  // Apoxi_RadioButtonList_hpp


