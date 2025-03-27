/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CodecManager_hpp)
#define Apoxi_CodecManager_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>
#include "CodecDevice.hpp"

class CodecManager {

    public:

        CodecDevice::ResultType ObtainDecoder(
                                            CodecDevice*& codec_device,
                                            CodecDevice::CodecType codec_type,
                                            BOOLEAN& combined_device);

        void ReleaseDecoder(CodecDevice* codec_device);

        CodecDevice::ResultType ObtainEncoder(
                                            CodecDevice*& codec_device,
                                            CodecDevice::CodecType codec_type,
                                            BOOLEAN& combined_device);

        void ReleaseEncoder(CodecDevice* codec_device);

        CodecDevice::ResultType RegisterDecoder(CodecDevice* codec_device);

        void UnregisterDecoder(CodecDevice* codec_device);

        CodecDevice::ResultType RegisterEncoder(CodecDevice* codec_device);

        void UnregisterEncoder(CodecDevice* codec_device);

        virtual ~CodecManager();

    private:

        enum CoderFlagsType {
            CoderInUseFlag = 1<<0
        };

        CodecDevice** m_reg_encoders_array;
        CodecDevice** m_reg_decoders_array;

        UINT8* m_encoders_flags_array;
        UINT8* m_decoders_flags_array;

        UINT8 m_num_of_reg_encoders;
        UINT8 m_num_of_reg_decoders;

        UINT8 m_num_of_encoders_in_use;
        UINT8 m_num_of_decoders_in_use;

        CodecManager();

        CodecManager(const CodecManager& codec_man) { ASSERT_DEBUG(FALSE); }

        CodecManager& operator=(const CodecManager& codec_man) {
            if (&codec_man != this) ASSERT_DEBUG(FALSE); return *this;
        }

        static CodecManager& GetInstance();

    friend class CodecConfig; // invokes the GetInstance() function

};

#endif // Apoxi_CodecManager_hpp

