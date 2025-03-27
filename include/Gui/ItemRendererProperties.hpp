/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ItemRendererProperties_hpp)
#define Apoxi_ItemRendererProperties_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/WString.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Gui/Color.hpp>
#include <Gui/TextFormat.hpp>

class Dispatcher;
class ResourceParser;

class ItemRendererProperties {
    public:
        enum {
            ID = 0
        };

        enum DisplayType {
            TextAndIconDisplayType      = 0,
            TextDisplayType             = 1,
            IconDisplayType             = 2,
            TextAboveIconDisplayType    = 3,
            TextBelowIconDisplayType    = 4,
            TextOverlapsIconDisplayType = 5,
            CustomDisplayType           = 99
        };
            

        enum AnimType {
            NoAnimation                 = 0,
            CycleAnimation              = 1,
            BounceAnimation             = 2,
            BlinkingAnimation           = 3,
            IconAnimation               = 4,
            OnlyOnceAnimation           = 5,    
            CustomAnimation             = 99,

            // Obsolete - use CycleAnimation instead (whether the 
            // scrolling is done horizontally or vertically is decided through
            // the multiline-mode)
            CycleVerticalAnimation      = 1,            
            // Obsolete - use CycleAnimation instead (whether the 
            // scrolling is done horizontally or vertically is decided through
            // the multiline-mode)
            CycleHorizontalAnimation    = 1,
            // Obsolete - use CycleAnimation instead.
            HardVerticalAnimation       = 1,
            // Obsolete - use CycleAnimation instead.
            HardHorizontalAnimation     = 1,
            // Obsolete - use CycleAnimation instead.
            SoftVerticalAnimation       = 1,
            // Obsolete - use CycleAnimation instead.
            SoftHorizontalAnimation     = 1,
        };

        ItemRendererProperties();

        ItemRendererProperties(INT display_type,
                               INT anim_type,
                               UINT16 scroll_delay,
                               XYDIM scroll_gap,
                               const TextFormat& text_format,
                               BOOLEAN full_screen_per_item = FALSE,
                               BOOLEAN transparent = FALSE,
                               BOOLEAN multi_line = FALSE,
                               BOOLEAN centered_vertical = TRUE,
                               BOOLEAN indicate_item_cont = FALSE,
                               const Color& backgr_color = Color(Color::ClientBackground),
                               XYDIM height = -1,
                               XYDIM gap = 2,
                               INT column_count = 1,
                               XYDIM selection_height = -1,
                               UINT16 start_delay = 0,
                               const ImageObtainer& backgr_image = ImageObtainer(),
                               const Color* text_color = 0,
                               INT renderer_hint = 0);

        virtual ~ItemRendererProperties();
        
        BOOLEAN SetProperty(ResourceParser& parser,
                            const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetDisplayType(INT display_type) { m_display_type = display_type; }

        INT GetDisplayType() const { return m_display_type; }

        void SetAnimType(INT anim_type) { m_anim_type = anim_type; }

        INT GetAnimType() const { return m_anim_type; }
    
        void SetStartDelay(UINT16 start_delay) { m_start_delay = start_delay; }
        
        UINT16 GetStartDelay() const { return m_start_delay; }

        void SetScrollDelay(UINT16 scroll_delay);
        
        UINT16 GetScrollDelay() const { return m_scroll_delay; }

        void SetScrollGap(XYDIM scroll_gap);
        
        XYDIM GetScrollGap() const { return m_scroll_gap; }

        void SetTextFormat(const TextFormat& text_format) { m_text_format = text_format; }

        const TextFormat& GetTextFormat() const { return m_text_format; }

        void SetTransparent(BOOLEAN transparent) { m_bits.transparent = transparent; }

        BOOLEAN IsTransparent() const { return (BOOLEAN)m_bits.transparent; }

        void SetMultiLine(BOOLEAN multi_line) { m_bits.multi_line = multi_line; }

        BOOLEAN IsMultiLine() const { return (BOOLEAN)m_bits.multi_line; }

        void SetIndicateItemContainer(BOOLEAN flag) { m_bits.indicate_item_cont = flag; }

        BOOLEAN IndicateItemContainer() const { return (BOOLEAN)m_bits.indicate_item_cont; }

        void SetFullScreenPerItem(BOOLEAN full_screen_per_item) { m_bits.full_screen_per_item = full_screen_per_item; }

        BOOLEAN FullScreenPerItem() const { return (BOOLEAN)m_bits.full_screen_per_item; }

        void SetVerticalCentered(BOOLEAN vertical_centered) { m_bits.vertical_centered = vertical_centered; }
        
        BOOLEAN IsVerticalCentered() const { return (BOOLEAN)m_bits.vertical_centered; }

        void SetTextColor(const Color* text_color);
    
        const Color& GetTextColor() const;

        void SetBackgroundColor(const Color& backgr_color);
    
        const Color& GetBackgroundColor() const { return m_backgr_color; }

        void SetHeight(XYDIM height) { m_height = height; }

        XYDIM GetHeight() const { return m_height; }

        void SetGap(XYDIM gap) { m_gap = gap; }

        XYDIM GetGap() const { return m_gap; }

        void SetColumnCount(INT column_count) { m_column_count = column_count; }
        
        INT GetColumnCount() const { return m_column_count; }
        
        void SetSelectionHeight(XYDIM selection_height) { m_selection_height = selection_height; }
        
        XYDIM GetSelectionHeight() const { return m_selection_height; }

        void SetBackgroundImage(const ImageObtainer& backgr_image) { m_backgr_image = backgr_image; }

        const ImageObtainer& GetBackgroundImage() const { return m_backgr_image; }

        void SetRendererHint(INT renderer_hint) { m_renderer_hint = renderer_hint; }

        INT GetRendererHint() const { return m_renderer_hint; }
        
    private:
        struct {
            UINT transparent          : 1;
            UINT multi_line           : 1;
            UINT indicate_item_cont   : 1;
            UINT full_screen_per_item : 1;
            UINT vertical_centered    : 1;
            UINT use_default_text_col : 1;
        } m_bits;

        INT m_display_type;
        INT m_anim_type;
        UINT16 m_start_delay;
        UINT16 m_scroll_delay;
        XYDIM m_scroll_gap;
        TextFormat m_text_format;
        mutable Color m_text_color;
        Color m_backgr_color;
        XYDIM m_height;
        XYDIM m_gap;
        INT m_column_count;
        XYDIM m_selection_height;
        ImageObtainer m_backgr_image;
        INT m_renderer_hint;
};
 
#endif  // Apoxi_ItemRendererProperties_hpp

