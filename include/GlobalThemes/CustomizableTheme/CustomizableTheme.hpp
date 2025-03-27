/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_CTTheme_hpp)
#define Apoxi_CTTheme_hpp

#include <Gui/Theme.hpp>
#include <Gui/PaintDc.hpp>

#include "CTResourcePack.hpp"

#include "CTPanelView.hpp"
#include "CTWindowFrameView.hpp"
#include "CTPositionIndicatorView.hpp"
#include "CTProgressBarView.hpp"
#include "CTPushButtonView.hpp"
#include "CTControlFrameView.hpp"

#ifdef APOXI_COMPAT_1_9_0
    #include <GlobalThemes/DefaultTheme/DefaultTextListView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultSoftkeyBarView.hpp>
#endif

#ifdef APOXI_COMPAT_1_7_0
    #include <GlobalThemes/DefaultTheme/DefaultCheckBoxView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultRadioButtonView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultCheckBoxListView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultRadioButtonListView.hpp>
#endif

class ImageObtainer;
class AbstractItemContainer;

/*  ------------------------------------------------------------------------
    CustomizableTheme
    ------------------------------------------------------------------------*/
class CustomizableTheme : public Theme {
    typedef Theme Base;
    
    public:
        virtual ~CustomizableTheme();

        static const Theme& GetInstance(CTResourcePack* pack = 0);
        
        static CTResourcePack* GetResourcePackIfActive();
        
        void SetResourcePack(CTResourcePack* resource_pack) { m_resource_pack = resource_pack; }
        CTResourcePack* GetResourcePack() { return m_resource_pack; }

        virtual const WCHAR* GetName() const;
        virtual void Update();
        virtual const ColorTable* GetSystemColorTable() const;
        virtual const WindowFrameView* GetWindowFrameView() const;
        virtual const ControlFrameView* GetControlFrameView() const;
        
        virtual const PositionIndicatorView* GetPositionIndicatorView() const;
        virtual const ProgressBarView* GetProgressBarView() const;
        virtual const PushButtonView* GetPushButtonView() const;
        virtual const PanelView* GetPanelView() const;

        virtual const BitmapRes* GetBitmap(BitmapResId id) const;
        
        #ifdef APOXI_COMPAT_1_9_0
            virtual const TextListView* GetTextListView() const;
            virtual const SoftkeyBarView* GetSoftkeyBarView() const;
        #endif
            
        #ifdef APOXI_COMPAT_1_7_0
            virtual const CheckBoxView* GetCheckBoxView() const;
            virtual const RadioButtonView* GetRadioButtonView() const;
            virtual const CheckBoxListView* GetCheckBoxListView() const;
            virtual const RadioButtonListView* GetRadioButtonListView() const;
        #endif

        static Rect AdjustBounds(const Rect& bounds, CTResourcePack* pack, CTResourcePack::ResourceType resource);

        static void DrawComponent(PaintDc& pdc, 
                                  const Rect& bounds, 
                                  CTResourcePack* pack,
                                  CTResourcePack::ResourceType resource);

        static WString c_theme_name;

    private:
        CustomizableTheme();
        CustomizableTheme(CTResourcePack *resource_pack);

        CTPanelView                 m_panel_view;
        CTWindowFrameView           m_window_frame_view;
        CTPositionIndicatorView     m_position_indicator_view;
        CTProgressBarView           m_progress_bar_view;
        CTPushButtonView            m_push_button_view;
        CTControlFrameView          m_control_frame_view;

        #ifdef APOXI_COMPAT_1_9_0
            DefaultTextListView             m_text_list_view;
            DefaultSoftkeyBarView           m_softkey_bar_view;
        #endif

        #ifdef APOXI_COMPAT_1_7_0
            DefaultCheckBoxView             m_check_box_view;
            DefaultRadioButtonView          m_radio_button_view;
            DefaultCheckBoxListView         m_check_box_list_view;
            DefaultRadioButtonListView      m_radio_button_list_view;
        #endif

        static void DrawAngularBorderComponent(PaintDc& pdc, 
                                               const Rect& bounds_param,
                                               CTResourcePack* pack,
                                               CTResourcePack::ResourceType resource);

        static void DrawRoundedBorderComponent(PaintDc& pdc, 
                                             const Rect& bounds_param, 
                                             CTResourcePack* pack,
                                             CTResourcePack::ResourceType resource);
        
        void UpdateProperties();

        static CTResourcePack c_default_pack;
        static CustomizableTheme m_instance;
        CTResourcePack* m_resource_pack;
};

#endif


