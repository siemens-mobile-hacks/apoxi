/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexChannel_hpp)
#define Apoxi_ObexChannel_hpp

#include <Auxiliary/BitField.hpp>

#include <Obex/ObexTypes.hpp>

class ObexChannel {

    inline  friend BOOLEAN  operator==(const ObexChannel &  lhs,
                                       const ObexChannel &  rhs);
    inline  friend BOOLEAN  operator!=(const ObexChannel &  lhs,
                                       const ObexChannel &  rhs);

    public:
        inline  ObexChannel();

        ObexChannel(ObexTransportId     transport_id,
                    ObexProtocolId      protocol_id,
                    BOOLEAN             is_server,
                    BOOLEAN             is_unique,
                    UINT16              impl_index);

        inline  ObexChannel(const ObexChannel &);

        inline  ObexChannel & operator=(const ObexChannel &);

        inline  BOOLEAN             IsValid() const;

        inline  void                Invalidate();

        inline  BOOLEAN             IsUnique() const;

        inline  BOOLEAN             IsClient() const;

        inline  BOOLEAN             IsServer() const;

        inline  ObexProtocolId      GetProtocolId() const;

        inline  ObexTransportId     GetTransportId() const;

        inline  UINT16              GetIndex() const;

    private:
        static  UINT8   s_last_creation_id; 

        BitField32      m_bitfield;

        // Value offsets within bitfield
        enum {
            OffsIsUnique    =  0,
            OffsIsServer    =  1,
            OffsTransportId =  2,
            OffsProtocolId  =  5,
            OffsCreationId  =  8,
            OffsImplIndex   = 16
        };

        // Value masks
        enum {
            MaskTransportId = ( 0x0007uL << OffsTransportId ),  //  3 bits
            MaskProtocolId  = ( 0x0007uL << OffsProtocolId ),   //  3 bits
            MaskCreationId  = ( 0x00FFuL << OffsCreationId ),   //  8 bits
            MaskImplIndex   = ( 0xFFFFuL << OffsImplIndex )     // 16 bits
        };

        inline  static  UINT8   NewCreationId();
};

/*  ----------------------------------------------------------------------
    Comparison for equality
    ---------------------------------------------------------------------- */
BOOLEAN     operator==(const ObexChannel &  lhs,
                       const ObexChannel &  rhs)
{
    return ( lhs.m_bitfield == rhs.m_bitfield );
}

/*  ----------------------------------------------------------------------
    Comparison for inequality
    ---------------------------------------------------------------------- */
BOOLEAN     operator!=(const ObexChannel &  lhs,
                       const ObexChannel &  rhs)
{
    return ! ( lhs.m_bitfield == rhs.m_bitfield );
}

/*  ----------------------------------------------------------------------
    NewCreationId
    ---------------------------------------------------------------------- */
UINT8   ObexChannel::NewCreationId()
{
    return ( ++s_last_creation_id != 0 )
           ? s_last_creation_id
           : ++s_last_creation_id;  // Wraparound, increment again
}

/*  ----------------------------------------------------------------------
    Copy Constructor
    ---------------------------------------------------------------------- */
ObexChannel::ObexChannel() :
    m_bitfield(0)
{
}

/*  ----------------------------------------------------------------------
    Copy Constructor
    ---------------------------------------------------------------------- */
ObexChannel::ObexChannel(const ObexChannel &    from) :

    m_bitfield( from.m_bitfield )
{
}

/*  ----------------------------------------------------------------------
    Assignment
    ---------------------------------------------------------------------- */
ObexChannel &   ObexChannel::operator=(const ObexChannel &  from)
{
    m_bitfield = from.m_bitfield;
    return *this;
}

/*  ----------------------------------------------------------------------
    IsValid
    ---------------------------------------------------------------------- */
BOOLEAN     ObexChannel::IsValid()
const
{
    return  ( m_bitfield.Get(MaskCreationId) != 0 );
}

/*  ----------------------------------------------------------------------
    Invalidate
    ---------------------------------------------------------------------- */
void        ObexChannel::Invalidate()
{
    m_bitfield.Clear();
}// Invalidate

/*  ----------------------------------------------------------------------
    IsUnique
    ---------------------------------------------------------------------- */
BOOLEAN     ObexChannel::IsUnique()
const
{
    return  m_bitfield.GetBit(OffsIsUnique);
}

/*  ----------------------------------------------------------------------
    IsClient
    ---------------------------------------------------------------------- */
BOOLEAN     ObexChannel::IsClient()
const
{
    return  ! m_bitfield.GetBit(OffsIsServer);
}// IsClient

/*  ----------------------------------------------------------------------
    IsServer
    ---------------------------------------------------------------------- */
BOOLEAN     ObexChannel::IsServer()
const
{
    return  m_bitfield.GetBit(OffsIsServer);
}

/*  ----------------------------------------------------------------------
    Constructor
    ---------------------------------------------------------------------- */
ObexProtocolId      ObexChannel::GetProtocolId() const
{
    return (ObexProtocolId) (m_bitfield.Get(MaskProtocolId) >> OffsProtocolId);
}

/*  ----------------------------------------------------------------------
    GetTransportId
    ---------------------------------------------------------------------- */
ObexTransportId     ObexChannel::GetTransportId() const
{
    return (ObexTransportId) (m_bitfield.Get(MaskTransportId) >> OffsTransportId);
}

/*  ----------------------------------------------------------------------
    GetIndex
    ---------------------------------------------------------------------- */
UINT16              ObexChannel::GetIndex() const
{
    return  (UINT16) (m_bitfield.Get(MaskImplIndex) >> OffsImplIndex);
}

#endif  // Apoxi_ObexChannel_hpp


