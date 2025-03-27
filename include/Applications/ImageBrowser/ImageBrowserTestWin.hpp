/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageBrowserTestWin_hpp)
#define Apoxi_ImageBrowserTestWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

class IMelody;

class ImageBrowserTestWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        ImageBrowserTestWin();
        virtual ~ImageBrowserTestWin();
        
        void Init();

    protected:
        virtual BOOLEAN OnCancel();
        virtual void OnLayoutClient();
        virtual void OnActionExecuted(Action *action);

    private:
        ImageBox m_image_box;
        TextBox m_text_box;

        ActionAccessor m_accessor;

        // For sounds.
        Action m_select_snd_action;
        Action m_save_snd_action;
        Action m_get_cnt_snd_action;
        Action m_get_names_snd_action;

        // For images.
        Action m_select_img_action;
        Action m_save_img_action;
        Action m_get_cnt_img_action;
        Action m_get_names_img_action;

        CancelAction m_cancel_action;

        INT m_current_image;
        Image *m_images[4];
        INT m_current_sound;
        IMelody *m_sounds[3];
};

#endif  // Apoxi_ImageBrowserTestWin_hpp
