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

#if ! defined(Atl_Features_MenuIdObj_hpp)
#define Atl_Features_MenuIdObj_hpp

#include <Auxiliary/GenericObject.hpp>
#include <Atl/Features/MenuID.hpp>

const GenericTypeId c_menu_id_ptr_type = c_user_base_gentypes + 4800;

class MenuIdObj : public GenericObject
{
    public:
        // Constructor of MenuAccessorPtr
        MenuIdObj(const MenuID& menu_id);

        // Destructor of MenuAccessorPtr
        virtual ~MenuIdObj();

        virtual GenericObject* Copy() const;

        //instance itself
        virtual BOOLEAN IsEqual(GenericObject* object);

        virtual GenericTypeId GetTypeId();

        void SetMenuID(const MenuID& menu_id) { m_menu_id = menu_id; }

        const MenuID& GetMenuId() {return m_menu_id;}


    private:
        MenuID m_menu_id;

};

#endif


