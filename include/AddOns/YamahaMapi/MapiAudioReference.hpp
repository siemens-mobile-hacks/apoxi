/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MapiAudioReference_hpp)
#define Apoxi_MapiAudioReference_hpp

#include <Audio/AudioReference.hpp>
#include <AddOns/YamahaMapi/AudioMapiManager.hpp>

class AudioPlayer;


class MapiAudioReference: public AudioReference {
    public:
        virtual ~MapiAudioReference();
        static SharedPtr<MapiAudioReference> Create();
        virtual enumClassType GetClassType() const;
    protected:
        MapiAudioReference();
    
    private:

        friend class MapiAudioPlayer;
    
};

#endif // Apoxi_MapiAudioReference_hpp

