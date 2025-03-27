/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsDecls_hpp)
#define AddOns_Lcs_Common_LcsDecls_hpp

#include "LcsTimer.hpp"
#include "LcsRepeatTimer.hpp"
#include "LcsTypes.hpp"

class LcsProviderImplBase;
class Application;

enum VerificationResponse
{
    PermissionDenied = MTLR_PERMISSION_DENIED,
    PermissionGranted = MTLR_PERMISSION_GRANTED,
    NoResponseFromUser = MTLR_NO_RESPONSE
};

enum LocationMethod
{
    ms_based_eotd = MN_MS_BASED_EOTD,
    ms_assisted_eotd = MN_MS_ASSISTED_EOTD,
    assisted_gps = MN_ASSISTED_GPS
};

struct LcsQos
{
    BYTE                m_horiz_accuracy;

    BYTE                m_vert_accuracy;

    RespTimeCategory    m_rsp_time_cat;
};

class MolrParams
{
    public:
        
        MolrParams( MolrType molr_type,
                    LocationMethod loc_method,
                    const LcsQos& lcs_qos,
                    const ClientId& client_id,
                    const MlcNumber& mlc_number)
        {
            m_molr_params.molr_type = (T_MN_MOLR_TYPE) molr_type;
            m_molr_params.loc_method = (T_MN_LOC_METHOD) loc_method;
            m_molr_params.lcs_qos.horiz_accuracy = (byte) lcs_qos.m_horiz_accuracy;
            m_molr_params.lcs_qos.vertic_accuracy = (byte) lcs_qos.m_vert_accuracy;
            m_molr_params.lcs_qos.rsp_time_cat = (T_MN_RESPONSE_TIME_CATEGORY) lcs_qos.m_rsp_time_cat;
            memcpy(m_molr_params.client_id.A, &client_id, sizeof(ClientId));
            memcpy(m_molr_params.mlc_number.A, &mlc_number, sizeof(MlcNumber));
        }

        const T_MN_MOLR_REQ& GetMolrParams() const { return m_molr_params; }
        

    private:

        MolrParams();


    private:

        T_MN_MOLR_REQ m_molr_params;
        
}; // MolrParams


/*  -------------------------------------------------
    Declarations used by the request processor
    -------------------------------------------------*/

class InvokeId
{
    public:

        InvokeId()
        { 
            ++m_invoke_id;
            if(m_invoke_id == 0) // 0 is an invalid InvokeId
                ++m_invoke_id;
        }

        UINT16 GetInvokeId() const { return m_invoke_id; }


    private:

        static UINT16 m_invoke_id;

}; // InvokeId

struct MolrInfo : public Linkable<MolrInfo>
{
    MolrInfo(   MolrType molr_type,
                LocationMethod location_method,
                const LcsQos& lcs_qos,
                const ClientId& client_id,
                const MlcNumber& mlc_number,
                INT32 repeat_interval,
                const Application* app,
                const LcsProviderImplBase* provider)
                : m_molr_type(molr_type), m_location_method(location_method), 
                m_lcs_qos(lcs_qos), m_client_id(client_id), m_mlc_number(mlc_number),
                m_repeat_interval(repeat_interval)
    {
        // Remove the constness
        m_app = (Application*) app;
        m_provider = (LcsProviderImplBase*) provider;
    }

    virtual ~MolrInfo()
    {
    }

    MolrType                m_molr_type;
    LocationMethod          m_location_method;
    LcsQos                  m_lcs_qos;
    ClientId                m_client_id;
    MlcNumber               m_mlc_number;
    INT32                   m_repeat_interval; 
    Application*            m_app;
    LcsProviderImplBase*    m_provider;


private:

    MolrInfo();

}; // MolrInfo

struct MolrRepeatInfo : public MolrInfo
{
    typedef MolrInfo Base;

    MolrRepeatInfo( MolrType molr_type,
                    LocationMethod location_method,
                    const LcsQos& lcs_qos,
                    const ClientId& client_id,
                    const MlcNumber& mlc_number,
                    INT32 repeat_interval,
                    const Application* app,
                    const LcsProviderImplBase* provider)
                    : Base( molr_type, location_method, lcs_qos, client_id,
                            mlc_number, repeat_interval, app, provider)
    {
        // Assign a unique invoke id to this request
        m_invoke_id = InvokeId().GetInvokeId();

        // Initialize the repeat MO-LR timer
        const UINT16 SEC_TO_MSEC = 1000;
        m_rep_timer.Init(m_invoke_id, m_repeat_interval * SEC_TO_MSEC);
    }

    virtual ~MolrRepeatInfo()
    {
        m_rep_timer.Stop();
    }

    UINT16 m_invoke_id;
    LcsRepeatTimer m_rep_timer; // To know when it's time to repeat the location request 

    
private:

    MolrRepeatInfo();

}; // MolrRepeatInfo

struct MtlrInfo : public Linkable<MtlrInfo>
{
    MtlrInfo(BYTE ti_pd, LcsNotificationType notif_type, const LcsProviderImplBase* provider)
            : m_ti_pd(ti_pd), m_notif_type(notif_type)
    {
        // Remove the constness
        m_provider = (LcsProviderImplBase*) provider;

        // Assign a unique invoke id to this request
        m_invoke_id = InvokeId().GetInvokeId();

        // Initialize the timer
        const UINT16 MTLR_TIMEOUT = 8400; // in msec
        m_lcs_timer.Init(MtlrTimer, MTLR_TIMEOUT, m_provider);
    }

    virtual ~MtlrInfo()
    {
        m_lcs_timer.Stop();
    }

    BYTE m_ti_pd;
    UINT16 m_invoke_id;
    LcsNotificationType m_notif_type;
    LcsTimer m_lcs_timer;
    LcsProviderImplBase* m_provider;


private:

    MtlrInfo();

};

#endif // AddOns_Lcs_Common_LcsDecls_hpp

