/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsImage_hpp)
#define Ems_EmsImage_hpp

#include <Gui/Image.hpp>
#include <Auxiliary/BinData.hpp>

class EmsImage : public Image 
{
    typedef Image Base;
    public:     
    
        enum {
            ID = 3
        };

        EmsImage(XYDIM width, XYDIM height, UINT8 frames, BinData* data, UINT8 anim_control = 0);
        virtual ~EmsImage();
        
        virtual INT GetId() const;
        virtual void Draw(DeviceContext* dc, XYDIM x, XYDIM y, INT frame_idx, const Rect& clip_rect) const;
        virtual INT GetNextFrame(INT frame_idx) const;
        virtual UINT32 GetFrameDelay(INT frame_idx) const;

        BinData* GetPlainData() { return m_data; }
        virtual const BinData* GetBinData() const;

    private:
        /*
        INT ConvertToMonochrome(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo2BitGs(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo4BitColor(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo4BitGs(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo8BitColor(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo8BitGs(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo16BitColor(INT offset, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo24BitColor(INT offset, INT frame_idx, UINT8* pixel_buffer, INT buffer_length);
        INT ConvertTo32BitColor(INT offset, INT frame_idx, UINT8* pixel_buffer, INT buffer_length);
        */
        BinData*    m_data;
        UINT32      m_delay;
};

#endif // Ems_EmsImage_hpp
