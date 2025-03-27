/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BitVector_hpp)
#define Apoxi_BitVector_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>

template<INT N> class BitVector {
    private:
        enum {
            BITS_PER_UINT = sizeof(UINT) * 8,
            UINT_COUNT = (N + BITS_PER_UINT - 1) / BITS_PER_UINT
        };

        UINT bits[UINT_COUNT];

        inline UINT& Atom(INT bitidx) {
            ASSERT_DEBUG(bitidx >= 0 && bitidx < N);
            return(bits[bitidx / BITS_PER_UINT]);
        }

        inline UINT Atom(INT bitidx) const {
            ASSERT_DEBUG(bitidx >= 0 && bitidx < N);
            return(bits[bitidx / BITS_PER_UINT]);
        }

        inline UINT BitMask(INT bitidx) const {
            ASSERT_DEBUG(bitidx >= 0 && bitidx < N);
            return(1U << (bitidx % BITS_PER_UINT));
        }

    public:
        inline BitVector() {
            memset(bits,0,sizeof(bits));
        }
        inline BOOLEAN GetBit(INT idx) const {
            return((Atom(idx) & BitMask(idx)) != 0);
        }
        inline void SetBit(INT idx,BOOLEAN set) {
            if (set)
                Atom(idx) |= BitMask(idx);
            else
                Atom(idx) &= ~BitMask(idx);
        }

        inline void SetBit(INT idx) {
            SetBit(idx,TRUE);
        }
};


#endif  // Apoxi_BitVector_hpp


