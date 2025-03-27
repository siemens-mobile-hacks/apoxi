/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.     
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.    
   Passing on and copying of this document, use and communication of its   
   contents is not permitted without prior written authorisation.          
   ------------------------------------------------------------------------ */

#if !defined(Mmi_EnumTextMap_hpp)
#define Mmi_EnumTextMap_hpp

#include <Kernel/Types.hpp>

struct EnumTextTableEntry {
    INT     code;
    const WCHAR*    text;
};

typedef EnumTextTableEntry EnumTextTable[]; 

class EnumTextMap {
    public:
        static const WCHAR* GetText(const EnumTextTable table, const UINT size, const INT value);
};

#endif  //Mmi_EnumTextMap_hpp

