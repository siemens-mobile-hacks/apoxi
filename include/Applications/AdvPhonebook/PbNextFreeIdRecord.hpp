/*------------------------------------------------------------------------
Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */
#if !defined(Mmi_PbNextFreeIdRecord_hpp)
#define Mmi_PbNextFreeIdRecord_hpp

// Included header file for the super class.
#include <AddOns/AdcExtensions/Record.hpp>

class PbNextFreeIdRecord : public Record
{
    public:
        
        PbNextFreeIdRecord();

        virtual const UINT8* GetData();

        virtual void SetData(const UINT8* data);

        virtual INT GetPersistentSize();

        void    SetNextFreeUniqueId(UINT32 next_free_unique_id){
            m_data.m_next_free_unique_id = next_free_unique_id;}
        
        UINT32 GetNextFreeUniqueId(){return m_data.m_next_free_unique_id;}
    private:

        struct Persist{
            UINT32                  m_next_free_unique_id;
        }m_data;
};
#endif //Mmi_PbNextFreeIdRecord_hpp
