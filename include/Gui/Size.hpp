/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Size_hpp)
#define Apoxi_Size_hpp

#include <Kernel/Types.hpp>

class Size {
    public:
        Size(XYDIM width = 0, XYDIM height = 0) : m_width(width), m_height(height) {}
        Size(const Size& size) : m_width(size.GetWidth()), m_height(size.GetHeight()) {}
        void SetWidth(XYDIM width) { m_width = width; }
        XYDIM GetWidth() const { return m_width; }
        void SetHeight(XYDIM height) { m_height = height; }
        XYDIM GetHeight() const { return m_height; }

    private:
        XYDIM m_width;
        XYDIM m_height;
};

#endif  // Apoxi_Size_hpp


