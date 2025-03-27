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

#if ! defined(Atl_Context_MenuDescObj_hpp)
#define Atl_Context_MenuDescObj_hpp

#include <Auxiliary/GenericObject.hpp>
#include <Atl/Context/MenuDesc.hpp>

const GenericTypeId c_menu_desc_ptr_type = c_user_base_gentypes + 4800;

class MenuDescObj : public GenericObject
{
    public:
        MenuDescObj(const MenuDesc& menu_desc);

        virtual ~MenuDescObj();

        virtual GenericObject* Copy() const;

        virtual BOOLEAN IsEqual(GenericObject* object);

        virtual GenericTypeId GetTypeId();

        void SetMenuDesc(const MenuDesc& menu_desc) { m_menu_desc = menu_desc; }

        const MenuDesc& GetMenuDesc() {return m_menu_desc;}


    private:
        MenuDesc m_menu_desc;

};

#endif


