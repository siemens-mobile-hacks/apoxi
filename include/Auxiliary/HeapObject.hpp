/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HeapObject_hpp)
#define Apoxi_HeapObject_hpp

#include <Auxiliary/Macros.hpp>
#include <Auxiliary/NonCloneable.hpp>

template<class T> class HeapObject : public NonCloneable {
    public:
        inline HeapObject(T *data) : m_data(data) { }
        inline HeapObject() : m_data(0) { }
        virtual inline ~HeapObject() { delete m_data; }

        inline void Attach(T *data) { delete m_data; m_data = data; };

        inline T* operator()() const { return m_data; }

    private:
        T *m_data;
};

template<class T> class HeapArrayObject {
    public:
        inline HeapArrayObject(T *data) : m_data(data) { }
        inline HeapArrayObject() : m_data(0) { }
        inline ~HeapArrayObject() { delete [] m_data; }

        inline void Attach(T * data) { delete [] m_data; m_data = data; };

        inline T* operator()() const { return m_data; }

    private:
        T *m_data;

        inline HeapArrayObject(const HeapObject<T> &heap_object) { ASSERT_DEBUG(FALSE); };
        inline HeapArrayObject& operator=(const HeapObject<T> &heap_object) { ASSERT_DEBUG(FALSE); return *this; };
};

#endif  // Apoxi_HeapObject_hpp


