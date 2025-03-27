/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(_Apoxi_HashTable_hpp)
#define _Apoxi_HashTable_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>


typedef UINT16 HashKey;     // wide range key

class Hashable : public Linkable<Hashable> {
    public:
        Hashable(HashKey key = 0) : m_key(key) {}
        virtual HashKey GetKey() const { return m_key; }

    private:
        HashKey m_key;
};

class HashTable {
    public:
        HashTable(UINT16 init_size);
        virtual ~HashTable() { delete [] m_vector; }
        virtual INT GetSize() const { return m_size; }
        virtual BOOLEAN AddElem(Hashable *elem);
        virtual void RemoveElem(HashKey key);
        virtual Hashable* GetElem(HashKey key) const;

    protected:
        virtual HashKey Hash(HashKey key) const;

    private:
        const UINT16 m_size;
        LinkedList<Hashable> *m_vector;
};

#endif


