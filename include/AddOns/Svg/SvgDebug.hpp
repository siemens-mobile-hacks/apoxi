/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgPlayerDebug_hpp)
#define Apoxi_SvgPlayerDebug_hpp

#include "SvgConfig.hpp"

#define SVG_DBG_SECTION_DECODER     0x00000001
#define SVG_DBG_SECTION_CALLBACK    0x00000002
#define SVG_DBG_SECTION_PLAYER      0x00000004
#define SVG_DBG_SECTION_IMAGE       0x00000008
#define SVG_DBG_SECTION_FILEWRAPPER 0x00000010
#define SVG_DBG_SECTION_MEMORY      0x00000020
#define SVG_DBG_SECTION_MEMORY_PROF 0x00000040
#define SVG_DBG_SECTION_MIME        0x00000080
#define SVG_DBG_SECTION_TEST        0x00000100
#define SVG_DBG_SECTION_FIXPOINT    0x00000200
#define SVG_DBG_SECTION_GZ          0x00000400
#define SVG_DBG_SECTION_SYSFONTS    0x00000800

#ifdef SVG_DEBUG

#define SVG_DBG_USED_SECTIONS (SVG_DBG_SECTION_TEST | SVG_DBG_SECTION_IMAGE | SVG_DBG_SECTION_DECODER | SVG_DBG_SECTION_CALLBACK | SVG_DBG_SECTION_MEMORY_PROF)
#define SVG_DBG_SECTIONS_USE_ALL 0

#define SVG_DBG_OUT(SECTION, DATA) \
    if((SECTION & SVG_DBG_USED_SECTIONS) || SVG_DBG_SECTIONS_USE_ALL){ \
        DBG_OUT(DATA); \
    }

#define SVG_ASSERT(COND) \
    if(!(COND)){ \
        DBG_OUT((0, "ASSERTION \"" #COND "\" FAILED AT: \"%s:%d\"\n", __FILE__, __LINE__)); \
    }

#define SVG_PRINT_IMAGE_ERROR(ERROR_CODE) \
    switch(ERROR_CODE) \
    { \
        case Image::NoError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: NoError\n")); \
            break; \
        case Image::UnspecifiedError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: UnspecifiedError\n")); \
            break; \
        case Image::InvalidSizeError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: InvalidSizeError\n")); \
            break; \
        case Image::InitializationError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: InitializationError\n")); \
            break; \
        case Image::ScanlineBufferError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: ScanLineBufferError\n")); \
            break; \
        case Image::MissingDataError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: MissingDataError\n")); \
            break; \
        case Image::IsCurrentlyDecodedError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: IsCurrently>DecodedError\n")); \
            break; \
        case Image::CouldNotAllocateThreadletError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: CouldNotAllocateThreadletError\n")); \
            break; \
        case Image::ThreadletStoppedError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: ThreadletStoppedError\n")); \
            break; \
        case Image::OutOfMemoryError: \
            SVG_DBG_OUT(SVG_DBG_SECTION_DECODER, (0, "*** SVGPLAYER::Callback_OpenStream() : Jpeg init error: OutOfMemory\n")); \
            break; \
        default: \
            break; \
    }


#else 

#define SVG_DBG_OUT(SECTION, DATA) 
#define SVG_ASSERT(COND)
#define SVG_PRINT_IMAGE_ERROR(ERROR_CODE)

#endif // SVG_DEBUG
 
#endif // SvgPlayerDebug_hpp

