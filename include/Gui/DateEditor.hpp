/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DateEditor_hpp)
#define Apoxi_DateEditor_hpp

#include <Gui/AbstractLineEditor.hpp>
#include <Gui/DateEditorDocument.hpp>
#include <Gui/View.hpp>
#include <Auxiliary/Date.hpp>

class DefaultCaret;

class DateEditorView : public AbstractLineEditorView {
    typedef AbstractLineEditorView Base;

    public:
        explicit DateEditorView();
        
        virtual ~DateEditorView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;
};

class DateEditor : public AbstractLineEditor {
    typedef AbstractLineEditor Base;

    public:
        enum {
            ID = 30
        };

        DateEditor();

        explicit DateEditor(Control* parent, const Date& date = Date());

        virtual ~DateEditor();

        void Init(Control* parent, const Date& date = Date());

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void MoveCaret(INT steps);

        void SetDate(const Date& date);

        Date GetDate() const;

        void SetDateFormat(DateFormat date_format);

        DateFormat GetDateFormat() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void Refresh(const Rect& rect);

    private:
        BOOLEAN m_valid;

        static DateEditorView m_view;
        
        DateEditorDocument* GetMyDocument() { return (DateEditorDocument*)GetModel(); } //lint !e1762
        const DateEditorDocument* GetMyDocument() const { return (const DateEditorDocument*)GetModel(); }

        DefaultCaret* GetMyCaret() { return (DefaultCaret*)GetCaret(); }
};

#endif  // Apoxi_DateEditor_hpp


