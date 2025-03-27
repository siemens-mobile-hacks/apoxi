/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RadioButtonItem_hpp)
#define Apoxi_RadioButtonItem_hpp


class RadioButtonItem : public Linkable<RadioButtonItem> {
    public:
        RadioButtonItem(const WCHAR *text = 0, BOOLEAN pressed = FALSE) :
            m_text(text), m_pressed(pressed) {}

        // Sets the text of the item.
        void SetText(const WCHAR *text) { m_text = text; };

        // Returns the text of the item.
        const WCHAR* GetText() const { return m_text; };

        // Sets the selection of the item.
        void SetPressed(BOOLEAN pressed) { m_pressed = pressed; };

        // Returns <b>TRUE</b>, if the checkbox is pressed.
        BOOLEAN IsPressed() const { return m_pressed; };

        void SetValue(INT value) { m_value = value; }

        INT GetValue() { return m_value; }

    private:
        const WCHAR *m_text;
        BOOLEAN     m_pressed;
        INT         m_value;
};

template<class Content> class TRadioButtonItem : public RadioButtonItem {
    public:
        typedef RadioButtonItem Base;

        TRadioButtonItem() : Base(0, FALSE) {}
        TRadioButtonItem(const WCHAR *text) : Base(text, FALSE) {}
        TRadioButtonItem(const WCHAR *text, BOOLEAN pressed) : Base(text, pressed) {}

        void SetContent(Content content) { m_content = content; }

        Content GetContent() const { return m_content; }

    private:
        Content m_content;
};


#endif  // Apoxi_RadioButtonItem_hpp


