/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceListIterator_hpp)
#define BtDeviceListIterator_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtDeviceList.hpp>

class BtDeviceListConstantIterator: public BtDeviceList::BtDeviceListBidirectionalIterator
{
    private:
        typedef BtDeviceList::BtDeviceListBidirectionalIterator Base;
        
        friend class BtDeviceListConstantReverseIterator;
        friend class BtDeviceList;

    public:
        BtDeviceListConstantIterator();

        explicit BtDeviceListConstantIterator(const BtDeviceListConstantReverseIterator& device_list_constant_reverse_iterator);


        const BtDevice& operator*() const;


        const BtDevice* operator->() const;


        BtDeviceListConstantIterator& operator++();


        BtDeviceListConstantIterator operator++(int);


        BtDeviceListConstantIterator& operator--();


        BtDeviceListConstantIterator operator--(int);


        BOOLEAN operator==(const BtDeviceListConstantIterator& device_list_constant_iterator) const;


        BOOLEAN operator!=(const BtDeviceListConstantIterator& device_list_constant_iterator) const;


        BOOLEAN operator==(const BtDeviceListConstantReverseIterator& device_list_constant_reverse_iterator) const;


        BOOLEAN operator!=(const BtDeviceListConstantReverseIterator& device_list_constant_reverse_iterator) const;

    protected:
        explicit BtDeviceListConstantIterator(BtDeviceList::BtDeviceListNode* device_list_node);
};

class BtDeviceListIterator : public BtDeviceListConstantIterator
{
    private:
        typedef BtDeviceListConstantIterator Base;

        friend class BtDeviceListReverseIteator;
        friend class BtDeviceList;

    public:
        BtDeviceListIterator();

        explicit BtDeviceListIterator(const BtDeviceListReverseIterator& device_list_reverse_iterator);


        BtDevice& operator*();


        BtDevice* operator->();


        BtDeviceListIterator& operator++();


        BtDeviceListIterator operator++(int);


        BtDeviceListIterator& operator--();


        BtDeviceListIterator operator--(int);

    protected:
        explicit BtDeviceListIterator(BtDeviceList::BtDeviceListNode* device_list_node);
};

#endif  // BtDeviceListIterator_hpp


