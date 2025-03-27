/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiVideoDecoderhpp)
#define EmApoxiVideoDecoderhpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
class VideoDecoder;

class EmApoxiVideoDecoder {
    public:

        enum ParameterType {
            QualityLevel,
            EndOfParameterType
        };

        enum FlagsType {
            LastFrameFlag = 1<<0, 
            LastPacketInFrameFlag = 1<<1, 
            GreatestValueOfFlagsType = LastPacketInFrameFlag
        };

        typedef void (*CbFrameDecoded)( EmApoxiCodecManager::ResultType result,
                                        void* context,
                                        const EmApoxiUINT8 HUGE* out_buf,
                                        EmApoxiUINT32 time_stamp);

        typedef void (*CbInBufferFree)( void* context,
                                        EmApoxiUINT8 HUGE* in_buf);

        EmApoxiCodecManager::ResultType AllocateOutputBuffers(EmApoxiUINT8& out_buf_count,
                                                                EmApoxiUINT32& out_buf_len);

        EmApoxiCodecManager::ResultType GetNumberOfInitialDecodeOperations(EmApoxiUINT8& operations) ;

        EmApoxiCodecManager::ResultType RegisterCallbackFunctions(  void* context,
                                                                    CbFrameDecoded cb_frame_decoded,
                                                                    CbInBufferFree cb_in_buf_free);

        EmApoxiCodecManager::ResultType DecodeFrame(    const EmApoxiUINT8 HUGE* in_buf,
                                                        EmApoxiUINT32 in_buf_len,
                                                        EmApoxiUINT16 flags) ;

         EmApoxiCodecManager::ResultType DecodePacket(  const EmApoxiUINT8 HUGE* in_buf,
                                                        EmApoxiUINT32 in_buf_len,
                                                        EmApoxiUINT16 flags) ;

         EmApoxiCodecManager::ResultType ReleaseOutputBuffer(const EmApoxiUINT8 HUGE* out_buf) ;

         EmApoxiCodecManager::ResultType NotifyOutputBufferReleased(const EmApoxiUINT8 HUGE* out_buf) ;

         EmApoxiCodecManager::ResultType Flush() ;

         EmApoxiCodecManager::ResultType SetParameters( const ParameterType* types_array,
                                                        const EmApoxiUINT32* values_array,
                                                        EmApoxiUINT8 array_count) ;

         EmApoxiCodecManager::ResultType GetParameters( const ParameterType* types_array,
                                                        EmApoxiUINT32* values_array,
                                                        EmApoxiUINT8 array_count) ;
         EmApoxiCodecManager::ResultType Start( const EmApoxiUINT8* config_stream,
                                                EmApoxiUINT32& config_len,
                                                const EmApoxiCodecManager::VideoDecoderParameters& params,
                                                EmApoxiCodecManager::VideoStreamInfo& stream_info) ;
        
         void Stop() ;
        
        EmApoxiVideoDecoder();

        ~EmApoxiVideoDecoder();

    private:
        EmApoxiVideoDecoder(const EmApoxiVideoDecoder& decoder) {}

        EmApoxiVideoDecoder& operator=(const EmApoxiVideoDecoder& decoder) { }

        VideoDecoder*   m_VideoDecoder;

        CbFrameDecoded m_DecodeCbFxn;

        CbInBufferFree m_InBufFreeCb;

        void *m_Context;

        friend void sEmApoxiVideoDecoderFrameDecodedCb(int result,
                                                    void* context,
                                            void *out_buf,
                                            unsigned int time_stamp);
        friend void sEmApoxiInBufFreeCb(void* context,void* in_buf);


};

#endif
#endif // Apoxi_CodecManager_hpp

