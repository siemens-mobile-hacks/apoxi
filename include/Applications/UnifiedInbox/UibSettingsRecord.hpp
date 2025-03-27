/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */ 

#if !defined(Mmi_UibSettingsRecord_hpp)
#define Mmi_UibSettingsRecord_hpp

#include <AddOns/AdcExtensions/Record.hpp>

class UibSettingsRecord : public Record {
    typedef Record Base;

    public:
        UibSettingsRecord(UINT8 sort_key = 0, BOOLEAN sort_asc = TRUE);

        UINT8 GetSortKey() const { return m_data.m_bits.sort_key; }

        void SetSortKey(UINT8 value) { m_data.m_bits.sort_key = value; }

        void SetSortAsc(BOOLEAN flag) { m_data.m_bits.sort_asc = flag; }

        BOOLEAN IsSortAsc() const { return m_data.m_bits.sort_asc; }

        void SetDefault();

        virtual const UINT8* GetData();
        
        virtual void SetData(const UINT8* data);
        
        virtual INT GetPersistentSize();

        virtual void MarkDeleted();
        
        virtual BOOLEAN IsRecordDeleted();

    private:
        struct Persist {
            struct {
                UINT8 sort_key : 7;
                UINT8 sort_asc : 1;
            } m_bits;
        } m_data;
};

#endif /* Mmi_UibSettingsRecord_hpp */
