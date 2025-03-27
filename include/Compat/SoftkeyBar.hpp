/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoftkeyBar_hpp)
#define Apoxi_SoftkeyBar_hpp

class Window;
class Action;
class Message;

#include <Gui/DrawableObject.hpp>

#if !defined(APOXI_MAX_SOFTKEY_COUNT)
#define APOXI_MAX_SOFTKEY_COUNT 2
#endif

class SoftkeyBar : public DrawableObject {
    typedef DrawableObject Base;

    public:
        SoftkeyBar();

        SoftkeyBar(Window* win);

        virtual ~SoftkeyBar();

        void Init(Window* win);

        void Set(INT idx, Action* action);

        Action* Get(INT idx) const;

        void Trigger(INT idx) const;

        void SetPressedIndex(INT pressed_idx);

        INT GetPressedIndex() const { return m_pressed_idx; }

        INT GetSoftkeyCount() const;

        INT GetNoOfSoftkeys() const { return GetSoftkeyCount(); }

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

    private:
        INT m_pressed_idx;
        Action* m_actions[APOXI_MAX_SOFTKEY_COUNT];
};

class SoftkeyBarView : public DrawableObjectView {
    public:
        SoftkeyBarView();

        virtual ~SoftkeyBarView();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

    protected:
        virtual void DrawSoftkeyBar(const SoftkeyBar& softkey_bar, DeviceContext* dc, const Rect& repaint_rect) const = 0;
};

#endif  // Apoxi_SoftkeyBar


