/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FoggyTheme_hpp)
#define Apoxi_FoggyTheme_hpp

#include <Gui/Theme.hpp>

#include <GlobalThemes/DefaultTheme/DefaultWindowFrameView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultControlFrameView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultCheckBoxView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultRadioButtonView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultCheckBoxListView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultRadioButtonListView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultTextListView.hpp>
#include <GlobalThemes/FoggyTheme/FoggySoftkeyBarView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultPositionIndicatorView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultProgressBarView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultPushButtonView.hpp>

class FoggyTheme : public Theme {
    public:
        FoggyTheme();
        virtual ~FoggyTheme();
        virtual void Update();
        virtual const SystemColor GetSystemColor(SystemColorId id) const;
        virtual const WindowFrameView* GetWindowFrameView() const;
        virtual const ControlFrameView* GetControlFrameView() const;
        virtual const CheckBoxView* GetCheckBoxView() const;
        virtual const RadioButtonView* GetRadioButtonView() const;
        virtual const CheckBoxListView* GetCheckBoxListView() const;
        virtual const RadioButtonListView* GetRadioButtonListView() const;
        virtual const TextListView* GetTextListView() const;
        virtual const SoftkeyBarView* GetSoftkeyBarView() const;
        virtual const PositionIndicatorView* GetPositionIndicatorView() const;
        virtual const ProgressBarView* GetProgressBarView() const;
        virtual const PushButtonView* GetPushButtonView() const;

    private:
        DefaultWindowFrameView          m_window_frame_view;
        DefaultControlFrameView         m_control_frame_view;
        DefaultCheckBoxView             m_check_box_view;
        DefaultRadioButtonView          m_radio_button_view;
        DefaultCheckBoxListView         m_check_box_list_view;
        DefaultRadioButtonListView      m_radio_button_list_view;
        DefaultTextListView             m_text_list_view;
        FoggySoftkeyBarView             m_softkey_bar_view;
        DefaultPositionIndicatorView    m_position_indicator_view;
        DefaultProgressBarView          m_progress_bar_view;
        DefaultPushButtonView           m_push_button_view;
};

extern const FoggyTheme foggy_theme;

#endif


