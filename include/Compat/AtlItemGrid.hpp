/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_AtlItemGrid_hpp)
#define Atl_AtlItemGrid_hpp

#include <Gui/ItemGrid.hpp>

class AtlItemGrid : public ItemGrid {
    typedef ItemGrid Base;
    
    public:
        AtlItemGrid();

        AtlItemGrid(Control* parent, AbstractItemContainer* item_cont = 0);

        virtual ~AtlItemGrid();

        void Init(Control* parent, AbstractItemContainer* item_cont = 0);
    
    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

};

#endif  // Atl_AtlItemGrid_hpp


