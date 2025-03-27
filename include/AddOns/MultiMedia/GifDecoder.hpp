/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GifDecoder_hpp)
#define Apoxi_GifDecoder_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include "GifImage.hpp"
#include <Gui/Image.hpp>
#include <Gui/ImageDecoder.hpp>
#include <Auxiliary/BinData.hpp>

#define INPUT_BUFFER_SIZE   4096

class GifDecoder : public ImageDecoder {
    typedef ImageDecoder Base;

    public:
        static GifDecoder* GetInstance();

        virtual BOOLEAN GetMetaData(Image& image, Image::MetaData* meta_data);

        virtual BOOLEAN BeginDecoding(const Image& image, INT frame_idx = 0);

        virtual void EndDecoding(const Image& image, INT frame_idx = 0);
        
        BOOLEAN IsInterlaced() const { return m_interlaced;}
        
        UINT8* GetScanlineBuffer() const { return m_scanline_buffer; }

        BOOLEAN DecodeScanline(INT scanline_idx, INT old_scanline_idx, UINT32 size);

        ColorValue GetColor(INT index) const {  ASSERT_DEBUG_HOST(index >= 0);
                                                ASSERT_DEBUG_HOST(index < 256);
                                                ASSERT_DEBUG_HOST(m_color_table != 0);
                                                return *(m_color_table + index);
                                            };

        INT GetTransparentColorIndex() const { return m_transparent_color_idx; }

        INT GetBackgroundColorIndex() const {return m_background_idx; }
                
        ColorValue GetBackgroundColor() const {return m_background; }
        

        UINT8 GetDisposalMethod() const {return m_disposal_method; }
        
        XYDIM GetFrameXPos() const {return m_frame_xpos;}

        XYDIM GetFrameYPos() const {return m_frame_ypos;}
        
        XYDIM GetFrameWidth() const {return m_frame_width;}

        XYDIM GetFrameHeight() const {return m_frame_height;}

        const ColorValue* GetColorTable() const { return m_color_table;}

    private:
        BOOLEAN         m_user_input;
        BOOLEAN         m_interlaced;
        BOOLEAN         m_optimize_for_16bpp;
        BOOLEAN         m_global_color_table;
        UINT8           m_disposal_method;
        INT             m_background_idx;
        INT             m_frame_idx;
        INT             m_transparent_color_idx;
        XYDIM           m_frame_xpos;
        XYDIM           m_frame_ypos;
        XYDIM           m_frame_width;
        XYDIM           m_frame_height;
        INT             m_ct_size;
        INT             m_decompressed_scanline_idx;
        UINT32          m_offset;
        ColorValue      m_background;   

        UINT8* m_scanline_buffer;

        ColorValue* m_color_table;
    
        static GifDecoder m_decoder;

        GifImage* m_image;

        GifDecoder();
        BOOLEAN InitFrameData();
        BOOLEAN DecodeFrame(INT frame_idx);
        BOOLEAN GetFrameHandle(INT frame_idx);
        
        BOOLEAN OverreadExtensionBlock();
        BOOLEAN OverreadImageBlock();
        BOOLEAN ParseGraphicControlExtension(UINT32& frame_delay);
        BOOLEAN ParseImageDescriptor();
        BOOLEAN ParseApplicationExtension(INT& repeat_value);

        BOOLEAN DoubleTransparency();
        void ReplaceTransparent();
        
        BOOLEAN FillInputBuffer();
        BOOLEAN RelocateInputBuffer(UINT32 offset);

        // LZW decoding stuff
        BOOLEAN StartDecompress();
        void EndDecompress();
        BOOLEAN DecompressLine(UINT8 *line, UINT32 &line_len);
        BOOLEAN BufferedInput(UINT8 *next_byte);
        INT GetPrefixChar(INT lz_code, INT clear_code);
        INT DecompressInput(INT* lz_Code);

        UINT8 m_lzw_bytes_left;
        UINT8 m_bits_per_pixel;         /* Bits per pixel (Codes uses at least this + 1). */
        UINT8 m_code_size;
        INT16 m_clear_code;             /* The CLEAR LZ code. */
        INT16 m_eof_code;               /* The EOF LZ code. */
        INT16 m_running_code;           /* The next code algorithm can generate. */
        INT16 m_running_bits;           /* The number of bits required to represent RunningCode. */
        INT16 m_max_code1;              /* 1 bigger than max. possible code, in RunningBits bits. */
        INT16 m_last_code;              /* The code before the current code. */
        INT m_crnt_code;                /* Current algorithm code. */
        INT m_stack_ptr;                /* For character stack (see below). */
        INT m_crnt_shift_state;         /* Number of bits in CrntShiftDWord. */
        UINT32 m_crnt_shift_dword;      /* For bytes decomposition into codes. */
        
        INT m_bytes_in_buffer;
        UINT32 m_abs_offset;
        UINT8* m_next_input_byte;
        UINT8 m_input_buffer[INPUT_BUFFER_SIZE];

        UINT8* m_buf;
        UINT8* m_stack;
        UINT8* m_suffix;
        UINT16* m_prefix;
};


#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //Apoxi_GifDecoder_hpp


