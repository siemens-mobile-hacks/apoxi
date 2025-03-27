/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractListBox_hpp)
#define Apoxi_AbstractListBox_hpp

#include <Kernel/Types.hpp>
#include <Gui/Control.hpp>
#include <Gui/Model.hpp>
#include <Gui/View.hpp>
#include <Gui/PositionIndicator.hpp>
#include <Gui/ScrollBehavior.hpp>

class AbstractListBox;

class AbstractListBoxModel : public Model {
    typedef Model Base;

    public:
        AbstractListBoxModel();

        AbstractListBoxModel(INT item_count);

        virtual ~AbstractListBoxModel();

        void Init(INT item_count);

        void SetItemCount(INT item_count);

        INT GetItemCount() const { return m_item_count; };

        void SetListBox(AbstractListBox* list_box) { m_list_box = list_box; }

        AbstractListBox* GetListBox() const { return m_list_box; }

        void SetNoOfItems(INT item_count) {
            DBG_OUT((5003, L"Obsolete - AbstractListBox::SetNoOfItems(). Use SetItemCount() instead.\n"));
            SetItemCount(item_count);
        }

        INT GetNoOfItems() const { 
            DBG_OUT((5003, L"Obsolete - AbstractListBox::GetNoOfItems(). Use GetItemCount() instead.\n"));
            return GetItemCount();
        }

        AbstractListBoxModel(INT item_count, INT selected_index);

        void Init(INT item_count, INT selected_index);

        void SetSelectedIndex(INT index);

        INT GetSelectedIndex() const;

        void SetFirstVisibleIndex(INT index);

        INT GetFirstVisibleIndex() const;

        void SetMaxVisibleItems(INT max_visible_items);

        INT GetMaxVisibleItems() const;

    private:
        INT m_item_count;
        AbstractListBox *m_list_box;
};

class AbstractListBox : public Control {
    typedef Control Base;

    public:     
        class SmoothScrollInfo {
        public:
            BOOLEAN IsSelector() const { return m_is_selector; }

            const Timer& GetTimer() const { return m_timer; }

            XYDIM GetDiff() const { return (XYDIM)m_diff; }

            XYDIM GetInc() const { return (XYDIM)m_inc; }

        private:
            BOOLEAN m_is_selector;
            Timer m_timer;
            INT8 m_diff;
            INT8 m_inc;

            friend class AbstractListBox;
        };

        AbstractListBox();

        AbstractListBox(Control* parent);

        virtual ~AbstractListBox();

        void Init(Control* parent);

        void SetSelectedIndex(INT index);

        INT GetSelectedIndex() const;

        void SetFirstVisibleIndex(INT index);

        INT GetFirstVisibleIndex() const { return m_first_visible_idx; }

        INT GetLastVisibleIndex() const;

        void SetItemCount(INT item_count);

        INT GetItemCount() const;

        void SetItemHeight(XYDIM item_height) { m_item_height = (INT8)item_height; };

        XYDIM GetItemWidth() const;

        XYDIM GetItemHeight() const;

        INT GetMaxVisibleItems() const;

        const PositionIndicator& GetPositionIndicator() const { return m_pos_ind; }

        virtual BOOLEAN IsPositionIndicatorShown() const;
    
        virtual ScrollBehavior GetScrollBehavior() const;

        void SetFocusPassingEnabled(BOOLEAN flag) { m_focus_passing_enabled = flag; }

        BOOLEAN IsFocusPassingEnabled() const { return m_focus_passing_enabled; }

        void SetNoOfItems(INT item_count) { SetItemCount(item_count); }

        INT GetNoOfItems() const { return GetItemCount(); }

        AbstractListBox(Control* parent,
                        INT item_count,
                        ScrollBehavior behavior,
                        INT selected_index = 0);

        void Init(Control* parent,
                  INT item_count,
                  ScrollBehavior behavior,
                  INT selected_index = 0);

        void SetBehavior(Behavior behavior);

        Behavior GetBehavior() const;

        const SmoothScrollInfo* GetSmoothScrollInfo() const;

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void OnLayoutClient();

        virtual void OnResize(XYDIM dx, XYDIM dy);

        virtual BOOLEAN OnInputMap(const InputMapItem& input_map_item);

        virtual BOOLEAN OnPenDown(const Point& pen_pos);

        virtual void OnPreviousItem();

        virtual void OnNextItem();

        virtual void OnSelectionChanged();

        virtual void OnThemeChanged();

        virtual void OnPaint(const Rect& repaint_rect);

        virtual BOOLEAN OnTimeout(const Timer& timer);

        void UpdatePositionIndicator();

        void IndicateSelectionChanged();

        void InvalidateSelectedItem();

    private:
        INT                 m_selected_idx;
        INT                 m_first_visible_idx;
        BOOLEAN             m_focus_passing_enabled;
        INT8                m_item_height;
        PositionIndicator   m_pos_ind;
#ifdef APOXI_ENABLE_SMOOTH_SCROLLING
        SmoothScrollInfo    m_smooth_scroll_info;
#endif

        AbstractListBoxModel* GetMyModel() const { return (AbstractListBoxModel* )GetModel(); }

        INT GetLastCompleteVisibleIndex() const;

        INT GetMaxCompleteVisibleItems() const;

        void AdjustThemeDependencies();

        ScrollBehavior GetInterpretedScrollBehavior() const;

        void InitProperties();
};

class AbstractListBoxView : public View {
    typedef View Base;

    public:
        AbstractListBoxView();
        
        AbstractListBoxView(XYDIM default_item_height);

        void Init(XYDIM default_item_height);
        
        virtual ~AbstractListBoxView() {};

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        virtual void DrawItem(const AbstractListBox& listbox, DeviceContext* dc, INT index, const Rect& item_rect) const;

        Rect GetItemRect(const AbstractListBox& listbox, INT index) const;

        void SetDefaultItemHeight(XYDIM default_item_height) { m_default_item_height = default_item_height; };

        XYDIM GetDefaultItemHeight() const { return m_default_item_height; };

        BOOLEAN IsBackgrDrawingEnabled() const { return m_backgr_drawing; } 

    private:
        mutable BOOLEAN m_backgr_drawing;
        XYDIM m_default_item_height;
};

#endif // Apoxi_AbstractListBox_hpp


