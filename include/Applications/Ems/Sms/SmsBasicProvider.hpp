/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsBasicProvider_hpp)
#define Mmi_SmsBasicProvider_hpp

#include <AddOns/AuxExtensions/PhoneNumberMergeProvider.hpp>
#include <AddOns/AuxExtensions/JoinRule.hpp>
#include <Auxiliary/AbstractDelegationProvider.hpp>
#include <Gui/Bitmap.hpp>

#include <Config/Config.hpp>

class SmsBasicProvider : public AbstractDelegationProvider
{
    typedef AbstractDelegationProvider Base;

    public:
        SmsBasicProvider();
        virtual ~SmsBasicProvider();

        void Init(Provider *sms_provider);

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        virtual BOOLEAN GetChildRow(INT& childrow, INT row);

        void SetProvider(Provider *provider);

        void SetStatusChanged() { m_status = Provider::changed; }
        
    protected:
        virtual BOOLEAN IsPhoneNumberTextDefaultData(INT columnid, INT row);
        virtual BOOLEAN Lock();
        virtual BOOLEAN Unlock();

    private:
        BOOLEAN IsWaitingMessage(const INT16 &row);
        const ImageObtainer GetIcon(const INT16 &row);


        BOOLEAN             m_is_locked;
};

#endif // Mmi_SmsBasicProvider_hpp
