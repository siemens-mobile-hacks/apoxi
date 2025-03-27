/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(WapProfile_hpp)

#define WapProfile_hpp



#include <ApoxiLib.hpp>
#include <Socket/DataConnProfile.hpp>
#include <Socket/DataConnManager.hpp>

#include <Auxiliary/DataItem.hpp>
#include <Auxiliary/RegBlobObject.hpp>
#include <Afs/Registry.hpp>
#include <Afs/RegistryTypes.hpp>

typedef UINT8 WapProfileId;


class WapProfile {
    public:

        enum PxAddrType {   
            IPv4,
            E164,
            Invalid
        };

        enum PortService {
            WapConnectionless,
            WapSession,
            WapSecureConnectionless,
            WapSecureSession,
            WapWtaSecureSession,
            WapWtaSecureConnectionless,
            InvalidService
        };

        enum WapAuthMethod {
            AuthMethodHttpBasic,
            AuthMethodHttpDigest,
            AuthMethodWtlsSs,
            InvalidMethod
        };

        enum ProfileConstants {
                c_invalid_id = 255,
                c_invalid_set_id = 255,
                c_max_proxy_id_len = 32,
                c_max_proxy_p_id_len = 32,
                c_max_proxy_name_len = 16,
                c_max_profile_name_len1 = 16,
                c_max_startpage_len = 64,
                c_max_username_len = 16,
                c_max_pwd_len = 16,
                c_max_url_len1 = 255,
                c_dataconn_profile_count = 5,
                c_max_physical_set = 5,
                c_max_auth_set = 5,
                c_max_port_set = 5,
                c_max_phy_port_set = 5,
                c_max_domain = 4,
                c_max_port_services = 5,
                c_max_wap_profile_count = 5
        };

        struct Ipv4E164 {
            IpAddr ipv4_address;
            WString e164_number;
            PxAddrType type;
        };

        struct PxLogicalCharacs {
            PxLogicalCharacs() : m_wsp_version("1.2")
            {
            }

            WString         m_proxy_id; 
            WString         m_proxy_p_id; 
            WString         m_proxy_name; 
            WString         m_domain[c_max_domain]; 
            BOOLEAN         m_proxy_trusted; 
            WString         m_startpage; 
            WString         m_startpage_user_name; 
            WString         m_startpage_pwd; 
            WString         m_wsp_version; 
            BOOLEAN         m_push_enabled; 
            
            struct PxAuthInfoCharacs : public Linkable<PxAuthInfoCharacs> {
                WapAuthMethod   m_proxy_auth_type; 
                WString         m_auth_user_name; 
                WString         m_auth_pwd; 
                UINT8           m_auth_set_id; 
            };
            LinkedList<PxAuthInfoCharacs> m_list_pxauthinfo; 

            struct PxPortCharacs : public Linkable<PxPortCharacs> { 
                UINT32          m_port; 
                PortService     m_port_service[c_max_port_services]; 
                UINT8           m_port_set_id; 
            };
            LinkedList<PxPortCharacs> m_list_port; 
            
            struct PxPhysicalCharacs : public Linkable<PxPhysicalCharacs> {
                WString         m_phy_proxy_id; 
                WString         m_phy_domain[c_max_domain]; 
                Ipv4E164        m_proxy_addr; 
                UINT8           m_physical_set_id; 
                UINT8           m_to_nap_id;
                LinkedList<PxPortCharacs> m_list_phy_port; 
                BOOLEAN         m_phy_push_enabled; 
            };
            LinkedList<PxPhysicalCharacs> m_list_pxphysical; 

        }; // PxLogicalCharacs

    WapProfile(); 
    ~WapProfile(); 
    
    BOOLEAN SetProxyId(const CHAR* proxy_id) ; 
    
    const WCHAR* GetProxyId() const ; 
    
    BOOLEAN SetProxyProviderId(const CHAR* proxy_p_id) ; 

    const WCHAR* GetProxyProviderId() const ; 

