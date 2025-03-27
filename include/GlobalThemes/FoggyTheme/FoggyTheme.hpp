/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_FoggyTheme_hpp)
#define Apoxi_FoggyTheme_hpp

#include <Gui/Theme.hpp>

#include <GlobalThemes/FoggyTheme/FoggyWindowFrameView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultControlFrameView.hpp>
#include <GlobalThemes/FoggyTheme/FoggyPositionIndicatorView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultProgressBarView.hpp>
#include <GlobalThemes/FoggyTheme/FoggyPushButtonView.hpp>
#include <GlobalThemes/FoggyTheme/FoggyPanelView.hpp>

#ifndef APOXI_DISABLE_TAB_CONTROL
    #include <GlobalThemes/DefaultTheme/DefaultTabControlView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultTabButtonView.hpp>
#endif

#ifdef APOXI_COMPAT_1_9_0
    #include <GlobalThemes/DefaultTheme/DefaultTextListView.hpp>
    #include <GlobalThemes/FoggyTheme/FoggySoftkeyBarView.hpp>
#endif

#ifdef APOXI_COMPAT_1_7_0
    #include <GlobalThemes/DefaultTheme/DefaultCheckBoxView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultRadioButtonView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultCheckBoxListView.hpp>
    #include <GlobalThemes/DefaultTheme/DefaultRadioButtonListView.hpp>
#endif

/*  ------------------------------------------------------------------------
    FoggyTheme
    ------------------------------------------------------------------------*/
class FoggyTheme : public Theme {
    typedef Theme Base;
    
    public:
        static const Theme& GetInstance();
        virtual ~FoggyTheme();
        
        virtual const WCHAR* GetName() const;
        virtual void Update();
        virtual const ColorTable* GetSystemColorTable() const;
        virtual const WindowFrameView* GetWindowFrameView() const;
        virtual const ControlFrameView* GetControlFrameView() const;

        virtual const PositionIndicatorView* GetPositionIndicatorView() const;
        virtual const ProgressBarView* GetProgressBarView() const;
        virtual const PushButtonView* GetPushButtonView() const;
        virtual const PanelView* GetPanelView() const;

        #ifndef APOXI_DISABLE_TAB_CONTROL
            virtual const TabControlView* GetTabControlView() const;
            virtual const TabButtonView* GetTabButtonView() const;
        #endif

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

    private:
        FoggyWindowFrameView m_window_frame_view;
        DefaultControlFrameView m_control_frame_view;
        FoggyPositionIndicatorView m_position_indicator_view;
        DefaultProgressBarView m_progress_bar_view;
        FoggyPushButtonView m_push_button_view;
        FoggyPanelView m_panel_view;

        #ifndef APOXI_DISABLE_TAB_CONTROL
            DefaultTabControlView m_tab_control_view;
            DefaultTabButtonView m_tab_button_view;
        #endif

        #ifdef APOXI_COMPAT_1_9_0
            DefaultTextListView m_text_list_view;
            FoggySoftkeyBarView m_softkey_bar_view;
        #endif

        #ifdef APOXI_COMPAT_1_7_0
            DefaultCheckBoxView m_check_box_view;
            DefaultRadioButtonView m_radio_button_view;
            DefaultCheckBoxListView m_check_box_list_view;
            DefaultRadioButtonListView m_radio_button_list_view;
        #endif

        static FoggyTheme m_foggy_theme;

        FoggyTheme();
};

#ifdef APOXI_COMPAT_1_9_0
    #define foggy_theme FoggyTheme::GetInstance()
#endif

#endif


