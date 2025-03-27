/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_Unicode_hpp)
#define Auxiliary_Unicode_hpp


/*
  =============================================================================
  APOXI Library for UNICODE to/from UTF8 conversion.
  =============================================================================
  UnicodeNextUtf8      Searches the beginning of the next UTF-8 character
                       in the UTF-8 string.

  UnicodePreviousUtf8  Searches the beginning of the previous UTF-8 character
                       in the UTF-8 string

  UnicodeUtf8Strlen    Calculates the length of the UTF-8 string with limited
                       length.

  UnicodeLastUtf8      Searches for the last UTF-8 character in UTF-8 string.
  UnicodeGetUtf8       Fetch the next UTF-8 character from P into result and
                       convert it into the UNICODE value.
  UnicodePutUtf8       Convert a single UNICODE character to UTF-8 character
                       and send it to UTF-8 output buffer.
  UnicodeUtf8Strchr    Finds the first occurrence of the UNICODE character in
                       the UTF-8 string.
  UnicodeOffsetToIndex Searches for beginning of offset of UTF-8 character in
                       UTF-8 string and returns its offset in bytes.
  UnicodeIndexToOffset Searches for number of UTF-8 characters in UTF-8
                       string in first offset bytes.

  UnicodeToUtf8        Convert UNICODE string to UTF-8 string and return length
                       counted including terminating null-character.
  Utf8ToUnicode        Convert UTF-8 string to UNICODE string and return length
                       counted including terminating null-character.
  
  UnicodeFromUtf8      Convert UTF-8 string to UNICODE string and return length
                       counted excluding terminating null-character.
  Utf8FromUnicode      Convert UNICODE string to UTF-8 string and return length
                       counted excluding terminating null-character.

  UnicodeUtf8Validate  Validates UTF-8 encoded text.

  UnicodeStrlen        Find length of UNICODE string.
  UnicodeStringWidth   Same as UnicodeStrlen.
  UnicodeStrncpy       Copies a given number of bytes from one string into
                       another.
  UnicodeStrcmp        Compares a portion of one UNICODE string to a portion
                       of another with case sensitivity.
  UnicodeStrncmp       Compares a portion of one UNICODE string to a portion
                       of another with case sensitivity.
  UnicodeStrstr        Scans UNICODE string for the occurrence of a given

  
  Common warning:

  The caller and his/her C/C++ compiler are responsible for proper arguments
  boundary on the stack by calling some function; on some systems (depending on
  target processor), access to an element bigger than a byte (short, integer, long,
  etc.) and located on an odd address, can cause address error exception (or even
  something worse).

  =============================================================================
*/

#include  <Kernel/Types.hpp>
#include  <Auxiliary/StrUtil.hpp>

#define APOXI_UNICODE_EOF (WCHAR)0xffff

/*
      UnicodeToUtf8
Description:
        Scans UNICODE string buffer and converts UNICODE characters into UTF-8
        characters and copies UTF-8 characters to destination buffer.
        Destination buffer must have enough space available.
Arguments:
          utf8      Pointer to destination memory buffer receiving converted UNICODE.
                    If this pointer is 0 (NULL), no conversion will be done but the
                    number of UTF-8 characters needed for conversion is returned
                    (including null-terminator).
          unicode   Pointer to a memory buffer holding text in UNICODE data format,
                    must be null-terminated.
Returns:
        The number of UTF-8 characters generated (including null-terminator).
Notes:
        Be aware that the generated UNICODE string will be null-terminated. The 
        difference to the function "Utf8FromUnicode" is therefore just the counting
        of the length, the string conversion and generation is the same.
*/
INT UnicodeToUtf8(CHAR *utf8, const WCHAR *unicode);


/*
      Utf8ToUnicode
Description:
        Scans UTF-8 string buffer and converts UTF-8 characters into UNICODE
        characters and copies UNICODE characters to destination buffer.
        Destination buffer must have enough space available.
Arguments:
          unicode   Pointer to destination memory buffer receiving converted UTF-8.
                    If this pointer is 0 (NULL), no conversion will be done but the
                    number of UNICODE characters needed for conversion is returned
                    (including null-terminator).
          utf8      Pointer to a memory buffer holding text in UTF-8 data format,
                    must be null-terminated.
Returns:
        The number of UNICODE characters generated (including null-terminator).
Notes:
        Be aware that the generated UTF-8 string will be null-terminated. The 
        difference to the function "UnicodeFromUtf8" is therefore just the counting
        of the length, the string conversion and generation is the same.
*/
INT Utf8ToUnicode(WCHAR *unicode, const CHAR *utf8);


