/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ColorSegmentation_hpp)
#define Apoxi_ColorSegmentation_hpp


struct ColorSegmentation {
    INT GetAlphaBitCount() const { return m_alpha_bit_count; }
    INT GetRedBitCount() const { return m_red_bit_count; }
    INT GetGreenBitCount() const { return m_green_bit_count; }
    INT GetBlueBitCount() const { return m_blue_bit_count; }

    INT m_alpha_bit_count;
    INT m_red_bit_count;
    INT m_green_bit_count;
    INT m_blue_bit_count;
};

#endif  // Apoxi_ColorSegmentation_hpp


