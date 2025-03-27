/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiAudioUtils_hpp)
#define EmApoxiAudioUtils_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

EmApoxiBOOLEAN EaadGetPlaybackSampleRate (
        EaadPlayBackSamplingRate sample_rate,
        EmApoxiUINT8& apoxisamplerate );
    
EmApoxiBOOLEAN EaadGetRecordSamplingRate (
        EaadRecordSamplingRate sample_rate,
        EmApoxiUINT8&   apoxisamplerate );

EmApoxiBOOLEAN EaadGetNumChannels ( 
        EaadNumChannels num_channels,
        EmApoxiUINT8&   monosteromode );

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiAudioUtils_hpp

