/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundBrowserWin_hpp)
#define Apoxi_SoundBrowserWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include <Common/MmiWaitingBox.hpp>
#include <Devices/AudioActiveReference.hpp>
#include <SoundBrowser/Common/BrowserViewContainer.hpp>
#include <SoundBrowser/Common/RenameFileDialog.hpp>
#include <SoundBrowser/Common/FileNameView.hpp>

#include <ImageBrowser/Common/InfoDialog.hpp>
#include <SoundBrowser/SoundRef.hpp>

class SoundRef;
class SoundRefContainer;
class SoundFilter;

class SoundBrowserWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        SoundBrowserWin();
        virtual ~SoundBrowserWin();

        void Init(BooleanCondition &condition, SoundRefContainer &snd_refs);

        BOOLEAN SetSoundFilter(const SoundFilter &snd_filter, BOOLEAN show_select_button);

        MediaRefPtr& GetSelectedSoundRef();

        BOOLEAN GetSuccess() const;
        void OnErrorNotification(const SharedPtr<AudioReference>& audio_reference,
                                AudioError::ErrorType err_no);

        void OnStopNotification(const SharedPtr<AudioActiveReference>& active_reference, BOOLEAN auto_stop);

    protected:
        virtual void OnLayoutClient();
        virtual BOOLEAN OnCancel();
        virtual BOOLEAN OnConfirm();
        void OnOpen();
        virtual void OnClose();
        virtual void OnActionExecuted(Action *action);
        virtual BOOLEAN OnMessage(const Message & msg);

        virtual BOOLEAN OnKeyDown(KeyCode key_code);


        void PlaySelectedSound();
        void StopSound();

    private:
        void DisplayAlert(const WCHAR *msg);

        ConfirmAction m_confirm_action;
        CancelAction m_cancel_action;
        Action m_delete_action;
        Action m_rename_action;
        Action m_play_action;
        Action m_stop_action;
        ActionAccessor m_accessor;
        Action m_info_action;
        Action m_drm_info_action;
        MmiWaitingBox m_waiting_box;

        BrowserViewContainer m_views;
        FileNameView m_fnv;

        SoundRefContainer *m_snd_refs;

        BooleanCondition *m_condition;
        BOOLEAN m_success;

        SharedPtr<AudioActiveReference> m_active_file_ref;

        UINT8 HUGE* m_current_sound_buffer;
        BOOLEAN m_is_sound_playing;

        RenameFileDialog m_rename_file_dialog;
        SoundRef* m_current_sound_ref;
        InfoDialog m_info_dialog;
};

#endif  // Apoxi_SoundBrowserWin_hpp
