/*
*******************************************************************************
                       Copyright eMuzed Inc., 2001-2004.
All rights Reserved, Licensed Software Confidential and Proprietary Information
    of eMuzed Incorporation Made available under Non-Disclosure Agreement OR
                            License as applicable.
*******************************************************************************
*/

/*
*******************************************************************************
Product     : MMFr and MM Apps on APOXI
Module      : MMFr
File        : DisplaySettings.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added private members
------------------------------------------------------------------------ */

#if !defined(Apoxi_DisplaySettings_hpp)
#define Apoxi_DisplaySettings_hpp

#include <Gui/Rect.hpp>

class DisplaySettings {
    public:
        
        enum VideoQuality {
            LowQuality,
            MediumQuality,
            HighQuality
        };

    
        enum ScaleType {
            DownscaleToBounds,
            ScaleToBounds,
        };

        DisplaySettings();

        DisplaySettings(const Rect& bounds,
                       ScaleType scale_type,
                       UINT8 display_index = 0,
                       BOOLEAN keep_aspect_ratio = TRUE,
                       BOOLEAN is_first_frame_rendered = FALSE);


        const Rect& GetBounds() const { return m_rect;}

        ScaleType GetScaleType() const { return m_scale_type;}

        BOOLEAN KeepAspectRatio() const { return m_keep_aspect_ratio;}

    private:
        Rect m_rect;
        ScaleType m_scale_type;
        BOOLEAN m_keep_aspect_ratio;
        
    
};
#endif  //Apoxi_DisplaySettings_hpp

