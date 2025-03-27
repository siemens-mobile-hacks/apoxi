/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundBrowserTestWin_hpp)
#define Apoxi_SoundBrowserTestWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

class IMelody;

class SoundBrowserTestWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        SoundBrowserTestWin();
        virtual ~SoundBrowserTestWin();
        
        void Init();

    protected:
        virtual BOOLEAN OnCancel();
        virtual void OnLayoutClient();
        virtual void OnActionExecuted(Action *action);

    private:
        ImageBox m_image_box;
        TextBox m_text_box;

        ActionAccessor m_accessor;

        Action m_select_action;
        Action m_save_action;

        CancelAction m_cancel_action;

        INT m_current_sound;
        IMelody *m_sounds[3];
};

#endif  // Apoxi_SoundBrowserTestWin_hpp
