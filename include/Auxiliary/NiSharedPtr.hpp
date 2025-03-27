/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NiSharedPtr_hpp)
#define Apoxi_NiSharedPtr_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>

#define NO_MEMBER_TEMPLATES

template <typename X>
class NiSharedPtr
{
public:
    explicit NiSharedPtr(X* p = 0) // Allocate a new item reference.
        : m_itemRef(0) { if (p) m_itemRef = new ItemRef(p); }

    ~NiSharedPtr();

    NiSharedPtr(const NiSharedPtr &r)
        { Acquire(r.m_itemRef); }

    NiSharedPtr& operator=(const NiSharedPtr &r);

#ifndef NO_MEMBER_TEMPLATES
    template <typename Y> friend class NiSharedPtr;
    template <typename Y> NiSharedPtr(const NiSharedPtr<Y>& r)
        { Acquire(r.m_itemRef); }
    template <typename Y> NiSharedPtr<X>& operator=(const NiSharedPtr<Y> &r);
#endif // NO_MEMBER_TEMPLATES

    X& operator*() const
    {
        ASSERT_DEBUG_HOST(m_itemRef && m_itemRef->m_ptr);
        return *m_itemRef->m_ptr;
    }

    X* operator->() const
    {
        ASSERT_DEBUG_HOST(m_itemRef && m_itemRef->m_ptr);
        return m_itemRef->m_ptr;
    }

    X* Get() const { return m_itemRef ? m_itemRef->m_ptr : 0; }

    BOOLEAN IsValid() const { return Get() != 0; }

    BOOLEAN Unique() const
        { return (m_itemRef ? m_itemRef->m_count == 1 : FALSE); }

    void Release()
    {   // Decrement the counter and delete the reference counted object if the
        // counter is 0.
        if (m_itemRef) {
            if (--m_itemRef->m_count == 0) {
                delete m_itemRef->m_ptr;
                delete m_itemRef;
            }
            m_itemRef = 0;
        }
    }

private:
    struct ItemRef {
        ItemRef(X *p = 0, UINT c = 1) : m_ptr(p), m_count(c) {}
        X *m_ptr;
        UINT m_count;
    } *m_itemRef;

    void Acquire(ItemRef *itemRef)
    {   // Increment the counter.
        m_itemRef = itemRef;
        if (itemRef) ++itemRef->m_count;
    }
};

template <typename X>
NiSharedPtr<X>::~NiSharedPtr()
{
    Release();
}

template <typename X>
NiSharedPtr<X>& NiSharedPtr<X>::operator=(const NiSharedPtr<X> &r)
{
    if (this != &r) {
        Release();
        Acquire(r.m_itemRef);
    }
    return *this;
}

#ifndef NO_MEMBER_TEMPLATES

template <typename X>
template <typename Y>
NiSharedPtr<X>& NiSharedPtr<X>::operator=(const NiSharedPtr<Y> &r)
{
    if (this != &r) {
        Release();
        Acquire(r.m_itemRef);
    }
    return *this;
}

#endif // NO_MEMBER_TEMPLATES

template<typename X, typename Y>
BOOLEAN operator==(const NiSharedPtr<X> &lhs, const NiSharedPtr<Y> &rhs)
{
    return lhs.Get() == rhs.Get();
}

template<typename X, typename Y>
BOOLEAN operator!=(const NiSharedPtr<X> &lhs, const NiSharedPtr<Y> &rhs)
{
    return lhs.Get() != rhs.Get();
}

#endif  // Apoxi_NiSharedPtr_hpp

