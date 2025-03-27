/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractEditBox_hpp)
#define Apoxi_AbstractEditBox_hpp

#include <Gui/Model.hpp>
#include <Gui/View.hpp>
#include <Gui/Control.hpp>
#include <Kernel/Timer.hpp>
#include <Auxiliary/Vector.hpp>

class AbstractEditBox;
struct PagingMapEntry;

class EditLine {
    public:
        EditLine();

        void SetIndex(INT index) { m_index = index; }
        INT GetIndex() const { return m_index; }

        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }

    private:
        INT m_index;
        INT m_length;
};

class AbstractEditBoxModel : public Model {
    public:
        typedef Model Base;

        AbstractEditBoxModel(WCHAR *buff = 0,
                     INT max_text_len = 0,
                     const WCHAR *caption = 0, 
                     UINT caption_type = 0,
                     BOOLEAN password_mode = FALSE);

        virtual ~AbstractEditBoxModel();

        void Init(WCHAR *buff = 0,
                  INT max_text_len = 0,
                  const WCHAR *caption = 0, 
                  UINT caption_type = 0,
                  BOOLEAN password_mode = FALSE);

        void SetCaption(const WCHAR *caption) { m_caption = caption; }

        const WCHAR* GetCaption() const { return m_caption; }

        void SetCaptionType(UINT caption_type) { m_caption_type = caption_type; }

        UINT GetCaptionType() const { return m_caption_type; }

        void SetInputValid(BOOLEAN input_valid) { m_bits.input_valid = input_valid; }

        BOOLEAN IsInputValid() const { return m_bits.input_valid; }

        void SetPasswordMode(BOOLEAN password_mode) { m_bits.password_mode = password_mode; }

        BOOLEAN IsPasswordMode() const { return m_bits.password_mode; }

        void SetText(const WCHAR *text);

        WCHAR* GetText() const { return m_text; }

        void SetMaxTextLength(INT max_text_len);

        INT GetMaxTextLength() const { return m_max_text_len; }

        void SetTextLength(INT text_len);

        INT GetTextLength() const { return m_text_len; }

        BOOLEAN InsertChar(WCHAR ch, INT insert_idx = -1);

        BOOLEAN ReplaceChar(WCHAR ch, INT replace_idx = -1);

        WCHAR GetChar(INT idx = -1) const;

        void RemoveEmptyLines();

        void DeleteChar(INT idx = -1);
        
        void SetCursorPos(INT i) { m_cursor_pos = i; }

        INT GetCursorPos() const { return m_cursor_pos; }

        void SetLineIndex(INT line, INT index) { m_line[line].SetIndex(index); }

        INT GetLineIndex(INT line) const { return m_line[line].GetIndex(); }

        void SetLineLength(INT line, INT length) { m_line[line].SetLength(length); }

        INT GetLineLength(INT line) const {return m_line[line].GetLength(); }

        INT GetLine(INT char_idx = -1) const;

        void AppendEmptyLine();

        void SetCursorVisible(BOOLEAN state) { m_bits.cursor_blink_state = state; }

        BOOLEAN IsCursorVisible() const { return m_bits.cursor_blink_state; }

        void SetPaging(BOOLEAN paging) { m_bits.paging = paging; }

        BOOLEAN IsPaging() const { return m_bits.paging; }

        INT GetNoOfLines() const { return m_line.GetSize(); }

        void SetNoOfVisibleLines(INT lines) { m_nr_of_visible_lines = lines; }

        INT GetNoOfVisibleLines() const { return m_nr_of_visible_lines; }

        void SetFirstVisibleLine(INT line) { m_first_visible_line = line; }

        INT GetFirstVisibleLine() const { return m_first_visible_line; }

        INT GetLastVisibleLine() const;

        INT GetFirstVisibleIndex() const { return GetLineIndex(GetFirstVisibleLine()); }

        INT GetLastVisibleIndex() const { return GetLastCharIdxOfLine(GetLastVisibleLine()); }

        BOOLEAN IsIndexVisible(INT index) const { return (index >= GetFirstVisibleIndex()) && (index <= GetLastVisibleIndex()); }

        void Reset();

        void SetBuffer(WCHAR *buff) { m_text = buff; }

        WCHAR* GetBuffer() const { return m_text; }

    private:
        struct {
            UINT    paging              : 1;
            UINT    cursor_blink_state  : 1;
            UINT    input_valid         : 1;
            UINT    password_mode       : 1;
        } m_bits;
        INT     m_caption_type;
        INT     m_max_text_len;
        INT     m_first_visible_line;
        INT     m_nr_of_visible_lines;
        INT     m_text_len;
        INT     m_cursor_pos;
        WCHAR   *m_text;
        const WCHAR *m_caption;
        Vector<EditLine>    m_line;

        INT GetLastCharIdxOfLine(INT i) const { return (m_line[i].GetIndex() + m_line[i].GetLength() - 1); };
};

class AbstractEditBoxView : public View {
    typedef View Base;

    public:
        AbstractEditBoxView();
        AbstractEditBoxView(XYDIM line_height,
                    XYDIM caption_gap,
                    XYDIM caption_width,
                    XYDIM caption_height, 
                    XYDIM edit_box_frame_size,
                    XYDIM default_width = -1,
                    XYDIM default_height = -1);

