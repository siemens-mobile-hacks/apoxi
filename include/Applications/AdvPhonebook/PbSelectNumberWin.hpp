/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbSelectNumberWin_hpp)
#define Mmi_PbSelectNumberWin_hpp

#include <Gui/Lib.hpp>

#include <Gui/Action.hpp>
#include <AdvPhonebook/PbPhoneNumberPrompt.hpp>
#include <AdvPhonebook/PbBaseWin.hpp>
#include <AdvPhonebook/ProvListBoxWin.hpp>


class PbSelectNumberWin : public PbBaseWin {
    public:
        typedef PbBaseWin Base;

        PbSelectNumberWin();
        virtual ~PbSelectNumberWin();

        void Init(Provider *pb_provider = 0);

        void EnterNumber();
        
        PhoneNumber GetSelectedNumber() const { return m_selected_number; };

    protected:
        virtual void OnOpen();
        virtual BOOLEAN OnConfirm();
        virtual BOOLEAN OnCancel();
        virtual void OnActionExecuted(Action *action);

    private:
        PhoneNumber             m_selected_number;
        
        ConfirmAction           m_confirm_action;
        Action                  m_enter_no_action;

        PbPhoneNumberPrompt     m_enter_no_win;
        ProvColListBoxWin       m_no_win;

};

#endif  // Mmi_PbSelectNumberWin_hpp
