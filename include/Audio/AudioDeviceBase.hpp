/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioDeviceBase_hpp)
#define Apoxi_AudioDeviceBase_hpp

#include <Auxiliary/MimeTypeTable.hpp>
#include <Audio/AudioReference.hpp>

class AudioActiveReference;
class AudioReference;
class GenericObject;
class Mutex;

//@TODO move to its own file
class NonCopyable
{
 protected:
    NonCopyable() {}
    ~NonCopyable() {}
 private:
    NonCopyable( const NonCopyable& );
    const NonCopyable& operator=( const NonCopyable& );
};

class AudioDeviceBase : public NonCopyable
{
    public:
        AudioDeviceBase();
        virtual ~AudioDeviceBase();     

        enum PredefinedFeature {
            SetTimeFeature,
            GetTimeFeature,
            MmfSuspendFeature,
            MmfResumeFeature,
            
            GenericFastForward,
            
            GenericRewind,
            
            GenericGetTrackInfo,            
            
            MmfGetAudioTrackInfo,
            
            FmRadioSeekStationFeature,
            
            FmRadioSetStationFeature,
            
            FmRadioRssiLevelFeature,
            
            FmRadioRdsFeature,
            
            FmRadioRdsStationNameFeature,
            
            FmRadioRdsRadioTextFeature,
            
            FmRadioRdsRawDataFeature,
            
            FmRadioRdsAlternativeFrequenciesFeature,
            
            PredefinedFeatureEnd
        };

        typedef INT Feature;

        virtual BOOLEAN IsFeatureSupported(Feature feature, MimeType mime_type = c_mime_unknown, AudioReference::SoundDataSource sound_data_source = AudioReference::InvalidSoundDataSource) const {return FALSE;}

        virtual BOOLEAN ExecuteFeature(Feature feature, GenericObject* data = 0) {return FALSE;}

        typedef AudioReference::VolumeLevel VolumeLevel;
        
        enum MuteDirection
        {   
            UplinkDirection, 
            DownlinkDirection,
            UpDownlinkDirection, 
        };

        VolumeLevel GetVolume() const;
                
        BOOLEAN SetVolume(VolumeLevel volume);

        BOOLEAN SetMasterVolume(VolumeLevel volume);
        
        VolumeLevel GetMasterVolume() const {
            return m_master_volume;
        }
        
        
                
        BOOLEAN SetDeviceVolume(VolumeLevel volume);        
                
        VolumeLevel GetDeviceVolume() const {
            return m_device_volume;
        }
        
        virtual BOOLEAN SetMute(BOOLEAN enable = TRUE, MuteDirection direction = UpDownlinkDirection);      

        // @todo this should go to the SimpleDevices
        typedef enum {
            StatusEnabled,
            StatusDisabled
        } AudioDeviceStatus;
            
        enum AudioErrorType {
            NoErrorType = 0,
            FileOperationErrorType,
            InvalidFormatErrorType,
            GeneralErrorType
        };

        enum StopCause {
            InvalidCause = 0, //< if an application gets this, something is wrong
            DriverCause, //< the driver stopped the sound because 1. playback finished to completion, or 2. some unspecified driver problem occurred
            VoluntaryCause, //< the application stopped the sound
            PriorityManagementCause, //< APOXI priority management stopped the sound in order to make room for another one
            TimerCause //< the active reference's timer has timed out
        };

        virtual UINT16 GetDeviceID() const = 0;
        
#ifndef DOXYGEN_SHOULD_SKIP_THIS

        enum PredefinedAudioSource
        {
            InvalidAudioSource = 0,
            DspAudioSource,
            RingerAudioSource,
            FmRadioAudioSource
        };

        typedef INT AudioSource;
        typedef AudioSource AudioSourceType;

        virtual AudioSource GetSource() const = 0;      
        
#endif //DOXYGEN_SHOULD_SKIP_THIS

        // xxx internal
        //BOOLEAN UpdateReferenceVolume(const AudioActiveReference& active_reference, VolumeLevel reference_volume);
        virtual BOOLEAN UpdateReferenceVolume(const AudioActiveReference& active_reference);
    private:        
        VolumeLevel m_master_volume;
        VolumeLevel m_device_volume;
    
#if 1 // todo: remove

    protected:
        virtual BOOLEAN ApplyDeviceVolume();
        virtual BOOLEAN ApplyMasterVolume();
        
        //VolumeLevel m_volume;
        //VolumeLevel m_playing_volume;
        BOOLEAN m_mute;     

        

        VolumeLevel GetVolume_Specific(const AudioReference &audio_ref);

        static Mutex* GetMutex();

#endif

};

#endif  // Apoxi_AudioDeviceBase_hpp

