/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Zi8InputMapper_hpp)
#define Apoxi_Zi8InputMapper_hpp

#include <Gui/PredInputMapper.hpp>
#include <AddOns/Zi8/Zi8Wrapper.hpp>

class Zi8InputMapper : public PredInputMapper {
    typedef PredInputMapper Base;
    
    public:
        Zi8InputMapper(AbstractEditor *editor = 0);

        virtual ~Zi8InputMapper();

        virtual INT GetId() const;

        virtual Type GetType() const;

        virtual void SetEditor(AbstractEditor *editor);

        virtual const WCHAR* GetStatusInfo() const;

        virtual const WCHAR* GetPhonetics(INT *selected_idx = 0) const;

        virtual const WCHAR* GetStrokes() const;

        virtual const WCHAR* GetSelection() const;

        virtual INT GetSelectedIndex() const;

        virtual BOOLEAN SetMode(PredMode mode);

        virtual PredMode GetMode() const;
        
        virtual BOOLEAN IsModeSupported(PredMode mode);

        BOOLEAN HasPrevPage() const;

        BOOLEAN HasNextPage() const;
        
        INT GetElementCount() const;    
        
        INT GetCapsStatus() const;
        
        BOOLEAN HasCandidate() const;

        BOOLEAN AddNewWordToUdb(const WString& new_word);

        void ReplaceWithNewWord(const WString& new_word);
        
        void        ClearEditor();

    protected:
        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);

        virtual BOOLEAN OnKeyUp(KeyCode key_code, UINT32 duration);

        virtual BOOLEAN Notify (NotificationType type, INT index, const AtomItem* item = 0);

    private:

        void SynchronizeBuffers_Zi8ToApoxi(const WString& new_word=L"");

        BOOLEAN     HandleZi8EnglishKeyDown(WCHAR key); 
        
        BOOLEAN     HandlePinYinKeyDown(WCHAR key);
    
        BOOLEAN     HandleStrokeKeyDown(WCHAR key);

        BOOLEAN     HandleToneKeyDown(WCHAR key);
        
        INT         m_caret_idx;

        INT         m_old_buff_length;
        
        INT         m_caps_status;  //0=No Caps; 1=All Caps; 2=First Caps

        BOOLEAN     m_insert_between, m_reset_write_pos;

        BOOLEAN     m_left_key, m_right_key;

        BOOLEAN     m_prev_page, m_next_page;

        BOOLEAN     m_select_chinese;

        Zi8Wrapper  m_zi8_wrapper;

        // for storing the mode that was engaged before switching to symbol mode
        PredInputMapper::PredMode       m_old_mode;

        #if defined(_MSC)
            #if defined(_DEBUG)
                INT DumpCompoundItem(const CompoundItem& comp_item, INT level = 0) const;
                void DumpDocument (WCHAR* method);
            #endif
        #endif
};

#endif  // Apoxi_Zi8InputMapper_hpp

