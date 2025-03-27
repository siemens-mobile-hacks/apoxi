/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_WbmpImage_hpp)
#define Apoxi_WbmpImage_hpp

#include <Auxiliary/BinData.hpp>
#include <Gui/Image.hpp>



class WbmpImage : public Image {
    typedef Image Base;

    public:
        enum {
            ID = 5
        };
        
        WbmpImage();

        WbmpImage(BinData* data, BOOLEAN* success = 0);
        
        virtual ~WbmpImage();

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        void Init(BinData* data, BOOLEAN* success = 0);
        
        virtual const BinData* GetBinData() const;

        virtual INT GetNextFrame(INT frame_idx) const { return frame_idx; }

        virtual UINT32 GetFrameDelay(INT frame_idx) const { return c_unlimited; }

    protected:
        virtual void* BeginScanlineDrawing(INT frame_idx = 0) const;

        virtual void EndScanlineDrawing(void* context) const;

        virtual void DrawScanline(void* context,
                                  DeviceContext* dc,
                                  XYDIM x,
                                  XYDIM y,
                                  INT scanline_idx,
                                  INT old_scanline_idx) const;

        virtual BOOLEAN IsTransparent(void* context) const;

        virtual ColorValue GetTransparentColor(void* context) const;

    private:            
        BinData* m_bin_data;
};

#endif


