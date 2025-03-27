/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioSuspendedDetails_hpp)
#define Apoxi_AudioNewAPI_AudioSuspendedDetails_hpp

#include <Audio/AudioActiveReference.hpp>

class AudioReference;
//class AudioActiveReference;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class AudioSuspendedDetails : public Linkable<AudioSuspendedDetails>
{
public:
    explicit AudioSuspendedDetails(AudioActiveReference& suspended);
    AudioSuspendedDetails(AudioActiveReference& suspended, AudioActiveReference& suspended_by);
    virtual ~AudioSuspendedDetails();
    
    SharedPtr<AudioActiveReference> GetSuspendedSound();
    SharedPtr<const AudioActiveReference> GetSuspendedSound() const;
    
    void SetSuspendedSound(AudioActiveReference& active_reference);
    
    SharedPtr<const AudioActiveReference> GetSuspendedBy() const;
    
    void SetSuspendedBy(const AudioActiveReference& active_reference);
    
protected:
    SharedPtr<AudioActiveReference> m_active_reference; //The suspended sound
    SharedPtr<const AudioActiveReference> m_suspended_by; //This sound that played instead.
};

#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_AudioSuspendedDetails_hpp


