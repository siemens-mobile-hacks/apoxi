/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CheckBoxItem_hpp)
#define Apoxi_CheckBoxItem_hpp


class CheckBoxItem : public Linkable<CheckBoxItem> {
    public:
        CheckBoxItem(const WCHAR *text = 0, BOOLEAN selected = FALSE) :
            m_text(text), m_selected(selected) {}

        void SetText(const WCHAR *text) { m_text = text; };

        const WCHAR* GetText() const { return m_text; };

        void SetSelected(BOOLEAN selected) { m_selected = selected; };

        BOOLEAN IsSelected() const { return m_selected; };

    private:
        const WCHAR *m_text;
        BOOLEAN     m_selected;
};


#endif  // Apoxi_CheckBoxItem_hpp


