/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(_APOXI_String_hpp)
#define _APOXI_String_hpp

#include <stdarg.h>               // Variable argument list.
#include <Kernel/Types.hpp>       // Standard types
#include <Kernel/Os/OsStrLib.hpp>   // string includes
#include <Auxiliary/StrUtil.hpp>  // String utility methods

class WString;  // Necessary forward declaration


struct StrData {
    UINT8 m_refcount;
    UINT8 m_len;
    UINT16 m_bufsize;
    static CHAR *m_null_str;
    static StrData *m_null_strbuf;

    void* operator new(UINT s_strbuf, UINT char_count);

    void operator delete(void *p);

    const CHAR* ToPtr() const { return (const CHAR*) (this + 1); }

    CHAR* ToPtr() { return (CHAR*) (this + 1); }

    UINT GetLength() const;

    void ResetRefCount();

    void SetLength(UINT n);

    void SetBufSize(UINT n);

    UINT GetBufSize() const { return m_bufsize; }

    BOOLEAN HasMultipleRefs() const { return m_refcount > 0; }

    BOOLEAN IncRefCount();

    void DecRefCount();

    BOOLEAN IsNullStr() const { return this == m_null_strbuf; }

    static CHAR* GetNullStr() { return m_null_str; }

    static StrData* FromPtr(CHAR *str) { return ((StrData *) str) - 1; }
};


const INT string_max_buffer_size = 256;


class String
{
    friend class WString;

    public:
        String();

        String(const CHAR * pchCopy);

        String(const CHAR * pchCopy, UINT len);

        String(const String & szCopy);

        String(const String * szCopy);

        String(INT32 val);

        String(CHAR singlechar);

        ~String();

        const CHAR * GetCString() const  { return m_strdata; }

        const UINT8 * GetData() const  { return (UINT8*) m_strdata; }

        BOOLEAN Reserve(UINT nchars) { return Modify(nchars + 1, TRUE); }

        BOOLEAN PreAlloc(UINT nchars) { return Modify(nchars + 1, FALSE); }

        BOOLEAN IsEmpty() const { return *m_strdata == 0; }

        INT GetMemSize() const;

        INT GetLength() const;

        INT GetSize() const;

        String Substring(INT nStart, INT nLength = -1) const;

        INT IndexOf(CHAR character, INT frompos = 0) const;

        INT IndexOf(const String & searchstr, INT frompos = 0) const {
            return Find(searchstr.GetCString(), frompos, searchstr.GetLength());
        }

        INT IndexOf(const CHAR * searchstr, INT frompos = 0) const {
            return Find(searchstr, frompos, strlen(searchstr));
        }

        INT LastIndexOf(CHAR character, INT frompos = -1) const;

        BOOLEAN StartsWith(const String & other) const;

        BOOLEAN EndsWith(const String & other) const;

        void StrCopy(const CHAR * buffer, INT len);

        WString ToWString() const;

        WString FromUtf8ToWString() const;

        String& ToUpper();

        String& ToLower();

        void Swap(String & swapstr);

        void Clear();

        void Erase(INT frompos);

        void Erase(INT from, INT nchars);

        void Replace(INT pos, CHAR ch);

        void Insert(INT pos, CHAR character);

        void Insert(INT pos, const String & szInsert);

        INT CompareTo(const String & szOther) const { return strcmp(m_strdata, szOther.GetCString()); };

        INT CompareTo(const String & szOther, INT startpos, INT count = -1) const { return CompareTo(szOther.GetCString(), startpos, count); };

        INT CompareTo(const CHAR * szOther) const { return strcmp(m_strdata, szOther); };

        INT CompareTo(const CHAR * szOther, INT startpos, INT count = -1) const;

        static INT Compare(const String &s1, const String &s2) { return strcmp(s1.GetCString(), s2.GetCString()); }

        void Format(const CHAR * format, ...);

        void VFormat(const CHAR * format, va_list args);

        void Scan(const CHAR * format, ...) const;

        BOOLEAN IsNumeric(INT number = -1) const { return IsNumeric(m_strdata, number); }

        static BOOLEAN IsNumeric(const CHAR * string, INT number = -1);

