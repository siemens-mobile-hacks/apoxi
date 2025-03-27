/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DataPack_hpp)
#define Apoxi_DataPack_hpp

#include <Gui/AcacTypes.hpp>

class DataPack {
    public:
        DataPack(const UINT8 *data);

        virtual ~DataPack();

        DataPackId GetId() const;

        UINT32 GetSize() const;

        UINT16 GetNumberOfEntries() const;

    protected:
        const DataPackHeaderData* m_data;

        friend class BasicPackConnector;
};
#endif //Apoxi_DataPack_hpp


