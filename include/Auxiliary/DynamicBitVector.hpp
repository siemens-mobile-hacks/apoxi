/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DynamicBitVector_hpp)
#define Apoxi_DynamicBitVector_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>
#include <string.h> // for memset()

class DynamicBitVector
{
    private:
        enum {
            BITS_PER_UINT = sizeof(UINT) * 8,
        };

    public:
        inline DynamicBitVector() : m_bits(0),
                                    m_nrofbits(0)
        {
        }

        inline DynamicBitVector(INT nrofbits) : m_bits(0),
                                                m_nrofbits(0)
        {
            UINT noofuints = BitsToAtoms(nrofbits);

            if ( (m_bits = Allocate(noofuints)) != 0 ) {
                memset( (UINT8*) &m_bits[0], 0, noofuints * sizeof(UINT) );
                m_nrofbits = nrofbits;
            }
        }

        inline DynamicBitVector(const DynamicBitVector &  from) : m_bits(0),
                                                                  m_nrofbits(0)
        {
            Copy(from);
        }

        inline ~DynamicBitVector()
        {
            Free();
        }

        inline DynamicBitVector &   operator=(const DynamicBitVector &  from)
        {
            if ( &from != this ) {

                Free();
                Copy(from);
            }
            return  *this;
        }

        inline UINT     GetLength() const
        {
            return  m_nrofbits;
        }

        inline BOOLEAN  GetBit(INT idx) const
        {
            return ( (Atom(idx) & BitMask(idx)) != 0 );
        }

        inline void     SetBit(INT idx,BOOLEAN set = TRUE)
        {
            if (set)
                Atom(idx) |= BitMask(idx);
            else
                Atom(idx) &= ~BitMask(idx);
        }

        inline BOOLEAN  Intersects(const DynamicBitVector &  rhs) const
        {
            UINT    lhs_atoms = BitsToAtoms(m_nrofbits);
            UINT    rhs_atoms = BitsToAtoms(rhs.m_nrofbits);
            UINT    int_atoms = Minimum(lhs_atoms, rhs_atoms);

            for ( UINT  i = 0; i < int_atoms; i++ ) {
                if ( (m_bits[i] & rhs.m_bits[i]) != 0 ) {
                    return TRUE;
                }
            }
            return FALSE;
        }

    private:
        inline UINT &   Atom(INT bitidx)
        {
            ASSERT_DEBUG(bitidx >= 0 && bitidx < m_nrofbits);
            return(m_bits[bitidx / BITS_PER_UINT]);
        }

        inline UINT     Atom(INT bitidx) const
        {
            ASSERT_DEBUG(bitidx >= 0 && bitidx < m_nrofbits);
            return(m_bits[bitidx / BITS_PER_UINT]);
        }

        inline UINT     BitMask(INT bitidx) const {
            ASSERT_DEBUG(bitidx >= 0 && bitidx < m_nrofbits);
            return(1U << (bitidx % BITS_PER_UINT));
        }

        inline UINT     BitsToAtoms(UINT    nrofbits) const
        {
            return ( (nrofbits + BITS_PER_UINT - 1) / BITS_PER_UINT );
        }

        inline void     Copy(const DynamicBitVector &   from)
        {
            UINT    noofuints = BitsToAtoms(from.m_nrofbits);

            ASSERT_DEBUG( m_bits == 0 );
            ASSERT_DEBUG( m_nrofbits == 0 );

            if ( (m_bits = Allocate(noofuints)) != 0 ) {
                memcpy( (UINT8*) m_bits, (UINT8*) from.m_bits, noofuints * sizeof(UINT) );
                m_nrofbits = from.m_nrofbits;
            }
        }

        inline UINT *   Allocate(UINT   noofuints)
        {
            return ( noofuints != 0 )
                   ? new UINT[noofuints]
                   : 0;
        }

        inline void Free()
        {
            delete [] m_bits;

            m_bits     = 0;
            m_nrofbits = 0;
        }

        UINT * m_bits;
        INT    m_nrofbits;
};

#endif  // Apoxi_DynamicBitVector_hpp

