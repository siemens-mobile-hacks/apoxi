/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceList_hpp)
#define BtDeviceList_hpp

#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtDeviceFilter.hpp>

/*  ------------------------------------------------------------------------
    forward declartion
    ------------------------------------------------------------------------ */
class BtGapAndSdapController;
class BtDeviceListConstantIterator;
class BtDeviceListIterator;
class BtDeviceListConstantReverseIterator;
class BtDeviceListReverseIterator;

class BtDeviceList
{
    public:

        explicit BtDeviceList(BOOLEAN do_refresh = FALSE, const BtDeviceFilter& device_filter = BtDeviceFilter());


        explicit BtDeviceList(const BtDeviceList& device_list, const BtDeviceFilter& device_filter = BtDeviceFilter());

        virtual ~BtDeviceList();


        BtDeviceListIterator Begin();


        BtDeviceListConstantIterator Begin() const;


        BtDeviceListIterator End();


        BtDeviceListConstantIterator End() const;


        BtDeviceListReverseIterator RBegin();


        BtDeviceListConstantReverseIterator RBegin() const;


        BtDeviceListReverseIterator REnd();


        BtDeviceListConstantReverseIterator REnd() const;


        UINT GetSize() const;


        BOOLEAN IsEmpty() const;


        BtDevice& Front();


        const BtDevice& Front() const;


        BtDevice& Back();


        const BtDevice& Back() const;


        void PushFront(const BtDevice& device);


        void PopFront();


        void PushBack(const BtDevice& device);


        void PopBack();


        BtDeviceListIterator Insert(BtDeviceListIterator iterator, const BtDevice& device);


        BtDeviceListIterator Erase(BtDeviceListIterator iterator);


        BtDeviceListIterator Erase(BtDeviceListIterator first, BtDeviceListIterator last);


        void Clear(void);


        void Remove(const BtDevice& device);


        BtDeviceListIterator Find(const BtDevice& device);


        BtDeviceListConstantIterator Find(const BtDevice& device) const;


        BtDeviceListIterator Find(const BtDeviceAddress& device_address);


        BtDeviceListConstantIterator Find(const BtDeviceAddress& device_address) const;


        void Refresh(const BtDeviceFilter& device_filter = BtDeviceFilter());


        void Filter(const BtDeviceFilter& device_filter);

    public:
        /*  BtDeviceListBidirectionalIterator is made public only because some 
            target compilers can not dervive classes from nested protected or 
            private classes. */
        class BtDeviceListBidirectionalIterator;

    protected:
        friend class BtGapAndSdapController;
        friend class BtDeviceListBidirectionalIterator;
        friend class BtDeviceListConstantIterator;
        friend class BtDeviceListIterator;
        friend class BtDeviceListConstantReverseIterator;
        friend class BtDeviceListReverseIterator;


        class BtDeviceListNode
        {
            public:
                BtDeviceListNode();

                virtual ~BtDeviceListNode();

            public:

                BtDeviceListNode* GetNext();


                const BtDeviceListNode* GetNext() const;


                void SetNext(BtDeviceListNode* next);


                BtDeviceListNode* GetPrevious();


                const BtDeviceListNode* GetPrevious() const;


                void SetPrevious(BtDeviceListNode* previous);


                BtDevice& GetDevice();


                const BtDevice& GetDevice() const;


                void SetDevice(const BtDevice& device);

            private:
                BtDeviceListNode* m_next;

                BtDeviceListNode* m_previous;

                BtDevice m_device;

            private:
                friend class BtDeviceListBidirectionalIterator;
        };

    public:
        /*  BtDeviceListBidirectionalIterator is made public only because some 
            target compilers can not dervive classes from nested protected or 
            private classes. */

        class BtDeviceListBidirectionalIterator
        {
            public:
                BtDeviceListBidirectionalIterator();
            
                explicit BtDeviceListBidirectionalIterator(const BtDeviceListBidirectionalIterator& bidirectional_iterator);

            protected:
                explicit BtDeviceListBidirectionalIterator(BtDeviceListNode* device_list_node);

            protected:

                BtDeviceListNode* GetDeviceListNode()
                    { return m_device_list_node; }


                const BtDeviceListNode* GetDeviceListNode() const
                    { return m_device_list_node; }


                void SetDeviceListNode(BtDeviceListNode* device_list_node);

            protected:
                BtDeviceListNode* m_device_list_node;
        };

    private:
        unsigned int m_size;


        BtDeviceListNode m_empty_node;


        BtDeviceListNode* m_anchor;
};

const BtDeviceList bt_c_empty_device_list;
#endif  // BtDeviceList_hpp


