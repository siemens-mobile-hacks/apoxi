/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsViewerWin_hpp)
#define Mmi_SmsViewerWin_hpp

#include <Sms/AbstractSmsViewerWin.hpp>
#include <Gui/ImageBox.hpp>
#include <Sms/SmsTextParser.hpp>

class SmsApp;

class SmsViewerWin : public AbstractSmsViewerWin {
    typedef AbstractSmsViewerWin Base;

    public:
        SmsViewerWin();
        void Init(SmsApp* sms_app);
        virtual ~SmsViewerWin();
        virtual const EditorDocument* GetDocument() const;
        virtual void SetDocument(const EditorDocument* doc);

        void GoToSmsEmbItems(Direction dir);

        SmsTextEntry GetSelectedSmsEmbItem();

        virtual void OnGetFocus();
        
    protected:
        virtual void OnDisplaySms(Provider* provider, INT row, INT set_index = -1);

        virtual void OnLayoutClient();

    private:
        SmsViewerWin(const SmsViewerWin &ascw);
    
        SmsViewerWin& operator=(const SmsViewerWin&);
        MultiLineEditor     m_text_area;
        WString             m_message;
        SmsTextParser   m_parser;
        INT             m_parsed_item_idx;

        WString         m_ph_no;
        INT             m_idx_msg_txt;
        PhoneNumber     m_from_to_ph_no;
        
        ImageBox            m_conc_display;

        INT m_row_to_set;

        INT m_current_row;
        INT m_set_index;
};

#endif // Mmi_SmsViewerWin_hpp
