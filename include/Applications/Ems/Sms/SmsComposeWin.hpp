/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsComposeWin_hpp)
#define Mmi_SmsComposeWin_hpp

class SmsApp;
#include <Gui/TextLine.hpp>

#if defined(APOXI_INCLUDE_T9)
    #include <AddOns/T9/T9PredictiveInputBox.hpp>
#elif defined(APOXI_INCLUDE_ZI8)
    #include <AddOns/Zi8/Zi8PredictiveInputBox.hpp>
#endif

#include <Sms/AbstractSmsComposeWin.hpp>
#include <Sms/SmsEditor.hpp>
    

class SmsComposeWin : public AbstractSmsComposeWin {
    typedef AbstractSmsComposeWin Base;

    public:
        SmsComposeWin();
        
        virtual ~SmsComposeWin();

        void Init(AbstractSmsApp* sms_app);

        virtual EditorDocumentObtainer GetDocumentObtainer() const;
        
        virtual void SetDocumentObtainer(const EditorDocumentObtainer& obtainer);

        virtual void InsertText(const WString& text);

        void SetCounterText(int segment, int freecounter);

        UINT8 GetCharactersPerSegment();

    protected:
        virtual AbstractPredictiveInputBox* GetPredInputBox();
        virtual void OnOpen();

        virtual void OnLayoutClient();



#if defined(APOXI_INCLUDE_T9) || defined (APOXI_INCLUDE_ZI8)

        virtual void OnInputModeChanged(PredInputMapper::PredMode mode);
#endif

    private:
        SmsComposeWin(const SmsComposeWin &ascw);
    
        SmsComposeWin& operator=(const SmsComposeWin&);

#if defined(APOXI_INCLUDE_T9)
        T9PredictiveInputBox    m_input_box;
#elif defined (APOXI_INCLUDE_ZI8)
        Zi8PredictiveInputBox   m_input_box;
#endif      

        SmsEditor       m_editor;
        
        TextLine    m_counter_display;
        WString     m_counter_text;
};

#endif // Mmi_SmsComposeWin_hpp
