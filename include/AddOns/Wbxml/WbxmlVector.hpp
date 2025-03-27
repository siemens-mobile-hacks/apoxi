/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Wbxml_Vector_hpp)
#define Apoxi_Wbxml_Vector_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Vector.hpp>

template<class T> class WbxmlVector : public Vector<T> {
    public :
        typedef Vector<T> Base;
        typedef INT SizeType;
        typedef INT DifferenceType;

        using Base::Iterator ;
        using Base::ReverseIterator ;
        typedef typename Vector<T>::Iterator iterator;
        typedef typename Vector<T>::ReverseIterator reverse_iterator;

        WbxmlVector() { }   
        SizeType size() { return Base::GetSize() ; }
        bool empty() const { return (Base::IsEmpty() ? TRUE:FALSE ) ; } 
        T& front() { return Base::Front() ; }
        const T& front() const {return Base::Front() ;} 
        T& back() { return Base::Back() ; } 
        const T& back() const { return Base::Back() ; }
        void push_back(const T&  x) { Base::PushBack(x) ; }
        void clear() { Base::Erase(Base::Begin(), Base::End()) ; }
        void reserve(SizeType n) { Base::Reserve(n) ; } 

        iterator begin() { return Base::Begin() ; }
        iterator end() { return  Base::End() ; }    // The End() function returns an iterator past the last element. std::end() returns iterator to last element.
        reverse_iterator rbegin() { return Base::RBegin() ; } 
        reverse_iterator rend() { return Base::REnd() ; } 

        iterator erase(const iterator &pos) { 
            if(pos == end()) {
                Base::Erase(pos) ;
                return end() ;
            }
            else {
                Base::Erase(pos) ; 
                return pos ; 
            }
        }

        iterator erase(const iterator &first, const iterator &last) {        // Need to check if end then return end.
            iterator temp = first ;
            if(last < temp) {
                while(last <= temp){                
                    erase(temp) ;
                    temp = temp + 1;
                }
                return temp ;
            }
            else {
                Base::Erase(first,last) ; 
                return first ;
            }   
        }

        iterator insert(const iterator &pos, T& x) { 
            Base::Insert(pos,1,x) ; 
            if(pos == end())
                return end() ;
            else
                return pos ;
        } 
                
        void insert(const iterator &pos, SizeType n, const T&  x) { Base::Insert(pos,n,x) ;}
    
        void resize(SizeType n) { // To check after changes.
        int length = size() ;
            if(length == 0)                         
                Base::Insert(begin(),n) ;
            else if(length < n)
                Base::Insert(end(),n) ;
            else if (n < length)
                erase(begin() + n, end());
        }       
} ; 

#endif // Apoxi_Wbxml_Vector_hpp

