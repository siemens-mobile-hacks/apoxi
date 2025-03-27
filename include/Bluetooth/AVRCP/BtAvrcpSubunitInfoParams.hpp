/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpSubunitInfoParams_hpp)
#define BtAvrcpSubunitInfoParams_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */



class BtAvrcpSubunitInfoParams
{

    public:
        BtAvrcpSubunitInfoParams();


        virtual ~BtAvrcpSubunitInfoParams();

        /**********************************************************************/
        /* Bt Avrcp Sub Unit Info                             */
        /**********************************************************************/


        const UINT8 GetPage() const { return m_page; };


        void SetPage(UINT8 page) { m_page = page; };


        const UINT8 GetNoOfSubunitInfoEntries() const { return m_no_of_subunit_info_entries; };


        void SetNoOfSubunitInfoEntries(UINT8 no_of_subunit_info_entries) { m_no_of_subunit_info_entries = no_of_subunit_info_entries; };


        const BtAvrcpSubunitInfoEntry* GetSubunitInfoEntries() const { return m_subunit_info_entries; };


        void SetSubunitInfoEntries(BtAvrcpSubunitInfoEntry* subunit_info_entries);


    private:

        UINT8                   m_page;
        UINT8                   m_no_of_subunit_info_entries;
        BtAvrcpSubunitInfoEntry m_subunit_info_entries[4];

};

#endif  // BtAvrcpSubunitInfoParams_hpp

