/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_CombinedDeviceAudioReference_hpp)
#define Apoxi_AudioNewAPI_CombinedDeviceAudioReference_hpp

#include <Audio/StreamAudioReference.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class CombinedDeviceAudioReference : public StreamAudioReference
{
    public:
        
        CombinedDeviceAudioReference(MimeType mime_type, SoundDataSource sound_data_source);

        CombinedDeviceAudioReference(BufferType buffer_handle, BufferByteType buffer_size, MimeType mime_type, SoundDataSource sound_data_source);
        
        virtual ~CombinedDeviceAudioReference();

        virtual enumClassType GetClassType() const;

        typedef INT32 HandleType;

        typedef UINT32 TimeStampType;
        
        void SetDriverHandle(HandleType handle);

        void SetTime(TimeStampType time);

        HandleType GetDriverHandle() const;

        TimeStampType GetTime() const;

    protected:

        HandleType m_handle;

        TimeStampType m_time;
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_CombinedDeviceAudioReference_hpp


