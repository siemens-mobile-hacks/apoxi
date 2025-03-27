/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BackToIdleFeature_hpp)
#define BackToIdleFeature_hpp

#include <Atl/Features/Feature.hpp>

class BackToIdleFeature : public Feature {
    typedef Feature Base;
public:

    enum {
        ID = 106
    };

    BackToIdleFeature();

    virtual ~BackToIdleFeature();

    void Init();

    virtual INT GetID() const;
        
    virtual BOOLEAN IsInstanceOf(INT id) const;

    virtual BOOLEAN Execute();

    virtual BOOLEAN IsEqual(const Feature& feature) const;
};

#endif /* BackToIdleFeature_hpp */

