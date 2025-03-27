/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Kernel_Grid_hpp)
#define Kernel_Grid_hpp

#include <Kernel/Types.hpp>
#include <Gui/Control.hpp>
#include <Gui/Model.hpp>
#include <Gui/View.hpp>
#include <Gui/PositionIndicator.hpp>
#include <Gui/AbstractListBox.hpp>

enum {
    DefaultBehaviour = 0,
    BlockScrollBehaviour = 1,
    NoSelectionBehaviour = 2,
    NoHighlightningBehaviour = 4,
    RotateBehaviour = 8
};

enum RepaintHint {
    NoRepaintHint,
    TopReachedRepaintHint,
    BottomReachedRepaintHint,
    MovedLeftRepaintHint,
    MovedRightRepaintHint,
    MovedUpRepaintHint,
    MovedDownRepaintHint
};

typedef UINT Behaviour;

enum SelectionMode {
    Horizontal,
    Vertical
};

class Cell {
    public:
        Cell(INT column = 0, XYDIM row = 0);

        Cell(const Cell &row);

        void SetColumn(INT column) { m_column = column; }

        INT GetColumn() const { return m_column; }

        void SetRow(INT row) {  m_row = row; }

        INT GetRow() const {    return m_row; }

        BOOLEAN IsEqual(const Cell *cell) const;

        BOOLEAN IsLess(const Cell *cell) const;

        BOOLEAN IsGreater(const Cell *cell) const;

    private:
        INT m_column;
        INT m_row;
};

class GridModel : public AbstractListBoxModel {
    typedef AbstractListBoxModel Base;
    public:
        GridModel();
        GridModel(INT n_columns, INT n_rows, Behaviour behaviour = DefaultBehaviour, 
                  const Cell &selected_cell = Cell());

        virtual ~GridModel() {}

        void Init(INT n_columns, INT n_rows, Behaviour behaviour = DefaultBehaviour, 
                  const Cell &selected_cell = Cell());

        void SetSelectedCell(const Cell &cell);

        Cell GetSelectedCell() const { return m_selected_cell; };

        INT GetNoOfCells() const { return (m_n_rows * m_n_columns); };

        void SetNoOfColumns(INT n_columns);

        INT GetNoOfColumns() const { return m_n_columns; };

        void SetNoOfRows(INT n_rows);

        INT GetNoOfRows() const { return m_n_rows; };

        void SetColumnTitled(BOOLEAN column_titled);

        BOOLEAN IsColumnTitled() const { return m_column_titled; };

        void SetRowTitled(BOOLEAN row_titled);

        BOOLEAN IsRowTitled() const { return m_row_titled; };

        void SetFirstCell(const Cell &cell);

        Cell GetFirstCell() const { return m_first_cell; };

        void SetLastCell(const Cell &cell);

        Cell GetLastCell() const { return m_last_cell; };

        void SetSelectionMode(SelectionMode mode) { m_selection_mode = mode; };

        SelectionMode GetSelectionMode() const { return m_selection_mode; };

        void SetBehaviour(Behaviour behaviour) { m_behaviour = behaviour; };

        Behaviour GetBehaviour() const { return m_behaviour; };

        void SetFirstVisibleRow(INT row);

        INT GetFirstVisibleRow() const { return m_first_visible_row; };

        void SetRepaintHint(RepaintHint hint) { m_hint = hint; };

        INT GetRepaintHint() const { return m_hint; };

        //void SetPositionIndicator(PositionIndicator *position_indicator) { m_position_indicator = *position_indicator; };

        PositionIndicator* GetPositionIndicator() { return &m_position_indicator; };

        void SetMaxVisibleRows(INT max_visible_rows);

        INT GetMaxVisibleRows() const { return m_max_visible_rows; }; 

        BOOLEAN IsIndicatorFullsized() const { return (m_first_visible_row == 0 || IsColumnTitled()) && (m_max_visible_rows >= m_n_rows); };

        //cell manipulation and checking functions:
        //infos about data in the model is needed
        BOOLEAN IncrementCell(Cell *cell, BOOLEAN select) const;

        BOOLEAN DecrementCell(Cell *cell, BOOLEAN select) const;

        BOOLEAN IsFirstCell(const Cell *cell) const;

        BOOLEAN IsLastCell(const Cell *cell) const;

        BOOLEAN IsSelectableCell(const Cell *cell) const;

    private:
        BOOLEAN             m_column_titled;
        BOOLEAN             m_row_titled;
        INT                 m_n_columns;
        INT                 m_n_rows;
        INT                 m_first_visible_row;
        INT                 m_max_visible_rows;
        Behaviour           m_behaviour;            // TODO: Behaviour part of model? Shouldn't it be part of the control?
        RepaintHint         m_hint;
        PositionIndicator   m_position_indicator;
        Cell                m_first_cell;
        Cell                m_last_cell;
        Cell                m_selected_cell;
        SelectionMode       m_selection_mode;

};

