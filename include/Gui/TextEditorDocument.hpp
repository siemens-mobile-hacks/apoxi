/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextEditorDocument_hpp)
#define Apoxi_TextEditorDocument_hpp

#include <Gui/EditorDocument.hpp>
#include <Gui/CharItem.hpp>
#include <Gui/TextCompoundItem.hpp>

class TextEditorDocument : public EditorDocument {
    typedef EditorDocument Base;

    public:
        TextEditorDocument(const WCHAR* text = 0);
        
        virtual ~TextEditorDocument();

        void Init(const WCHAR* text = 0);

        void SetText(const WCHAR* text);

        const WString& GetText() const;

        virtual INT GetItemCount() const;

        void SetMaxItemCount(INT max_item_count);

        virtual INT GetMaxItemCount() const;

        void SetCrSupported(BOOLEAN flag) { m_bitfield.cr_supported = flag; }

        BOOLEAN IsCrSupported() const { return (BOOLEAN)m_bitfield.cr_supported; }
        
        virtual BOOLEAN InsertItem(const AtomItem& item, INT item_index);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT item_index);

        virtual BOOLEAN RemoveItem(INT item_index);

        virtual const CompoundItem& GetCompoundItem(INT ci_index, INT* start_item_index = 0) const;

        virtual void Draw(DeviceContext* dc, XYDIM x, XYDIM y, 
                          INT item_index, INT count) const;

        virtual INT WrapLine(INT item_index, XYDIM width, WrapPolicy wrap_policy = WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT item_index, INT count) const;

        void SetFont(const Font& font);

        const Font& GetFont() const;

        void SetLineHeight(XYDIM line_height) { m_line_height = line_height; }

        virtual XYDIM GetLineHeight(INT item_index, INT count, XYDIM* baseline = 0) const;

        virtual void GetItemScope(INT item_index,
                                  INT count,
                                  INT sub_index,
                                  XYDIM* x,
                                  XYDIM* width) const;

        virtual BOOLEAN IsRightToLeftItem(INT item_index) const;
        
        virtual void Clear();

    private:
        struct {
            UINT max_item_count : 15;
            UINT cr_supported   : 1;
        } m_bitfield;
        TextCompoundItem* m_compound_item;
        INT m_line_height;
};

#endif  // Apoxi_TextEditorDocument_hpp


