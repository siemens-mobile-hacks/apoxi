/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_LineEditor_hpp)
#define Apoxi_LineEditor_hpp

#include <Gui/AbstractLineEditor.hpp>
#include <Gui/TextEditorDocument.hpp>
#include <Gui/InputMapper.hpp>
#include <Gui/View.hpp>

class DefaultCaret;

class LineEditor : public AbstractLineEditor {
    typedef AbstractLineEditor Base;

    public:
        enum {
            ID = 32
        };

        LineEditor();

        LineEditor(Control* parent,
                   INT input_mapper_id,
                   const WCHAR* text = 0);

        virtual ~LineEditor();

        void Init(Control* parent,
                  INT input_mapper_id,
                  const WCHAR* text = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetText(const WCHAR* text);

        const WString& GetText() const;

        void SetMaxTextLength(INT max_tex_len);

        INT GetMaxTextLength() const;

        void SetFont(const Font& font);

        const Font& GetFont() const;

    protected:
        virtual Model* CreateModel() const;

        virtual XYDIM GetDefaultHeight() const;

    private:
        TextEditorDocument* GetMyDocument() { return (TextEditorDocument*)GetModel(); } //lint !e1762
        const TextEditorDocument* GetMyDocument() const { return (const TextEditorDocument*)GetModel(); }

        DefaultCaret* GetMyCaret() { return (DefaultCaret*)GetCaret(); }
};

#endif  // Apoxi_LineEditor_hpp