/*
      UnicodeFromUtf8
Description:
        Scans UTF-8 string buffer and converts UTF-8 characters into UNICODE
        characters and copies UNICODE characters to destination buffer.
        Destination buffer must have enough space available.
Arguments:
          unicode   Pointer to destination memory buffer receiving converted UTF-8.
                    If this pointer is 0 (NULL), no conversion will be done but the
                    number of UNICODE characters needed for conversion is returned
                    (excluding null-terminator).
          utf8      Pointer to a memory buffer holding text in UTF-8 data format,
                    must be null-terminated.
Returns:
        The number of UNICODE characters generated (excluding null-terminator).
Notes:
        Be aware that the generated UNICODE string will be null-terminated. The 
        difference to the function "Utf8ToUnicode" is therefore just the counting
        of the length, the string conversion and generation is the same.
*/
INT UnicodeFromUtf8(WCHAR *unicode, const CHAR *utf8);


/*
      Utf8FromUnicode
Description:
        Scans UNICODE string buffer and converts UNICODE characters into UTF-8
        characters and copies UTF-8 characters to destination buffer.
        Destination buffer must have enough space available.
Arguments:
          utf8      Pointer to destination memory buffer receiving converted UNICODE.
                    If this pointer is 0 (NULL), no conversion will be done but the
                    number of UTF-8 characters needed for conversion is returned
                    (excluding null-terminator).
          unicode   Pointer to a memory buffer holding text in UNICODE data format,
                    must be null-terminated.
Returns:
        The number of UTF-8 characters generated (excluding null-terminator).
Notes:
        Be aware that the generated UTF-8 string will be null-terminated. The 
        difference to the function "UnicodeToUtf8" is therefore just the counting
        of the length, the string conversion and generation is the same.
*/
INT Utf8FromUnicode(CHAR *utf8, const WCHAR *unicode);


/*
      UnicodeUtf8Validate
Description:
        Validates UTF-8 encoded text. str is the text to validate. If str is
        null-terminated, then max_len can be -1, otherwise max_len should be
        the number of bytes to validate. If end is non-NULL, then the end of
        the valid range will be stored there (i.e. the address of the first
        invalid byte if some bytes were invalid, or the end of the text being
        validated otherwise).
        Many routines valid UTF8 as input. So data read from a file or the
        network should be checked with this function before doing
        anything else with it.
Arguments:
          str     a pointer to character data
        max_len max bytes to validate, or -1 to go until null
        end     return location for end of valid data
Returns:
        TRUE if the text was valid UTF-8, otherwise FALSE.
*/
INT UnicodeUtf8Validate(const CHAR *str, INT max_len, const CHAR **end);


/*
      UnicodePreviousUtf8
Description:
        Searches the beginning of the previous UTF-8 character in the UTF-8
        string.
Arguments:
          start     pointer to the beginning of the UTF-8 string.
          p         pointer insidee the UTF-8 string.
Returns:
        Pointer to the beginning of the UTF-8 character
        If P points to the middle of an UTF-8 character, this function
        returns a pointer to the first byte of the character.
        If P points to the start of an UTF-8 character, this function returns a
        pointer to the first byte of the previous character.
        If P does not point to an UTF-8 character, NULL is returned.
        START bounds the search, in no case will a value before START be
        returned.
        If p does not point inside UTF-8 string the result is false
*/
CHAR *UnicodePreviousUtf8 (const CHAR *start, const CHAR *p);


/*
    UnicodeNextUtf8
Description:
        Searches the beginning of the next UTF-8 character in the UTF-8 string.
Arguments:
          p         pointer inside the UTF-8 string.
Returns:
        Returns pointer to the next UTF-8 character in the string of the UTF-8
        characters
        Return pointer to the first byte of the next UTF-8 character after P.
        This works whether P points to the start or to the middle of an UTF-8
        character.
        P is assumed to be null-terminated.
        If p does not point inside the UTF-8 string, the result is false
*/
CHAR *UnicodeNextUtf8 (const CHAR *p);


