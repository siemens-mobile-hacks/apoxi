/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_CTResourcePack_hpp)
#define Apoxi_CTResourcePack_hpp

#include <Gui/Bitmap.hpp>
#include <Gui/ColorTable.hpp>

class CTResourceParser;

/*  ------------------------------------------------------------------------
    CTResourcePack
    ------------------------------------------------------------------------*/
class CTResourcePack {
    
    public:
        CTResourcePack();
        ~CTResourcePack();

        enum LightOriginType {
            LowerLeft,
            LowerRight,
            UpperLeft,
            UpperRight
        };

        enum CornerModeType {
            Angular,
            Rounded                             // NSY (Not Supported Yet)
        };

        enum BorderModeType {
            Flat,
            Raised,         // raised control
            RaisedBorder,   // raised border    // NSY
            Sunken,
            SunkenBorder                        // NSY
        };

        enum ProgressBarDrawModeType {
            DrawPrimitives,
            DrawBitmap
        };

        enum ResourceType {
            Global = 0,

            ControlFrameControl,
            
            WindowFrameControl,
            WindowTitleBarControl,

            InactiveWindowFrameControl,
            InactiveWindowTitleBarControl,
            
            SoftkeyBarControl,
            SoftkeyBarButtonsControl,
            
            ProgressBarControl,
            ProgressBarBarControl,
            
            PushButtonControl,
            
            PositionIndicatorControl,
            PositionIndicatorBarControl,
            PositionIndicatorArrowBoxControl
        };

        enum PropertyType {
            UnknownPropertyType = 255,
            SubComponentPropertyType,

            // global properties
            SystemColorTable = 0,           // ColorTable
            ThemeName,

            ClientBackgroundColor,          // Color
            ClientForegroundColor,          // Color
            ActiveFrameBackgroundColor,     // Color
            ActiveFrameForegroundColor,     // Color
            InactiveFrameBackgroundColor,   // Color
            InactiveFrameForegroundColor,   // Color
            SelectionBackgroundColor,       // Color
            SelectionForegroundColor,       // Color
            ShadedColor,                    // Color
            ButtonBackgroundColor,          // Color
            ButtonForegroundColor,          // Color
            ContextMenuBackgroundColor,     // Color

            LightOrigin,                    // LightOriginType
            DropShadowWidth,                // XYDIM
            DropShadowDistance,             // XYDIM
            DropShadowColor,                // Color
            DropShadowMaxAlpha,             // UINT8
            DropShadowMinAlpha,             // UINT8

            BackgroundDim,                  // BOOLEAN  // NSY
            
            SelectedCheckBoxBitmapUri,      // WString
            DeselectedCheckBoxBitmapUri,    // WString
            SelectedRadioButtonBitmapUri,   // WString
            DeselectedRadioButtonBitmapUri, // WString

            SelectedCheckBoxBitmap,         // BitmapRes
            DeselectedCheckBoxBitmap,       // BitmapRes
            SelectedRadioButtonBitmap,      // BitmapRes
            DeselectedRadioButtonBitmap,    // BitmapRes

            // common component properties
            BorderMode,                     // BorderModeType
            BorderWidth,                    // XYDIM
            OuterBorderWidth,               // XYDIM
            BorderCornerMode,               // CornerModeType
            RoundedCornerRadius,            // XYDIM
            DropShadowEnabled,              // BOOLEAN
            ComponentForegroundColor,       // Color
            ComponentBackgroundColor,       // Color
            OuterBorderColor,               // Color
            InnerBorderColor,               // Color
            LightColor,                     // Color
            DarkerLightColor,               // Color
            LightShadow,                    // Color
            DarkShadow,                     // Color

            // component specific properties
            // WindowTitlebar
            TitleBarHeight,                 // XYDIM
            TitleBarBitmapUri,              // WString
            TitleBarBitmap,                 // Bitmap
            InactiveTitleBarHeight,         // XYDIM
            InactiveTitleBarBitmapUri,      // WString
            InactiveTitleBarBitmap,         // Bitmap

            // Panel
            // Softkeys
            SoftkeyBarHeight,               // XYDIM
            SoftkeyBarButtonSpacing,        // XYDIM
            SoftkeyBarBackgroundBitmapUri,  // WString
            SoftkeyBarBackgroundBitmap,     // Bitmap
            SoftkeyBarButton1BitmapUri,     // WString
            SoftkeyBarButton1Bitmap,        // Bitmap
            SoftkeyBarButton2BitmapUri,     // WString
            SoftkeyBarButton2Bitmap,        // Bitmap
            // Navigation guidance
            SoftkeyBarNavGuideEnabled,      // BOOLEAN
            SoftkeyBarNavGuideActiveColor,  // Color
            SoftkeyBarNavGuideInactiveColor,// Color

            ProgressBarDrawingMode,         // ProgressBarDrawModeType
            ProgressBarBitmap,              // BOOLEAN
            ProgressBarDrawPercentage,      // BOOLEAN
            ProgressBarHeight,              // XYDIM

            PushButtonHeight,               // XYDIM

            PositionIndicatorWidth,         // XYDIM
            PositionIndicatorDrawArrows,    // BOOLEAN
            PositionIndicatorArrowHeight,   // XYDIM

            TextFormatProp,                 // TextFormat
            TextAlignProp,                  // TextFormat::TextAlign
            TextAttrProp,                   // TextFormat::TextAttr
            FontAlignProp                   // TextFormat::FontAlign
        };

