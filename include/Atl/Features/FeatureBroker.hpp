//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Features_FeatureBroker_hpp)
#define Atl_Features_FeatureBroker_hpp

#include <Auxiliary/SimpleMap.hpp>

#include <Atl/Features/AppFeatureID.hpp>
#include <Atl/Features/FeatureID.hpp>
#include <Atl/Features/MenuID.hpp>


class AtlApplication;
class Feature;
class MenuDesc;

class FeatureBroker {

    friend class Feature;
    friend class Property;

    public:

        static FeatureBroker* GetInstance() { return &m_instance; }
            
        virtual ~FeatureBroker();
            
        BOOLEAN RegisterApplication(AtlApplication* app) ;

        Feature * GetFeature(const ApplicationID& appID, 
                             const FeatureID& feature) const ;

        Feature * GetFeature(const AppFeatureID& id) const { return GetFeature(id.m_app_id, id.m_feature_id); }

        BOOLEAN OnFeatureAdded(Feature* feature);

        virtual MenuDesc* GetMenu(const MenuID& id);

        void    OnFeatureStatusChanged(Feature* feature);

    protected:
        BOOLEAN IsMenuInitialized();

    private:
        FeatureBroker();
          
        void InitMenus();

        typedef SimpleMap<ApplicationID,AtlApplication*> ApplicationsContainer;

        ApplicationsContainer m_applications;

        BOOLEAN m_menu_initialized;

        static FeatureBroker m_instance;
};
#endif // Atl_Features_FeatureBroker_hpp 


