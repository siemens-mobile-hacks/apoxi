/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaRefContainer_hpp)
#define Apoxi_MediaRefContainer_hpp

#include <Auxiliary/ElementList.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Afs/Rfs/Path.hpp>
#include "MediaRef.hpp"
#include "MediaVisitor.hpp"


class File;
class MediaFilter;
class ImageBrowserApp;
class SoundBrowserApp;


typedef NiSharedPtr<File> FilePtr;
typedef NiSharedPtr<MediaRef> MediaRefPtr;

struct MediaRefLinkable : public Linkable<MediaRefLinkable>
{
    MediaRefPtr m_elem;

    explicit MediaRefLinkable(MediaRefPtr &elem) : 
        m_elem(elem) {}

    const MediaRefPtr& operator*() const { return m_elem; }
    MediaRefPtr& operator*() { return m_elem; }
    
    BOOLEAN operator==(const MediaRefLinkable &rhs) const {
        return m_elem.Get() == rhs.m_elem.Get();
    }

};


class MediaRefContainer
{
    protected:
        MediaRefContainer();
        MediaRefContainer(const Path &path);

    public:
        virtual ~MediaRefContainer();

        void Init(const Path &database_path);

        virtual BOOLEAN Add(MediaRefPtr &media_ref);

        virtual BOOLEAN Delete(MediaRefPtr &media_ref, 
            BOOLEAN delete_file = FALSE);

        BOOLEAN DeleteAt(INT index, BOOLEAN delete_file = FALSE);

        virtual BOOLEAN Rename(MediaRefPtr &media_ref, const WString &new_name);

        void Clear();

        MediaRefPtr& GetElementAt(INT index);

        const MediaRefPtr& GetElementAt(INT index) const;

        INT GetSize() const { return m_elems.GetSize(); }

        INT GetIndex(const MediaRefPtr &media_ref) const;

        BOOLEAN MediaRefExists(const Path &path) const;

        BOOLEAN ApplyFilter(const MediaFilter &media_filter);

        void ApplyVisitorFilter(MediaVisitor* media_visitor, const MediaFilter &media_filter);

        void Refresh(MediaFilter *filter = 0);
        
        static BOOLEAN SaveMedia(MediaRefPtr &media_ref, const UINT8 HUGE *content, UINT32 length);

        virtual UINT32 GetSizeOfRecord() const = 0;

        void SearchForFiles(MediaFilter *app_filter = 0, const WString& storage_device_Id = L"ffs");
        void SetDbPath(const Path &path){m_path = path;}
        
    protected:
    
        
        // Returns a new media reference object of the derived class.
        virtual MediaRefPtr CreateMediaRef() const = 0;

        virtual FileFilterPtr GetMediaFileFilter() const = 0;

        virtual BOOLEAN SetupMediaObject(MediaRefPtr &media_ref) = 0;

        virtual BOOLEAN IsInDatabase(const Path& path) const;

        Path m_path;

    private:

        friend class ImageBrowserApp;
        friend class SoundBrowserApp;
        
        BOOLEAN Read(MediaFilter *filter  = 0 );

        MediaRefPtr ReadMediaRef(INT index, const FilePtr &file) const;

        BOOLEAN Write() const;

        BOOLEAN WriteMediaRef(INT index, const FilePtr &file) const;

        ElementList<MediaRefLinkable> m_elems;
        INT32 m_index_counter; 
};

#endif  // Apoxi_MediaRefContainer_hpp
