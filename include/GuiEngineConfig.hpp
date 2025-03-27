/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GuiEngineConfig_hpp)
#define Apoxi_GuiEngineConfig_hpp

class AbstractItemRenderer;
class ItemRendererProperties;
class AbstractTextRenderer;

#include <Kernel/Types.hpp>
#include <Gui/ScrollBehavior.hpp>
#include <Gui/IconState.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Gui/Size.hpp>

class GuiEngineConfig {
    public:
        static ScrollBehavior GetScrollBehavior();

        static UINT32 GetSharedImageBufferMax();

        static UINT32 GetImageBufferMax();

        static AbstractItemRenderer* ObtainItemRenderer(const ItemRendererProperties* properties = 0);

        static void ReleaseItemRenderer(AbstractItemRenderer* renderer);

        static const ItemRendererProperties* GetDefaultItemRendererProperties();
        
        static Size GetIconSize(IconState::Size size);
        
        static AbstractTextRenderer& GetTextRenderer(LanguageManager::LanguageType language_id);
        
        static const ColorValue* GetIconColorTable();
};

#endif  // Apoxi_GuiEngineConfig_hpp