/*
    UnicodeUtf8Strlen
Description:
        Calculates the length of the UTF-8 string with limited length
Arguments:
          p         pointer to a valid UTF-8 character.
          max       limited number of characters for the search function.
Returns:
        Return the length, in characters, of p, an UTF-8 string.  Max is the
        maximum number of bytes to examine.  If max is less than 0, then P is
        assumed to be null-terminated.
*/
UINT  UnicodeUtf8Strlen (const CHAR *p, INT max);


/*
      UnicodeStrlen
Description:
        Find length of UNICODE string.
Arguments:
        unicode pointer to the start of an UTF-8 string.
        max     the maximum number of WCHAR objects to examine.
Returns:
        Function returns length of an UNICODE string in  WCHAR characters
*/
UINT  UnicodeStrlen(const WCHAR *unicode, INT max);


/*
    UnicodeStringWidth
Description:
        Calculates the length of the UTF-8 string with no length limitation
Arguments:
          p         pointer to a valid UTF-8 character.
Returns:
        Return the length, in characters, of p, an UTF-8 string.  Max is the
        maximum number of bytes to examine.  If max is less than 0, then P is
        assumed to be null-terminated.
        Returns the visual width, in character-size units, of P, a string. This
        value may be used for tabulation.
*/
UINT  UnicodeStringWidth(const CHAR *p);


/*
    UnicodeGetUtf8
Description:
        Fetch the next UTF-8 character from P into result and convert it into
        the UNICODE value.
Arguments:
          p         pointer to the valid UTF-8 character.
          result    pointer to the location into which the UNICODE value of the
                  UTF-8 character returns.
Returns:
        If the next character is a valid UTF-8 character, rasult holds UNICODE
        value of UTF-8 character. If the character is not valid, result holds -1.
        The function returns a pointer to the start of the next UTF-8 character.
        If p is not well formed, it will return NULL.
*/
CHAR *UnicodeGetUtf8(const CHAR *p, WCHAR *result);


/*
    UnicodePutUtf8
Description:
        Convert a single UNICODE CHAR to UTF-8 CHAR and send it to UTF-8 output
        buffer.
Arguments:
          c         ISO10646 character code.
          outbuf    output buffer must have at least 6 bytes of space. If %NULL,
                  the length will be computed and returned and nothing will be
                  written to @out.
Returns:
        number of bytes written
*/
INT UnicodePutUtf8(WCHAR c, CHAR *outbuf);


/*
    UnicodeOffsetToIndex
Description:
        Function searches for begining of offset of UTF-8 character in UTF-8
        string and returns its offset in bytes
Arguments:
          p         pointer to a valid UTF-8 string.
          offset    offset of UTF-8 character in UTF-8 string.
Returns:
        offset of UTF-8 character in UTF-8 string in bytes, if offset is within
        the range of UTF-8 string.
        If offset is biger then size of UTF-8 string in UTF-8 characters,
        function returns size of UTF-8 string in bytes
*/
INT UnicodeOffsetToIndex(const CHAR *src, INT offset);


/*
    UnicodeIndexToOffset
Description:
        Function searches for number of UTF-8 characters in UTF-8 string in
        first offset bytes.
Arguments:
          p         pointer to a valid UTF-8 character.
          offset    offset in UTF-8 string in bytes.
Returns:
        number of UTF-8 characters in first offset bytes.
              if offset is longer than UTF-8 string in bytes, function returns
              number of UTF-8 characters
*/
INT UnicodeIndexToOffset(const CHAR *src, INT  index);


/*
    UnicodeLastUtf8
Description:
        Searches for the last UTF-8 character in UTF-8 string
Arguments:
          p         pointer to a valid UTF-8 string
Returns
        Pointer to the last UTF-8 sequence in a string
        If the string is empty, it returns pointer to empty string
*/
CHAR *UnicodeLastUtf8(const CHAR *p);


