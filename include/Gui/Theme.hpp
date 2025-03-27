/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Theme_hpp)
#define Apoxi_Theme_hpp

class WindowFrameView;
class ControlFrameView;
class CheckBoxView;
class RadioButtonView;
class CheckBoxListView;
class RadioButtonListView;
class TextListView;
class PositionIndicatorView;
class ProgressBarView;
class PushButtonView;
class SoftkeyBarView;
class PanelView;
class TabControlView;
class TabButtonView;
class Theme;
class View;

struct ColorTable;
struct BitmapRes;

#include <Gui/Font.hpp>
#include <Gui/Color.hpp>

/*  Internal class, which allows to iterate through all theme views.
    The class should not be used by the MMI in a direct manner, as the
    interface might get changed in future releases. */
class ThemeViewIterator {
    public:
        ThemeViewIterator(Theme* theme);
        virtual ~ThemeViewIterator();
        void Begin();
        BOOLEAN Next();
        View* GetView() const;

    private:
        INT m_index;
        View* m_view;
        Theme* m_theme;
};

class Theme {
    public:
        enum BitmapResId {
            SelectedCheckBoxId,
            DeselectedCheckBoxId,
            SelectedRadioButtonId,
            DeselectedRadioButtonId,
        };

        virtual const WCHAR* GetName() const;

        virtual void Update();

        virtual const ColorTable* GetSystemColorTable() const;

        virtual ColorValue GetSystemColor(SystemColorId id) const;

        INT GetFontId(SystemFontId id) const;

        virtual const WindowFrameView* GetWindowFrameView() const = 0;

        virtual const ControlFrameView* GetControlFrameView() const = 0; 

        virtual const PositionIndicatorView* GetPositionIndicatorView() const = 0;

        virtual const ProgressBarView* GetProgressBarView() const = 0;

        virtual const PushButtonView* GetPushButtonView() const = 0;
        
        virtual const PanelView* GetPanelView() const;
        
        virtual const TabControlView* GetTabControlView() const;

        virtual const TabButtonView* GetTabButtonView() const;

        virtual const BitmapRes* GetBitmap(BitmapResId id) const;

#ifdef APOXI_COMPAT_1_9_0
        // Obsolete
        virtual INT GetId() const;

        virtual FontId GetSystemFontId(SystemFontId id) const;

        virtual const TextListView* GetTextListView() const = 0;

        virtual const SoftkeyBarView* GetSoftkeyBarView() const = 0;
#endif

#ifdef APOXI_COMPAT_1_7_0

        virtual const CheckBoxView* GetCheckBoxView() const;

        virtual const RadioButtonView* GetRadioButtonView() const;

        virtual const CheckBoxListView* GetCheckBoxListView() const;

        virtual const RadioButtonListView* GetRadioButtonListView() const;
#endif

    protected:
        Theme();
        virtual ~Theme();
        void SetSystemColor(SystemColorId id, ColorValue color_value);
        void SetFontId(SystemFontId id, INT font_id);

    private:
        ColorValue m_system_color_table[Color::SystemColorIdCount];
        INT m_system_font_table[Font::SystemFontIdCount];
};

#endif  // Apoxi_Theme_hpp


