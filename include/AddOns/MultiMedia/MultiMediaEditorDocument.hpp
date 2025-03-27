/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MultiMediaEditorDocument_hpp)
#define Apoxi_MultiMediaEditorDocument_hpp

#include <Gui/EditorDocument.hpp>
#include <Gui/CharItem.hpp>
#include <Gui/TextCompoundItem.hpp>
#include <Auxiliary/Vector.hpp>
#include <AddOns/MultiMedia/ParagraphCompoundItem.hpp>

class MultiMediaEditorDocument;

#define c_max_level_count 4         // const INT declaration on target not possible

class CompoundItemIterator {
    public:
        CompoundItemIterator(const MultiMediaEditorDocument* doc);

        virtual ~CompoundItemIterator();

        BOOLEAN Begin();

        BOOLEAN Next();

        const CompoundItem* Get(INT* start_index = 0) const;

    private:
        struct Node {
            INT m_comp_item_index;
            INT m_start_index;
            const CompoundItem* m_comp_item;
        } m_node[c_max_level_count];
        INT m_level;
        const MultiMediaEditorDocument* m_doc;
            
        BOOLEAN TraverseToLeaf();
};

class MultiMediaEditorDocument : public EditorDocument {
    typedef EditorDocument Base;

    public:
        class TextManager {
            public:
                TextManager(MultiMediaEditorDocument& doc);
                virtual ~TextManager();

                BOOLEAN InsertText(const WString& text,
                                   INT item_index = -1,
                                   TextAttr attr = TextFormat::Normal,
                                   const Font* font = 0,
                                   const Color* foreground_color = 0,
                                   const Color* background_color = 0);

                BOOLEAN SetFont(INT item_index, INT item_count, const Font& font);

                BOOLEAN SetTextAttr(INT item_index, INT item_count, TextAttr attr);

                BOOLEAN SetForegroundColor(INT item_index, INT item_count, const Color& color);

                BOOLEAN SetBackgroundColor(INT item_index, INT item_count, const Color& color);
    
            private:
                BOOLEAN SetFormat(INT item_index, 
                                  INT item_count,
                                  const TextAttr* attr = 0,
                                  const Font* font = 0,
                                  const Color* foreground_color = 0,
                                  const Color* background_color = 0);

                const Font& GetDefaultFont() const;

                MultiMediaEditorDocument& m_doc;
        };

        MultiMediaEditorDocument();
                
        virtual ~MultiMediaEditorDocument();

        virtual INT GetItemCount() const;

        virtual INT GetMaxItemCount() const;
        
        virtual BOOLEAN InsertItem(const AtomItem& item, INT item_index);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT item_index);

        virtual BOOLEAN RemoveItem(INT item_index);

        virtual INT GetCompoundItemCount() const;

        virtual BOOLEAN InsertCompoundItem(CompoundItem* compound_item, INT ci_index = -1);

        virtual BOOLEAN InsertCompoundItemBeforeItem(CompoundItem* compound_item, INT item_index = -1);

        virtual BOOLEAN RemoveCompoundItem(INT ci_index = -1);

        virtual const CompoundItem& GetCompoundItem(INT ci_index, INT* start_item_index = 0) const;

        INT GetCompoundItemIndex(INT item_index) const;

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y, 
                          INT item_index,
                          INT count) const;

        virtual INT WrapLine(INT item_index,
                             XYDIM width,
                             WrapPolicy wrap_policy = WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT item_index, INT count) const;

        virtual XYDIM GetLineHeight(INT item_index, INT count, XYDIM* baseline = 0) const;

        void SetLineAlignment(LineAlignment alignment);

        virtual LineAlignment GetLineAlignment(INT item_index, INT count) const;

        virtual BOOLEAN IsEditableAfterLastItem() const;
        
        virtual void GetItemScope(INT item_index,
                                  INT count,
                                  INT sub_index,
                                  XYDIM* x,
                                  XYDIM* width) const;

        virtual BOOLEAN IsRightToLeftItem(INT item_index) const;

        virtual void Clear();

        virtual void OnChangedLayout(const Vector<EditorLine>& line, INT from = -1, INT count = 0);

        void SetTopLineGap(UINT8 gap);

        UINT8 GetTopLineGap() const;

        void SetBottomLineGap(UINT8 gap);

        UINT8 GetBottomLineGap() const;

    private:
        ParagraphCompoundItem* m_paragraph;

        BOOLEAN IsParagraphAtEnd() const;
        
    friend class CompoundItemIterator;      // accesses to m_paragraph for easier iteration
};

#endif  // Apoxi_MultiMediaEditorDocument_hpp


