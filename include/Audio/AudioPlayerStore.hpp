/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioPlayerStore_hpp)
#define Apoxi_AudioPlayerStore_hpp

#include <Auxiliary/MimeTypeTable.hpp>
#include <Auxiliary/Vector.hpp>
#include <Auxiliary/SimpleMap.hpp>

#include <Audio/AudioPlayer.hpp>

class AudioPlayerStore
{
    protected:
        AudioPlayerStore();

    public:
        ~AudioPlayerStore();

        static AudioPlayerStore* GetInstance();
        
        BOOLEAN AddPlayer(AudioPlayer *player);

        BOOLEAN PrioritizePlayer(AudioPlayer *player, MimeType type, AudioReference::SoundDataSource source);

        BOOLEAN ExcludePlayer(AudioPlayer *player, MimeType type, AudioReference::SoundDataSource source);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        AudioPlayer* FindPlayer(MimeType type) const;

        Vector<AudioPlayer*> GetPrioritizedPlayers(MimeType type, AudioReference::SoundDataSource source, BOOLEAN for_playback, BOOLEAN for_recording) const;
        
#endif //DOXYGEN_SHOULD_SKIP_THIS       
        
protected:
        struct DataFormatDataSource {
            MimeType mime_type;
            AudioReference::SoundDataSource source;
            
            BOOLEAN operator== (const DataFormatDataSource& other) {
                return mime_type == other.mime_type && source == other.source;
            }
        };

        SimpleMap<DataFormatDataSource, Vector<AudioPlayer*> > m_mime_to_source_to_players;
        static AudioPlayerStore m_instance;
};

#endif  // Apoxi_AudioPlayerStore_hpp

