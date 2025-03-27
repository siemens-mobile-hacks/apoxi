/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Caret_hpp)
#define Apoxi_Caret_hpp

#include <Gui/DrawableObject.hpp>

class AbstractEditor;   //lint !e763
class DeviceContext;
class Rect;             //lint !e763
class AtomItem;

class Caret {
    public:
        enum Mode {
            Insert,
            Overwrite
        };

        Caret();
        explicit Caret(AbstractEditor* editor, Mode mode = Insert);
        virtual ~Caret();

        virtual void SetRow(INT row);

        INT GetRow() const { return (INT)m_row; }

        virtual void SetColumn(INT column);

        INT GetColumn() const { return (INT)m_column; }

        INT GetIndex() const;

        void SetMode(Mode mode) { m_mode = mode; }

        Mode GetMode() const { return m_mode; }

        virtual void SetVisible(BOOLEAN visible);

        BOOLEAN IsVisible() const;

        virtual XYDIM GetMinimalWidth() const = 0;

        virtual void Draw(DeviceContext* dc, const Rect& bounds, BOOLEAN right_to_left = FALSE) const = 0;

        virtual void ShowHint() const;

        const AbstractEditor* GetEditor() const { return m_editor; }

    protected:
        AbstractEditor* GetEditor() { return m_editor; }
        
    private:
        Mode m_mode;
        INT m_row;
        INT m_column;
        AbstractEditor *m_editor;
};

#endif  // Apoxi_Caret_hpp


