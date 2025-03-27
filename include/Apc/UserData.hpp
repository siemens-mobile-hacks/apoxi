/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_UserData_hpp)
#define Apc_UserData_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BlobObject.hpp>
#include <Auxiliary/WString.hpp>

#include <Apc/DataCodingScheme.hpp>
#include <Apc/InformationElement.hpp>


/*  ========================================================================
    UserDataHeader - 3GPP 23.040 V5.1.0 [9.2.3.24.1-12]
    ======================================================================== */
class UserDataHeader {
    public:
        UserDataHeader();

        UserDataHeader(UINT8 *data_header_anchor, INT max_size = -1);

        void Init(UINT8 *data_header_anchor);

        BOOLEAN IsValid() const { return m_data_header_anchor!=0; }

        INT GetLength() const;
        void SetLength(INT length);
        const UINT8* GetData() const;
        UINT8* GetData();

        UINT8 GetSize() const;
        const UINT8* GetStartAddress() const { return (m_data_header_anchor); }

        InformationElement GetFirstInformationElement();

        InformationElement GetNextInformationElement();

        BOOLEAN HasMoreInformationElements() const;

        INT GetRemainingSize() const;
        BOOLEAN Append(const InformationElement& information_element);


    private:
        UINT8 *m_data_header_anchor;
        INT m_iterator_idx;
        INT m_max_size;
};


/*  ========================================================================
    UserData - 3GPP 23.040 V5.1.0 [9.2.3.24]
    ======================================================================== */
class UserData {
    public:
        //
        UserData();
        UserData(UINT8 *data_anchor, INT max_user_data_size = 0, BOOLEAN header_exists = FALSE, const DataCodingScheme &dcs = DataCodingScheme());
        ~UserData();
        void Init(UINT8 *data_anchor = 0, INT max_user_data_size = 0, BOOLEAN header_exists = FALSE, const DataCodingScheme &dcs = DataCodingScheme());

        BOOLEAN HeaderExists() const;
        UserDataHeader GetUserDataHeader() const;

        INT GetSize() const;
        const UINT8* GetStartAddress() const { return (m_data_anchor); }

        INT GetLength() const;
        void SetLength(INT length);
        const UINT8* GetData() const;
        UINT8* GetData();

        INT GetTextData(UINT8 *&text, UINT8 &padding) const;
        
        INT GetTextDataLength() const;

        INT GetPayloadSize() const;
        INT GetPayloadOffset() const;
        
        void Read(WString &text) const;
        WString Read() const;

        void ReadPayloadData(BlobObject &blob) const;
        BlobObject ReadPayloadData() const;

        INT Write(const WString &text);

        INT WritePayloadData(const BlobObject &blob);

        void Reset();

        INT GetRemainingSize() const;

        BOOLEAN Append(const InformationElement &information_element);


        static INT CalculateUserDataSize(INT header_size, INT &data_length, const WString *text,
                                         INT text_length, DataCodingScheme::Alphabet alphabet);

    private:
        UINT8 *m_data_anchor;
        INT m_max_size;
        BOOLEAN m_header_exists;
        DataCodingScheme m_dcs;

        // Returns the correct length (septets or octets) depending on the alphabet.
        static INT CalculateLength(INT bytes, DataCodingScheme::Alphabet alphabet, UINT8 *padding = 0);

        // Returns the correct size (in bytes) depending on the alphabet.
        static INT CalculateSize(INT length, DataCodingScheme::Alphabet alphabet);
};


#endif  // Apc_UserData_hpp


