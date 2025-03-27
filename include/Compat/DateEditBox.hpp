/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DateEditBox_hpp)
#define Apoxi_DateEditBox_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Date.hpp>
#include <Compat/AbstractEditBox.hpp>
#include <Gui/Lib.hpp>

class DateEditBoxModel : public AbstractEditBoxModel {
};

class DateEditBoxView : public AbstractEditBoxView {
    typedef AbstractEditBoxView Base;

    public:
        DateEditBoxView();
        DateEditBoxView(XYDIM line_height,
                        XYDIM caption_gap,
                        XYDIM caption_width,
                        XYDIM caption_height, 
                        XYDIM frame_size,
                        XYDIM default_width = -1,
                        XYDIM default_height = -1);

        virtual ~DateEditBoxView();

        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;

    protected:
        virtual void DrawDateEditBox(const DateEditBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

class DateEditBox : public AbstractEditBox {
    typedef AbstractEditBox Base;

    public:
        DateEditBox();

        DateEditBox(Control *parent,
                    Date::Format format = Date::ShortDateDMY, 
                    const WCHAR *caption = 0,
                    CaptionPos caption_pos = CaptionOnTop);

        virtual ~DateEditBox();

        void Init(Control *parent,
                  Date::Format format = Date::ShortDateDMY, 
                  const WCHAR *caption = 0,
                  CaptionPos caption_pos = CaptionOnTop);

        void SetFormat(Date::Format format);
        void SetFormat(const WCHAR *format);

        const WCHAR* GetFormat() const { return m_format; }

        void SetDate(const Date& date) const;

        Date GetDate() const;

        virtual BOOLEAN IsInputValid() const;

    protected:
        virtual Model* CreateModel() const;

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnDeleteChar();

        virtual void MoveCursor(INT inc);

        virtual const AbstractEditBoxView* GetView() const;

    private:
        const WCHAR         *m_format;
        WCHAR               m_buffer[20];
        static DateEditBoxView m_view;

        DateEditBoxModel* GetMyModel() const { return (DateEditBoxModel *)GetModel(); }
        INT GetCharPos(WCHAR chr) const;
        INT GetDay() const;
        INT GetMonth() const;
        INT GetYear() const;
        INT GetBufferSize() const { return sizeof(m_buffer)/sizeof(m_buffer[0]); }
};


#endif  // Apoxi_DateEditBox_hpp


