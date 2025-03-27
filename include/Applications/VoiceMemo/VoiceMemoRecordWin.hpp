/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_VoiceMemoRecordWin_hpp)
#define Mmi_VoiceMemoRecordWin_hpp

#include <Auxiliary/WStrUtil.hpp>
#include <Auxiliary/DrmInfo.hpp>
#include <AddOns/Services/ServiceBroker.hpp>
#include <AddOns/Services/Service.hpp>

#include <Common/MmiServices.hpp>
#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/MmiAlert.hpp>
#include <Devices/VoiceMemoAudioPlayer.hpp>
#include <Devices/VoiceMemoAudioReference.hpp>

class VoiceMemoRecordWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        VoiceMemoRecordWin();
        ~VoiceMemoRecordWin();
        void Init();
        SharedPtr<AudioActiveReference> Record(
                                    VoiceMemoAudioReference::Mode mode);
        BOOLEAN StopRecord(VoiceMemoAudioReference::Mode mode);
        BOOLEAN PauseRecord();
        BOOLEAN ResumeRecord();

        SharedPtr<AudioActiveReference>& GetAudioRef() { return m_audio_ref; }

    private:
        TextBox     m_time_elapsed;
        Timer       m_timer;
        TextBox     m_file;
        TextBox     m_filename;
        //TextBox       m_used_space;


        UINT32      m_counter;
        
        SharedPtr<AudioActiveReference>     m_audio_ref;
        SharedPtr<StreamAudioReference>     m_voicememo_ref;
        VoiceMemoAudioPlayer*               m_voicememo_player;
        WString                             m_user_file_name;

        void ShowAlert(const WString& str);

    protected:
        virtual void OnLayoutClient();
        virtual void OnClose();
        virtual BOOLEAN  OnTimeout(const Timer& timer);
};

#endif  // Mmi_VoiceMemoRecordWin_hpp
