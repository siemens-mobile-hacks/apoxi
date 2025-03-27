/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtiAudioCapturerEncoder_hpp)
#define AtiAudioCapturerEncoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>
#include <AddOns/CodecManager/AudioCapturerEncoder.hpp>

extern "C"{
#include <gci_common.h>
#include <gci_audio.h>
}

class AtiAudioCapturerEncoder : public AudioCapturerEncoder {
    public:
        virtual ~AtiAudioCapturerEncoder();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType Open(AudioChannel& audio_channel);

        virtual void Close();

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbReady cb_data_available);

        virtual ResultType GetAudioChannelId(AudioChannel& audio_channel);
        
        virtual ResultType ConfigureAMR(    AmrIfFormat amr_if_format,
                                            EncQualityConfig quality_config,
                                            AmrDtxConfig dtx_config,
                                            UINT32 max_buffer_size);        

        virtual ResultType ConfigureAAC(    AacFormat aac_encoding_format,
                                            UINT16 sampling_rate,
                                            EncQualityConfig quality_config,
                                            MonoSteroConfig monostero_config,
                                            UINT32 max_buffer_size);        

        virtual ResultType GetBuffer(AudioIOBuffer** buffer);

    protected:
        virtual ResultType SetCodec(CodecType codec);

    private:
        typedef UINT8 t_ati_codec_max_num_of_audio_cap_enc_inst;
        static const t_ati_codec_max_num_of_audio_cap_enc_inst  c_ati_codec_max_num_of_audio_cap_enc_inst = 1;

        enum StateType {
            IdleState = 0,   
            ConfiguredState, 
            RunningState     
        };

        struct StateFlags {
            UINT m_state                        :3; 
            UINT m_callback_funcs_registered    :1; 
        };

        StateFlags m_flags;

        AudioChannel m_audio_channel;

        CbReady m_client_cb_data_available;

        void* m_client_context;

        CodecType m_codec;

        static AtiAudioCapturerEncoder*
            m_exist_this_ptr_array[c_ati_codec_max_num_of_audio_cap_enc_inst];

        AtiAudioCapturerEncoder();

        static void CbDataAvailable(void* context);

        static BOOLEAN IsValidContext(void* context);

        void ResetAtiAudioCapturerEncoder();

friend class AtiCodecsLib; // creates/destroys the AtiAudioCapturerEncoder
};

#endif // AtiAudioCapturerEncoder_hpp

