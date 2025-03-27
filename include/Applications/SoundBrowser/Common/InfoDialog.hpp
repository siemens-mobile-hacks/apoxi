/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_InfoDialog_hpp)
#define Apoxi_InfoDialog_hpp

#include <GuiExtensions/MmiDialog.hpp>
#include <Gui/TextBox.hpp>

class InfoDialog : public MmiDialog
{
    typedef MmiDialog Base;

    public:
        InfoDialog();
        virtual ~InfoDialog();

        void Init();

        void SetText(const WString &text);

    protected:
        virtual BOOLEAN OnConfirm();

        virtual void OnLayoutClient();

    private:
        TextList m_text_box;
        WString m_text;
};

#endif  // Apoxi_InfoDialog_hpp
