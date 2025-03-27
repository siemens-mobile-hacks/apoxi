/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsSendingConfirmDialog_hpp)
#define Mmi_SmsSendingConfirmDialog_hpp

#include <Common/MmiDialog.hpp> 

class SmsSendingConfirmDialog : public MmiDialog {
    typedef MmiDialog Base;

    public:
        SmsSendingConfirmDialog();
        ~SmsSendingConfirmDialog();
        void Init();
        void SetAddressText(const WString& text)            { m_address = text; }
        void SetTelematicDeviceText(const WString& text)    { m_device = text; }
        void SetValidityPeriod(const ValidityPeriod& vp);
        void SetSegmentCount(INT segment_count);

    protected:
        void OnOpen();

    private:
        SmsSendingConfirmDialog(const SmsSendingConfirmDialog& cds);
        SmsSendingConfirmDialog& operator=(const SmsSendingConfirmDialog& cds);
        WString m_address;
        WString m_device;
        WString m_period;
        WString m_segment_info;
        WString m_text;
        MultiLineEditor m_text_area;
};

#endif  // Mmi_SmsSendingConfirmDialog_hpp
