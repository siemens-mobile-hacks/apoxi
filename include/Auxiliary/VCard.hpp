/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifndef Apoxi_VCard_hpp
#define Apoxi_VCard_hpp

#include <Auxiliary/WString.hpp>

#define APOXI_VCARD_ADDRESS_MAX 2

#define APOXI_VCARD_NAME_COUNT 5
// order specified by vCard standard
#define APOXI_VCARD_NAME_FAMILY     0
#define APOXI_VCARD_NAME_GIVEN      1
#define APOXI_VCARD_NAME_ADD        2
#define APOXI_VCARD_NAME_PREFIX     3
#define APOXI_VCARD_NAME_SUFFIX     4

#define APOXI_VCARD_ADR_COUNT 7
// order specified by vCard standard
#define APOXI_VCARD_ADR_POSTOFFICE      0
#define APOXI_VCARD_ADR_EXTENDED        1
#define APOXI_VCARD_ADR_STREET          2
#define APOXI_VCARD_ADR_LOCALITY        3
#define APOXI_VCARD_ADR_REGION          4
#define APOXI_VCARD_ADR_POSTALCODE      5
#define APOXI_VCARD_ADR_COUNTRY         6

#define APOXI_VCARD_ORG_MAX 3

#define APOXI_VCARD_ORG_NAME            0
#define APOXI_VCARD_ORG_UNIT            1
#define APOXI_VCARD_ORG_ADDUNIT         2

// telephone type flags
#define APOXI_VCARD_TYPE_TEL_PREF   0x0001
#define APOXI_VCARD_TYPE_TEL_WORK   0x0002
#define APOXI_VCARD_TYPE_TEL_HOME   0x0004
#define APOXI_VCARD_TYPE_TEL_VOICE  0x0008
#define APOXI_VCARD_TYPE_TEL_FAX    0x0010
#define APOXI_VCARD_TYPE_TEL_MSG    0x0020
#define APOXI_VCARD_TYPE_TEL_CELL   0x0040
#define APOXI_VCARD_TYPE_TEL_PAGER  0x0080
#define APOXI_VCARD_TYPE_TEL_BBS    0x0010
#define APOXI_VCARD_TYPE_TEL_MODEM  0x0020
#define APOXI_VCARD_TYPE_TEL_CAR    0x0040
#define APOXI_VCARD_TYPE_TEL_ISDN   0x0080
#define APOXI_VCARD_TYPE_TEL_VIDEO  0x0100

#define APOXI_VCARD_TYPE_TEL_DEFAULT (APOXI_VCARD_TYPE_TEL_VOICE)

// address type flags
#define APOXI_VCARD_TYPE_ADR_DOM    0x0001
#define APOXI_VCARD_TYPE_ADR_INTL   0x0002
#define APOXI_VCARD_TYPE_ADR_POSTAL 0x0004
#define APOXI_VCARD_TYPE_ADR_PARCEL 0x0008
#define APOXI_VCARD_TYPE_ADR_HOME   0x0010
#define APOXI_VCARD_TYPE_ADR_WORK   0x0020

#define APOXI_VCARD_TYPE_ADR_DEFAULT (APOXI_VCARD_TYPE_ADR_INTL|APOXI_VCARD_TYPE_ADR_POSTAL|APOXI_VCARD_TYPE_ADR_PARCEL|APOXI_VCARD_TYPE_ADR_WORK)

class VCard
{
        friend class VCardParser;
        friend class VCardWriter;

    public:

        typedef UINT TelType;
        typedef UINT AdrType;

        VCard();
        
        VCard(const VCard &vCard);

        ~VCard();

        VCard& operator=(const VCard &vcard);

        UINT32 ReadBuffer(const CHAR* buffer, UINT32 buffer_len);
        
        UINT32 WriteBuffer(CHAR* buffer, UINT32 buffer_len) const;
        
        
        WString GetFormattedName() const;

        void SetFormattedName(const WString& formatted_name);
        
        
        WString GetFamilyName() const;

        void SetFamilyName(const WString& family_name);
        
        
        WString GetGivenName() const;
        
        void SetGivenName(const WString& given_name);
        
        
        WString GetAdditionalNames() const;
        
        void SetAdditionalNames(const WString& add_name);
        
        
        WString GetNamePrefix() const;
        
        void SetNamePrefix(const WString& name_prefix);
        
        
        WString GetNameSuffix() const;
        
        void SetNameSuffix(const WString& name_suffix);
        
        
        INT GetNumberOfAddresses() const;
        

        AdrType GetAddressType(UINT index = 0) const;
        
        void SetAddressType(AdrType address_type, UINT index = 0);
        

        WString GetPostOfficeAdress(UINT index = 0) const;
        
        void SetPostOfficeAddress(const WString& po_address, UINT index = 0);
        

        WString GetExtendedAddress(UINT index = 0) const;
        
        void SetExtendedAddress(const WString& ext_address, UINT index = 0);
        
        
        WString GetStreet(UINT index = 0) const;
        
        void SetStreet(const WString& street, UINT index = 0);
        

        WString GetLocality(UINT index = 0) const;
        
        void SetLocality(const WString& locality, UINT index = 0);
        

        WString GetRegion(UINT index = 0) const;
        
        void SetRegion(const WString& region, UINT index = 0);
        

