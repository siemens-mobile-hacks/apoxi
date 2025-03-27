/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgImage_hpp)
#define Apoxi_SvgImage_hpp

#include <Gui/Image.hpp>
#include <Auxiliary/BinData.hpp>
#include <Kernel/Allocator.hpp>
#include <AddOns/Svg/SvgFixPoint.hpp>

#define SVGIMAGE_DEFAULT_WIDTH  128
#define SVGIMAGE_DEFAULT_HEIGHT 128

class SvgDecoder;

class SvgImage : public Image {
        typedef Image Base;

    public:
        enum {
            ID = 9
        };

        SvgImage();

        SvgImage(BinData* data, BOOLEAN* p_success = 0);

        virtual ~SvgImage();

        void Init();

        BOOLEAN Init(BinData* data);

        BOOLEAN Load(BinData* data);

        virtual BOOLEAN Draw(DeviceContext *dc, XYDIM x, XYDIM y,
                         INT frame_idx,
                         XYDIM scaled_width = -1,
                         XYDIM scaled_height = -1,
                         const Rect &clip_rect = Rect()) const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual INT GetNextFrame(INT frame_idx) const;

        virtual UINT32 GetFrameDelay(INT frame_idx) const;

        virtual const BinData* GetBinData() const;

        virtual BOOLEAN DecodeSynchronously() const;

        virtual BOOLEAN IsBufferingAllowed() const;

        BOOLEAN Rotate(SvgFixPoint angle, SvgFixPoint x, SvgFixPoint y);

        BOOLEAN SetZoomLevel(SvgFixPoint magnification);

        BOOLEAN Pan(SvgFixPoint dx, SvgFixPoint dy);

        void ResetTransformation();

        BOOLEAN ToViewportSpace(SvgFixPoint user_x,
                                SvgFixPoint user_y,
                                XYDIM& viewport_x,
                                XYDIM& viewport_y) const;
 
        BOOLEAN ToUserSpace(XYDIM viewport_x, 
                            XYDIM viewport_y,
                            SvgFixPoint& user_x,
                            SvgFixPoint& user_y) const;

        BOOLEAN SetViewportSize(XYDIM width, XYDIM height);

    protected:
        virtual BOOLEAN IsTransparent(void* context) const;

        virtual ColorValue GetTransparentColor(void* context) const;

        virtual BOOLEAN HasAlphaChannel(void* context) const;

    // private: TODO: should be private!
        // Variable to track the correct time offset
        Ticks m_ticks;
        mutable UINT32 m_player_time_offset;
        mutable UINT32 m_normalized_time;
        mutable INT32 m_delta;

        BinData* m_data;
        SvgDecoder* m_decoder;
        mutable INT m_set_frame_idx;

        INT m_frames;
        INT8 m_previous_zoom_level;

        SvgFixPointTrans m_trans;

        mutable Bitmap* m_svg_bitmap;
        mutable XYDIM m_svg_width;
        mutable XYDIM m_svg_height;
        mutable struct {
            UINT memory_alloc_failure   : 1;
            UINT first_frame            : 1;
            UINT is_loading             : 1;
        } m_bits;

    private:
        void InitProperties();
        BOOLEAN Load(BinData* data, BOOLEAN blocking);   
};

#endif  // Apoxi_SvgImage_hpp

