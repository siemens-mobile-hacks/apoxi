/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Bitmap_hpp)
#define Apoxi_Bitmap_hpp

#include <Gui/Color.hpp>
#include <Gui/Size.hpp>

class Rect;
class DeviceContext;

struct BitmapRes {
    XYDIM GetWidth() const { return m_width; };

    XYDIM GetHeight() const { return m_height; };

    const DDrvAtomPtr GetBits() const { return m_bits; };

    const DDrvAtomPtr GetAlphaMask() const { 
                                            #ifdef APOXI_ENABLE_ALPHA_BLENDING
                                                return m_alphamask; 
                                            #else
                                                return 0;
                                            #endif
                                            }

    BOOLEAN IsTransparent() const { return (BOOLEAN)m_flags.transparent; }

    BOOLEAN IsCompressed() const { return (BOOLEAN)m_flags.compressed; }

    BOOLEAN IsCopyrighted() const { return (BOOLEAN)m_flags.copyrighted; }

    BOOLEAN IsAlphaBlendingEnabled() const {
#ifdef APOXI_ENABLE_ALPHA_BLENDING
                                                return (BOOLEAN)m_flags.alpha_blending_enabled;
#else
                                                return 0;
#endif
                                            }

    BOOLEAN HasNativeImageData() const { return (BOOLEAN)m_flags.has_native_img_data; }

    ColorValue GetTransparentColor() const { return m_transparent_color; }

    // Important: the order of the members must match with the order of the members
    // of the class Bitmap!
    struct {
        UINT transparent            : 1;
        UINT compressed             : 1;
        UINT copyrighted            : 1;
#ifdef APOXI_ENABLE_ALPHA_BLENDING
        UINT alpha_blending_enabled : 1;
#endif
        UINT has_native_img_data    : 1;
    } m_flags;
    XYDIM m_width;
    XYDIM m_height;
    const DDrvAtomPtr m_bits;
    ColorValue  m_transparent_color;
#ifdef APOXI_ENABLE_ALPHA_BLENDING
    const DDrvAtomPtr m_alphamask;
#endif
};

class Bitmap {
    typedef BitmapRes Base;

    public:
        Bitmap();

        Bitmap(XYDIM width,
               XYDIM height,
               BOOLEAN transparent = FALSE,
               ColorValue transparent_color = 0,
               BOOLEAN compressed = FALSE,
               BOOLEAN copyrighted = FALSE,
               INT display_idx = 0,
               DDrvAtomPtr external_buffer = 0,
               BOOLEAN free_external_buffer = FALSE,
               BOOLEAN create_alpha_mask = FALSE);

        ~Bitmap();

        operator BitmapRes() const;

        static UINT32 GetBufferByteCount(XYDIM width, XYDIM height, INT display_idx = 0);

        XYDIM GetWidth() const { return m_width; };

        void SetWidth(XYDIM width) { m_width = width; };

        XYDIM GetHeight() const { return m_height; };

        void SetHeight(XYDIM height) { m_height = height; };

        DDrvAtomPtr GetBits() const { return m_bits; };

        void SetBits(DDrvAtomPtr bits, BOOLEAN free_external_buffer = FALSE);
        
        void SetTransparent(BOOLEAN flag) { m_flags.transparent = flag; }

        BOOLEAN IsTransparent() const { return (BOOLEAN)m_flags.transparent; }
        
        BOOLEAN IsCompressed() const { return (BOOLEAN)m_flags.compressed; }

        BOOLEAN IsCopyrighted() const { return (BOOLEAN)m_flags.copyrighted; }

        BOOLEAN HasNativeImageData() const { return (BOOLEAN)m_flags.has_native_img_data; }

        BOOLEAN IsValid() const { return m_bits != 0; }

        void SetTransparentColor(ColorValue color) { m_transparent_color = color; }

        ColorValue GetTransparentColor() const { return m_transparent_color; }

        DDrvAtomPtr GetAlphaMask() const { 
#ifdef APOXI_ENABLE_ALPHA_BLENDING
                                            return m_alphamask; 
#else
                                            return 0;
#endif
                                            }
        void SetAlphaMask(DDrvAtomPtr alphamask);

        void SetAlphaValue(XYDIM x, XYDIM y, UINT8 alpha_value);

        UINT8 GetAlphaValue(XYDIM x, XYDIM y) const;

        BOOLEAN IsAlphaBlendingEnabled() const {
#ifdef APOXI_ENABLE_ALPHA_BLENDING
                                                return (BOOLEAN)m_flags.alpha_blending_enabled;
#else
                                                return FALSE;
#endif
                                            }

        void SetAlphaBlendingEnabled(BOOLEAN alpha_enabled) { 
#ifdef APOXI_ENABLE_ALPHA_BLENDING
                                                m_flags.alpha_blending_enabled = alpha_enabled;
#endif
                                                }
    private:
        // Important: the order of the members must match with the order of the members
        // of the struct BitmapRes!
        struct {
            UINT transparent                : 1;
            UINT compressed                 : 1;
            UINT copyrighted                : 1;
#ifdef APOXI_ENABLE_ALPHA_BLENDING
            UINT alpha_blending_enabled     : 1;
#endif
            UINT has_native_img_data        : 1;
            UINT free_external_buffer       : 1;
            UINT external_buffer            : 1;
#ifdef APOXI_ENABLE_ALPHA_BLENDING
            UINT alpha_external_buffer      : 1;
            UINT alpha_free_external_buffer : 1;
#endif
        } m_flags;

        XYDIM       m_width;
        XYDIM       m_height;
        DDrvAtomPtr m_bits;
        ColorValue  m_transparent_color;
#ifdef APOXI_ENABLE_ALPHA_BLENDING
        DDrvAtomPtr m_alphamask;
#endif
};

#endif  // Apoxi_Bitmap_hpp

