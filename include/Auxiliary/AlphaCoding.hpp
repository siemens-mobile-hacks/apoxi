/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_AlphaCoding_hpp)
#define Adc_AlphaCoding_hpp

#include <Auxiliary/WString.hpp>



class AlphaCoding
{
    public:
        AlphaCoding();
        ~AlphaCoding(); // destructor not virtual !!!

        static void EnableUsagePureUcs2Encoding(BOOLEAN enable = TRUE);

        static INT GetCodedAlphaFieldLen(const WString & wstr);

        static BOOLEAN EncodeAlphaField(const WString & str, UINT8 * buffer, INT len);
        static BOOLEAN EncodeAlphaField(const WString & str, UINT8 * buffer, INT len,
                                        INT & strlen, INT & efflen);

        static WString DecodeAlphaField(const UINT8 * buffer, const INT len, const INT prealloclen = 0);

    private:

        static BOOLEAN Encode7bit(const WString & wstr, UINT8 * buffer, INT len);

        static BOOLEAN EncodeUcs80(const WString & wstr, UINT8 * buffer, INT len);

        static BOOLEAN EncodeUcs81(const WString & wstr, UINT8 * buffer, INT len, UINT8 offset);

        static BOOLEAN EncodeUcs82(const WString & wstr, UINT8 * buffer, INT len, WCHAR offset);

        static INT Get7BitLen(const WString & wstr);

        static INT GetUcs80Len(const WString & wstr);

        static INT GetUcs81Len(const WString & wstr, UINT8 & offset);

        static INT GetUcs82Len(const WString & wstr, WCHAR & offset);

        static void FindHighAndLow(const WString & wstr, WCHAR & lowest, WCHAR & highest);

        static WString Decode7bit(const UINT8 * buffer, const INT len, const INT prealloclen);

        static WString DecodeUcs80(const UINT8 * buffer, const INT len, const INT prealloclen);

        static WString DecodeUcs81(const UINT8 * buffer, const INT prealloclen);

        static WString DecodeUcs82(const UINT8 * buffer, const INT prealloclen);

    private:
        static WCHAR * m_wchar_buffer;
        static INT     m_buffer_len;
        static BOOLEAN m_pure_ucs2_encoding;
        
        static void ResizeWCharBuffer(INT size);

};


#endif


