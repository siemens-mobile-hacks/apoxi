/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DrmSecurity_hpp)
#define Apoxi_DrmSecurity_hpp

#include <Adc/DataHandler.hpp>
#include <Adc/SimAccessor.hpp>
#include <Apc/SignalTypes.hpp>

//Enable this for testing on host
//#define DRM_SECURITY_TEST

//Enable this for HOST only
//#define DRM_SECURITY_HOST_TESTING

//Enable this when NO encryption is required
//#define DRM_SEURITY_NO_ENCRYPTION

#define DRM_SECURITY_KEY_LEN 10
#define DRM_SECURITY_MAGIC_NUMBER 7

class DrmSecurity {
    public:

        DrmSecurity() { };
        ~DrmSecurity() { };

        static BOOLEAN DrmCrypt(UINT8 *in_buf, INT buf_len);

        static void InitializeKey();

    private:
        static UINT8 key[DRM_SECURITY_KEY_LEN];
        static BOOLEAN drm_key_init;
#ifdef DRM_SECURITY_TEST
        static void DumpKey();
#endif //DRM_SECURITY_TEST
};

#endif //Apoxi_DrmSecurity_hpp


