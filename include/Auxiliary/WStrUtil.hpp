/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(_APOXI_WStrutil_h)
#define _APOXI_WStrutil_h

#include <Kernel/Types.hpp>
#include <Auxiliary/Latin.hpp>
#include <Auxiliary/StrUtil.hpp>
#include <Auxiliary/WCattr.hpp>

UINT    WStrLen(const WCHAR *s);
WCHAR * WStrCpy(WCHAR *dest, const WCHAR *src);
WCHAR * WStrnCpy(WCHAR *dest, const WCHAR *src, UINT maxlen);
INT     WStrCmp(const WCHAR *s1, const WCHAR *s2);
INT     WXStrCmp(const WCHAR *s1, const WCHAR *s2, BOOLEAN ignore_case = TRUE, BOOLEAN locale_sensitive = TRUE);
INT     WStrnCmp(const WCHAR *s1, const WCHAR *s2, UINT maxlen);
WCHAR * WStrCat(WCHAR *dest, const WCHAR *src);
WCHAR * WStrnCat(WCHAR *dest, const WCHAR *src, UINT maxlen);
CHAR *  WStrToStr(CHAR *dest, const WCHAR *src);
WCHAR * StrToWStr(WCHAR *dest, const CHAR *src);
INT     WStrPrintD(WCHAR *dest, INT value);

INT     WStrPrintf(WCHAR *s, INT maxStrChars, const WCHAR *format, ...);
INT     WStrPrintf(WCHAR *s, const WCHAR *format, ...);
void    wstrprintf(WCHAR *buffer, INT maxBufChars, const WCHAR *format, va_list args, ...);
void    wstrprintf(WCHAR *buffer, const WCHAR *format, va_list args, ...);

INT     WStrScanf(const WCHAR *s, const WCHAR * format, ...);
INT     wstrscanf(const WCHAR* str, const WCHAR * format, va_list args, ...);

WCHAR   WCharToLower(WCHAR wc);
WCHAR   WCharToUpper(WCHAR wc);

WCHAR*  WCharStrToLower(WCHAR *wc);
WCHAR*  WCharStrToUpper(WCHAR *wc);

UINT    WStrChr(const WCHAR* s, UINT size, const WCHAR c);
UINT    WStrrChr(const WCHAR* send, UINT size, const WCHAR c);
UINT    WStrStr(const WCHAR* s1, UINT size, const WCHAR* s2);
UINT    WStrStrn(const WCHAR* s1, UINT size, const WCHAR* s2, UINT s2size);
UINT    WStrrStr(const WCHAR* s1end, UINT size, const WCHAR* s2);
UINT    WStrrStrn(const WCHAR* s1end, UINT size, const WCHAR* s2, UINT s2size);

INT     WStrToInt(const WCHAR *s);
INT32   WStrToInt32(const WCHAR *s);
WCHAR * IntToWStr(INT value, WCHAR *s);
WCHAR * Int32ToWStr(INT32 value, WCHAR *s);
WCHAR * UIntToWStr(UINT value, WCHAR *s);
WCHAR * UInt32ToWStr(UINT32 value, WCHAR *s);
WCHAR * HexToWStr(UINT8 value, WCHAR *s);

INT     IsWwhiteSpace(WCHAR c);
INT     IsWsign(WCHAR c);
INT     IsWplusSign(WCHAR c);
INT     IsWminusSign(WCHAR c);
INT     IsWdDigit(WCHAR c);
INT     IsWxDigit(WCHAR c);
INT     IsWbDigit(WCHAR c);
INT     IsWoDigit(WCHAR c);
INT     WdDigitValue(WCHAR c);
INT     WxDigitValue(WCHAR c);
INT     WbDigitValue(WCHAR c);
INT     WoDigitValue(WCHAR c);
WCHAR   WminusSign(void);
WCHAR   WxDigit(INT digit,INT xstyle);


#endif  // _APOXI_WStrutil_h


