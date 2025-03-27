/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_AtlItemGridWindow_hpp)
#define Atl_Gui_AtlItemGridWindow_hpp

#include <Gui/ItemMenu.hpp>
#include <Atl/Context/ContextID.hpp>
#include <Atl/AtlWindow.hpp>

class AtlItemGridWindow : public AtlWindow {
    typedef AtlWindow Base;

    public:

        enum {
            ID = 42
        };

        AtlItemGridWindow();

        AtlItemGridWindow(ItemGrid* item_grid);

        virtual ~AtlItemGridWindow();

        void Init(ItemGrid* item_grid = 0);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        Item* GetSelectedItem() const { return m_item_grid->GetSelectedItem(); }

        INT GetSelectedIndex() const { return m_item_grid->GetSelectedIndex(); }

        void SetSelectedIndex(INT idx);

        virtual const ContextID& GetContextId() const;

    protected:

        virtual void OnOpen();
      

        virtual void OnClose();


        virtual void OnGetFocus();
        
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnSelectionChanged();

        virtual void ApplyContext();

        INT GetCurrentDisplayType();

        const ContextID& GetWindowContextId() const { return Base::GetContextId(); }
        

    private:

        void TriggerSelectedItem();
        BOOLEAN ContextAffected(const Item* changed_item, INT property_id) const;

        ItemGrid*   m_item_grid;
        INT         m_predefined_selection;
};

#endif  // Atl_Gui_AtlItemGridWindow_hpp

