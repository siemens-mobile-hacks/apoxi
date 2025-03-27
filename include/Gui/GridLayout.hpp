/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GridLayout_hpp)
#define Apoxi_GridLayout_hpp

class Component;
#include <Gui/Control.hpp>
#include <Gui/PositionIndicator.hpp>

class GridLayout : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 15
        };

        enum XAlign {
            XDefault,
            Left,
            Center,
            Right
        };

        enum YAlign {
            YDefault,
            Top,
            Middle,
            Bottom
        };

        enum StretchUnit {
            //  Default: Remaining space is used
            Default,
            Percent,
            Pixel
        };

        GridLayout();

        GridLayout(Control* parent, INT row_count, INT col_count = 1, Size min_size = Size(-1, -1));
        
        virtual ~GridLayout();

        void Init(Control* parent, INT row_count, INT col_count = 1, Size min_size = Size(-1, -1));
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetCellProperties(INT row, INT col, Component* component, XAlign x_align = XDefault, YAlign y_align = YDefault);

        void SetColumnProperty(INT col, StretchUnit stretch_unit, INT value = 0);

        void SetRowProperty(INT row, StretchUnit stretch_unit, INT value = 0);

        virtual Rect GetClientRect() const;

        Size GetCellSize(INT row, INT column) const;

        INT GetRowCount() const { return m_rows; }

        INT GetColumnCount() const { return m_cols; }

    protected:
        virtual void OnLayoutClient();

        virtual void OnGetFocus();
        
        virtual void OnFocusPreviousControl();
        
        virtual void OnFocusNextControl();

        virtual void OnThemeChanged();
        
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnKeyAutoRepeat(KeyCode key_code);

    private:
        struct Cell {
            Component* component;
            XAlign  x_align;
            YAlign  y_align;
        };

        struct LayouterProperties {
            StretchUnit unit;
            INT value;
        };
    
        struct {
            UINT initialized            : 1;
            UINT rows_initialized       : 1;
            UINT columns_initialized    : 1;
            UINT vert_pos_ind_needed    : 1;
            UINT horiz_pos_ind_needed   : 1;
        } m_bits;

        Vector<Cell> m_cells;
        Vector<LayouterProperties> m_row_properties;
        Vector<LayouterProperties> m_col_properties;

        INT m_cols;
        INT m_rows;

        XYDIM m_x_pos;
        XYDIM m_y_pos;

        Size m_min_size;
        PositionIndicator m_vert_pos_ind;
        PositionIndicator m_horiz_pos_ind;
        
        KeyCode m_key_code;

        WString GetStretchDescr(XYDIM pixels, INT sections, const Vector<LayouterProperties>& properties) const;
        void InitProperties(INT rows, INT cols);
        void AssureVisibleFocus();
        void UpdatePositionIndicators();
        BOOLEAN TreatKeyCode(KeyCode key_code);
        BOOLEAN FindCellPos(const Component& comp, INT& column, INT& row) const;
        void UpdateNavigationGuidance();

        BOOLEAN IsCellFocusable(INT column, INT row) const;

        BOOLEAN ShowBorder(INT column, INT row) const;
};

#if defined(APOXI_COMPAT_2_4_0)
    #if !defined(LayouterControl)
        #define LayouterControl GridLayout
    #endif
#endif

#endif  //Apoxi_GridLayout_hpp

