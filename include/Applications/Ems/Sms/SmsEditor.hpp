/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsEditor_hpp)
#define Mmi_SmsEditor_hpp


/*
#include <Gui/LineEditor.hpp>
#include <Gui/TextEditorDocument.hpp>
#include "GuiExtensions/MmiWindow.hpp"
#include <Gui/InputMapper.hpp>
#include <Gui/View.hpp>
#include <Apc/Sms.hpp>
*/
class DefaultCaret;
class AbstractMmiPrompt;
class SmsComposeWin;

#include <Config/SmsCustomizationConfig.hpp>

class SmsEditor : public MultiLineEditor {
    typedef MultiLineEditor Base;

    public:
        SmsEditor();

            SmsEditor(Control* parent,
                   INT input_mapper_id,
                   INT max_char_limit = 10,
                   const WCHAR* text = 0);

        virtual ~SmsEditor();

        void Init(Control* parent,
                  INT input_mapper_id,
                  INT max_char_limit = 10,
                  const WCHAR* text = 0);

    public:

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);


        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Backspace();

        virtual void OnGetFocus();

        virtual SmsComposeWin* GetComposeWin();

        virtual void ResetCounter();



        UINT8 CalcFreeChars(InputMapper::Alphabet mode);

        UINT8 GetMaxPduSize() const { return SmsSubmit::c_max_guaranteed_user_data_size;}

    private:
        INT32       m_max_chars;

        INT32       m_count;

        INT32       m_seg_count;

        INT32       m_totalseg_count;

        INT32       m_free_char;

        INT32       m_last_cnt;

        // << Fix for SMS00044556
        INT32       m_char_in_segment_1;
        INT32       m_char_in_segment_2;
        INT32       m_char_in_segment_rest;
        // >> Fix for SMS00044556

        static INT32        m_current_segment_count;

        WString m_str;  
};

#endif  // Mmi_SmsEditor_hpp
