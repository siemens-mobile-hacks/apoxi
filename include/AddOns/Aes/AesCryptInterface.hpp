#if !defined(AesCryptInterface_hpp)
#define AesCryptInterface_hpp

#include <Kernel/Types.hpp>

// AES currently is provided from Prof. Gladman's C implementation
// It currently supports the following features only (to reduce code size)
// Features chosen for DRM
//
//  - Decryption only
//  - 128 bit keysize
//  - CBC Mode
//  - 128 bit blocksize
//

enum AesError {
    AesErrorNone = 0,           // No Error
    AesGeneralError,            // General failure - no specific info available
    AesNoKey,                   // Key not set
    AesInvalidBlockWindow       // Invalid start_block end_block combination
};


class AesCrypt {
    public:
        enum PaddingMethod {
            PaddingMethod2630,          // RFC 2630
            PaddingMethodNone           // None
        };

        // Constructor
        AesCrypt() : m_last_error(AesErrorNone) {}
        // Destructor
        ~AesCrypt() {}

        void SetKey(const UINT8* key);

        AesError GetLastAesError() const
            { return m_last_error; }

        INT DecryptBuffer(const BYTE* in, BYTE* out,
            UINT buf_len, PaddingMethod pad_method,
            UINT start_block=0, UINT end_block=0);

    private:
        UINT8           m_key[16];              // 128 bit Key
        AesError        m_last_error;           // Last occured error code

        void XorBlock(BYTE* left, const BYTE* right, const UINT16 len);
};

#endif // AesCryptInterface_hpp


