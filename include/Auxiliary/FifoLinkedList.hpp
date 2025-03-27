/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_FifoLinkedList_hpp)
#define Apoxi_FifoLinkedList_hpp

#include <Auxiliary/LinkedList.hpp>

template<class T> class FifoLinkedList : private LinkedList<T> {
    typedef LinkedList<T> Base; 
    public:
        inline FifoLinkedList() : m_back(0) { }

        inline void Push(T *elem) {
            if (m_back != 0) {
                m_back->SetNext(elem);
                elem->SetNext(0);
            }
            else
                LinkedListBase::PushFront(elem);
            m_back = elem;
        }

        inline void Pop() {
            LinkedListBase::PopFront();
            if (LinkedListBase::m_anchor == 0)
                m_back = 0;
        }

        inline void Remove(T *elem) {
            Base::Remove(elem);
            if (elem == m_back) {
                m_back = (T *) Base::GetBack();
            } // if
        }

        using LinkedList<T>::GetFront;
        using LinkedList<T>::IsEmpty;
    private:
        T *m_back;
};


#endif  // Apoxi_FifoLinkedList_hpp