        enum ParseType {
            UnknownParseType,
            BooleanParseType,
            XyDimParseType,
            IntegerParseType,
            UInt8ParseType,
            UInt16ParseType,
            WStringParseType,
            ColorParseType,
            LightOriginParseType,
            CornerModeParseType,
            BorderModeParseType,
            ProgressBarDrawModeParseType,
            TextAttrParseType,
            TextAlignParseType,
            FontAlignParseType
        };
        
        void InitProperties();

        void* GetProperty(ResourceType resource, PropertyType property);

        BOOLEAN SetProperty(ResourceType resource, PropertyType property, void* data);
        
        WString GetResourceUri() const { return m_resource_uri; }

        void SetResourceUri(const WString& resource_uri) { m_resource_uri = resource_uri; }

        BOOLEAN ReadProperties(CTResourceParser& parser);

        BOOLEAN CustomizedDataAvailable() { return m_customized_data_available; }

        WString GetName() const { return m_name; }

    private:

        WString m_resource_uri;

        static CTResourcePack::ResourceType MapIdToResourceType (INT id);

        static CTResourcePack::PropertyType MapIdToPropertyType (INT id);

        static CTResourcePack::ParseType MapPropertyToParseType (PropertyType prop_id);

        BOOLEAN ReadNextProperty(CTResourceParser& parser, CTResourcePack::ResourceType resource_id, CTResourcePack::PropertyType property_id);

        BOOLEAN IsCommonProperty(PropertyType property);

        Bitmap* GenerateBitmap(const WString& uri);
        
        void Cleanup();

        BOOLEAN m_customized_data_available;
        WString m_name;
        
        Palette* m_cust_system_colors;
        ColorTable m_cust_system_color_table;

        CTResourcePack::LightOriginType m_light_origin;

        CTResourcePack::CornerModeType m_border_corners;

        XYDIM m_dropshadow_width;
        XYDIM m_dropshadow_distance;
        Color m_dropshadow_color;
        UINT8 m_dropshadow_max_alpha;
        UINT8 m_dropshadow_min_alpha;

        BOOLEAN m_background_dim_enabled;

        // checkbox / radiobutton bitmap properties
        WString m_selected_checkbox_bmp_uri;
        BitmapRes* m_selected_checkbox_bmp;

        WString m_deselected_checkbox_bmp_uri;
        BitmapRes* m_deselected_checkbox_bmp;

        WString m_selected_radiobutton_bmp_uri;
        BitmapRes* m_selected_radiobutton_bmp;
        
        WString m_deselected_radiobutton_bmp_uri;
        BitmapRes* m_deselected_radiobutton_bmp;

        struct CommonProperties {
            BorderModeType m_border_mode;
            XYDIM m_border_width;
            XYDIM m_outer_width;
            CornerModeType m_corner_mode;
            XYDIM m_round_corner_radius;
            BOOLEAN m_dropshadow_enabled;
            Color m_fg_color;
            Color m_bg_color;
            Color m_outer_border_color;
            Color m_inner_border_color;
            Color m_light;
            Color m_darker_light;
            Color m_light_shadow;
            Color m_dark_shadow;
        };

        CommonProperties m_windowframe_props;
        CommonProperties m_window_titlebar_props;
        XYDIM m_window_titlebar_height;
        // window titlebar bitmap properties
        WString m_window_titlebar_bmp_uri;
        Bitmap* m_window_titlebar_bmp;
        TextFormat m_window_titlebar_textformat;

        CommonProperties m_inactive_windowframe_props;
        CommonProperties m_inactive_window_titlebar_props;
        XYDIM m_inactive_window_titlebar_height;
        // inactive window titlebar bitmap properties
        WString m_inactive_window_titlebar_bmp_uri;
        Bitmap* m_inactive_window_titlebar_bmp;
        TextFormat m_inactive_window_titlebar_textformat;

        // Softkeybar
        CommonProperties m_softkeybar_props;
        XYDIM m_softkeybar_height;
        XYDIM m_softkeybar_button_spacing;
        WString m_softkeybar_background_bmp_uri;
        Bitmap* m_softkeybar_background_bmp;
        // nav guide specific properties
        BOOLEAN m_softkeybar_navguide_enabled;
        Color m_softkeybar_navguide_active_color;
        Color m_softkeybar_navguide_inactive_color;

        CommonProperties m_softkeybar_buttons_props;
        TextFormat m_softkeybar_buttons_textformat;
        // softkeybar bitmap properties
        WString m_softkeybar_button_1_bmp_uri;
        Bitmap* m_softkeybar_button_1_bmp;
        WString m_softkeybar_button_2_bmp_uri;
        Bitmap* m_softkeybar_button_2_bmp;

        CommonProperties m_progressbar_props;
        XYDIM m_progressbar_height;
        CTResourcePack::ProgressBarDrawModeType m_progressbar_draw_mode;
        Bitmap* m_progressbar_bitmap;
        BOOLEAN m_progressbar_draw_percentage;
        TextFormat m_progressbar_textformat;

        CommonProperties m_progressbar_bar_props;

        CommonProperties m_controlframe_props;

        CommonProperties m_pushbutton_props;
        XYDIM m_pushbutton_height;
        TextFormat m_pushbutton_textformat;

        CommonProperties m_positionindicator_props;
        XYDIM m_positionindicator_width;
        BOOLEAN m_positionindicator_draw_arrows;

        CommonProperties m_positionindicatorbar_props;

        CommonProperties m_positionindicator_arrowbox_props;
        XYDIM m_positionindicator_arrowbox_height;

        friend class CTResourceParser;
};

#endif  // Apoxi_CTResourcePack_hpp


