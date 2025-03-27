/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ContextDescriptionTypes_hpp)
#define ContextDescriptionTypes_hpp

class FeatureHandle;

struct SoftkeyDescTableEntry {
    const CHAR* app_menu_id;
    const CHAR* feature_id;
    const CHAR* text;
    const CHAR* icon_id;
};

enum KeymapType {
    keymapNone,
    keymapVKey,
    keymapVKeyFeature,
    keymapVKeyLongFeature,
    keymapVKeyVeryLongFeature
};

struct KeymapTableEntry {
    UINT8                   keymap_type;
    KeyCode                 key_code;
    KeyCode                 to_key_code;
    const FeatureHandle*    feature_handle;
};

struct ContextTableEntry {
    const CHAR*             context_id;
    const CHAR*             title;
    SoftkeyDescTableEntry   softkey_descriptions[APOXI_MAX_SOFTKEY_COUNT];
    const KeymapTableEntry* keymap;
};

#endif /* ContextDescriptionTypes_hpp */

