/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_T9Pack_hpp)
#define Apoxi_T9Pack_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/DataPack.hpp>

class T9Pack : public DataPack {
    typedef DataPack Base;

    public:
        T9Pack(UINT8 *data);

        virtual ~T9Pack();

        UINT16 GetLdbId(UINT32 index);

        INT32 GetIndex(UINT16 ldb_id);

        const UINT8 *GetData(UINT16 index) const;

        UINT32 GetSize(UINT16 index) const;

        UINT32 GetLdbSize(UINT16 index) const;

    private:
        T9PackData* m_t9_pack_data;

        T9LdbData ** m_ldbs;
};
#endif //Apoxi_FontPack_hpp


