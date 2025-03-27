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
File        : VideoCaptureParameters.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author              Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
13th Oct 2004           Naveen Narayanan        Integrated the proposal
------------------------------------------------------------------------ */
#if !defined(VideoCaptureParameters_hpp)
#define VideoCaptureParameters_hpp

class VideoCaptureParameters{

    public:

        VideoCaptureParameters( Size max_resolution=0,
                                UINT16 max_frame_rate_numerator=0,
                                UINT16 max_frame_rate_denominator=0,
                                UINT16 max_bit_rate=0,
                                UINT32 max_duration=0,
                                UINT32 max_media_length=0,
                                BOOLEAN audio_flag=TRUE,
                                MimeType pref_mime_type=c_mime_unknown);

        virtual ~VideoCaptureParameters();

        virtual Size GetMaxResolution() const;

        virtual void GetMaxFramerate(   UINT16& max_frame_rate_numerator,
                                        UINT16& max_frame_rate_denominator) const;

        virtual UINT16 GetMaxBitrate() const;

        virtual UINT32 GetMaxDuration() const;

        virtual UINT32 GetMaxMediaLength() const;

        virtual BOOLEAN IsAudioEnabled() const;

        virtual MimeType GetPrefMimeType() const;

    private :

        Size m_max_resolution;

        UINT16 m_max_frame_rate_numerator;
        UINT16 m_max_frame_rate_denominator;

        UINT16 m_max_bitrate;

        UINT32 m_max_duration;

        UINT32 m_max_media_length;

        BOOLEAN m_audio_flag;

        MimeType m_pref_mime_type;
};
#endif

