/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EditorLine_hpp)
#define Apoxi_EditorLine_hpp


class EditorLine {
    public:
        explicit EditorLine(INT start_idx = 0, INT length = 0, XYDIM height = 0);
        void SetStartIndex(INT start_idx) { m_start_idx = start_idx; }
        INT GetStartIndex() const { return m_start_idx; }
        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }
        void SetHeight(INT height) { m_height = height; }
        XYDIM GetHeight() const { return m_height; }

    private:
        INT m_start_idx;
        INT m_length;
        XYDIM m_height;
};

#endif  // Apoxi_EditorLine_hpp


