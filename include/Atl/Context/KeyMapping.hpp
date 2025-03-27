//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_KeyMapping_hpp)
#define Atl_Context_KeyMapping_hpp

#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/Map.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Features/FeatureHandle.hpp>
#include <Atl/Context/KeySequence.hpp>
#include <Auxiliary/LinkedList.hpp>
#endif  // APOXI_COMPAT_2_7_0

class FeatureHandle;
class KeySequence;
class KeySequenceCandidate;
class KeyMapping {
    
    friend class KeyManager;

    public:
        
        KeyMapping();

        ~KeyMapping();

        void            AddVKey(KeyCode hw_key, KeyCode v_key);

        KeyCode         GetVKey(KeyCode hw_key) const;

        void            AddVKeyFeature(KeyCode key, const FeatureHandle* feature_handle);

        const FeatureHandle*    GetFeature(KeyCode key) const;

        void            AddVKeyLongFeature(KeyCode key, const FeatureHandle* feature_handle);

        const FeatureHandle*    GetLongFeature(KeyCode key) const;


        void            AddKeySequenceFeature(KeySequence* sequence, const FeatureHandle* feature_handle);

        const FeatureHandle*  GetSequenceFeature(KeyCode key, BOOLEAN& consume_last_key);

        void            AddVKeyVeryLongFeature(KeyCode key, const FeatureHandle* feature_handle);

        const FeatureHandle*    GetVeryLongFeature(KeyCode key) const;


    protected:
        
        static void UpdateExpireTime();

    private:

        typedef Map <KeyCode, KeyCode>               VKeyMapping;
        typedef Map <KeyCode, const FeatureHandle*>      VKeyFeatureMap;
        typedef Map <KeySequence*, const FeatureHandle*>   KeySequenceFeatureMap;
        typedef Map <KeySequence*, KeyCode>          KeySequenceVKeyMap;

        typedef SimpleMap  <KeySequenceCandidate*,const FeatureHandle* >  KeySequenceFeatureCandidates;
        typedef SimpleMap  <KeySequenceCandidate*, KeyCode >  KeySequenceVKeyCandidates;


        VKeyMapping     m_vkey_keys;
        VKeyFeatureMap  m_feature_keys;
        VKeyFeatureMap  m_vkey_long_feature_keys;
        VKeyFeatureMap  m_very_long_feature_keys;

        KeySequenceFeatureMap*  m_keysequence_features;
    
        static void           AddSequenceFeatureCandidate(KeySequenceFeatureMap::Iterator iter);
        static const FeatureHandle* GetSequenceFeatureCandidate(KeyCode key, BOOLEAN& consume_last_key);

        static void    AddSequenceVKeyCandidate(KeySequenceVKeyMap::Iterator iter);
        static KeyCode GetSequenceVKeyCandidate(KeyCode key, BOOLEAN& consume_last_key);

        static void FlushCandidates();

        
        static Ticks  m_last_key_pressed;
        static KeySequenceFeatureCandidates s_keysequence_feature_candidates;
        static KeySequenceVKeyCandidates    s_keysequence_vKey_candidates;
    
        

};

#endif // Atl_Context_KeyMapping_hpp 
 


