/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextLine_hpp)
#define Apoxi_TextLine_hpp

#include <Gui/Color.hpp>
#include <Gui/AbstractTextObject.hpp>

class TextLineView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        TextLineView();
        virtual ~TextLineView();
        void Init();
        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
};

class TextLine : public AbstractTextObject {
    typedef AbstractTextObject Base;

    public:
        enum {
            ID = 25
        };

        TextLine();

        TextLine(Control* control, 
                 const WCHAR* text = 0, 
                 const TextFormat& text_format = TextFormat());

        virtual ~TextLine();

        void Init(Control* control,
                  const WCHAR* text = 0,
                  const TextFormat& text_format = TextFormat());

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

    private:
        static TextLineView m_view;
};

#endif  // Apoxi_TextLine_hpp


