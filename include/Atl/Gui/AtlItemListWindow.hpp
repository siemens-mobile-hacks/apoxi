/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_AtlItemListWindow_hpp)
#define Atl_Gui_AtlItemListWindow_hpp

#include <Gui/ItemGrid.hpp>
#include <Atl/Gui/AtlItemGridWindow.hpp>

class AtlItemListWindow : public AtlItemGridWindow {
    typedef AtlItemGridWindow Base;

    public:
         enum {
            ID = 41
         };

        AtlItemListWindow();

        AtlItemListWindow(AbstractItemContainer* item_container);

        virtual ~AtlItemListWindow();

        void Init(AbstractItemContainer* item_container = 0);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetItemContainer(AbstractItemContainer* item_container);

        AbstractItemContainer* GetItemContainer() const { return m_item_list.GetItemContainer(); }

        void SetSelectedRow(INT idx);

        INT GetSelectedRow() const { return GetSelectedIndex(); }
        
        ItemGrid& GetList() { return m_item_list; }
        
    protected:
        virtual void OnOpen();

        virtual void OnSelectionChanged();

    private:        
        void UpdateContainerItems(const ItemContainer* item_cont);
        ItemGrid        m_item_list;
};

#endif  // Atl_Gui_AtlItemListWindow_hpp