    BOOLEAN SetProxyName(const CHAR* name) ; 

    const WCHAR* GetProxyName() const ; 

    BOOLEAN SetDomain(INT number, const CHAR* domain) ; 

    const WCHAR* GetDomain(INT number) const ; 

    BOOLEAN SetTrust(BOOLEAN trust) ; 

    BOOLEAN GetTrust() const ; 

    BOOLEAN SetStartpage(const CHAR* startpage) ; 

    const WCHAR* GetStartpage() const ; 

    BOOLEAN SetStartpageUsername(const CHAR* username) ; 

    const WCHAR* GetStartpageUsername() const ; 

    BOOLEAN SetStartpagePassword(const CHAR* password) ; 

    const WCHAR* GetStartpagePassword() const ; 

    BOOLEAN SetWspVersion(const CHAR* version) ; 

    const WCHAR* GetWspVersion() const ; 

    BOOLEAN SetPushEnabled(BOOLEAN enable) ; 

    BOOLEAN IsPushEnabled() const ; 

    BOOLEAN SetAuthenticationMethod(WapAuthMethod method,
                                            INT   set = 0) ; 

    WapAuthMethod GetAuthenticationMethod(INT set = 0) const ; 

    BOOLEAN SetAuthenticationUsername(  const CHAR* username, 
                                                INT   set = 0) ; 
    
    const WCHAR* GetAuthenticationUsername(INT set = 0) const ; 

    BOOLEAN SetAuthenticationPassword(  const CHAR* password, 
                                                INT   set = 0) ; 

    const WCHAR* GetAuthenticationPassword(INT set = 0) const ; 



    BOOLEAN SetPortNumber(UINT port, INT set = 0) ; 

    UINT GetPortNumber(INT set = 0) const ; 

    BOOLEAN SetPortService( UINT port, PortService    service) ; 

    PortService GetPortService(UINT port) const ; 



    BOOLEAN SetPhysicalProxyId( const CHAR* proxy_id, INT   set = 0) ; 

    const WCHAR* GetPhysicalProxyId(INT set = 0) const ; 

    BOOLEAN SetPhysicalDomain(INT number, const CHAR* domain, INT set = 0) ; 

    const WCHAR* GetPhysicalDomain(INT number, INT set = 0) const ; 

    BOOLEAN SetPhysicalProxyAddress(const CHAR* address, PxAddrType addr_type, 
                                                         INT set = 0) ; 

    const Ipv4E164& GetPhysicalProxyAddress(INT set = 0) const ; 

    BOOLEAN SetPhysicalPushEnabled(BOOLEAN pushenable, INT set = 0) ; 

    BOOLEAN IsPhysicalPushEnabled(INT set = 0) const ; 

    BOOLEAN SetDataConnId(INT id, INT set = 0) ; 

    INT GetDataConnId(INT set = 0) const ; 

    BOOLEAN SetPhysicalPortNumber(UINT port, INT physet = 0, INT set = 0) ; 

    UINT GetPhysicalPortNumber(INT physet = 0, INT set = 0) const ; 

    BOOLEAN SetPhysicalPortService( UINT port, PortService  service, 
                                                INT physet = 0) ; 

    PortService GetPhysicalPortService(UINT port, INT physet = 0) const ; 

    INT GetNoOfAuthorizationSets() const ; 

    INT GetNoOfPortSets() const ; 

    INT GetNoOfPhysicalSets() const ; 

    INT GetNoOfPhysicalPortSets(INT physet = 0) const ; 

    INT GetNoOfAuthorizationSetsSupported() const ; 

    INT GetNoOfPortSetsSupported() const ; 
    
    INT GetNoOfPhysicalSetsSupported() const ; 
    
    INT GetNoOfPhysicalPortSetsSupported(INT physet = 0) const ;
   

    INT AddAuthorizationSet() ; 

    INT AddPortSet() ; 
    
    INT AddPhysicalSet() ; 
    
