/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DisplayConfig_hpp)
#define Apoxi_DisplayConfig_hpp

#include <Kernel/Types.hpp>

struct ColorTable;
struct ColorSegmentation;

class DisplayConfig {
    public:
        static UINT8 GDI_HUGE* GetFrameBuffer(INT display_idx);
        
        static UINT8 GDI_HUGE* GetTransferBuffer(INT display_idx);

        static UINT8 GDI_HUGE* GetMaskBuffer(INT display_idx);
        
        static INT GetDisplayCount();

        static XYDIM GetWidth(INT display_idx);

        static XYDIM GetHeight(INT display_idx);

        static INT GetBitsPerPixel(INT display_idx);

        static BOOLEAN PlanesMode(INT display_idx);
        
        static const ColorTable& GetColorTable(INT display_idx);

        static const ColorSegmentation& GetColorSegmentation(INT display_idx);
};

#endif  // Apoxi_DisplayConfig_hpp

