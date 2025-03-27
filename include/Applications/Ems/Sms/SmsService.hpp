/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsService_hpp)
#define Mmi_SmsService_hpp

#include <Common/MmiServices.hpp>
#include <Common/CommonMsgTypes.hpp>
#include <Common/MmiServices.hpp>
#include <Sms/SmsMsgTypes.hpp>

class AbstractSmsApp;

class BasicSmsService : public SmsService {
    typedef SmsService Base;
    public:
        BasicSmsService(AbstractSmsApp* implementing_app);
        virtual ~BasicSmsService();

        virtual ServiceResult ComposeSms(const WString* text = 0, const PhoneNumber* destination = 0) const;
        virtual ServiceResult ComposeSms(const PhoneNumber* destination = 0) const;
        virtual ServiceResult ComposeSms(const EditorDocumentObtainer& obtainer, const PhoneNumber* destination = 0) const;
        
        virtual ServiceResult StoreSms(const WString* text, const PhoneNumber* destination = 0) const;
        virtual ServiceResult StoreSms(const EditorDocumentObtainer& obtainer, const PhoneNumber* destination = 0) const;
        
        virtual ServiceResult SendSms(const WString* text, const PhoneNumber* destination = 0) const;
        virtual ServiceResult SendSms(const EditorDocumentObtainer& obtainer, const PhoneNumber* destination = 0) const;
        
    private:
        ServiceResult SendMessage(INT type, const WString* text, const PhoneNumber* destination) const;
        ServiceResult SendMessage(INT type, const EditorDocumentObtainer& obtainer, const PhoneNumber* destination) const;
        AbstractSmsApp* m_app;

};

#endif // Mmi_SmsService_hpp
