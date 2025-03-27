/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SharedPtr_hpp)
#define Apoxi_SharedPtr_hpp

#include <Auxiliary/Linkable.hpp>

template< typename T_obj >
class SharedPtr : public Linkable< SharedPtr<T_obj> >
{
public:
    SharedPtr();

    explicit SharedPtr(T_obj* pobj);

    SharedPtr(const SharedPtr<T_obj>& src);

    //template <typename T_CastFrom>
    //inline SharedPtr(const SharedPtr<T_CastFrom>& src);

    SharedPtr& operator=(const SharedPtr<T_obj>& src);

    //template <class T_CastFrom>
    //SharedPtr<T_obj>& operator=(const SharedPtr<T_CastFrom>& src);

    virtual ~SharedPtr();

    bool operator==(const SharedPtr<T_obj>& src) const;

    bool operator!=(const SharedPtr<T_obj>& src) const;

    virtual void Clear();


    inline T_obj& operator*();

    inline const T_obj& operator*() const;

    inline T_obj* operator->() const;

    inline operator bool() const;



protected:

    inline void Ref();
    inline void Unref();

    mutable T_obj* m_pobj; //The underlying instance. Derived from ReferableObject.
};

template< typename T_obj >
SharedPtr<T_obj>::SharedPtr()
: m_pobj(0)
{
}

template< typename T_obj >
SharedPtr<T_obj>::SharedPtr(T_obj* pobj)
: m_pobj(0)
{
    if(pobj)
    {
        //Copy it:
        m_pobj = pobj;

        //Start reference counting:
        Ref();
    }
}

template< typename T_obj >
SharedPtr<T_obj>::SharedPtr(const SharedPtr<T_obj>& src)
{
        m_pobj = src.m_pobj;

        Ref();
}


template< typename T_obj >
SharedPtr<T_obj>& SharedPtr<T_obj>::operator=(const SharedPtr<T_obj>& src)
{
    if(&src != this)
    {
        //Unref any existing stuff.
        //operator= can never run before a constructor, so these values will be initialized already.
        if(m_pobj) //The if() might not be required.
        {
            Unref(); //Could cause a deallocation.
        }

        //Copy:
        m_pobj = src.m_pobj;

        Ref();
    }

    return *this;
}


template< typename T_obj >
SharedPtr<T_obj>::~SharedPtr()
{
     Unref();
}

template< typename T_obj >
bool SharedPtr<T_obj>::operator==(const SharedPtr<T_obj>& src) const
{
    return m_pobj == src.m_pobj;
}

template< typename T_obj >
bool SharedPtr<T_obj>::operator!=(const SharedPtr<T_obj>& src) const
{
    return !operator==(src);
}

template< typename T_obj >
void SharedPtr<T_obj>::Clear()
{
    //Forget any previous instance:
    //This will not affect any other SharedPtr that happens to contain the same underlying instance,
    if(m_pobj)
    {
        Unref();
        m_pobj = 0;
    }
}

template< typename T_obj >
inline
T_obj& SharedPtr<T_obj>::operator*()
{
    return *m_pobj;
}

template< typename T_obj >
inline
const T_obj& SharedPtr<T_obj>::operator*() const
{
    ASSERT(m_pobj != 0);
    return *m_pobj;
}

template< typename T_obj >
inline
T_obj* SharedPtr<T_obj>::operator->() const
{
    return m_pobj;
}

template <class T_obj >
inline
SharedPtr<T_obj>::operator bool() const
{
    return (m_pobj != 0);
}


template <class T_obj >
inline
void SharedPtr<T_obj>::Ref()
{
    if(m_pobj)
        m_pobj->AddRef(); //This is really a "Reference".
}

template <class T_obj >
inline
void SharedPtr<T_obj>::Unref()
{
    if(m_pobj)
        m_pobj->Release(); //This is really an "Un-reference".
}

#endif  // Apoxi_SharedPtr_hpp

