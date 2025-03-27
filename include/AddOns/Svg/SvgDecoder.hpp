/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgDecoder_hpp)
#define Apoxi_SvgDecoder_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include <Kernel/Threadlet.hpp>
#include "SvgConfig.hpp"

#include "zpplayerh.h"
#include "zpdisplaybufferh.h"


#ifdef APOXI_ENABLE_SVG_FONT_SERIALIZATION
    #include <Afs/Rfs/File.hpp>
    #include "zpwritecallbackh.h"
#endif

#define SVG_METADATA_NO_SUCH_KEY          0

#define SVG_METADATA_TYPE_STRING          1
#define SVG_METADATA_TYPE_INT             2

#define SVG_METADATA_PLAYER_NAME          1
#define SVG_METADATA_PLAYER_VERSION       2
#define SVG_METADATA_PRESENTATION_TITLE   3
#define SVG_METADATA_PRESENTATION_DESC    4

#define SVG_DURATION_UNKNOWN              0xFFFFFFFF

typedef enum {
  SvgDecoderNoError = 0,
  SvgDecoderNoAnimationLoadedError = 2,
  SvgDecoderNoWidthSpecifiedError,
  SvgDecoderNoHeightSpecifiedError,
  SvgDecoderNoSuchMetadataKeyError,
  SvgDecoderDurationUnknownError,
  SvgDecoderAllocationError,
  SvgDecoderMethodNotImplementedError,
  SvgDecoderInitializationError,
  SvgDecoderInvalidInputParameterError,
  SvgDecoderNoLinkActivatedError,
  SvgDecoderNoSuchEventError
} SvgDecoderError;

typedef enum {
  SvgDecoderNoEvent = 0,
  /* Normal Events */
  SvgDecoderActivateEvent,
  SvgDecoderClickEvent,
  SvgDecoderMouseUpEvent,
  SvgDecoderMouseDownEvent,
  SvgDecoderShowHyperlinksEvent,
  SvgDecoderHideHyperlinksEvent,
  SvgDecoderSelectNextHyperlinkEvent,
  SvgDecoderSelectPreviousHyperlinkEvent,

  /* Special Root Element events */
  SvgDecoderFocusInEvent = 64,
  SvgDecoderFocusOutEvent,
  SvgDecoderUiActivateEvent,

} SvgDecoderInputEvent;

typedef enum {
  SvgDecoderNoChangeEvent = 0,
  SvgDecoderTimeHasChangedEvent,
  SvgDecoderExternalHyperlinkActivatedEvent,
  SvgDecoderHyperlinkListChangedEvent
} SvgDecoderOutputEvent;

class SvgDecoder;

class SvgDecoderThreadlet : public Threadlet {
    typedef Threadlet Base;

    public:
        virtual ~SvgDecoderThreadlet();

        static SvgDecoderThreadlet* CreateInstance(SvgDecoder* decoder,
                                                   BinData* bindata);

        virtual void ReleaseInstance();

        virtual INT Fn();

    private:
        SvgDecoder* m_decoder;
        BinData* m_bindata;
        
        SvgDecoderThreadlet(SvgDecoder* decoder, BinData* bindata);
};

class SvgDecoder {
  public:
    SvgDecoder(BOOLEAN *p_success = 0);
    BOOLEAN Init();
    ~SvgDecoder(void);
    SvgDecoderError GetError(void) const { return m_last_error_code; };
    UINT8 GetBytesPerPixel(void) const { return SVG_BYTES_PER_PIXEL; };
    BOOLEAN SetFrameBuffer(void *p_frame_buffer, UINT16 width, UINT16 height);
    BOOLEAN Load(BinData *p_bin_data, BOOLEAN blocking);
    BOOLEAN Unload(void);
    INT16 GetWidth(BOOLEAN *p_is_percent, UINT32 offset_millis = 0);
    INT16 GetHeight(BOOLEAN *p_is_percent, UINT32 offset_millis = 0);
    INT16 ScaleWidthHeight(INT16 *width, INT16 *height, UINT32 offset_millis = 0);
    INT8  GetMetaDataType(UINT16 key);
    INT16 GetMetaDataStringLength(UINT16 key);
    BOOLEAN GetMetaDataString(UINT16 key, WCHAR *p_buffer, INT16 buffer_length);
    INT32 GetMetaDataInteger(UINT16 key);
    UINT32 GetDuration(void);
    BOOLEAN SetTransformation(INT32 x_scale, INT32 y_scale, INT32 x_shear, INT32 y_shear, INT32 x_trans, INT32 y_trans);
    BOOLEAN RenderFrameAt(UINT32 offset_mills);
    BOOLEAN RenderFrameAtWithEvent(UINT32 offset_millis, SvgDecoderInputEvent input_event, SvgDecoderOutputEvent *p_output_event);
    INT16 GetLastSelectedHyperlinkLength(void) const { return m_last_selected_hyperlink_length; };
    BOOLEAN GetLastSelectedHyperlink(UINT8 *p_buffer, UINT32 time_offset = 0);
    BOOLEAN IsDocumentZoomAndPanAble() const;
    void ToUserSpace(INT32 viewportX, INT32 viewportY, INT32& userX, INT32& userY, XYDIM width, XYDIM height, BOOLEAN* visible, UINT32 time_offset);
    void ToViewportSpace(INT32 userX, INT32 userY, INT32& viewportX, INT32& viewportY, XYDIM width, XYDIM height, BOOLEAN* visible, UINT32 time_offset);

