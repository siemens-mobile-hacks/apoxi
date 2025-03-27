/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_UsimPbCommit_hpp)
#define Adc_UsimPbCommit_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/BitField.hpp>

/*  ------------------------------------------------------------------------
    Uint8CommitArray
    ------------------------------------------------------------------------ */
// Array is used for Provider commit stuff
class Uint8CommitArray 
{
    public:
        void Clear() { 
            for(INT j=0; j<c_pb_max_file_type_per_record; j++) {
                m_val[j] = 0;
            }
            m_set.Clear();
        }
        void Set(UINT idx, UINT8 id) { 
            m_val[idx] = id;
            m_set.SetTrue(idx);
        }
        UINT8 Get(UINT idx) const { 
            return m_val[idx];
        }
        BOOLEAN WasChanged(UINT idx) const { 
            return m_set.GetBit(idx);
        }
        BOOLEAN IsUsed() const { 
            return m_set.Get()!=0;
        }

        UINT8       m_val[c_pb_max_file_type_per_record];
        BitField16  m_set; 
};

/*  ------------------------------------------------------------------------
    PhoneNumberCommitArray
    ------------------------------------------------------------------------ */
// Array is used for Provider commit stuff
class PhoneNumberCommitArray 
{
    public:
        void Clear() { 
            for(INT j=0; j<c_pb_max_file_type_per_record; j++) {
                m_val[j].Clear();
            }
            m_set.Clear();
        }
        void Set(UINT idx, const PhoneNumber & phno) { 
            m_val[idx] = phno;
            m_set.SetTrue(idx);
        }
        const PhoneNumber & Get(UINT idx) const { 
            return m_val[idx];
        }
        BOOLEAN WasChanged(UINT idx) const { 
            return m_set.GetBit(idx);
        }
        BOOLEAN IsUsed() const { 
            return m_set.Get()!=0;
        }

        PhoneNumber m_val[c_pb_max_file_type_per_record];
        BitField16  m_set; 
};

/*  ------------------------------------------------------------------------
    WStringCommitArray
    ------------------------------------------------------------------------ */
// Array is used for Provider commit stuff
class WStringCommitArray 
{
    public:
        void Clear() { 
            for(INT j=0; j<c_pb_max_file_type_per_record; j++) {
                m_val[j].Clear();
            }
            m_set.Clear();
        }
        void Set(UINT idx, const WString & phno) { 
            m_val[idx] = phno;
            m_set.SetTrue(idx);
        }
        const WString & Get(UINT idx) const { 
            return m_val[idx];
        }
        BOOLEAN WasChanged(UINT idx) const { 
            return m_set.GetBit(idx);
        }
        BOOLEAN IsUsed() const { 
            return m_set.Get()!=0;
        }

        WString     m_val[c_pb_max_file_type_per_record];
        BitField16  m_set; 
};


#endif // APOXI_ENABLE_USIM_PHONEBOOK

#endif


