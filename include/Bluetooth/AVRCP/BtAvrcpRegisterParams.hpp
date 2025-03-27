/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpRegisterParams_hpp)
#define BtAvrcpRegisterParams_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */


class BtAvrcpRegisterParams
{

    public:
        BtAvrcpRegisterParams();

        virtual ~BtAvrcpRegisterParams();

        /**********************************************************************/
        /* Bt Avrcp Unit Info                             */
        /**********************************************************************/
        void SetRole(BtAvrcpRole role) { m_role = role; };

        BtAvrcpRole GetRole() { return m_role; };

        const BtAvrcpSubunitType GetUnitType() const { return m_unit_type; };

        void SetUnitType(BtAvrcpSubunitType type) { m_unit_type = type; };

        const UINT8 GetUnit() const { return m_unit; };


        void SetUnit(UINT8 unit) { m_unit = unit; };

        const ULONG GetCompanyId() const { return m_company_id; };

        void SetCompanyId(ULONG company_id) { m_company_id = company_id; };

        const UINT8 GetNoOfSubunits() const { return m_no_of_subunits; };

        const BtAvrcpSubunitInfoEntry* GetSubunitInfos() const { return m_subunit_infos; };

        void SetSubunitInfos(UINT8 no_of_subunits, BtAvrcpSubunitInfoEntry* subunit_infos);

        const UINT8 GetSupportedCategories() const { return m_categories; };

        void SetSupportedCategories(UINT8 categories) { m_categories = categories; };

        BOOLEAN ReleaseSubunitInfos();

    private:
        BtAvrcpSubunitType          m_unit_type;
        UINT8                       m_unit;
        UINT8                       m_categories;
        ULONG                       m_company_id;
        BtAvrcpRole                 m_role;
        UINT8                       m_no_of_subunits;
        BtAvrcpSubunitInfoEntry*    m_subunit_infos;
};

#endif  // BtAvrcpRegisterParams_hpp

