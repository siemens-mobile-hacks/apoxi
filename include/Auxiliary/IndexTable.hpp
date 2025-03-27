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

#if ! defined(_Adc_IndexTable_hpp)
#define _Adc_IndexTable_hpp

#include <Kernel/Types.hpp>

template<class T> class IndexTable
{
    public:
        IndexTable() : m_indextable(0), m_count(0), m_size(0) {}
        IndexTable(INT count) : m_count(count), m_size(count)  { 
            m_indextable = new T[count]; 
            if(m_indextable==0) {
                m_count = 0;
                m_size = 0;
            }
        }
        
        IndexTable(const IndexTable<T>& indextable) 
               : m_indextable(0), m_count(indextable.m_count), m_size(indextable.m_count)  {
            if (indextable.m_indextable != 0) {
                m_indextable = new T[m_count]; 
                if(m_indextable==0) {
                    m_count = 0;
                    m_size = 0;
                } else {
                    for (INT i = 0; i < m_size; ++i) {
                        m_indextable[i] = indextable.m_indextable[i];
                    }
                }
            }
        }

        ~IndexTable() { 
            if (m_indextable != 0) {
                delete[] m_indextable; 
                m_indextable = 0;
            }
        }

        BOOLEAN Resize(INT count) {
            if(m_size<count) {
                delete[] m_indextable;
                m_indextable = new T[count];
                if(m_indextable==0) {
                    m_size = 0;
                    m_count = 0;
                    return FALSE;
                }
                m_size = count;
            }
            m_count = count;    
            return TRUE;
        }

        inline void SetValue(INT idx, T value) { m_indextable[idx] = value; }
        inline T  GetValue(INT idx) const { return m_indextable[idx]; }

        const T operator [] (INT idx) const { return m_indextable[idx]; }
        T operator [] (INT idx) { return m_indextable[idx]; }
        IndexTable<T>& operator = (const IndexTable<T>& indextable) { 
            if (this == &indextable) {
                return *this;
            }
            INT size = indextable.GetSize();
            Resize(size);
            for (INT i = 0; i < size; ++i) {
                m_indextable[i] = indextable.m_indextable[i];
            }
            return *this; 
        }

        inline void SwapValues(INT row1, INT row2) {
            T help = GetValue(row1);
            SetValue(row1,GetValue(row2));
            SetValue(row2,help);
        }

        inline void MoveValue(INT row1, INT row2) {
            INT row = row1;
            while (row != row2)
            {
               SwapValues(row, row +1);
               row++;
            }
        }
        inline void FillIndexValues() {
            for(INT i=0; i<m_count; i++)
                SetValue(i,(T)i);
        }
        inline void FillZeroes() {
            for(INT i=0; i<m_count; i++)
                SetValue(i,(T)0);
        }
        inline INT  GetCount() const { return m_count; }

        inline INT  GetSize() const { return m_size; }

    private:
        T *  m_indextable;
        INT  m_count;
        INT  m_size;
};



#endif


