/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\views\wickhara_apoxitest_pu_sv\lnz_apoxi\Apoxi\Kernel\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Kernel_MsgTypes_hpp)
#define Kernel_MsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Kernel/Timer.hpp>
#include <Auxiliary/Time.hpp>
#include <Auxiliary/Date.hpp>
#include <Devices/Keyboard.hpp>


class Threadlet;
class Item;
class Action;
class ExecutionContext;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class NoMessage
    ====================================================================== */

class NoMessage : public Message {
    public:
        NoMessage();
        virtual ~NoMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 0
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class PowerOnMsg
    ====================================================================== */

class PowerOnMsg : public Message {
    public:
        PowerOnMsg();
        virtual ~PowerOnMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class PowerOffMsg
    ====================================================================== */

class PowerOffMsg : public Message {
    public:
        PowerOffMsg();
        virtual ~PowerOffMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 2
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class AppOpenMsg
    ====================================================================== */

class AppOpenMsg : public Message {
    public:
        AppOpenMsg();
        virtual ~AppOpenMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 100
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class AppCloseMsg
    ====================================================================== */

class AppCloseMsg : public Message {
    public:
        AppCloseMsg();
        virtual ~AppCloseMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 101
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class AppUpdateDisplayMsg
    ====================================================================== */

class AppUpdateDisplayMsg : public Message {
    public:
        AppUpdateDisplayMsg();
        virtual ~AppUpdateDisplayMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 107
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class ThemeChangedMsg
    ====================================================================== */

class ThemeChangedMsg : public Message {
    public:
        ThemeChangedMsg();
        virtual ~ThemeChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 120
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class LanguageChangedMsg
    ====================================================================== */

class LanguageChangedMsg : public Message {
    public:
        LanguageChangedMsg();
        virtual ~LanguageChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 121
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class PowerWakeupMsg
    ====================================================================== */

class PowerWakeupMsg : public Message {
    public:
        PowerWakeupMsg();
        virtual ~PowerWakeupMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 130
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class KeyDownMsg
    ====================================================================== */

class KeyDownMsg : public Message {
    public:
        KeyDownMsg(const KeyCode& key_code);
        virtual ~KeyDownMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 200
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        
    };


/*  ======================================================================
    Class KeyUpMsg
    ====================================================================== */

class KeyUpMsg : public Message {
    public:
        KeyUpMsg(const KeyCode& key_code = 0, UINT32 duration = 0);
        virtual ~KeyUpMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        void SetDuration(UINT32 duration) { m_duration = duration; }
        UINT32 GetDuration() const { return m_duration; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 201
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        UINT32 m_duration;
        
    };


/*  ======================================================================
    Class LongKeyPressMsg
    ====================================================================== */

class LongKeyPressMsg : public Message {
    public:
        LongKeyPressMsg(const KeyCode& key_code);
        virtual ~LongKeyPressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 202
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        
    };


/*  ======================================================================
    Class VeryLongKeyPressMsg
    ====================================================================== */

class VeryLongKeyPressMsg : public Message {
    public:
        VeryLongKeyPressMsg(const KeyCode& key_code);
        virtual ~VeryLongKeyPressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 203
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        
    };


/*  ======================================================================
    Class KeyAutoRepeatMsg
    ====================================================================== */

class KeyAutoRepeatMsg : public Message {
    public:
        KeyAutoRepeatMsg(const KeyCode& key_code);
        virtual ~KeyAutoRepeatMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 204
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        
    };


/*  ======================================================================
    Class FlipMsg
    ====================================================================== */

class FlipMsg : public Message {
    public:
        FlipMsg(BOOLEAN flip_open);
        virtual ~FlipMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        BOOLEAN IsFlipOpen() const { return m_flip_open; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 205
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_flip_open;
        
    };


/*  ======================================================================
    Class LockedKeyDownMsg
    ====================================================================== */

class LockedKeyDownMsg : public Message {
    public:
        LockedKeyDownMsg(const KeyCode& key_code);
        virtual ~LockedKeyDownMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 210
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        
    };


/*  ======================================================================
    Class LockedKeyMsg
    ====================================================================== */

class LockedKeyMsg : public Message {
    public:
        LockedKeyMsg(const Keyboard::Flag& flag, const KeyCode& key_code);
        virtual ~LockedKeyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Keyboard::Flag& GetFlag() const { return m_flag; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 211
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Keyboard::Flag m_flag;
        KeyCode m_key_code;
        
    };


/*  ======================================================================
    Class InputCharMsg
    ====================================================================== */

class InputCharMsg : public Message {
    public:
        InputCharMsg(WCHAR character);
        virtual ~InputCharMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCharacter(WCHAR character) { m_character = character; }
        WCHAR GetCharacter() const { return m_character; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 220
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WCHAR m_character;
        
    };


/*  ======================================================================
    Class PenDownMsg
    ====================================================================== */

class PenDownMsg : public Message {
    public:
        PenDownMsg(XYDIM pos_x, XYDIM pos_y);
        virtual ~PenDownMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPosX(XYDIM pos_x) { m_pos_x = pos_x; }
        XYDIM GetPosX() const { return m_pos_x; }
        void SetPosY(XYDIM pos_y) { m_pos_y = pos_y; }
        XYDIM GetPosY() const { return m_pos_y; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 240
            };
        
    private:
        static const MsgMetaData m_meta_data;
        XYDIM m_pos_x;
        XYDIM m_pos_y;
        
    };


/*  ======================================================================
    Class PenUpMsg
    ====================================================================== */

class PenUpMsg : public Message {
    public:
        PenUpMsg(XYDIM pos_x, XYDIM pos_y);
        virtual ~PenUpMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPosX(XYDIM pos_x) { m_pos_x = pos_x; }
        XYDIM GetPosX() const { return m_pos_x; }
        void SetPosY(XYDIM pos_y) { m_pos_y = pos_y; }
        XYDIM GetPosY() const { return m_pos_y; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 241
            };
        
