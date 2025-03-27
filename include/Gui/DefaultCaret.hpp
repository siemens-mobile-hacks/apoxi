/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultCaret_hpp)
#define Apoxi_DefaultCaret_hpp

#include <Gui/Caret.hpp>
#include <Gui/EditorDocument.hpp>
#include <Gui/DrawableObject.hpp>
#include <Auxiliary/TriggerTimer.hpp>

class DefaultCaret : public Caret {
    typedef Caret Base;

    public:
        DefaultCaret();

        DefaultCaret(AbstractEditor* editor,
                     UINT32 blink_rate,
                     Caret::Mode mode = Insert);
        
        virtual ~DefaultCaret();

        virtual void SetRow(INT row);

        virtual void SetColumn(INT column);

        virtual void SetVisible(BOOLEAN visible);

        virtual XYDIM GetMinimalWidth() const;

        virtual void Draw(DeviceContext* dc,
                          const Rect& bounds,
                          BOOLEAN right_to_left = FALSE) const;

        BOOLEAN IsBlinking() const { return m_blinking; }

    private:
        friend class TriggerTimer<DefaultCaret>;
        
        BOOLEAN m_blinking;
        TriggerTimer<DefaultCaret> m_blinking_timer;

        void OnTimer();
        void Update();
};

#endif  // Apoxi_DefaultCaret_hpp


