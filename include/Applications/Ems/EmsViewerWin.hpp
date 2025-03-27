/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_EmsViewerWin_hpp)
#define Mmi_EmsViewerWin_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/Provider.hpp>
#include <Adc/CompoundSmsItem.hpp>

#include <Sms/SmsActions.hpp>
#include <Sms/AbstractSmsViewerWin.hpp>
#include <Ems/EmsIeParser.hpp>
#include <Ems/EmsEditor.hpp>

class EmsApp;

class EmsViewerWin : public AbstractSmsViewerWin {
    typedef AbstractSmsViewerWin Base;

    public:
        EmsViewerWin();
        void Init(EmsApp* sms_app);
        virtual ~EmsViewerWin();
        
        virtual const EditorDocument* GetDocument() const;
        virtual void SetDocument(const EditorDocument* doc);

    protected:
        virtual void OnDisplaySms(Provider* provider, INT row);

    private:
        EmsEditor   m_editor;
        EmsIeParser m_parser;
};

#endif // Mmi_EmsViewerWin_hpp
