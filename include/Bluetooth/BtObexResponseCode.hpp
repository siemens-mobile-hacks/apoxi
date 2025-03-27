/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BtObexResponseCode_hpp)
#define Apoxi_BtObexResponseCode_hpp


class BtObexResponseCode
{
    public:
        enum ResponseCode {
            // Success
            Success                     = 0x20,
            Continue                    = 0x10,
            PartialContent              = 0x26,

            // Error Codes
            BadRequest                  = 0x40,
            NotImplemented              = 0x51,
            Forbidden                   = 0x43,
            Unauthorised                = 0x41,
            PreconditionFailed          = 0x4C,
            NotFound                    = 0x44,
            NotAcceptable               = 0x46,
            ServiceUnavailable          = 0x53,

            // Unspecified error
            Unspecified                 = 0x7F
        };

        static inline BtObexResponseCode Ok();

        inline BtObexResponseCode(ResponseCode  obex_resp_code = Unspecified, BOOLEAN final_flag = FALSE);

        inline BtObexResponseCode(UINT8 obex_resp_code);

        inline BtObexResponseCode(const BtObexResponseCode &  from);

        inline BtObexResponseCode & operator=(const BtObexResponseCode &  from);

        inline BOOLEAN IsError() const;

        inline BOOLEAN IsOk() const;

        inline BOOLEAN IsFinal() const;
    
        inline BOOLEAN IsFinished() const;

        inline operator BOOLEAN() const;

        inline ResponseCode GetObexResponseCode() const;

        inline UINT8 GetObexResponseCodeByte() const;

    private:
        UINT8       m_obex_resp_code;   
};

/*  ----------------------------------------------------------------------
    Ok
    ---------------------------------------------------------------------- */
BtObexResponseCode  BtObexResponseCode::Ok()
{
    return  BtObexResponseCode(Success, TRUE);
}// Ok

/*  ----------------------------------------------------------------------
    BtObexResponseCode
    ---------------------------------------------------------------------- */
BtObexResponseCode::BtObexResponseCode(ResponseCode  obex_resp_code, BOOLEAN final_flag)
{
    m_obex_resp_code = obex_resp_code;

    if (final_flag) {
        m_obex_resp_code = (ResponseCode)(m_obex_resp_code | 0x80);
    }
}// BtObexResponseCode

/*  ----------------------------------------------------------------------
    BtObexResponseCode
    ---------------------------------------------------------------------- */
BtObexResponseCode::BtObexResponseCode(UINT8 obex_response_code) :
    m_obex_resp_code(obex_response_code)
{
}// BtObexResponseCode

/*  ----------------------------------------------------------------------
    BtObexResponseCode
    ---------------------------------------------------------------------- */
BtObexResponseCode::BtObexResponseCode(const BtObexResponseCode &  from) :
    m_obex_resp_code( from.m_obex_resp_code )
{
}// BtObexResponseCode

/*  ----------------------------------------------------------------------
    operator=
    ---------------------------------------------------------------------- */
BtObexResponseCode &    BtObexResponseCode::operator=(const BtObexResponseCode &  from)
{
    // Self - assignment doesn't hurt here, so we don't check for it !
    m_obex_resp_code = from.m_obex_resp_code;
    return *this;
}// operator=

/*  ----------------------------------------------------------------------
    IsError
    ---------------------------------------------------------------------- */
BOOLEAN BtObexResponseCode::IsError() const
{
    return ((m_obex_resp_code & 0x7F) > 0x30);
}// IsError

/*  ----------------------------------------------------------------------
    IsOk
    ---------------------------------------------------------------------- */
BOOLEAN BtObexResponseCode::IsOk() const
{
    return ((m_obex_resp_code & 0x7F) < 0x30);
}// IsOk

/*  ----------------------------------------------------------------------
    IsFinal
    ---------------------------------------------------------------------- */
BOOLEAN BtObexResponseCode::IsFinal() const
{
    return (m_obex_resp_code & 0x80);
}// IsOk

/*  ----------------------------------------------------------------------
    operator BOOLEAN
    ---------------------------------------------------------------------- */
BOOLEAN BtObexResponseCode::IsFinished() const
{
    return (GetObexResponseCode() != Continue);
}

/*  ----------------------------------------------------------------------
    operator BOOLEAN
    ---------------------------------------------------------------------- */
BtObexResponseCode::operator BOOLEAN() const
{
    return IsOk();
}// BOOLEAN

/*  ----------------------------------------------------------------------
    GetObexResponseCode
    ---------------------------------------------------------------------- */
BtObexResponseCode::ResponseCode BtObexResponseCode::GetObexResponseCode() const
{
    return (ResponseCode)(m_obex_resp_code & 0x7F);
}// GetErrorCode

/*  ----------------------------------------------------------------------
    GetObexResponseCodeByte
    ---------------------------------------------------------------------- */
UINT8 BtObexResponseCode::GetObexResponseCodeByte() const
{
    return m_obex_resp_code;
}// GetErrorCode

#endif  // Apoxi_BtObexResponseCode_hpp

