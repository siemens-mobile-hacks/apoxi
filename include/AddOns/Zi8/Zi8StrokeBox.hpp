/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_Zi8StrokeBox_hpp)
#define Apoxi_Zi8StrokeBox_hpp

#include <Gui/DrawableObject.hpp>

#define MAX_STROKE_COUNT 20

class Zi8StrokeBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        Zi8StrokeBoxView();

        virtual ~Zi8StrokeBoxView();

        void Init();

        virtual void Draw(const Component &component, 
                          DeviceContext *dc, 
                          const Rect &repaint_rect) const;
};

class Zi8StrokeBox : public DrawableObject {
    public:
        typedef DrawableObject Base;
        
        Zi8StrokeBox();

        Zi8StrokeBox(Control *control);

        virtual ~Zi8StrokeBox();

        void Init(Control *control);

        void SetText(const WCHAR *text);

        const WCHAR* GetText() const { return m_text; }

        virtual XYDIM GetDefaultHeight() const;

    private:
        const WCHAR *m_text;
        static Zi8StrokeBoxView m_view;
};

#endif  // Apoxi_Zi8StrokeBox_hpp


