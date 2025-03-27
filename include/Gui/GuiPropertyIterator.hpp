/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GuiPropertyIterator_hpp)
#define Apoxi_GuiPropertyIterator_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>
#include <Gui/GuiObjectDescr.hpp>
#include <Gui/ResourceParser.hpp>
#include <Gui/GridLayout.hpp>
#include <Gui/FlowLayout.hpp>

class GuiPropertyIterator {

    public:
        struct CellProps {
            INT16 m_row;
            INT16 m_column;
            GridLayout::XAlign  m_x_align;
            GridLayout::YAlign  m_y_align;
            UINT16 m_component_id;
        };

        struct ColumnAndRowProps {
            INT m_index;
            GridLayout::StretchUnit m_stretch_unit;
            INT m_value;
        };

        struct AlignInfoProps {
            UINT16 m_component_id;
            FlowLayout::Alignment align;
        };
        
        struct TabProps {
            UINT16 m_component_id;
            BOOLEAN m_enabled;
            WString m_text;
            String m_icon_uri;
        };
        
        struct AmbiguousTextProps {
            WString m_text;
            UINT8 m_hint;
        };

        GuiPropertyIterator(ResourceParser& parser,
                            INT object_id,
                            GuiObjectFactory::PropertyId prop_id);
        
        ~GuiPropertyIterator();

        BOOLEAN HasNext();

        BOOLEAN GetNext(void* property);

        void Release();

    private:
        ResourceParser* m_parser;
        UINT32 m_prop_pos;
        UINT16 m_prop_count;
        GuiObjectFactory::PropertyId m_prop_id;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_GuiPropertyIterator_hpp

