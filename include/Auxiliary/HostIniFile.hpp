/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HostIniFile_hpp)
#define Apoxi_HostIniFile_hpp

#include <Auxiliary/String.hpp>

class HostIniFile {
    public:
        HostIniFile(String inifilename, BOOLEAN on_desktop = FALSE);
        ~HostIniFile();

        BOOLEAN ReadString(CHAR * section, CHAR * keyname, CHAR * keyvalueMax80);

        BOOLEAN WriteString(CHAR * section, CHAR * keyname, CHAR * keyvalueMax80);

        INT ReadInteger(CHAR * section, CHAR * keyname);

        BOOLEAN WriteInteger(CHAR * section, CHAR * keyname, INT keyvalue);

        BOOLEAN ReadBool(CHAR * section, CHAR * keyname);

        BOOLEAN WriteBool(CHAR * section, CHAR * keyname, BOOLEAN keyvalue);

    private:
        static String GetModulePath();
        static String GetSpecialDirectory(int type);

        String m_inifilename;
};

#endif  // Apoxi_HostIniFile_hpp

