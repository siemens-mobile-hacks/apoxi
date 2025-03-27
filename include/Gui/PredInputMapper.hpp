/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PredInputMapper_hpp)
#define Apoxi_PredInputMapper_hpp

#include <Gui/InputMapper.hpp>

class PredInputMapper : public InputMapper {
    typedef InputMapper Base;

    
    public:
        enum Type {
            T9,
            Zi8
        };

        explicit PredInputMapper(AbstractEditor* editor = 0);

        virtual ~PredInputMapper();

        virtual Type GetType() const = 0;

        //TODO: Why not return a WString? murrayc
        virtual const WCHAR* GetStatusInfo() const = 0;

        virtual const WCHAR* GetPhonetics(INT* selected_idx = 0) const = 0;

        virtual const WCHAR* GetStrokes() const = 0;

        virtual const WCHAR* GetSelection() const = 0;
        
        virtual INT GetSelectedIndex() const = 0;


        enum PredMode {
            PredEnglish,
            PredMultiTap,
            PredPinyin,
            PredSimplifiedChineseStroke,
            PredTraditionalChineseStroke,
            PredBpmf,
            PredNone,
            PredSymbol,

            PredArabic,

            PredThai,
            
            PredThaiMatrix,

            PredHebrew
        };

        virtual BOOLEAN SetMode(PredMode mode) = 0;

        virtual PredMode GetMode() const = 0;

        virtual BOOLEAN IsModeSupported(PredMode mode) = 0;

    protected:
        virtual BOOLEAN OnKeyDown (KeyCode key_code);

        BOOLEAN m_number_input_mode;
};

#endif  // Apoxi_PredInputMapper_hpp

