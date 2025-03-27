/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TimeEditBox_hpp)
#define Apoxi_TimeEditBox_hpp

#include <Gui/Lib.hpp>
#include <Kernel/Types.hpp>
#include <Auxiliary/Time.hpp>
#include <Compat/AbstractEditBox.hpp>

class TimeEditBoxModel : public AbstractEditBoxModel {
};

class TimeEditBoxView : public AbstractEditBoxView {
    typedef AbstractEditBoxView Base;

    public:
        TimeEditBoxView();
        TimeEditBoxView(XYDIM line_height,
                        XYDIM caption_gap,
                        XYDIM caption_width,
                        XYDIM caption_height, 
                        XYDIM frame_size,
                        XYDIM default_width = -1,
                        XYDIM default_height = -1);

        virtual ~TimeEditBoxView();

        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;

    protected:
        virtual void DrawTimeEditBox(const TimeEditBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

class TimeEditBox : public AbstractEditBox {
    typedef AbstractEditBox Base;

    public:
        TimeEditBox();

        TimeEditBox(Control *parent,
                    Time::Format format = Time::TimeHM, 
                    const WCHAR *caption = 0,
                    CaptionPos caption_pos = CaptionOnTop);

        virtual ~TimeEditBox();

        void Init(Control *parent,
                  Time::Format format = Time::TimeHM, 
                  const WCHAR *caption = 0,
                  CaptionPos caption_pos = CaptionOnTop);

        void SetFormat(Time::Format format);
        void SetFormat(const WCHAR *format);

        const WCHAR* GetFormat() const { return m_format; }

        void SetTime(const Time& time) const;

        Time GetTime() const;
        
        virtual BOOLEAN IsInputValid() const;

    protected:
        virtual Model* CreateModel() const;

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnDeleteChar();

        virtual void MoveCursor(INT inc);

        virtual const AbstractEditBoxView* GetView() const;

        INT GetHour() const { return GetDigits(L'H'); }

        INT GetMinute() const { return GetDigits(L'M'); }

        INT GetSecond() const { return GetDigits(L'S'); }

    private:
        const WCHAR         *m_format;
        WCHAR               m_buffer[10];
        static TimeEditBoxView m_view;

        TimeEditBoxModel* GetMyModel() const { return (TimeEditBoxModel *)GetModel(); }

        INT GetCharPos(WCHAR chr) const;
        INT GetDigits(WCHAR c) const;
        INT GetBufferSize() const { return sizeof(m_buffer) / sizeof(m_buffer[0]); }
};


#endif  // Apoxi_TimeEditBox_hpp


