/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractTextObject_hpp)
#define Apoxi_AbstractTextObject_hpp

#include <Gui/Color.hpp>
#include <Gui/DrawableObject.hpp>
#include <Gui/TextFormat.hpp>

class Font;
class Control;
class View;

class AbstractTextObject : public DrawableObject {
    typedef DrawableObject Base;

    public:
        enum {
            ID = 3
        };

        AbstractTextObject();

        AbstractTextObject(Control* control,
                           const View* view,
                           const WCHAR* text = 0, 
                           const TextFormat& text_format = TextFormat());

        virtual ~AbstractTextObject();

        void Init(Control* control,
                  const View* view,
                  const WCHAR* text = 0,
                  const TextFormat& text_format = TextFormat());

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void SetText(const WCHAR* text);

        void SetText(const WString& text);

        const WString& GetText() const { return m_text; }

        virtual void SetTextFormat(const TextFormat& text_format);

        const TextFormat& GetTextFormat() const { return m_text_format; }

        virtual void SetFont(const Font& font);

        const Font& GetFont() const;

        void SetColor(const Color& color);

        const Color& GetColor() const { return m_color; }

    protected:
        virtual void OnLanguageChanged();
        
        virtual void OnThemeChanged();

    private:
        BOOLEAN m_use_default_color;
        WString m_text;
        TextFormat m_text_format;
        Color m_color;

        void InitProperties(const WCHAR* text, const TextFormat& text_format);
};

#endif  // Apoxi_AbstractTextObject_hpp

