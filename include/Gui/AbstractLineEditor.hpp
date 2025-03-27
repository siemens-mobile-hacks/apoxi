/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractLineEditor_hpp)
#define Apoxi_AbstractLineEditor_hpp

#include <Gui/AbstractEditor.hpp>

class AbstractLineEditorView : public View {
    typedef View Base;

    public:
        explicit AbstractLineEditorView();
        virtual ~AbstractLineEditorView();
        void Init();
        virtual void Draw(const Component& component,
                          DeviceContext* dc,
                          const Rect& repaint_rect) const;
};


class AbstractLineEditor : public AbstractEditor {
    typedef AbstractEditor Base;

    public:
        enum {
            ID = 28
        };

        AbstractLineEditor();

        AbstractLineEditor(Control* parent, INT input_mapper_id);

        virtual ~AbstractLineEditor();

        void Init(Control* parent, INT input_mapper_id);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        virtual void MoveCaret(INT steps);

        virtual INT GetCaretIndex() const;

        virtual Rect GetItemRect(INT index) const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Backspace();

        virtual void Update();

        void SetFirstVisibleIndex(INT index);

        INT GetFirstVisibleIndex() const { return m_first_visible_idx; }

        INT GetVisibleItemCount() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

    private:
        INT m_first_visible_idx;

        static AbstractLineEditorView m_view;

        void InvalidateToEol(INT from);
};

#endif  // Apoxi_AbstractLineEditor_hpp


