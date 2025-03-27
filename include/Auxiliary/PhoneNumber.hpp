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

#if ! defined(_Adc_PhoneNumber_hpp)
#define _Adc_PhoneNumber_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/TypeOfAddress.hpp>

/*------------------------------------------------------------------
                            PhoneNumber
 ------------------------------------------------------------------*/

enum BCDConversionNibble { DtmfValue = 0xC , WildcardValue = 0xD, ExpansionValue = 0xE };

const INT   c_max_bcd_number_size = 0x18;
const INT   c_max_telnr_size =      (c_max_bcd_number_size - 4) * 2;
const UINT8  c_invalid_nibble =      0xFF;
const UINT8  c_max_nibble_range =    0x18;

#if ! defined(APOXI_PHONENUMBER_MATCH_DEFAULT_DEPTH)
    const INT c_default_depth = 6;
#else
    const INT c_default_depth = APOXI_PHONENUMBER_MATCH_DEFAULT_DEPTH;
#endif  

//typedef UINT16 Key;

class PhoneNumber
{
    public:

        typedef UINT16 Key;

        enum PresentationIndicator
        {
            PresentationAllowed = 0,
            PresentationRestricted = 1,
            NumberNotAllowed = 2,
            PresentationReserved = 3,
            PresentationUndefined = 0xff
        };

        enum ScreeningIndicator
        {
            NotScreened = 0,
            VerifiedAndPassed = 1,
            VerifiedAndFailed = 2,
            NetworkProvided = 3,
            ScreeningUndefined = 0xff
        };


        enum Type {
                 In,
                 Out,
                 Tpdu,
                 Invalid
        };

        struct Persist {
            UINT8   m_persist[c_max_bcd_number_size + 1];
        };

        PhoneNumber();

        PhoneNumber(const PhoneNumber & number);

        PhoneNumber(const PhoneNumber * number);

        PhoneNumber(Type type, const UINT8 * rawbcd);

        PhoneNumber(UINT8 tonnpi, UINT8 datalen, UINT8 * data);

        PhoneNumber(Type type, const WString & telnr);

        PhoneNumber(Type type, const WCHAR * telnr);

        ~PhoneNumber();

        Type GetType() const { return m_type; };

        Key GetKey() const { return 0; }

        BOOLEAN ChangeType(Type type);


        BOOLEAN IsInvalid() const { return (m_type == Invalid); }

        BOOLEAN IsEmpty() const { return (m_bcd_number[0] == 0); }

        void Clear() { Reset(); }

        INT GetNumOfValidDigits() const;

        INT GetBCDLength() const;

        INT GetRawBCDLength() const {
            return (INT)GetBCDLength()+1;
        }
        static INT GetRawBCDLength(Type type, const UINT8 * buffer);

        static BOOLEAN IsStorable(const WCHAR * phnostring);

        UINT8 * GetBCD() const { return (UINT8*)&m_bcd_number[1]; };

        UINT8 * GetRawBCDBuffer() const { return (UINT8*)&m_bcd_number[0]; };

        PresentationIndicator  GetPresentationInd() const;

        ScreeningIndicator  GetScreeningInd() const;

        BOOLEAN  IsPresentationAllowed() const;
        
        BOOLEAN  HasClirOverrideCategory() const;

        TypeOfAddress::TypeOfNumber GetTON() const;

        TypeOfAddress::NumberingPlanIdentification GetNPI() const;

        UINT8   GetTONNPI() const { return m_bcd_number[1]; }

        String  GetString() const;

    /*  @param override_presentation_indicator If true, the real phone number is returned although
                the caller has CLIR activated */
        WString GetWString() const;

        BOOLEAN HasDtmf() const;

        PhoneNumber GetNonDtmfPhoneNumber() const;

        BOOLEAN     IsMatching(const PhoneNumber & right) const;

        BOOLEAN     IsMatching(const PhoneNumber & right, INT depth) const;

        INT Compare(const PhoneNumber & right) const;

        static INT Compare(const PhoneNumber & ph1, const PhoneNumber & ph2) { return ph1.Compare(ph2); }

        PhoneNumber & operator = (const PhoneNumber * value);

        PhoneNumber & operator = (const PhoneNumber & value);

        BOOLEAN     operator ==(const PhoneNumber & right) const;

        BOOLEAN     operator <(const PhoneNumber & right) const;

        BOOLEAN     operator >(const PhoneNumber & right) const;

        static WCHAR BcdNibbleToWChar(UINT8 value) { return m_bcd_to_wchar[value & 0x0F]; };

        static UINT8 WCharToBcdNibble(WCHAR value);

        static void SetWCharForBcdCode(BCDConversionNibble nibble, WCHAR character);

        static WCHAR GetWCharForBcdCode(UINT8 nibble);

        static void SetEmptyNumberText(const WCHAR* text) { m_empty_number_text = text; }

        static void SetInvalidNumberText(const WCHAR* text) { m_invalid_number_text = text; }

        static void SetRestrictedNumberText(const WCHAR* text) { m_restricted_number_text = text; }

        static void SetNumberNotAvailableText(const WCHAR* text) { m_number_not_available_text = text; }

        INT TransformToReversedByteBuffer(UINT8 * buffer, INT len) const;
        INT TransformToWCharBuffer(WCHAR * buffer, INT len) const;
        void operator<<(const PhoneNumber::Persist & phonenumber);
        void operator>>(PhoneNumber::Persist & phonenumber) const;
        UINT16 GetHashValue() const;

    protected:
        UINT8   m_bcd_number[c_max_bcd_number_size];
        Type    m_type;

    private:
        BOOLEAN ConvertWStringToBCD(const WString & telnr, INT & digits, UINT8 & tonnpi);

        void Reset();

        static WCHAR m_bcd_to_wchar[c_max_nibble_range];
        static const WCHAR* m_empty_number_text;
        static const WCHAR* m_invalid_number_text;
        static const WCHAR* m_restricted_number_text;
        static const WCHAR* m_number_not_available_text;
};

#if !defined(APOXI_PHONENUMBER_TEST_SUITE) && defined(APOXI_RTOS_WIN32)
#define APOXI_PHONENUMBER_TEST_SUITE
#endif
#if defined(APOXI_PHONENUMBER_TEST_SUITE)
    void PhoneNumberTest();
#endif



#endif


