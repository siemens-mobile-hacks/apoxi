/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef Apoxi_Zi8Wrapper_hpp
#define Apoxi_Zi8Wrapper_hpp

#ifdef _cplusplus
extern "C"
#endif

#include "zi8api.h"
#include <Config/Config.hpp>
#include <AddOns/GuiInputExtensions/AbstractPredictiveInputBox.hpp>

/************************************************************************/
/* Define values for zi8 core                                                                     */
/************************************************************************/
#define MAX_WORD_LENGTH_SIZE            80  /*Word buffer length*/
#define MAX_CAND_BUFF_SIZE              30  /*Max buffer size of candidate*/
#define MAX_ELEM_BUFF_SIZE              30  /*Max element buffer size */
#define MAX_NUM_CHINESE_CANDIDATES       6  /*Max number of chinese candidate*/
#define MAX_NUM_CANDIDATES              10  /*Max number of candidate*/
#define CAND_PAGE_INCR                  10
#define CHINESE_CAND_PAGE_INCR           6  /*Chinese Candidate page increment*/
#define INPUT_BUF_SIZE                  30  
#define NULL_VALUE                      0xCCCC /* null value for the buffer*/

/************************************************************************/
/*    Zi8 class interfaces with Zi8 core and Apoxi                        */
/************************************************************************/  
class Zi8Wrapper {
    public:

        Zi8Wrapper();

        virtual ~Zi8Wrapper();

        void    Init();
        
        //Handle key down processing
        BOOLEAN         HandleEnglishKeyEvent(WCHAR key);

        BOOLEAN         HandlePinYinKeyEvent(WCHAR key);

        BOOLEAN         HandleStrokeKeyEvent(WCHAR key);

        BOOLEAN         HandleToneKeyEvent(WCHAR key);

        INT             GetMode() const;

        ZI8BOOL         SetZi8EnglishMode();

        ZI8BOOL         SetPinyinSpellingMode();

        ZI8BOOL         SetPinYinMode();

        ZI8BOOL         SetBpmfSpellingMode();

        ZI8BOOL         SetBpmfMode();

        ZI8BOOL         SetScStrokeMode();

        ZI8BOOL         SetTcStrokeMode();
        
        ZI8BOOL         SetZi8GermanMode();

        ZI8BOOL         SetZi8SymbolMode();

        ZI8BOOL         SetToneMode();

        BOOLEAN         GetToneMode();

        INT             SetCandidateSelection(BOOLEAN = FALSE, BOOLEAN = FALSE);

        INT             SetChineseSelection(BOOLEAN = FALSE, BOOLEAN = FALSE);

        const WCHAR*    GetSelectedCandidate()const {return (const WCHAR*)candidate;}

        const WCHAR*    GetCandidatesBuffer()const ;

        const ZI8WCHAR* GetPhonetics() const;

        const ZI8WCHAR* GetStrokes() const;

        const WCHAR*    GetChineseCandidate(INT idx);

        INT             GetSelectedCandidateLength();
        
        void            ClearBuffer();

        void            SetCapsStatus(INT caps_status);

        INT             GetSelectedIndex();

        BOOLEAN         HasPrevPage();

        BOOLEAN         HasNextPage();

        BOOLEAN         HasNextCandidates();

        BOOLEAN         HasPrevCandidates();

        BOOLEAN         HasCandidate();

        BOOLEAN         HasChineseCandidate();

        BOOLEAN         IsComponent(const WCHAR *chr);

        void            SelectComponent(const WCHAR *chr);

        void            SetAssociatedCandidates(WCHAR chr);

        INT             GetCandCharCount();

        INT             GetElementCount();

        BOOLEAN         AddWordToUdb(const WCHAR* new_word);

        static INT      Zi8PinyinCompare(const WString* string1,const WString* string2);  
        static INT      Zi8StrokeCompare(const WString* string1,const WString* string2);  
        static INT      Zi8BopomofoCompare(const WString* string1,const WString* string2);  

        BOOLEAN         IsLanguageSupported(INT language_number) const;


    private:
        
        INT             AddInputBuff(WCHAR key);

        ZI8BOOL         Initialize();

        ZI8BOOL         ProcessInput();

        ZI8BOOL         ProcessPinYinInput();

        ZI8BOOL         ProcessBpmfInput();

        ZI8BOOL         ProcessStrokeInput();

        INT             GetShowCount(const WCHAR *text, AbstractPredictiveInputBox::PredFontId font_id);

        INT             m_inputBuff_count;

        INT             m_iCandOffset, m_chinese_offset;

        INT             m_page_num;     

        INT             m_selected_idx;
        
        INT             m_count, m_totalCount, m_chinese_totalCount;

        INT             m_caps_status;  

        WCHAR*          m_input_buff_ptr;

        WCHAR           m_chinese_candidate;

        BOOLEAN         m_next_page, m_prev_page;

        BOOLEAN         m_scroll_chinese;

        BOOLEAN         m_is_tone_mode;

        INT             m_mode;

        INT             m_cand_char_count;

        ZI8GETPARAM     zi8param;

        ZI8UCHAR        ucElemCount;

        INT             m_offset[50];   

        WCHAR           m_input_buff[INPUT_BUF_SIZE];

        //Buffer for EZiText prediction
        ZI8WCHAR        WordBuffer[MAX_WORD_LENGTH_SIZE];

        ZI8WCHAR        elementBuffer[MAX_ELEM_BUFF_SIZE];

        ZI8WCHAR        candidatesBuffer[MAX_CAND_BUFF_SIZE];

        ZI8WCHAR        PhoneticBuffer[MAX_CAND_BUFF_SIZE];

        ZI8WCHAR        StrokeBuffer[MAX_ELEM_BUFF_SIZE];

        ZI8WCHAR        candidate[30];

        ZI8UCHAR        m_cur_pdb; // Id of the current personal dictionary
};

#ifdef _cplusplus
}//end of extern "C"
#endif

#endif


