/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EditBox_hpp)
#define Apoxi_EditBox_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <Compat/AbstractEditBox.hpp>
#include <Gui/Lib.hpp>


class EditBoxModel : public AbstractEditBoxModel {
};

class EditBoxView : public AbstractEditBoxView {
    typedef AbstractEditBoxView Base;

    public:
        EditBoxView();
        EditBoxView(XYDIM line_height,
                        XYDIM caption_gap,
                        XYDIM caption_width,
                        XYDIM caption_height, 
                        XYDIM frame_size,
                        XYDIM default_width = -1,
                        XYDIM default_height = -1);

        virtual ~EditBoxView();

        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;

    protected:
        virtual void DrawEditBox(const EditBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

class EditBox;

class EditBoxPagingTimer : public Timer {
    public:
        typedef Timer Base;
        EditBoxPagingTimer();
        void SetEditBox(EditBox *edit_box) { m_edit_box = edit_box; }

    protected:
        virtual void OnTimer();

    private:
        EditBox *m_edit_box;
};


class EditBox : public AbstractEditBox {
    public:
        typedef AbstractEditBox Base;

        friend class EditBoxPagingTimer;

        enum EditMode {
            AlphanumMode,
            AlphanumNameMode,
            NumericMode,
            PhoneNumberMode,
            PredInputMode,
        };

        enum DeleteMode {
            DelLeftCharMode,
            DelCurrCharMode
        };

        enum ShiftState {
            OffShiftstate,
            OnShiftstate,
            LockedShiftstate
        };

        EditBox();

        EditBox(Control *parent,
                WCHAR *text = 0,
                INT max_text_len = 0,
                EditMode edit_mode = AlphanumMode, 
                const WCHAR *caption = 0,
                CaptionPos caption_pos = CaptionOnTop);

        virtual ~EditBox();

        void Init(Control *parent,
                  WCHAR *text = 0,
                  INT max_text_len = 0,
                  EditMode edit_mode = AlphanumMode, 
                  const WCHAR *caption = 0,
                  CaptionPos caption_pos = CaptionOnTop);

        void SetEditMode(EditMode edit_mode);

        EditMode GetEditMode() const { return (EditMode)m_bits.edit_mode; }

        void SetDeleteMode(DeleteMode delete_mode) { m_bits.delete_mode = delete_mode; }

        DeleteMode GetDeleteMode() const { return (DeleteMode)m_bits.delete_mode; }

    protected:
        virtual Model* CreateModel() const;

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnInputMap(const InputMapItem &input_map_item);

        virtual void OnShiftKey();

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual void OnPagingTimer();

        virtual void OnDeleteChar();

        virtual void OnDtmfSeparator();

        virtual void OnPlus();

        virtual void OnWildcard();

        virtual const AbstractEditBoxView* GetView() const;

        virtual void MoveCursor(INT inc);

    private:
        struct {
            UINT edit_mode      : 2;
            UINT delete_mode    : 1;
            UINT shift_state    : 2;
            UINT i_paging       : 5;
        } m_bits;
        KeyCode         m_prev_key;
        static EditBoxPagingTimer m_paging_timer;
        static EditBoxView m_view;

        EditBoxModel* GetMyModel() const { return (EditBoxModel *)GetModel(); }

        BOOLEAN GetAcceptableChar(const WCHAR *presentation, INT insert_idx);

        void SetShiftState(ShiftState state) { m_bits.shift_state = state; };
        ShiftState GetShiftState() const { return (ShiftState)m_bits.shift_state; };
};

typedef EditBox::ShiftState EditBoxShiftState;

#ifndef APOXI_NOSTREAMING

InputStream & operator >> (InputStream & istr, EditBoxShiftState val);

#endif


#endif  // Apoxi_EditBox_hpp


