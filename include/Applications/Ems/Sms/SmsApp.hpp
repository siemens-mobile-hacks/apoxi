/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsApp_hpp)
#define Mmi_SmsApp_hpp

#include <Sms/AbstractSmsApp.hpp>
#include <Sms/SmsComposeWin.hpp>
#include <Sms/SmsViewerWin.hpp>
#include <Sms/SmsUtility.hpp>

class SmsApp : public AbstractSmsApp {
    typedef AbstractSmsApp Base;

    public:
        static SmsApp* GetInstance();
        ~SmsApp();
            
    private:
        void OnOpen();      
        SmsApp();           
        
        static SmsApp m_app;
        
        static SmsUtility                   m_sms_utility;
};

#endif  // Mmi_SmsApp_hpp
