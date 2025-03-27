/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(_APOXI_WString_hpp)
#define _APOXI_WString_hpp

#include <stdarg.h>                 // Variable argument list
#include <Kernel/Types.hpp>         // Standard types
#include <Auxiliary/WStrUtil.hpp>   // WString utility methods
#include <Auxiliary/String.hpp>     // String

struct WStrData {
    UINT8 m_refcount;
    UINT8 m_len;
    UINT16 m_bufsize;
    static WCHAR *m_null_str;
    static WStrData *m_null_strbuf;

    void* operator new(UINT s, UINT wchar_count);

    void operator delete(void *p);

    const WCHAR* ToPtr() const { return (const WCHAR*) (this + 1); }

    WCHAR* ToPtr() { return (WCHAR*) (this + 1); }

    UINT GetLength() const;

    void ResetRefCount();

    void SetLength(UINT n);

    void SetBufSize(UINT n);

    UINT GetBufSize() const { return m_bufsize; }

    BOOLEAN HasMultipleRefs() const { return m_refcount > 0; }

    BOOLEAN IncRefCount();

    void DecRefCount();

    BOOLEAN IsNullStr() const { return this == m_null_strbuf; }

    static WCHAR* GetNullStr() { return m_null_str; }

    static WStrData* FromPtr(WCHAR *str) { return ((WStrData *) str) - 1; }
};


const INT wstring_max_buffer_size = 256;


class WString {

    friend class String;

    public:
        WString();

        WString(const WCHAR* str);

        WString(const WCHAR* str, UINT len);

        WString(const UINT8* str, UINT len);

        WString(const WString& str);

        WString(const WString* str);

        WString(const CHAR* str);

        WString(const String& str);

        WString(INT32 val);

        WString(WCHAR ch);

        ~WString();

        const WCHAR * GetCString() const { return m_strdata; }      

        const UINT8 * GetData() const  { return (UINT8*) m_strdata; }

        BOOLEAN Reserve(UINT char_count) { return Modify(char_count + 1, TRUE); }

        BOOLEAN PreAlloc(UINT char_count) { return Modify(char_count + 1, FALSE); }

        BOOLEAN IsEmpty() const { return *m_strdata == 0; }

        INT GetMemSize() const;

        INT GetLength() const;

        INT GetSize() const;

        WString Substring(INT start, INT length = -1) const;

        INT IndexOf(WCHAR ch, INT from = 0) const;

        INT IndexOf(const WString& str, INT from = 0) const {
            return Find(str.GetCString(), from, str.GetLength());
        }

        INT IndexOf(const WCHAR* str, INT from = 0) const {
            return Find(str, from, WStrLen(str));
        }

        INT LastIndexOf(WCHAR ch, INT from = -1) const;

        BOOLEAN StartsWith(const WString& other) const;
        
        BOOLEAN StartsWith(WCHAR chr) const;

        BOOLEAN EndsWith(const WString& other) const;

        BOOLEAN EndsWith(WCHAR chr) const;

        void StrCopy(const WCHAR* buffer, INT len);

        String ToString() const;

        String ToUtf8String() const;

        WString& ToUpper();

        WString& ToLower();

        void Swap(WString & str);

        void Clear();

        void Erase(INT from);

        void Erase(INT from, INT char_count);

        void Replace(INT pos, WCHAR ch);

        void Insert(INT pos, WCHAR ch);

        void Insert(INT pos, const WString & str);

        INT CompareTo(const WString& other_str,
                      BOOLEAN ignore_case = TRUE,
                      BOOLEAN locale_sensitive = TRUE) const
        {
            return WXStrCmp(m_strdata, other_str.GetCString(), ignore_case, locale_sensitive);
        }

        INT CompareTo(const WCHAR* other_str,
                      BOOLEAN ignore_case = TRUE,
                      BOOLEAN locale_sensitive = TRUE) const
        {
            return WXStrCmp(m_strdata, other_str, ignore_case, locale_sensitive);
        }

        static INT Compare(const WString& s1,
                           const WString& s2,
                           BOOLEAN ignore_case = TRUE,
                           BOOLEAN locale_sensitive = TRUE)
        {
            return WXStrCmp(s1.GetCString(), s2.GetCString(), ignore_case, locale_sensitive);
        }

        void Format(const WCHAR* format,...);

        void VFormat(const WCHAR* format, va_list args);

        void Scan(const WCHAR* format,...) const;

