/*
*******************************************************************************
                       Copyright eMuzed Inc., 2001-2004.
All rights Reserved, Licensed Software Confidential and Proprietary Information
    of eMuzed Incorporation Made available under Non-Disclosure Agreement OR
                            License as applicable.
*******************************************************************************
*/

/*
*******************************************************************************
Product     : MMFr and MM Apps on APOXI
Module      : MMFr
File        : RecordSettings.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author              Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
13th Oct 2004           Naveen Narayanan        Integrated the proposal
------------------------------------------------------------------------ */


#if !defined(Apoxi_RecordSettings_hpp)
#define Apoxi_RecordSettings_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/DataSink.hpp>
#include <Afs/Rfs/Pathname.hpp>
#include <Gui/Rect.hpp>

#include <AddOns/MediaFramework/MediaInfo.hpp>

class RecordSettings {
    public:
        enum MediaSinkType {
            FilePathname,
            DataSink
        };

        enum MediaQuality {
            QualityLow = 1,
            QualityNormal,
            QualityHigh
        };

        RecordSettings();

        ~RecordSettings();

        RecordSettings( INT frame_rate,
                        XYDIM width,
                        XYDIM height,
                        UINT8 camera_dev_id,
                        MediaQuality video_quality,
                        MediaQuality audio_quality,
                        MediaInfo::MediaCodec video_codec,
                        MediaInfo::MediaCodec audio_codec,
                        UINT32 max_file_size,
                        const char* media_sink);

        RecordSettings( INT frame_rate,
                        XYDIM width,
                        XYDIM height,
                        UINT8 camera_dev_id,
                        MediaQuality video_quality,
                        MediaQuality audio_quality,
                        MediaInfo::MediaCodec video_codec,
                        MediaInfo::MediaCodec audio_codec,
                        UINT32 max_file_size,
                        class DataSink* media_sink);

        RecordSettings( void* media_sink,
                        MediaSinkType media_sink_type,
                        MediaInfo::MediaCodec video_codec,
                        MediaQuality video_quality,
                        INT contrast,
                        INT brightness,
                        BOOLEAN camera_night_mode,
                        UINT32 max_file_size,
                        UINT32 max_recording_duration);

        const MediaSinkType GetMediaSinkType() const { return m_sink_type; }

        void SetMediaSinkType(MediaSinkType sink_type) { m_sink_type = sink_type; }

        const void* GetMediaSink() const { return m_media_sink; }

        void SetMediaSink(void* media_sink) { m_media_sink = media_sink; }

        const MediaInfo::MediaCodec GetVideoCodec() const { return m_video_codec; }

        void SetVideoCodec(MediaInfo::MediaCodec video_codec) { m_video_codec = video_codec; }

        void SetAudioCodec(MediaInfo::MediaCodec audio_codec) { m_audio_codec = audio_codec; }

        const INT   GetContrast() const { return m_contrast; }

        const INT GetBrightness() const { return m_brightness; }

        const BOOLEAN GetCameraNightMode() const { return m_camera_night_mode; }

        const UINT32 GetMaxFileSize() const { return m_max_file_size; }

        void SetMaxFileSize(UINT32 max_file_size) { m_max_file_size = max_file_size; }

        const UINT32 GetMaxRecordingDuration() const { return m_max_recording_duration; }

        void SetMaxRecordingDuration(UINT32 max_recording_duration) { m_max_recording_duration = max_recording_duration; }

        const MediaQuality GetVideoQuality() const { return m_video_quality; }

    private:
        INT m_frame_rate;
        XYDIM m_width;
        XYDIM m_height;
        MediaQuality m_video_quality;
        MediaQuality m_audio_quality;
        MediaInfo::MediaCodec m_video_codec;
        MediaInfo::MediaCodec m_audio_codec;
        UINT32 m_max_file_size;
        MediaSinkType m_sink_type;
        void* m_media_sink;
        
        INT     m_contrast;

        INT     m_brightness;

        BOOLEAN m_camera_night_mode;

        UINT32  m_max_recording_duration;
        
        UINT8   m_camera_device_id;
        
        
        friend class MediaRecorder;
        friend class EmApoxiRecordSettings;
};
#endif  //Apoxi_RecordSettings_hpp

