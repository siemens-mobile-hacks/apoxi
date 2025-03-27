/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(_Adc_FixedPtrArray_hpp)
#define _Adc_FixedPtrArray_hpp

#include <Kernel/Types.hpp>

template<class T> class FixedPtrArray
{
    public:
        typedef T * PtrT;
        FixedPtrArray() : m_ptr_array(0), m_count(0), m_size(0) {};
        FixedPtrArray(INT count) : m_count(0), m_size(0) { 
            m_ptr_array = new PtrT[count]; 
            if(m_ptr_array!=0) {
                m_count = count;
                m_size = count;
            }
        }
        ~FixedPtrArray() { delete[] m_ptr_array; };

        BOOLEAN Resize(INT count, T * pattern) {
            if(m_size<count) {
                delete[] m_ptr_array;
                m_ptr_array = new PtrT[count];
                if(m_ptr_array!=0) {
                    m_size = count;
                } else {
                    m_count = 0;
                    m_size = 0;
                    return FALSE;
                }
            }
            m_count = count;
            for(INT i=0; i<count; i++) {
                SetPtr(i,pattern);
            }
            return TRUE;
        }

        BOOLEAN Resize(INT count) {
            return Resize(count, 0);
        }

        void SetPtr(INT idx, PtrT ptr) { m_ptr_array[idx] = ptr; }
        PtrT GetPtr(INT idx) const { return m_ptr_array[idx]; }

        void DeletePtrObj(INT idx) const { delete m_ptr_array[idx]; m_ptr_array[idx] = 0; }

        PtrT operator [] (INT idx) const { return m_ptr_array[idx]; }

        PtrT operator [] (INT idx) { return m_ptr_array[idx]; }

        inline INT  GetCount() const { return m_count; }

    private:
        PtrT  * m_ptr_array;
        INT   m_count;
        INT   m_size;
};




#endif


