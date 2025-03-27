/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apc_DataCoding_hpp)
#define Apc_DataCoding_hpp



#include <Kernel/Types.hpp>


#define GsmInternalCodingAt 0x81 // representation of "@" in GsmInternalCoding

class DataCoding
{
    public:
        DataCoding();
        ~DataCoding(); // destructor not virtual !!!


        static BOOLEAN UnpackSeptetsToWchars(const UINT8 * in7bitbuffer, INT nofwcharchrs, WCHAR * outbuffer, UINT8 step = 0);

        static BOOLEAN UnpackCbsSeptetsToWchars(const UINT8 * in7bitbuffer, INT nofbytes, WCHAR * outbuffer, BOOLEAN haslengthbyte = FALSE);

        static INT GetWchars(INT nofbytes, const UINT8 * buffer, BOOLEAN checkeos = FALSE);

        static INT GetCbsWchars(INT nofbytes, const UINT8 * buffer, BOOLEAN haslengthbyte = FALSE);

        static INT GetEffectiveWchars(INT nofseptets, const UINT8 * buffer, UINT8 step = 0);

        static INT PackWcharsToSeptets(const WCHAR * inbuffer, INT nofwcharchrs, UINT8 * outbuffer, UINT8 step = 0);
        static INT PackWcharsToSeptets(const WCHAR * inbuffer, INT nofwcharchrs, UINT8 * outbuffer, INT size_of_outbuffer, UINT8 step);

        static INT GetSeptets(INT nofwcharchrs, const WCHAR * string);

        static INT GetBufferLength(INT nofwcharchrs, const WCHAR * string);

        static INT GetUnicodeStringToGsm7DefaultStringLength(const WCHAR * src, INT len);

        static void UnicodeStringToGsm7DefaultString(const WCHAR * src, CHAR * dest, INT len);

        static void Gsm7DefaultStringToUnicodeString(const CHAR * src, WCHAR * dest, INT len);

        static INT MoveUnicodeBufferAndAdjustBytes(const UINT8 * src, UINT8 * dest, INT bufferlen);

        static INT CopyCbsUnicodeBufferAndAdjustBytes(const UINT8 * src, UINT8 * dest, INT bufferlen, BOOLEAN haslengthbyte = FALSE);

        static BOOLEAN IsWCharToGsm7Possible(WCHAR src);

        static BOOLEAN HasOnly7bitChars(const WCHAR * string);

        static BOOLEAN ForceWcharsTo7bitWchars(const WCHAR * source, WCHAR * dest, INT len);

    private:

        static INT FindTerminatingCRSequence(const WCHAR * buffer, INT bufferlen);

        static WCHAR Gsm7DefaultExtendedToUnicode(UINT8 src);
        static WCHAR Gsm7DefaultToUnicode(UINT8 src);
        
        static UINT8 UnicodeToGsm7DefaultNormal(WCHAR src);
        static UINT8 UnicodeToGsm7DefaultExtended(WCHAR src);
        static UINT8 UnicodeToGsm7Default(WCHAR src, BOOLEAN & shallexpand);


};


#endif


