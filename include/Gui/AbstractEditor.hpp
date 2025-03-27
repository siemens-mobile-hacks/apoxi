/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractEditor_hpp)
#define Apoxi_AbstractEditor_hpp

#include <Gui/Control.hpp>
#include <Gui/Caret.hpp>
#include <Gui/EditorDocument.hpp>
#include <Gui/InputMapper.hpp>

class AbstractEditor : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 27
        };

        enum SelectionStyle {
            InvertedSelection = 0,
            TransparentSelection = 1
        };

        AbstractEditor();

        AbstractEditor(Control* parent, INT input_mapper_id);

        virtual ~AbstractEditor();

        void Init(Control* parent, INT input_mapper_id);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        virtual void SetReadOnly(BOOLEAN read_only);

        BOOLEAN IsReadOnly() const { return static_cast<BOOLEAN>(m_bits.read_only); }

        void SetCaretAlwaysVisible(BOOLEAN visible);

        BOOLEAN IsCaretAlwaysVisible() const { return static_cast<BOOLEAN>(m_bits.caret_always_visible); }
        
        void SetEditMode(Caret::Mode mode);

        Caret::Mode GetEditMode() const;
        
        EditorDocument* GetDocument() { return (EditorDocument*)GetModel(); }   //lint !e1762

        const EditorDocument* GetDocument() const { return (const EditorDocument*)GetModel(); }

        INT GetItemCount() const;

        INT GetMaxItemCount() const; 

        void SetInputMapper(INT input_mapper_id);

        InputMapper* GetInputMapper() { return m_input_mapper; }

        const InputMapper* GetInputMapper() const { return m_input_mapper; }

        Caret* GetCaret();

        const Caret* GetCaret() const;

        virtual void MoveCaret(INT steps);

        void SetCaretIndex(INT index);

        virtual INT GetCaretIndex() const = 0;

        virtual Rect GetItemRect(INT index) const = 0;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Backspace();

        virtual void Update();

        BOOLEAN InsertCompoundItem(CompoundItem* compound_item, INT comp_item_index = -1);

        BOOLEAN InsertCompoundItemBeforeItem(CompoundItem* compound_item, INT item_index = -1);

        BOOLEAN RemoveCompoundItem(INT comp_item_index = -1);
        
        void UpdateDocumentAlphabet(InputMapper::Alphabet alphabet);

        void StartSelection();

        void StopSelection();

        void SetSelection(INT item_index, INT count);

        void GetSelection(INT* item_index, INT* count) const;

        BOOLEAN HasSelection() const { return m_sel_count != 0; }

        void SetSelectionStyle(SelectionStyle style);

        SelectionStyle GetSelectionStyle() const { return static_cast<SelectionStyle>(m_bits.selection_style); }

        virtual BOOLEAN IsStandaloneItem(INT index) const;

        virtual void DrawSelection(DeviceContext* dc, const Rect& bounds) const;
    
    protected:
        void AssureValidCaretIndex(INT& index);

        void AssureValidIndex(INT& index) const;

        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnKeyUp(KeyCode key_code, UINT32 duration);

        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);       

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual void OnPaint(const Rect& repaint_rect);
        
    private:
        struct {
            UINT read_only            : 1;
            UINT caret_always_visible : 1;
            UINT selection_started    : 1;
            UINT selection_style      : 2;
        } m_bits;
        INT m_sel_start;
        INT m_sel_count;
        InputMapper* m_input_mapper;
        
        void InitProperties(INT input_mapper_id);
        void UpdateNavigationGuidance();
};

#endif  // Apoxi_AbstractEditor_hpp

