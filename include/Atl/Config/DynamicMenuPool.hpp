/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_Dynamic_MenuPool_hpp)
#define Mmi_Dynamic_MenuPool_hpp

#include <Atl/Features/MenuPool.hpp>
#include <Atl/Features/MenuID.hpp>
#include <Atl/Config/MenuResourceTable.hpp>
class Feature;

class DynamicMenuPool: public MenuPool {

    typedef MenuPool Base;

public:

    DynamicMenuPool();

    virtual ~DynamicMenuPool();
};

#endif  // Mmi_Dynamic_MenuPool_hpp


