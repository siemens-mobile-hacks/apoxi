/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ItemGrid_hpp)
#define Apoxi_ItemGrid_hpp

#include <Kernel/Timer.hpp>
#include <Gui/AbstractItemGrid.hpp>

class ItemGrid : public AbstractItemGrid {
    typedef AbstractItemGrid Base;
    
    public:
        enum {
            ID = 12
        };

        ItemGrid();

        ItemGrid(Control* parent, AbstractItemContainer* item_cont = 0);

        virtual ~ItemGrid();

        void Init(Control* parent, AbstractItemContainer* item_cont = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        void SetColumnCount(INT count);
        
        virtual INT GetColumnCount() const;

    private:
        INT m_column_count;
};

#endif  // Apoxi_ItemGrid_hpp

