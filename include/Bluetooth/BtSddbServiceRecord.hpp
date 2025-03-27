/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbServiceRecord_hpp)
#define BtSddbServiceRecord_hpp

#include <Bluetooth/BtSddbServiceAttribute.hpp>

/*  ------------------------------------------------------------------------
    forward declartion
    ------------------------------------------------------------------------ */
class BtServiceDiscoveryDatabase;

class BtSddbServiceRecord
{
    public:
        BtSddbServiceRecord();

        virtual ~BtSddbServiceRecord();


        BOOLEAN IsValid() const;


        UINT16 GetNumberOfAttributes() const;


        BtSddbServiceAttribute* GetAttributeById(UINT16 service_attribute_id);


        const BtSddbServiceAttribute* GetAttributeById(UINT16 service_attribute_id) const;


        BtSddbServiceAttribute* GetFirstAttribute();


        const BtSddbServiceAttribute* GetFirstAttribute() const;


        BtSddbServiceAttribute* GetNextAttribute(const BtSddbServiceAttribute* current);


        const BtSddbServiceAttribute* GetNextAttribute(const BtSddbServiceAttribute* current) const;


        BOOLEAN Insert(const BtSddbServiceAttribute& service_attribute, const BtSddbServiceAttribute* position = 0);


        BtSddbServiceAttribute* Delete(BtSddbServiceAttribute* service_attribute);


        void Clear(void);


        BtSddbServiceRecord& operator=(const BtSddbServiceRecord& service_record);

    protected:
        UINT32 GetMemorySize() const;

        BOOLEAN ReadFromMemory(const void*& memory, INT32& memory_size);

        void* WriteToMemory(void* memory) const;

    private:
        class BtSddbServiceRecordNode
        {
            public:
                BtSddbServiceRecordNode(BtSddbServiceAttribute* service_attribute, BtSddbServiceRecordNode* next = 0);

                virtual ~BtSddbServiceRecordNode();

                BtSddbServiceAttribute* GetServiceAttribute();

                void SetServiceAttribute(BtSddbServiceAttribute* service_attribtue);

                BtSddbServiceRecordNode* GetNext();

                void SetNext(BtSddbServiceRecordNode* next);

            private:
                BtSddbServiceAttribute* m_service_attribute;

                BtSddbServiceRecordNode* m_next;
        };

    private:

        BtSddbServiceRecordNode* CreateNewServiceRecordNode(const BtSddbServiceAttribute* data_element);


        BtSddbServiceRecordNode* Search(const BtSddbServiceAttribute* service_attribute) const;

    private:
        BOOLEAN m_is_valid;

        BtSddbServiceRecordNode* m_anchor;

        INT16 m_number_of_attributes;

    private:
        friend class BtServiceDiscoveryDatabase;
};

#endif  // BtSddbServiceRecord_hpp

