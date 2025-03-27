/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_EmsComposeWin_hpp)
#define Mmi_EmsComposeWin_hpp

#include <Asc/SmsContext.hpp>
#include <AddOns/MultiMedia/MultiMediaEditor.hpp>
#include <AddOns/MultiMedia/RichTextCompoundItem.hpp>
#include <AddOns/MultiMedia/ParagraphCompoundItem.hpp>
#include <AddOns/MultiMedia/MultiMediaEditorDocument.hpp>
#include <AddOns/GuiInputExtensions/AbstractPredictiveInputBox.hpp>
#include <GuiExtensions/MenuAction.hpp>
#include <GuiExtensions/ActionMenuAccessor.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Sms/AbstractSmsComposeWin.hpp>
#include <Ems/EmsEditor.hpp>
#include <Ems/EmsCreator.hpp>
#include <Ems/EmsIeParser.hpp>
#include <Ems/EmsEditorListener.hpp>

#ifdef APOXI_INCLUDE_T9
#include <AddOns/T9/T9PredictiveInputBox.hpp>
#endif

class EmsApp;

class EmsComposeWin : public AbstractSmsComposeWin, public EmsEditorListener {
    typedef AbstractSmsComposeWin Base;

    public:

        EmsComposeWin();
        virtual ~EmsComposeWin();

        virtual void Init(EmsApp* ems_app);
        
        virtual EditorDocumentObtainer GetDocumentObtainer() const;
        virtual void SetDocumentObtainer(const EditorDocumentObtainer& obtainer);

        virtual void RelaySms(Provider* provider, INT row, BOOLEAN reply = FALSE);

        EmsEditor* GetEditor()  { return &m_editor; }

        void InsertImage();
        void InsertSound();

        virtual void OnInputModeChanged(PredInputMapper::PredMode mode);

        virtual AbstractPredictiveInputBox* GetPredInputBox();

    protected:
        virtual void OnLayoutClient();
        virtual void OnDocumentChanged(const EditorDocument* doc);
        virtual void OpenModeless(const Rect& rect = Rect());


    private:
        enum EmsTriggerType {
            TriggerFormat = 32,
            TriggerInsert
        };


        // Customer specific implementation
        ImageObtainer GetSelectedImage() const;
        // Customer specific implementation
        SoundObtainer GetSelectedSound() const;

        EmsEditor           m_editor;
        SmsContext          m_sms_context;
#ifdef APOXI_INCLUDE_T9
        T9PredictiveInputBox    m_input_box;
#endif      
        static Label        m_counter_display;
        static WString      m_counter_text;
                
        static EmsIeParser          m_parser;

        INT     m_pdu_count;
        INT     m_free_chars;
};

#endif // Mmi_EmsComposeWin_hpp
