/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RichTextCompoundItem_hpp)
#define Apoxi_RichTextCompoundItem_hpp

#include <Auxiliary/WString.hpp>
#include <Gui/TextCompoundItem.hpp>
#include <Gui/Color.hpp>

class RichTextCompoundItem : public TextCompoundItem {
    typedef TextCompoundItem Base;

    public:
        enum {
            ID = 10
        };

        static RichTextCompoundItem* CreateInstance(const Font& font, const WCHAR* text = 0);

        virtual ~RichTextCompoundItem();

        virtual INT GetId() const;

        void SetTextAttr(TextAttr text_attr) { m_text_attr = text_attr; }

        virtual TextAttr GetTextAttr() const;

        void SetForegroundColor(const Color& color);

        const Color& GetForegroundColor() const { return m_foregr_color; }

        void SetBackgroundColor(const Color& color) { m_backgr_color = color; }

        const Color& GetBackgroundColor() const { return m_backgr_color; }

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual BOOLEAN Split(INT index, CompoundItem** compound_item);

        virtual BOOLEAN Merge(const CompoundItem& compound_item);

        virtual CompoundItem* Clone() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        RichTextCompoundItem(const Font& font, const WCHAR* text = 0);

    private:
        TextAttr    m_text_attr;
        Color       m_foregr_color;
        Color       m_backgr_color;
};

#endif  // Apoxi_RichTextCompoundItem_hpp

