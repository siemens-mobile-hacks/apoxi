/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Alert_hpp)
#define Apoxi_Alert_hpp

#include <Gui/Window.hpp>
#include <Gui/TextFormat.hpp>
#include <Kernel/Condition.hpp>

class Alert : public Window {
    typedef Window Base;

    public:
        enum {
            ID = 4
        };

        Alert();

        Alert(const WCHAR* text, INT delay = -1);

        Alert(const WString& text, INT delay = -1);

        virtual ~Alert();

        void Init(const WCHAR* text, INT delay = -1);

        void Init(const WString& text, INT delay = -1);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetText(const WCHAR* text);

        void SetText(const WString& text);

        const WString& GetText() const { return m_text; }

        void SetDelay(INT delay);

        INT GetDelay() const { return m_delay; }

        void SetTextFormat(const TextFormat& text_format) { m_text_format = text_format; }

        const TextFormat& GetTextFormat() const { return m_text_format; }

        virtual void OpenModeless(const Rect& rect = Rect());

        virtual INT OpenModal(const Rect& rect = Rect());

        BOOLEAN CloseImmediately();

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnPaint(const Rect& repaint_rect);

        virtual BOOLEAN OnTimeout(const Timer& timer);

        virtual void OnClose();

    private:
        class CloseCondition : public Condition {
            public:
                explicit CloseCondition(const Timer* timer) : m_timer(timer) { }
                virtual BOOLEAN IsTrue() const { return !m_timer->IsActive(); }
            private:
                const Timer* m_timer;
        };

        BOOLEAN     m_auto_close;
        INT         m_delay;
        WString     m_text;
        Timer       m_timer;
        TextFormat  m_text_format;

        void InitProperties(const WCHAR* text, INT delay);
        void StartTimer();
};

#endif  // Apoxi_Alert_hpp


