//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_KeySequence_hpp)
#define Atl_Context_KeySequence_hpp

#if defined(APOXI_COMPAT_2_7_0)
#include <Auxiliary/Vector.hpp>
#include <Atl/Features/FeatureHandle.hpp>
#endif  // APOXI_COMPAT_2_7_0
class AtlApplication;

class KeySequence {
        friend class KeySequenceCandidate; 
        friend class KeyMapping;

    public:

        KeySequence(const KeyCode* keys, INT length, BOOLEAN consume_last_key);

        ~KeySequence();

        BOOLEAN GetConsumeLastKey() const;

        BOOLEAN HasKeyAtPos(const KeyCode& key_code, INT pos) const;

        INT GetLength() const;

    protected:
        BOOLEAN IsStartOfSequence(const KeyCode& key) const;

        
    private:
        const KeyCode* GetKeys() const; 
        
        /* List of keys */
        const KeyCode* m_keys;
        const INT m_length;
        const BOOLEAN m_consume_last_key;
        
};

class KeySequenceCandidate
{
    public:

        KeySequenceCandidate(const KeySequence* sequence);

        KeySequenceCandidate(const KeySequenceCandidate& candidate);

        BOOLEAN IsValidSequence(const KeyCode& key);

        BOOLEAN GetConsumeLastKey() const;

        BOOLEAN IsFinished() const;


        
    private:
        INT m_currentTriggeredKey;
        const KeySequence* m_sequence;
        BOOLEAN m_isFinished;
        BOOLEAN m_isValid;
        
};


#endif // Atl_Context_KeySequence_hpp 



