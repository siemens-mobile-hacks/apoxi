/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ChineseT9InputMapper_hpp)
#define Apoxi_ChineseT9InputMapper_hpp

#include "EnglishT9InputMapper.hpp"
#include <AddOns/T9/ChineseT9Wrapper.hpp>


class ChineseT9InputMapper : public EnglishT9InputMapper {
    typedef EnglishT9InputMapper Base;
    
    public:
        ChineseT9InputMapper(AbstractEditor *editor = 0);

        virtual ~ChineseT9InputMapper();


        virtual const WCHAR* GetStatusInfo() const;

        virtual const WCHAR* GetPhonetics(INT *selected_index = 0) const;

        virtual const WCHAR* GetStrokes() const;

        virtual const WCHAR* GetSelection() const;

        virtual INT GetSelectedIndex() const;
        
        virtual BOOLEAN SetMode(PredMode mode);

        virtual PredMode GetMode() const;

        virtual BOOLEAN IsModeSupported(PredMode mode);

        virtual InputMapper::Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnShortKeyUp_T9(KeyCode apoxi_key_code);

        virtual BOOLEAN OnLongKeyPress_T9(KeyCode apoxi_key_code);
        
        virtual T9Wrapper* GetT9Wrapper();

        virtual const T9Wrapper* GetT9Wrapper() const;
        
    private:
        BOOLEAN OnShortKeyUp_PinYin(KeyCode apoxi_key_code);
        BOOLEAN OnShortKeyUp_Bopomofo(KeyCode apoxi_key_code);
        BOOLEAN OnShortKeyUp_Stroke(KeyCode apoxi_key_code);

        BOOLEAN OnLongKeyPress_Stroke(KeyCode apoxi_key_code);
        BOOLEAN OnLongKeyPress_Bopomofo(KeyCode apoxi_key_code);
        BOOLEAN OnLongKeyPress_PinYin(KeyCode apoxi_key_code);


        typedef T9Wrapper::t9_symbol t9_symbol;
        t9_symbol MapKey_Pinyin(KeyCode apoxi_key_code, BOOLEAN allow_selection = TRUE);
        t9_symbol MapKey_Bopomofo(KeyCode apoxi_key_code, BOOLEAN allow_selection = TRUE);
        t9_symbol MapKey_Stroke(KeyCode apoxi_key_code);
    
        t9_symbol MapKey_ChineseControl(KeyCode apoxi_key_code, BOOLEAN allow_selection = TRUE);


        UINT MapKey_PhoneticDigitSelect(KeyCode apoxi_key_code, BOOLEAN& found);
        UINT MapKey_StrokeDigitSelect(KeyCode apoxi_key_code, BOOLEAN& found);
    
        BOOLEAN HandlePhoneticSelection(KeyCode apoxi_key_code);

        ChineseT9Wrapper m_t9;
};

#endif  // Apoxi_ChineseT9InputMapper_hpp

