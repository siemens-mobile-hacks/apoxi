/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GifImage_hpp)
#define Apoxi_GifImage_hpp

#include <Gui/Image.hpp>
#include <Auxiliary/BinData.hpp>
#include <Kernel/Threadlet.hpp>
#include <Auxiliary/Vector.hpp>

class GifImage : public Image {
    typedef Image Base;

    public:
        enum {
            ID = 2
        };
            
        GifImage();

        GifImage(BinData* bin_data, BOOLEAN* success = 0);

        virtual ~GifImage();

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

        virtual BOOLEAN IsTransparent(void* context) const;

        virtual ColorValue GetTransparentColor(void* context) const;
        
        virtual BOOLEAN IsFullTraversingEnabled(void* context) const;

        virtual XYDIM GetFrameWidth(void* context) const;
    
        virtual XYDIM GetFrameHeight(void* context) const;
        
        virtual XYDIM GetFrameXPos(void* context) const;

    private:            
        void AddFrameHandle(UINT32 handle) {m_frame_offsets.PushBack(handle);}

        UINT32 GetFrameHandle(INT frame_idx) const {ASSERT(frame_idx <= m_frame_offsets.GetSize());
                                                    return m_frame_offsets[frame_idx];}
        
        void AddFrameDelay(UINT32 delay) {m_frame_delays.PushBack(delay);}

        UINT32 GetStoredFrameDelay(INT frame_idx) const {ASSERT(frame_idx <= m_frame_delays.GetSize());
                                                        return m_frame_delays[frame_idx];}

        BinData* m_bin_data;
        Vector<UINT32> m_frame_offsets;
        Vector<UINT32> m_frame_delays;
        mutable INT m_pass_count;

        friend class GifDecoder;
};

#endif  //Apoxi_GifImage_hpp


