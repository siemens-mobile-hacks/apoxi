/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaFilter_hpp)
#define Apoxi_MediaFilter_hpp

#include <Auxiliary/MimeTypeTable.hpp>

class MediaRef;

class MediaFilter
{
    public:
        MediaFilter();
        virtual ~MediaFilter();

        virtual BOOLEAN IsAllowed(const MediaRef &media_ref) const;
};

class ImageFilter : public MediaFilter
{
    public:
        ImageFilter();
        virtual ~ImageFilter();

        virtual BOOLEAN IsAllowed(const MediaRef &media_ref) const;
};

class SoundFilter : public MediaFilter
{
    public:
        SoundFilter();
        virtual ~SoundFilter();

        virtual BOOLEAN IsAllowed(const MediaRef &snd_ref) const;
};

class MimeTypeFilter : public MediaFilter
{
    typedef MediaFilter Base;

    public:
        MimeTypeFilter(MimeType mime_type);
        virtual ~MimeTypeFilter();

        virtual BOOLEAN IsAllowed(const MediaRef &media_ref) const;

        virtual void SetMimeType(MimeType mime_type);

    private:
        MimeType m_mime_type;
};

#endif  // Apoxi_MediaFilter_hpp
