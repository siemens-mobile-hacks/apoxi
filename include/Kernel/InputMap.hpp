/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_InputMap_hpp)
#define Apoxi_InputMap_hpp

#include <Kernel/Types.hpp>

const InputMapControlId c_control_imid              =  1;
const InputMapControlId c_check_box_imid            =  2;
const InputMapControlId c_list_box_imid             =  3;
const InputMapControlId c_edit_box_imid             =  4;
const InputMapControlId c_abstract_menu_list_imid   =  5;
const InputMapControlId c_radio_button_imid         =  6;
const InputMapControlId c_check_box_list_imid       =  7;
const InputMapControlId c_radio_button_list_imid    =  8;
const InputMapControlId c_push_button_imid          =  9;
const InputMapControlId c_grid_imid                 = 10;

const InputMapId    c_FocusNextControl_imid         =  1;
const InputMapId    c_FocusPreviousControl_imid     =  2;
const InputMapId    c_Confirm_imid                  =  3;
const InputMapId    c_Cancel_imid                   =  4;

const InputMapId    c_EditBoxCursorRight_imid       = 10;
const InputMapId    c_EditBoxCursorLeft_imid        = 11;
const InputMapId    c_EditBoxCursorUp_imid          = 12;
const InputMapId    c_EditBoxCursorDown_imid        = 13;
const InputMapId    c_EditBoxDeleteCharacter_imid   = 14;
const InputMapId    c_EditBoxShiftKey_imid          = 15;

const InputMapId    c_ListBoxPreviousItem_imid      = 20;
const InputMapId    c_ListBoxNextItem_imid          = 21;

const InputMapId    c_MenuItemSelected_imid         = 30;

const InputMapId    c_CheckBoxChangeStatus_imid     = 40;

const InputMapId    c_EditBoxDtmfSeparator_imid     = 50;
const InputMapId    c_EditBoxPlus_imid              = 51;
const InputMapId    c_EditBoxWildcard_imid          = 52;

const InputMapId    c_GridMoveLeft_imid             = 60;
const InputMapId    c_GridMoveRight_imid            = 61;
const InputMapId    c_GridMoveUp_imid               = 62;
const InputMapId    c_GridMoveDown_imid             = 63;

const InputMapId    c_PushButtonClick_imid          = 70;
const InputMapId    c_PushButtonRelease_imid        = 71;

const InputMapId    c_RadioButtonPreviousItem_imid  = 80;
const InputMapId    c_RadioButtonNextItem_imid      = 81;

/*  ------------------------------------------------------------------------
                                    InputMap
    ------------------------------------------------------------------------ */

struct InputMapEntry {
    InputMapControlId   m_input_map_control_id;
    InputMapId          m_input_map_id;
};

class InputMapItem {
    public:
        enum MapItemType {
            KeyDownType,
            KeyAutoRepeatType,
            KeyUpType,
            LongKeyPressType,
            InputCharType
        };

        InputMapItem(MapItemType type) : m_type(type) {};

        MapItemType Type() const { return m_type; };

    private:
        MapItemType m_type;
};

typedef InputMapItem::MapItemType MapItemType;

struct InputMap {
    InputMapId GetTriggeredMessage(InputMapControlId map_id, const InputMapItem& item) const;

    InputMapEntry   *m_map_entry;
    INT             m_size;
};

/*  ------------------------------------------------------------------------
                             KeyDownInputMap
    ------------------------------------------------------------------------ */

struct KeyDownInputMapEntry {
    InputMapEntry   m_map_entry;
    KeyCode         m_key_code;
};

class KeyDownInputMapItem : public InputMapItem {
    public:
        typedef InputMapItem Base;

        KeyDownInputMapItem(MapItemType type, KeyCode key_code) : Base(type), m_key_code(key_code) {};

        void SetKeyCode(KeyCode key_code) { m_key_code = key_code; };
        KeyCode GetKeyCode() const { return m_key_code; };

    private:
        KeyCode     m_key_code;
};

/*  ------------------------------------------------------------------------
                                 KeyUpInputMap
    ------------------------------------------------------------------------ */
struct KeyUpInputMapEntry {
    InputMapEntry   m_map_entry;
    KeyCode         m_key_code;
    UINT32          m_duration;
};

class KeyUpInputMapItem : public InputMapItem {
    public:
        typedef InputMapItem Base;

        KeyUpInputMapItem(MapItemType type, KeyCode key_code, UINT32 duration) : 
            Base(type), m_key_code(key_code), m_duration(duration) {};

        void SetKeyCode(KeyCode key_code) { m_key_code = key_code; };
        KeyCode GetKeyCode() const { return m_key_code; };

        void SetDuration(UINT32 duration) { m_duration = duration; };
        UINT32 GetDuration() const { return m_duration; };

    private:
        KeyCode     m_key_code;
        UINT32      m_duration;
};

/*  ------------------------------------------------------------------------
                                 CharInputMap
    ------------------------------------------------------------------------ */
struct CharInputMapEntry {
    InputMapEntry   m_map_entry;
    WCHAR           m_char;
};

class CharInputMapItem : public InputMapItem {
    public:
        typedef InputMapItem Base;

        CharInputMapItem(MapItemType type, WCHAR chr) :
            Base(type), m_char(chr) {}

        void SetChar(WCHAR chr) { m_char = chr; }
        WCHAR GetChar() const { return m_char; }

    private:
        WCHAR   m_char;
};

#endif  // Apoxi_InputMap_hpp


