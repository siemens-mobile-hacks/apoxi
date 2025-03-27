/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceListReverseIterator_hpp)
#define BtDeviceListReverseIterator_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtDeviceList.hpp>

class BtDeviceListConstantReverseIterator : public BtDeviceList::BtDeviceListBidirectionalIterator
{
    private:
        typedef BtDeviceList::BtDeviceListBidirectionalIterator Base;

        friend class BtDeviceListConstantIterator;

    public:
        BtDeviceListConstantReverseIterator();

        explicit BtDeviceListConstantReverseIterator(const BtDeviceListConstantIterator& device_list_constant_iterator);


        const BtDevice& operator*() const;


        const BtDevice* operator->() const;


        BtDeviceListConstantReverseIterator& operator++();


        BtDeviceListConstantReverseIterator operator++(int);


        BtDeviceListConstantReverseIterator& operator--();


        BtDeviceListConstantReverseIterator operator--(int);


        BOOLEAN operator==(const BtDeviceListConstantReverseIterator& device_list_constant_reverse_iterator) const;


        BOOLEAN operator!=(const BtDeviceListConstantReverseIterator& device_list_constant_reverse_iterator) const;

    protected:
        explicit BtDeviceListConstantReverseIterator(BtDeviceList::BtDeviceListNode* device_list_node);
};

class BtDeviceListReverseIterator: public BtDeviceListConstantReverseIterator
{
    private:
        typedef BtDeviceListConstantReverseIterator Base;

    public:
        BtDeviceListReverseIterator();

        explicit BtDeviceListReverseIterator(const BtDeviceListIterator& device_list_iterator);


        BtDevice& operator*();


        BtDevice* operator->();


        BtDeviceListReverseIterator& operator++();


        BtDeviceListReverseIterator operator++(int);


        BtDeviceListReverseIterator& operator--();


        BtDeviceListReverseIterator operator--(int);

    protected:
        explicit BtDeviceListReverseIterator(BtDeviceList::BtDeviceListNode* device_list_node);
};

#endif  // BtDeviceListReverseIterator_hpp


