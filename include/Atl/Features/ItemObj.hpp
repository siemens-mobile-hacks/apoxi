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

#if ! defined(Atl_Features_ItemObj_hpp)
#define Atl_Features_ItemObj_hpp

#include <Auxiliary/GenericObject.hpp>
#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Context/MenuDesc.hpp>
#endif  // APOXI_COMPAT_2_7_0

const GenericTypeId c_item_ptr_type = c_user_base_gentypes + 4801;

class Item;

class ItemObj : public GenericObject
{
    public:
        ItemObj(Item* item);

        virtual ~ItemObj();

        virtual GenericObject* Copy() const;

        virtual BOOLEAN IsEqual(GenericObject* object);

        virtual GenericTypeId GetTypeId();

        void SetItem(Item* item);

        Item* GetItem() const { return m_item; }

    private:
        Item* m_item;
};

#endif


