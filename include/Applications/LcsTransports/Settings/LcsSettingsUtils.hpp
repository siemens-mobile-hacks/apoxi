/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsSettingsUtils_hpp)
#define Mmi_LcsSettingsUtils_hpp

#include <GuiExtensions/MmiAlert.hpp>

class WString;

class LcsSettingsUtils
{
    public:

        ~LcsSettingsUtils();

        static LcsSettingsUtils* GetInstance();

        static void ReleaseInstance();

        void DisplayMsg(const WCHAR* str = NULL);

        BOOLEAN GetData(const CHAR* data_type, WString& data);

        BOOLEAN GetData(const CHAR* data_type, INT32& data);

        BOOLEAN StoreData(const CHAR* data_type, const WString& data) const;

        BOOLEAN StoreData(const CHAR* data_type, INT32 data) const;


    private:

        LcsSettingsUtils();

    private:

        static LcsSettingsUtils* m_self;

}; // LcsSettingsUtils

#endif // Mmi_LcsSettingsUtils_hpp