        WString GetPostalCode(UINT index = 0) const;
        
        void SetPostalCode(const WString& postal_code, UINT index = 0);
        
        
        WString GetCountry(UINT index = 0) const;
        
        void SetCountry(const WString& country, UINT index = 0);
        

        WString GetEmail() const;
        
        void SetEmail(const WString& email);
        
        
        WString GetOrganizationName() const;
        
        void SetOrganizationName(const WString& org_name);
        
        
        WString GetOrganizationalUnit() const;
        
        void SetOrganizationalUnit(const WString& org_unit);
        

        WString GetAdditionalOrgUnit() const;
        
        void SetAdditionalOrgUnit(const WString& add_org_unit);
        

        WString GetTitle() const;
        
        void SetTitle(const WString& title);


        UINT GetTelNumberCount() const;
        

        WString GetTelNumber(UINT index = 0) const;

        void SetTelNumber(const WString& number, UINT index = 0);
        
        TelType GetTelNumberType(UINT index = 0) const;

        void SetTelNumberType(TelType tel_type, UINT index = 0);

        void AddTelNumber(const WString& number, TelType tel_types);
                
    private:
        void CleanUp();
        void SetNull();
        
        WString m_fn;                                       // formatted name
        WString m_names[APOXI_VCARD_NAME_COUNT];            // family name, given name, additional name, prefix, suffix

        /* address array:

            Post Office Address, Extended Address, Street, Locality, Region, Postal Code, and Country
        */
        WString             m_addresses[APOXI_VCARD_ADDRESS_MAX][APOXI_VCARD_ADR_COUNT];
        UINT                m_address_count;                // number of addresses in use
        /* address type array:
            the address type consists of an combination of address type flags
        */
        AdrType             m_address_types[APOXI_VCARD_ADDRESS_MAX];
        
        WString             m_orgs[APOXI_VCARD_ORG_MAX];    // organization properties
        
        WString             m_title;                        // job title
        WString             m_email;                        // email

        WString             *m_tel;                         // dynamic array of telephone numbers
        UINT                m_tel_count;                    // number of telephone numbers
        TelType             *m_tel_types;                   // dynamic array of telephone types
        
};

class VCardParser
{
    public:
        UINT32 ReadVCard(const CHAR* vcard_buffer, const UINT32 vcard_buffer_len, VCard* vcard);

    private:

        enum Encoding {
            None,
            Base64,
            QuotedPrintable
        };
        
        enum Charset {
            Ascii,
            Utf8
        };
        
        /* caseless compare (ASCII) */
        INT StrnCaseCmp(const CHAR *s1, const CHAR *s2, const UINT size) const;

        BOOLEAN Check(UINT amount) const;

        void ReadAdvance(INT amount);

        BOOLEAN IsWs(const CHAR b) const;

        void SkipWs();

        void SkipWsls();
        
        BOOLEAN ReadString(const CHAR *string, INT len);
        BOOLEAN ReadChar(const CHAR c);
        BOOLEAN ReadColon();
        BOOLEAN ReadSeparator();
        BOOLEAN ReadCrlf();
        
        void Canonical2Native(CHAR *buffer);
        void Canonical2Native(WCHAR *buffer);
        
        BOOLEAN ReadVCardBegin();
        BOOLEAN ReadVCardEnd();

        BOOLEAN ReadValue(WString& value, Encoding encoding, Charset charset);
        void ReadVector(const WString& value, WString vector[], UINT count) const;

        INT GetNextCrlfOffset(INT offset = 0) const;
        INT GetNextGroupOffset() const;
        INT GetNextParamOffset() const;
        INT GetNextParamValueOffset() const;
        INT GetNextItemNameOffset() const;
        
        INT GetNextItemNameIndex(INT offset) const;
        
        const CHAR*  m_vcard_buffer;
        const CHAR*  m_vcard_buffer_ptr;
        UINT32 m_vcard_buffer_len;
        UINT32 m_vcard_buffer_left;
};

class VCardWriter
{
    public:
        UINT32 WriteVCard(CHAR *buffer, UINT32 buffer_len, const VCard *vcard);

    private:

        BOOLEAN WriteBegin();

        BOOLEAN WriteEnd();

        void WriteAdvance(INT amount);

        BOOLEAN Write(const CHAR *data, UINT len);

        BOOLEAN WriteChar(const CHAR c);

        BOOLEAN WriteStr(const CHAR *s);
        
        BOOLEAN WriteWStr(const WString & ws);
        
        INT WriteQP(const CHAR *string, INT len);
        
        BOOLEAN WriteQPStr(const CHAR *string);
        
        BOOLEAN WriteQPUTF8(const WString& string);
        
        BOOLEAN WriteValue(const WString& value);
        
        INT GetCanonicalStrLen(const WString& string);
        
        WString GetCanonicalStr(const WString& string);
        
        BOOLEAN WriteOrganization();
        
        BOOLEAN WriteEmail();
        
        BOOLEAN WriteTelephoneNumbers();
        
        BOOLEAN WriteAddresses();
        
        BOOLEAN WriteName();
        
        BOOLEAN WriteTitle();
        
        const VCard     *m_vcard;
        CHAR            *m_write_buffer_ptr;
        UINT32          m_write_buffer_len;
        UINT32          m_write_buffer_left;
};

#endif // Apoxi_VCard_hpp

