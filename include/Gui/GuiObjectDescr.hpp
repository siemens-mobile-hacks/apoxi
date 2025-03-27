/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GuiObjectDescr_hpp)
#define Apoxi_GuiObjectDescr_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>
#include <Config/GuiObjectFactory.hpp>

class GuiObjectDescr {
    public:

        GuiObjectDescr();

        GuiObjectDescr(UINT16 id, GuiObjectFactory::ClassType classType, UINT32 binary_pos = 0, UINT32 binary_len = 0);

        void SetId(UINT16 id);
        UINT16 GetId() const;

        void SetClassType(GuiObjectFactory::ClassType class_type);
        GuiObjectFactory::ClassType GetClassType() const;

        void SetBinaryPos(UINT32 pos);
        UINT32 GetBinaryPos() const;

        void SetBinaryLen(UINT32 len);
        UINT32 GetBinaryLen() const;

    private:
        UINT16 m_id;
        GuiObjectFactory::ClassType m_class_type;
        UINT32 m_binary_pos;
        UINT32 m_binary_len;        
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_GuiObjectDescr_hpp


