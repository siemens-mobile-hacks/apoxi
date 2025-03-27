/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_PredefinedEmsSound_hpp)
#define Ems_PredefinedEmsSound_hpp

#include <AddOns/MultiMedia/PreparedSound.hpp>

class PredefinedEmsSound : public PreparedSound 
{
    typedef PreparedSound Base;

    public:
        enum {
            ID = 4
        };

        explicit PredefinedEmsSound(InformationElement::PredefinedSoundType type);      
        virtual ~PredefinedEmsSound();

        virtual INT GetId() const;
        InformationElement::PredefinedSoundType GetPredefinedType() const { return m_type; }

    private:
        InformationElement::PredefinedSoundType m_type;
};

#endif // Ems_PredefinedEmsSound_hpp
