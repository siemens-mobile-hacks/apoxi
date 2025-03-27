/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Zi8PredictiveInputBox_hpp)
#define Apoxi_Zi8PredictiveInputBox_hpp

#include <AddOns/GuiInputExtensions/AbstractPredictiveInputBox.hpp>
#include <AddOns/Zi8/Zi8InputMapper.hpp>
#include <AddOns/Zi8/Zi8AlphabetBox.hpp>
#include <AddOns/Zi8/Zi8StrokeBox.hpp>
#include <AddOns/Zi8/Zi8SelectionBox.hpp>

class Zi8PredictiveInputBox : public AbstractPredictiveInputBox {
    typedef AbstractPredictiveInputBox Base;

    public:
        Zi8PredictiveInputBox();

        Zi8PredictiveInputBox(Control* parent,
                              AbstractMultiLineEditor* m_editor,
                              Window* add_word_to_dict_win = 0,
                              Window* ext_punc_win = 0);

        virtual ~Zi8PredictiveInputBox();

        void Init(Control* parent,
                  AbstractMultiLineEditor* m_editor,
                  Window* add_word_to_dict_win = 0,
                  Window* ext_punc_win= 0);

        virtual INT GetCapsStatus() const;

        virtual BOOLEAN SetMode(PredInputMapper::PredMode mode);

        virtual BOOLEAN AddNewWordToUdb(const WString& word);

    protected:
        virtual void OnLayoutClient();

        virtual void UpdateDrawableObjects();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual BOOLEAN RouteMessage(const Message& msg);
        
    private:
        Zi8AlphabetBox  m_zi8_alphabet_box;
        Zi8StrokeBox    m_zi8_stroke_box;
        Zi8SelectionBox m_zi8_selection_box;
};

#endif  // Apoxi_Zi8PredictiveInputBox_hpp


