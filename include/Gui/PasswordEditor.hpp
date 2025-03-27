/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PasswordEditor_hpp)
#define Apoxi_PasswordEditor_hpp

#include <Gui/AbstractLineEditor.hpp>
#include <Gui/TextEditorDocument.hpp>
#include <Gui/InputMapper.hpp>
#include <Gui/View.hpp>

class DefaultCaret;

class PasswordEditor : public AbstractLineEditor {
    typedef AbstractLineEditor Base;

    public:
        enum {
            ID = 34
        };

        PasswordEditor();

        PasswordEditor(Control* parent,
                       INT input_mapper_id,
                       const WCHAR* text = 0,
                       BOOLEAN cleartext_mode = FALSE);

        virtual ~PasswordEditor();

        void Init(Control* parent,
                  INT input_mapper_id,
                  const WCHAR* text = 0,
                  BOOLEAN cleartext_mode = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        void SetText(const WCHAR* text);

        const WString& GetText() const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Backspace();

        void SetMaxTextLength(INT max_tex_len);

        INT GetMaxTextLength() const;
        
        void SetClearTextModeEnabled(BOOLEAN cleartext);

        BOOLEAN IsClearTextModeEnabled() { return m_cleartext; }

    protected:
        virtual Model* CreateModel() const;

    private:
        WString m_text;
        BOOLEAN m_cleartext;

        TextEditorDocument* GetMyDocument() { return (TextEditorDocument*)GetModel(); } //lint !e1762
        const TextEditorDocument* GetMyDocument() const { return (const TextEditorDocument*)GetModel(); }

        DefaultCaret* GetMyCaret() { return (DefaultCaret*)GetCaret(); }
};

#endif  // Apoxi_PasswordEditor_hpp


