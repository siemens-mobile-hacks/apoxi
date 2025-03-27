/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EnglishT9InputMapper_hpp)
#define Apoxi_EnglishT9InputMapper_hpp

#include "T9InputMapper.hpp"
#include <AddOns/T9/T9Wrapper.hpp>

class EnglishT9InputMapper : public T9InputMapper {
    typedef T9InputMapper Base;
    
    public:
        EnglishT9InputMapper(AbstractEditor *editor = 0);

        virtual ~EnglishT9InputMapper();

        virtual const WCHAR* GetStatusInfo() const;
        
        virtual InputMapper::Alphabet GetAlphabet() const;

        virtual BOOLEAN SetMode(PredMode mode);

        virtual PredMode GetMode() const;

        virtual BOOLEAN IsModeSupported(PredMode mode);

    protected:
        T9NUM GetLdbNumForMode(PredMode mode) const;

        virtual BOOLEAN OnShortKeyUp_T9(KeyCode key_code);

        virtual BOOLEAN OnLongKeyPress_T9(KeyCode apoxi_key_code);

        WCHAR MapKeyToCharacter_Numbers(KeyCode apoxi_key_code);

        T9Wrapper::t9_symbol MapKey_English(KeyCode apoxi_key_code);

        T9Wrapper::t9_symbol MapKey_English_Alphabetic(KeyCode apoxi_key_code);

        virtual T9Wrapper* GetT9Wrapper();

        virtual const T9Wrapper* GetT9Wrapper() const;


    private:
        //Member data:
        T9Wrapper   m_t9;
        BOOLEAN     m_thai_matrix_mode;
};

#endif  // Apoxi_EnglishT9InputMapper_hpp

