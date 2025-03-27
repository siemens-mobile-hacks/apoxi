/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SelfLocationDialogWin_hpp)
#define Mmi_SelfLocationDialogWin_hpp

#include <Common/MmiWindow.hpp>

class SelfLocationDialog : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        SelfLocationDialog();

        virtual ~SelfLocationDialog();

        void Init();


    protected:

        virtual void OnOpen();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

        virtual void OnLayoutClient();


    private:

        TextBox m_label_qos;

        TextBox m_label_hor_acc;

        TextBox m_label_vert_acc;

        TextBox m_label_rsp_time_cat;

        MultiLineEditor m_horiz_accuracy;

        MultiLineEditor m_vert_accuracy;

        MultiLineEditor m_rsp_time_cat;

        TextBox m_label_lcs_cost;

        TextBox m_label_repeat_interval;

        MultiLineEditor m_lcs_cost;

        MultiLineEditor m_repeat_interval;

}; // SelfLocationDialog

#endif // Mmi_SelfLocationDialogWin_hpp
