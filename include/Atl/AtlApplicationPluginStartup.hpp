 /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtlApplicationPluginStartup_hpp)
#define AtlApplicationPluginStartup_hpp

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/AtlApplication.hpp>
#include <Atl/AtlApplicationPlugin.hpp>
#endif  // APOXI_COMPAT_2_7_0

class AtlApplication;
class AtlApplicationPlugin;

class AtlApplicationPluginStartup {

    public:
        struct Table {
                AtlApplication* app;
                AtlApplicationPlugin* plugin;
        };

        static void InitPlugins(const Table*);
};
#endif

