/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ActionExtension_hpp)
#define Apoxi_ActionExtension_hpp

#include <Kernel/Types.hpp>

class ActionExtension {
    public:
        ActionExtension();

        virtual ~ActionExtension();

        virtual INT GetId() const = 0;

        virtual BOOLEAN IsInstanceOf(INT id) const = 0;
};

#endif  // Apoxi_ActionExtension_hpp


