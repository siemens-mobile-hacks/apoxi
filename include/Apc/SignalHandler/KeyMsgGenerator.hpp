/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apc_KeyMsgGenerator_hpp)
#define Apc_KeyMsgGenerator_hpp

#include <Auxiliary/Macros.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Kernel/Types.hpp>
#include <Kernel/SubSystem.hpp>
#include <Kernel/Os/SystemTimer.hpp>
#include <Kernel/Os/SemObtainer.hpp>

class KeyMsgGenerator : public SubSystem {
    public:
        class Key : public Linkable<Key> {
            friend class KeyMsgGenerator;
            public:
                enum State { 
                    Invalid, 
                    Set, 
                    InProcess 
                };
                
                Key() : m_key_code((KeyCode) -1), m_duration(0), m_pause(0), m_state(Invalid) {}
                Key(KeyCode key_code, UINT32 duration) : m_key_code(key_code), m_duration(duration), m_pause(0), m_state(Set) {}
                Key(UINT32 pause) : m_key_code((KeyCode) -1), m_duration(0), m_pause(pause), m_state(Set) {}

                KeyCode GetKeyCode() const { return (m_key_code); }
                UINT32 GetDuration() const { return (m_duration); } 
                UINT32 GetPause() const { return (m_pause); } 
                
            private:
                KeyCode m_key_code;
                UINT32 m_duration;      // in milliseconds
                UINT32 m_pause;         // in milliseconds
                State m_state;

                State GetState() const { return (m_state); }
                void SetState(State state) { m_state = state; }
        };

        KeyMsgGenerator();

        static KeyMsgGenerator* GetInstance() { return m_instance; }

        virtual const WCHAR* GetName() const { return L"APOXI KeyMsgGenerator (Apc)"; }

        virtual BootSequenceState InvokeAt() const { return (SubSystemManager::c_run_level_3); }

        virtual UINT8 GetPriority() const { return (100); } 

        virtual void OnPowerUp();

        virtual void OnPowerDown();

        static BOOLEAN Enqueue(const Key &key);

    private:
        static SystemTimer m_timer;
        static KeyMsgGenerator *m_instance;
        static Semaphore m_sem;
        static LinkedList<Key>  m_key_list;
        static Key *m_active_key;

        static void SendNextKey();

        // Callback function for key timer.
        static void OnTimeout(void *key);
};

#endif  // Apc_KeyMsgGenerator_hpp


