/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_GuidServiceTable_hpp)
#define Apoxi_GuidServiceTable_hpp
#include <AddOns/Services/Service.hpp>
#include <Afs/ObjectTreeService.hpp>

#if !defined(APOXI_REG_MAX_ASOT)
#define APOXI_REG_MAX_ASOT 5
#endif

struct GuidUriTable{
    Uri rooturi;
    ObjectTreeService* serviceptr;
};

class GuidServiceTable {
    public:
        enum {
            c_asot_max = APOXI_REG_MAX_ASOT
        };

        static ObjectTreeService* GetObjectTreeforURI(const Uri& reg_uri);

        static BOOLEAN SetObjectTreeURI(const Uri& reg_uri, const Guid& guid);

    private:

        static GuidUriTable m_guid_uri_table[c_asot_max];
};
#endif


