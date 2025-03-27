/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDatatElements_hpp)
#define BtDatatElements_hpp

#include <Bluetooth/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    forward declaration
    ------------------------------------------------------------------------ */

class BtSvrServiceAttribute;

class BtSvrDataElement
{
    private:
        friend class BtSvrServiceAttribute;

    public:
        BtSvrDataElement();

        virtual ~BtSvrDataElement();

    public:

        BOOLEAN IsValid() const;


        BtDataElementType GetType() const;


        INT32 GetValueSize() const;


        const void* GetValuePointer() const;


        UINT16 GetNumberOfDataElements() const;


        BOOLEAN GetDataElementAtIndex(UINT16 index, BtSvrDataElement& svr_data_element) const;

    public:

        UINT32 AsUnsigned() const;


        INT32 AsSigned() const;


        BtUUID AsUuid() const;


        String AsString() const;


        WString AsWString() const;


        BOOLEAN AsBoolean() const;

    private:

        friend BOOLEAN operator==(const BtSvrDataElement& left_value, const BtSvrDataElement& right_value);


        friend BOOLEAN operator!=(const BtSvrDataElement& left_value, const BtSvrDataElement& right_value);

    private:

        BtSvrDataElement(const btapi_de_t& data_element);


        BtSvrDataElement& operator=(const BtSvrDataElement& svr_data_element);

    private:

        BOOLEAN IsEqual(const BtSvrDataElement& right_value) const; 


        int CompareUnsigned(const BtSvrDataElement& right_value) const;


        int CompareSigned(const BtSvrDataElement& right_value) const;


        BOOLEAN CompareUuid(const BtSvrDataElement& right_value) const; 

    private:
        BOOLEAN m_is_valid;

        btapi_de_t m_data_element;

        UINT16 m_number_of_data_elements;
};


BOOLEAN operator==(const BtSvrDataElement& left_value, const BtSvrDataElement& right_value);


BOOLEAN operator!=(const BtSvrDataElement& left_value, const BtSvrDataElement& right_value);

#endif  // BtDatatElements_hpp

