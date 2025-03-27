/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestTheme_hpp)
#define Apoxi_TestTheme_hpp

#include <Gui/Theme.hpp>

#include <GlobalThemes/TestTheme/TestWindowFrameView.hpp>
#include <GlobalThemes/TestTheme/TestControlFrameView.hpp>
#include <GlobalThemes/TestTheme/TestCheckBoxView.hpp>
#include <GlobalThemes/TestTheme/TestRadioButtonView.hpp>
#include <GlobalThemes/TestTheme/TestCheckBoxListView.hpp>
#include <GlobalThemes/TestTheme/TestRadioButtonListView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultTextListView.hpp>            // using default-view
#include <GlobalThemes/TestTheme/TestSoftkeyBarView.hpp>
#include <GlobalThemes/TestTheme/TestPositionIndicatorView.hpp>
#include <GlobalThemes/DefaultTheme/DefaultProgressBarView.hpp>         // using default-view
#include <GlobalThemes/TestTheme/TestPushButtonView.hpp>

class TestTheme : public Theme {
    public:
        TestTheme();
        virtual ~TestTheme();
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
        TestWindowFrameView         m_window_frame_view;
        TestControlFrameView        m_control_frame_view;
        TestCheckBoxView            m_check_box_view;
        TestRadioButtonView         m_radio_button_view;
        TestCheckBoxListView        m_check_box_list_view;
        TestRadioButtonListView     m_radio_button_list_view;
        DefaultTextListView         m_text_list_view;
        TestSoftkeyBarView          m_softkey_bar_view;
        TestPositionIndicatorView   m_position_indicator_view;
        DefaultProgressBarView      m_progress_bar_view;
        TestPushButtonView          m_push_button_view;
};

extern const TestTheme test_theme;

#endif


