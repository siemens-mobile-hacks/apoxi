/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_KeyboardConfig_hpp)
#define Apoxi_KeyboardConfig_hpp

#include <Kernel/Types.hpp>
#include <Kernel/InputMap.hpp>

class KeyboardConfig {
    public:
        static KeyCode GetArrowLeft();

        static KeyCode GetArrowRight();

        static KeyCode GetArrowUp();

        static KeyCode GetArrowDown();

        static KeyCode GetSoftkey(INT index);

        static INT GetSoftkeyCount();

        static KeyCode GetNumber(UINT8 number);

        static KeyCode GetGreenKey();

        static KeyCode GetRedKey();

        static KeyCode GetDeleteKey();

        static KeyCode GetCustomKey(WCHAR custom_key);

        static INT GetAutorepeatDelay();

        static INT GetAutorepeatInterval();

        static INT GetLongKeyDelay();

        static INT GetVeryLongKeyDelay();

        static const InputMap& GetInputMap(INT index);

        static KeyCode GetHeadsetKey();
        
        static KeyCode GetOptionKey();

        static KeyCode GetSelectKey();

        static KeyCode GetBackKey();

        static KeyCode GetCloseKey();

        static KeyCode GetCancelKey();

        static KeyCode GetClearAllKey();

        static KeyCode GetInputTogglingKey();

        static KeyCode GetConfirmKey(); 
};


#endif  // Apoxi_KeyboardConfig_hpp

