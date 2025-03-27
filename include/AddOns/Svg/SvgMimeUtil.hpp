/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgPlayerMIMEUtil_hpp)
#define Apoxi_SvgPlayerMIMEUtil_hpp

#define SVG_MIME_CONTENT_TYPE_NA         0

// MIME types for images must have bit 7 set (0x80)
#define SVG_MIME_CONTENT_TYPE_IMAGE      0x80
#define SVG_MIME_CONTENT_TYPE_IMAGE_JPEG 0x81
#define SVG_MIME_CONTENT_TYPE_IMAGE_PNG  0x82
#define SVG_MIME_CONTENT_TYPE_IMAGE_GIF  0x83
#define SVG_MIME_CONTENT_TYPE_IMAGE_WBMP 0x84
#define SVG_MIME_CONTENT_TYPE_IMAGE_SVG  0x85

#define SVG_MIME_CONTENT_TYPE_IS_IMAGE(CT) ((CT) & SVG_MIME_CONTENT_TYPE_IMAGE)

class SvgMimeUtil
{
  public:
    static UINT8 GetMimeContentType(const UINT8 *p_mime);
  private:
    static BOOLEAN StrCmp(const UINT8 *a, const UINT8 *b, UINT16 len);
    static UINT16 StrLen(const UINT8 *a, UINT16 max_length);
};
#endif

