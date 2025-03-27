/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundRef_hpp)
#define Apoxi_SoundRef_hpp

#include <Afs/Ffs/FfsTypes.hpp>
#include <Afs/Rfs/FileBinData.hpp>
#include <SoundBrowser/Common/MediaRef.hpp>
#include <SoundBrowser/SoundMetaData.hpp>

class Sound;

class SoundRef : public MediaRef
{
    typedef MediaRef Base;

    public:
        SoundRef();
        virtual ~SoundRef();

        virtual MetaData& GetMetaData();
        virtual const MetaData& GetMetaData() const;

        virtual void SetMetaData(const MetaData &meta_data);

#if defined(APOXI_INCLUDE_DRM)
        virtual WString GetAssetInfo();
#endif

        BinData* GetSoundBuffer(MimeType &mime_type);

#if defined(APOXI_COMPAT_1_11_0)
        Sound* GetSound(BOOLEAN buffer_to_ram = TRUE);


        void SetSound(Sound *sound){m_sound = sound;}

        BOOLEAN IsSoundInitialized() const {return m_sound != 0; }

        void ReleaseSound();

        Sound* CreateSoundObject(BOOLEAN buffer_to_ram);
#endif


#if defined(APOXI_INCLUDE_DRM)
    #if defined(APOXI_COMPAT_1_11_0)
        Sound* CreateSoundObject(FfsDrmAttrib attrib);
    #endif
#endif

    private:
        SoundMetaData m_meta_data;
        FileBinData *m_fbd;

#if defined(APOXI_COMPAT_1_11_0)

        Sound *m_sound;
        Sound * ConstructSoundObject(const MimeType& mType, BinData* bin_data);
#endif

        
        BufferedData* GetFileData();
};

#endif  // Apoxi_SoundRef_hpp
