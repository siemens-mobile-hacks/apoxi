/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractGrid_hpp)
#define Apoxi_AbstractGrid_hpp

class ResourceParser;
#include <Gui/Control.hpp>
#include <Gui/PositionIndicator.hpp>
#include <Gui/ScrollBehavior.hpp>
#include <Kernel/Timer.hpp>

class AbstractGrid : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 1
        };

        enum MoveDirection {
            Left,
            Right,
            Up,
            Down,
            PageUp,
            PageDown,
        };

        class SmoothScrollInfo {
            public:
                SmoothScrollInfo();
                ~SmoothScrollInfo();

                BOOLEAN IsSelector() const { return (BOOLEAN)m_flags.is_selector; }

                BOOLEAN IsHorizontal() const { return (BOOLEAN)m_flags.is_horizontal; }

                BOOLEAN IsMirrored() const { return (BOOLEAN)m_flags.is_mirrored; }

                const Timer& GetTimer() const { return m_timer; }

                XYDIM GetDiff() const { return (XYDIM)m_diff; }

                XYDIM GetInc() const { return (XYDIM)m_inc; }

            private:
                struct {
                    UINT is_selector    : 1;
                    UINT is_horizontal  : 1;
                    UINT is_mirrored    : 1;
                } m_flags;
                Timer m_timer;
                INT8 m_diff;
                INT8 m_inc;

            friend class AbstractGrid;
        };

        AbstractGrid(Control* parent = 0);
        
        virtual ~AbstractGrid();

        void Init(Control* parent = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        virtual void SetSelectedIndex(INT idx);
        
        virtual void MoveSelectedIndex(MoveDirection move_dir);

        INT GetSelectedIndex() const;

        void SetFirstVisibleIndex(INT idx, BOOLEAN respect_scroll_gap = TRUE);

        INT GetFirstVisibleIndex() const { return m_first_visible_idx; }

        INT GetLastVisibleIndex() const;

        INT GetLastCompleteVisibleIndex() const;

        INT GetVisibleRowCount() const;

        INT GetCompleteVisibleRowCount() const;

        Rect GetCellRect(INT idx) const;

        virtual INT GetCellCount() const = 0;

        virtual INT GetColumnCount() const = 0;

        virtual XYDIM GetCellHeight() const = 0;

        INT GetRowCount() const;

        virtual XYDIM GetCellWidth() const;

        void SetFirstVisibleColumn(INT column);
        
        INT GetFirstVisibleColumn() const { return m_first_visible_column; }
        
        virtual BOOLEAN HasHeader() const;

        virtual XYDIM GetHeaderHeight() const;

        virtual XYDIM GetSelectionHeight() const;

        Rect GetHeaderRect(INT column_idx) const;

        virtual BOOLEAN IsPositionIndicatorShown() const;

        virtual ScrollBehavior GetScrollBehavior() const;

        const SmoothScrollInfo* GetSmoothScrollInfo() const;
    
    protected:
        virtual void Refresh(const Rect& rect);     

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnKeyAutoRepeat(KeyCode key_code);

        virtual void OnLayoutClient();

        virtual void OnPaint(const Rect& repaint_rect);

        virtual void OnThemeChanged();

        virtual void OnSelectionChanged();

        virtual BOOLEAN OnTimeout(const Timer& timer);
        
        virtual void OnGetFocus();

        void AssureVisibleSelection(BOOLEAN respect_scroll_gap = TRUE);

        void UpdatePositionIndicator();

        BOOLEAN IsPositionIndicatorLeftAligned() const;

        void DrawPositionIndicator(const Rect& repaint_rect);

        INT GetSelectedIndexProperty() const { return m_selected_idx; }

        void UpdateNavigationGuidance();

        void CancelSmoothScrolling(INT new_selected_idx);

    private:
        INT m_selected_idx;
        INT m_first_visible_idx;
        INT m_first_visible_column;
        PositionIndicator m_pos_ind;
#ifdef APOXI_ENABLE_SMOOTH_SCROLLING
        SmoothScrollInfo m_smooth_scroll_info;
#endif

        INT GetCompleteVisibleCellCount() const;
        INT GetVisibleCellCount() const;
        INT GetRowOfIndex(INT idx) const;
        void AdjustCellWidth(XYDIM& cell_width) const;

        void EnlargeGridSelection(Rect& cell_rect) const;

        BOOLEAN TreatKeyCode(KeyCode key_code);
        void CenterSelection(INT complete_visible_cell_count);
        void TreatScrollGap();
        void InitProperties();
#ifdef APOXI_ENABLE_SMOOTH_SCROLLING
        void InvalidateSmoothAnim(BOOLEAN up);
#endif
};

#endif  // Apoxi_AbstractGrid_hpp


