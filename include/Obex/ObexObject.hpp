/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexObject_hpp)
#define Apoxi_ObexObject_hpp

#include <Obex/ObexHeaderList.hpp>

//  Forward declaration of classes
class ObexObjectData;
class ObexBuffer;

class ObexObject {
    public:
        enum ResponseCode {
            Request                         = 0,

            RespOk                          = 0x20,

            // 3xx codes
            RespMultipleChoices             = 0x30,
            RespMovedPermanently            = 0x31,
            RespMovedTemporarily            = 0x32,
            RespSeeOther                    = 0x33,
            RespNotModified                 = 0x34,
            RespUseProxy                    = 0x35,

            // 4xx codes
            RespBadRequest                  = 0x40,
            RespUnauthorized                = 0x41,
            RespPaymentRequired             = 0x42,
            RespForbidden                   = 0x43,
            RespNotFound                    = 0x44,
            RespMethodNotAllowed            = 0x45,
            RespNotAcceptable               = 0x46,
            RespProxyAuthenticationRequired = 0x47,
            RespRequestTimeOut              = 0x48,
            RespConflict                    = 0x49,
            RespGone                        = 0x4A,
            RespLengthRequired              = 0x4B,
            RespPreconditionFailed          = 0x4C,
            RespRequestedEntityTooLarge     = 0x4D,
            RespRequestUrlTooLarge          = 0x4E,
            RespRequestUnsupportedMediaType = 0x4F,

            // 5xx codes
            RespInternalServerError         = 0x50,
            RespNotImplemented              = 0x51,
            RespBadGateWay                  = 0x52,
            RespServiceUnavailable          = 0x53,
            RespGatewayTimeOut              = 0x54,
            RespHttpVersionNotSupported     = 0x55,

            // 6xx codes
            RespDatabaseFull                = 0x60,
            RespDatabaseLocked              = 0x61
        };

        enum ConnectFlags {
            ConnMultipleIrlmpLsapSel = 0x01
        };

        enum SetPathFlags {
            SetpBackup      = 0x01, 
            SetpDontCreate  = 0x02  
        };

        ObexObject();

        ObexObject(ObexObject const &  from);

        ObexObject &  operator=(ObexObject const &  rhs);

        ~ObexObject();

        void                Release();

        ObexResult          Init(ResponseCode   response_code = Request);

        inline  ObexResult  Init(ObexBuffer &   source_buffer);

        ObexResult          Init(ResponseCode   response_code,
                                 ObexBuffer &   source_buffer);

        inline  BOOLEAN     IsValid() const;

        BOOLEAN             IsWritable() const;

        inline  BOOLEAN     IsSuccessResponse() const;

        ObexHeaderList &    GetHeaderList() const;

        ResponseCode        GetResponseCode() const;

        void                SetResponseCode(ResponseCode  r);

        UINT8               GetRequestFlags() const;

        void                SetRequestFlags(UINT8   req_flags);

        BOOLEAN             IsEndOfData() const;

        void                SetEndOfData(BOOLEAN    end_of_data = TRUE);

        BOOLEAN             ObtainBuffer(ObexBuffer &   target_buffer);

        void                CommitBuffer(ObexBuffer &   source_buffer);

        UINT32              GetDataFractionSize() const;

    private:
        ObexObjectData *    m_data_ptr; 

        void                Attach();

        void                Detach();
};

/*  ----------------------------------------------------------------------
    IsValid
    ---------------------------------------------------------------------- */
BOOLEAN     ObexObject::IsValid() const
{
    return ( m_data_ptr != 0 );
}// IsValid

/*  ----------------------------------------------------------------------
    IsSuccessResponse
    ---------------------------------------------------------------------- */
BOOLEAN     ObexObject::IsSuccessResponse() const
{
    return ( GetResponseCode() == RespOk );
}// IsSuccessResponse

/*  ----------------------------------------------------------------------
    Init
    ---------------------------------------------------------------------- */
ObexResult  ObexObject::Init(ObexBuffer &   source_buffer)
{
    return  Init(Request, source_buffer);
}// Init                                                #

#endif  // Apoxi_ObexObject_hpp

