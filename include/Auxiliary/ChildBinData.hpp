/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_ChildBinData_hpp)
#define Auxiliary_ChildBinData_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BinData.hpp>

class ChildBinData : public BinData {
    typedef BinData Base;
    public:
        static ChildBinData* CreateInstance(const BinData& parent_data,
                                            UINT32 start_offset);

        virtual BOOLEAN Read(UINT32 idx, UINT8& val) const;
        
        virtual UINT32 Read(UINT32 idx, void *val, UINT32 nbytes) const;
        
        virtual UINT32 GetLength() const;

    protected:
        ChildBinData(const BinData& parent_data,
                     UINT32 start_offset);
        virtual ~ChildBinData();

    private:
        const BinData& m_parent_data;
        UINT32 m_start_offset;
};

#endif  // Auxiliary_ChildBinData_hpp