        virtual ~AbstractEditBoxView();

        Rect GetCursorRect(const AbstractEditBoxModel &model, const DeviceContext &dc, INT cursor_pos = -1) const;

        XYDIM GetLineHeight() const { return m_line_height; }

        XYDIM GetCaptionGap() const { return m_caption_gap; }

        XYDIM GetCaptionWidth() const { return m_caption_width; }

        XYDIM GetCaptionHeight() const { return m_caption_height; }

        XYDIM GetFrameSize() const { return m_frame_size; }

    protected:
        XYDIM m_line_height;
        XYDIM m_caption_gap;
        XYDIM m_caption_width;
        XYDIM m_caption_height;
        XYDIM m_frame_size;

        // Draws the cursor of the editbox.
        void DrawCursor(const AbstractEditBoxModel &model, DeviceContext *dc) const;

    private:
        BOOLEAN m_block_cursor;
        BOOLEAN m_underscore_cursor;

        INT GetNoOfFittingChars(const AbstractEditBoxModel &model, const DeviceContext &dc, INT start_index, XYDIM width) const;
};

class AbstractEditBox;

class EditBoxBlinkTimer : public Timer {
    public:
        typedef Timer Base;
        EditBoxBlinkTimer();
        void SetEditBox(AbstractEditBox *edit_box) { m_edit_box = edit_box; }

    protected:
        virtual void OnTimer();

    private:
        AbstractEditBox *m_edit_box;
};

class AbstractEditBox : public Control {
    typedef Control Base;

    public:
        friend class EditBoxBlinkTimer;

        enum  CaptionPos {
            CaptionOnLeft,
            CaptionOnTop
        };

        AbstractEditBox(Control *parent = 0,
                        WCHAR *buffer = 0,
                        INT max_text_len = 0,
                        const WCHAR *caption = 0,
                        CaptionPos caption_pos = CaptionOnTop,
                        BOOLEAN password_mode = FALSE);

        virtual ~AbstractEditBox();

        void Init(Control *parent,
                  WCHAR *buffer,
                  INT max_text_len = 0,
                  const WCHAR *caption = 0,
                  CaptionPos caption_pos = CaptionOnTop,
                  BOOLEAN password_mode = FALSE);

        void SetCaption(const WCHAR *caption);

        const WCHAR* GetCaption() const { return GetMyModel()->GetCaption(); }

        void SetText(const WCHAR* text);

        WCHAR* GetText() const { return GetMyModel()->GetText(); }

        void SetPasswordMode(BOOLEAN password_mode) { GetMyModel()->SetPasswordMode(password_mode); }

        void SetCursorPos(INT cursor_pos);

        void SetMaxTextLength(INT max_text_len) { GetMyModel()->SetMaxTextLength(max_text_len); }

        INT GetMaxTextLength() const { return GetMyModel()->GetMaxTextLength(); }

        void SetBuffer(WCHAR *buff) { GetMyModel()->SetBuffer(buff); }

        WCHAR* GetBuffer() const { return GetMyModel()->GetBuffer(); }

    protected:
        virtual void Refresh(const Rect &rect);

        virtual BOOLEAN OnInputMap(const InputMapItem &input_map_item);

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual void OnBlinkTimer();

        virtual void OnCursorRight();

        virtual void OnCursorLeft();

        virtual void OnCursorDown();

        virtual void OnCursorUp();

        virtual void OnDeleteChar() {}

        virtual void OnThemeChanged();

        virtual BOOLEAN AcceptChar(WCHAR ch, INT insert_idx) const { return TRUE; };

        BOOLEAN ReplaceChar(WCHAR ch, INT replace_idx = -1);

        BOOLEAN InsertChar(WCHAR ch, INT insert_idx = -1);

        WCHAR GetChar(INT idx = -1) const;

        void SetInputValid(BOOLEAN input_valid) { GetMyModel()->SetInputValid(input_valid); }

        BOOLEAN IsInputValid() const { return GetMyModel()->IsInputValid(); }

        virtual const AbstractEditBoxView* GetView() const = 0;

        void DrawCursor();

        void EraseCursor();

        void InvertCursor();

        virtual void MoveCursor(INT inc);

        void MoveCursorToLine(INT line);

        void SetCursorMode(BOOLEAN paging);

        const PagingMapEntry& GetPagingMapEntry(KeyCode key_code) const;

        void InvalidateText();

        void InvalidateCursor();

        void Layout(INT line_index);

        INT GetNoOfFittingChars(INT start_index, XYDIM width);

        BOOLEAN IsCursorVisible(INT cursor_pos = -1);

        XYDIM GetLineWidth() const;


    private:
        XYDIM                       m_vertical_pos;
        static EditBoxBlinkTimer    m_blink_timer;

        // Returns the x-position of the the upper left
        // edge of the box containing the text.
        XYDIM GetBoxXPos() const;

        // Returns the y-position of the the upper left
        // edge of the box containing the text.
        XYDIM GetBoxYPos() const;

        AbstractEditBoxModel* GetMyModel() const { return (AbstractEditBoxModel *)GetModel(); }

        void AdjustThemeDependencies();
};


#endif  // Apoxi_EditBox_hpp


