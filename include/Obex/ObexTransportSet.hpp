/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexTransportSet_hpp)
#define Apoxi_ObexTransportSet_hpp

#include <Auxiliary/BitField.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexConfig.hpp>

// Forward declarations of classes.
class ObexAbstractTransport;

class ObexTransportSet {

    public:
        class Iterator {

            friend  class ObexTransportSet;

            public:
                inline  Iterator();

                inline  Iterator(const Iterator & from);

                inline  Iterator &          operator=(const Iterator & from);

                ObexAbstractTransport &     operator*() const;

                ObexAbstractTransport *     operator->() const;

                inline  BOOLEAN             IsValid() const;

                inline  Iterator &          operator++();

                void                        Advance();

            private:
                Iterator(ObexTransportSet &     set,
                         ObexTransportId        pos = 0);

                ObexTransportSet *  m_ptr;  
                ObexTransportId     m_pos;  
        };

        inline  ObexTransportSet() {}

        inline  ObexTransportSet(const ObexTransportSet &  from);

        inline  ObexTransportSet &  operator=(const ObexTransportSet &  from);

        inline  Iterator            Begin();

        inline  BOOLEAN             IsEmpty() const;

        inline  BOOLEAN             Contains(ObexTransportId    id) const;

        UINT8                       GetCount() const;

        void                        Include(const ObexAbstractTransport &   xp);

        void                        Include(const String &                  scheme);

        inline void                 Include(const ObexTransportSet &        xs);

        inline  void                Exclude(const ObexTransportSet &        xs);

    private:
        BitField8   m_bitset;
};

/*  ----------------------------------------------------------------------
    Iterator    Default constructor.
    ---------------------------------------------------------------------- */
ObexTransportSet::Iterator::Iterator() :
    m_ptr( 0 ),
    m_pos( APOXI_OBEX_MAX_NO_TRANSPORTS )
{
}// Constructor

/*  ----------------------------------------------------------------------
    Iterator    Copy constructor.
    ---------------------------------------------------------------------- */
ObexTransportSet::Iterator::Iterator(const Iterator & from) :
    m_ptr( from.m_ptr ),
    m_pos( from.m_pos )
{
}// Constructor

/*  ----------------------------------------------------------------------
    Iterator    Assignment operator.
    ---------------------------------------------------------------------- */
ObexTransportSet::Iterator &
ObexTransportSet::Iterator::operator=(const Iterator & from)
{
    m_ptr = from.m_ptr;
    m_pos = from.m_pos;
    return * this;
}// Assignment

/*  ----------------------------------------------------------------------
    Iterator::IsValid
    ---------------------------------------------------------------------- */
BOOLEAN     ObexTransportSet::Iterator::IsValid()
const
{
    return ( (m_ptr != 0) &&
             (m_pos < APOXI_OBEX_MAX_NO_TRANSPORTS) );
}// IsValid

/*  ----------------------------------------------------------------------
    Iterator::operator++()
    ---------------------------------------------------------------------- */
ObexTransportSet::Iterator &
ObexTransportSet::Iterator::operator++()
{
    Advance();
    return *this;
}// operator++()

/*  ----------------------------------------------------------------------
    ObexTransportSet Copy
    ---------------------------------------------------------------------- */
ObexTransportSet::ObexTransportSet(const ObexTransportSet &  from) :
    m_bitset( from.m_bitset )
{
}// ObexTransportSet

/*  ----------------------------------------------------------------------
    ObexTransportSet Assignment
    ---------------------------------------------------------------------- */
ObexTransportSet &  ObexTransportSet::operator=(const ObexTransportSet &  from)
{
    m_bitset = from.m_bitset;
    return *this;
}// operator=

/*  ----------------------------------------------------------------------
    Begin
    ---------------------------------------------------------------------- */
ObexTransportSet::Iterator  ObexTransportSet::Begin()
{
    return Iterator(*this);
}// Begin

/*  ----------------------------------------------------------------------
    IsEmpty
    ---------------------------------------------------------------------- */
BOOLEAN     ObexTransportSet::IsEmpty()
const
{
    return ( m_bitset.Get() == 0 );
}// IsEmpty

/*  ----------------------------------------------------------------------
    Contains
    ---------------------------------------------------------------------- */
BOOLEAN     ObexTransportSet::Contains(ObexTransportId  id)
const
{
    return m_bitset.GetBit(id);
}// Contains

/*  ----------------------------------------------------------------------
    Include
    ---------------------------------------------------------------------- */
void    ObexTransportSet::Include(const ObexTransportSet &  xp_set)
{
    m_bitset.Set( m_bitset.Get() | xp_set.m_bitset.Get() );
}// Include

/*  ----------------------------------------------------------------------
    Exclude
    ---------------------------------------------------------------------- */
void    ObexTransportSet::Exclude(const ObexTransportSet &  xp_set)
{
    m_bitset.Set( m_bitset.Mask( ~xp_set.m_bitset.Get() ) );
}// Exclude

#endif  // Apoxi_ObexTransportSet_hpp

