/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AnimatedTextLine_hpp)
#define Apoxi_AnimatedTextLine_hpp

#include <Auxiliary/TriggerTimer.hpp>
#include <Gui/TextLine.hpp>

class AnimatedTextLineView : public TextLineView {
    typedef TextLineView Base;

    public:
        AnimatedTextLineView();
        virtual ~AnimatedTextLineView();

    private:
        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
};

class AnimatedTextLine : public TextLine {
    typedef TextLine Base;

    public:
        enum {
            ID = 5
        };

        enum Type {
            Bounce,
            Cycle,
            OnlyOnce
        };

        AnimatedTextLine();

        AnimatedTextLine(Control* control, 
                         const WCHAR* text = 0, 
                         const TextFormat& text_format = TextFormat(),
                         Type anim_type = Cycle, 
                         UINT16 start_delay = 300,
                         UINT16 anim_speed = 200, 
                         XYDIM step = 2,
                         BOOLEAN auto_start = FALSE);

        virtual ~AnimatedTextLine();

        void SetHighlighted(BOOLEAN highlighted) const;

        void Init(Control* control,
                  const WCHAR* text = 0,
                  const TextFormat& text_format = TextFormat(), 
                  Type anim_type = Cycle,
                  UINT16 start_delay = 300,
                  UINT16 anim_speed = 200,
                  XYDIM step = 2,
                  BOOLEAN auto_start = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void SetText(const WCHAR* text);

        virtual void SetTextFormat(const TextFormat& text_format);

        virtual void SetFont(const Font& font);

        void Start();

        void Stop();

        BOOLEAN IsStarted() const { return m_started; }

        Type GetType() const { return m_type; }

        INT GetOffset() const { return m_offset; }

        XYDIM GetStep() const { return m_step; }

        XYDIM GetTextGap() const;
        
    protected:
        virtual void OnResize(XYDIM dx, XYDIM dy);
        
        virtual void Cleanup();
        
        virtual void Refresh(const Rect& rect);
        

    private:
        friend class TriggerTimer<AnimatedTextLine>;

        BOOLEAN m_started;
        BOOLEAN m_auto_start;
        XYDIM m_offset;
        XYDIM m_step;
        Type m_type;
        UINT16 m_animation_speed;
        TriggerTimer<AnimatedTextLine> m_timer;

        static AnimatedTextLineView m_view;

        void UpdateAnimationState();
        void OnTimer();

        XYDIM GetTextWidth() const;
};

#endif  // Apoxi_AnimatedTextLine_hpp

