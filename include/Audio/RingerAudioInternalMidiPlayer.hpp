/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_RingerAudioInternalMIDIPlayer_hpp)
#define Apoxi_AudioNewAPI_RingerAudioInternalMIDIPlayer_hpp

#include <Audio/RingerAudioPlayer.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS

class RingerAudioInternalMIDIPlayer : public RingerAudioPlayer
{
    public:
        virtual ~RingerAudioInternalMIDIPlayer();
    
        virtual AudioSourceType GetSource() const; //override

        static AudioDeviceBase* GetInstance();
        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;
        virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const;
    protected:
        virtual UINT16 GetDeviceID() const; //overwrite
        virtual BOOLEAN Play_Allocate(AudioActiveReference &playing_ref);       
    private:
    RingerAudioInternalMIDIPlayer();

    RingerAudioInternalMIDIPlayer(const RingerAudioInternalMIDIPlayer& obj);


        static RingerAudioInternalMIDIPlayer m_singleton_instance;
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_RingerAudioInternalMIDIPlayer_hpp


