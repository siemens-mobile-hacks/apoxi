/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexResult_hpp)
#define Apoxi_ObexResult_hpp


class ObexResult
{
    public:
        enum ErrorCode {
            // Success
            Success                     =   0,

            // Spontaneous events
            ObexError                   =   1,
            OperationAborted            =   2,
            TransportDisconnected       =   3,

            // Errors related to an operation
            OperationAlreadyRunning     =   8,
            OperationAlreadyComplete    =   9,
            OperationNotSupported       =  10,
            OperationNotPermitted       =  11,
            InvalidHeadersInRequest     =  14,

            // Errors caused by lack of resources
            ResourceNotAvailable        =  16,
            OutOfMemory                 =  17,

            // Server-specific errors
            ServerAlreadyOpen           =  32,
            ServerAlreadyClosed         =  33,
            ServerAlreadyKnown          =  34,

            // Client-specific errors
            ClientAlreadyOpen           =  64,
            ClientAlreadyClosed         =  65,

            // Internal errors
            InvalidHeaderId             =  96,
            UnknownMimeType             =  97,
            ObjectNotWritable           =  98,

            // OBEX Url parsing errors
            SyntaxErrorInUrl            = 128,
            UnknownParameterInUrl       = 129,
            InvalidParameterInUrl       = 130,

            // API function errors
            InvalidExecutionContext     = 192,

            // Unspecified error
            Unspecified                 = 255
        };

        static inline   ObexResult  Ok();

        inline          ObexResult(ErrorCode  e = Unspecified);

        inline          ObexResult(const ObexResult &  from);

        inline          ObexResult &    operator=(const ObexResult &  from);

        inline          BOOLEAN         IsError() const;

        inline          BOOLEAN         IsOk() const;

        inline          operator        BOOLEAN() const;

        inline          ErrorCode       GetErrorCode() const;

    private:
        ErrorCode       m_code; 
};


/*  ----------------------------------------------------------------------
    Ok
    ---------------------------------------------------------------------- */
ObexResult  ObexResult::Ok()
{
    return  ObexResult(Success);
}// Ok

/*  ----------------------------------------------------------------------
    ObexResult
    ---------------------------------------------------------------------- */
ObexResult::ObexResult(ErrorCode  e) :
    m_code( e )
{
}// ObexResult

/*  ----------------------------------------------------------------------
    ObexResult
    ---------------------------------------------------------------------- */
ObexResult::ObexResult(const ObexResult &  from) :
    m_code( from.m_code )
{
}// ObexResult

/*  ----------------------------------------------------------------------
    operator=
    ---------------------------------------------------------------------- */
ObexResult &    ObexResult::operator=(const ObexResult &  from)
{
    // Self - assignment doesn't hurt here, so we don't check for it !
    m_code = from.m_code;
    return *this;
}// operator=

/*  ----------------------------------------------------------------------
    IsError
    ---------------------------------------------------------------------- */
BOOLEAN ObexResult::IsError()
const
{
    return (m_code != Success);
}// IsError

/*  ----------------------------------------------------------------------
    IsOk
    ---------------------------------------------------------------------- */
BOOLEAN ObexResult::IsOk()
const
{
    return (m_code == Success);
}// IsOk

/*  ----------------------------------------------------------------------
    operator BOOLEAN
    ---------------------------------------------------------------------- */
ObexResult::operator BOOLEAN()
const
{
    return IsOk();
}// BOOLEAN

/*  ----------------------------------------------------------------------
    GetErrorCode
    ---------------------------------------------------------------------- */
ObexResult::ErrorCode   ObexResult::GetErrorCode()
const
{
    return m_code;
}// GetErrorCode

#endif  // Apoxi_ObexResult_hpp

