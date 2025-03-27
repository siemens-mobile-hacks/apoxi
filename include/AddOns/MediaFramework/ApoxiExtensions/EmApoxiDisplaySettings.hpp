/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined (EmApoxiDisplaySettings_hpp)
#define EmApoxiDisplaySettings_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

class DisplaySettings;

class EmApoxiDisplaySettings {

    public:
        enum EmApoxiVideoQuality {
            EmApoxiLowQuality,
            EmApoxiMediumQuality,
            EmApoxiHighQuality
        };

        enum EmApoxiScaleType {
            EmApoxiDownscaleToBounds,   
            EmApoxiScaleToBounds,
        };

        EmApoxiDisplaySettings(EmApoxiINT32 left, EmApoxiINT32 top, EmApoxiINT32 width, EmApoxiINT32 height);

        ~EmApoxiDisplaySettings();

        EmApoxiINT32  GetLeft() const { return m_left; }

        EmApoxiINT32  GetTop() const { return m_top; }

        EmApoxiINT32  GetWidth() const { return m_width; }

        EmApoxiINT32  GetHeight() const { return m_height; }

    private:
        
        EmApoxiINT32  m_left;

        EmApoxiINT32  m_top;

        EmApoxiINT32  m_width;

        EmApoxiINT32  m_height;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiDisplaySettings_hpp

