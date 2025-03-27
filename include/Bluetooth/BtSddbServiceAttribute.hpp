/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbServiceAttribute_hpp)
#define BtSddbServiceAttribute_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtSddbDataElements.hpp>


/*  ------------------------------------------------------------------------
    forward declartion
    ------------------------------------------------------------------------ */
class BtSddbServiceRecord;

class BtSddbServiceAttribute
{
    public:
        BtSddbServiceAttribute();

        BtSddbServiceAttribute(UINT16 attribute_id, const BtSddbDataElement& data_delement);

        BtSddbServiceAttribute(const BtSddbServiceAttribute& service_attribute);

        virtual ~BtSddbServiceAttribute();


        BOOLEAN IsValid() const;


        UINT16 GetAttributeId() const;


        void SetAttributeId(UINT16 attribute_id);


        BtSddbDataElement* GetAttributeValue();


        const BtSddbDataElement* GetAttributeValue() const;


        BOOLEAN SetAttributeValue(const BtSddbDataElement& attribute_value);

    protected:

        UINT32 GetMemorySize() const;


        BOOLEAN ReadFromMemory(const void*& memory, INT32& memory_size);


        void* WriteToMemory(void* memory) const;

    private:
        BOOLEAN m_is_valid;

        UINT16 m_attribute_id;

        BtSddbDataElement* m_attribute_value;

    private:
        friend class BtSddbServiceRecord;
};

#endif  // BtSddbServiceAttribute_hpp

