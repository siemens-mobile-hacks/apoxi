/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(FmRadioEditWin_hpp)
#define FmRadioEditWin_hpp

#include <Common/MmiWindow.hpp>

class FmRadioEditWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        FmRadioEditWin();
        ~FmRadioEditWin();

        void Init(INT BandLim);

    protected:
        BOOLEAN OnCancel();
        BOOLEAN OnConfirm();
        void OnLayoutClient();

    private:
//      RadioAudioDevice::BandLimits m_band_lim;
        TextLine            m_phone_no_text;    
        LineEditor          m_freq_editor;
};

#endif 

