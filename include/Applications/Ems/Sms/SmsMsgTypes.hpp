/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "datey_RefMMI_2\lnz_mmi\Mmi\Sms\SmsMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Sms_SmsMsgTypes_hpp)
#define Sms_SmsMsgTypes_hpp
#include <Kernel/Message.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/WString.hpp>
#include <Gui/EditorDocument.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class SmsServiceMsg
    ====================================================================== */
class SmsServiceMsg : public ContextMsg {
    public:
        SmsServiceMsg(ExecutionContext* context, INT16 arg, const WString& text, const PhoneNumber& phone_number);
        virtual ~SmsServiceMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(INT16 arg) { m_arg = arg; }
        INT16 GetArg() const { return m_arg; }
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 21500
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT16 m_arg;
        WString m_text;
        PhoneNumber m_phone_number;
        
    };
/*  ======================================================================
    Class SmsServiceDocumentMsg
    ====================================================================== */
class SmsServiceDocumentMsg : public ContextMsg {
    public:
        SmsServiceDocumentMsg(ExecutionContext* context, INT16 arg, const EditorDocumentObtainer& document_obtainer, const PhoneNumber& phone_number);
        virtual ~SmsServiceDocumentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(INT16 arg) { m_arg = arg; }
        INT16 GetArg() const { return m_arg; }
        const EditorDocumentObtainer& GetDocumentObtainer() const { return m_document_obtainer; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 21501
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT16 m_arg;
        EditorDocumentObtainer m_document_obtainer;
        PhoneNumber m_phone_number;
        
    };
/*  ======================================================================
    Class SendSmsMsg
    ====================================================================== */
class SendSmsMsg : public ContextMsg {
    public:
        SendSmsMsg(ExecutionContext* context, const EditorDocumentObtainer& document_obtainer, const PhoneNumber& phone_number, const PhoneNumber& service_center);
        virtual ~SendSmsMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const EditorDocumentObtainer& GetDocumentObtainer() const { return m_document_obtainer; }
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        void SetServiceCenter(const PhoneNumber& service_center) { m_service_center = service_center; }
        const PhoneNumber& GetServiceCenter() const { return m_service_center; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 21502
            };
        
    private:
        static const MsgMetaData m_meta_data;
        EditorDocumentObtainer m_document_obtainer;
        PhoneNumber m_phone_number;
        PhoneNumber m_service_center;
        
    };
#endif // Sms_SmsMsgTypes_hpp
