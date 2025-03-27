/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DataConnManager_hpp)
#define Apoxi_DataConnManager_hpp

#include <Kernel/Os/Semaphore.hpp>
#include <Socket/DataConnProfile.hpp>
#include <Auxiliary/SimpleMap.hpp>

#if defined(APOXI_COMPAT_1_13_0)
    class DataConn;

    #include <Socket/DataConnProfileManager.hpp>
    #include <Socket/SerDataConnProfile.hpp>

    class SerDataConnProfile;
#endif

class DataConnManager
{
    friend class SocketRxThread;

    private:
        DataConnManager();

        DataConnManager(const DataConnManager &);

        DataConnManager& operator=(const DataConnManager &);

        void Init();

    public:
        static DataConnManager& Get();

        BOOLEAN IsDataConnRegistered(DataConnProfileId id) const;

        BOOLEAN RegisterDataConn(DataConnProfileId id);

        BOOLEAN UnregisterDataConn(DataConnProfileId id);

        const DataConn& GetDataConn(DataConnProfileId id) const;

       DataConn& GetDataConn(DataConnProfileId id);

        UINT GetDataConnCount() const;

        UINT GetDataConnCount(DataConnProfile::ProfileType type) const;

        DataConnPtr GetDataConnByIdx(UINT idx) const;

        DataConnPtr GetDataConnByIdxAndType(UINT idx,
            DataConnProfile::ProfileType type) const;

    private:
        void CheckDataConnTimers() const;

        /* Helper smart-pointer used for unregistering a data connection. */
        DataConnPtr m_dc_in_release;

        typedef SimpleMap<DataConnProfileId, DataConnPtr> TDataConnMap;

        TDataConnMap m_data_connections;

        mutable Semaphore m_sem;

#if defined(APOXI_COMPAT_1_13_0)

    public:

        enum {
            c_profile_count = c_data_conn_profile_count,
            c_invalid_id = c_invalid_data_conn_profile_id,
            c_default_id = c_default_data_conn_profile_id
        };

        enum DataConnState {
            c_data_conn_inactive,
            c_data_conn_in_setup,
            c_data_conn_in_release,
            c_data_conn_in_forced_release,
            c_data_conn_in_hold,
            c_data_conn_active
        };

        typedef DataConnProfileManager::ProfileInfo ProfileInfo;
        typedef DataConnProfileId ProfileId;
        typedef DataConnProfileIdSet ProfileIdSet;

        inline static ProfileId GetDefProfileId()
            { return DataConnProfileManager::Get().GetDefProfileId(); }

        inline static BOOLEAN SetDefProfileId(ProfileId id)
            { return DataConnProfileManager::Get().SetDefProfileId(id); }

        inline static BOOLEAN GetProfileIdSet(ProfileIdSet &pis)
            { return DataConnProfileManager::Get().GetProfileIdSet(pis); }

        inline static BOOLEAN AddProfile(DataConnProfile &dcp, BOOLEAN as_default = FALSE) {
            BOOLEAN rc = DataConnProfileManager::Get().AddProfile(dcp);
            if (rc && as_default)
                rc = DataConnProfileManager::Get().SetDefProfileId(dcp.GetId());
            return rc;
        }

        inline static BOOLEAN SaveProfile(DataConnProfile &dcp, BOOLEAN as_default = FALSE) {
            BOOLEAN rc = DataConnProfileManager::Get().SaveProfile(dcp);
            if (rc && as_default)
                rc = DataConnProfileManager::Get().SetDefProfileId(dcp.GetId());
            return rc;
        }

        inline static BOOLEAN DeleteProfile(ProfileId id)
            { return DataConnProfileManager::Get().DeleteProfile(id); }

        inline static BOOLEAN GetProfileInfo(ProfileId id, ProfileInfo &pi)
            { return DataConnProfileManager::Get().GetProfileInfo(id, pi); }

        inline static BOOLEAN GetProfile(ProfileId id, CsdDataConnProfile &csd)
            { return GetProfileOfType(id, csd, DataConnProfile::c_profile_type_csd); }

        inline static BOOLEAN GetProfile(ProfileId id, PsdDataConnProfile &psd)
            { return GetProfileOfType(id, psd, DataConnProfile::c_profile_type_psd); }

