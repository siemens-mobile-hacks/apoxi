/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BmpImage_hpp)
#define Apoxi_BmpImage_hpp

#include <Gui/Image.hpp>
#include <Auxiliary/BinData.hpp>


class BmpImage : public Image {
    typedef Image Base;

    public:
        enum {
            ID = 1
        };
                
        BmpImage();

        BmpImage(BinData* bin_data, BOOLEAN* success = 0);

        virtual ~BmpImage();

        void Init(BinData* bin_data, BOOLEAN* success = 0);
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual const BinData* GetBinData() const;

        virtual INT GetNextFrame(INT frame_idx) const;

        virtual UINT32 GetFrameDelay(INT frame_idx) const;

    protected:
        virtual void* BeginScanlineDrawing(INT frame_idx = 0) const;

        virtual void EndScanlineDrawing(void* context) const;

        virtual void DrawScanline(void* context,
                                  DeviceContext* dc,
                                  XYDIM x,
                                  XYDIM y,
                                  INT scanline_idx,
                                  INT old_scanline_idx) const;

        virtual XYDIM GetScanlineDiff(void* context,
                                      INT scanline_idx,
                                      INT old_scanline_idx) const;


        virtual ColorValue GetTransparentColor(void* context) const;
        
        virtual BOOLEAN IsFullTraversingEnabled(void* context) const;

    private:            
        BinData* m_bin_data;
};

#endif  //Apoxi_GifImage_hpp


