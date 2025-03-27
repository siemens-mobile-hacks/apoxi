/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(_Adc_DataItem_hpp)
#define _Adc_DataItem_hpp

#include <Auxiliary/String.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/GenericObject.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>
#include <Auxiliary/DateTime.hpp>


enum DataType {
    UndefinedType = 0,
    NumberType = 1,
    WStringType = 2,
    StringType = 3,
    PhoneNumberType = 4,
    ProviderType = 5,
    DateType = 6,
    TimeType = 7,
    DateTimeType = 8,
    GenericType = 9,
    BooleanType = 10
};

typedef INT32 Number;

class Provider;

class DataItem
{
    public:
        DataItem();
        DataItem(DataType type);
        DataItem(Number val);
        DataItem(const String & stringdata);
        DataItem(const WString & wstringdata);
        DataItem(const PhoneNumber & PhoneNumber);
        DataItem(const Date & date);
        DataItem(const Time & time);
        DataItem(const DateTime & datetime);
        DataItem(const DateTime::Persist & datetime);
        DataItem(const GenericObject * const object);
        DataItem(const DataItem &data_item);

        ~DataItem();

        void SetDataType(DataType type);

        DataType GetDataType() const { return m_type; }

        Provider  * GetProvider() const;

        Number      GetNumber() const;

        String      GetString() const;

        WString     GetWString() const;

        PhoneNumber GetPhoneNumber() const;

        Date        GetDate() const;

        Time        GetTime() const;

        DateTime    GetDateTime() const;

        BOOLEAN GetString(String & strdata) const;

        BOOLEAN GetWString(WString & strdata) const;

        BOOLEAN GetPhoneNumber(PhoneNumber & bcdnr) const;

        BOOLEAN GetDate(Date & date) const;

        BOOLEAN GetTime(Time & time) const;

        BOOLEAN GetDateTime(DateTime & date) const;

        GenericObject * GetGenericObject() const;

        const GenericObject * GetGenericObjectPtr() const;

        BOOLEAN GetBoolean() const;

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

        BOOLEAN IsEqual(const DataItem & item) const;
        BOOLEAN IsNotEqual(const DataItem & item) const { return ! IsEqual(item); }
        BOOLEAN IsLess(const DataItem & item) const;
        BOOLEAN IsGreater(const DataItem & item) const;
        BOOLEAN IsLessEqual(const DataItem & item) const { return ! IsGreater(item); }
        BOOLEAN IsGreaterEqual(const DataItem & item) const { return ! IsLess(item); }
        BOOLEAN IsInRange(const DataItem & item1, const DataItem & item2) const;

        BOOLEAN operator == (DataItem & item) const { return IsEqual(item); }
        BOOLEAN operator != (DataItem & item) const { return IsNotEqual(item); }
        BOOLEAN operator < (DataItem & item) const { return IsLess(item); }
        BOOLEAN operator > (DataItem & item) const { return IsGreater(item); }
        BOOLEAN operator <= (DataItem & item) const { return IsLessEqual(item); }
        BOOLEAN operator >= (DataItem & item) const { return IsGreaterEqual(item); }

        DataItem & operator = (const DataItem & item);
    private:
        void DeleteChildObject();
        // union has now 64 bits, because of clear area, necessary cause of Persist structs
        union {
            void *            m_void;
            Number            m_number;
            Time::Persist     m_time;
            Date::Persist     m_date;
            DateTime::Persist m_datetime;
            struct {
                UINT32 m_del1;
                UINT32 m_del2;
            } m_clear;  // clear area for the 64 bits used
        } m_val;

    protected:
        DataType m_type;

};

typedef INT (*CompareFunction)(void **, void **);
typedef void * (*CreateFunction)(const void *);
typedef void (*DeleteFunction)(const void *);


BOOLEAN DataItemTestSuite();

#endif

