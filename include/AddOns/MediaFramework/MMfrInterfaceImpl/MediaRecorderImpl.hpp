/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(MediaRecorderImpl_hpp)
#define MediaRecorderImpl_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiRecordSettings.hpp"
#include "EmApoxiDisplaySettings.hpp"
#include "EmApoxiPlayerEnum.hpp"
#include "EmApoxiRecorderEnum.hpp"
#include "EmApoxiMutex.hpp"

class EmMediaRecorder;
class MediaRecorder;

class  MediaRecorderImpl {
    public:
        
        virtual ~MediaRecorderImpl();

        EmApoxiMmfResult SetDisplaySettings(
                            const EmApoxiDisplaySettings& display_settings);

        EmApoxiMmfResult SetDisplayAndRecordSettings(
                            const EmApoxiDisplaySettings& display_settings,
                            const EmApoxiRecordSettings& record_settings);

        EmApoxiMmfResult StartPreview();

        EmApoxiMmfResult StopPreview();
        
        EmApoxiMmfResult SetRecordSettings(
            const EmApoxiRecordSettings& record_settings);

        EmApoxiMmfResult StartRecord();

        EmApoxiMmfResult PauseRecord();

        EmApoxiMmfResult ResumeRecord();

        EmApoxiMmfResult StopRecord();

        EmApoxiMmfResult GetState(EmApoxiRecorderState& state) const;

        EmApoxiMmfResult GetPosition(EmApoxiUINT32& position) const;

        virtual EmApoxiMmfResult Zoom(EmApoxiBOOLEAN zoom_up);

        virtual EmApoxiMmfResult Unzoom();

        EmApoxiMmfResult SetCameraNightMode(EmApoxiBOOLEAN night_mode_on);

        EmApoxiMmfResult SetCameraMirroring(EmApoxiBOOLEAN mirroring_on);

        EmApoxiMmfResult SetMute(EmApoxiBOOLEAN mute_on);

        virtual EmApoxiMmfResult SetPriority(EmApoxiUINT32 priority = 0) ;

        virtual EmApoxiUINT32 GetPriority() const ;
        
    private:
        EmMediaRecorder*        m_p_media_recorder;
        
        //Mutex to make a particular function wait, 
        //if one is already being processed. 
        EmApoxiMutex*           m_p_api_wait_mutex;
        
        static EmApoxiBOOLEAN   m_recorder_exists;
        
        MediaRecorderImpl(EmApoxiMmfResult& mmf_result, 
                        void *msg_dispatcher,
                        void* msg_data,
                        EmApoxiUINT32 audio_priority_value=0,
                        EmApoxiMmfModeType mmf_mode=EmApoxiMmfModeAudioVideo);

        friend class MediaRecorder;

        
};

#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif // MediaRecorderImpl_hpp

