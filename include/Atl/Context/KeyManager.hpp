//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_KeyManager_hpp)
#define Atl_Context_KeyManager_hpp

#if defined(APOXI_COMPAT_2_7_0)
#include <Auxiliary/LinkedList.hpp>
#include <Atl/Context/KeySequence.hpp>
#endif  // APOXI_COMPAT_2_7_0

class FeatureHandle;
class AtlApplication;

class KeyManager {
   public:
      ~KeyManager();
       
      static KeyManager& GetInstance() { return m_instance; }

      static void SwallowKey(KeyCode key_code) { m_swallow_key = key_code; }

      BOOLEAN HandleMessage(const Message &msg, AtlApplication* parent);

    
   private:
      KeyManager();
            
      static KeyManager m_instance;

      static KeyCode m_swallow_key;

      const FeatureHandle*  m_longkey_feature;
      const FeatureHandle*  m_verylong_feature;


};

#endif // Atl_Context_KeyManager_hpp 

