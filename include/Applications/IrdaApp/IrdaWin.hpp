/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_IrdaWin_hpp)
#define Mmi_IrdaWin_hpp

#include <Gui/CheckBoxAction.hpp>
#include <GuiExtensions/MmiMenuWindow.hpp>
#include <GuiExtensions/MmiProgressBox.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include <Devices/AbstractTransport.hpp>

class IrdaWin : public MmiMenuWindow {
    typedef MmiWindow Base;
    public:


        IrdaWin();
        ~IrdaWin();
        void Init();
        void ToggleSelection();
    protected:
        virtual void OnActionExecuted(Action *action);
        virtual void OnClose();
        virtual void OnOpen();
    private:
        CheckBoxAction m_disable_action;
        MmiProgressBox m_hour_glass;
        Action m_select_action;
        Action m_close_action;
        ActionAccessor m_accessor;
        AbstractTransport::AvState m_state;

        void DisplayAlert(const WCHAR *msg);


};
#endif  // Mmi_IrdaApp_hpp


