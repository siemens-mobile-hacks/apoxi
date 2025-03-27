/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_BtHsVolumeSettingsWin_hpp)
#define Mmi_BtHsVolumeSettingsWin_hpp

#include <Gui/Lib.hpp>

#include <Gui/ItemMenu.hpp>
#include <Common/MmiWindow.hpp>
#include <Common/AudioRequest.hpp>

#include "BtHsProfileService.hpp"

// Define min & max audio volume level as defined in Bluetooth SIG
#define MIN_VOLUME_LEVEL 0
#define MAX_VOLUME_LEVEL 15

class BtHsVolumeSettingsWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        BtHsVolumeSettingsWin(BtHsProfileService& service);

        virtual ~BtHsVolumeSettingsWin();

        void Init();

        enum AudioGain
        {
            MicGain = 0,
            SpeakerGain
        };

    protected:

        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnLayoutClient();
        virtual void OnOpen();
        virtual BOOLEAN OnConfirm();
        virtual BOOLEAN OnCancel();

    private:
        void DecreaseBtHsVolume();

        void IncreaseBtHsVolume();

        BOOLEAN SwitchBtHsVolume();

        void UpdateProgressBar();

        Item m_speaker_item;
        Item m_microphone_item;
        ItemMenu                m_item_menu;
        AudioGain               m_mic_speaker;
        ProgressBar             m_progress_bar;
        UINT8                   m_speaker_gain;
        UINT8                   m_microphone_gain;

        BtHsProfileService      &m_bt_hs_service;
};

#endif  // Mmi_BtHsVolumeSettingsWin_hpp
