//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Auxiliary_Map_hpp)
#define Auxiliary_Map_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Auxiliary/Vector.hpp>

template <class T1, class T2> 
class Map 
{


    public:
        
        class Pair 
        {
            public:
                Pair(): First(), Second()  {;}
                Pair(const T1& k ,const T2& v): First(k), Second(v) {;}
                
                
                T1 First;
                T2 Second; 
        }; 

    private:
        typedef Vector<Pair> VectorType;
        VectorType  m_vec;

        
    public:
        Map(){};
 
      
        void Add(const T1& key, const T2& val) {  InsertSorted(Pair(key,val));}
        const T2& operator[](const T1& key) const { return (*BinSearch(key)).Second;}
        T2& operator[](const T1& key) { return (*FindElem(key)).Second;}   
      

        INT GetSize() const { return m_vec.GetSize(); }

      
        typedef typename Vector<Pair>::Iterator Iterator;
        typedef typename Vector<Pair>::Iterator ConstIterator;
        
        ConstIterator Begin() const  { return m_vec.Begin();}
        ConstIterator End() const  { return m_vec.End();}

        ConstIterator RBegin() const  { return m_vec.RBegin();}
        ConstIterator REnd() const  { return m_vec.REnd();}

        void Erase(const ConstIterator &elem) { m_vec.Erase(elem); }
        void Erase(const ConstIterator &first, const ConstIterator &last) { m_vec.Erase(first,last);}

        ConstIterator Find(const T1& key) const { return BinSearch(key); }
      

    
    private: 


        Iterator FindElem(const T1& key);

        void InsertSorted(const Pair& pair);

        ConstIterator  BinSearch(const T1& key) const;
}; 

template<class T1, class T2>
typename Map<T1,T2>::Iterator Map<T1,T2>::FindElem(const T1& key)  
{
    Iterator it= BinSearch(key);
    if (it==m_vec.End()) {
        InsertSorted(Pair(key,T2()));
        return BinSearch(key);
    }
    return it;
}
      
template<class T1, class T2>
void Map<T1,T2>::InsertSorted(const Pair& pair) 
{
    Iterator it= m_vec.Begin();
    for(;(it<m_vec.End()) && pair.First > (*it).First ;it++);
    if(it==m_vec.End()) {
        m_vec.PushBack(pair);
        return;
    }
    if(pair.First==(*it).First)
        *it= pair;
    else
        m_vec.Insert(it,pair);
}

template<class T1, class T2>
typename Map<T1,T2>::ConstIterator Map<T1,T2>::BinSearch(const T1& key) const 
{

    if(m_vec.GetSize() <= 0)
        return m_vec.End();

    
    INT low = 0;
    INT high = m_vec.GetSize()-1;        
    INT middle;

    
    while( low <= high )
    {
        middle = ( low  + high ) / 2;
        ConstIterator elem= m_vec.Begin() + middle;
        if( key == (*elem).First) {
            return elem;
        }
        if(key < (*elem).First)
            high = middle-1;              
        else 
            low = middle+1;

    }
    return m_vec.End();          
}

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  // Auxiliary_Map_hpp

