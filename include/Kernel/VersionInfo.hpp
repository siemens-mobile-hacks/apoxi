/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiVersionInfo_hpp)
#define ApoxiVersionInfo_hpp

#include <Kernel/Types.hpp>

class VersionInfo {
    public:
        enum {
            c_flag_never_show_on_display = (1U << 0U),
            c_flag_hide_in_engineering_mode = (1U << 1U),
            c_flag_add_to_trace_info = (1U << 2U),
            c_flag_is_build_version = (1U << 3U)
        };

        struct Data {
            UINT m_flags;
            const CHAR* m_subsys_name;
            const CHAR* m_version_string;
            const CHAR* m_build_date;
        };

        VersionInfo(const Data* data);

        UINT GetFlags() const { return m_data->m_flags; }

        const CHAR* GetSubSystemName() const { return m_data->m_subsys_name; }

        const CHAR* GetVersionString() const { return m_data->m_version_string; }

        const CHAR* GetBuildDate() const { return m_data->m_build_date; }

        static const VersionInfo* GetFirst() { return m_first; }

        const VersionInfo* GetNext() const { return m_next; }

    private:
        const Data* m_data;
        VersionInfo* m_next;

        static VersionInfo* m_first;        
};



#define ApoxiDefVersionInfo(subsys, ver, flags) \
    static const VersionInfo::Data g_##subsys##_version_data = { (flags), #subsys, ver, __DATE__ " " __TIME__ }; \
    VersionInfo g_##subsys##_version_obj(&g_##subsys##_version_data) \


#define ApoxiUseVersionInfo(subsys) \
    extern VersionInfo g_##subsys##_version_obj; \
    VersionInfo*  g_##subsys##_prt =& g_##subsys##_version_obj;


#endif  // ApoxiVersionInfo_hpp