/*
      UnicodeStrcmp
Description:
        Compares a portion of one string to a portion of another, with case
        sensitivity. Function performs a signed comparison of s1 to s2,
        starting with the first character in each string and continuing with
        subsequent characters until the corresponding characters differ .
        The comparison is case sensitive. It returns a value (< 0, 0, or > 0)
        based on the result of comparing s1 (or part of it) to s2 (or part of it).
Arguments:
          str1   pointer to first Unicode string.
          str2   pointer to second Unicode string.
Returns:
        If s1 is... returns a value that is...
        less than s2    < 0
        the same as s2  == 0
        greater than s2 > 0
*/
INT UnicodeStrcmp( const WCHAR *str1, const WCHAR *str2 );


/*
      UnicodeStrncmp
Description:
        Compares a portion of one string to a portion of another, with case
        sensitivity. Function performs a signed comparison of s1 to s2,
        for a maximum length of n bytes, starting with the first character in
        each string and continuing with subsequent characters until the
        corresponding characters differ or until n characters have been examined.
        The comparison is not case sensitive. It returns a value (< 0, 0, or > 0)
        based on the result of comparing s1 (or part of it) to s2 (or part of it).
Arguments:
          str1    pointer to first Unicode string.
          str2    pointer to second Unicode string.
Returns:
        If s1 is... returns a value that is...
        less than s2    < 0
        the same as s2  == 0
        greater than s2 > 0
*/
INT UnicodeStrncmp( const WCHAR *str1, const WCHAR *str2, INT n );


/*
      UnicodeStrstr
Description:
        Scans a string for the occurrence of a given substring. Function
        scans s1 for the first occurrence of the substring s2.
Arguments:
          str     pointer to first Unicode string.
          sub     pointer to Unicode substring.
Returns:
        return a pointer to the element in s1, where s2 begins
        (points to s2 in s1). If s2 does not occur in s1, strstr returns null.
*/
WCHAR *UnicodeStrstr( const WCHAR *str, const WCHAR *sub );


/*
      UnicodeStrncpy
Description:
        Copies a given number of bytes from one string into another, truncating
        or padding as necessary. Strncpy copies up to maxlen characters from src
        into dest, truncating or null-padding dest. The target string, dest,
        might not be null-terminated if the length of src is maxlen or more.
Arguments:
          dest      pointer to destination UTF-8 string
          src       pointer to source UTF-8 string
          n         maximum number of UTF-8 characters to copy
Returns:
        Value strncpy returns dest.
*/
CHAR  *UnicodeStrncpy(CHAR *dest, const CHAR *src, UINT n);


/*
      UnicodeUtf8Strchr
Description:
        Scans UNICODE character corresponding to ch, in string p.
        Function scans a string in forward direction, looking for a
        specific character. It finds the first occurrence of the
        unicode WCHAR c in the UTF-8 string s. The null-terminator is considered
        to be part of the string.
Arguments:
          p         pointer to destination UNICODE string
          ch        value of UNICODE character
Returns:
        pointer to the first occurrence of the character c in s. If c does not
        occur in s, function returns null.
*/
CHAR *UnicodeUtf8Strchr(const CHAR *p, WCHAR c);


#define UTF8_COMPUTE(Char, Mask, Len)                                         \
  if (Char < 128)       { Len = 1;  Mask = 0x7f; }                            \
  else if ((Char & 0xe0) == 0xc0)                                             \
    { Len = 2; Mask = 0x1f; }                                                 \
  else if ((Char & 0xf0) == 0xe0)                                             \
    { Len = 3; Mask = 0x0f; }                                                 \
  else if ((Char & 0xf8) == 0xf0)                                             \
    { Len = 4; Mask = 0x07; }                                                 \
  else if ((Char & 0xfc) == 0xf8)                                             \
    { Len = 5; Mask = 0x03; }                                                 \
  else if ((Char & 0xfe) == 0xfc)                                             \
    { Len = 6; Mask = 0x01; }                                                 \
  else                                                                        \
    Len = -1;

#define UTF8_GET(Result, Chars, Count, Mask, Len)                             \
  (Result) = (Chars)[0] & (Mask);                                             \
  for ((Count) = 1; (Count) < (Len); ++(Count))                               \
    {                                                                         \
      if (((Chars)[(Count)] & 0xc0) != 0x80)                                  \
        {                                                                     \
          (Result) = -1;                                                      \
          break;                                                              \
    }                                                                     \
      (Result) <<= 6;                                                         \
      (Result) |= ((Chars)[(Count)] & 0x3f);                                  \
}


#endif // Auxiliary_Unicode_hpp

