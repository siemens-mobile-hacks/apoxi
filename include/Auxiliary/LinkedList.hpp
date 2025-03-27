/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_LinkedList_hpp)
#define Apoxi_LinkedList_hpp

#include <Kernel/Types.hpp>

class LinkableBase;

/*  ------------------------------------------------------------------------
                                    LinkedList
    ------------------------------------------------------------------------ */

class LinkedListBase {
    public:
        LinkedListBase(LinkableBase *elem = 0);

        BOOLEAN IsEmpty() const {
            return m_anchor == 0;
        }

        INT GetSize() const;

        LinkableBase* GetFront() const {
            return m_anchor;
        }

        void PushFront(LinkableBase *elem);

        void PopFront();

        LinkableBase* GetBack() const;

        void PushBack(LinkableBase *elem);

        void PopBack();

        void Remove(LinkableBase *elem);

        void Insert(LinkableBase *elem, LinkableBase *after = 0);

        BOOLEAN Contains(LinkableBase *elem) const;

    protected:
        LinkableBase *m_anchor;
};

template<class T> class LinkedList : public LinkedListBase {
    typedef LinkedListBase Base;

    public:
        LinkedList(T *elem) : Base(elem) {}
        LinkedList() : Base(0) {}

        T* GetFront() const {
            return (T*)Base::GetFront();
        }
};


/*  ------------------------------------------------------------------------
                                SortedLinkedList
    ------------------------------------------------------------------------ */
class SortedLinkedListBase : private LinkedListBase {
    typedef LinkedListBase Base;

    public:
        using Base::IsEmpty;
        using Base::GetSize;
        using Base::Remove;
        using Base::PopFront;
        using Base::GetFront;
        using Base::Contains;

    protected:
        using Base::PushFront;
};

template<class T> class SortedLinkedList : public SortedLinkedListBase {
    typedef SortedLinkedListBase Base;

    public:
        T* GetFront() const {
            return (T*)Base::GetFront();
        }


        void Insert(T *elem);
};



/*  ------------------------------------------------------------------------
    Insert
    ------------------------------------------------------------------------ */
template<class T> void SortedLinkedList<T>::Insert(T *elem) 
{
    T *t = (T*)GetFront();
    T *prev = 0;

    while(t != 0 && *t < *elem) {
        prev = t;
        t = (T*)t->GetNext();
    }

    if (GetFront() == 0 || prev == 0)
        PushFront(elem);
    else {
        prev->SetNext(elem);
        elem->SetNext(t);
    }
}   // Insert

#endif  // Apoxi_LinkedList_hpp


