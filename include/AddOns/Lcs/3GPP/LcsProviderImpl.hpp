/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_3GPP_LcsProviderImpl_hpp)
#define AddOns_Lcs_3GPP_LcsProviderImpl_hpp

#include <AddOns/Lcs/Common/LcsProviderImplBase.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>

class SsErrorCode;

class LcsProviderImpl : public LcsProviderImplBase, public StackMsgDispatcher
{
    typedef LcsProviderImplBase Base1;
    typedef StackMsgDispatcher Base2;

    public:
        
        virtual ~LcsProviderImpl();

        static LcsProviderImpl* GetInstance();

        static void ReleaseInstance();

        virtual void Init();

        virtual LcsErrorCode SendVerificationResult(UINT16 invoke_id, BOOLEAN user_response);

        virtual LcsErrorCode TransferLocationReq(MolrType molr_type,
                                                LocationMethod location_method,
                                                const LcsMmiQos& lcs_mmi_qos,
                                                const ClientId& client_id,
                                                const MlcNumber& mlc_number,
                                                INT32 repeat_interval);
        
        virtual void OnTimeOut(LcsTimerType timer_type);

        void SendEndReq();


    protected:

        virtual BOOLEAN OnMessage(const Message& msg);

        BOOLEAN OnLocationNotifInvoke(const StackMsgArgument& arg);

        BOOLEAN OnLocationResponse(const StackMsgArgument& arg);

//      BOOLEAN OnSsFacilityRej(const StackMsgArgument& arg);

        BOOLEAN OnSsError(const StackMsgArgument& arg);

        virtual BOOLEAN OnAbortResponse(const StackMsgArgument& arg);


    private:
        
        LcsProviderImpl();

        void ProcessMolr(const MolrInfo* molr_info);

        LcsErrorCode GetLcsError(const SsErrorCode& ss_err) const;


    private:

        static LcsProviderImpl* m_lcs_impl;

        BYTE m_ti_pd_molr;

        static const StackMsgArgMap<LcsProviderImpl> m_arg_map[];

        StackMsgArgMapContainer<LcsProviderImpl> m_arg_map_container;

}; // LcsProviderImpl

#endif // Apoxi_Lcs_LcsProviderImpl_hpp

