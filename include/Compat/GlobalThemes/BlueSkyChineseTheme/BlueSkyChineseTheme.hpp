/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_BlueSkyChineseTheme_hpp)
#define Apoxi_BlueSkyChineseTheme_hpp

#include <Gui/Theme.hpp>

#include <GlobalThemes/BlueSkyTheme/BlueSkyWindowFrameView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyControlFrameView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyCheckBoxView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyRadioButtonView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyCheckBoxListView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyRadioButtonListView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyTextListView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkySoftkeyBarView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyPositionIndicatorView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyProgressBarView.hpp>
#include <GlobalThemes/BlueSkyTheme/BlueSkyPushButtonView.hpp>

class BlueSkyChineseTheme : public Theme {
    public:
        BlueSkyChineseTheme();
        virtual ~BlueSkyChineseTheme();
        virtual const SystemColor GetSystemColor(SystemColorId id) const;
        virtual const FontId GetSystemFontId(SystemFontId id) const;
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
        BlueSkyWindowFrameView          m_window_frame_view;
        BlueSkyControlFrameView         m_control_frame_view;
        BlueSkyCheckBoxView             m_check_box_view;
        BlueSkyRadioButtonView          m_radio_button_view;
        BlueSkyCheckBoxListView         m_check_box_list_view;
        BlueSkyRadioButtonListView      m_radio_button_list_view;
        BlueSkyTextListView             m_text_list_view;
        BlueSkySoftkeyBarView           m_softkey_bar_view;
        BlueSkyPositionIndicatorView    m_position_indicator_view;
        BlueSkyProgressBarView          m_progress_bar_view;
        BlueSkyPushButtonView           m_push_button_view;
};

extern const BlueSkyChineseTheme blue_sky_chinese_theme;

#endif


