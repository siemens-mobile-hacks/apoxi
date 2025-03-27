/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DrmDcfParser_hpp)
#define Apoxi_DrmDcfParser_hpp

//#define DRM_DCF_TEST

#include <Auxiliary/BufferedData.hpp>
#include <Auxiliary/BinData.hpp>
#include <AddOns/Drm/Drm.hpp>

// Dcf header name strings
#define ENCRYPTION_METHOD_STR   "Encryption-Method"
#define PADDING_STR             "padding"
#define RIGHT_ISSUER_STR        "Rights-Issuer"
#define CONTENT_NAME_STR        "Content-Name"
#define CONTENT_DESCRIPTION_STR "Content-Description"
#define CONTENT_VENDOR_STR      "Content-Vendor"
#define ICON_URI_STR            "Icon-URI"

// Error code, this could be memory fail/parse error
#define DRM_DCF_ERROR         -1
#define DRM_DCF_INVALID_BLOCK -2

#define DCF_SKIP_SPACE(b, l) while(*b == ' ' || *b == '\t') { b++; l--; }
#define DCF_VALIDATE_DATA_SIZE(total_size, curr_size) if (total_size < curr_size) return FALSE;


typedef struct DrmDcfHeaderData {
    String m_name;
    String m_value;
} DrmDcfHeaderData;

typedef struct DrmDcfHeader {
    Vector<DrmDcfHeaderData> m_header;
} DrmDcfHeader;

class DrmDcfParser {
    public:
        
        enum DrmDcfHeaderType {
            DrmDcfEncryptionMethod = 0,
            DrmDcfPaddingScheme,
            DrmDcfRightsIssuer,
            DrmDcfContentName,
            DrmDcfContentDescription,
            DrmDcfContentVendor,
            DrmDcfIconUriHeader,
            DrmDcfUnSupported
        };

        DrmDcfParser(const BinData* bd);
        DrmDcfParser();

        ~DrmDcfParser();

        void SetDrmDcfMessage(const BinData* bd);

        BOOLEAN GetVersion(UINT8& version) const;

        BOOLEAN GetContentType(String& content_type);

        BOOLEAN GetContentId(String& content_id);

        BOOLEAN GetDcfHeader(enum DrmDcfHeaderType header_type, String &data);
        
        BOOLEAN GetDcfHeader(const CHAR* header_name, String& header_value);

        BOOLEAN GetDcfHeader(DrmDcfHeader &header);

        INT GetMediaObjectLen();

        INT GetMediaObjectOffSet();

        INT GetBlockDataOffSet(INT block_num, INT block_sz, INT &new_block_sz);

    private:
        // Points to user data
        const BinData* m_dcf_message;

        // Holds entire DCF message header only, 
        // By having this we can avoid the entire bin data message reading into an buffer
        UINT8* m_msg_header;

        INT m_ct_len;
        INT m_cid_len;
        INT m_dcf_hdr_len;
        INT m_dcf_hdr_byte_count;
        INT m_data_len;
        INT m_data_byte_count;
        INT m_dcf_hdr_offset;
        INT m_data_offset;

        // Helper functions
        BOOLEAN ParseMsgHeader();
        INT GetMbToInt(UINT8 *bytes, INT byte_count);
        INT GetHeaderData(CHAR* data, INT data_len, CHAR* h_name, DrmDcfHeaderData &h_data);
        BOOLEAN GetHeaderValue(CHAR* data, INT data_len, String &value, INT flag);
        BOOLEAN ParseMbOctets(INT start_offset, INT flag);
        INT ParseUserDefinedHeaders(CHAR* data, INT data_len, DrmDcfHeaderData &h_data);
#ifdef DRM_DCF_TEST
        void DisplayParameters();
#endif //DRM_DCF_TEST
};

#endif // Apoxi_DrmDcfParser_hpp

