/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(TriggerKeyFeature_hpp)
#define TriggerKeyFeature_hpp

#include <Atl/Features/Feature.hpp>


class TriggerKeyFeature : public Feature {
    typedef Feature Base;
public:

    enum {
        ID = 5
    };

    TriggerKeyFeature();

    virtual ~TriggerKeyFeature();

    void Init(const FeatureID& feature_id, KeyCode key_code);

    void SetKeyCode(KeyCode key_code) { m_key_code = key_code; }

    KeyCode GetKeyCode() const { return m_key_code; }

    virtual INT GetID() const;
        
    virtual BOOLEAN IsInstanceOf(INT id) const;

    virtual BOOLEAN Execute();

    virtual BOOLEAN IsEqual(const Feature& feature) const;

private:
    TriggerKeyFeature(const TriggerKeyFeature& orig);
    TriggerKeyFeature& operator = (const TriggerKeyFeature& rhs);

    KeyCode m_key_code;
};

#endif /* TriggerKeyFeature_hpp */

