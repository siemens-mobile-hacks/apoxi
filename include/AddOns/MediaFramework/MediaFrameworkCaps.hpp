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
File        : MediaFrameworkCaps.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added private members
------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaFrameworkCaps_hpp)
#define Apoxi_MediaFrameworkCaps_hpp

#include <MediaFramework/MediaInfo.hpp>

class MediaFrameworkCaps {
    public:

        MediaFrameworkCaps();

        const MediaFrameworkCaps* GetCapabilities() const;

        BOOLEAN IsEncoderCodecSupported(MediaInfo::MediaCodec codec) const;

        INT GetSupportedEncoderCodecsCount() const;

        MediaInfo::MediaCodec GetEncoderCodec(INT index) const;

        BOOLEAN IsDecoderCodecSupported(MediaInfo::MediaCodec codec) const;

        INT GetSupportedDecoderCodecsCount() const;

        MediaInfo::MediaCodec GetDecoderCodec(INT index) const;

    private:
};


#endif  //Apoxi_MediaFrameworkCaps_hpp

