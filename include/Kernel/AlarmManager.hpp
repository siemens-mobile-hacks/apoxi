/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AlarmManager_hpp)
#define Apoxi_AlarmManager_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/DateTime.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Kernel/SubSystem.hpp>
#include <AddOns/Services/Service.hpp>  // needed for Guid!
#include <Devices/StartUp.hpp>
#include <Afs/Uri.hpp>

#if !defined(APOXI_ALARMMANAGER_MAX_ENTRIES)
    #define APOXI_ALARMMANAGER_MAX_ENTRIES 10
#endif

const INT c_alarm_manager_max_entries = APOXI_ALARMMANAGER_MAX_ENTRIES;

class AlarmManager : private SubSystem {
    typedef SubSystem Base;

    public:
        enum PowerOnBehavior {
            Default,    
            NoPowerOn,  
            PowerOn     
        };

        //static AlarmManager& GetInstance() { return m_alarm_manager; }

        static void Register();

        static void SetAlarm(const DateTime& alarm,
                      PowerOnBehavior behavior = Default,
                      StartUp::Cause startup_cause = StartUp::AlarmOn);

        static void ClearAlarm();

        static void SetDefaultPowerOnBehavior(PowerOnBehavior behavior);
        
        virtual ~AlarmManager();

    private:
        struct AlarmList {
            ExecutionContext* context;
            Guid guid;
            UINT32 absolute_seconds;
            UINT16 power_on_behavior : 2;
            UINT16 startup_cause     : 5;
        };

        static PowerOnBehavior m_default_behavior;
        static const UINT32 c_no_alarm;
        static const Uri c_uri;
        static Mutex m_mutex;
        static AlarmList m_list[c_alarm_manager_max_entries];
        static AlarmManager m_alarm_manager;

        AlarmManager();
        
        virtual const WCHAR* GetName() const;
        virtual void OnPowerUp();
        virtual void OnPowerDown();
        virtual UINT8 GetPriority() const;
        virtual BootSequenceState InvokeAt() const;

        static INT GetIdxForGuid(const Guid& guid);
        static INT GetIdxForContext(const ExecutionContext& context);
        static INT GetIdxFree();
        static INT GetIdxNextAlarm();
        static INT GetIdxNextPowerOnAlarm();

        static void SendNextAlarmToRtc(BOOLEAN power_on, UINT32 abs_sec_now);

        static void InitRegistry(Uri& uri);
        static void InitRegistryMainNodes(Uri& uri);
        static void SaveAlarm(INT idx);
        static void LoadAlarm(INT idx);
        static void SaveDefaultBehavior();
        static void LoadDefaultBehavior();
        static Uri NodeUri(const CHAR* node, INT idx);
        static void AlarmExpired(INT idx);
        static void Clear(INT idx);
        static void ClearCb(void* arg);
        static void RtcEventCallbackFn();
};

#endif  // Apoxi_AlarmManager_hpp

