/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_T9InputMapper_hpp)
#define Apoxi_T9InputMapper_hpp

#include <Gui/PredInputMapper.hpp>
#include <AddOns/T9/T9Wrapper.hpp>


class T9InputMapper : public PredInputMapper {
    typedef PredInputMapper Base;
    
    public:
        T9InputMapper(AbstractEditor *editor = 0);

        typedef T9Wrapper::enumConstants enumConstants;

        virtual ~T9InputMapper();

        virtual INT GetId() const;
        
        virtual Type GetType() const;

        virtual void SetEditor(AbstractEditor *editor);

        virtual const WCHAR* GetStatusInfo() const;

        virtual const WCHAR* GetPhonetics(INT *selected_idx = 0) const;

        virtual const WCHAR* GetStrokes() const;

        virtual const WCHAR* GetSelection() const;

        virtual INT GetSelectedIndex() const;

        virtual PredMode GetMode() const;

        typedef T9Wrapper::t9_language t9_language;

        BOOLEAN SetMode_T9_Latin(t9_language lang);

        virtual BOOLEAN AddExplicitCharacter(const WCHAR chr);

        BOOLEAN AddExplicitWord(const WString& word);
        
        BOOLEAN AddNewWordToUdb(const WString& new_word);

        BOOLEAN DeleteActiveWord();

        virtual BOOLEAN Notify (NotificationType type, INT index = 0, const AtomItem* item = 0);
    protected:
        
        KeyCode GetSpaceKeyCode() const;

        virtual BOOLEAN OnLongKeyPress(KeyCode apoxi_key_code);

        //This is a new virtual handler, for T9, because APOXI does not implement this logic:
        virtual BOOLEAN OnLongKeyPress_T9(KeyCode apoxi_key_code);

        virtual BOOLEAN OnKeyUp(KeyCode apoxi_key_code, UINT32 duration);

        //This is a new virtual handler, for T9, because APOXI does not implement this logic:
        virtual BOOLEAN OnShortKeyUp_T9(KeyCode apoxi_key_code);


        static KeyCode GetApoxiKeyCode_Hash();

        static KeyCode GetApoxiKeyCode_Menu();

        static KeyCode GetApoxiKeyCode_Star();

        void SynchronizeBuffers_T9ToApoxi();

        void SynchronizeBuffers_ApoxiToT9();

        void UpdateTextEditorDocument();

        void UpdateMultiMediaEditorDocument();

        BOOLEAN IsTextEditorDocument() const;

        virtual T9Wrapper* GetT9Wrapper() = 0;

        virtual const T9Wrapper* GetT9Wrapper() const = 0;

        // Debugging-code (enabled only for HOST-environment)
        #if defined(_MSC)
            #if defined(_DEBUG)
                INT DumpCompoundItem(const CompoundItem& comp_item, INT level = 0) const;
                void DumpDocument (WCHAR* method);
            #endif
        #endif

    private:
        BOOLEAN m_longkeypress_processed;
        UINT m_old_t9_caret_pos;
};

#endif  // Apoxi_T9InputMapper_hpp


