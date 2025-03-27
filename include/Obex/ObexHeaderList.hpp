/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexHeaderList_hpp)
#define Apoxi_ObexHeaderList_hpp

#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/MimeTypeTable.hpp>

#include <Obex/ObexResult.hpp>
#include <Obex/ObexHeader.hpp>

// Forward declarations of classes
class ObexHeaderBuilder;

class ObexHeaderList : private LinkedList< ObexHeader > {

    friend class ObexObjectData;

    private:
        // This is only private (implementation) inheritance !
        typedef LinkedList<ObexHeader>  Base;

    public:
        class ConstIterator {

            friend  class  ObexHeaderList;

            public:
                inline  ConstIterator();

                inline  ConstIterator(const ConstIterator &  from);

                inline  ConstIterator & operator=(const ConstIterator &  from);

                inline  BOOLEAN     IsValid() const;

                void    Advance();

                inline  ConstIterator &     operator++();

                inline  const ObexHeader &  operator*() const;

                inline  const ObexHeader *  operator->() const;

            private:
                const ObexHeader *      m_ptr;

                inline  ConstIterator(const ObexHeader *  obex_hdr_ptr);
        };

        ObexHeaderList();

        ~ObexHeaderList();

        ObexResult  AddHeader(INT   id, const WString & unicode_data);

        ObexResult  AddHeader(INT   id, const String &  byteseq_data);

        ObexResult  AddHeader(INT   id, const UINT8 data[], UINT16  data_size);

        ObexResult  AddHeader(INT   id, UINT8   byte_data);

        ObexResult  AddHeader(INT   id, UINT32  long_data);

        ObexResult  AddHeader(ObexHeaderBuilder &   builder);

        ObexResult  AddMimeType(MimeType    mime_type);

        MimeType    ObtainMimeType() const;

        inline  ConstIterator   Begin() const;

        inline  BOOLEAN         Contains(ObexHeader::HeaderId   id,
                                         ConstIterator          from) const;

        inline  BOOLEAN         Contains(ObexHeader::HeaderId   id) const;

        ConstIterator           Find(ObexHeader::HeaderId   id,
                                     ConstIterator          from) const;

        inline  ConstIterator   Find(ObexHeader::HeaderId   id) const;

        using                   Base::IsEmpty;

    private:
        ObexHeaderList(const ObexHeaderList &);

        ObexHeaderList &        operator=(const ObexHeaderList &);

        ObexResult              Append(ObexHeader *  obex_header_ptr);

        void                    Release();
};

/*  ----------------------------------------------------------------------
    Default constructor
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator::ConstIterator() :
    m_ptr( 0 )
{
}// Constructor

/*  ----------------------------------------------------------------------
    Constructor
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator::ConstIterator(const ObexHeader *  obex_hdr_ptr) :
    m_ptr( obex_hdr_ptr )
{
}// Constructor

/*  ----------------------------------------------------------------------
    Constructor
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator::ConstIterator(const ConstIterator &  from) :
    m_ptr( from.m_ptr )
{
}// Constructor

/*  ----------------------------------------------------------------------
    operator=
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator &
ObexHeaderList::ConstIterator::operator=(const ConstIterator &  from)
{
    m_ptr = from.m_ptr;
    return *this;
}// operator=

/*  ----------------------------------------------------------------------
    IsValid
    ---------------------------------------------------------------------- */
BOOLEAN     ObexHeaderList::ConstIterator::IsValid()
const
{
    return ( m_ptr != 0 );
}// IsValid

/*  ----------------------------------------------------------------------
    operator++()
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator &  ObexHeaderList::ConstIterator::operator++()
{
    Advance();
    return *this;
}// operator++()

/*  ----------------------------------------------------------------------
    operator*
    ---------------------------------------------------------------------- */
const ObexHeader &  ObexHeaderList::ConstIterator::operator*()
const
{
    ASSERT_DEBUG( IsValid() );
    return *m_ptr;
}// operator*

/*  ----------------------------------------------------------------------
    operator->
    ---------------------------------------------------------------------- */
const ObexHeader *  ObexHeaderList::ConstIterator::operator->()
const
{
    ASSERT_DEBUG( IsValid() );
    return m_ptr;
}// operator->

/*  ----------------------------------------------------------------------
    Begin
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator   ObexHeaderList::Begin()
const
{
    return  ConstIterator( Base::GetFront() );
}// Begin

/*  ----------------------------------------------------------------------
    Contains
    ---------------------------------------------------------------------- */
BOOLEAN  ObexHeaderList::Contains(ObexHeader::HeaderId  id,
                                  ConstIterator         from)
const
{
    return Find( id, from ).IsValid();
}// Contains

/*  ----------------------------------------------------------------------
    Contains
    ---------------------------------------------------------------------- */
BOOLEAN  ObexHeaderList::Contains(ObexHeader::HeaderId  id)
const
{
    return Find( id, Begin() ).IsValid();
}// Contains

/*  ----------------------------------------------------------------------
    Find
    ---------------------------------------------------------------------- */
ObexHeaderList::ConstIterator   ObexHeaderList::Find(ObexHeader::HeaderId   id)
const
{
    return Find( id, Begin() );
}// Find

#endif  // Apoxi_ObexHeaderList_hpp

