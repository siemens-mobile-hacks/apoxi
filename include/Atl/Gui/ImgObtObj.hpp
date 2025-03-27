/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(Atl_Gui_ImgObtObj_hpp)
#define Atl_Gui_ImgObtObj_hpp


#include <Auxiliary/GenericObject.hpp>
#include <Gui/ImageObtainer.hpp>

const GenericTypeId c_img_obt_type = c_user_base_gentypes + 4802;

class ImgObtObj : public GenericObject{
    public:
        typedef GenericObject Base;

        ImgObtObj(const ImageObtainer& img_obt);

        // Destructor of the class BitmapRes
        virtual ~ImgObtObj();

        virtual GenericObject* Copy() const;

        //instance itself
        virtual BOOLEAN IsEqual(GenericObject* object);

        virtual GenericTypeId GetTypeId();

        void SetImgObt(const ImageObtainer& img_obt) { m_img_obt = img_obt; }

        const ImageObtainer& GetImgObt() const { return m_img_obt; }

    private:
        ImageObtainer m_img_obt;

};

#endif 


