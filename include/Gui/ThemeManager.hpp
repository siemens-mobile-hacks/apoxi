/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ThemeManager_hpp)
#define Apoxi_ThemeManager_hpp

class Theme;

class ThemeManager {
    public:
        static void SetActiveTheme(INT active_theme_idx);

        static INT GetActiveThemeIndex() { return m_active_theme_idx; }

        static const Theme& GetActiveTheme();

        static void UpdateThemes();
    
    private:
        static INT m_active_theme_idx;
        static Semaphore m_sem;
        static BOOLEAN m_sem_created;
};

#endif  // Apoxi_ThemeManager_hpp


