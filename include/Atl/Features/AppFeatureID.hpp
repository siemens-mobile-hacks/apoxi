//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Features_AppFeatureID_hpp)
#define Atl_Features_AppFeatureID_hpp


#include <Atl/Features/ApplicationID.hpp>
#include <Atl/Features/FeatureID.hpp>

struct AppFeatureID {
    AppFeatureID();
    AppFeatureID(ApplicationID app_id, FeatureID feature_id);
    explicit AppFeatureID(const CHAR* app_id, const CHAR* feature_id);

#if defined(_DEBUG)
    String ToString();
#endif

    ApplicationID m_app_id;
    FeatureID m_feature_id;
};

#endif 


