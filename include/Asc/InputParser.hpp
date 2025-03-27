/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(_Asc_InputParser_hpp)
#define _Asc_InputParser_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/WString.hpp>


enum LexToken {
    StarToken,
    HashToken,
    StringToken,
    EosToken,
    InvalidToken
};


class LexAnalyzer 
{
    public:
        LexAnalyzer() : m_len(0), m_idx(0), m_startidx(0) {}
        explicit LexAnalyzer(const WString & ssstring);
        ~LexAnalyzer(); 
        
        LexToken GetFirstLexToken(WString & retparam);
        LexToken GetNextLexToken(WString & retparam);
        void JumpBack();
        void GetRest(WString & rest);
       
    private:        
        const WString m_string;
        const INT m_len;
        INT   m_idx;
        INT   m_startidx;
        
};


//lint -e{1712} suppress Info default constructor not defined for class 'InputParser'
class InputParser 
{
    public:
        enum SsProcedure {   // dont change order, range operations are done
            Activation,
            Deactivation,
            Registration,
            Erasure,
            Interrogation,
            InvalidProcedure
        };

        enum SsCode {   // dont change order, range operations are done on enums
            CLIP,                   // 30
            CLIR,                   // 31
            COLP,                   // 76
            COLR,                   // 77

// forwarding services must be in range -------------
            CFU,                    // 21
            CFBusy,                 // 67
            CFNoReply,              // 61
            CFNotReachable,         // 62
            AllCF,                  // 002
            AllConditionalCF,       // 004
//---------------------------------------------------


// barring services must be in range ----------------
            BAOC,                    // 33
            BAOIC,                   // 331
            BAOICexchome,            // 332  
            BAIC,                    // 35
            BAICroaming,             // 351
            AllBarrServices,         // 330
            OutgBarrServices,        // 333
            IncBarrServices,         // 353
// --------------------------------------------------

            ChangePin,               // 04
            ChangePin2,              // 042
            UnblockPin,              // 05
            UnblockPin2,             // 052
            Wait,                   // 43
            UUSService1,            // 361
            UUSService2,            // 362
            UUSService3,            // 363
            AllUUSServices,         // 360
            ECT,                     // 96
            CCBS,                    // 37
            FM,                      // 214
            CNAP,                    // 300
            MSP,                     // 59n  where n=1-4
            MC,                      // 88
            RegisterNewPassword,     // 03
            EMLPP,                  // 75 or 75n n=0-4
            CD,                     // 66
            AllSsServices,          // <empty> for passwordchange
            InvalidSsCode
        };

        enum BasicServiceMmiCode {   
            AllServices,                // empty string
            AllTeleServices,            // 10
            Telephony,                  // 11
            AllDataServices,            // 12
            FacsimileServices,          // 13
            ShortMessageServices,       // 16
            AllTeleServicesExceptSMS,   // 19
            VoiceGroupCallService,      // 17
            VoiceBroadcastService,      // 18
            AllBearerServices,          // 20
            AllAsyncServices,           // 21
            AllSyncServices,            // 22
            AllDataCircuitSync,         // 24
            AllDataCircuitAsync,        // 25
            AuxiliarySpeech,            // 89   CPHS !!!
            AllGPRSBearerServices,      // 99
            InvalidServiceGroup
        };

        InputParser() {}
        explicit InputParser(const WString & ssstring);
        ~InputParser(); 
        
        SsProcedure GetSsProcedure();
        SsCode      GetSsCode(INT & additionaldigit);
        SsCode      GetSsCode(const WString & ssstring, INT & additionaldigit);

        LexToken    GetNextToken(WString & parsedstring) {
            return m_lex.GetNextLexToken(parsedstring);
        }
        void GetRest(WString & parsedstring) {
            m_lex.GetRest(parsedstring);
        }
        
        static const WCHAR * GetSSProcedureString(SsProcedure procedure);
        static const WCHAR * GetSSCodeString(SsCode code);
        static const WCHAR * GetBasicServiceMmiCodeString(InputParser::BasicServiceMmiCode code);
        static InputParser::BasicServiceMmiCode GetBasicServiceMmiCode(const WString & bsgstring);
       
    private:
        LexAnalyzer m_lex;
       
};

 
#endif


