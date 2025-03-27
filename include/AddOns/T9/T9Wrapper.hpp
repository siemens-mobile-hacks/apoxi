/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ----------------------------------------------------------------------- */

#ifndef Apoxi_T9Wrapper_hpp
#define Apoxi_T9Wrapper_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include <t9api.h>
#include <Config/T9InputConfig.hpp>


class T9EventWrapper : public T9Event //T9Event is a struct from the T9 C API.
{
    public:
        T9EventWrapper();
};

class T9Wrapper {
    public:
        T9Wrapper();
        virtual ~T9Wrapper();

        typedef T9SYMB t9_symbol;

        enum enumConstants
        {
            T9_KEY_MAP_INVALID = 0xff
        };

        enum HandleKeyEventStatus {
            Error,
            Ok,
            WordNotFound
        };

        virtual void Init();
        virtual void DestroyT9();

        const t9_symbol* GetTextBuffer() const;
        T9NUM GetTextBufferLengthMax() const;
        T9NUM GetTextBufferLength() const;
        INT GetCursorPos() const;

        virtual UINT8 HandleKeyEvent(t9_symbol T9Key);

        T9NUM GetLdbNum() const;

        T9U32 GetLdbMode() const;
        
        BOOLEAN SetBuffer(INT cursor_pos, INT buf_len, const t9_symbol *symb_buffer);
        

        typedef T9NUM t9_language;

        BOOLEAN SetT9EnglishMode();

        BOOLEAN SetT9LatinMode(t9_language lang);

        BOOLEAN AddExplicitCharacter(t9_symbol t9_key);
    
        BOOLEAN DeleteActiveWord();

        BOOLEAN RepositionCursor(INT cursor_pos);
        BOOLEAN RepositionCursor_Beginning();
        BOOLEAN RepositionCursor_End();

        const WString GetActiveWord();

        BOOLEAN AddExplicitWord(const WString& word);
        
        BOOLEAN AddNewWordToUdb(const WString& new_word);

        BOOLEAN SetWordLeftToCursorActive();

        T9FieldInfo* GetT9FieldInfo();

        const T9FieldInfo* GetT9FieldInfo() const;

        BOOLEAN IsLanguageSupported(t9_language language);
    
    protected:

        // T9FieldInfo seems to be a general state structure for the T9 C API.
        T9FieldInfo m_field_info;

        // Internal function, used for T9 core initialization
        BOOLEAN AllocateT9(T9NUM nBufLenMax);
        BOOLEAN InitializeT9Udb(T9U16 wSymbolClass);
        BOOLEAN InitializeT9(T9NUM nLdbNum);

        // Internal function, used for T9 core termination, and to free the allocated space
        BOOLEAN TerminateT9();
        BOOLEAN DeallocateT9();
        BOOLEAN DeallocateT9Udb();

};


T9STATUS  FARCALL   T9HandleRequest(T9FieldInfo *pFieldInfo, T9Request *pRequest);

// This is implemented in t9gen.c, but not declared in any header:
// See "5.2.6 Implementing T9ReadLdbData with Internal LDBs" in the "T9 API Implementation Guide":
extern "C" // It's a C function, not a C++ function.
{
T9NUM FARCALL T9ReadLdbData(T9FieldInfo *pFieldInfo,T9U32 dwOffset,T9U8 *pbDst,T9NUM nSize);
}

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_T9Wrapper_hpp


