/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SimpleMap_hpp)
#define Apoxi_SimpleMap_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/NonCloneable.hpp>
#include <Auxiliary/Macros.hpp>

// Forward declaration.
template <class TKey, class TValue> class SimpleMap;

template <class TKey, class TValue>
class SimpleMapElem : public Linkable<SimpleMapElem<TKey, TValue> >
{
    typedef Linkable<SimpleMapElem<TKey, TValue> > Base;

    public:
        SimpleMapElem(const TKey &key, const TValue &value) :
          m_key(key), m_value(value)
        {}

        TKey& GetKey()
            { return m_key; }

        TValue& GetValue()
            { return m_value; }

    private:
        TKey m_key;
        TValue m_value;

        friend class SimpleMap<TKey, TValue>;
};

template <class TKey, class TValue>
class SimpleMap : public NonCloneable
{
    public:
        typedef SimpleMapElem<TKey, TValue> Pair;

    public:
        class Iterator
        {
            protected:
                Iterator(const SimpleMap &map) :
                    m_map(map),
                    m_cur_elem(map.m_head)
                {}

            public:
                BOOLEAN IsValid() const
                    { return m_cur_elem != 0; }

                Pair& GetPair() const
                    {
                        ASSERT_DEBUG(m_cur_elem != 0);
                        return *m_cur_elem;
                    }

                void Increment()
                    {
                        ASSERT_DEBUG(m_cur_elem != 0);
                        m_cur_elem = m_cur_elem->GetNext();
                    }

            private:
                const SimpleMap &m_map;
                Pair *m_cur_elem;

                friend class SimpleMap<TKey, TValue>;
        };

    public:
        SimpleMap();

        virtual ~SimpleMap();

        TValue& operator[](const TKey &key);

        const TValue& operator[](const TKey &key) const;

        BOOLEAN Exists(const TKey &key) const;

        BOOLEAN Remove(const TKey &key);

        void RemoveAll();

        BOOLEAN Ok() const
            { return m_ok; }

        UINT GetSize() const;

        Iterator GetIterator() const;

        BOOLEAN GetValue(const TKey &key, TValue &value) const;

    private:
        mutable BOOLEAN m_ok;

        Pair *m_head;

        friend class Iterator;
};

template <class TKey, class TValue>
SimpleMap<TKey, TValue>::SimpleMap() :
    m_ok(TRUE),
    m_head(0)
{
}

template <class TKey, class TValue>
SimpleMap<TKey, TValue>::~SimpleMap()
{
    while (m_head != 0) {
        Pair *next = m_head->GetNext();
        delete m_head;
        m_head = next;
    }
}

template <class TKey, class TValue>
TValue& SimpleMap<TKey, TValue>::operator[](const TKey &key)
{
    // Static value which is returned on out of memory error.
    static TValue s_err_val = TValue();

    m_ok = TRUE;

    // Search for an existing element for key.
    Pair *list = m_head;
    while (list != 0) {
        if (list->m_key == key) {
            return list->m_value;
        }
        list = list->GetNext();
    }

    // Insert new element for key at head.
    Pair *new_elem = new Pair(key, TValue());

    if (new_elem == 0) {
        m_ok = FALSE;
        return s_err_val;
    }

    new_elem->SetNext(m_head);
    m_head = new_elem;

    return m_head->m_value;
}

template <class TKey, class TValue>
const TValue& SimpleMap<TKey, TValue>::operator[](const TKey &key) const
{
    // Static value which is returned on out of memory error.
    static TValue s_err_val = TValue();

    m_ok = TRUE;

    // Search for an existing element for key.
    Pair *list = m_head;
    while (list != 0) {
        if (list->m_key == key) {
            return list->m_value;
        }
        list = list->GetNext();
    }

    m_ok = FALSE;

    return s_err_val;
}

template <class TKey, class TValue>
BOOLEAN SimpleMap<TKey, TValue>::Exists(const TKey &key) const
{
    Pair *list = m_head;
    while (list != 0) {
        if (list->m_key == key) {
            return TRUE;
        }
        list = list->GetNext();
    }

    return FALSE;
}

template <class TKey, class TValue>
BOOLEAN SimpleMap<TKey, TValue>::Remove(const TKey &key)
{
    Pair *list = m_head, *prev = 0;
    while (list != 0) {
        if (list->m_key == key) {
            if (prev == 0) {
                m_head = list->GetNext();
            }
            else {
                prev->SetNext(list->GetNext());
            }
            delete list;
            return TRUE;
        }
        prev = list;
        list = list->GetNext();
    }

    return FALSE;
}

template <class TKey, class TValue>
void SimpleMap<TKey, TValue>::RemoveAll()
{
    while (m_head != 0) {
        Pair *next = m_head->GetNext();
        delete m_head;
        m_head = next;
    }
}

template <class TKey, class TValue>
UINT SimpleMap<TKey, TValue>::GetSize() const
{
    UINT size = 0;
    Pair *list = m_head;
    while (list != 0) {
        size++;
        list = list->GetNext();
    }

    return size;
}

template <class TKey, class TValue>
typename SimpleMap<TKey, TValue>::Iterator
    SimpleMap<TKey, TValue>::GetIterator() const
{
    return SimpleMap<TKey, TValue>::Iterator(*this);
}

template <class TKey, class TValue>
BOOLEAN SimpleMap<TKey, TValue>::GetValue(const TKey &key, TValue &value) const
{
    value = operator[](key);
    return Ok();
}

#endif  // Apoxi_SimpleMap_hpp

