/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioEncoder_hpp)
#define Apoxi_AudioEncoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

class AudioEncoder : public CodecDevice {
    public:

        enum ParameterType {
            BitPool,
            FilterBankBlockLength,
            EndOfParameterType
        };

        enum EncodingFunctionType {
            EncodeBufferFct,
            EncodeFrameFct
        };

        enum ChannelModeType {
            MonoChannelMode,
            DualChannelMode,
            StereoChannelMode,
            JointStereoChannelMode
        };

        enum BitAllocationMethodType {
            LoudnessAllocation,
            SnrAllocation
        };

        typedef void (*CbFrameEncoded)( ResultType result,
                                        void* context,
                                        const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_used,
                                        const UINT8 HUGE* out_buf,
                                        UINT32 out_buf_len);

        virtual ResultType Open() = 0;

        virtual void Close() = 0;

        virtual ResultType SetConfig(const AudioEncoderParameters& params) = 0;

        virtual ResultType GetCapabilities(AudioCodecCapabilities& caps) = 0;

        virtual ResultType AllocateOutputBuffers(
                                            UINT8 HUGE** &out_buf_array,
                                            UINT8& out_buf_count,
                                            UINT32& out_buf_len,
                                            EncodingFunctionType& enc_fct) = 0;

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbFrameEncoded cb_frame_encoded) = 0;

        virtual ResultType EncodeBuffer(    const UINT8 HUGE* in_buf,
                                            UINT32 in_buf_len,
                                            const UINT8 HUGE* out_buf,
                                            UINT32 out_buf_len) = 0;

        virtual ResultType EncodeFrame( const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        const UINT8 HUGE* out_buf,
                                        UINT32 out_buf_len) = 0;

        virtual ResultType SetParameters(   const ParameterType* types_array,
                                            const UINT32* values_array,
                                            UINT8 array_count) = 0;

        virtual ResultType GetParameters(   const ParameterType* types_array,
                                            UINT32* values_array,
                                            UINT8 array_count) = 0;

    protected:

    private:

    friend class CodecManager;

};

#endif // Apoxi_AudioEncoder_hpp

