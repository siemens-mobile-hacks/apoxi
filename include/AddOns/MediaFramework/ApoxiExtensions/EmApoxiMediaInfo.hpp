/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined (EmApoxiMediaInfo_hpp)
#define EmApoxiMediaInfo_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

class MediaInfo;

class EmApoxiMediaInfo
{

    public:
        enum EmApoxiMediaCodec {
            DefaultCodec,
            UnknownCodec,   
            Mpeg4Sp,    
            H263Bl,     
            GsmAmrNb,   
            Mpeg4Aac,   
            Qcelp,      
            Evrc,       
            Mp3,        
            Mpeg4AacPlusV1, 
            Mpeg4AacPlusV2, 
            H264Bp,         
            EndOfCodecType
        };

        class EmApoxiClipInfo {
            public:
                void Init();
                void DeInit();
                /* Fields for 3gpp clip  */
                EmApoxiUINT8*   m_p_title;
                EmApoxiUINT8*   m_p_author;
                EmApoxiUINT8*   m_p_copyright;
                EmApoxiUINT8*   m_p_rating;
                EmApoxiUINT8*   m_p_description;

                /* There are fields for Mp3 */
                EmApoxiUINT16*  m_p_song_name;
                EmApoxiUINT16* m_p_artist;
                EmApoxiUINT16* m_p_album; 
                EmApoxiUINT16* m_p_year;
                EmApoxiUINT16* m_p_comment;
                EmApoxiUINT16* m_p_genre;
                EmApoxiUINT16* m_p_track;
                EmApoxiUINT16* m_p_duration;
                EmApoxiUINT16* m_p_composer;
                EmApoxiUINT16* m_p_original_artist;
                EmApoxiUINT16* m_p_url;
                EmApoxiClipInfo operator = (EmApoxiClipInfo);

        };
        
        class EmApoxiMediaTrackInfo {
            public:
                EmApoxiMediaTrackInfo();
                
                EmApoxiMediaTrackInfo(EmApoxiMediaCodec codec_type, //needed???
                                EmApoxiUINT32 duration,
                                EmApoxiUINT32 track_id,
                                EmApoxiUINT32 bitrate = 0); 
                                
                EmApoxiMediaCodec GetMediaCodec() const {return m_codec_type;}
                
                EmApoxiUINT32 GetDuration() const {return m_duration;}

                EmApoxiUINT32 GetTrackId() const {return m_track_id;}

                EmApoxiUINT32 GetBitrate() const {return m_bitrate;}

            protected: // or private???
                EmApoxiMediaCodec m_codec_type;
                EmApoxiUINT32 m_duration;
                EmApoxiUINT32 m_track_id;
                EmApoxiUINT32 m_bitrate;
            
        };

        class EmApoxiAudioTrackInfo : public EmApoxiMediaTrackInfo {
            public:
                EmApoxiAudioTrackInfo();
                
                EmApoxiAudioTrackInfo(EmApoxiMediaCodec codec_type, //needed???
                                EmApoxiUINT32 duration,
                                EmApoxiUINT32 track_id,
                                EmApoxiUINT16 sample_freq, //needed???
                                EmApoxiUINT16 channel_cnt, //needed???
                                EmApoxiUINT32 bitrate = 0); 

                EmApoxiUINT16 GetSampleFreq() const {return m_sample_freq;}
                
                EmApoxiUINT16 GetNumberOfChannels() const {return m_channel_cnt;}
                
            private:
                EmApoxiUINT16 m_sample_freq;
                EmApoxiUINT16 m_channel_cnt;
        };
        class EmApoxiVideoTrackInfo : public EmApoxiMediaTrackInfo {
            public:
                EmApoxiVideoTrackInfo();
                
                EmApoxiVideoTrackInfo(EmApoxiMediaCodec codec_type, // needed???
                                EmApoxiUINT32 duration,
                                EmApoxiUINT32 track_id,
                                EmApoxiUINT16 m_width,
                                EmApoxiUINT16 m_height,
                                EmApoxiUINT32 bitrate = 0);
                
                EmApoxiUINT16 GetWidth() const {return m_width;}

                EmApoxiUINT16 GetHeight() const {return m_height;}

            private:
                EmApoxiUINT16 m_width;
                EmApoxiUINT16 m_height;
        };

        EmApoxiMediaInfo(MediaInfo *p_mediainfo = 0);
        ~EmApoxiMediaInfo();


        EmApoxiBOOLEAN AddAudioInfo(const EmApoxiAudioTrackInfo& info);
        
        EmApoxiBOOLEAN AddVideoInfo(const EmApoxiVideoTrackInfo& info);

        EmApoxiINT GetAudioInfoCount() const;

        EmApoxiINT GetVideoInfoCount() const;
        
        const EmApoxiAudioTrackInfo* GetAudioInfo(EmApoxiINT index) const;

        const EmApoxiVideoTrackInfo* GetVideoInfo(EmApoxiINT index) const;

        EmApoxiBOOLEAN SetClipInfo(EmApoxiUINT8 *title, 
                                    EmApoxiUINT8 *author, 
                                    EmApoxiUINT8 *copyright, 
                                    EmApoxiUINT8 *rating, 
                                    EmApoxiUINT8 *description);

        EmApoxiBOOLEAN EmApoxiMediaInfo::SetClipInfo(EmApoxiClipInfo & clip_info);

    //  const EmApoxiClipInfo& GetClipInfo() const { return m_clip_info; }
    

        EmApoxiBOOLEAN ReInit();

    

    private:
    
        /* Pimple Pointer */
        MediaInfo*                  m_p_mediainfo;
    
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiMediaInfo_hpp

