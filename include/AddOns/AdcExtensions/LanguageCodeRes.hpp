/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.     
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.    
   Passing on and copying of this document, use and communication of its   
   contents is not permitted without prior written authorisation.          
   ------------------------------------------------------------------------ */

#if !defined(Apoxi_AdcExtensions_LanguageCodeRes_hpp)
#define Apoxi_AdcExtensions_LanguageCodeRes_hpp

#include <Kernel/Types.hpp>
#include <Apc/DataCodingScheme.hpp>

struct LanguageCodeTableEntry {
    DataCodingScheme::Language dcs_lang_code;   // Code of some languages according to CBS Data Coding Scheme.
                                                // Any language, that is not supported by DCS has 'Language unspecified'.
    const WCHAR* lang_name;             // English name, can be used for translations
    const WCHAR* iso_3ltr_code;         // 3 letter ISO 639 language code
    const WCHAR* iso_2ltr_code;         // 2 letter ISO 639 language code
    UINT8           gsm_lang_code;              // 1 byte GSM language code; Stored on SIM, Read by PrefExtLangProvider
};

extern const LanguageCodeTableEntry c_language_code_table[];
extern const INT c_language_table_entry_count;

#endif  //Apoxi_AdcExtensions_LanguageCodeRes_hpp