        operator const CHAR * () const  { return m_strdata; }

        CHAR operator [] (INT nPos) const;

        String & operator = (const String & szCopy);

        String & operator = (const CHAR * pchCopy);

        String operator + (const String & szConcat) const;

        String operator + (const CHAR * pchConcat) const;

        void operator += (const String & szConcat) { *this << szConcat; }

        void operator += (const WString & szConcat) { *this << szConcat; }

        void operator += (const CHAR * pchConcat) { *this << pchConcat; }

        void operator += (const WCHAR * pchConcat) { *this << pchConcat; }

        String & operator << (const String & right);

        String & operator << (const String * right);

        String & operator << (const WString & right);

        String & operator << (const WString * right);

        String & operator << (const CHAR * right);

        String & operator << (const WCHAR * right);

        String & operator << (INT32 number);

        BOOLEAN operator == (const String & szcompare) const { return CompareTo(szcompare) == 0; }

        BOOLEAN operator == (const CHAR * szcompare) const { return CompareTo(szcompare) == 0; }

        BOOLEAN operator != (const String & szcompare) const { return CompareTo(szcompare) != 0; }

        BOOLEAN operator < (const String & right) const { return strcmp(GetCString(), right.GetCString()) < 0; }

        BOOLEAN operator <= (const String & right) const { return strcmp(GetCString(), right.GetCString()) <= 0; }

        BOOLEAN operator > (const String & right) const { return strcmp(GetCString(), right.GetCString()) > 0; }

        BOOLEAN operator >= (const String & right) const {
            return strcmp(GetCString(), right.GetCString()) >= 0; }

#if defined(APOXI_ENABLE_OBSOLETE_STRING_INTERFACE)

        // Obsolete methods - should not be used anymore

        const CHAR* c_str() const;

        const UINT8* data() const;

        BOOLEAN empty() const;

        INT memsize() const;

        INT length() const;

        INT size() const;

        WString getwstring() const;

        String substr(INT nStart, INT nLength = -1) const;

        INT find(CHAR character, INT frompos = 0) const;

        INT find(const String & searchstr, INT frompos = 0) const;

        INT reverse_find(CHAR character, INT frompos = -1) const;

        INT compare(const String & szOther) const;

        INT compare(const String & szOther, INT startpos, INT count = -1) const;

        INT compare(const CHAR * szOther) const;

        INT compare(const CHAR * szOther, INT startpos, INT count = -1) const;

        BOOLEAN startswith(const String & other) const;

        BOOLEAN endswith(const String & other) const;

        void strcopy(const CHAR * buffer, INT len);

        String& toupper();

        String& tolower();

        void swap(String & swapstr);

        void clear();

        void erase(INT frompos);

        void insert(INT pos, CHAR character);

        void insert(INT pos, const String & szInsert);

        void format(const CHAR * format,...);

        void vformat(const CHAR * format, va_list args);

        BOOLEAN HasOnlyDigits(INT number = -1) const;

        static BOOLEAN HasOnlyDigits(const CHAR * string, INT number = -1);

#endif // APOXI_ENABLE_OBSOLETE_STRING_INTERFACE

    private:
        CHAR *m_strdata;

        BOOLEAN Allocate(UINT nchars);
        BOOLEAN Modify(UINT new_nchars, BOOLEAN preserve_content = TRUE);
        BOOLEAN AttachTo(StrData *sd);
        void DetachFrom(StrData *sd) const;

        StrData* GetStrData() const { return StrData::FromPtr(m_strdata); }

        INT Find(const CHAR * searchstr, INT frompos, INT searchlen) const;
        BOOLEAN ConCat(const CHAR * cc_str, UINT cc_len);
        BOOLEAN ConCat(const WCHAR * cc_str, UINT cc_len);

        static CHAR m_formatbuffer[string_max_buffer_size+1];
};

#if !defined(APOXI_STRING_TEST_SUITE) && defined(APOXI_RTOS_WIN32)
#define APOXI_STRING_TEST_SUITE

// Call for String test suite, only for WIN32 platform
extern void StringTest();

#endif

#endif