    const BinData* GetBinData() const {
        return m_svg_data;
    };

#ifdef APOXI_ENABLE_SVG_FONT_SERIALIZATION
    BOOLEAN SerializeSvgFont(FilePtr file);
#endif

  private:
    /* framebuffer in which the frames are rendered */
    void *m_frame_buffer;

    /* the last error that the player did */
    SvgDecoderError m_last_error_code;

    /* zoomon player */
    ZPPlayer *m_player;
    ZPNativeGraphicsInfo m_display_info;
    ZPDisplayBuffer m_display_buffer;
    BOOLEAN* m_is_loading;

    /* The string length of the last selected hyperlink */
    INT16 m_last_selected_hyperlink_length;

    /* struct containing the callback pointers */
    ZPCallback m_callbacks;

    /* Carries the SVG data */
    BinData *m_svg_data;

    /* Callbacks used by the ZoomOn Player */
    static void*    Callback_Malloc(void *p_userdata, ZPUInt32 min_size, ZPUInt32 *p_allocated_size);
    static void     Callback_Free(void *p_userdata, void *p_memory);
    static ZPStatus Callback_OpenStream(void *p_userdata, const ZPChar8 *p_xml_base, const ZPChar8 *p_href, ZPMIMEContentType *p_content, void **pp_stream_handle);
    static ZPStatus Callback_ReadStream(void *p_userdata, void *p_stream_handle, void *p_buffer, const ZPSize buffer_size, ZPSize *p_bytes_read);
    static void     Callback_CloseStream(void *p_userdata, void *p_stream_handle);
    static ZPStatus Callback_OpenDecodeSession(void *p_userdata, void *p_stream_handle, const ZPMIMEContentType content, void **pp_decode_session_handle);
    static ZPStatus Callback_GetImageSize(void *p_userdata, void *p_decode_session_handle, ZPSize *p_width, ZPSize *p_height);
    static ZPStatus Callback_DecodeImage(void *p_userdata, void *p_decode_session_handle, ZPUInt8 *p_target_buffer, const ZPSize target_buffer_size);
    static void     Callback_CloseDecodeSession(void *p_userdata, void *p_decode_session_handle);
    static void*  Callback_IndexFont(void *p_userdata, const ZPChar16 **p_fontfamily_list, const ZPSize *p_fontfamily_list_length, ZPSize no_of_fontfamilies, ZPUInt8 weight, ZPBool italic);
    static void   Callback_RenderText(void *p_userdata, void *p_fontindex, const ZPChar16 *p_text, ZPSize no_of_glyphs, ZPTextPosition *p_text_position, ZPTextRenderGraphics *p_graphics, ZPRasterInt *p_left, ZPRasterInt *p_bottom, ZPRasterInt *p_width, ZPRasterInt *p_height, ZPRasterInt *p_text_advance);
#ifdef APOXI_ENABLE_SVG_FONT_SERIALIZATION
    static ZPStatus Callback_WriteStream(void *pUserData, void *pOutStream, const ZPUInt8 *pData, ZPSize size);
    static ZPStatus Callback_SeekStream(void *pUserData, void *pOutStream, const ZPInt offset, ZPWriteCallbackSeekOrigin origin);

    static UINT32 m_write_offset;
#endif
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_SvgDecoder_hpp

