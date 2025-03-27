/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextBox_hpp)
#define Apoxi_TextBox_hpp

#include <Gui/AbstractTextObject.hpp>

class TextBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        virtual ~TextBoxView();
        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
};

class TextBox : public AbstractTextObject {
    typedef AbstractTextObject Base;

    public:
        enum {
            ID = 24
        };

        TextBox();
        
        TextBox(Control* control, 
                const WCHAR* text = 0, 
                const TextFormat& text_format = TextFormat(),
                BOOLEAN vertical_centered = FALSE);

        virtual ~TextBox();

        void Init(Control* control,
                  const WCHAR* text = 0,
                  const TextFormat& text_format = TextFormat(),
                  BOOLEAN vertical_centered = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetVerticalCentered(BOOLEAN vertical_centered);

        BOOLEAN IsVerticalCentered() const { return m_vertical_centered; }

    private:
        BOOLEAN m_vertical_centered;
        static TextBoxView m_view;
};

#endif  // Apoxi_TextBox_hpp


