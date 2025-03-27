//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------


#ifndef Atl_Property_hpp
#define Atl_Property_hpp

#include <Auxiliary/DataItem.hpp>
#include <Atl/Features/Feature.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Kernel/MessageRouter.hpp>
#endif  // APOXI_COMPAT_2_7_0

class PropertyDescriptor;


class Property : public Feature{
    typedef Feature Base;

    public:
        enum {
            ID = 4
        };

        enum PropertyAttributeId {
            ValueAttributeId = 2
        };
        
        enum Notification{
            NotifyNever = 0,
            NotifyValidateSet = 1, 
            NotifyPreviewChanged = 2,
            NotifySet = 4,
            NotifyCanceled = 8
        };

        Property(); 

        Property(AtlApplication* app, 
                const FeatureID& id); 

        Property(AtlApplication* app, 
                const FeatureID& id, 
                const DataItem& value);

        Property(AtlApplication* app, 
                const FeatureID& id, 
                const UINT8 notification_rule, 
                const DataItem& value);
        
        virtual ~Property();

        void Init(AtlApplication* app, 
                  const FeatureID& id, 
                  const DataItem& value);

        void Init(AtlApplication* app, 
                  const FeatureID& id);

        void Init(AtlApplication* app, 
                  const FeatureID& id, 
                  const UINT8 notification_rule);

        void Init(AtlApplication* app, 
                  const FeatureID& id, 
                  const UINT8 notification_rule, 
                  const DataItem& value);

        void Init(AtlApplication* app, 
                  const FeatureID& id, 
                  const DataItem& value, 
                  BOOLEAN available, 
                  BOOLEAN enabled);

        void Init(AtlApplication* app, 
                  const FeatureID& id, 
                  const UINT8 notification_rule, 
                  const DataItem& value, 
                  BOOLEAN available, 
                  BOOLEAN enabled);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        const DataItem& GetDataItem() const { return m_value; }

        void            SetDataItem(const DataItem& value);
           
        Number      GetNumber() const { return m_value.GetNumber(); }

        String      GetString() const { return m_value.GetString(); }

        WString     GetWString() const { return m_value.GetWString(); }

        PhoneNumber GetPhoneNumber() const { return m_value.GetPhoneNumber(); }

        Date        GetDate() const { return m_value.GetDate(); }

        Time        GetTime() const { return m_value.GetTime(); }

        DateTime    GetDateTime() const { return m_value.GetDateTime(); }

        BOOLEAN GetString(String & strdata) const { return m_value.GetString(strdata); }

        BOOLEAN GetWString(WString & strdata) const { return m_value.GetWString(strdata); }

        BOOLEAN GetPhoneNumber(PhoneNumber & bcdnr) const { return m_value.GetPhoneNumber(bcdnr); }

        BOOLEAN GetDate(Date & date) const { return m_value.GetDate(date); }

        BOOLEAN GetTime(Time & time) const { return m_value.GetTime(time); }

        BOOLEAN GetDateTime(DateTime & date) const { return m_value.GetDateTime(date); }

        GenericObject * GetGenericObject() const { return m_value.GetGenericObject(); }

        const GenericObject * GetGenericObjectPtr() const { return m_value.GetGenericObjectPtr(); }

        BOOLEAN GetBoolean() const { return m_value.GetBoolean(); }

        void SetProvider(Provider * provider);

        void SetNumber(const Number data);

        void SetString(const String & strdata);

        void SetString(const CHAR * strdata);

        void SetWString(const WString & strdata);

        void SetWString(const WCHAR * strdata);

        void SetPhoneNumber(const PhoneNumber & bcdnr);

        void SetDate(const Date & date);

        void SetTime(const Time & time);

        void SetDateTime(const DateTime & date);

        void SetDateTime(const DateTime::Persist & date);

        void SetGenericObject(const GenericObject * const genobject);

        void SetBoolean(const BOOLEAN data);

        BOOLEAN HasNotification(const Notification rule) const { return ((m_notification_rule & rule) == rule); }

        virtual void GetAsWString(WString& text) const;

        const PropertyDescriptor* GetDefaultDescriptor() const {return m_descriptor;}

        void  SetDefaultDescriptor(PropertyDescriptor* descriptor) {m_descriptor = descriptor;}
                    
    protected:
        DataItem m_value;
        UINT8 m_notification_rule;
        PropertyDescriptor* m_descriptor;
        
    private:
        Property(const Property& value);
};

#endif  // Atl_Property_hpp

