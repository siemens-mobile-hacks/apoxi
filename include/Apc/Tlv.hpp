/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Tlv_hpp)
#define Apc_Tlv_hpp

#include <Kernel/Types.hpp>

/*  ========================================================================
                                  types
    ======================================================================== */
typedef UINT8 TlvAtom;

/*  ========================================================================
                                constants
    ======================================================================== */
const UINT8 c_tlv_len_byte_mask = 0x80;  
const UINT8 c_tlv_two_byte_len_sign = 0x81;  

/*  ========================================================================
                                  enums
    ======================================================================== */
enum Nai {
    NaiInvalid = 0x00,
    NaiSetupCall = 0x10,
    NaiSendSs = 0x11,
    NaiSendUssd = 0x12,
    NaiSendShortMessage = 0x13,
    NaiLaunchBrowser = 0x15,
    NaiPlayTone = 0x20,
    NaiDisplayText = 0x21,
    NaiGetInkey = 0x22,
    NaiGetInput = 0x23,
    NaiSelectItem = 0x24,
    NaiSetupMenu = 0x25,
    NaiProvideLocalInformation = 0x26,  
    NaiSetupIdleModeText = 0x28,
    NaiPerformCardApdu = 0x30,
    NaiPowerOnCard = 0x31,
    NaiPowerOffCard = 0x32,
    NaiGetReaderStatus = 0x33,
    NaiOpenChannel = 0x40,
    NaiCloseChannel = 0x41,
    NaiReceiveData = 0x42,
    NaiSendData = 0x43,
    NaiGetChannelStatus = 0x44,
    NaiEndOfProactiveSession = 0x81,
};

enum Toc {
    TocInvalid                  = 0x00,
    TocRefresh                  = 0x01,
    TocMoreTime                 = 0x02,
    TocPollIntervall            = 0x03,
    TocPollingOff               = 0x04,
    TocSetUpEventList           = 0x05,
    TocSetupCall                = 0x10,
    TocSendSs                   = 0x11,
    TocSendUssd                 = 0x12,
    TocSendShortMessage         = 0x13,
    TocSendDtmf                 = 0x14,
    TocLaunchBrowser            = 0x15,
    TocPlayTone                 = 0x20,
    TocDisplayText              = 0x21,
    TocGetInkey                 = 0x22,
    TocGetInput                 = 0x23,
    TocSelectItem               = 0x24,
    TocSetupMenu                = 0x25,
    TocProvideLocalInformation  = 0x26,
    TocTimerManagement          = 0x27,
    TocSetupIdleModeText        = 0x28,
    TocPerformCardApdu          = 0x30,
    TocPowerOnCard              = 0x31,
    TocPowerOffCard             = 0x32,
    TocGetReaderStatus          = 0x33,
    TocRunAtCommand             = 0x34,
    TocLanguageNotification     = 0x35,
    TocOpenChannel              = 0x40,
    TocCloseChannel             = 0x41,
    TocReceiveData              = 0x42,
    TocSendData                 = 0x43,
    TocGetChannelStatus         = 0x44,
    TocEndOfProactiveSession    = 0x81,
};

enum SimStatusCondition {
    SscNormalEnding             = 0x90,
    SscNormalEndingExtra                = 0x91,
    SscDataDownloadResponse             = 0x9E,
    SscOtherResponse                    = 0x9F,
    SscPostponedResponse                = 0x93,
    SscMemoryManagementResponse         = 0x92,
    SscReferencingManagementResponse    = 0x94,
    SscSecurityManagementResponse       = 0x98,
    SscIncorrectParameterP3             = 0x67,
    SscIncorrectParameterP1_P2          = 0x6B,
    SscUnknownInstruction               = 0x6D,
    SscWrongInstruction                 = 0x6E,
    SscTechnicalProblem                 = 0x6F
};

/*  ========================================================================
    Tlv
    ======================================================================== */
class Tlv {
    public:
        enum LengthCoding {
            OneByte = 1, 
            TwoByte = 2 
        };

        enum Tag {  // this list holds only the actual needed tags
            UndefinedTag = 0x00,
            AlphaIdentifierTag = 0x05,
            TextStringTag = 0x0D,
            ItemTag = 0x0F,
            ItemIdentifierTag = 0x10,
            ItemsNaiTag = 0x18,
            IconIdentifierTag = 0x1E,
            ItemIconIdentifierListTag = 0x1F,
        };

        Tlv(const TlvAtom *byte_stream = 0, const LengthCoding len_coding = OneByte);
        Tlv(const Tag tag, const INT val_len = 0, const TlvAtom *val_data = 0);
        Tlv(const Tlv& tlv);
        Tlv& operator =(const Tlv &tlv);
        virtual ~Tlv();
        
        Tag GetTag() const { return ((Tag) (m_tag & 0x7F)); }

        INT GetStreamSize() const { return (m_stream_size); }       

        INT GetValLen() const { return (m_val_len); }
        const TlvAtom* GetValPtr() const { return (m_val_data); }

        BOOLEAN IsComprehensionRequired() const { return ((m_tag & 0x80) == 0x80); }

    private:
        Tag m_tag;
        INT m_val_len;
        TlvAtom *m_val_data;
        INT m_stream_size;

        void Clear();
};


#endif  // Apc_Tlv_hpp