        BOOLEAN IsNumeric(INT number = -1) const { return IsNumeric(GetCString(), number); }

        static BOOLEAN IsNumeric(const WCHAR* string, INT number = -1);

        operator const WCHAR* () const  { return m_strdata; }

        WCHAR operator [] (INT pos) const;

        WString& operator = (const WString & str);

        WString& operator = (const WCHAR *str);

        WString operator + (const WString & str) const;

        WString operator + (const WCHAR * str) const;

        void operator += (const String & str) { *this << str; }

        void operator += (const WString & str) { *this << str; }

        void operator += (const CHAR * str) { *this << str; }

        void operator += (const WCHAR * str) { *this << str; }

        WString& operator << (const String & right);

        WString& operator << (const String * right);

        WString& operator << (const WString & right);

        WString& operator << (const WString * right);

        WString& operator << (const CHAR * right);

        WString& operator << (const WCHAR * right);

        WString& operator << (INT32 number);

        BOOLEAN operator == (const WString & str) const { return CompareTo(str) == 0; }

        BOOLEAN operator == (const WCHAR * str) const { return CompareTo(str) == 0; }

        BOOLEAN operator != (const WString & str) const { return CompareTo(str) != 0; }

        BOOLEAN operator < (const WString & right) const { return CompareTo(right) < 0; }

        BOOLEAN operator <= (const WString & right) const { return CompareTo(right) <= 0; }

        BOOLEAN operator > (const WString & right) const { return CompareTo(right) > 0; }

        BOOLEAN operator >= (const WString & right) const { return CompareTo(right) >= 0; }

#if defined(APOXI_ENABLE_OBSOLETE_WSTRING_INTERFACE)

        // Obsolete methods - should not be used anymore

        const WCHAR* c_str() const;

        const UINT8* data() const;

        BOOLEAN reserve(UINT char_count);

        BOOLEAN prealloc(UINT char_count);

        BOOLEAN empty() const;

        INT memsize() const;

        INT length() const;

        INT size() const;

        WString substr(INT start, INT length = -1) const;

        INT find(WCHAR ch, INT from = 0) const;

        INT find(const WString & str, INT from = 0) const;

        INT find(const WCHAR *str, INT from = 0) const;

        INT reverse_find(WCHAR ch, INT from = -1) const;

        BOOLEAN startswith(const WString & other) const;

        BOOLEAN startswith(WCHAR chr) { return StartsWith(chr); }

        BOOLEAN endswith(const WString & other) const;

        BOOLEAN endswith(WCHAR chr) { return EndsWith(chr); }

        String getstring() const;

        void strcopy(const WCHAR * buffer, INT len);

        WString& toupper();

        WString& tolower();

        void swap(WString & str);

        void clear();

        void erase(INT from);

        void erase(INT from, INT char_count);

        void replace(INT pos, WCHAR ch);

        void insert(INT pos, WCHAR ch);

        void insert(INT pos, const WString & str);

        INT compare(const WString & other_str) const;

        INT compare(const WCHAR * other_str) const;

        void format(const WCHAR * format,...);

        void vformat(const WCHAR * format, va_list args);

        void scan(const WCHAR * format,...) const;

        BOOLEAN HasOnlyDigits(INT number = -1) const;

        static BOOLEAN HasOnlyDigits(const WCHAR * string, INT number = -1);

#endif // APOXI_ENABLE_OBSOLETE_WSTRING_INTERFACE

    private:
        WCHAR *m_strdata;

        BOOLEAN Allocate(UINT char_count);
        BOOLEAN Modify(UINT new_nchars, BOOLEAN preserve_content = TRUE);
        BOOLEAN AttachTo(WStrData *wsd);
        void DetachFrom(WStrData *wsd) const;

        WStrData* GetWStrData() const { return WStrData::FromPtr(m_strdata); }
        UINT WCharToByteCount(UINT n) const { return n << 1U; }

        INT Find(const WCHAR *str, INT from, INT searchlen) const;
        BOOLEAN ConCat(const CHAR *cc_str, UINT cc_len);
        BOOLEAN ConCat(const WCHAR *cc_str, UINT cc_len);

        static WCHAR m_formatbuffer[wstring_max_buffer_size+1];
};

#if !defined(APOXI_WSTRING_TEST_SUITE) && defined(APOXI_RTOS_WIN32)
#define APOXI_WSTRING_TEST_SUITE

// Call for WString test suite, only for WIN32 platform
extern void WStringTest();

#endif

#endif