    private:
        static const MsgMetaData m_meta_data;
        XYDIM m_pos_x;
        XYDIM m_pos_y;
        
    };


/*  ======================================================================
    Class ExternalTimeoutMsg
    ====================================================================== */

class ExternalTimeoutMsg : public Message {
    public:
        ExternalTimeoutMsg(Timer* timer);
        virtual ~ExternalTimeoutMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetTimer(Timer* timer) { m_timer = timer; }
        Timer* GetTimer() const { return m_timer; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 301
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Timer* m_timer;
        
    };


/*  ======================================================================
    Class ItemPropertiesChangedMsg
    ====================================================================== */

    class ItemPropertiesChangedMsg : public Message {
    public:
        ItemPropertiesChangedMsg(Item* item, INT property_id);
        virtual ~ItemPropertiesChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Item* GetItem() const { return m_item; }
        INT GetPropertyId() const { return m_property_id; }
        virtual Message* Clone() const;
        Action* GetAction() const;
        
        enum  {
            ID = 302
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Item* m_item;
        INT m_property_id;
        
    };


/*  ======================================================================
    Class ActionExecutedMsg
    ====================================================================== */

class ActionExecutedMsg : public Message {
    public:
        ActionExecutedMsg(Action* action);
        virtual ~ActionExecutedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Action* GetAction() const { return m_action; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 303
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Action* m_action;
        
    };


/*  ======================================================================
    Class RtcTimeChangedMsg
    ====================================================================== */

class RtcTimeChangedMsg : public Message {
    public:
        RtcTimeChangedMsg();
        virtual ~RtcTimeChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 2911
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class RtcDateChangedMsg
    ====================================================================== */

class RtcDateChangedMsg : public Message {
    public:
        RtcDateChangedMsg();
        virtual ~RtcDateChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 2912
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class RtcAlarmReachedMsg
    ====================================================================== */

class RtcAlarmReachedMsg : public Message {
    public:
        RtcAlarmReachedMsg();
        virtual ~RtcAlarmReachedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 2913
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class ServiceThreadTerminateMsg
    ====================================================================== */

class ServiceThreadTerminateMsg : public ContextMsg {
    public:
        ServiceThreadTerminateMsg(ExecutionContext* context);
        virtual ~ServiceThreadTerminateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 102
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class AppGetFocusMsg
    ====================================================================== */

class AppGetFocusMsg : public ContextMsg {
    public:
        AppGetFocusMsg(ExecutionContext* context);
        virtual ~AppGetFocusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 105
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class AppLoseFocusMsg
    ====================================================================== */

class AppLoseFocusMsg : public ContextMsg {
    public:
        AppLoseFocusMsg(ExecutionContext* context);
        virtual ~AppLoseFocusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 106
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SharedTimerMsg
    ====================================================================== */

class SharedTimerMsg : public ContextMsg {
    public:
        SharedTimerMsg(ExecutionContext* context, INT arg);
        virtual ~SharedTimerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        INT GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 108
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_arg;
        
    };


/*  ======================================================================
    Class ThreadletNotificationMsg
    ====================================================================== */

class ThreadletNotificationMsg : public ContextMsg {
    public:
        ThreadletNotificationMsg(ExecutionContext* context, Threadlet* threadlet);
        virtual ~ThreadletNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Threadlet* GetThreadlet() const { return m_threadlet; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 109
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Threadlet* m_threadlet;
        
    };


/*  ======================================================================
    Class ContextWakeupMsg
    ====================================================================== */

class ContextWakeupMsg : public ContextMsg {
    public:
        ContextWakeupMsg(ExecutionContext* context);
        virtual ~ContextWakeupMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 110
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class ShutdownRequestMsg
    ====================================================================== */

class ShutdownRequestMsg : public ContextMsg {
    public:
        ShutdownRequestMsg(ExecutionContext* context);
        virtual ~ShutdownRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 111
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class AlarmNotificationMsg
    ====================================================================== */

class AlarmNotificationMsg : public ContextMsg {
    public:
        AlarmNotificationMsg(ExecutionContext* context);
        virtual ~AlarmNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 112
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class TimerTimeoutMsg
    ====================================================================== */

class TimerTimeoutMsg : public ContextMsg {
    public:
        TimerTimeoutMsg(ExecutionContext* context, Timer* timer);
        virtual ~TimerTimeoutMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetTimer(Timer* timer) { m_timer = timer; }
        Timer* GetTimer() const { return m_timer; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 300
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Timer* m_timer;
        
    };


/*  ======================================================================
    Class ContextExecuteMsg
    ====================================================================== */

class ContextExecuteMsg : public ContextMsg {
    public:
        typedef void (*CallbackFn)(void*);
        ContextExecuteMsg(ExecutionContext* context, const CallbackFn fn = 0, void* arg = 0);
        virtual ~ContextExecuteMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual void Execute();
        virtual Message* Clone() const;
        
        enum  {
            ID = 3000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallbackFn m_fn;
        void* m_arg;
        
    };


/*  ======================================================================
    Class GetFocusMsg
    ====================================================================== */

class GetFocusMsg : public ControlMsg {
    public:
        GetFocusMsg(Control* control);
        virtual ~GetFocusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class LoseFocusMsg
    ====================================================================== */

class LoseFocusMsg : public ControlMsg {
    public:
        LoseFocusMsg(Control* control);
        virtual ~LoseFocusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

typedef ItemPropertiesChangedMsg ActionPropertiesChangedMsg;

#endif // Kernel_MsgTypes_hpp

