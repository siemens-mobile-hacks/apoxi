/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GenericFeatureData_hpp)
#define Apoxi_GenericFeatureData_hpp

#include <Auxiliary/GenericObject.hpp>
#include <Auxiliary/WString.hpp>
#include <Audio/AudioActiveReference.hpp>

class GenericFeatureData : public GenericObject
{
    public:
    GenericFeatureData();

        GenericFeatureData(const GenericFeatureData&);

    virtual ~GenericFeatureData();
   
    virtual GenericObject* Copy() const;
    virtual BOOLEAN IsEqual(GenericObject * object);
    virtual GenericTypeId GetTypeId();

        struct GenericTrackInfo {
            WString m_title;
            WString m_author;
            WString m_copyright;
            WString m_rating;
            WString m_description;
            WString m_song_name;
            WString m_artist;
            WString m_album;
            WString m_year;
            WString m_comment;
            WString m_genre;
            WString m_track;
            WString m_duration;
            WString m_composer;
            WString m_original_artist;
            WString m_url;
        };
        
        void SetDataPtr(void* data);
        void SetNumber(UINT32 data);
        void SetGenericTrackInfo(const GenericFeatureData::GenericTrackInfo& track_info);
        void SetActiveReference(const AudioActiveReference* active_ref);

        void* GetDataPtr() const;
        UINT32 GetNumber() const;
        const GenericFeatureData::GenericTrackInfo* GetGenericTrackInfo() const;
        const AudioActiveReference* GetActiveReference() const;

    private:
        void* m_void_ptr;
        UINT32 m_number;
        GenericTrackInfo* m_track_info;
        const AudioActiveReference* m_active_ref;

        void CopyGenericTrackInfo(const GenericFeatureData::GenericTrackInfo& track_info);
};

#endif

