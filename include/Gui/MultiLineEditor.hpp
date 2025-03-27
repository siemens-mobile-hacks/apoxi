/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MultiLineEditor_hpp)
#define Apoxi_MultiLineEditor_hpp

#include <Gui/AbstractMultiLineEditor.hpp>

class TextEditorDocument;

class MultiLineEditor : public AbstractMultiLineEditor {
    typedef AbstractMultiLineEditor Base;

    public:
        enum {
            ID = 33
        };

        MultiLineEditor();

        MultiLineEditor(Control* parent, INT input_mapper_id, const WCHAR* text = 0);

        virtual ~MultiLineEditor();

        void Init(Control* parent, INT input_mapper_id, const WCHAR* text = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void SetReadOnly(BOOLEAN read_only);

        void SetText(const WCHAR* text);

        const WString& GetText() const;

        void SetMaxTextLength(INT max_tex_len);

        INT GetMaxTextLength() const;

        void SetLineHeight(XYDIM line_height);

        void SetFont(const Font& font);

        const Font& GetFont() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void OnThemeChanged();

    private:
        TextEditorDocument* GetMyDocument() { return (TextEditorDocument*)GetModel(); } //lint !e1762
        const TextEditorDocument* GetMyDocument() const { return (TextEditorDocument*)GetModel(); }
};

#endif  // Apoxi_MultiLineEditor_hpp


