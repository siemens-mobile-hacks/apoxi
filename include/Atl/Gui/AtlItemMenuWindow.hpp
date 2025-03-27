/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_AtlItemMenuWindow_hpp)
#define Atl_Gui_AtlItemMenuWindow_hpp

#include <Gui/ItemMenu.hpp>
#include <Atl/Context/ContextID.hpp>
#include <Atl/Features/MenuID.hpp>
#include <Atl/Gui/AtlItemGridWindow.hpp>
#include <Atl/Context/MenuProperties.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Features/TriggerKeyFeature.hpp>
#include <Atl/Context/MenuDesc.hpp>
#endif  // APOXI_COMPAT_2_7_0

class AtlItemMenuWindow : public AtlItemGridWindow {
    typedef AtlItemGridWindow Base;

    public:

        enum {
            ID = 40
        };

        AtlItemMenuWindow();

        AtlItemMenuWindow(const MenuID& menu_id);

        virtual ~AtlItemMenuWindow();

        void Init();

        void Init(const MenuID& menu_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetMenuID(const MenuID& menu_id);

        const MenuID& GetMenuID() { return m_menu_id; }
            
        void SetParentWindow(Window* win) { m_parent_win = win; }

        INT GetMenuType() {return m_menu_type;}


    protected:

            
        virtual void OnOpen();
      
        virtual void OnLoseFocus();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnSelectionChanged();

        virtual void OnContextSwitched();
        
        ItemMenu* GetMenu() { return &m_item_menu; }

        void TriggerMenuItem(INT idx);

        virtual void ApplyContext();

    private:
        void UpdateMenuProperties();
        void CalcPopupWindowSize();
        INT GetPressedNumber(KeyCode key_code);

        BOOLEAN ItemContainerAffected(const Item* changed_item, INT property_id) const;
        void CheckTitle();
        void VerifyItemContainerTitle();

        
        MenuID      m_menu_id;
        Window*     m_parent_win;

        ItemMenu    m_item_menu;

        MenuProperties::MenuType    m_menu_type;
        MenuProperties::TitleTextType m_title_type;

        BOOLEAN     m_close_after_trigger;
};

#endif  // Atl_Gui_AtlItemMenuWindow_hpp

