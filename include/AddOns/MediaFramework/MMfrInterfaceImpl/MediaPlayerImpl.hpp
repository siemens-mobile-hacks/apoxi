/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef MediaPlayerImpl_hpp
#define MediaPlayerImpl_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiDisplaySettings.hpp"
#include "EmApoxiMutex.hpp"

class EmMediaPlayer;
class EmApoxiBinData;
class EmApoxiMediaInfo;

enum EmApoxiTrackSelection;


class MediaPlayerImpl 
{
    public:

        ~MediaPlayerImpl();

        virtual EmApoxiMmfResult SelectMediaTracks (
                                    EmApoxiTrackSelection track_selection,
                                    EmApoxiUINT audio_track_id,
                                    EmApoxiUINT video_track_id);

        virtual EmApoxiMmfResult SetDisplaySettings(
            const EmApoxiDisplaySettings& display_settings);

        virtual EmApoxiMmfResult Play();

        virtual EmApoxiMmfResult Pause();

        virtual EmApoxiMmfResult Stop();

        virtual EmApoxiMmfResult Rewind(EmApoxiINT rate);

        virtual EmApoxiMmfResult FastForward(EmApoxiINT rate);

        virtual EmApoxiMmfResult GetState(EmApoxiPlayerState& state) const;

        virtual EmApoxiMmfResult SetPosition(EmApoxiINT32 position);

        virtual EmApoxiMmfResult GetPosition(EmApoxiUINT32& position) const ;
    
        virtual EmApoxiMmfResult SetDisplayLocation(EmApoxiINT x, EmApoxiINT y);
        
        virtual EmApoxiMmfResult Zoom(EmApoxiBOOLEAN zoom_up);

        virtual EmApoxiMmfResult Unzoom();

        virtual EmApoxiMmfResult SetVolumeLevel(EmApoxiUINT volume_level);

        virtual EmApoxiMmfResult SetBassLevel(EmApoxiUINT bass_level);

        virtual EmApoxiMmfResult SetTrebleLevel(EmApoxiUINT treble_level);

        virtual EmApoxiMmfResult SetBalanceLevel(EmApoxiUINT balance_level);

        virtual EmApoxiMmfResult SetPlaybackContrast(EmApoxiUINT contrast_level);

        
        virtual EmApoxiMmfResult GetFirstVideoFrame
                            (EmApoxiUINT8 *buffer, EmApoxiUINT32& buffer_length);
        
        EmApoxiMmfResult SetPlaybackVideoQuality
                            (EmApoxiDisplaySettings::EmApoxiVideoQuality video_quality);
        virtual EmApoxiMmfResult SetRepeatCount(EmApoxiUINT16 repeat_count = 1) ;

        virtual EmApoxiMmfResult SetContinue(EmApoxiBOOLEAN continue_flag = EmApoxiFALSE) ;

        virtual EmApoxiMmfResult SetPriority(EmApoxiUINT32 priority = 0) ;

        virtual EmApoxiUINT16 GetRepeatCount() const ;

        virtual EmApoxiBOOLEAN GetContinue() const ;

        virtual EmApoxiUINT32 GetPriority() const ;

        virtual void* GetAudioReference(void) const;                            
#ifdef ENABLE_STREAMING

        virtual EmApoxiMmfResult GetBuffLevel(EmApoxiUINT32 &buff_level);

        virtual EmApoxiMmfResult SetBufferingTime(EmApoxiUINT32 buff_level);
#endif

    protected:

        
    private:
        
        EmMediaPlayer           *m_p_media_player;
        
        //Mutex to make a particular function wait, 
        //if one is already being processed. 
        EmApoxiMutex*           m_p_api_wait_mutex;

        MediaPlayerImpl(const EmApoxiBinData* media_source,
                    EmApoxiMediaInfo& media_info,
                    EmApoxiMimeType& media_mime_type,
                    EmApoxiMmfResult& mmf_result,
                    void *msg_dispatcher,
                    void* msg_data,
                    EmApoxiUINT32 audio_priority_value=0,
                    EmApoxiMmfModeType mmf_mode=EmApoxiMmfModeAudioVideo);

        MediaPlayerImpl(const char *location,
                    EmApoxiMediaInfo& media_info,
                    EmApoxiMimeType& media_mime_type,
                    EmApoxiMmfResult& mmf_result,
                    void *msg_dispatcher,
                    void* msg_data,
                    EmApoxiUINT32 audio_priority_value=0,
                    EmApoxiMmfModeType mmf_mode=EmApoxiMmfModeAudioVideo);

        friend class MediaPlayer;
};

#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif  //MediaPlayerImpl_hpp

