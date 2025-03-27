/* ------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgConfig_hpp)
#define Apoxi_SvgConfig_hpp

#define SVG_DEBUG

#define SVG_BYTES_PER_PIXEL 2

#define SVG_ANTI_ALIAS_LEVEL 2

#define SVG_FONT_ANTI_ALIAS_LEVEL 3

#define SVG_SMALLEST_PREFERED_MEM_CHUNK_SIZE 16384

#define SVG_FONT_RESOURCE_INLINE      0x01
#define SVG_FONT_RESOURCE_INLINE_FILENAME "fonts.hpp"
#define SVG_FONT_RESOURCE_FFS       ((SVG_FONT_RESOURCE_INLINE) ^ 0x01)
#define SVG_FONT_RESOURCE_FFS_FILENAME    L"svg_font_file.svgz"

#if defined(APOXI_ENABLE_SVG_SYSTEM_FONTS)
    #define SVG_FONT_USE_SYSTEM_FONT 1
#else
    #define SVG_FONT_USE_SYSTEM_FONT 0
#endif

#define SVG_LARGEST_IMAGE_SIZE 153600


#define SVG_VIRTUAL_HEAP    0

#define SVG_NUMBER_OF_ZOOMLEVELS 31

#define SVG_PLAYER_DEFAULT_WIDTH  128
#define SVG_PLAYER_DEFAULT_HEIGHT 128

#endif

