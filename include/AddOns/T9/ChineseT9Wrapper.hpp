#ifndef Apoxi_ChineseT9Wrapper_hpp
#define Apoxi_ChineseT9Wrapper_hpp

#ifdef _cplusplus
extern "C"
#endif

#include "T9Wrapper.hpp"
#include <Config/Config.hpp>


/************************************************************************/
/*    T9 class interfaces with T9 core and Apoxi                        */
/************************************************************************/  
class ChineseT9Wrapper : public T9Wrapper {
    typedef T9Wrapper Base;

    public:
        ChineseT9Wrapper();
        virtual ~ChineseT9Wrapper();

        virtual void Init();
        virtual void DestroyT9();
            
        BOOLEAN GetChineseMode_IsAutoSpell() const;
        BOOLEAN GetChineseMode_IsComponents() const;
        BOOLEAN GetChineseMode_IsCUdbSearchOnly() const;

        // Get different modes:
        BOOLEAN GetChineseMode_IsFuzzyPinyin() const;
        BOOLEAN GetChineseMode_IsAmbiguousPhonetic() const;
        BOOLEAN GetChineseMode_IsExplicitPhonetic() const;
        BOOLEAN GetChineseMode_IsExplicitPhoneticContinualSelection() const;
        BOOLEAN GetChineseMode_IsStroke() const;

        // Set different modes
        BOOLEAN SetMode_PinYin();
        BOOLEAN SetMode_Bopomofo();
        BOOLEAN SetMode_SimplifiedChineseStroke();
        BOOLEAN SetMode_TraditionalChineseStroke();

        const T9U16* GetChineseSelectPage() const;

        T9NUM GetChineseSelectPageNum() const;
        
        T9NUM GetChineseKeyBufLen() const;

        T9U8 GetPhoneticIndex() const;

        T9U8 GetPhoneticCount() const;

        BOOLEAN SelectPhoneticChineseWord(UINT index);
        BOOLEAN SelectStrokeChineseWord(UINT index);

        BOOLEAN ToggleComponentEntryMode();

        BOOLEAN ChangePhoneticSelection(T9U8 phonetic_index);

        const T9U8* GetPhoneticList() const;
        const WCHAR* GetBopomofoList() const;

        void RefreshPhoneticList();

        const T9U8* GetStrokeBuffer() const;

        BOOLEAN IsLanguageSupported(t9_language language, T9MINOR mode);
    
    private:
        int m_py_key_buf_origin_len;

        T9MINOR m_cur_pred_mode;

        T9U16 GetChineseMode() const;

        // Internal function, used for T9 core initialization
        BOOLEAN AllocateT9(T9NUM nBufLenMax);
        BOOLEAN AllocateT9Chinese(T9NUM nKeyBufLenMax, T9NUM nSelectPageMax, T9NUM nSpellBufLenMax);
        BOOLEAN AllocateT9CUdb(T9U16 wDataSize, T9U16 wSymbolClass);

        // Internal function, used for T9 core termination, and free the allocated space
        BOOLEAN DeallocateT9Chinese();

        // Convert Bopomofo Single character to Unicode
        t9_symbol ConvertBopomofoSingleByteToUnicode(T9U8 cChar) const;
};

T9STATUS  FARCALL   T9HandleRequest_Chinese(T9FieldInfo *pFieldInfo, T9Request *pRequest);

#ifdef _cplusplus
}//end of extern "C"
#endif

#endif


