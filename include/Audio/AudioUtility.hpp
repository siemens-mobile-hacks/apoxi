/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioUtility_hpp)
#define Apoxi_AudioNewAPI_AudioUtility_hpp

#include <Afs/Rfs/Path.hpp>
#include <Auxiliary/BinData.hpp>


class AudioUtility 
{
    public:
        enum AudioDataType
        {
            AudioDataTypeMidi = 0,
            AudioDataTypeMp3,
            AudioDataTypeSmaf,
            AudioDataTypeSmafPhrase,
            AudioDataTypeImelody,
            AudioDataTypeUnknown
        };

        virtual ~AudioUtility() = 0;

        static BOOLEAN ValidateAudioData(const UINT8 *buffer,
                                         const AudioDataType audioDataType);

        static BOOLEAN ValidateAudioData(const Path& path, 
                                         const AudioDataType audioDataType);

        static BOOLEAN FindAudioDataOffset(const Path& path,
                                           const AudioDataType audioDataType,
                                           UINT32 &offset);

        static BOOLEAN FindAudioDataOffset(const UINT8 *buffer,
                                           const UINT32 bufferSize,
                                           const AudioDataType audioDataType,
                                           UINT32 &offset);

        static UINT16 GetCallVolume(const UINT16 &volume);

        static BOOLEAN GetNumbersOfFrames(const Path& path,
                                          const AudioDataType audioDataType,
                                          const UINT32 offset,
                                          UINT32 &numberOfFrames);

        static BOOLEAN GetNumbersOfFrames(const UINT8 *buffer,
                                          const UINT32 bufferSize,
                                          const AudioDataType audioDataType,
                                          const UINT32 offset,
                                          UINT32 &numberOfFrames);

        
        static UINT32 CalculatePlayTime(BinData* bin_data, 
                                        MimeType mime_type);
                                        
        static UINT32 GetUint32FromUint8Array(const UINT8 *data);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
    protected:
        AudioUtility();

        static INT8 FindMp3Offset(const Path& path,
                                  UINT32 &offset);
        
        static INT8 FindMp3Offset(const UINT8 *buffer,
                                  const UINT32 bufferSize,
                                  UINT32 &offset);

        static INT8 FindMp3Frame(const UINT8 *buffer,
                                 const UINT32 bufferSize,
                                 UINT32 &frameHeader,
                                 UINT32 &offset);

        static INT8 GetFrameLength(const UINT32 &frameHeader, 
                                   UINT32 &frameLength);

        static INT8 GetMp3NumberOfFrames(const Path& path,
                                         const UINT32 offset,
                                         UINT32 &numberOfFrames);

        static INT8 GetMp3NumberOfFrames(const UINT8 *buffer,
                                         const UINT32 bufferSize,
                                         const UINT32 offset,
                                         UINT32 &numberOfFrames);

    private:
        static const UINT32 m_checkAudioTypePattern [5];

        static const UINT32 m_samplingRateFrequency [3][3];

        static const UINT16 m_bitRate [16][5];

        static const UINT32 m_readBufferSize;
#endif //DOXYGEN_SHOULD_SKIP_THIS
};

#endif  // Apoxi_AudioNewAPI_AudioUtility_hpp


