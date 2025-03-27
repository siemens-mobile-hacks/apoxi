/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_ElementList_hpp)
#define Auxiliary_ElementList_hpp

#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/Macros.hpp>

class ElementListBase : private LinkedListBase {
    typedef LinkedListBase Base;

    public:
        ElementListBase();
        virtual ~ElementListBase();

        using Base::GetSize;
        using Base::GetFront;
        using Base::IsEmpty;

        LinkableBase* GetAt(INT idx) const;

        const LinkableBase& operator [](INT i) const;
        LinkableBase& operator [](INT i);

    protected:
        using Base::PushFront;
        using Base::PopFront;
        using Base::PushBack;
        using Base::Remove;
        
    private:
};

template<class T> class ElementList : public ElementListBase {
    typedef ElementListBase Base;

    public:
        ElementList();
        ElementList(const ElementList<T> &list);
        virtual ~ElementList();

        using Base::IsEmpty;

        void Append(T *entry);
        void Append(const T &entry) { Append((T*)&entry); }

        BOOLEAN AppendDistinct(T *entry);
        BOOLEAN AppendDistinct(const T &entry) { return (AppendDistinct((T*)&entry)); }

        BOOLEAN Exists(T *entry) const;
        BOOLEAN Exists(const T &entry) const { return (Exists((T*)&entry)); }

        INT Remove(T *entry);
        INT Remove(const T &entry) { return (Remove((T*)&entry)); }

        void Clear();

        T* GetFront() const { return (T*)Base::GetFront(); }

        T* GetAt(INT idx) const {return (T*)Base::GetAt(idx); }

        ElementList& operator =(const ElementList<T> &list);

        const T& operator [](INT i) const { return (const T&)Base::operator[](i); }
        T& operator [](INT i) { return (T&)Base::operator[](i); }
};

/*  ========================================================================
    SortedElementList
    ======================================================================== */
template<class T> class SortedElementList : private ElementList<T> {
    typedef ElementList<T> Base;

    public:
        SortedElementList();
        SortedElementList(const SortedElementList<T> &list);

        using Base::GetSize;
        using Base::Clear;

        T* GetFront() const {
            return (T*)Base::GetFront();
        }

        T* GetAt(INT idx) const {
            return (T*)Base::GetAt(idx);
        }
        void Insert(T *entry);
        void Insert(const T &entry) { Insert((T*) &entry); };

        SortedElementList& operator =(const SortedElementList<T> &list);
};

/*  ========================================================================
    ElementList template methods
    ======================================================================== */
/*  ------------------------------------------------------------------------
    ElementList
    ------------------------------------------------------------------------ */
template <class T> ElementList<T>::ElementList()
{
}   // ElementList

/*  ------------------------------------------------------------------------
    ElementList
    ------------------------------------------------------------------------ */
template <class T> ElementList<T>::ElementList(const ElementList<T> &list)
{
    *this = list;
}   // ElementList

/*  ------------------------------------------------------------------------
    ElementList
    ------------------------------------------------------------------------ */
template <class T> ElementList<T>::~ElementList()
{
    Clear();
}   // ElementList

/*  ------------------------------------------------------------------------
    Insert
    ------------------------------------------------------------------------ */
template <class T> void ElementList<T>::Append(T *entry)
{
    T *new_entry = new T(*entry);
    new_entry->SetNext(0);
    PushBack(new_entry);
}   // Insert

/*  ------------------------------------------------------------------------
    AppendDistinct
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN ElementList<T>::AppendDistinct(T *entry)
{
    BOOLEAN add_entry = !Exists(entry);
    if (add_entry) {
        T *new_entry = new T(*entry);
        new_entry->SetNext(0);
        PushBack(new_entry);
    } // if
    return (add_entry);
}   // AppendDistinct

/*  ------------------------------------------------------------------------
    Exists
    ------------------------------------------------------------------------ */
template<class T> BOOLEAN ElementList<T>::Exists(T *entry) const
{
    BOOLEAN exists = FALSE;
    if (entry != 0) {
        T *list_entry = (T*)GetFront();
        while (list_entry != 0 && !exists) {
            exists = (*entry == *list_entry);
            list_entry = list_entry->GetNext();
        } // while
    } // if
    return (exists);
}   // Exists

