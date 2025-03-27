/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_AbstractSmsComposeWin_hpp)
#define Mmi_AbstractSmsComposeWin_hpp


class AbstractSmsApp;
class AbstractPredictiveInputBox;

#include <Atl/AtlWindow.hpp>

class AbstractSmsComposeWin : public AtlWindow {
        typedef AtlWindow Base;

    public:
        AbstractSmsComposeWin();
        void Init(AbstractSmsApp* sms_app, const WCHAR* title);
        virtual ~AbstractSmsComposeWin();
        virtual EditorDocumentObtainer GetDocumentObtainer() const = 0;
        virtual void SetDocumentObtainer(const EditorDocumentObtainer& obtainer) = 0;
        virtual void InsertText(const WString& text) = 0;
        void SetDestinationAddress(const PhoneNumber* number);
        const PhoneNumber& GetDestinationAddress() const { return m_destination; }
        void SetServiceCenter(const PhoneNumber* service_center) { m_service_center = service_center; }
        const PhoneNumber& GetServiceCenter() const { return m_service_center; }

        virtual void OnInputModeChanged(PredInputMapper::PredMode mode);
        virtual AbstractPredictiveInputBox* GetPredInputBox() = 0;

        virtual void RelaySms(Provider* provider, INT row, BOOLEAN reply = FALSE);

    private:
        AbstractSmsComposeWin(const AbstractSmsComposeWin &ascw);
    
        AbstractSmsComposeWin& operator=(const AbstractSmsComposeWin&);
        PhoneNumber         m_destination;
        PhoneNumber         m_service_center;
};

#endif // Mmi_AbstractSmsComposeWin_hpp
