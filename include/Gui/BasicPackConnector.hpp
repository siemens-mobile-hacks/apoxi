/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BasicPackConnector_hpp)
#define Apoxi_BasicPackConnector_hpp

#include <Gui/DataPack.hpp>
#include <Gui/TextPack.hpp>
#include <Gui/FontPack.hpp>
#include <Gui/FilePack.hpp>
#include <Gui/AcacTypes.hpp>

class BasicPackConnector {
    public:

        static void Init();

        static const DataPack *GetDataPack(DataPackId datapack_id);

        static BOOLEAN ContainsDataPack(DataPackId datapack_id);

        static UINT32 GetSizeOfDataPack(DataPackId datapack_id);

        static UINT16 GetNumberOfEntries(DataPackId datapack_id);

    protected:
        BasicPackConnector();
        virtual ~BasicPackConnector();


    private:
        static void InitDataPacks(const DataPackHeaderData *dphd);

        static DataPack **  m_datapacks;

        static UINT8 *  cp_handle;

        static UINT32       m_number_of_datapacks;

        static BOOLEAN      m_is_initialized;
};

#endif  // Apoxi_BasicPackConnector_hpp


