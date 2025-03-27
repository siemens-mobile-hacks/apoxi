/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Feature_hpp)
#define Feature_hpp

#include <Atl/Features/FeatureID.hpp>

class AtlApplication;

class Feature {

    public:

      enum {
         ID = 3
      };

      enum FeatureAttributeId {
          UnspecifiedAttributeId    = -1,
          AvailableAttributeId          = 0,
          EnabledAttributeId            = 1,
          CustomAttributeId     = 99
      };

      Feature();

      Feature(AtlApplication* app, 
              const FeatureID& id);

      virtual ~Feature();
    
      void Init(AtlApplication* app, 
                const FeatureID& id);

      void Init(AtlApplication* app, 
                const FeatureID& id, 
                BOOLEAN available, 
                BOOLEAN enabled);
         
      // TODO: Remove
      virtual INT GetID() const;
        
      virtual BOOLEAN IsInstanceOf(INT id) const;

      virtual BOOLEAN IsEqual(const Feature& feature) const;

      inline const FeatureID& GetFeatureId() const { return m_feature_id; }

      inline void SetApplication(AtlApplication* app) { m_app = app; }

      inline AtlApplication* GetApplication() const { return m_app; }

      virtual BOOLEAN Execute();

      void      SetEnabled(BOOLEAN enabled);

      BOOLEAN   IsEnabled() const { return m_bits.is_enabled; }

      void      SetAvailable(BOOLEAN available);

      BOOLEAN   IsAvailable() const { return m_bits.is_available; }
      
      void      BlockNotification(BOOLEAN block) { m_bits.block_notification = block; }

      BOOLEAN   IsNotificationBlocked() const { return m_bits.block_notification; }

  
protected:

      void NotifyFeatureChange(INT property_id = UnspecifiedAttributeId); 

      FeatureID         m_feature_id;
      
      AtlApplication*   m_app;
      
   private:
      Feature(const Feature& orig);
      Feature& operator = (const Feature& rhs);

        struct {
            UINT is_enabled : 1;
            UINT is_available : 1;
            UINT block_notification : 1;
         } m_bits;
};

#endif /* Feature_hpp */

