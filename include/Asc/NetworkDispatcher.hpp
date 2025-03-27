/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_NetworkDispatcher_hpp)
#define Asc_NetworkDispatcher_hpp

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    NetworkDispatcher
    ======================================================================== */
class NetworkDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        NetworkDispatcher();
        
        virtual ~NetworkDispatcher();

    protected:
        BOOLEAN OnConnectionInd(const StackMsgArgument &arg);

        BOOLEAN OnCellInfoInd(const StackMsgArgument &arg);
        
        BOOLEAN OnMnInformationInd(const StackMsgArgument &arg);

        BOOLEAN OnTestparamInd(const StackMsgArgument &arg);

        BOOLEAN OnBandSelectionInd(const StackMsgArgument &arg);

        BOOLEAN OnHomezoneInd(const StackMsgArgument &arg);

        BOOLEAN OnEngineeringModeControlResponse(const StackMsgArgument &arg);

        BOOLEAN OnOmBandStatusCnf(const StackMsgArgument &arg);
    private:
        void ProcessLsaIdentifier(const MnInformationIndArg &arg);
        void ProcessNetworkInformation(const MnInformationIndArg &arg);
        void ProcessTimeZone(const MnInformationIndArg &arg);
        
        static const StackMsgArgMap<NetworkDispatcher> m_arg_map[];
        StackMsgArgMapContainer<NetworkDispatcher> m_arg_map_container;

        static TimeZone old_tz;
        static WString old_network_name_long;
        static WString old_network_name_short;
        static BOOLEAN old_network_name_long_add_ci;
        static BOOLEAN old_network_name_short_add_ci;
        static LsaIdentifier old_lsa_identifier;
        static SDL_Boolean old_is_lsa_identifier_present;

};

#endif // Asc_NetworkDispatcher_hpp


