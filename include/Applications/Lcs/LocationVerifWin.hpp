/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LocationVerifWin_hpp)
#define Mmi_LocationVerifWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <Gui/Action.hpp>

class LocationVerifWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        LocationVerifWin();

        virtual ~LocationVerifWin();

        void Init();

        void SetData(INT invoke_id, const WString& text) { m_invoke_id = invoke_id; m_verif_text = text; }

        void SetTime(WString time_str);


    // Implementation for derived classes
    protected:

        virtual void OnOpen();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();


    private:

        TextBox m_verif_text_box;

        WString m_verif_text;

        UINT16 m_invoke_id;

        ConfirmAction m_resp_yes_action;

        CancelAction m_resp_no_action;

        SoftkeyBar  m_softkey_bar;

        WString m_real_time;

}; // LocationVerifWin

#endif // Mmi_LocationVerifWin_hpp
