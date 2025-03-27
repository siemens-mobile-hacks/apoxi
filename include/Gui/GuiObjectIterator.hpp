/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GuiObjectIterator_hpp)
#define Apoxi_GuiObjectIterator_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>
#include <Gui/GuiObjectDescr.hpp>
#include <Gui/ResourceParser.hpp>
#include <Config/GuiObjectFactory.hpp>

class GuiObjectIterator {
    public:

        GuiObjectIterator(ResourceParser& parser, BOOLEAN toplevel = FALSE);

        ~GuiObjectIterator();

        BOOLEAN HasNext();

        GuiObjectDescr GetNext();

        void Release();

    private:        
        ResourceParser* m_parser;
        BOOLEAN m_first;
        UINT16 m_obj_count;
        UINT32 m_obj_pos;
        UINT32 m_obj_len;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_GuiObjectIterator_hpp


