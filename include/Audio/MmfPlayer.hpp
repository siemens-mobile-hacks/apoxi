/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MmfPlayer_hpp)
#define Apoxi_MmfPlayer_hpp

#include <Audio/AudioPlayer.hpp>
#include <Kernel/MessageHook.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <AddOns/MediaFramework/MediaManager.hpp>
#include <AddOns/MediaFramework/MediaInfo.hpp>

class GenericFeatureData;

class MmfPlayer : public AudioPlayer
{
    public:
        virtual BOOLEAN IsFeatureSupported(Feature feature, MimeType mime_type = c_mime_unknown, AudioReference::SoundDataSource sound_data_source = AudioReference::InvalidSoundDataSource) const;
        virtual BOOLEAN ExecuteFeature(Feature feature, GenericObject* data = 0);       
        
        virtual BOOLEAN GetTotalPlayTime(AudioActiveReference &active_reference);
        virtual BOOLEAN GetPlayPosition(AudioActiveReference &active_reference);        

        virtual void Play(AudioActiveReference& active_reference);
        virtual void Stop(AudioActiveReference& active_reference);
        virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;
        virtual void Suspend(AudioActiveReference& active_reference);
        virtual void ResumeSuspended(AudioActiveReference& active_reference);
        virtual void StopSuspended(AudioActiveReference& active_reference);

        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;
        
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRfsFile(MimeType mime_type, const Path& path);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, ConstBuffer buffer, UINT32 buffer_size);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromBinData(MimeType mime_type, BinData* bin_data);
    
        BOOLEAN OnMessage(const Message &message);
        static AudioDeviceBase* GetInstance();
        
        virtual AudioSource GetSource() const { return AudioDeviceBase::DspAudioSource; }
        virtual UINT16 GetDeviceID() const { return 0; }    
        
    protected:
        virtual BOOLEAN ApplyDeviceVolume();
        
        BOOLEAN FastForward(GenericFeatureData* data);
        BOOLEAN Rewind(GenericFeatureData* data);
        BOOLEAN GetTrackInfo(GenericFeatureData* data);
        BOOLEAN GetAudioTrackInfo(GenericFeatureData* data);

        struct MediaPlayerInstanceData {
            MediaInfo* info;
            MediaPlayer* m_media_player;
            BinData* m_bin_data;
            BOOLEAN m_bin_data_provided;    
            AudioActiveReference* m_active_ref;     
        };
        
        void AddDataMapping(MmfPlayer::MediaPlayerInstanceData& instance_data, MediaPlayer* media_player);
        void RemoveDataMapping(MediaPlayer* media_player);
        MmfPlayer::MediaPlayerInstanceData FindData(MediaPlayer* media_player);         
        
    private:
        MmfPlayer();
        
        virtual ~MmfPlayer();
        
        MmfPlayer(const MmfPlayer& obj);
        
        void OnPlaybackStopped(MediaPlayer* media_player);

        // this has to be avoided as soon as possible
        // it is just not to violate the current pulic interfaces
        friend class AudioActiveReference;
        void SetActiveReference(const AudioActiveReference* active_ref);
        const AudioActiveReference* m_temp_active_ref;
        
        static MmfPlayer m_singleton_instance;
        //MediaInfo info;
        //MediaPlayer* m_media_player;
        //BinData* m_bin_data;
        //BOOLEAN m_bin_data_provided;
            
        SimpleMap<MediaPlayer*, MediaPlayerInstanceData> m_media_player_to_data_map;

};

#endif  // Apoxi_MmfPlayer_hpp

