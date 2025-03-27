/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Vector_hpp)
#define Apoxi_Vector_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Allocator.hpp>
#include <Auxiliary/Macros.hpp>

template<typename T>
class Vector {
public:
    friend class Iterator;
    typedef INT DifferenceType;
    typedef T ValueType;
    typedef T& Reference;
    typedef const T& ConstReference;
    typedef INT SizeType;

    enum {
        c_increment = 5
    };

    class Iterator {
    protected:
        friend class Vector<T>;

        Vector<T> *owner;
        SizeType current;

        Iterator(Vector<T> *daddy, SizeType i) :
            owner(daddy), current(i) { }
        Iterator(const Vector<T> *daddy, SizeType i) :
            owner((Vector<T> *)daddy), current(i) { }

    public:
        Iterator& operator++(INT) {
            ++current;
            return(*this);
        }

        Iterator& operator--(INT) {
            --current;
            return(*this);
        }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER >= 1300))
        Iterator operator+(DifferenceType n) const;
#else
        Iterator operator+(DifferenceType n) const {
            Iterator i(*this);
            i.current += n;
            return(i);
        }
#endif

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER >= 1300))
        Iterator operator-(DifferenceType n) const;
#else
        Iterator operator-(DifferenceType n) const {
            Iterator i(*this);
            i.current -= n;
            return(i);
        }
#endif

        Reference operator*() { return(owner->operator[](current)); }

        ConstReference operator*() const
            { return(owner->operator[](current)); }

        BOOLEAN operator<(const Iterator &i) const
            { return(current < i.current); }

        BOOLEAN operator>(const Iterator &i) const
            { return(current > i.current); }

        BOOLEAN operator<=(const Iterator &i) const
            { return(current <= i.current); }

        BOOLEAN operator>=(const Iterator &i) const
            { return(current >= i.current); }

        BOOLEAN operator==(const Iterator &i) const
            { return(current == i.current && owner == i.owner); }

        BOOLEAN operator!=(const Iterator &i) const
            { return(!(*this == i)); }

        DifferenceType operator+(const Iterator &i)
            { return(current + i.current); }

        DifferenceType operator-(const Iterator &i)
            { return(current - i.current); }
    };

    typedef const Iterator ConstIterator;
    typedef Iterator ReverseIterator;
    typedef const Iterator ConstReverseIterator;

private:
    T *m_elem;
    SizeType m_nelem;
    SizeType m_capacity;
    Allocator<T> allocator;

    void Set(SizeType i, ConstReference x);

    void Copy(SizeType to, SizeType from) { Set(to, m_elem[from]); }

    void Construct(Reference elem, ConstReference x);
    void Destruct(Reference elem);

    void Resize(SizeType n) {
        for (SizeType i = 0; i < GetSize(); ++i)
            Destruct(m_elem[i]);

        if (Capacity() < n) {
            allocator.Free(m_elem);

            m_capacity = ((n - m_capacity) < c_increment) ?
                m_capacity + c_increment : n;

            m_elem = allocator.Alloc(m_capacity);

            ASSERT_DEBUG(m_elem != 0);
        }
    }

    void CheckFree(SizeType n) {
        if ((GetSize() + n) > Capacity())
            Reserve(GetSize() + n);
    }

    void CheckFree() {
        CheckFree(1);
    }

public:
    Vector(SizeType n, ConstReference value);

    Vector() : m_elem(0), m_nelem(0), m_capacity(0) { }

    Vector(SizeType n);

    Vector(const Vector<T> &x) : m_elem(0), m_nelem(0), m_capacity(0)
        { *this = x; }

    ~Vector();

    Iterator Begin() const { return(Iterator(this, 0)); }

    Iterator End() const { return(Iterator(this, m_nelem)); }

    ReverseIterator RBegin() const
        { return(ReverseIterator(this, m_nelem - 1)); }

    ReverseIterator REnd() const { return(ReverseIterator(this, -1)); }

    SizeType GetSize() const { return(m_nelem); }

    SizeType MaxSize() const { return(SizeType(UINT_MAX / sizeof(T))); }

    BOOLEAN IsEmpty() const { return m_nelem == 0; }

    Reference operator[](SizeType i) {
        ASSERT_DEBUG(i >= 0 && i < GetSize());
        return(m_elem[i]);
    }

    ConstReference operator[](SizeType i) const {
        ASSERT_DEBUG(i >= 0 && i < GetSize());
        return(m_elem[i]);
    }

    Reference Front() {
        ASSERT_DEBUG(GetSize() > 0);
        return(m_elem[0]);
    }

    ConstReference Front() const {
        ASSERT_DEBUG(GetSize() > 0);
        return(m_elem[0]);
    }

    Reference Back() {
        ASSERT_DEBUG(GetSize() > 0);
        return(m_elem[m_nelem - 1]);
    }

    ConstReference Back() const {
        ASSERT_DEBUG(GetSize() > 0);
        return(m_elem[m_nelem - 1]);
    }

    void PushBack(ConstReference x);

    void Insert(const Iterator &pos, ConstReference x);

    void Insert(const Iterator &pos) {
        Insert(pos, T());
    }

    void Insert(const Iterator &pos, SizeType n, ConstReference x);

    void PopBack();

    void Erase(const Iterator &pos);

    void Erase(const Iterator &first, const Iterator &last);

    void Reserve(SizeType n);

    SizeType Capacity() const { return m_capacity; }

    Vector<T>& operator=(const Vector<T> &from);
};

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER >= 1300))
template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(
    typename Vector<T>::DifferenceType n) const
{
    Iterator i(*this);
    i.current += n;
    return(i);
}
#endif

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER >= 1300))
template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(
    typename Vector<T>::DifferenceType n) const
{
    Iterator i(*this);
    i.current -= n;
    return(i);
}
#endif

