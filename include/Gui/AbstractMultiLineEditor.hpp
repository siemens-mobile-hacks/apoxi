/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractMultiLineEditor_hpp)
#define Apoxi_AbstractMultiLineEditor_hpp

#include <Gui/AbstractEditor.hpp>
#include <Gui/EditorLine.hpp>
#include <Gui/PositionIndicator.hpp>
#include <Auxiliary/Vector.hpp>

class AbstractMultiLineEditorView : public View {
    typedef View Base;

    public:
        explicit AbstractMultiLineEditorView(XYDIM default_width = -1, XYDIM default_height = -1);
        virtual ~AbstractMultiLineEditorView();
        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;
};

class AbstractMultiLineEditor : public AbstractEditor {
    typedef AbstractEditor Base;

    public:
        enum {
            ID = 29
        };

        enum CaretAction {
            CaretLeft,
            CaretRight,
            CaretLineUp,
            CaretLineDown
        };

        AbstractMultiLineEditor();

        AbstractMultiLineEditor(Control* parent, INT input_mapper_id);

        virtual ~AbstractMultiLineEditor();

        void Init(Control* parent, INT input_mapper_id);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void NavigateCaret(CaretAction caret_action);

        virtual Rect GetItemRect(INT index) const;

        virtual void MoveCaret(INT steps);

        virtual INT GetCaretIndex() const;
        
        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Backspace();

        virtual void Update();
        
        virtual void SetFirstVisibleLineIndex(INT line_idx);

        INT GetFirstVisibleLineIndex() const { return m_first_visible_line_idx; }

        const EditorLine& GetLine(INT line_idx) const { return m_line[line_idx]; }
        
        INT GetLineCount() const { return m_line.GetSize(); }

        INT GetVisibleLineCount(BOOLEAN* line_clipped = 0) const;

        void SetUpDownPermitted(BOOLEAN flag) { m_bits.up_down_permitted = flag; }

        BOOLEAN IsUpDownPermitted() const { return (BOOLEAN)m_bits.up_down_permitted; }

        void SetPositionIndicatorEnabled(BOOLEAN flag);

        BOOLEAN IsPositionIndicatorEnabled() const { return (BOOLEAN)m_bits.pos_ind_enabled; }

        BOOLEAN IsPositionIndicatorLeftAligned() const;
        
        XYDIM GetLineAlignInc(INT index, INT count, XYDIM width) const;

        XYDIM GetContentLeft() const;

        XYDIM GetMaxContentWidth() const;

        virtual BOOLEAN IsStandaloneItem(INT index) const;
        
        virtual BOOLEAN GetCharItem(INT index, WCHAR& chr) const;

        void SetWrapPolicy(WrapPolicy wrap_policy);

        WrapPolicy GetWrapPolicy() const { return (WrapPolicy)m_bits.wrap_policy; }
    
    protected:
        virtual void Refresh(const Rect& rect);

        virtual void OnPaint(const Rect& repaint_rect);

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnGetFocus();

        virtual void OnResize(XYDIM dx, XYDIM dy);

        virtual void OnLayoutClient();

        void Layout(INT line_idx = 0, INT added_items = -1);

    private:
        struct {
            UINT up_down_permitted  : 1;
            UINT pos_ind_enabled    : 1;
            UINT wrap_policy        : 3;
        } m_bits;
        XYDIM               m_old_caret_x;
        INT                 m_first_visible_line_idx;
        Vector<EditorLine>  m_line;
        PositionIndicator   m_pos_ind;
        
        static AbstractMultiLineEditorView m_view;

        INT GetLineForIndex(INT index) const;
        void UpdateNavigationGuidance();
};

#endif  // Apoxi_AbstractMultiLineEditor_hpp


