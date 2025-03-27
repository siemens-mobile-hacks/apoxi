/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_AbstractPredictiveInputBox_hpp)
#define Apoxi_AbstractPredictiveInputBox_hpp

#include <Gui/Window.hpp>
#include <Gui/AbstractMultiLineEditor.hpp>
#include <Gui/PredInputMapper.hpp>
#include <Gui/Control.hpp>
#include <Config/KeyboardConfig.hpp>

class AbstractPredictiveInputBox : public Control {
    typedef Control Base;

    public:
        enum PredFontId {
            // Font for the indicess of the selection box
            SelectionBoxIndexId,
            // Font for the simplified chinese in the selection box
            SelectionBoxSimpId,
            // Font for the traditional chinese in the selection box
            SelectionBoxTradId,
            // Font for chinese in the selection box
            SelectionBoxChineseId,
            // Font for the strokes in the stroke box
            StrokeBoxId,
            // Font for BoPoMoFo in the pinyin box
            PinyinBoxNumbersId,
            // component font for Zi8 
            SelectionBoxComponentsId,
            //default
            PinyinBoxCharsId
            
        };

        enum PredBitmapId {
            UpDownArrowBitmapId,
            DownArrowBitmapId,
            UpArrowBitmapId,
            SelectBitmapId
        };

        AbstractPredictiveInputBox();

        AbstractPredictiveInputBox(Control* parent, AbstractMultiLineEditor* m_editor, Window* add_word_to_dict_win=0, Window* ext_punc_win=0);

        virtual ~AbstractPredictiveInputBox();

        void Init(Control* parent, AbstractMultiLineEditor* m_editor, Window* add_word_to_dict_win=0, Window* ext_punc_win=0);
        
        virtual BOOLEAN SetMode(PredInputMapper::PredMode mode);

        PredInputMapper::PredMode GetMode() const;

        virtual BOOLEAN IsModeSupported(PredInputMapper::PredMode mode);

        virtual INT GetCapsStatus() const = 0;

        virtual BOOLEAN AddNewWordToUdb(const WString& word) = 0;

    protected:
        virtual void OnGetFocus();

        virtual void UpdateDrawableObjects() = 0;

        // TODO: don't use protected members, make them private and provide getter methods
        AbstractMultiLineEditor* m_editor;
        Window* m_ext_punc_win;
        Window* m_add_word_to_dict_win;
        
    private:
        BOOLEAN HasPredInputMapper() const;
};

#endif  // Apoxi_AbstractPredictiveInputBox_hpp


