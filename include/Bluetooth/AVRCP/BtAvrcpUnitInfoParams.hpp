/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpUnitInfoParams_hpp)
#define BtAvrcpUnitInfoParams_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */


class BtAvrcpUnitInfoParams
{

    public:
        BtAvrcpUnitInfoParams();

        virtual ~BtAvrcpUnitInfoParams();

        /**********************************************************************/
        /* Bt Avrcp Unit Info                             */
        /**********************************************************************/


        const BtAvrcpSubunitType GetUnitType() const { return m_unit_type; };


        void SetUnitType(BtAvrcpSubunitType type) { m_unit_type = type; };


        const UINT8 GetUnit() const { return m_unit; };


        void SetUnit(UINT8 unit) { m_unit = unit; };


        const ULONG GetCompanyId() const { return m_company_id; };


        void SetCompanyId(ULONG company_id) { m_company_id = company_id; };

    private:
        BtAvrcpSubunitType          m_unit_type;
        UINT8                       m_unit;
        ULONG                       m_company_id;
};

#endif  // BtAvrcpUnitInfoParams_hpp

