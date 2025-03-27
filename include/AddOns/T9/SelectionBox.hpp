/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SelectionBox_hpp)
#define Apoxi_SelectionBox_hpp

#include <Gui/DrawableObject.hpp>
#include <Gui/PredInputMapper.hpp>
class SelectionBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        SelectionBoxView();

        virtual ~SelectionBoxView();

        void Init();

        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
};

class SelectionBox : public DrawableObject {
    public:
        typedef DrawableObject Base;
        
        SelectionBox();

        SelectionBox(Control* control);

        virtual ~SelectionBox();

        void Init(Control* control);

        void SetText(const WCHAR* text);        
        
        const WCHAR* GetText() const { return m_text; }
        
        void SetSelectedIndex(INT selected_idx) { m_selected_idx = selected_idx; }
        
        INT GetSelectedIndex() const { return m_selected_idx; }

        virtual XYDIM GetDefaultHeight() const;

    private:
        const WCHAR* m_text;
        INT m_selected_idx;

        static SelectionBoxView m_view;
};

#endif  // Apoxi_SelectionBox_hpp


