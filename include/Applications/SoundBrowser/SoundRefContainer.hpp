/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundRefContainer_hpp)
#define Apoxi_SoundRefContainer_hpp

#include <SoundBrowser/Common/MediaRefContainer.hpp>

class SoundRefContainer : public MediaRefContainer
{
    typedef MediaRefContainer Base;

    public:
        SoundRefContainer();
        SoundRefContainer(const Path &database_path);
        virtual ~SoundRefContainer();

        virtual BOOLEAN Add(MediaRefPtr &media_ref);

    protected:
        // @see MediaRefContainer::CreateMediaRef()
        virtual MediaRefPtr CreateMediaRef() const;

        // @see MediaRefContainer::GetSizeOfRecord()
        virtual UINT32 GetSizeOfRecord() const;

        virtual FileFilterPtr GetMediaFileFilter() const;

        virtual BOOLEAN SetupMediaObject(MetaData &metadata);
        virtual BOOLEAN SetupMediaObject(MediaRefPtr &media_ref);

};

#endif  // Apoxi_SoundRefContainer_hpp
