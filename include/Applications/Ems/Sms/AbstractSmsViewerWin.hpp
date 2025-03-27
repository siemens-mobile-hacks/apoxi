/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_AbstractSmsViewerWin_hpp)
#define Mmi_AbstractSmsViewerWin_hpp

class AbstractSmsApp;
#include <Atl/AtlWindow.hpp>
#include <Sms/SmsTextParser.hpp>

class AbstractSmsViewerWin : public AtlWindow { 
    typedef AtlWindow Base;

    public:
        enum Direction {
            First = 64,
            Prev,
            Next,
            Last,
        };

        AbstractSmsViewerWin();
        
        void Init(AbstractSmsApp* sms_app, const WCHAR* title);
        
        virtual ~AbstractSmsViewerWin();

        virtual INT GoToSms(Direction dir);
        
        virtual void GoToSmsEmbItems(Direction dir) = 0;

        virtual SmsTextEntry GetSelectedSmsEmbItem() = 0;
        
        virtual const EditorDocument* GetDocument() const = 0;
        
        virtual void SetDocument(const EditorDocument* doc) = 0;

        Provider* GetProvider() const;
        
        INT GetSelectedSms() const;
        
        virtual void SetSelectedSms(Provider* provider, INT selected_row = 0);

        void UpdateDisplayedSms();
    
        // Remove when EMS has been adapted to plugin   
 #if defined (APPLICATION_EMS) || defined (APPLICATION_ADVEMS)

        AbstractSmsApp* GetSmsApplication() const { return (AbstractSmsApp*) GetApplication(); }
        
        void    SetTitleText(const WCHAR* title) { SetTitle(title); }
        
        virtual void SwitchReadStatus(BOOLEAN switch_to_read) {  }
        
        #endif 

        void SetUpdateOnClose(BOOLEAN state);
    protected:
        virtual void OnClose();
        virtual void OnDisplaySms(Provider* provider, INT row, INT set_index = -1) = 0;

    private:
        AbstractSmsViewerWin(const AbstractSmsViewerWin &ascw);
    
        AbstractSmsViewerWin& operator=(const AbstractSmsViewerWin&);

        void PerformAutoDeletion(INT index);

        Provider*       m_provider;
        
        INT             m_selected_row;
        
        Number          m_selected_record;

        BOOLEAN m_update_on_close;
};

#endif // Mmi_AbstractSmsViewerWin_hpp
