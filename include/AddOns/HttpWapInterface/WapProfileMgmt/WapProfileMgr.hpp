/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(WapProfileMgr_hpp)

#define WapProfileMgr_hpp


#include <AddOns/HttpWapInterface/WapProfileMgmt/WapProfile.hpp>


class WapProfileMgr {
public:
    struct WapProfileInfo : public Linkable<WapProfileInfo> {
    WapProfileId m_prof_id; 
    WString m_prof_name; 
    };

    ~WapProfileMgr();

    static WapProfileMgr& GetInstance()
    {
        return m_wap_prof_mgr;
    }   // GetInstance



    BOOLEAN Init()
    {
        m_active_profile_id = WapProfile::c_invalid_id;
        return LoadProfileInfo();
    }   // Init


    const LinkedList<WapProfileInfo>& GetWapProfileInfo() const 
    { 
        return m_profileinfo_list; 
    }   // GetWapProfileInfo


    BOOLEAN CreateWapProfile(WapProfile &profile);


    BOOLEAN GetWapProfile(WapProfileId prof_id, WapProfile &profile); 


    BOOLEAN SaveWapProfile(WapProfile &profile); 


    BOOLEAN DeleteWapProfile(WapProfileId prof_id); 


    BOOLEAN SetActiveWapProfile(WapProfileId active_prof_id); 


    WapProfileId GetActiveWapProfileId()
    {
        return m_active_profile_id;
    }   // GetActiveWapProfileId

    
private:

    WapProfileMgr();


    BOOLEAN LoadProfileInfo();
    
    BOOLEAN AddProfileInfo(WapProfileId prof_id, WString prof_name);

    BOOLEAN UpdateProfileInfo(WapProfileId prof_id, WString prof_name);

    BOOLEAN RemoveProfileInfo(WapProfileId prof_id);

    BOOLEAN IsProfileIdValid(WapProfileId prof_id);


private:
    
    BOOLEAN m_init;

    static WapProfileMgr m_wap_prof_mgr;

    UINT8 m_prof_id_gen_array[WapProfile::c_max_wap_profile_count];

    WapProfileId m_active_profile_id; 

    LinkedList<WapProfileInfo> m_profileinfo_list;

}; // WapProfileMgr

#endif  // WapProfileMgr_hpp

