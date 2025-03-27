/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DataConnProfile_hpp)
#define Apoxi_DataConnProfile_hpp

#include <Socket/SocketTypes.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/IpAddr.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

class DataConn;
typedef NiSharedPtr<DataConn> DataConnPtr;

class DataConnProfile;
typedef NiSharedPtr<DataConnProfile> DataConnProfilePtr;

class PersistDataConnProfile;

class DataConnProfile
{
    friend class DataConnManager;
    friend class DataConnProfileManager;
    friend class PersistDataConnProfile;

    public:
        enum {
            c_account_len_max = APOXI_BEARER_PROFILE_ACCOUNT_LEN_MAX,
            c_passwd_len_max = APOXI_BEARER_PROFILE_PASSWD_LEN_MAX
#if defined(APOXI_COMPAT_1_13_0)
            , c_invalid_id = c_invalid_data_conn_profile_id,
            c_default_id = c_default_data_conn_profile_id
#endif
        };

#if defined(APOXI_COMPAT_1_13_0)
        typedef DataConnProfileId Id;
#endif

        enum ProfileType {
            c_profile_type_psd = 0,
            c_profile_type_csd = 1

#if defined(APOXI_SER_DATACONN_SUPPORT) || defined(APOXI_COMPAT_1_13_0)
            , c_profile_type_ser = 2
#endif
        };

        enum TimeoutValue {
            c_default_idle_timeout = 120,   
            c_default_linger_timeout = 30,  
            c_infinite_timeout = 1023,      
            c_no_timeout = 0                
        };

        struct Bit {
            UINT m_type             : 2;
            UINT m_passwd_query     : 1;
            UINT m_readonly         : 1;
            UINT m_id               : (sizeof(DataConnProfileId) * 8U);
            UINT m_idle_timeout     : 10;
            UINT m_linger_timeout   : 10;
        };

    protected:
        DataConnProfile(ProfileType type);

    public:
        virtual ~DataConnProfile();

        const WString& GetName() const
            { return m_name; }

        DataConnProfileId GetId() const
            { return m_bit.m_id; }

        void SetName(const WString &name)
            { m_name = name; }

        ProfileType GetType() const
            { return (ProfileType)m_bit.m_type; }

        BOOLEAN IsReadOnly() const
            { return m_bit.m_readonly; }

        void SetReadOnly()
            { m_bit.m_readonly = TRUE; }

        const String& GetAccount() const
            { return m_account; }

        void SetAccount(const String &account)
            { m_account = account; }

        const String& GetPasswd() const
            { return m_passwd; }

        void SetPasswd(const String &passwd)
            { m_passwd = passwd; }

        BOOLEAN QueryForPasswd() const
            { return m_bit.m_passwd_query; }

        void EnablePasswdQuery(BOOLEAN enable = TRUE)
            { m_bit.m_passwd_query = enable; }

        const IpAddr& GetPrimaryDnsServerAddress() const
            { return m_primary_dns; }

        const IpAddr& GetSecondaryDnsServerAddress() const
            { return m_secondary_dns; }

        void SetPrimaryDnsServerAddress(const IpAddr &primary_dns)
            { m_primary_dns = primary_dns; }

        void SetSecondaryDnsServerAddress(const IpAddr &secondary_dns)
            { m_secondary_dns = secondary_dns; }

#if defined(APOXI_COMPAT_2_2_0)

        const IpAddr& GetDnsAddr() const
            { return GetPrimaryDnsServerAddress(); }

        void SetDnsAddr(const IpAddr &dns)
            { SetPrimaryDnsServerAddress(dns); }
#endif

#if defined(APOXI_COMPAT_1_13_0)

        inline UINT GetIdleTimer() const
            { return GetIdleTimeout(); }

        inline void SetIdleTimer(UINT timeout)
            { SetIdleTimeout(timeout); }
#endif

        UINT16 GetIdleTimeout() const
            { return m_bit.m_idle_timeout; }

        void SetIdleTimeout(UINT16 timeout)
            { m_bit.m_idle_timeout = timeout; }

        UINT16 GetLingerTimeout() const
            { return m_bit.m_linger_timeout; }

        void SetLingerTimeout(UINT16 timeout)
            { m_bit.m_linger_timeout = timeout; }

        virtual void SaveFrom(const PersistDataConnProfile &bpp);
        virtual void SaveTo(PersistDataConnProfile &bpp) const;

        DataConnProfilePtr Clone() const;

    protected:
        static DataConnPtr CreateDataConn(const DataConnProfilePtr &profile);

        virtual DataConnProfile* New() const = 0;

        virtual void Assign(const DataConnProfile &from_dcp);

    private:
        String m_account;
        String m_passwd;
        WString m_name;
        IpAddr m_primary_dns;
        IpAddr m_secondary_dns;
        Bit m_bit;

    public:
        struct Persist {
            CHAR m_account[c_account_len_max + 1];
            CHAR m_passwd[c_passwd_len_max + 1];
            WCHAR m_name[c_host_name_len_max + 1];
            IpAddr::Persist m_primary_dns;
            IpAddr::Persist m_secondary_dns;
            Bit m_bit;
        };
};

#if defined(APOXI_COMPAT_1_13_0)
    #include <Socket/CsdDataConnProfile.hpp>
    #include <Socket/PsdDataConnProfile.hpp>
    #include <Socket/SerDataConnProfile.hpp>
#endif

#endif  // Apoxi_DataConnProfile_hpp


