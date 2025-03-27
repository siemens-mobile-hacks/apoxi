/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ParagraphCompoundItem_hpp)
#define Apoxi_ParagraphCompoundItem_hpp

#include <Gui/CompoundItem.hpp>
#include <Gui/EditorDocument.hpp>
#include <Auxiliary/Vector.hpp>
#include <AddOns/MultiMedia/CompoundItemReferrer.hpp>

class ParagraphCompoundItem : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 11
        };

        static ParagraphCompoundItem* CreateInstance(LineAlignment alignment = EditorDocument::DefaultAlign);

        virtual ~ParagraphCompoundItem();

        virtual INT GetId() const;

        BOOLEAN InsertCompoundItem(CompoundItem* item, INT ci_index = -1);

        virtual BOOLEAN InsertCompoundItemBeforeItem(CompoundItem* comp_item, INT item_index = -1);

        BOOLEAN RemoveCompoundItem(INT ci_index = -1);

        INT GetCompoundItemCount() const;

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;

        void SetLineAlignment(LineAlignment alignment) { m_alignment = alignment; }

        LineAlignment GetLineAlignment(INT index, INT count) const;

        virtual INT GetItemCount() const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        const CompoundItem& GetCompoundItem(INT index, INT* start_index = 0) const;

        INT GetCompoundItemIndex(INT item_index) const;

        virtual BOOLEAN Split(INT index, CompoundItem* *compound_item);

        virtual CompoundItem* Clone() const;

        virtual void Clear();

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetTopLineGap(UINT8 gap) { m_top_line_gap = gap; }

        UINT8 GetTopLineGap() const { return m_top_line_gap; }

        void SetBottomLineGap(UINT8 gap) { m_bottom_line_gap = gap; }

        UINT8 GetBottomLineGap() const { return m_bottom_line_gap; }
        
        void UpdateBidiBuffer() const;

        void ConvertBidiLine(INT item_index, INT count) const;

    protected:
        ParagraphCompoundItem(LineAlignment alignment = EditorDocument::DefaultAlign);

        CompoundItem* GetCompoundItem(INT index, INT* start_item_index = 0);

        BOOLEAN MoveToParagraph(ParagraphCompoundItem* paragraph);

        void UpdateStartIndices(INT ci_index);

        void BeginInternalUpdate() { m_internal_update = TRUE; }
        void EndInternalUpdate() { m_internal_update = FALSE; }
        BOOLEAN IsInternalUpdate() const { return m_internal_update; }

    private:
        LineAlignment m_alignment;
        BOOLEAN m_internal_update;
        INT m_item_count;
        UINT8 m_top_line_gap;
        UINT8 m_bottom_line_gap;
        Vector<CompoundItemReferrer> m_comp_item_vector;
        
        mutable WCHAR* m_bidi_text_buf;
        mutable INT* m_bidi_pos;
        mutable INT m_bidi_buffer_len;
        mutable INT m_bidi_text_len;

        void InitProperties();

        BOOLEAN SplitAndInsert(CompoundItem* comp_item,
                               CompoundItem* inserted_comp_item,
                               INT ci_index,
                               INT sub_index); 

        TextCompoundItem* CreateTextCompoundItem(INT ci_index);

        INT WrapTextCompoundItemChain(INT start_index,
                                      EditorDocument::WrapPolicy wrap_policy,
                                      INT& ci_index,
                                      XYDIM& width,
                                      BOOLEAN& wrapped) const;

        BOOLEAN InsertRootParagraph(ParagraphCompoundItem* paragraph, INT item_index);

        BOOLEAN AlignBidiItems(INT item_index,
                               INT count,
                               DeviceContext* dc,
                               XYDIM x,
                               XYDIM y,
                               XYDIM baseline,
                               INT* out_item_index = 0,
                               XYDIM* out_x = 0,
                               XYDIM* out_width = 0,
                               BOOLEAN* out_is_rtl_item = 0) const;
        
        BOOLEAN SearchRightToLeftChar(const WCHAR* text, INT index) const;

        friend class MultiMediaEditorDocument;      // allow access to method InsertRootParagraph
};

#endif  // Apoxi_ParagraphCompoundItem_hpp

