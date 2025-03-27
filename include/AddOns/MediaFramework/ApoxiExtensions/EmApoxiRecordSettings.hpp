/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined (EmApoxiRecordSettings_hpp)
#define EmApoxiRecordSettings_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiPlayerEnum.hpp"
#include "EmApoxiMediaInfo.hpp"

class RecordSettings;

class EmApoxiRecordSettings {
    
public:
    
    enum EmApoxiMediaQuality {
            EmApoxiQualityLow = 1,
            EmApoxiQualityNormal,
            EmApoxiQualityHigh
    };
    
    enum EmApoxiMediaSinkType {
            EmApoxiFilePathname,
            EmApoxiDataSink
    };

    
    EmApoxiRecordSettings();
    
    EmApoxiRecordSettings (RecordSettings* p_settings);
    
    ~EmApoxiRecordSettings();
    
    const EmApoxiMediaSinkType GetMediaSinkType() const;
    
    void SetMediaSinkType(EmApoxiMediaSinkType sink_type);
    
    const void* GetMediaSink() const;
    
    void SetMediaSink(void* media_sink);
    
    const EmApoxiMediaInfo::EmApoxiMediaCodec GetVideoCodec() const;
    
    const EmApoxiMediaInfo::EmApoxiMediaCodec GetAudioCodec() const;
    
    void SetVideoCodec(EmApoxiMediaInfo::EmApoxiMediaCodec video_codec);
    
    void SetAudioCodec(EmApoxiMediaInfo::EmApoxiMediaCodec audio_codec);
    
    const EmApoxiINT GetContrast() const;
    
    const EmApoxiINT GetBrightness() const;
    
    const EmApoxiBOOLEAN GetCameraNightMode() const;

    const EmApoxiUINT32 GetMaxFileSize() const;

    void SetMaxFileSize(EmApoxiUINT32 max_file_size);  

    const EmApoxiUINT32 GetMaxRecordingDuration() const;

    void SetMaxRecordingDuration(EmApoxiUINT32 max_recording_duration);
    
    const EmApoxiMediaQuality GetVideoQuality() const;
    
    const EmApoxiMediaQuality GetAudioQuality() const;
    
    const EmApoxiINT GetFrameRate () const;
    
    const EmApoxiUINT16 GetWidth () const;

    const EmApoxiUINT16 GetHeight () const;

    const EmApoxiUINT8 GetCameraDeviceId () const;
    
private:
    RecordSettings *m_p_record_setting;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiRecordSettings_hpp