    INT AddPhysicalPortSet(INT physet = 0) ; 

    BOOLEAN RemoveAuthorizationSet(INT set = 0) ; 
    
    BOOLEAN RemovePortSet(INT set = 0) ; 
    
    BOOLEAN RemovePhysicalSet(INT set = 1) ; 
    
    BOOLEAN RemovePhysicalPortSet(INT physet = 0, INT set = 0) ; 


    BOOLEAN SetActiveAuthorizationSet(INT set = 0) ; 

    INT GetActiveAuthorizationSet() const ; 

    BOOLEAN SetActivePortSet(INT set = 0) ; 

    INT GetActivePortSet() const ; 

    BOOLEAN SetActivePhysicalSet(INT set = 0) ; 

    INT GetActivePhysicalSet() const ; 

    BOOLEAN SetActivePhysicalPortSet(INT physet = 0, INT set = 0) ; 

    INT GetActivePhysicalPortSet(INT physet = 0) const ; 


    WapProfileId GetProfileId() const ; 

    BOOLEAN SetProfileName(const CHAR* name) ; 

    const WCHAR* GetProfileName() const ; 


    BOOLEAN SetProfileWriteable(BOOLEAN writeable) ; 

    BOOLEAN IsProfileWriteable() const ; 


    /* WapProfileMgr is made friend here because Memory accessing methods have
        protected access and these methods are being used by the manager class
        to store or retrieve or delete profile from/to memory. These methods are
        protected because inherited class can in turn again override these. */
    friend class WapProfileMgr;

    protected:

    BOOLEAN SetProfileId(INT id) ; 


    BOOLEAN Load(WapProfileId prof_id) ; 


    BOOLEAN Save() ; 
 

    static BOOLEAN Delete(WapProfileId prof_id); 

    static BOOLEAN LoadProfileName(WapProfileId prof_id, WString &prof_name); 


    private:

    /* Copy Constructor and Overloaded Assignment operator are made private in
        order to prevent copy/assignment access to the user */
    WapProfile(const WapProfile&);
    WapProfile& operator=(const WapProfile&);

    PxLogicalCharacs::PxAuthInfoCharacs* 
                                GetAuthenticationSetPtr(INT set=0) const ; 
    PxLogicalCharacs::PxPortCharacs* GetPortSetPtr(INT set=0) const ; 
    PxLogicalCharacs::PxPhysicalCharacs* GetPhysicalSetPtr(INT set=0) const ; 
    PxLogicalCharacs::PxPortCharacs* 
                GetPhysicalPortSetPtr(INT physet = 0, INT set=0) const ; 


    BOOLEAN GetFreeAuthSetId(UINT8 &set_id) ; 
    BOOLEAN GetFreePortSetId(UINT8 &set_id) ; 
    BOOLEAN GetFreePhysicalId(UINT8 &set_id) ; 
    BOOLEAN GetFreePhysicalPortSetId(UINT8 &set_id, INT physet = 0) ; 

    private:

        WapProfileId m_profile_id   ;   // ID of this Wap Profile
        WString m_profile_name; // User Given Name of this profile
        BOOLEAN m_writeable;    // Whether the profile can be modified

        /* Array to denote which set numbers are in use. If a set with set
            number 0 exists, then 0th element of this array will be filled
            with a '1' else a '0'*/
        UINT8 m_auth_setids[c_max_auth_set]; 
        UINT8 m_port_setids[c_max_port_set]; 
        UINT8 m_phy_setids[c_max_physical_set]; 
        UINT8 m_phy_port_setids[c_max_physical_set]
                                             [c_max_phy_port_set]; 

        // This holds the set number of the active characteristic set       
        UINT8 m_active_auth_set; 
        UINT8 m_active_port_set; 
        UINT8 m_active_phy_set; 
        UINT8 m_active_phy_port_set[c_max_physical_set]; 

        PxLogicalCharacs* m_px_logical; 

};


#endif  // WapProfile_hpp

