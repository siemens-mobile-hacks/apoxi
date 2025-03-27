/*  ------------------------------------------------------------------------
    Copyright (C) 2002 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SwitchedRleCompression_hpp)
#define Apoxi_SwitchedRleCompression_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BinData.hpp>

class SwitchedRleCompression {
    public:
        class Context {
            public:
                Context();

                ~Context(); // not virtual
                
            private:
                friend class SwitchedRleCompression;
                
                void SetData (const BinData* data) { m_data = data; }

                const BinData* GetData() { return m_data; }

                void SetOffset(UINT32 offset) { m_offset = offset; }

                UINT32 GetOffset() { return m_offset; }

            

                enum {
                    mode_lit, 
                    mode_fill
                } m_mode;
                BOOLEAN     m_continue;     // determines wheater to continue in last mode (more than 255 same bytes) or not

                union {
                    UINT8  m_lastlit8;
                    UINT16 m_lastlit16;
                };
                
                UINT8       m_ch;           // character that has been read (compression)
                UINT8       m_buff[256]; 
                UINT8       *m_buff_p;      // buffer for compression and pointer to actual position    (compression)
                INT         m_prev;         // last character - used for comparison (compression)
                INT         m_pcount;       // count of same characters (compression)
                UINT        m_bindex;       // buffer index (compression)
                UINT        m_bytes_left;   // bytes left that must be written in next run (compression)            

                UINT        m_lit_bytes;    // how many lit bytes are left  (decompression)
                UINT        m_fill_bytes;   // how many fill bytes are left (decompression)
                const BinData* m_data;
                UINT32      m_offset;
                UINT32      m_idx;              
        };

        static BOOLEAN InitContext(const BinData* src, UINT32 offset, Context& context);

        static BOOLEAN DecompressBlock(const Context& context, UINT8 *dest, UINT32& block_size);

        static BOOLEAN CompressBlock(const Context& context, UINT8 *dest, UINT32& block_size);
    
    private:

        static UINT16 ReadUINT16(UINT8* src, UINT32 idx);
                
        static UINT8  ReadUINT8(UINT8* src, UINT32 idx);

        SwitchedRleCompression();
        ~SwitchedRleCompression();  
};      

#endif //Apoxi_SwitchedRleCompression_hpp


