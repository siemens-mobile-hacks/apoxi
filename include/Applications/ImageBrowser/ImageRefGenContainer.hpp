/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

/*
* This template class GenricContainer can be used to contain object of any type.
* GenricContainer itself derives from class GenericObject and one of it's
* usage can be to contain objects which are not GenericObject and they
* need to be set into DataItem.
*/

#if !defined(Apoxi_ImageRefGenContainer_hpp)
#define Apoxi_ImageRefGenContainer_hpp

#include <Auxiliary/GenericObject.hpp>
#include "ImageRef.hpp"

const GenericTypeId c_image_ref_ptr_type = c_user_base_gentypes + 4804;

class ImageRefGenContainer : public GenericObject
{
    public:
    virtual ~ImageRefGenContainer(){}

    ImageRefGenContainer(const ImageRef& img_obt): m_genobj(img_obt){}

    virtual GenericObject* Copy() const;

    virtual BOOLEAN IsEqual(GenericObject* object);
    virtual GenericTypeId GetTypeId();

    ImageRef& GetImageRefObj();
    void SetImageRefObj(const ImageRef& gen_obt); 


    private:
        ImageRef m_genobj;
};

#endif  // Mmi_GenricContainer_hpp
