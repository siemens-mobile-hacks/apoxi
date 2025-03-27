/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AuxExtensions_PhoneNumberMergeProvider_hpp)
#define Apoxi_AuxExtensions_PhoneNumberMergeProvider_hpp

#include <AddOns/AuxExtensions/MergeProvider.hpp>

class PhoneNumberJoinRule;

class PhoneNumberMergeProvider : public MergeProvider
{
    typedef MergeProvider Base;
    public:
        PhoneNumberMergeProvider();

        PhoneNumberMergeProvider(INT provider_id, Provider* child_provider, Provider* merged_provider, INT child_key_colid, INT merge_key_colid, PhoneNumberJoinRule* merge_rule);
        virtual ~PhoneNumberMergeProvider();

        void Init(INT provider_id, Provider* child_provider, Provider* merge_provider, INT child_key_colid, INT merge_key_colid, PhoneNumberJoinRule* merge_rule);
        
        virtual BOOLEAN GetDefaultDataItem(INT columnid, INT row, DataItem& item);
        
    protected:
        virtual BOOLEAN IsPhoneNumberTextDefaultData(INT columnid, INT row);
        virtual BOOLEAN IsLess(const DataItem& item1, const DataItem& item2);

};

#endif  // Apoxi_AuxExtensions_PhoneNumberMergeProvider_hpp

