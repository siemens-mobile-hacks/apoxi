/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextCompoundItem_hpp)
#define Apoxi_TextCompoundItem_hpp

#include <Auxiliary/WString.hpp>
#include <Gui/CompoundItem.hpp>

class Font;

class TextCompoundItem : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 6
        };

        static TextCompoundItem* CreateInstance(const WCHAR* text = 0);

        static TextCompoundItem* CreateInstance(const WCHAR* text, const Font& font);

        virtual ~TextCompoundItem();

        virtual INT GetId() const;

        void SetText(const WCHAR* text) { m_text = text; }

        const WString& GetText() const { return m_text; }

        void Insert(INT index, WCHAR ch) { m_text.insert(index, ch); }

        void Replace(INT index, WCHAR ch) { m_text.replace(index, ch); }

        void Remove(INT index, INT count = -1) { m_text.erase(index, count); }

        void SetFont(const Font& font) { m_font = &font; }

        const Font& GetFont() const { ASSERT_DEBUG_HOST(m_font != 0); return *m_font; }

        virtual TextAttr GetTextAttr() const;

        WCHAR* ExportInternalBuffer(UINT length);

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual BOOLEAN IsStandaloneCharacter(INT index) const;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;

        virtual INT GetItemCount() const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Split(INT index, CompoundItem** compound_item);

        virtual BOOLEAN Merge(const CompoundItem& compound_item);

        virtual CompoundItem* Clone() const;

        virtual void Clear();

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        TextCompoundItem(const WCHAR* text = 0);
        TextCompoundItem(const WCHAR* text, const Font& font);

        void SetDefaultColorHint(BOOLEAN use_default_color) { m_use_default_color = use_default_color; }

    private:
        BOOLEAN m_use_default_color;
        const Font* m_font;
        WString m_text;
};

#endif  // Apoxi_TextCompoundItem_hpp

