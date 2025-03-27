/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TabButton_hpp)
#define Apoxi_TabButton_hpp


#if !defined(APOXI_DISABLE_TAB_CONTROL)

struct BitmapRes;
class TabButton;
class ImageObtainer;

#include <Kernel/Types.hpp>
#include <Gui/AbstractButton.hpp>
#include <Gui/Action.hpp>
#include <Gui/View.hpp>

class TabButtonView : public View {
    typedef View Base;

    public:
        TabButtonView(XYDIM default_height,
                      XYDIM default_width = -1,
                      XYDIM min_width = -1,
                      XYDIM max_width = -1,
                      XYDIM clipped_width = 20);

        virtual ~TabButtonView();

        virtual void Draw(const Component& component,
                          DeviceContext* dc,
                          const Rect& repaint_rect) const;

        XYDIM GetMinimumWidth() const { return m_min_width; }
        XYDIM GetMaximumWidth() const { return m_max_width; }
        XYDIM GetClippedWidth() const { return m_clipped_width; }

    protected:
        virtual void DrawTabButton(const TabButton& tab_button,
                                   DeviceContext* dc,
                                   const Rect& repaint_rect) const = 0;

        void SetMinimumWidth(XYDIM min_width) { m_min_width = min_width; }
        void SetMaximumWidth(XYDIM max_width) { m_max_width = max_width; }
        void SetClippedWidth(XYDIM clipped_width) { m_clipped_width = clipped_width; }

    private:
        XYDIM m_min_width;
        XYDIM m_max_width;
        XYDIM m_clipped_width;
};

class TabButton : public AbstractButton {
    typedef AbstractButton Base;

    public:
        enum {
            ID = 22
        };

        enum PositionHint {
            LeftPos,
            MiddlePos,
            RightPos,
        };

        TabButton();

        TabButton(Control* parent, const WString& text, const BitmapRes* icon = 0);
        
        TabButton(Control* parent, const WString& text, const ImageObtainer& icon);

        virtual ~TabButton();

        void Init(Control* parent, const WString& text, const BitmapRes* icon = 0);
        
        void Init(Control* parent, const WString& text, const ImageObtainer& icon);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetActive(BOOLEAN active);

        BOOLEAN IsActive() const { return m_active; }

        void SetPositionHint(PositionHint pos_hint);

        PositionHint GetPositionHint() const { return m_pos_hint; }

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void OnThemeChanged();

    private:
        BOOLEAN m_active;
        PositionHint m_pos_hint;
        Action m_action;

        void InitProperties(const WString& text, const ImageObtainer& icon);
};

#endif // APOXI_DISABLE_TAB_CONTROL

#endif  // Apoxi_TabButton_hpp