class GridView : public View {
    typedef View Base;

    public:
        GridView();
        GridView(XYDIM cell_width, XYDIM cell_height, XYDIM pos_indicator_width);

        virtual ~GridView();

        void SetCellHeight(XYDIM cell_height) { m_cell_height = cell_height; m_col_title_height = cell_height; };

        XYDIM GetCellHeight() const { return m_cell_height; };

        void SetCellWidth(XYDIM cell_width) { m_cell_width = cell_width; m_row_title_width = cell_width; };

        XYDIM GetCellWidth() const { return m_cell_width; };

        void SetColTitleHeight(XYDIM height) {m_col_title_height = height; };

        XYDIM GetColTitleHeight() const { return m_col_title_height; };

        void SetRowTitleWidth(XYDIM width) {m_row_title_width = width; };

        XYDIM GetRowTitleWidth() const { return m_row_title_width; };

        void SetPosIndicatorWidth(XYDIM pos_indicator_width) { m_pos_indicator_width = pos_indicator_width; }

        XYDIM GetPosIndicatorWidth() const { return m_pos_indicator_width; }

        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;

        virtual void DrawCell(const GridModel &model, DeviceContext *dc, const Cell &cell, BOOLEAN highlighted = FALSE) const;

        virtual void DrawCellPreHighlighted(const GridModel &model, DeviceContext *dc, const Cell &cell) const;

        virtual void DrawCellPostHighlighted(const GridModel &model, DeviceContext *dc, const Cell &cell) const;

        INT GetLastVisibleRow(const GridModel &model, const DeviceContext &dc) const;

        INT GetLastCompletelyVisibleRow(const GridModel &model, const DeviceContext &dc) const;

        Rect GetCellRect(const GridModel &model, const DeviceContext &dc, const Cell &cell) const;

        XYDIM GetCellXPos(const GridModel &model, const DeviceContext &dc, const Cell &cell) const;

        XYDIM GetCellYPos(const GridModel &model, const DeviceContext &dc, const Cell &cell) const;

    private:
        XYDIM m_cell_width;
        XYDIM m_cell_height;
        XYDIM m_row_title_width;
        XYDIM m_col_title_height;
        XYDIM m_pos_indicator_width;
        
        void DrawCellHighlighted(const GridModel &model, DeviceContext *dc, const Cell &cell) const;
        void DrawPositionIndicator(GridModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

class Grid : public Control {
    public:     
        typedef Control Base;

        Grid();

        Grid(Control *parent, INT columns, INT rows,
             Behaviour behaviour = DefaultBehaviour,
             const Cell &selected_cell = Cell());

        virtual ~Grid();

        void Init(Control *parent, INT columns, INT rows, 
                  Behaviour behaviour = DefaultBehaviour,
                  const Cell &selected_cell = Cell());

        void SetSelectedCell(const Cell &cell);

        Cell GetSelectedCell() const;

        INT GetNoOfCells() const;

        void SetNoOfColumns(INT n_columns);

        INT GetNoOfColumns() const;

        void SetNoOfRows(INT n_rows);

        INT GetNoOfRows() const;

        void SetColumnTitled(BOOLEAN column_titled);

        BOOLEAN IsColumnTitled() const;

        void SetRowTitled(BOOLEAN row_titled);

        BOOLEAN IsRowTitled() const;

        void SetFirstCell(const Cell &cell);

        Cell GetFirstCell() const;

        void SetLastCell(const Cell &cell);

        Cell GetLastCell() const;

        void SetSelectionMode(SelectionMode mode);

        SelectionMode GetSelectionMode() const;

        virtual void SetWidth(XYDIM width);

        virtual void SetHeight(XYDIM height);

        virtual void SetSize(const Size &size);

        void SetSize(XYDIM width, XYDIM height) { SetSize(Size(width, height)); }

    protected:
        virtual Model* CreateModel() const;

        virtual void Refresh(const Rect &rect);

        virtual BOOLEAN OnInputMap(const InputMapItem &input_map_item);

        virtual void OnMoveLeft();

        virtual void OnMoveRight();

        virtual void OnMoveUp();

        virtual void OnMoveDown();

        virtual void OnSelectionChanged() {}

        virtual void OnThemeChanged();
        
        void AdjustThemeDependencies();

    private:
        GridModel* GetMyModel() const { return (GridModel *)GetModel(); }
};
    


#endif // Kernel_Grid_hpp


