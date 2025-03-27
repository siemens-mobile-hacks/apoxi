/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsResourceMaps_hpp)
#define Ems_EmsResourceMaps_hpp

#include <Gui/Color.hpp>
#include <Gui/Font.hpp>
#include <Gui/EditorDocument.hpp>
#include <Apc/InformationElement.hpp>

#define COLOR_COUNT 16

class EmsResourceMaps {
    public:
        struct AnimNode {
            const BitmapRes* const * m_anim;
            UINT8 m_frame_count;
        };

        static EditorDocument::LineAlignment MapTextAlignment(InformationElement::TextAlignment val);           
        static InformationElement::TextAlignment MapTextAlignment(EditorDocument::LineAlignment val);

        static EditorDocument::LineAlignment MapLineAlignment(TextFormat::TextAlign val);
        static TextFormat::TextAlign MapLineAlignment(EditorDocument::LineAlignment val);
        
        static InformationElement::FontSize MapFont(const Font& font);  
        static const Font& MapFont(InformationElement::FontSize size);
        
        static const Color& MapTextColor(InformationElement::TextColour val);
        
        static InformationElement::TextColour MapTextColor(const Color& val);

        // initializes ems color map. Must be invoked once retreiving ems colors.
        static void         InitEmsColors();
        static const Color* GetEmsColors();
        static UINT8        GetEmsColorCount();
        static const WCHAR** GetEmsColorNames();
        
        static AnimNode MapAnimation(InformationElement::PredefinedAnimationType type);
        
        static Audio::AudioToneId MapSound(InformationElement::PredefinedSoundType type);
        
    private:
        // do not instanciate!
        EmsResourceMaps();  //lint !e1704
        virtual ~EmsResourceMaps();
        static Color        m_colors[COLOR_COUNT];  
        static const WCHAR*     m_color_names[];
};

#endif // Ems_EmsResourceMaps_hpp
