/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiAudioDecoderhpp)
#define EmApoxiAudioDecoderhpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiCodecManager.hpp"
class AudioDecoder;

class EmApoxiAudioDecoder {
    public:
        enum ParameterType {
            QualityLevel,
            Format,
            EndOfParameterType
        };

        enum DecodingFunctionType {
            DecodeBufferFct,
            DecodeFrameFct
        };

        enum AacFormatType {
            AacRawFormat,
            AacAdifOrAdtsFormat,
            AacAdtsWithOneRawDataBlockFormat
        };

        typedef void (*CbFrameDecoded)( EmApoxiCodecManager::ResultType result,
                                        void* context,
                                        const EmApoxiUINT8 HUGE* out_buf,
                                        EmApoxiUINT32 out_buf_len,
                                        EmApoxiUINT32 in_buf_used);
        

        EmApoxiCodecManager::ResultType AllocateOutputBuffers(
                                                    EmApoxiUINT8 HUGE** &out_buf_array,
                                                    EmApoxiUINT8& out_buf_count,
                                                    EmApoxiUINT32& out_buf_len,
                                                    DecodingFunctionType& dec_fct);     

        EmApoxiCodecManager::ResultType RegisterCallbackFunctions(void* context,
                                        CbFrameDecoded cb_frame_decoded);

            EmApoxiCodecManager::ResultType DecodeBuffer(
                                                    const EmApoxiUINT8 HUGE* in_buf,
                                                    EmApoxiUINT32 in_buf_len,
                                                    const EmApoxiUINT8 HUGE* out_buf,
                                                    EmApoxiUINT32 out_buf_len);                                     

        EmApoxiCodecManager::ResultType DecodeFrame(const EmApoxiUINT8 HUGE* in_buf,
                                                    EmApoxiUINT32 in_buf_len,
                                                    const EmApoxiUINT8 HUGE* out_buf,
                                                    EmApoxiUINT32 out_buf_len);
        
         EmApoxiCodecManager::ResultType Start( const EmApoxiUINT8* config_stream,
                                                EmApoxiUINT32& config_len,
                                                const EmApoxiCodecManager::AudioDecoderParameters& params,
                                                EmApoxiCodecManager::AudioStreamInfo& stream_info) ;
        
         void Stop() ;

         EmApoxiCodecManager::ResultType Reset();
        
        EmApoxiAudioDecoder();

        ~EmApoxiAudioDecoder();

    private:
        EmApoxiAudioDecoder(const EmApoxiAudioDecoder& decoder) {}

        EmApoxiAudioDecoder& operator=(const EmApoxiAudioDecoder& decoder) { }

        AudioDecoder*   m_AudioDecoder;

        CbFrameDecoded m_DecodeCbFxn;       

        void *m_Context;

        friend void sEmApoxiAudioDecoderFrameDecodedCb(int result,void* context,
                                        void* out_buf,
                                        unsigned int out_buf_len,
                                        unsigned int in_buf_used);


};

#endif
#endif // Apoxi_CodecManager_hpp

