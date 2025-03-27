/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexHeader_hpp)
#define Apoxi_ObexHeader_hpp

#include <Auxiliary/Linkable.hpp>
#include <Obex/ObexResult.hpp>

//  Forward declarations of classes
class ByteBuffer;

class ObexHeader : public Linkable< ObexHeader > {

    friend class ObexHeaderList;
    friend class ObexHeaderBuilder;

    public:
        enum {
            MaxHeaderLength = 255
        };

        enum HeaderType {
            UnicodeType = 0x00, 
            ByteSeqType = 0x40, 
            ByteType    = 0x80, 
            LongType    = 0xC0  
        };

        enum HeaderId {
            Invalid         = 0x00,
            Count           = 0x00 | LongType,
            Name            = 0x01 | UnicodeType,
            Type            = 0x02 | ByteSeqType,
            Length          = 0x03 | LongType,

            Description     = 0x05 | UnicodeType,
            Target          = 0x06 | ByteSeqType,
            Http            = 0x07 | ByteSeqType,
            Who             = 0x0A | ByteSeqType,
            ConnectionId    = 0x0B | LongType,
            AppParams       = 0x0C | ByteSeqType,
            AuthChallenge   = 0x0D | ByteSeqType,
            AuthResponse    = 0x0E | ByteSeqType,
            CreatorId       = 0x0F | LongType,
            WanUuid         = 0x10 | ByteSeqType,
            ObjectClass     = 0x11 | ByteSeqType,
            SessionParams   = 0x12 | ByteSeqType,
            SessionSeqNum   = 0x13 | ByteType
        };

        enum {
            NoConnectionId  = 0xFFFFFFFF
        };

        enum ByteOrder {
            HostByteOrder,  
            ObexByteOrder   
        };

        inline  static  HeaderType  TypeOfId(INT id);

        inline  BOOLEAN     IsValid() const;

        inline  HeaderType  GetType() const;

        inline  UINT8       GetId() const;

        UINT16              GetSize() const;

        const WString &     ToWString() const;

        const ByteBuffer &  ToByteBuffer() const;

        const String        ToString()  const;

        const CHAR *        ToCStr() const;

        UINT8               ToByte()    const;

        UINT32              ToLong()    const;

        ObexResult          PutValue(UINT8      buffer[],
                                     UINT16     size,
                                     ByteOrder  format = ObexByteOrder) const;
    private:
        union HeaderVariant {
            WString *       unicode_ptr;
            ByteBuffer *    byteseq_ptr;
            UINT8           byte_value;
            UINT32          long_value;
        };

        static  void    Write(UINT8             buffer[],
                              ByteOrder         format,
                              const WString &   value);

        static  void    Write(UINT8             buffer[],
                              ByteOrder         format,
                              UINT32            value);

        ObexHeader(UINT8    id, const WString &     unicode_data);

        ObexHeader(UINT8    id, const String &      string_data);

        ObexHeader(UINT8    id, const UINT8 data[], UINT16  data_size);

        ObexHeader(UINT8    id, UINT8           byte_data);

        ObexHeader(UINT8    id, UINT32          long_data);

        virtual ~ObexHeader();

        ObexHeader(ObexHeader const &  from);

        ObexHeader &    operator=(ObexHeader const &  from);

        UINT8           m_hi;   
        HeaderVariant   m_hv;   
};


/*  ----------------------------------------------------------------------
    IsValid
    ---------------------------------------------------------------------- */
BOOLEAN ObexHeader::IsValid()
const
{
    return ( m_hi != Invalid );
}// IsValid

/*  ----------------------------------------------------------------------
    GetType
    ---------------------------------------------------------------------- */
ObexHeader::HeaderType  ObexHeader::GetType()
const
{
    return  TypeOfId(m_hi);
}// GetType

/*  ----------------------------------------------------------------------
    GetId
    ---------------------------------------------------------------------- */
UINT8   ObexHeader::GetId()
const
{
    return m_hi;
}// GetId

/*  ----------------------------------------------------------------------
    TypeOfId
    ---------------------------------------------------------------------- */
ObexHeader::HeaderType  ObexHeader::TypeOfId(INT id)
{
    return HeaderType( (id & 0xC0) );
}// TypeOfId

#endif  // Apoxi_ObexHeader_hpp

