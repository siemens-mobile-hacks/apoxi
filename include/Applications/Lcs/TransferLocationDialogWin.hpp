/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_TransferLocationDialogWin_hpp)
#define Mmi_TransferLocationDialogWin_hpp

#include <Common/MmiWindow.hpp>

class TransferLocationDialog : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        TransferLocationDialog();

        virtual ~TransferLocationDialog();

        void Init();
            

    protected:

        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

        virtual void OnLayoutClient();


    private:

        TextBox m_label_mlc_number;

        TextBox m_label_client_id;

        LineEditor m_client_id;

        LineEditor m_mlc_number;

}; // TransferLocationDialog

#endif // Mmi_TransferLocationDialogWin_hpp
