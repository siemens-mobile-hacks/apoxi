/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StrokeBox_hpp)
#define Apoxi_StrokeBox_hpp

#include <Gui/DrawableObject.hpp>

class StrokeBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        StrokeBoxView();

        virtual ~StrokeBoxView();

        void Init();

        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
};

class StrokeBox : public DrawableObject {
    public:
        typedef DrawableObject Base;
        
        StrokeBox();

        StrokeBox(Control* control);

        virtual ~StrokeBox();

        void Init(Control* control);

        void SetText(const WCHAR* text);

        const WCHAR* GetText() const { return m_text; }

        virtual XYDIM GetDefaultHeight() const;

    private:
        const WCHAR* m_text;
        static StrokeBoxView m_view;
};

#endif  // Apoxi_StrokeBox_hpp


