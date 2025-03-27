/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioCapturerEncoder_hpp)
#define Apoxi_AudioCapturerEncoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

class AudioCapturerEncoder : public CodecDevice {
    public:

        typedef void (*CbReady)(void *context);

        virtual ResultType Open(AudioChannel& audio_channel) = 0;

        virtual void Close() = 0;

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbReady cb_data_available) = 0;

        virtual ResultType GetAudioChannelId(AudioChannel& audio_channel) = 0;
        
        virtual ResultType ConfigureAMR(    AmrIfFormat amr_if_format,
                                            EncQualityConfig quality_config,
                                            AmrDtxConfig dtx_config,
                                            UINT32 max_buffer_size) = 0;        

        virtual ResultType ConfigureAAC(    AacFormat aac_encoding_format,
                                            UINT16 sampling_rate,
                                            EncQualityConfig quality_config,
                                            MonoSteroConfig monostero_config,
                                            UINT32 max_buffer_size) = 0;        

        virtual ResultType GetBuffer(AudioIOBuffer** buffer) = 0;       

    protected:

    private:

    friend class CodecManager;

};

#endif // Apoxi_AudioCapturerEncoder_hpp

