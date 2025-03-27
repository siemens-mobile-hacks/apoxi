/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Layouter_hpp)
#define Apoxi_Layouter_hpp


class DeviceContext;
class Component;

class Layouter {
    public:
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
            Percent,
            Pixel
        };

        Layouter(INT x_cells,
                 INT y_cells,
                 DeviceContext* dc = 0,
                 XAlign x_align = XDefault,
                 YAlign y_align = YDefault);

        Layouter(INT x_cells,
                 INT y_cells,
                 const Control* control,
                 XAlign x_align = XDefault,
                 YAlign y_align = YDefault);

        Layouter(INT x_cells,
                 INT y_cells,
                 const Rect& bounding_rect,
                 XAlign x_align = XDefault,
                 YAlign y_align = YDefault);

        void Arrange(INT x_idx,
                     INT y_idx,
                     Component* content,
                     XAlign x_align = XDefault,
                     YAlign y_align = YDefault);

        void Arrange(INT x_idx,
                     INT y_idx,
                     Layouter* layouter);

        void StretchXGrid(const WCHAR* stretch_descr, StretchUnit unit = Percent);

        void StretchYGrid(const WCHAR* stretch_descr, StretchUnit unit = Percent);

        Size GetCellSize(INT row, INT column) const;

    private:
        /* Target-Compiler makes problems when using this slim structure:
        struct {
            UINT x_align           : 2;
            UINT y_align           : 2;
            UINT x_cells           : 5;
            UINT y_cells           : 5;
            UINT x_stretch_unit : 1;
            UINT y_stretch_unit : 1;
        } m_bits;
        */

        XYDIM m_x_pos;
        XYDIM m_y_pos;
        XYDIM m_cell_width;
        XYDIM m_cell_height;

        INT m_x_cells;
        INT m_y_cells;

        XAlign m_x_align;
        YAlign m_y_align;
    
        const WCHAR* m_x_stretch_descr;
        const WCHAR* m_y_stretch_descr;
        StretchUnit m_x_stretch_unit;
        StretchUnit m_y_stretch_unit;

        XYDIM GetCellWidth(INT index) const;
        XYDIM GetCellHeight(INT index) const;
        XYDIM GetPixelCount(INT index, BOOLEAN horizontal) const;
        XYDIM GetContentXPos(XAlign x_align, INT x_idx, XYDIM content_width) const;
        XYDIM GetContentYPos(YAlign y_align, INT y_idx, XYDIM content_height) const;
        void AssureValidCellSize();
};

#endif  // Apoxi_Layouter_hpp


