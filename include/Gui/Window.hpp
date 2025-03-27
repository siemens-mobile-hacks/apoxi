/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Window_hpp)
#define Apoxi_Window_hpp

#include <Gui/Control.hpp>
#include <Auxiliary/WString.hpp>

class Action;
class Model;
class View;
class SoftkeyBar;
class WindowFrameView;
class AnimatedTextLine;
class ResourceParser;

#if !defined(APOXI_MAX_SOFTKEY_COUNT)
#define APOXI_MAX_SOFTKEY_COUNT 2
#endif

class Window : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 26
        };

        Window(Control* parent = 0);        

        virtual ~Window();

        void Init(Control* parent = 0);
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        virtual void SetTitle(const WCHAR* title);

        void SetTitle(const WString& title);

        virtual const WCHAR* GetTitle() const;

        virtual XYDIM GetDefaultWidth() const;

        virtual XYDIM GetDefaultHeight() const;

        virtual Rect GetClientRect() const;

        virtual void OpenModeless(const Rect& rect);

        void OpenModeless();

        virtual INT OpenModal(const Rect& rect);

        INT OpenModal();

        BOOLEAN IsOpen() const { return (BOOLEAN)m_bits.is_open; }

        virtual BOOLEAN Close(INT exit_code = 0);

        void SetFocusPriority(UINT8 priority);

        UINT8 GetFocusPriority() const { return (UINT8)m_bits.focus_priority; }
        
        virtual void SetSoftkey(INT index, Action* action);

        Action* GetSoftkey(INT index) const;

        void SetLeftSoftkey(Action* action);

        Action* GetLeftSoftkey() const;

        void SetRightSoftkey(Action* action);

        Action* GetRightSoftkey() const;

        virtual void SetDefaultSize();

        BOOLEAN HasDefaultSize() const { return (BOOLEAN)m_bits.has_default_size; }

        BOOLEAN IsSyncSoftkeysEnabled() const { return (BOOLEAN)m_bits.sync_softkeys; }

        BOOLEAN IsTitleAnimated() const;

        virtual void Maximize();

        void SetTransparent(BOOLEAN enabled);

        BOOLEAN IsTransparent() const { return (BOOLEAN)m_bits.is_transparent; }

        void AddToTitlebar(DrawableObject& obj, BOOLEAN align_left = TRUE);

        void RemoveFromTitlebar(DrawableObject& obj);

#if defined(APOXI_COMPAT_1_8_0)
#if !defined(APOXI_DISABLE_SOFTKEYBAR)

        void SetSoftkeyBar(SoftkeyBar* softkey_bar);

        SoftkeyBar* GetSoftkeyBar() const { return m_softkey_bar; }
#endif // APOXI_DISABLE_SOFTKEYBAR
#endif // APOXI_COMPAT_1_8_0
        
    protected:
        virtual void Refresh(const Rect& rect);

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual void OnOpen();

        virtual void OnClose();

        virtual void OnActionExecuted(Action* action);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnMove(XYDIM dx, XYDIM dy);

        virtual void OnResize(XYDIM dx, XYDIM dy);

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual const ControlFrameView* GetFrameView() const;

        virtual void OnLayoutFrame();

        virtual void OnLayoutClient();

        void SetSyncSoftkeysEnabled(BOOLEAN enabled) { m_bits.sync_softkeys = enabled; }

        void SetDefaultSizeProperty(BOOLEAN has_default_size) { m_bits.has_default_size = has_default_size; }

#if defined(APOXI_COMPAT_1_8_0)
#if !defined(APOXI_DISABLE_SOFTKEYBAR)

        virtual BOOLEAN OnSoftkeyPressed(INT idx);
#endif  // APOXI_DISABLE_SOFTKEYBAR
#endif  // APOXI_COMPAT_1_8_0

    private:
        struct {
            UINT is_open            : 1;
            UINT modal              : 1;
            UINT has_default_size   : 1;
            UINT sync_softkeys      : 1;
            UINT is_transparent     : 1;
            UINT focus_priority     : 8;
            UINT keep_anim_title    : 1;
            UINT frame_layout_hint  : 2;
        } m_bits;
        INT m_exit_code;
        WString m_title;
        Action* m_sk_actions[APOXI_MAX_SOFTKEY_COUNT];

#if defined(APOXI_ENABLE_ANIMATED_TITLE)
        AnimatedTextLine* m_anim_title ;
#endif
        
#if defined(APOXI_COMPAT_1_8_0)
#if !defined(APOXI_DISABLE_SOFTKEYBAR)
        SoftkeyBar* m_softkey_bar;      // obsolete - provided for backward-compatibility with version < 1.8.0
#endif  // APOXI_DISABLE_SOFTKEYBAR
#endif  // APOXI_COMPAT_1_8_0

        void InitProperties();
        void AdjustBounds();
        void SynchronizeSoftkeys();
        void ForwardFocus();
        void PrepareTitleAnimation();

        void IndicateAlphaMaskUpdate() const;

        void InternalRefresh(const Rect& rect);
        
#if defined(APOXI_ENABLE_ANIMATED_TITLE)

        void UpdateAnimatedTitleColor();
#endif
};

#endif  // Apoxi_Window_hpp

