/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzUtils_hpp)
#define EmzUtils_hpp

#include <Kernel/Types.hpp>

class EmzUtils {
    public:

    template<class T> class Queue {

        public:
            Queue();
            Queue(UINT32 max_num_of_elems);
            ~Queue();
            BOOLEAN Init(UINT32 max_num_of_elems);
            BOOLEAN Reset();
            BOOLEAN PopAll();
            UINT32 GetCurrentNumberOfElements() const;
            UINT32 GetMaxNumberOfElements() const;
            BOOLEAN PushBack(T& elem);
            BOOLEAN PushFront(T& elem);
            BOOLEAN PopBack();
            BOOLEAN PopFront();
            T* GetFront() const;
            T* GetBack() const;

        private:
            UINT32 m_max_num_of_elems;
            UINT32 m_curr_num_of_elems;
            UINT32 m_curr_pos;
            T** m_queue;
    }; // class Queue

}; // class EmzUtils

// Template and inline functions

/*  ------------------------------------------------------------------------
    Queue
    ------------------------------------------------------------------------ */
template<class T> EmzUtils::Queue<T>::Queue():
    m_max_num_of_elems(0),
    m_curr_num_of_elems(0),
    m_curr_pos(0),
    m_queue(0)
{
} // Queue

/*  ------------------------------------------------------------------------
    Queue
    ------------------------------------------------------------------------ */
template<class T> EmzUtils::Queue<T>::Queue(UINT32 max_num_of_elems):
    m_max_num_of_elems(0),
    m_curr_num_of_elems(0),
    m_curr_pos(0),
    m_queue(0)
{
    Init(max_num_of_elems);
} // Queue

/*  ------------------------------------------------------------------------
    ~Queue
    ------------------------------------------------------------------------ */
template<class T> EmzUtils::Queue<T>::~Queue()
{
    Reset();
} // ~Queue

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::Init(UINT32 max_num_of_elems)
{
    Reset();
    m_queue = new T*[max_num_of_elems];
    if (!m_queue)
        return FALSE;
    UINT32 i;
    for (i = 0; i < max_num_of_elems; i++) {
        m_queue[i] = 0;
    }
    for (i = 0; i < max_num_of_elems; i++) {
        m_queue[i] = new T;
        if (!m_queue[i]) {
            Reset();
            return FALSE;
        }
    }
    m_max_num_of_elems = max_num_of_elems;
    return TRUE;
} // Init

/*  ------------------------------------------------------------------------
    Reset
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::Reset()
{
    if (!m_queue)
        return TRUE;
    for (UINT32 i = 0; i < m_max_num_of_elems; i++) {
        delete m_queue[i];
        m_queue[i] = 0;
    }
    m_max_num_of_elems = 0;
    m_curr_num_of_elems = 0;
    m_curr_pos = 0;
    delete [] m_queue;
    m_queue = 0;
    return TRUE;
} // Reset

/*  ------------------------------------------------------------------------
    PopAll
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::PopAll()
{
    m_curr_num_of_elems = 0;
    m_curr_pos = 0;
    return TRUE;
} // PopAll

/*  ------------------------------------------------------------------------
    GetCurrentNumberOfElements
    ------------------------------------------------------------------------ */
template<class T> UINT32 EmzUtils::Queue<T>::GetCurrentNumberOfElements() const
{
    return m_curr_num_of_elems;
} // GetCurrentNumberOfElements

/*  ------------------------------------------------------------------------
    GetMaxNumberOfElements
    ------------------------------------------------------------------------ */
template<class T> UINT32 EmzUtils::Queue<T>::GetMaxNumberOfElements() const
{
    return m_max_num_of_elems;
} // GetMaxNumberOfElements

/*  ------------------------------------------------------------------------
    PushBack
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::PushBack(T& elem)
{
    if (m_curr_num_of_elems >= m_max_num_of_elems)
        return FALSE;
    *m_queue[(m_curr_pos + m_curr_num_of_elems) % m_max_num_of_elems] = elem;
    m_curr_num_of_elems++;
    return TRUE;
} // PushBack

/*  ------------------------------------------------------------------------
    PushFront
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::PushFront(T& elem)
{
    if (m_curr_num_of_elems >= m_max_num_of_elems)
        return FALSE;
    if (m_curr_num_of_elems > 0)
            m_curr_pos = (m_curr_pos + m_max_num_of_elems - 1) % m_max_num_of_elems;
    *m_queue[m_curr_pos] = elem;
    m_curr_num_of_elems++;
    return TRUE;
} // PushFront

/*  ------------------------------------------------------------------------
    PopBack
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::PopBack()
{
    if (m_curr_num_of_elems == 0)
        return TRUE;
    m_curr_num_of_elems--;
    return TRUE;
} // PopBack

/*  ------------------------------------------------------------------------
    PopFront
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN EmzUtils::Queue<T>::PopFront()
{
    if (m_curr_num_of_elems == 0)
        return TRUE;
    m_curr_pos = (m_curr_pos + 1) % m_max_num_of_elems;
    m_curr_num_of_elems--;
    return TRUE;
} // PopFront

/*  ------------------------------------------------------------------------
    GetFront
    ------------------------------------------------------------------------ */
template<class T> T* EmzUtils::Queue<T>::GetFront() const
{
    if (m_curr_num_of_elems == 0) {
        return 0;
    }
    return m_queue[m_curr_pos];
} // GetFront

/*  ------------------------------------------------------------------------
    GetBack
    ------------------------------------------------------------------------ */
template<class T> T* EmzUtils::Queue<T>::GetBack() const
{
    if (m_curr_num_of_elems == 0) {
        return 0;
    }
    return m_queue[(m_curr_pos + m_curr_num_of_elems - 1) % m_max_num_of_elems];
} // GetBack

#endif // EmzUtils_hpp

