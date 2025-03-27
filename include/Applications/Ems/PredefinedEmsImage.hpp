/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_PredefinedEmsImage_hpp)
#define Ems_PredefinedEmsImage_hpp

#include <Apc/InformationElement.hpp>
#include <AddOns/MultiMedia/NativeImage.hpp>

class PredefinedEmsImage : public NativeImage 
{
    typedef NativeImage Base;
    public: 
        enum {
            ID = 4
        };

        explicit PredefinedEmsImage(InformationElement::PredefinedAnimationType type);
        virtual ~PredefinedEmsImage();
        
        virtual INT GetId() const;
        InformationElement::PredefinedAnimationType GetPredefinedType() const { return m_type; }

    private:
        InformationElement::PredefinedAnimationType m_type;

};

#endif // Ems_PredefinedEmsImage_hpp
