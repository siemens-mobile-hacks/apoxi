/* ----------------------------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
   ----------------------------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted withOut prior written authorisation.
   ---------------------------------------------------------------------------------------------- */

#if !defined(Apoxi_HostAudioDriver_hpp)
#define Apoxi_HostAudioDriver_hpp

#include <Kernel/Os/Os.hpp>
#include <Devices/Win32/aud_drv.h>

// Number of AMR encoded bytes based on Frame Type along with Frame Header
const UINT16 AMR_SM_WORDS[] = {13,14,16,18,20,21,27,32,5,0,0,0,0,0,0,1};

// Maximum size of the Shared Memory between APOXI & Audio Gati Client
// Support 312 Stereo or 625 Mono Pcm Samples of 16 bits width
#define MAXSHMEMSIZE 200004

// Number of Frames used to signal Notification event on client side
#define PCM_FILEPLAY_FRAMENUM   6
#define AMR_FILEPLAY_FRAMENUM   6
#define PCM_FILEREC_FRAMENUM    3   
#define AMR_FILEREC_FRAMENUM    3

// Structures for passing driver API parameters to Audio Gati Client
struct PcmParam {
    UINT8 handle;
    aud_pcm_mode_enum mode;
    aud_pcm_sample_rate_enum sample_rate;
    UINT8 bit_rate;
    aud_media_enum media;
    aud_pcm_format_enum format;
    UINT16* file_handle;
    UINT32 buffer_size;
};

struct VmParam {
    UINT8 handle;
    aud_vm_mode_enum vm_mode;
    aud_media_enum media;
    aud_dsp_format_enum format;
    UINT8 rate;
    UINT16* file_handle;
    UINT16 buffer_size;
};

struct Mp3Header {
    UINT8   mpg_ver;
    UINT8   mpg_layer;
    UINT8   mpg_pad_bit;
    UINT16  mpg_br;
    INT     mpg_freq;
};

struct Mp3Param {
        UINT8 handle;
        aud_media_enum media;
        UINT16* file_handle;
        UINT16 buffer_size;
        UINT32 id_offset;
        UINT32 start_frame;
        Mp3Header m_mpghead;
};

// Commands passed between Audio Gati Server/Client
typedef enum 
{
        InvalidEntry,
        PlayPcm,
        RecordPcm,
        StopPlayPcm,
        StopRecPcm,

        PlayAmr,
        RecordAmr,
        StopPlayAmr,
        StopRecAmr,

        PlayMp3,
        StopMp3,

        PcmPlayCallBack,
        PcmRecCallBack,

        AmrPlayCallBack,
        AmrRecCallBack,
        Mp3PlayCallBack,

        PcmRetCode,
        VmRetCode,
        Mp3RetCode
} AudCmd ;

enum StopRetCode {
    Playback_Finish,
    Playback_Stopped,
    Recording_Finish
};

// Methods to simulate driver functionality
BOOLEAN InitShmemEvent();

UINT16  PlayPcmCallback();
UINT16  RecPcmCallback();
UINT16  PlayAmrCallback();
UINT16  RecAmrCallback();

BOOLEAN GetMp3Head(Mp3Header* mp3head, INT* framesize, CHAR hdr_frame[] );
UINT16  PlayMp3Callback();

INT PlayPcmStreamFile();
INT RecPcmStreamFile();
INT PlayAmrStreamFile();
INT RecAmrStreamFile();
INT PlayMp3StreamFile();


#endif  // Apoxi_HostAudioDriver_hpp

