/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EditConfig_hpp)
#define Apoxi_EditConfig_hpp

/*  Do not change this header file. Each class in the configuration-lib must
    stay binary-compatible with Apoxi.  */

#include <Kernel/Types.hpp>

class InputMapper;
class InputMapperFactory;
typedef Vector<InputMapperFactory*> InputMapperVector;

class EditConfig {
    public:
        static UINT32 GetBlinkRate();

        static UINT32 GetPagingTimeout();

        static WCHAR GetDtmfSeparator();

        static WCHAR GetWildcard();

        static InputMapper* AllocInputMapper(INT input_mapper_id);

    private:
        static InputMapperVector m_imfv;
};

#endif  // Apoxi_EditConfig_hpp

