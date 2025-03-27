/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TimeEditor_hpp)
#define Apoxi_TimeEditor_hpp

#include <Gui/AbstractLineEditor.hpp>
#include <Gui/TimeEditorDocument.hpp>
#include <Gui/View.hpp>
#include <Auxiliary/Time.hpp>

class DefaultCaret;

class TimeEditor : public AbstractLineEditor {
    typedef AbstractLineEditor Base;

    public:
        enum {
            ID = 35
        };

        TimeEditor();

        explicit TimeEditor(Control* parent, const Time& time = Time());

        virtual ~TimeEditor();

        void Init(Control* parent, const Time& time = Time());

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        virtual void MoveCaret(INT steps);

        void SetTime(const Time& time);

        Time GetTime() const;

    protected:
        virtual Model* CreateModel() const;

    private:
        TimeEditorDocument* GetMyDocument() { return (TimeEditorDocument*)GetModel(); } //lint !e1762
        const TimeEditorDocument* GetMyDocument() const { return (const TimeEditorDocument*)GetModel(); }

        DefaultCaret* GetMyCaret() { return (DefaultCaret*)GetCaret(); }
};

#endif  // Apoxi_TimeEditor_hpp


