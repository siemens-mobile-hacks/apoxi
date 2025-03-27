/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ItemMenu_hpp)
#define Apoxi_ItemMenu_hpp

#include <Kernel/Timer.hpp>
#include <Gui/ItemGrid.hpp>
#include <Auxiliary/Vector.hpp>
#include <Gui/ItemContainer.hpp>

class ItemMenu : public ItemGrid {
    typedef ItemGrid Base;

    public:
        enum {
            ID = 13
        };

        class LevelInfo {
            public:             
                LevelInfo() : m_item_cont(0) {}
                LevelInfo(const ItemMenu& menu);
                INT GetSelectedIndex() const { return m_selected_idx; }
                INT GetFirstVisibleIndex() const { return m_first_visible_idx; }
                INT GetFirstVisibleColumn() const { return m_first_visible_column; }
                AbstractItemContainer* GetItemContainer() const { return m_item_cont; }

            private:
                INT m_selected_idx;
                INT m_first_visible_idx;
                INT m_first_visible_column;
                AbstractItemContainer* m_item_cont;
        };

        ItemMenu();

        ItemMenu(Control* parent,
                 AbstractItemContainer* item_cont = 0,
                 BOOLEAN adjust_win_title = FALSE);

        virtual ~ItemMenu();

        void Init(Control* parent,
                  AbstractItemContainer* item_cont = 0,
                  BOOLEAN adjust_win_title = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual BOOLEAN Trigger(INT index = -1);

        virtual BOOLEAN Back();

        INT GetLevel() const { return m_level; }

        const LevelInfo* GetLevelInfo(INT level);

        void SetAdjustWindowTitle(BOOLEAN flag) { m_adjust_win_title = flag; }

        BOOLEAN AdjustWindowTitle() const { return m_adjust_win_title; }

#if defined(APOXI_ENABLE_POSITION_PREVIEW)

        virtual WString GetShortcutInfo() const;
#endif
        
    protected:
        virtual void OnLevelChange(INT old_level, INT new_level);

        virtual void Refresh(const Rect& rect);
        
        virtual void Cleanup();

        virtual void OnSelectionChanged();

    private:
        BOOLEAN m_adjust_win_title;
        INT m_level;
        Vector<LevelInfo> m_level_info;
        
        void UpdateWindowTitle(const WString& title) const;
};

#endif  // Apoxi_ItemMenu_hpp

