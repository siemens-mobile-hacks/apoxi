/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_GltpProviderImpl_hpp)
#define AddOns_Lcs_GLTP_GltpProviderImpl_hpp

#include <AddOns/Lcs/Common/LcsProviderImplBase.hpp>

class Application;
class GltpAidDataRequests;
class GltpAssistanceData;
class MeasurementData;
struct LocationEstimate;

class GltpProviderImpl : public LcsProviderImplBase, public StackMsgDispatcher
{
    typedef LcsProviderImplBase Base1;
    typedef StackMsgDispatcher Base2;

    public:

        virtual ~GltpProviderImpl();

        static GltpProviderImpl* GetInstance();

        static void ReleaseInstance();

        virtual void Init();

        virtual LcsErrorCode TransferLocationReq(MolrType molr_type,
                                                LocationMethod location_method,
                                                const LcsMmiQos& lcs_mmi_qos,
                                                const ClientId& client_id,
                                                const MlcNumber& mlc_number,
                                                INT32 repeat_interval);

        virtual void OnTimeOut(LcsTimerType timer_type);

        void RegisterConnApp(Application* conn_app)
        {   
            ASSERT_DEBUG(conn_app != NULL);
            m_gltp_conn_app = conn_app;
        }

        void SetDataConnResult(LcsErrorCode result, BYTE* ack_buff = NULL, INT size = 0);

        void GetConfigValues(INT32& latitude, INT32& longitude, UINT32& unit_id) const;

        void StoreConfigValues(INT32 latitude, INT32 longitude, UINT32 unit_id);


    protected:

        virtual BOOLEAN OnMessage(const Message& msg);

        BOOLEAN OnMeasurementResp(const StackMsgArgument& arg);

        virtual BOOLEAN OnAbortResponse(const StackMsgArgument& arg);


    private:

        GltpProviderImpl();

        void ProcessMolr(const MolrInfo* molr_info);

        void SetupDataConn();

        void SendHello();

        void ProcessHelloAck(const BYTE* hello_ack_buf, INT size);

        void ProcessAidingAck(const BYTE* hello_ack_buf, INT size);

        BOOLEAN ProcessPositionData(const BYTE* position_buf, INT size);

        BOOLEAN ExtractLocationEstimate(const BYTE* head, LocationEstimate& loc_est);

        const BYTE* DecodeLocationValue(const BYTE* pos_buf, BYTE* pos_value) const;

        void TerminateMolr();

        void LoadConfigValues() const;

        BOOLEAN ValidateData(const BYTE* data, INT size) const;


    private:

        static GltpProviderImpl* m_self;

        static const StackMsgArgMap<GltpProviderImpl> m_arg_map[];

        enum
        {
            Idle,                   
            SetupDataConnSent,      

            DataConnEstablished,    
            HelloSent,              

            HelloAckRcvd,           
            AidingReqSent,          

            AidingAckRcvd,          

            MeasurementSent,        

            PosDataSent             

        } m_molr_state;

        Application* m_gltp_conn_app;

        Application* m_lcs_app;

        GltpAidDataRequests* m_ad_reqs;

        GltpAssistanceData* m_assist_data;

        BOOLEAN m_ms_based;

        BOOLEAN m_is_inited;

        INT m_num_attempts;

        StackMsgArgMapContainer<GltpProviderImpl> m_arg_map_container;

};

#endif // AddOns_Lcs_GLTP_GltpProviderImpl_hpp

