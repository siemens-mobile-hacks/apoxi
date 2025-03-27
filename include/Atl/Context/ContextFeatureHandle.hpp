//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_ContextFeatureHandle_hpp)
#define Atl_Context_ContextFeatureHandle_hpp

#include <Atl/Features/FeatureHandle.hpp>

class ContextFeatureHandle: public FeatureHandle{
    public:
        ContextFeatureHandle(const AppFeatureID& id, 
                             const DataItem& contextitem, 
                             BOOLEAN fixed_context);
        
        virtual ~ContextFeatureHandle();
        
        virtual void Execute(AtlApplication* context_app = 0) const;

    private:
        const DataItem& GetContextItem();
      
        DataItem m_context_item;
        BOOLEAN  m_fixed_context;
};


#endif // Atl_Context_ContextFeatureHandle_hpp 


