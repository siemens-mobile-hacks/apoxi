/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_InputMapper_hpp)
#define Apoxi_InputMapper_hpp

#include <Gui/Caret.hpp>

class AbstractEditor;

class InputMapper {
    public:
        enum Id {
            Numeric         = 0,
            MultiTap        = 1,
            MultiTab        = MultiTap,
            PhoneNumber     = 2,
            Predictive      = 3,
            Date            = 4,
            Time            = 5,
            Calculator      = 6,
            IpAddress       = 7,
            Zi8             = 8,
            Url             = 9,
            EMailAddress    = 10,
            T9              = 11,
            Name            = 12,
            Custom          = 99
        };

        enum Alphabet {
            UndefinedAlphabet   = 0,
            SevenBitAlphabet    = 1,
            EightBitAlphabet    = 2,
            Ucs2Alphabet        = 3
        };

        enum NotificationType {
            InsertedItem    = 0,
            UpdatedContent  = 1,
            SetText         = 1

        };

        explicit InputMapper(AbstractEditor* editor = 0);

        virtual ~InputMapper();

        virtual INT GetId() const = 0;

        virtual void SetEditor(AbstractEditor* editor);

        virtual Caret* GetCaret();

        virtual Alphabet GetAlphabet() const;

        virtual BOOLEAN Notify(NotificationType type, INT index = 0, const AtomItem* item = 0);

        virtual BOOLEAN IsContentValid() const;
        
    protected:
        Caret* m_caret;

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnKeyUp(KeyCode key_code, UINT32 duration);

        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);

        virtual void OnGetFocus();
        
        virtual void OnLoseFocus();

        AbstractEditor* GetEditor() { return m_editor; }

        const AbstractEditor* GetEditor() const { return m_editor; }

    private:
        // TODO: derive InputMapper from Dispatcher and forward key codes by SendSelf, this
        // avoids the following friend declarations
        friend class AbstractEditor;            // invokes InputMapper::OnKeyDown
        friend class AbstractMultiLineEditor;   // invokes InputMapper::OnKeyDown
        
        AbstractEditor* m_editor;
};

typedef InputMapper::NotificationType NotificationType;

#endif  // Apoxi_InputMapper_hpp


