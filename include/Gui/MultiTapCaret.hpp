/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MultiTapCaret_hpp)
#define Apoxi_MultiTapCaret_hpp

#include <Gui/DefaultCaret.hpp>

class MultiTapCaret : public DefaultCaret {
    typedef DefaultCaret Base;

    public:
        MultiTapCaret();

        MultiTapCaret(AbstractEditor* editor,
                      UINT32 blink_rate,
                      BOOLEAN show_preview = TRUE,
                      Caret::Mode mode = Insert);
        
        virtual ~MultiTapCaret();

        virtual XYDIM GetMinimalWidth() const;

        virtual void Draw(DeviceContext* dc, const Rect& bounds, BOOLEAN right_to_left = FALSE) const;

        virtual void ShowHint() const;

        void SetTabbing(BOOLEAN flag) { m_flags.tabbing = flag; }   //lint !e732

        BOOLEAN IsTabbing() const { return (BOOLEAN)m_flags.tabbing; }

        void SetPreview(const WCHAR* preview, INT index);

        const WCHAR* GetPreview(INT* prev_idx = 0) const;

    private:
        struct {
            UINT tabbing        : 1;
            UINT show_preview   : 1;
        } m_flags;

        const WCHAR* m_preview;
        INT         m_preview_idx;
        
        Rect GetPreviewRect(const Font& font,
                            TextAttr text_attr,
                            INT start_idx,
                            INT length) const;

        XYDIM GetMinGlyphWidth() const { return 8; }

        void DrawGlyph(DeviceContext& dc,
                       XYDIM x,
                       XYDIM y,
                       WCHAR chr,
                       XYDIM glyph_inc) const;
};

#endif  // Apoxi_MultiTapCaret_hpp