/*  ------------------------------------------------------------------------
    Remove
    ------------------------------------------------------------------------ */
template<class T> INT ElementList<T>::Remove(T *entry) 
{
    BOOLEAN removed_entries = 0;
    if (entry != 0) {
        T *list_entry = (T*)GetFront();
        T *next_list_entry = 0;
        while (list_entry != 0) {
            next_list_entry = list_entry->GetNext();
            if (*entry == *list_entry) {
                removed_entries++;
                Base::Remove(list_entry);
                SaveDelete(list_entry);
            }
            list_entry = next_list_entry;
        } // while
    } // if
    return (removed_entries);
}   // Remove

/*  ------------------------------------------------------------------------
    Clear
    ------------------------------------------------------------------------ */
template<class T> void ElementList<T>::Clear()
{
    // clean up existing plmn list
    T *entry;
    while (!IsEmpty()) {
        entry = GetFront();
        PopFront();
        SaveDelete(entry);
    } // end while
}   // Clear

/*  ------------------------------------------------------------------------
    operator =
    ------------------------------------------------------------------------ */
template <class T> ElementList<T>& ElementList<T>::operator =(const ElementList<T> &list)
{
    if (&list != this) {        // guard from self assignment
        Clear();
        // assign new plmn list
        T *entry = list.GetFront();
        while (entry != 0) {
            Append(entry);
            entry = entry->GetNext();
        } // while
    } // if
    return (*this);
}   // operator =

/*  ========================================================================
    SortedElementList template methods
    ======================================================================== */
/*  ------------------------------------------------------------------------
    SortedElementList
    ------------------------------------------------------------------------ */
template<class T> SortedElementList<T>::SortedElementList()
{
}   // SortedElementListBase

/*  ------------------------------------------------------------------------
    SortedElementList
    ------------------------------------------------------------------------ */
template<class T> SortedElementList<T>::SortedElementList(const SortedElementList<T> &list)
{
    *this = list;
}   // SortedElementList

/*  ------------------------------------------------------------------------
    ~SortedElementList
    ------------------------------------------------------------------------ */
/*template<class T> SortedElementList<T>::~SortedElementList()
{
    Clear();
}   // ~SortedElementList
*/
/*  ------------------------------------------------------------------------
    Insert
    ------------------------------------------------------------------------ */
template<class T> void SortedElementList<T>::Insert(T *entry)
{
    T *new_entry = new T;
    *new_entry = *entry;
    new_entry->SetNext(0);

    T *t = (T*)GetFront();
    T *prev = 0;

    while(t != 0 && *t < *new_entry) {
        prev = t;
        t = (T*)t->GetNext();
    }

    if (GetFront() == 0 || prev == 0)
        this->PushFront(new_entry);
    else {
        prev->SetNext(new_entry);
        new_entry->SetNext(t);
    }
}   // Insert

/*  ------------------------------------------------------------------------
    GetAt
    ------------------------------------------------------------------------ */
/*template<class T> T* SortedElementList<T>::GetAt(INT idx) const
{
    T *entry = m_list.GetFront();
    INT count = 0;
    while (entry != 0 && count != idx) {
        count++;
        entry = entry->GetNext();
    } // while
    return entry;
}   // GetAt
*/
/*  ------------------------------------------------------------------------
    operator []
    ------------------------------------------------------------------------ */
/*template<class T> const T& SortedElementList<T>::operator [](INT i) const
{
    T *elem = GetAt(i);
    ASSERT (elem != 0);
    return (*elem);
}   // operator []
*/
/*  ------------------------------------------------------------------------
    operator =
    ------------------------------------------------------------------------ */
template<class T> SortedElementList<T>& SortedElementList<T>::operator =(const SortedElementList<T> &list)
{
    if (&list != this) {        // guard from self assignment
        Clear();
        // assign new plmn list
        T *entry = list.GetFront();
        while (entry != 0) {
            Insert(entry);
            entry = entry->GetNext();
        } // while
    } // if
    return (*this);
}   // operator =

#endif  // Auxiliary_ElementList_hpp

