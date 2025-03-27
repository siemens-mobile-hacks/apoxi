/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_PlmnScanList_hpp)
#define Apc_PlmnScanList_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/ElementList.hpp>

#include <Apc/NetworkTypes.hpp>


class PlmnListEntry : public Linkable<PlmnListEntry> {
    public:
        PlmnListEntry();
        virtual ~PlmnListEntry();
        BOOLEAN operator <(const PlmnListEntry &plmn_list_entry) const;
        BOOLEAN operator==(const PlmnListEntry &plmn_list_entry) const;
        void Init(const Plmn &plmn, PlmnForbiddenIndicator f_ind, PlmnPlacementIndicator p_ind, RadioAccessTechnology rat);
        const Plmn& GetPlmn() const { return (m_plmn); } 
        RadioAccessTechnology GetRadioAccessTechnology() const { return (m_rat); }
        BOOLEAN IsForbidden() const { return (m_forbidden_indicator == PLMN_FORBIDDEN); }
        INT GetPos() const { return ((INT)  m_placement_indicator); }

    private:
        Plmn                    m_plmn;
        PlmnForbiddenIndicator  m_forbidden_indicator;
        PlmnPlacementIndicator  m_placement_indicator;
        RadioAccessTechnology   m_rat;
};                          

typedef SortedElementList<PlmnListEntry> PlmnScanList;


#endif  // Apc_PlmnScanList_hpp


