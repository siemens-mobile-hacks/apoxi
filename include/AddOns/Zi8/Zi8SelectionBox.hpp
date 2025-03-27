/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Zi8SelectionBox_hpp)
#define Apoxi_Zi8SelectionBox_hpp

#include <Gui/DrawableObject.hpp>
#include <Gui/PredInputMapper.hpp>

class Zi8SelectionBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        Zi8SelectionBoxView();

        virtual ~Zi8SelectionBoxView();

        void Init();

        virtual void Draw(const Component &component, 
                          DeviceContext *dc, 
                          const Rect &repaint_rect) const;
};

class Zi8SelectionBox : public DrawableObject {
    public:
        typedef DrawableObject Base;
        
        Zi8SelectionBox();

        Zi8SelectionBox(Control *control);

        virtual ~Zi8SelectionBox();

        void Init(Control *control);

        void SetText(const WCHAR *text);        
        
        const WCHAR* GetText() const;
        
        void SetSelectedIndex(INT selected_idx) { m_selected_idx = selected_idx; }
        
        INT GetSelectedIndex() const { return m_selected_idx; }

        void SetPageFlag(BOOLEAN prev_page, BOOLEAN next_page);

        void GetPageFlag(BOOLEAN *prev_page, BOOLEAN *next_page) const;

        virtual XYDIM GetDefaultHeight() const;

    private:
        INT                 m_selected_idx;
        BOOLEAN             m_prev_page, m_next_page;
        const WCHAR         *m_text;

        static Zi8SelectionBoxView m_view;
};


#endif  // Apoxi_Zi8SelectionBox_hpp