        inline static BOOLEAN GetProfile(ProfileId id, SerDataConnProfile &ser)
            { return GetProfileOfType(id, ser, DataConnProfile::c_profile_type_ser); }

        inline static BOOLEAN ResetToFactoryDefaults()
            { return DataConnProfileManager::Get().ResetToFactoryDefaults(); }

        inline static BOOLEAN AttachStorage(DataConnProfileStorage *storage)
            { return DataConnProfileManager::Get().AttachStorage(storage); }

        inline static INT GetCsdDataConnCount()
            { return DataConnManager::Get().GetDataConnCount(DataConnProfile::c_profile_type_csd); }

        inline static BOOLEAN GetCsdDataConnState(INT idx, ProfileId *id, DataConnState *state)
            { return GetDataConnState(idx, id, state, DataConnProfile::c_profile_type_csd); }

        inline static INT GetPsdDataConnCount()
            { return DataConnManager::Get().GetDataConnCount(DataConnProfile::c_profile_type_psd); }

        inline static BOOLEAN GetPsdDataConnState(INT idx, ProfileId *id, DataConnState *state)
            { return GetDataConnState(idx, id, state, DataConnProfile::c_profile_type_psd); }

        static BOOLEAN GetPsdIpAddress(INT idx, IpAddr &addr);

        inline static INT GetSerDataConnCount()
            { return DataConnManager::Get().GetDataConnCount(DataConnProfile::c_profile_type_ser); }

        inline static BOOLEAN GetSerDataConnState(INT idx, ProfileId *id, DataConnState *state)
            { return GetDataConnState(idx, id, state, DataConnProfile::c_profile_type_ser); }

        inline static void CsdClose(UINT idx = 0) {
            ReleaseNthDataConnOfType(idx, DataConnProfile::c_profile_type_csd);
        }

        inline static void PsdClose(UINT idx = 0) {
            ReleaseNthDataConnOfType(idx, DataConnProfile::c_profile_type_psd);
        }

        inline static void SerClose(UINT idx = 0) {
            ReleaseNthDataConnOfType(idx, DataConnProfile::c_profile_type_ser);
        }

        inline static UINT32 CsdStatus(UINT idx = 0)
            { return GetStatusOfNthDataConnOfType(idx, DataConnProfile::c_profile_type_csd); }

        inline static UINT32 PsdStatus(UINT idx = 0)
            { return GetStatusOfNthDataConnOfType(idx, DataConnProfile::c_profile_type_psd); }

        inline static UINT32 SerStatus(UINT idx = 0)
            { return GetStatusOfNthDataConnOfType(idx, DataConnProfile::c_profile_type_ser); }

        inline static void SetCsdDetachTimer(UINT32 value, UINT idx = 0)
            { SetDetachTimerOfNthDataConnOfType(idx, DataConnProfile::c_profile_type_csd, value); }

        inline static void SetPsdDetachTimer(UINT32 value, UINT idx = 0)
            { SetDetachTimerOfNthDataConnOfType(idx, DataConnProfile::c_profile_type_psd, value); }

        inline static void SetSerDetachTimer(UINT32 value, UINT idx = 0)
            { SetDetachTimerOfNthDataConnOfType(idx, DataConnProfile::c_profile_type_ser, value); }

        inline static void CheckTimers()
            { DataConnManager::Get().CheckTimers(); }

        static void DataConnCancel(BOOLEAN cancel);

        static BOOLEAN IsDataConnCancelled();

    private:
        static BOOLEAN GetProfileOfType(ProfileId id, DataConnProfile &dcp,
            DataConnProfile::ProfileType type);

        static BOOLEAN GetDataConnState(INT idx, ProfileId *id,
            DataConnState *state, DataConnProfile::ProfileType type);

        static UINT32 GetStatusOfNthDataConnOfType(UINT idx,
            DataConnProfile::ProfileType type);

        static void SetDetachTimerOfNthDataConnOfType(UINT idx,
            DataConnProfile::ProfileType type, UINT32 value);

        static void ReleaseNthDataConnOfType(UINT idx,
            DataConnProfile::ProfileType type);


#endif

};

#endif  // Apoxi_DataConnManager_hpp

