/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_T9PinyinBox_hpp)
#define Apoxi_T9PinyinBox_hpp

#include <Gui/DrawableObject.hpp>

class T9PinyinBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        T9PinyinBoxView();

        virtual ~T9PinyinBoxView();

        void Init();

        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
};

class T9PinyinBox : public DrawableObject {
    public:
        typedef DrawableObject Base;
        
        T9PinyinBox();

        T9PinyinBox(Control* control);

        virtual ~T9PinyinBox();

        void Init(Control* control);
        
        void SetText(const WCHAR* text, INT selected_idx = -1);

        const WCHAR* GetText(INT* selected_idx = 0) const;

        virtual XYDIM GetDefaultHeight() const;

    private:
        const WCHAR* m_text;
        INT         m_selected_idx;
        
        static T9PinyinBoxView m_view;
};

#endif  // Apoxi_T9PinyinBox_hpp


