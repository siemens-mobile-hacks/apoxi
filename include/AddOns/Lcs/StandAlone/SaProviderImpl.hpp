/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_StandAlone_SaProviderImpl_hpp)
#define AddOns_Lcs_StandAlone_SaProviderImpl_hpp

#include <AddOns/Lcs/Common/LcsProviderImplBase.hpp>

class SaProviderImpl : public LcsProviderImplBase, public StackMsgDispatcher
{
    typedef LcsProviderImplBase Base1;
    typedef StackMsgDispatcher Base2;

    public:
        
        virtual ~SaProviderImpl();

        static SaProviderImpl* GetInstance();

        static void ReleaseInstance();

        virtual void Init();

        virtual LcsErrorCode TransferLocationReq(MolrType molr_type,
                                                LocationMethod location_method,
                                                const LcsMmiQos& lcs_mmi_qos,
                                                const ClientId& client_id,
                                                const MlcNumber& mlc_number,
                                                INT32 repeat_interval);
        
        virtual void OnTimeOut(LcsTimerType timer_type);

    
    protected:

        virtual BOOLEAN OnMessage(const Message& msg);

        BOOLEAN OnLocationResponse(const StackMsgArgument& arg);

        BOOLEAN OnLocationError(const StackMsgArgument& arg);

        virtual BOOLEAN OnAbortResponse(const StackMsgArgument& arg);


    private:
        
        SaProviderImpl();

        void ProcessMolr(const MolrInfo* molr_info);


    private:

        static SaProviderImpl* m_self;

        static const StackMsgArgMap<SaProviderImpl> m_arg_map[];

        StackMsgArgMapContainer<SaProviderImpl> m_arg_map_container;

}; // SaProviderImpl

#endif // AddOns_Lcs_StandAlone_SaProviderImpl_hpp

