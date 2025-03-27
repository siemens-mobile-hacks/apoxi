/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbAdvDataHandler_hpp)
#define Mmi_PbAdvDataHandler_hpp

#include <Adc/DataHandler.hpp>
#include <AddOns/AuxExtensions/JoinRule.hpp>

#include <AdvPhonebook/PbNameFilterProvider.hpp>

#include <AdvPhonebook/PbFfsNameHandler.hpp>
#include <AdvPhonebook/PbNameProvider.hpp>
#include <AdvPhonebook/PbFfsNumberHandler.hpp>
#include <AdvPhonebook/PbNumberProvider.hpp>
#include <AdvPhonebook/PbSimProvider.hpp>

#include <AdvPhonebook/GroupProvider.hpp>
#include <AdvPhonebook/PbMergeProvider.hpp>
#include <AdvPhonebook/PbDataHandler.hpp>

class PbAdvDataHandler : public PbDataHandler {
    typedef PbDataHandler Base;

    public:

        PbAdvDataHandler();
        virtual ~PbAdvDataHandler();

        void Init();

        virtual Provider* GetPbProvider();
        virtual Provider* GetDistinctNameProvider();
        Provider* GetNameProvider() { return &m_name_provider; }
        Provider* GetNumberProvider() { return &m_no_provider; }

        virtual void UpdateProvider(ProviderListener *listener = 0);
        void ObserveProvider(BOOLEAN observe);
//CN200013749 
        UINT32 GetLastDeletedUniqueId(){
            return m_pb_provider.GetLastDeletedUniqueId();}
//END CN200013749 

    private:
        void InitIccFilter();

        PbFfsNameHandler        m_name_handler;
        PbFfsNumberHandler      m_number_handler;
        PbMergeProvider         m_pb_provider;
        PbNameProvider          m_name_provider;
        PbNumberProvider        m_no_provider;
        FilterProvider          m_name_icc_provider;
        StandardJoinRule        m_join_rule;
        EqualsRule              m_rule;
        Protector               m_protector;
        GroupProvider           m_group_provider;

};

#endif
