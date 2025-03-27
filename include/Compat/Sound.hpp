/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_MultiMedia_Sound_hpp)
#define AddOns_MultiMedia_Sound_hpp

#include <Auxiliary/ObjectObtainer.hpp>
#include <AddOns/MultiMedia/AudioContext.hpp>
#include <Auxiliary/BinData.hpp>

class Sound;

class SoundObtainer : public ObjectObtainer {
    typedef ObjectObtainer Base;

    public:
        SoundObtainer();

        SoundObtainer(Sound* sound, BOOLEAN disposable);

        // needed because of a bug in the tasking-compiler
        SoundObtainer(const SoundObtainer& sound_obt) { *this = sound_obt; }

        virtual ~SoundObtainer();

        Sound* GetSound() { return (Sound*)GetObject(); }

        const Sound* GetSound() const { return (Sound*)GetObject(); }
};

class Sound : public ObtainableObject {
    typedef ObtainableObject Base;

    public:
        Sound();        

        virtual ~Sound();

        virtual INT GetId() const = 0;      

        virtual const WCHAR* GetName() const = 0;

        virtual BOOLEAN Play(AudioContext* context) = 0;

        virtual const BinData* GetBinData() const;
};

#endif // AddOns_MultiMedia_Sound_hpp


