/*
*******************************************************************************
                       Copyright eMuzed Inc., 2001-2004.
All rights Reserved, Licensed Software Confidential and Proprietary Information
    of eMuzed Incorporation Made available under Non-Disclosure Agreement OR
                            License as applicable.
*******************************************************************************
*/

/*
*******************************************************************************
Product     : MMFr and MM Apps on APOXI
Module      : MMFr
File        : MediaInfo.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added private members
------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaInfo_hpp)
#define Apoxi_MediaInfo_hpp

#include "PreComp.hpp" 

class MediaInfo {
    public:
        enum MediaCodec {
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
        
        class ClipInfo {
            public:
                void Init();
                void DeInit();

                /* Fields for 3gpp clip  */
                UINT8*  m_p_title;
                UINT8*  m_p_author;
                UINT8*  m_p_copyright;
                UINT8*  m_p_rating;
                UINT8*  m_p_description;

                /* There are fields for Mp3 */
                UINT16* m_p_song_name;
                UINT16* m_p_artist;
                UINT16* m_p_album; 
                UINT16* m_p_year;
                UINT16* m_p_comment;
                UINT16* m_p_genre;
                UINT16* m_p_track;
                UINT16* m_p_duration;
                UINT16* m_p_composer;
                UINT16* m_p_original_artist;
                UINT16* m_p_url;
            
        };


        class MediaTrackInfo {
            public:
                MediaTrackInfo();
                
                MediaTrackInfo(MediaCodec codec_type, //needed???
                                UINT32 duration,
                                UINT32 track_id,
                                UINT32 bitrate = 0); //needed???
                                
                MediaCodec GetMediaCodec() const {return m_codec_type;}
                
                UINT32 GetDuration() const {return m_duration;}

                UINT32 GetTrackId() const {return m_track_id;}

                UINT32 GetBitrate() const {return m_bitrate;}

            protected: // or private???
                MediaCodec m_codec_type;
                UINT32 m_duration;
                UINT32 m_track_id;
                UINT32 m_bitrate;
            
        };

        class AudioTrackInfo : public MediaTrackInfo {
            public:
                AudioTrackInfo();
                
                AudioTrackInfo(MediaCodec codec_type, //needed???
                                UINT32 duration,
                                UINT32 track_id,
                                UINT16 sample_freq, //needed???
                                UINT16 channel_cnt, //needed???
                                UINT32 bitrate = 0); 

                UINT16 GetSampleFreq() const {return m_sample_freq;}
                
                UINT16 GetNumberOfChannels() const {return m_channel_cnt;}
                
            private:
                UINT16 m_sample_freq;
                UINT16 m_channel_cnt;
        };
        
        class VideoTrackInfo : public MediaTrackInfo {
            public:
                VideoTrackInfo();
                
                VideoTrackInfo(MediaCodec codec_type, // needed???
                                UINT32 duration,
                                UINT32 track_id,
                                XYDIM m_width,
                                XYDIM m_height,
                                UINT32 bitrate = 0); 
                
                XYDIM GetWidth() const {return m_width;}

                XYDIM GetHeight() const {return m_height;}

            private:
                XYDIM m_width;
                XYDIM m_height;
        };
        
        /* Default constructor*/
        MediaInfo();
    
        /* Default Destructor */
        ~MediaInfo();

        BOOLEAN AddAudioInfo(const AudioTrackInfo& info);
        
        BOOLEAN AddVideoInfo(const VideoTrackInfo& info);

        INT GetAudioInfoCount() const{ return mAudTrackCnt;}

        INT GetVideoInfoCount() const{ return mVidTrackCnt;}
        
        const AudioTrackInfo* GetAudioInfo(INT index) const;

        const VideoTrackInfo* GetVideoInfo(INT index) const;

        BOOLEAN SetClipInfo(UINT8 *title, UINT8 *author, UINT8 *copyright, UINT8 *rating, UINT8 *description);

        BOOLEAN MediaInfo::SetClipInfo(ClipInfo & clip_info);

        const ClipInfo& GetClipInfo() const { return m_clip_info; }
    

        BOOLEAN ReInit();
    
    private:
        
        INT32 mAudTrackCnt;
        INT32 mVidTrackCnt;

        VideoTrackInfo*     m_p_vid_track_info;
        AudioTrackInfo*     m_p_aud_track_info;


        ClipInfo            m_clip_info;

        friend class        EmApoxiMediaInfo;
        
};


#endif  //Apoxi_MediaInfo_hpp

