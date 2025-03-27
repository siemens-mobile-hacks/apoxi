/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PagingMap_hpp)
#define Apoxi_PagingMap_hpp

#include <Kernel/Types.hpp>

// Defines the mapping of a key code to it's character code presentations.
struct PagingMapEntry {
    UINT8 GetKeyCode() const { return keycode; }
    WCHAR GetNumber() const { return number; }
    const WCHAR* GetUpperCaseChar() const { return uppercase; }
    const WCHAR* GetLowerCaseChar() const { return lowercase; }
    BOOLEAN IsValid() const { return number != 0; }
    BOOLEAN IsSwitch() const { return (number != 0) && (uppercase == 0) && (lowercase == 0); }

    UINT8 keycode;                      // the code of the key this mapping applies to
    WCHAR number;                       // numeric presentation
    const WCHAR* uppercase;             // upper case presentations
    const WCHAR* lowercase;             // lower case presentations
};

// Defines the key to character mapping for a certain language.
struct PagingMap {
    const PagingMapEntry& GetPagingMapEntry(KeyCode key_code) const {
        INT i = 0;
        while ((m_pme[i].GetNumber() != 0) && (m_pme[i].GetKeyCode() != key_code))
            i++;
        return m_pme[i];
    }

    WCHAR GetNumber(KeyCode key_code) const {
        return GetPagingMapEntry(key_code).GetNumber();
    }

    const WCHAR* GetLowerCaseChar(KeyCode key_code) const {
        return GetPagingMapEntry(key_code).GetLowerCaseChar();
    }

    //LanguageId lang_id;               // language the mapping applies to
    const PagingMapEntry* m_pme;        // Array of mapping entries. Last entry must be initialized with zero.
};

#endif  // Apoxi_PagingMap_hpp


