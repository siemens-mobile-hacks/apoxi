/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_UsimPbAddData_hpp)
#define Adc_UsimPbAddData_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/DataItem.hpp>

/*  ------------------------------------------------------------------------
    UsimPbAddData
    ------------------------------------------------------------------------ */
// allow hold various number of data items of the sam type. The behaviour is 
// controlled by the number of entries and columns. A pointer array with 
// entries*columns is always allocated, this array is type checked with the parameter
// DataType. If misused, assertions are thrown. This container class is used
// for SNE, ANR, EMAIL entries.

class UsimPbAddData
{
    // a union which can be either a pointer to a wstring or a phonenumber object
    struct UsimPbAddDataItem 
    {
        union {
            PhoneNumber * m_phno;
            WString * m_wstr;
        } m_val;
    };

    public:
        UsimPbAddData();
        ~UsimPbAddData(); // destructor not virtual !!!

        // creates a dynamically array which contain pointers to objects of DataType
        BOOLEAN Init(UINT entries, UINT columns, DataType type);

        // get the WString if existing, otherwise an empty WString object
        const WString & GetWString(UINT idx, UINT column) const;
        // set the WString object, if it is empty, then object which was pointed to is deleted 
        void SetWString(UINT idx, UINT column, const WString & wstr);

        // get the PhoneNumber if existing, otherwise an empty WString object
        const PhoneNumber & GetPhoneNumber(UINT idx, UINT column) const;
        // set the PhoneNumber object, if it is empty, then object which was pointed to is deleted 
        void SetPhoneNumber(UINT idx, UINT column, const PhoneNumber & phno);

        // get the recno of the item
        UINT8 GetRecno(UINT idx, UINT column) const;
        // set the recno of the item
        void SetRecno(UINT idx, UINT column, UINT8 recno);

        // returns TRUE if the object is ready for operation
        BOOLEAN IsReady() const { return (m_ptrs!=0); }

        // static empty objects which are used for returning empty objects in case ptr = 0
        static const WString     c_empty_wstr;
        static const PhoneNumber c_empty_phno;

    private:
        DataType m_type;
        UINT     m_entries;
        UINT     m_columns;
        UsimPbAddDataItem * m_ptrs;
        UINT8 *  m_recnos;
};


#endif //#if defined(APOXI_ENABLE_USIM_PHONEBOOK)

#endif


