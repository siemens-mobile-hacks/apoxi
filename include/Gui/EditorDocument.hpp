/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EditorDocument_hpp)
#define Apoxi_EditorDocument_hpp

#include <Auxiliary/ObjectObtainer.hpp>
#include <Auxiliary/Vector.hpp>
#include <Gui/Model.hpp>
#include <Gui/InputMapper.hpp>
#include <Gui/EditorLine.hpp>

class AtomItem;     //lint !e763
class CharItem;
class CompoundItem;
class EditorDocument;

class EditorDocumentObtainer : public ObjectObtainer {
    typedef ObjectObtainer Base;

    public: 
        EditorDocumentObtainer();

        EditorDocumentObtainer(EditorDocument* doc, BOOLEAN disposeable);
        virtual ~EditorDocumentObtainer();
        EditorDocument* GetEditorDocument() { return m_doc; }
        const EditorDocument* GetEditorDocument() const { return m_doc; }
        
    private:
        EditorDocument* m_doc;
};

class EditorDocument : public Model, public ObtainableObject {
    typedef Model Base;

    public:
        enum WrapPolicy {
            WhitespaceWrap = 0,

            StrictWhitespaceWrap = 1,

            LeftJustifiedWrap = 2,

            CutWrap = 3,

            CompactWrap = 4
        };

        enum LineAlignment {
            DefaultAlign,
            LeftAlign,
            CenteredAlign,
            RightAlign
        };

        EditorDocument();
        virtual ~EditorDocument();

        virtual INT GetItemCount() const = 0;

        virtual INT GetMaxItemCount() const = 0;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT item_index = -1) = 0;

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT item_index = -1) = 0;

        virtual BOOLEAN RemoveItem(INT item_index = -1) = 0;

        virtual INT GetCompoundItemCount() const;

        virtual BOOLEAN InsertCompoundItem(CompoundItem* compound_item, INT ci_index = -1);

        virtual BOOLEAN InsertCompoundItemBeforeItem(CompoundItem* compound_item, INT item_index = -1);

        virtual BOOLEAN RemoveCompoundItem(INT ci_index = -1);

        virtual const CompoundItem& GetCompoundItem(INT ci_index, INT* start_item_index = 0) const = 0;
        
        const CompoundItem& GetParentCompoundItem(INT item_index, INT* start_item_index = 0) const;

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT item_index,
                          INT count) const = 0;

        virtual INT WrapLine(INT item_index, XYDIM width, WrapPolicy wrap_policy = WhitespaceWrap) const = 0;

        virtual XYDIM GetLineWidth(INT item_index, INT count) const = 0;

        virtual XYDIM GetLineHeight(INT item_index, INT count, XYDIM* baseline = 0) const = 0;

        virtual LineAlignment GetLineAlignment(INT item_index, INT count) const;
        
        virtual void GetItemScope(INT item_index,
                                  INT count,
                                  INT sub_index,
                                  XYDIM* x,
                                  XYDIM* width) const;

        virtual BOOLEAN IsEditableAfterLastItem() const;

        virtual void Clear();

        virtual BOOLEAN IsRightToLeftItem(INT item_index) const;

        void SetAlphabet(InputMapper::Alphabet alphabet) { m_alphabet = alphabet; }

        InputMapper::Alphabet GetAlphabet() const { return m_alphabet; }

        virtual void OnChangedLayout(const Vector<EditorLine>& line, INT from = -1, INT count = 0);

    private:
        InputMapper::Alphabet   m_alphabet;
};

typedef EditorDocument::WrapPolicy WrapPolicy;
typedef EditorDocument::LineAlignment LineAlignment;

#endif  // Apoxi_EditorDocument_hpp


