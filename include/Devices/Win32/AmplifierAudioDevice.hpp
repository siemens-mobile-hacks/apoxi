/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(AmplifierAudioDevice_hpp)
#define AmplifierAudioDevice_hpp

#include <Kernel/Types.hpp>
#include "GenericAudioDevice.hpp"

class AmplifierAudioDevice : public GenericAudioDevice {
    public:
        AmplifierAudioDevice();
        virtual ~AmplifierAudioDevice();    

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        
};

#endif // AmplifierAudioDevice_hpp


