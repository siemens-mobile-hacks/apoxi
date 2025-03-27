/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MapiAudioPlayer_hpp)
#define Apoxi_MapiAudioPlayer_hpp

#include <Audio/DwdPlayer.hpp>
#include <Audio/AudioPlayer.hpp>
#include <AddOns/YamahaMapi/AudioMapiManager.hpp>

class MapiAudioReference;

class MapiAudioPlayer: public DwdPlayer
{

    public:
    
        friend class AudioMapiManager;
    
    
        virtual void Play(AudioActiveReference& active_reference);
        virtual void Stop(AudioActiveReference& active_reference);
        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;
    
        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;
        
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromExtensionSoundDataSource(MimeType mime_type, AudioReference::SoundDataSource sound_data_source);  
    
        void SetStopCallback(BOOLEAN (*cb_stop)(const AudioActiveReference &active_ref) );

        static MapiAudioPlayer* GetInstance();
        
        virtual UINT16 GetDeviceID() const;
        virtual AudioPlayer::AudioSourceType GetSource() const;

    
    protected:

        virtual BOOLEAN OnSdlSignal(UINT16 func_id, UINT8 handle, UINT16 drv_id, INT8 return_code, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
        virtual AudioMapiManager::RequestOutcomeType ForwardCommandToDriver(AudioMapiManager::MapiCommandType &command);
        virtual BOOLEAN Play_Allocate(AudioActiveReference &playing_ref);
        
        BOOLEAN StopCallbackHaveBeenSet() const;
        BOOLEAN (*m_cb_stop)(const AudioActiveReference &active_ref);
        static void SetCommandExecutedCondition(UINT32 parm1, UINT32 parm2);
    
    private:
        MapiAudioPlayer();
        virtual ~MapiAudioPlayer();
        static MapiAudioPlayer m_singleton_instance;
};

#endif // Apoxi_MapiAudioPlayer_hpp

