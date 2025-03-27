/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class Keyboard {
#endif

    public:
        enum Flag {
            KeyDown,
            KeyUp,
            LongKeyPress,
            VeryLongKeyPress,
            KeyAutoRepeat,
            InputChar   // Obsolete!
        };

        enum IlluminationMode {
            IlluminationModeOff,    
            IlluminationModeAuto,   
            IlluminationModeOn      
        };
        
        virtual ~Keyboard();

        virtual const WCHAR* GetName() const;

        static ControlArg Control(INT command, ControlArg arg);

        static void PostKeyMsg(KeyCode key_code, Flag key_flag, UINT32 duration = 0);

        static void ConfirmKeyInput();

        static void SetLocked(BOOLEAN locked);

        static BOOLEAN IsLocked();

        static BOOLEAN GetKeyState(KeyCode keycode);

        static void SetMultiKeyMode(BOOLEAN enable);

        static BOOLEAN IsMultiKeyMode();

        static void SetIlluminationTimeout(UINT32 timeout);

        static void ReactivateIllumination();

        static void SetIlluminationMode(IlluminationMode mode);

        static IlluminationMode GetIlluminationMode();

        static BOOLEAN IsIlluminationOn();

    private:
        static Keyboard m_keyboard;

        static BOOLEAN m_key_pressed_very_long;
        static KeyCode m_prev_key_code;
        static SystemTimer m_key_press_timer;
        static SystemTimer m_key_autorepeat_timer;

        Keyboard();

        static void UpdateKeyTimers(KeyCode key_code, Flag key_flag);
        static void OnKeyPressTimer(void* arg);
        static void OnKeyAutorepeatTimer(void* arg);

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

