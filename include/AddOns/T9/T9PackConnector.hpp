/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_T9PackConnector_hpp)
#define Apoxi_T9PackConnector_hpp

#include <AddOns/T9/T9Pack.hpp>

class T9PackConnector {
    public:
        static void Init();

        static BOOLEAN IsT9PackAvailable();

        static BOOLEAN SetActiveLdb(UINT16 id);

        static UINT32 GetSizeOfLdb(UINT16 id = m_ldb_id);

        static INT ReadLdbData(UINT32 offset, UINT8 *dst, INT size);

        static INT16 GetNumberOfLdbs();

        static BOOLEAN GetLdbIds(INT *ldb_ids, UINT16 size);

    private:
        static T9Pack* m_t9_pack;

        static INT32 m_ldb_id;
};

#endif  // Apoxi_T9PackConnector_hpp

