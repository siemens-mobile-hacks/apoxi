/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexOperationId_hpp)
#define Apoxi_ObexOperationId_hpp

#include <Kernel/Types.hpp>

class ObexOperationId {
    public:
        inline  ObexOperationId();

        inline  ObexOperationId(const ObexOperationId &  from);

        inline  ObexOperationId &   operator=(const ObexOperationId &  from);

        inline  friend  BOOLEAN     operator==(const ObexOperationId &  lhs,
                                               const ObexOperationId &  rhs);

        inline  friend  BOOLEAN     operator!=(const ObexOperationId &  lhs,
                                               const ObexOperationId &  rhs);

        inline  static  ObexOperationId     Create();

        inline  BOOLEAN     IsValid() const;

        inline  void        Invalidate();

        inline  UINT16      GetSeqNr() const;

    private:
        static  UINT16  s_seq_nr_last;

        UINT16          m_seq_nr;

        inline  ObexOperationId(UINT16  seq_nr);
};


/*  ----------------------------------------------------------------------
    ObexOperationId
    ---------------------------------------------------------------------- */
ObexOperationId::ObexOperationId() :
    m_seq_nr(0)
{
}// ObexOperationId

/*  ----------------------------------------------------------------------
    ObexOperationId
    ---------------------------------------------------------------------- */
ObexOperationId::ObexOperationId(const ObexOperationId &  from) :
    m_seq_nr( from.m_seq_nr )
{
}// ObexOperationId

/*  ----------------------------------------------------------------------
    ObexOperationId
    ---------------------------------------------------------------------- */
ObexOperationId::ObexOperationId(UINT16  seq_nr) :
    m_seq_nr( seq_nr )
{
}// ObexOperationId

/*  ----------------------------------------------------------------------
    operator=
    ---------------------------------------------------------------------- */
ObexOperationId &  ObexOperationId::operator=(const ObexOperationId &  from)
{
    m_seq_nr = from.m_seq_nr;
    return *this;
}// operator=

/*  ----------------------------------------------------------------------
    Create
    ---------------------------------------------------------------------- */
ObexOperationId  ObexOperationId::Create()
{
    return ObexOperationId( ++s_seq_nr_last );
}// Create

/*  ----------------------------------------------------------------------
    operator==
    ---------------------------------------------------------------------- */
BOOLEAN operator==(const ObexOperationId &  lhs,
                   const ObexOperationId &  rhs)
{
    return (lhs.m_seq_nr == rhs.m_seq_nr);
}// operator==

/*  ----------------------------------------------------------------------
    operator!=
    ---------------------------------------------------------------------- */
BOOLEAN operator!=(const ObexOperationId &  lhs,
                   const ObexOperationId &  rhs)
{
    return (lhs.m_seq_nr != rhs.m_seq_nr);
}// operator!=

/*  ----------------------------------------------------------------------
    IsValid
    ---------------------------------------------------------------------- */
BOOLEAN ObexOperationId::IsValid()
const
{
    return (m_seq_nr != 0);
}// IsValid

/*  ----------------------------------------------------------------------
    Invalidate
    ---------------------------------------------------------------------- */
void    ObexOperationId::Invalidate()
{
    m_seq_nr = 0;
}// Invalidate

/*  ----------------------------------------------------------------------
    GetSeqNr
    ---------------------------------------------------------------------- */
UINT16  ObexOperationId::GetSeqNr()
const
{
    return  m_seq_nr;
}// GetSeqNr

#endif  // Apoxi_ObexOperationId_hpp


