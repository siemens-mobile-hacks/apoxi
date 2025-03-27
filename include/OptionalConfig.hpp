/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_OptionalConfig_hpp)
#define Apoxi_OptionalConfig_hpp

#include <Kernel/Types.hpp>
#include <Gui/OptionalConfigBase.hpp>

class OptionalConfig : public OptionalConfigBase {
    public:
        static BOOLEAN GetSetting(INT group_id, INT setting_id, INT &result);
};

#endif  // Apoxi_OptionalConfig_hpp

