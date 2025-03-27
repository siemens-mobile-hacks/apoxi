//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Features_FeatureHandle_hpp)
#define Atl_Features_FeatureHandle_hpp

#include <Atl/Features/AppFeatureID.hpp>

class AtlApplication;

class FeatureHandle
{
    public:
        FeatureHandle(const AppFeatureID& id);
      
        ~FeatureHandle();

        virtual  void           Execute(AtlApplication* context_app = 0) const;

        const AppFeatureID&     GetAppFeatureID() const { return m_featureID;}
        
    protected:
        AppFeatureID m_featureID;
};


#endif // Atl_Features_FeatureHandle_hpp 


