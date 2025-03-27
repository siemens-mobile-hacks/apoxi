//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------


#ifndef Atl_MappingPolicy_hpp
#define Atl_MappingPolicy_hpp

#include <Auxiliary/DataItem.hpp>

class MappingPolicy {
    public:
        MappingPolicy();

        virtual ~MappingPolicy();

        virtual INT GetIndex(const DataItem& value) const;
        
        virtual DataItem GetValue(INT index) const { return DataItem((Number)index); }

        BOOLEAN SetProperty(ResourceParser& parser, GuiObjectFactory::PropertyId property_id, INT object_id);
};

class RangeMappingPolicy : public MappingPolicy {
    typedef MappingPolicy Base;
    public:
        RangeMappingPolicy();

        RangeMappingPolicy(INT range_count);

        virtual ~RangeMappingPolicy();

        void SetRangeCount(INT range_count) { m_range_count = range_count; }
        
        virtual INT GetIndex(const DataItem& value) const;

        virtual DataItem GetValue(INT index) const;

        BOOLEAN SetProperty(ResourceParser& parser, GuiObjectFactory::PropertyId property_id, INT object_id);

    private:
        INT m_range_count;
};
#endif  // Atl_MappingPolicy_hpp

