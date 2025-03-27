/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Features_FeaturePool_hpp)
#define Atl_Features_FeaturePool_hpp

#include <Atl/Features/FeatureID.hpp>
#include <Auxiliary/SimpleMap.hpp>

class Feature;

class FeaturePool {
   public:

      virtual Feature* GetFeature(const FeatureID& id) const;

      virtual BOOLEAN AddFeature(Feature* feature);

      virtual BOOLEAN AddFeatures(Feature features[], INT size);

   protected:
      typedef SimpleMap<FeatureID,Feature*> FeaturePoolF;

   private:
      FeaturePoolF m_features;
};

#endif  // Atl_Features_FeaturePool_hpp


