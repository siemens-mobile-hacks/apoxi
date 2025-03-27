/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GuiPropertyIdIterator_hpp)
#define Apoxi_GuiPropertyIdIterator_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>
#include <Gui/GuiObjectDescr.hpp>
#include <Gui/ResourceParser.hpp>
#include <Config/GuiObjectFactory.hpp>

class GuiPropertyIdIterator {
    public:
        GuiPropertyIdIterator(ResourceParser& parser,
                              INT object_id);
        
        ~GuiPropertyIdIterator();
        
        BOOLEAN HasNext();

        GuiObjectFactory::PropertyId GetNext();

        void Release();     

    private:
        ResourceParser* m_parser;
        BOOLEAN m_first;
        UINT16 m_prop_count;
        UINT32 m_prop_len;
        UINT32 m_prop_pos;      
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_GuiPropertyIdIterator_hpp


