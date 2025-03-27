/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_JpegImage_hpp)
#define Apoxi_JpegImage_hpp

#include <Gui/Image.hpp>
#include <Auxiliary/BinData.hpp>

class PaintDc;

class JpegImage : public Image {
    typedef Image Base;

    public:
        enum {
            ID = 3
        };

        JpegImage();

        JpegImage(BinData *data, BOOLEAN *success = 0);

        virtual ~JpegImage();

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void Init(BinData* jpeg_data, BOOLEAN* success = 0);

        virtual INT GetNextFrame(INT frame_idx) const;

        virtual UINT32 GetFrameDelay(INT frame_idx) const;

        virtual const BinData* GetBinData() const;

    protected:
        virtual void* BeginScanlineDrawing(INT frame_idx = 0) const;

        virtual void EndScanlineDrawing(void *context) const;

        virtual void DrawScanline(void *context, 
                                  DeviceContext *dc, 
                                  XYDIM x, 
                                  XYDIM y, 
                                  INT scanline_idx, 
                                  INT old_scanline_idx) const;

        void FreeImage();

    protected:
        BinData *m_data;
};

#endif  // Apoxi_JpegImage_hpp


