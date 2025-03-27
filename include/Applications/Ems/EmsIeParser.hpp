/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsIeParser_hpp)
#define Ems_EmsIeParser_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/Provider.hpp>
#include <Auxiliary/BufferedData.hpp>
#include <Apc/BaseInformationElement.hpp>
#include <Apc/InformationElement.hpp>
#include <Adc/CompoundSmsItem.hpp>
#include <Gui/EditorDocument.hpp>
#include <Gui/CompoundItem.hpp>
#include <Gui/Color.hpp>
#include <Gui/Font.hpp>
#include <AddOns/MultiMedia/ParagraphCompoundItem.hpp>
#include <AddOns/MultiMedia/RichTextCompoundItem.hpp>
#include <AddOns/MultiMedia/ImageItem.hpp>
#include <AddOns/MultiMedia/SoundItem.hpp>
#include <AddOns/MultiMedia/IMelody.hpp>

#include <Ems/EmsImage.hpp>
#include <Ems/PredefinedEmsSound.hpp>
#include <Ems/PredefinedEmsImage.hpp>

class EditorItemNode {
    public:
        enum ItemType {
            DefaultTextFormattingIe,
            ParagraphItem,
            TextItem,
            AtomicItem,
            InvalidItem
        };

        EditorItemNode();
        ~EditorItemNode(); // not virual !!
        
        void SetItemType(ItemType type) { m_type = type; }
        ItemType GetItemType() const { return m_type; }
        void SetPosition(INT pos) { m_pos = pos; }
        INT GetPosition () const { return m_pos; }
        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }
        void SetCompoundItem(CompoundItem* item);
        CompoundItem* GetCompoundItem();
        void SetEditorItem(AtomItem* item);
        AtomItem* GetEditorItem();
        void SetTextFormatting(UINT8 mode, UINT8 colour);
        InformationElement GetTextFormattingElement();
        
    private:
        enum UnionType {
            CompoundItemType,
            EditorItemType,
            TextFormattingType,
            InvalidType
        };

        ItemType    m_type;
        UnionType   m_union_type;
        INT         m_pos;
        INT         m_length;
        union {
            CompoundItem*   m_compound_item;
            AtomItem*       m_editor_item;
            UINT16          m_text_formatting;
        };
};

class EmsIeParser {
    public:
        EmsIeParser();
        virtual ~EmsIeParser();
        
        void Parse(CompoundSmsItem* sms_item, EditorDocument& document, BOOLEAN append = FALSE, BOOLEAN mark_missing = TRUE);

    private:

        enum PredefinedMediaType {
            PredefinedSoundType,
            PredefinedAnimationType,
        };

        void GenerateDocument(EditorDocument& document, const WString& text);

        void ParseInformationElement(const InformationElement& ie);
        void ParseTextFormatting(const InformationElement& ie);
        void ParsePredefinedMedia(INT rel_start_pos, PredefinedMediaType id, INT type);

        ParagraphCompoundItem* CreateParagraphItem(const InformationElement& ie, ParagraphCompoundItem* prev_pg = 0) const;
        TextCompoundItem* CreateTextItem(const InformationElement& ie) const;
        TextCompoundItem* CloneTextItem(const TextCompoundItem* item) const;
        
        void AppendImageItem(INT rel_start_pos, UINT16 width, UINT16 height, UINT8* data, UINT8 data_length, UINT8 frames);
        void AppendImageItem(INT rel_start_pos, Image* image);
        void AppendSoundItem(INT rel_start_pos, UINT8* data, UINT8 data_length);
        void AppendSoundItem(INT rel_start_pos, Sound* snd);

        BOOLEAN SupportsItem(EditorDocument& document, CompoundItem* item);         
        void ResetParser();
        void MarkMissingPdu(INT rel_start_pos);

        void AddItemNode(const EditorItemNode& node);
        EditorItemNode* GetPreviousItemNode(EditorItemNode::ItemType type, INT text_pos);

        struct {
            BOOLEAN supports_paragraphs : 2;
            BOOLEAN supports_rich_text  : 2;
        } m_flags;

        INT                     m_offset;
        Vector<EditorItemNode>  m_items;
};

#endif // Ems_EmsIeParser_hpp
