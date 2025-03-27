/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioDecoderRenderer_hpp)
#define Apoxi_AudioDecoderRenderer_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

class AudioDecoderRenderer : public CodecDevice {
    public:

        typedef void (*CbReady)(void *context);

        virtual ResultType Open(AudioChannel& audio_channel) = 0;

        virtual void Close() = 0;

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbReady cb_ready_for_data,
                                        CbResult cb_all_buffers_processed) = 0;

        virtual ResultType DecodeRenderBuffer(AudioIOBuffer* buffer) = 0;

        virtual ResultType GetAudioChannelId(AudioChannel& audio_channel) = 0;

    protected:

    private:

    friend class CodecManager;

};

#endif // Apoxi_AudioDecoderRenderer_hpp

