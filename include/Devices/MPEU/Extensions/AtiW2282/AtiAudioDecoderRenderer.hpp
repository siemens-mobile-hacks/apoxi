/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtiAudioDecoderRenderer_hpp)
#define AtiAudioDecoderRenderer_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/AudioDecoderRenderer.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

extern "C"{
#include <gci_common.h>
#include <gci_audio.h>
}

class AtiAudioDecoderRenderer : public AudioDecoderRenderer {

//------------------------------------------------------------------------------
    public:
//------------------------------------------------------------------------------
        virtual ~AtiAudioDecoderRenderer();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType Open(AudioChannel& audio_channel);

        virtual void Close();

        virtual ResultType RegisterCallbackFunctions(void* context,
                                                     CbReady cb_ready_for_data,
                                                     CbResult cb_all_buffers_processed);

        virtual ResultType DecodeRenderBuffer(AudioIOBuffer* buffer);

        virtual ResultType GetAudioChannelId(AudioChannel& audio_channel);


//------------------------------------------------------------------------------
    protected:
//------------------------------------------------------------------------------

        virtual ResultType SetCodec(CodecType codec);



//------------------------------------------------------------------------------
    private:
//------------------------------------------------------------------------------
        typedef UINT8 t_ati_codec_max_num_of_audio_dec_rend_inst;
        static const t_ati_codec_max_num_of_audio_dec_rend_inst c_ati_codec_max_num_of_audio_dec_rend_inst = 2;

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

        tGciAudioInputBuffer m_gci_input_buffer;

        static void CbReadyForData(void* context);

        static void CbAllBuffersProcessed(tGciResult result, void* context);

        CbReady m_client_cb_ready_for_data;


        CbResult m_client_cb_all_buffers_processed;

        void* m_client_context;

        CodecType m_codec;

        AtiAudioDecoderRenderer();

        void ResetAudioDecoderRenderer();

        static AtiAudioDecoderRenderer*
            m_exist_this_ptr_array[c_ati_codec_max_num_of_audio_dec_rend_inst];

        static BOOLEAN IsValidContext(void* context);

    friend class CodecManager;
    friend class AtiCodecsLib; // creates/destroys AtiAudioDecoderRenderer
};

#endif // AtiAudioDecoderRenderer_hpp

