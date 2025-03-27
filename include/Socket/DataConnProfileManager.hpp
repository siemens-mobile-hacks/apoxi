/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DataConnProfileManager_hpp)
#define Apoxi_DataConnProfileManager_hpp

#include <Socket/DataConnProfile.hpp>
#include <Socket/PersistDataConnProfile.hpp>
#include <Socket/DataConnProfileStorage.hpp>
#include <Auxiliary/SimpleMap.hpp>

class DataConnProfileManager
{
    private:
        DataConnProfileManager();

        DataConnProfileManager(const DataConnProfileManager &);

        DataConnProfileManager& operator=(const DataConnProfileManager &);

    public:
        class ProfileInfo
        {
            friend class DataConnProfileManager;

            public:
                BOOLEAN IsReadOnly() const { return m_bit.m_readonly; }

                BOOLEAN IsTemporary() const { return m_bit.m_temporary; }

                DataConnProfile::ProfileType GetType() const
                    { return (DataConnProfile::ProfileType) m_bit.m_type; }

                const WString& GetName() const { return m_name; }

            private:

                struct Bit {
                    UINT m_type                 : 2;
                    UINT m_readonly             : 1;
                    UINT m_temporary            : 1;
                };

                Bit m_bit;
                WString m_name;
        };

    public:
        static DataConnProfileManager& Get();

        static DataConnProfileId GetCanonicalProfileId(DataConnProfileId id);

        BOOLEAN StorageIsAttached() const
            { return m_storage != 0; }

        DataConnProfileId GetDefProfileId() const;

        BOOLEAN SetDefProfileId(DataConnProfileId id);

        BOOLEAN GetProfileIdSet(DataConnProfileIdSet &pis) const;

        BOOLEAN GetTemporaryProfileIdSet(DataConnTempProfileIdSet &pis) const;

        BOOLEAN AddProfile(DataConnProfile &dcp);

#if defined(APOXI_COMPAT_2_0_0)

        BOOLEAN AddProfile(DataConnProfile &dcp, BOOLEAN as_default)
        {
            BOOLEAN rc = AddProfile(dcp);
            if (rc && as_default)
                rc = SetDefProfileId(dcp.GetId());
            return rc;
        }
#endif

        BOOLEAN AddTemporaryProfile(DataConnProfile &dcp);

        BOOLEAN SaveProfile(const DataConnProfile &dcp);

#if defined(APOXI_COMPAT_2_0_0)

        BOOLEAN SaveProfile(const DataConnProfile &dcp, BOOLEAN as_default)
        {
            BOOLEAN rc = SaveProfile(dcp);
            if (rc && as_default)
                rc = SetDefProfileId(dcp.GetId());
            return rc;
        }
#endif

        BOOLEAN DeleteProfile(DataConnProfileId id);

        BOOLEAN GetProfileInfo(DataConnProfileId id, ProfileInfo &pi);

        DataConnProfilePtr GetProfile(DataConnProfileId &id);

        BOOLEAN ResetToFactoryDefaults();

        BOOLEAN AttachStorage(DataConnProfileStorage *storage);

        BOOLEAN IsTemporaryProfileId(DataConnProfileId id) const;

        BOOLEAN UpdateProfile(DataConnProfile &dcp);

    private:
        mutable DataConnProfileStorage::Header m_header;
        mutable PersistDataConnProfile m_cache;
        mutable INT m_cache_recno;
        mutable SimpleMap<DataConnProfileId, DataConnProfilePtr>
            m_temp_profiles;
        mutable DataConnProfileId m_last_temp_id;

        DataConnProfileStorage *m_storage;

        INT GetRecNo(DataConnProfileId id) const;

        BOOLEAN ReadProfile(INT recno) const;

        BOOLEAN WriteProfile(INT recno);

        BOOLEAN ReadProfile(DataConnProfileId id,
            PersistDataConnProfile &cache) const;

        BOOLEAN GetPersistDataConnProfile(DataConnProfileId &id,
            PersistDataConnProfile &persist_profile) const;

        BOOLEAN IsInPersistentProfileIdRange(DataConnProfileId id) const;

        void PostDataConnProfileInfoMsg(DataConnProfileId id,
            DataConnProfileInfoMsgType msg, const WString &name) const;
};

#endif  // Apoxi_DataConnProfileManager_hpp

