/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(ToDoComposeWin_hpp)
#define ToDoComposeWin_hpp

#include <Common/MmiWindow.hpp>
#include <Gui/MultiLineEditor.hpp>
#ifdef APOXI_INCLUDE_T9
#include <AddOns/T9/T9PredictiveInputBox.hpp>
#endif

//#include "AbstractToDoComposeWin.hpp"

class ToDoApp;
class AbstractPredictiveInputBox;

class ToDoComposeWin : public MmiWindow /*AbstractToDoComposeWin*/{
    //typedef AbstractToDoComposeWin Base;
    typedef MmiWindow Base;

    public:
        ToDoComposeWin();

        virtual ~ToDoComposeWin();

        void Init(ToDoApp* todo_app);

        virtual EditorDocumentObtainer GetDocumentObtainer() const;

        virtual void SetDocumentObtainer(const EditorDocumentObtainer& obtainer);

        //virtual void SetEnabled(BOOLEAN is_T9_enabled, BOOLEAN is_save_enabled);

        ToDoApp* GetToDoApplication() const { return m_todo_app; };

        void OnClose();

        void Clean();

        void SetProrityDisplay (INT priority);

        void SetDateDisplay(Date date);

        void SetReadOnlyMode (BOOLEAN read_only);

        void SetNoteDisplay(WCHAR *note);

        virtual AbstractPredictiveInputBox* GetPredInputBox();  

        virtual void OnInputModeChanged(PredInputMapper::PredMode mode);        


    protected:

        virtual void OnLayoutClient();      

    private:
        void OnOpen();
            
        MultiLineEditor         m_editor;       
#ifdef APOXI_INCLUDE_T9
        T9PredictiveInputBox    m_input_box;
#endif          
        ToDoApp*                m_todo_app;
        Label                   m_priority_display;
        Label                   m_date_display;
        WString                 m_priority_text;
        WString                 m_date_text;        
};
#endif 

