/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtJsr82Url_hpp)
#define BtJsr82Url_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */


class BtJsr82Url
{
    // Forward declarations
    public:
        class Token;

    private:
        class Scanner;

        friend class Scanner;
        friend class Token;

    public:
        class Token {

            friend class Scanner;

            public:
                enum TypeId {
                    TUnknown,       // Unknown yet, currently being assembled
                    TAmbigous,      // Context-dependent, look at properties

                    TScheme,        // Protocol identifier in URL
                    TBadInput,      // Illegal character in input stream
                    TEndInput,      // End of input (not necessarily an error)

                    TColon,         // Separators
                    TEqual,
                    TSemicolon,
                    TComma,
                    TDot,
                    TAsterix,
                    TSlashes,

                    TDecNumber,
                    THexNumber,
                    TText,

                    TLocalhost,
                    TAuthenticate,  // Keywords / predefined identifiers
                    TAuthorize,
                    TEncrypt,
                    TMaster,
                    TName,
                    TFalse,
                    TTrue
                };

                struct  Keyword {
                    const CHAR *        text_ptr;
                    TypeId              type_id;
                };

                inline  TypeId          GetTypeId()
                const
                {
                    return  m_type;
                }

                inline  const String &  GetValue()
                const
                {
                    return  m_value;
                }

                inline  BOOLEAN         IsOfType(TypeId     type_id)
                const
                {
                    return  ( type_id == m_type );
                }

                BOOLEAN                 MatchesType(TypeId  type_id) const;

            private:
                class StrCaseCmp;

                enum Property {
                    HasDecDigits,
                    HasHexDigits,
                    HasLetters,
                    HasDash,
                    HasUnderscore,
                    HasWhitespace
                };

                enum {

                    KeywordMask = ( (1 << HasDecDigits)  |
                                    (1 << HasDash)       |
                                    (1 << HasUnderscore) |
                                    (1 << HasWhitespace)   ),

                    SchemeMask  = ( (1 << HasDash)       |
                                    (1 << HasUnderscore) |
                                    (1 << HasWhitespace)   ),

                    DecNumMask  = ( (1 << HasHexDigits)  |
                                    (1 << HasLetters)    |
                                    (1 << HasDash)       |
                                    (1 << HasUnderscore) |
                                    (1 << HasWhitespace)   ),

                    HexNumMask  =( (1 << HasLetters)     |
                                   (1 << HasDash)        |
                                   (1 << HasUnderscore)  |
                                   (1 << HasWhitespace) ),
                };

                static  const Keyword   s_keywords[];

                String                  m_value;
                TypeId                  m_type;
                BitField8               m_props;

                Token();

                void                    Reset();

                void                    Append(CHAR ch, Property    p);

                void                    SetType(TypeId  type_id);
                void                    SetType();
        };

        enum UrlType {
            UnknownUrlType,
            ClientUrlType,
            ServerUrlType
        };

        enum Parameter {
            // Boolean parameters
            PAuthenticate,
            PAuthorize,
            PEncrypt,
            PMaster,

            // Text parameters
            PName
        };

        enum Result {
            RParsing,                   
            RSuccess,                   
            RSyntaxErr,                 
            RParameterDuplicatedErr,    
            RParameterValueRangeErr,    
            RSecuritySettingsErr        
        };

        BtJsr82Url(const String &   url_str,
                   UrlType          url_type = UnknownUrlType);

        inline  Result      GetResult()
        const
        {
            return  m_result;
        }

        inline  BOOLEAN     IsUrlValid()
        const
        {
            return  ( m_result == RSuccess );
        }

        inline  UrlType     GetUrlType()
        const
        {
            return  m_url_type;
        }

        BOOLEAN             GetParamValue(Parameter     param,
                                          BOOLEAN &     value) const;

        BOOLEAN             GetParamValue(Parameter     param,
                                          String &      value) const;

        BOOLEAN             GetBtService(BtUUID &   uuid) const;

        BOOLEAN             GetBtAddress(BtDeviceAddress &  bt_addr) const;

        inline  UINT8       GetBtChannel() const
        {
            return  m_channel;
        }

        BOOLEAN             GetSecuritySettings(BtSecuritySettings &    ses) const;

    private:
        class StringReader {

            public:
                enum {
                    EndOfInput = '\0'
                };

                StringReader(const String &     input);

                CHAR    GetNextChar();

            private:
                String  m_input;
                INT     m_pos;
        };

        class Scanner {
            public:
                Scanner(const String &  text);

                static  BOOLEAN     IsHexDigit(CHAR         ch)
                {
                    return  ( Between(ch, 'a', 'f') || Between(ch, 'A', 'F') );
                }

                static  BOOLEAN     IsAlpha(CHAR            ch)
                {
                    return  ( Between(ch, 'a', 'z') || Between(ch, 'A', 'Z') );
                }

                static  BOOLEAN     IsDecDigit(CHAR         ch)
                {
                    return  Between(ch, '0', '9');
                }

                static  BOOLEAN     HexStringToOctetSeq(UINT8 *         oct_seq_buf,
                                                        UINT            oct_seq_len,
                                                        String const &  hex_str);

                void                    Advance();

                inline  const Token &   GetToken()
                {
                    return  m_token;
                }

            private:
                StringReader        m_reader;
                Token               m_token;
                CHAR                m_lookahead;

                void    HandleCharacter(Token::Property     p);
                void    HandleSeparator();
        };

        Scanner             m_scanner;
        UrlType             m_url_type;
        Result              m_result;
        String              m_name;
        String              m_addr;                 //  Client: Device address
                                                    //  Server: UUID
        UINT8               m_channel;              //  Client: RFComm channel
        BitField8           m_param_set;
        BitField8           m_bool_values;          //  BOOLEAN parameter values
        BOOLEAN             m_is_strictly_jsr82;
        BOOLEAN             m_is_wildcard_url;      //  address contains '*://'

        inline  BOOLEAN     IsParsing()
        const
        {
            return  ( m_result == RParsing );
        }

        inline  BOOLEAN     IsStrictlyJsr82() const
        {
            return  m_is_strictly_jsr82;
        }

        inline  BOOLEAN     IsWildcardUrl() const
        {
            return  m_is_wildcard_url;
        }

        inline  BOOLEAN     IsBoolean(Parameter     p)
        const
        {
            return  ( p < PName );
        }

        inline  BOOLEAN     IsText(Parameter        p)
        const
        {
            return  ( p >= PName );
        }

        BtJsr82Url(const BtJsr82Url &);
        BtJsr82Url &        operator=(const BtJsr82Url &);

        void                SetError(Result     err_code);

        void                SetParamValue(Parameter     param,
                                          BOOLEAN       value);

        void                MatchToken(Token::TypeId    t);

        void                Parse();
        void                ParseProtocol();
        void                ParseHost();
        void                ParseClientHost();
        void                ParseServerHost();
        void                ParseParamList();
        void                ParseParameter();
        void                ParseBoolParam(Parameter    p);
        void                ParseTextParam(Parameter    p);

        void                CheckParameter(Parameter    p);
        void                CheckDepSecurityParam(Parameter p);
};

#endif  // BtJsr82Url_hpp

