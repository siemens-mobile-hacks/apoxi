/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DrmUtils_hpp)
#define Apoxi_DrmUtils_hpp


class DrmUtils{
    public :
        static BOOLEAN DecodeBase64Data(UINT8* base64data, INT base64len, UINT8** decoded_buf, INT* buflen);
} ;

#endif // Apoxi_DrmUtils_hpp