template<typename T>
void Vector<T>::Set(SizeType i, ConstReference x)
{
    if (i < GetSize())
        operator[](i) = x;
    else
        Construct(m_elem[i], x);
}

template<typename T>
void Vector<T>::Construct(Reference elem, ConstReference x)
{
    allocator.Construct(&elem, x);
}

template<typename T>
void Vector<T>::Destruct(Reference elem)
{
    allocator.Destruct(&elem);
}

template<typename T>
Vector<T>::Vector(SizeType n, ConstReference value) :
    m_elem(0),
    m_nelem(0),
    m_capacity(0)
{
    if (n > 0) {
        Reserve(n);
        Insert(Begin(), n, value);
    }
}

template<typename T>
Vector<T>::Vector(SizeType n) :
    m_elem(0),
    m_nelem(0),
    m_capacity(0)
{
    if (n > 0) {
        Reserve(n);
        Insert(Begin(), n, T());
    }
}

template<typename T>
Vector<T>::~Vector()
{
    for (SizeType i = 0; i < GetSize(); ++i)
        Destruct(m_elem[i]);
    allocator.Free(m_elem);
}

template<typename T>
void Vector<T>::PushBack(ConstReference x)
{
    CheckFree();
    Construct(m_elem[m_nelem], x);
    ++m_nelem;
}

template<typename T>
void Vector<T>::Insert(const Iterator &pos, ConstReference x)
{
    SizeType p;

    p = pos.current;
    if (p >= GetSize())
        PushBack(x);
    else {
        Reserve(GetSize() + 1);

        SizeType i = GetSize();

        while (i > p) {
            Copy(i, i - 1);
            --i;
        }
        Set(i, x);
        ++m_nelem;
    }
}

template<typename T>
void Vector<T>::Insert(const Iterator &pos, SizeType n, ConstReference x)
{
    if (n == 0)
        return;

    Reserve(GetSize() + n);
    SizeType p;

    p = pos.current;
    if (p < GetSize()) {
        SizeType i(m_nelem + n - 1);
        SizeType j(m_nelem - 1);

        while (j >= p)
            Copy(i--, j--);
    }
    for (SizeType i = 0; i < n; ++i) {
        Set(p, x);
        ++p;
    }
    m_nelem += n;
}

template<typename T>
void Vector<T>::PopBack()
{
    ASSERT_DEBUG(GetSize() > 0);

    Destruct(Back());
    --m_nelem;
}

template<typename T>
void Vector<T>::Erase(const Iterator &pos)
{
    if (GetSize() <= 0 || pos.current >= GetSize())
        return;

    SizeType i = pos.current;
    while (i < GetSize() - 1) {
        Copy(i, i + 1);
        ++i;
    }
    Destruct(Back());
    --m_nelem;
}

template<typename T>
void Vector<T>::Erase(const Iterator &first, const Iterator &last)
{
    if (last <= first)
        return;

    SizeType ifirst = first.current;
    SizeType ilast = last.current;

    while (ilast < GetSize())
        Copy(ifirst++, ilast++);

    SizeType nelem = ilast - ifirst;
    while (ifirst < GetSize()) {
        Destruct(m_elem[ifirst]);
        ++ifirst;
    }
    m_nelem -= nelem;
}

template<typename T>
void Vector<T>::Reserve(SizeType n)
{
    if (Capacity() >= n)
        return;

    SizeType as = ((n - m_capacity) < c_increment) ? m_capacity + c_increment : n;

    T *tmp = allocator.Alloc(as);
    ASSERT_DEBUG(tmp != 0);

    for (SizeType i = 0; i < m_nelem; ++i) {
        Construct(tmp[i], m_elem[i]);
        Destruct(m_elem[i]);
    }

    m_capacity = as;
    allocator.Free(m_elem);
    m_elem = tmp;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &from)
{
    if (&from == this)
        return(*this);

    Resize(from.GetSize());
    m_nelem = 0;
    for (SizeType i = 0; i < from.GetSize(); ++i)
        Construct(m_elem[i], from[i]);

    m_nelem = from.GetSize();
    return(*this);
}

#endif  // Apoxi_Vector_hpp

