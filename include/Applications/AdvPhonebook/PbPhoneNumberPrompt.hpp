/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbPhoneNumberPrompt_hpp)
#define Mmi_PbPhoneNumberPrompt_hpp

#include <GuiExtensions/MmiPhoneNumberPrompt.hpp>

class PbPhoneNumberPrompt;
class SaveNoAction : public Action {
    typedef Action Base;

    public:
        SaveNoAction(PbPhoneNumberPrompt *win);
        virtual ~SaveNoAction();

        BOOLEAN Execute();

    private:
        PbPhoneNumberPrompt *m_parent;
};

class PbPhoneNumberPrompt : public MmiPhoneNumberPrompt {
    typedef MmiPhoneNumberPrompt Base;
    
    public:

        PbPhoneNumberPrompt();
        virtual ~PbPhoneNumberPrompt();

        //
        void Init();

        //
        void SavePhoneNo();

    protected:
        virtual void OnOpen();

    private:
        SaveNoAction        m_save_no_action;

};

#endif  // Mmi_PbPhoneNumberPrompt_hpp
