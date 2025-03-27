/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_StreamAudioReference_hpp)
#define Apoxi_AudioNewAPI_StreamAudioReference_hpp


#include <Audio/AudioReference.hpp>
#include <Afs/Rfs/RootFileSystem.hpp>
#include <Afs/Rfs/Path.hpp>
#include <Audio/AudioPlayer.hpp>


class StreamAudioReference : public AudioReference
{
    public:
        friend class AudioPriorityManager;
        friend class StreamAudioPlayer;
        friend class VoiceMemoAudioPlayer;
        friend class PCMAudioPlayer;
        friend class MP3AudioPlayer;
        enum Mode {
            StandbyMode,
            TchMode
        };

        enum Media {
            FfsMedia,
            MmcMedia,
            RamMedia,
            RfsMedia,
            MmfMedia,
#ifndef DOXYGEN_SHOULD_SKIP_THIS

            VrMedia
#endif
        };

        enum DspFormat {
            PcmDspFormat,
            AdpcmDspFormat,
            WaveDspFormat,
            FrDspFormat,
            AmrDspFormat,
            MP3DspFormat,
            A2dpFormat          
        };


        typedef UINT32              BufferByteType;
        // Now we have one central definition for Buffer and ConstBuffer in the AudioPlayer.
        // Buffer should used for playback and ConstBuffer should used for recording.
        typedef AudioPlayer::Buffer BufferType;
        typedef AudioPlayer::ConstBuffer ConstBufferType;

        virtual ~StreamAudioReference();        

        typedef UINT8 SampleRateType;

        typedef UINT8 MonoStereoType;

        

        static SharedPtr<StreamAudioReference> CreateRam(BufferType buffer, BufferByteType buffer_size, Mode mode, DspFormat format);

        static SharedPtr<StreamAudioReference> CreateRam(ConstBufferType buffer, BufferByteType buffer_size, Mode mode, DspFormat format);


        static SharedPtr<StreamAudioReference> CreateFFS(const String& filename, Mode mode, DspFormat format);

        static SharedPtr<StreamAudioReference> CreateFile(const Path& filename, Mode mode, DspFormat format);

        //typedef void (*GetAudioBufferFunction)( /* audiobuffer */ UINT8 ** , /*size */UINT16 *, /* application data */void* pUserData);
        typedef AudioPlayer::GetAudioBufferFunction GetAudioBufferFunction;

        static SharedPtr<StreamAudioReference> CreateStream(Mode mode, DspFormat format, GetAudioBufferFunction func, void* user_data = 0);

        static SharedPtr<StreamAudioReference> MmfCreateStream(Mode mode, DspFormat format, GetAudioBufferFunction func, void* user_data = 0, BOOLEAN has_audio = TRUE);

        BOOLEAN HasAudio() const;

        static SharedPtr<StreamAudioReference> CreateVoiceRecognition();

        virtual enumClassType GetClassType() const;

        static UINT32 CalculateBufferSize(UINT32 seconds, DspFormat format, SampleRateType rec_rate);

        ConstBufferType GetBuffer(BufferByteType& size) const;
        BufferType GetBuffer(BufferByteType& size);
        
        const Path& GetPath() const { return m_path; }

        virtual UINT16 GetDelay(void) const;

        Mode GetMode() const;
        Media GetMediaType() const;
        DspFormat GetDspFormat() const;

        BufferByteType GetRecordedSize();
    
        MonoStereoType GetMonoStereoMode() const;

        SampleRateType GetSampleRate() const;

        void SetRecordingRate(SampleRateType val);
        void SetSampleRate(SampleRateType val);

        void SetMonoStereoMode(MonoStereoType val);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        UINT32 GetDataOffset() const;
#endif

    protected:

        StreamAudioReference(const Path& filename, Mode mode, DspFormat format);
        StreamAudioReference(BufferType buffer_handle, BufferByteType buffer_size, Mode mode,  DspFormat format);
        StreamAudioReference(const String& filename, Mode mode, DspFormat format);
        StreamAudioReference(Mode mode, DspFormat format);

        StreamAudioReference();

        static SharedPtr<StreamAudioReference> Create(Mode mode, Media media_type, DspFormat format);

        // Called by AudioPriorityManager, which is a friend class.
        // stores actual size
        void SetRecordedSize(BufferByteType rec_size);

        //Initialize the offset to the raw audio data. It has to be called after the path is set up!!!
        void InitDataOffset();

        static SharedPtr<StreamAudioReference> Create(const String& fName, BufferType buffer, BufferByteType buffer_size, Mode mode, Media media_type, DspFormat format);

//      StreamAudioReference(const Path& filename, Mode mode, DspFormat format);

    protected:
        //Called by StreamAudioPlayer, which is a friend class.
        BOOLEAN CreateFile();
        BOOLEAN OpenFile();
        void CloseFile();
        
        BufferType m_buffer;
        BufferByteType m_buffer_size;

        Mode m_mode;

        Media m_media_type;

        DspFormat m_format;

        SampleRateType m_sample_rate;

        MonoStereoType m_mono_stereo_mode;

        UINT32 m_data_offset;

        Path m_path;

        FilePtr m_file_handle;
        
        BOOLEAN m_has_audio;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        static int StreamingGetBuffer(UINT8** audiobuffer,UINT16* size, void* user_data);
        //The MMF callback function
        GetAudioBufferFunction ptr_MMFCallaback;
        void* m_pUserData;
#endif
};

#endif // Apoxi_AudioNewAPI_StreamAudioReference_hpp


