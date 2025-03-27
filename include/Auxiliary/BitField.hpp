/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Auxiliary_BitField_hpp)
#define Auxiliary_BitField_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>

template <class T> class BitField {
    public:
        enum { NrOfBits = sizeof(T) * 8 };

        BitField(const T& bit_field = 0) : m_bit_field(bit_field) {};

        BitField& operator <<(INT shift_pos) {
            ASSERT_DEBUG(shift_pos >= 0 && shift_pos < NrOfBits);
            m_bit_field = m_bit_field << shift_pos;
            return (*this);
        }

        BitField& operator >>(INT n_shifts) {
            ASSERT_DEBUG(n_shifts >= 0 && n_shifts < NrOfBits);
            m_bit_field = m_bit_field >> n_shifts;
            return (*this);
        }

        BOOLEAN operator == (const BitField &bit_field) const { 
            return (m_bit_field == bit_field.m_bit_field); 
        }

        void Set(T bit_field, T mask) {
            m_bit_field = (m_bit_field & ~mask) | (bit_field & mask);
        }

        void Set(T bit_field) {
            m_bit_field = bit_field;
        }

        void SetBit(INT bit_index, BOOLEAN set) {
            if (set) {
                m_bit_field |= BitMask(bit_index);
            } // if
            else {
                m_bit_field &= ~BitMask(bit_index);
            } // else
        };
        void SetBit(INT bit_index) {
            m_bit_field |= BitMask(bit_index);
        };

        void SetTrue(INT bit_index) {
            m_bit_field |= BitMask(bit_index);
        };

        void SetFalse(INT bit_index) {
            m_bit_field &= ~BitMask(bit_index);
        };

        void Clear() { m_bit_field = 0; }

        INT GetNrOfBits() const { return (NrOfBits); }

        T Get(const T &mask) const { return (m_bit_field & mask); }

        T Get() const { return (m_bit_field); }

        BOOLEAN GetBit(INT bit_index) const { return ((m_bit_field & BitMask(bit_index)) != 0); };

        BOOLEAN IsSet(const T &bit_field) const { return ((~(m_bit_field | ~bit_field)) == 0); };


        T Mask(const T &mask) const { return (m_bit_field & mask); };

        BOOLEAN IsEqual(const T &bit_field, const T &mask) const {
            return ((bit_field & mask) == Get(mask));
        };

        BOOLEAN IsEqual(const BitField<T> &bit_field) const {
            return (m_bit_field == bit_field.m_bit_field);
        };

    private:
        T m_bit_field;

        T BitMask(INT bit_index) const {
            ASSERT_DEBUG(bit_index >= 0 && bit_index < NrOfBits);
            return (T(1) << bit_index);
        }

};

typedef BitField<UINT8>  BitField8;
typedef BitField<UINT16> BitField16;
typedef BitField<UINT32> BitField32;



#endif  // Auxiliary_BitField_hpp

