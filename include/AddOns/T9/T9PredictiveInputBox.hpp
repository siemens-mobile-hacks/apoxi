/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_T9PredictiveInputBox_hpp)
#define Apoxi_T9PredictiveInputBox_hpp

#include <AddOns/GuiInputExtensions/AbstractPredictiveInputBox.hpp>
#include <AddOns/T9/T9ThaiMatrixModeWindowInterface.hpp>
#include "T9PinyinBox.hpp"
#include "StrokeBox.hpp"
#include "SelectionBox.hpp"

class T9PredictiveInputBox : public AbstractPredictiveInputBox {
    typedef AbstractPredictiveInputBox Base;

    public:
        T9PredictiveInputBox();

        T9PredictiveInputBox(Control* parent, AbstractMultiLineEditor* m_editor, Window* add_word_to_dict_win=0, Window* ext_punc_win=0);

        virtual ~T9PredictiveInputBox();

        void Init(Control* parent, AbstractMultiLineEditor* m_editor, Window* add_word_to_dict_win=0, Window* ext_punc_win=0);
        
        virtual INT GetCapsStatus() const;

        virtual BOOLEAN SetMode(PredInputMapper::PredMode mode);
        
        virtual BOOLEAN AddNewWordToUdb(const WString& word);
        
        virtual void SetThaiMatrixModeWindow (T9ThaiMatrixModeWindowInterface* matrix_mode_window) { m_thai_matrix_mode_window = matrix_mode_window; }

    protected:
        virtual void OnLayoutClient();

        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void UpdateDrawableObjects();

        virtual BOOLEAN RouteMessage(const Message& msg);

    private:
        T9PinyinBox     m_pinyin_box;
        StrokeBox       m_stroke_box;
        SelectionBox    m_selection_box;
        T9ThaiMatrixModeWindowInterface*    m_thai_matrix_mode_window;
};

#endif  // Apoxi_T9PredictiveInputBox_hpp


