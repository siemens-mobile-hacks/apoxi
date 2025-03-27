/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Gprs_PlmnDispatcher_gprs_hpp)
#define Asc_Gprs_PlmnDispatcher_gprs_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    PlmnDispatcher
    ======================================================================== */
class PlmnDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        PlmnDispatcher();
        virtual ~PlmnDispatcher();

        void SetBlockingScan(BOOLEAN blocking_scan) { m_blocking_scan = blocking_scan; }
        BOOLEAN IsAttachAllowed() const { return (m_attach_allowed); }
        
        void Register(const RegisterMode &mode, const Plmn &plmn, RadioAccessTechnology plmn_rat_mode,
                    RatChangeMode rat_change_mode = InvalidRatChangeMode, 
                    RadioAccessTechnology rat_mode = RatNotAvailable, 
                    GsmService gsm_service = InvalidGsmService) const;

        void Detach() const;

        void Detach(const GsmService gsm_service) const;

        void Detach(const RatChangeMode rat_change_mode, RadioAccessTechnology rat_mode = RatNotAvailable) const;

        void Detach(RadioAccessTechnology rat_mode) const;

        //Check if rat-change is possible
        BOOLEAN IsRatChangePossible() const;

    protected:
        BOOLEAN OnAttachCnf(const StackMsgArgument &arg);
        BOOLEAN OnAttachRej(const StackMsgArgument &arg);
        BOOLEAN OnAttachAllowedInd(const StackMsgArgument &arg);
        BOOLEAN OnDetachCnf(const StackMsgArgument &arg);
        BOOLEAN OnGprsClassInd(const StackMsgArgument &arg);
        BOOLEAN OnNRegStateInd(const StackMsgArgument &arg);
        BOOLEAN OnPlmnListCnf(const StackMsgArgument &arg);
        BOOLEAN OnPlmnListRej(const StackMsgArgument &arg);
        BOOLEAN OnRegStateInd(const StackMsgArgument &arg);
        BOOLEAN OnOmRatChangeInd(const StackMsgArgument &arg);      

    private:
        void ChangeGsmService(GsmService gsm_service) const;
        void ChangeRatMode(RatChangeMode rat_change_mode, RadioAccessTechnology rat_mode) const;

        static const StackMsgArgMap<PlmnDispatcher> m_arg_map[];
        StackMsgArgMapContainer<PlmnDispatcher> m_arg_map_container;

        BOOLEAN m_blocking_scan;
        PlmnScanList m_plmn_scan_list;
        BOOLEAN m_attach_allowed;
        static GsmService m_new_gsm_service;
        static RatChangeMode m_new_rat_change_mode;
        static RadioAccessTechnology m_new_radio_access_technology;
        static RegisterMode m_register_mode;
        static Plmn m_register_plmn;
        static RadioAccessTechnology m_register_rat;
};


#endif // Asc_Gprs_PlmnDispatcher_gprs_hpp

